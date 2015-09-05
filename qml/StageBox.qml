import QtQuick 2.0

Rectangle {
    id: bg


    property int size: 12
    property alias content: boxText.text
    property alias fontSize: boxText.font.pointSize

color:'white'
    width: parent.width
    height: boxText.paintedHeight+20


    z: 5
    Text {

        color: "black"

        id: boxText
        width: parent.width
        height: parent.height


        z: 1
        font.pointSize: size
        wrapMode: Text.WordWrap

}
}
