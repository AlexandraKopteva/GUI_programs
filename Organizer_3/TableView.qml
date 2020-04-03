import QtQuick 2.0
import com.vv.oranizer 3.0

ListView {
    id: rootListView
    width: parent.width
    height: parent.height
    anchors.fill: parent

    model: Oranizer { }

    delegate:
        Tile {
          id_text: if (index != 0) index
          task: name
          description_task: description
          date_start: start
          date_end: end
          prog: progress
          //
          new_color: if (index != 0) "#ffffff"
          border_color: if (index !=0) "#000000"
          height1: if (index != 0) height1 + height1
    }
}
