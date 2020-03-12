import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import com.vv.organizer 1.0

Window {
    id:root
    visible: true
    width: 740
    height: 480
    title: qsTr("Organizer")
    property string ns: 'NewData{width:640; height:20;}'
    property string ts: 'NewData{width:640; height:20;'
    property int num: 0

    ScrollView {
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        anchors.fill: parent
        Component.onCompleted:
        {
            loader.loadBase()
        }
        ColumnLayout {
            id:list
            y:30
        }
    }

    Organizer{
        id : loader
        onInitEnd:
        {
            if (succeed)
            {
              loader.getNextRecord()
              Qt.createQmlObject(ns, list, "objdata")
            }
            else
            {
                Qt.quit()
            }
        }
        onLoad:
        {
            var total = ts + 't_id:"' + id + '";task:"' + task +
                             '";desc:"' + desc + '";date_beg:"' + date_beg +
                             '";date_end:"' + date_end + '";prog:"' + prog +'";}'
            Qt.createQmlObject(total, list, "obj" + (++num))
            loader.getNextRecord()

        }
    }
    Rectangle {
        id: id_rect
        x: 0
        y: 0
        width: 40
        height: 30
        color: "#98FB98"
        border.color: "#000000"
        Text {
            id: id_label
            x: 20
            y: 8
            text: qsTr("ID")
            font.pixelSize: 12
        }
    }
    Rectangle {
        id: task_rect
        x: 40
        y: 0
        width: 120
        height: 30
        color: "#98FB98"
        border.color: "#000000"
        Text {
            id: task_label
            x: 20
            y: 8
            text: qsTr("Задача")
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: desc_rect
        x: 160
        y: 0
        width: 120
        height: 30
        color: "#98FB98"
        border.color: "#000000"
        Text {
            id: desc_label
            x: 40
            y: 8
            text: qsTr("Описание")
            font.pixelSize: 12
        }
    }
    Rectangle {
        id: datebeg_rect
        x: 280
        y: 0
        width: 120
        height: 30
        color: "#98FB98"
        border.color: "#000000"
        Text {
            id: datebeg_label
            x: 14
            y: 0
            width: 120
            height: 30
            text: qsTr("Дата начала\n разработки")
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: dateend_rect
        x: 400
        y: 0
        width: 120
        height: 30
        color: "#98FB98"
        border.color: "#000000"
        Text {
            id: dateend_label
            x: 13
            y: 2
            text: qsTr("Срок\nвыполнения")
            font.pixelSize: 12
        }
    }
    Rectangle {
        id: progress_rect
        x: 520
        y: 0
        width: 80
        height: 30
        color: "#98FB98"
        border.color: "#000000"

        Text {
            id: progress_label
            x: 14
            y: 8
            text: qsTr("Прогресс")
            font.pixelSize: 12
        }
    }
    Button{
        id:addData
        text: qsTr("Добавить")
        Component.onCompleted: {
            x = 600;
            y = 0;
            width=100
            height=25
            color: "#B0C4DE"
        }
        onClicked:
        {
           var data_id = list.data[num].data[0].data[0].text
           var data_task = list.data[num].data[1].data[0].text
           var data_desc = list.data[num].data[2].data[0].text
           var data_datebeg = list.data[num].data[3].data[0].text
           var data_dateend = list.data[num].data[4].data[0].text
           var data_prog = list.data[num].data[5].data[0].text
           loader.writeNewInformation(data_id,data_task,data_desc,data_datebeg,data_dateend,data_prog)
           Qt.createQmlObject(ns, list, "objdata")
           num++
        }

    }
    Button{
        id:rewriteData
        text: qsTr("Перезаписать")
        Component.onCompleted: {
            x = 600;
            y = 30;
            width=100
            height=25
        }
        onClicked:
        {
            loader.rewriteFile()
            for (var i = 0; i < num;i++)
            {
                var data_id = list.data[i].data[0].data[0].text
                var data_task = list.data[i].data[1].data[0].text
                var data_desc = list.data[i].data[2].data[0].text
                var data_datebeg = list.data[i].data[3].data[0].text
                var data_dateend = list.data[i].data[4].data[0].text
                var data_prog = list.data[i].data[5].data[0].text
                loader.writeNewInformation(data_id,data_task,data_desc,data_datebeg,data_dateend,data_prog)
            }
        }
    }
    Button{
        id:deleteData
        text: qsTr("Очистить все")
        Component.onCompleted: {
            x = 600;
            y = 60;
            width=100
            height=25
        }
        onClicked:
        {
            loader.deleteFile()
            for (var i = 0; i < num;i++)
            {
                var data_id = list.data[i].data[0].data[0].text
                var data_task = list.data[i].data[1].data[0].text
                var data_desc = list.data[i].data[2].data[0].text
                var data_datebeg = list.data[i].data[3].data[0].text
                var data_dateend = list.data[i].data[4].data[0].text
                var data_prog = list.data[i].data[5].data[0].text
                loader.writeNewInformation(data_id,data_task,data_desc,data_datebeg,data_dateend,data_prog)
            }
        }
    }
}
