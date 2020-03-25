import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

Dialog {
    id: dialog
    visible:  false

    property int id_: 0
    property string task: ""
    property string description_task: ""
    property string date_start: ""
    property string date_end: ""
    property string progress: ""
    //
    property string border_color: "#000000"
    width: 840
    height: 60
    Rectangle {
        id: tile_id
        anchors.left: parent.left
        border.color: border_color
        border.width: 1
        height: parent.height
        width: 50
        Text {
            id: label_id
            text: id_
            anchors.centerIn: parent
        }
    }
    Rectangle {
        id: tile_task
        anchors.left: tile_id.right
        border.color: border_color
        border.width: 1
        height: parent.height
        width: (parent.width - 430) / 2
        TextField {
            id: label_task
            text: task
            anchors.centerIn: parent
            width: parent.width
            horizontalAlignment: TextInput.AlignHCenter
            ScrollBar.horizontal: autoScroll
        }
    }
    Rectangle {
        id: tile_description
        anchors.left: tile_task.right
        border.color: border_color
        border.width: 1
        height: parent.height
        width: (parent.width - 430) / 2
        TextField {
            id: label_description
            text: description_task
            width: parent.width
            anchors.centerIn: parent
            horizontalAlignment: TextInput.AlignHCenter
            ScrollBar.horizontal: autoScroll
        }
    }
    Rectangle {
        id: tile_start
        anchors.left: tile_description.right
        border.color: border_color
        border.width: 1
        height: parent.height
        width: 140
        TextField {
            id:label_start
            text: date_start
            anchors.centerIn: parent
            width: parent.width
            horizontalAlignment: TextInput.AlignHCenter
        }
    }
    Rectangle {
        id: tile_end
        anchors.left: tile_start.right
        border.color: border_color
        border.width: 1
        height: parent.height
        width: 140
        TextField {
            id:label_end
            text: date_end
            anchors.centerIn: parent
            width: parent.width
            horizontalAlignment: TextInput.AlignHCenter
        }
    }
    Rectangle {
        id: tile_progress
        anchors.left: tile_end.right
        border.color: border_color
        border.width: 1
        height: parent.height
        width: 100
        TextField {
            id:label_progress
            text: progress
            anchors.centerIn: parent
            width: parent.width
            horizontalAlignment: TextInput.AlignHCenter
        }
    }
    onAccepted: {
        task = label_task.text
        description_task = label_description.text
        date_start = label_start.text
        date_end = label_end.text
        progress = label_progress.text
    }
}
