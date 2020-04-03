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
        color: new_color
        height: parent.height
        width: 50
        anchors.left: parent.left
        border.color: black
        border.width: 1

        Label {
            id: label_id
            text: id_text
            anchors.centerIn: parent
        }
    }

    Rectangle {
        id: tile_task
        color: new_color
        height: parent.height
        width: (parent.width - 430) / 2
        anchors.left: tile_id.right
        border.color: black
        border.width: 1
        TextField {
            id: lebel_task
            text: task
            background: back_color
            width: parent.width
            anchors.centerIn: parent
            horizontalAlignment: TextInput.AlignHCenter
        }
    }

    Rectangle {
        id: tile_description
        color: new_color
        height: parent.height
        width: (parent.width - 430) / 2
        anchors.left: tile_task.right
        border.color: black
        border.width: 1
        clip: true
        TextField {
            id: lebel_description
            text: description_task
            background: back_color
            anchors.centerIn: parent
            horizontalAlignment: TextInput.AlignHCenter
        }
        ScrollBar {
            id: hbar
            hoverEnabled: true
            active: hovered || pressed
            orientation: Qt.Horizontal
            size: tile_description.width / lebel_description.width
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
        }
    }
    Rectangle {
        id: tile_start
        color: new_color
        height: parent.height
        width: 140
        anchors.left: tile_description.right
        border.color: black
        border.width: 1
        TextField {
            id: lebel_start
            text: date_start
            background: back_color
            width: parent.width
            anchors.centerIn: parent
            horizontalAlignment: TextInput.AlignHCenter
       }
    }

    Rectangle {
        id: tile_end
        color: new_color
        height: parent.height
        width: 140
        anchors.left: tile_start.right
        border.color: black
        border.width: 1

        TextField {
            id: lebel_end
            text: date_end
            background: back_color
            width: parent.width
            anchors.centerIn: parent
            horizontalAlignment: TextInput.AlignHCenter
       }
    }

    Rectangle {
        id: tile_progress
        color: new_color
        height: parent.height
        width: 100
        anchors.left: tile_end.right
        border.color: black
        border.width: 1

        TextField {
            id: lebel_progress
            text: prog
            background: back_color
            width: parent.width
            anchors.centerIn: parent
            horizontalAlignment: TextInput.AlignHCenter
        }
    }
}
