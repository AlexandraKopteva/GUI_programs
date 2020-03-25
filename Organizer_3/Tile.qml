import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item {
    id: tile
    property string id_text: "ID"
    property string task: "Задания"
    property string description_task: "Описание  задания"
    property string date_start: "Дата  начала"
    property string date_end: "Дата  окончания"
    property string prog: "Прогресс"
    //
    property string new_color: "#98FB98"
    property string border_color: "#000000"
    property int height1: 20

    width: parent.width
    height: height1
    Rectangle {
        id: tile_id
        anchors.left: parent.left
        border.color: border_color
        color: new_color
        border.width: 1
        height: parent.height
        width: 50
        Label {
            id: label_id
            text: id_text
            anchors.centerIn: parent
        }
    }
    Rectangle {
        id: tile_task
        anchors.left: tile_id.right
        border.color: border_color
        color: new_color
        border.width: 1
        height: parent.height
        width: (parent.width - 430) / 2
        TextField {
            id: label_task
            text: task
            anchors.centerIn: parent
            horizontalAlignment: TextInput.AlignHCenter
        }
    }
    Rectangle {
        id: tile_description
        anchors.left: tile_task.right
        border.color: border_color
        color: new_color
        border.width: 1
        height: parent.height
        width: (parent.width - 430) / 2

        clip:  true
        TextField {
            id: label_description
            text: description_task
            anchors.centerIn: parent
            horizontalAlignment: TextInput.AlignHCenter
        }
        ScrollBar {
            id: scrollbar
            hoverEnabled: true
            active: hovered || pressed
            orientation: Qt.Horizontal
            size: tile_description.width / label_description.width
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
        }
    }
    Rectangle {
        id: tile_start
        anchors.left: tile_description.right
        border.color: border_color
        color: new_color
        border.width: 1
        height: parent.height
        width: 140
        TextField {
            id:label_start
            text: date_start
            anchors.centerIn: parent
            horizontalAlignment: TextInput.AlignHCenter
        }
    }
    Rectangle {
        id: tile_end
        anchors.left: tile_start.right
        border.color: border_color
        color: new_color
        border.width: 1
        height: parent.height
        width: 140
        TextField {
            id:label_end
            text: date_end
            anchors.centerIn: parent
            horizontalAlignment: TextInput.AlignHCenter
        }
    }
    Rectangle {
        id: tile_progress
        anchors.left: tile_end.right
        border.color: border_color
        color: new_color
        border.width: 1
        height: parent.height
        width: 100
        TextField {
            id:label_progress
            text: prog
            anchors.centerIn: parent
            horizontalAlignment: TextInput.AlignHCenter
        }
    }
}
