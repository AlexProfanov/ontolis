#-------------------------------------------------
#
# Project created by QtCreator 2013-10-13T21:36:39
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = ontolis
TEMPLATE = app
RC_FILE = resources/resources.rc

SOURCES += main.cpp\
        OntolisWindow.cpp \
    widgets/ProjectTree/OLSProject.cpp \
    widgets/ProjectTree/OLSProjectFile.cpp \
    widgets/ProjectTree/OLSProjectFileCategory.cpp \
    widgets/ProjectTree/OLSProjectTreeViewController.cpp \
    widgets/ProjectTree/OLSProjectTreeWidget.cpp \
    widgets/OntologyTree/OLSOntologyTreeViewController.cpp \
    widgets/OntologyPallete/OLSOntologyPalleteWidget.cpp \
    widgets/OntologyGraph/OLSOntologyGraphNodeItem.cpp \
    widgets/OntologyGraph/OLSOntologyGraphElement.cpp \
    widgets/OntologyGraph/OLSOntologyGraphWidget.cpp \
    widgets/OntologyGraph/OLSOntologyGraphRelationItem.cpp \
    widgets/OntologyGraph/OLSOntologyGraphRelationVisualizedLine.cpp \
    widgets/Shared/OLSOntologyDataController.cpp \
    widgets/OntologyGraph/OLSOntologyGraphView.cpp \
    ontoliscategorywidget.cpp

HEADERS  += OntolisWindow.h \
    widgets/ProjectTree/OLSProject.h \
    widgets/ProjectTree/OLSProjectFile.h \
    widgets/ProjectTree/OLSProjectFileCategory.h \
    widgets/ProjectTree/OLSProjectTreeViewController.h \
    widgets/ProjectTree/OLSProjectTreeWidget.h \
    widgets/ProjectTree/OLSProjectTreeWidgetDelegate.h \
    widgets/OntologyTree/OLSOntologyTreeViewController.h \
    widgets/OntologyPallete/OLSOntologyPalleteWidget.h \
    widgets/OntologyGraph/OLSOntologyGraphItemDataKey.h \
    widgets/OntologyGraph/OLSOntologyGraphItemType.h \
    widgets/OntologyGraph/OLSOntologyGraphNodeItem.h \
    widgets/OntologyGraph/OLSOntologyGraphElement.h \
    widgets/OntologyGraph/OLSOntologyGraphWidget.h \
    widgets/OntologyGraph/OLSOntologyGraphRelationItem.h \
    widgets/OntologyGraph/OLSOntologyGraphRelationVisualizedLine.h \
    widgets/Shared/OLSOntologyNodeData.h \
    widgets/Shared/OLSOntologyRelationData.h \
    widgets/Shared/OLSOntologyDataController.h \
    widgets/OntologyGraph/OLSOntologyGraphView.h \
    ontoliscategorywidget.h

FORMS    += OntolisWindow.ui \
    widgets/OntologyGraph/OLSOntologyGraphAttributeEditor.ui \
    widgets/OntologyGraph/OLSOntologyGraphWidget.ui \
    ontoliscategorywidget.ui

RESOURCES +=
