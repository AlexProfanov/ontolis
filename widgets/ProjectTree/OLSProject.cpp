#include "OLSProject.h"

#include <fstream>

OLSProject::OLSProject() {

}

OLSProject::~OLSProject() {

  foreach (OLSProjectFile *file, m_files) {
    delete file;
  }
}

OLSProjectFile *OLSProject::createFile() {

  OLSProjectFile *newFile = new OLSProjectFile();
  m_files.append(newFile);
  return newFile;
}

OLSProjectFile *OLSProject::createFile(const QString &jsonString) {

  if (jsonString.length() > 0) {
    QJson::Parser parser;
    bool ok = false;
    QVariant json = parser.parse(jsonString.toLocal8Bit(), &ok);
    if (ok) {
      OLSProjectFile *newFile = new OLSProjectFile();
      newFile->ontologyController()->deserialize(json);
      m_files.append(newFile);
      return newFile;
    }
  }

  return NULL;
}

OLSProjectFile *OLSProject::openFile(const QString &path) {

  if (QFile::exists(path)) {
    QFile file(path);
    QJson::Parser parser;
    bool ok = false;
    QVariant json = parser.parse(&file, &ok);

    if (ok) {
      QFileInfo fileInfo(path);
      OLSProjectFile *newFile = new OLSProjectFile(path, fileInfo.fileName());
      newFile->ontologyController()->deserialize(json);
      m_files.append(newFile);
      return newFile;
    }
  }

  return NULL;
}

bool OLSProject::saveFile(OLSProjectFile *file, const QString &path) {

  if (file != NULL) {
    QFile dstFile(path);
    if (dstFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
      QVariant json = file->ontologyController()->serialize();

      QJson::Serializer serializer;
      QByteArray data = serializer.serialize(json);

      dstFile.write(data);

      QFileInfo fileInfo(path);
      file->setName(fileInfo.fileName());
      file->setPath(path);

      return true;
    }
  }

  return false;
}

bool OLSProject::saveFile(OLSProjectFile *file) {

  return saveFile(file, file->path());
}

OLSProjectFile *OLSProject::getProjectFileByName(const QString &name) const {

  foreach (OLSProjectFile *file, m_files) {
    if (file->name() == name) {
      return file;
    }
  }

  return NULL;
}

OLSProjectFile *OLSProject::getProjectFileByIndex(int index) const {

  return m_files[index];
}

int OLSProject::filesCount() const {

  return m_files.count();
}

QVariant OLSProject::serialize() const {

  QVariantList filesJson;
  foreach (OLSProjectFile *file, m_files) {
    filesJson.append(file->serialize());
  }

  QVariantMap json;
  json["files"] = filesJson;
  return json;
}

void OLSProject::deserialize(const QVariant &json) {

  m_files.clear();

  QVariantList filesJson = json.toMap()["files"].toList();
  foreach (QVariant fileJson, filesJson) {
    OLSProjectFile *file = new OLSProjectFile("", "");
    file->deserialize(fileJson);
    m_files.append(file);
  }
}

bool OLSProject::openProject(const QString &path) {

  if (QFile::exists(path)) {
    QFile file(path);
    QJson::Parser parser;
    bool ok = false;
    QVariant json = parser.parse(&file, &ok);

    if (ok) {
      deserialize(json);
      return true;
    }
  }

  return false;
}

bool OLSProject::saveProject(const QString &path) {

  QFile file(path);
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QVariant jsonState = serialize();

    QJson::Serializer serializer;
    QByteArray data = serializer.serialize(jsonState);
    file.write(data);
    return true;
  }
  return false;
}