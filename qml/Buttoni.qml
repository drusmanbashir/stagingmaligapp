import QtQuick 2.0

Item {
    id: container
    property real size
    property alias src: img.source
    implicitWidth: 100
    implicitHeight: 100
    height: size
    width: size
    signal clunked
    z:1
    anchors.verticalCenter: parent.verticalCenter

Rectangle{
    color:"transparent"


   anchors.fill:parent
    MouseArea{
        id:msArea
        anchors.fill: parent
        onClicked:{container.clunked()    }
    Image{
        height:container.height
        id:img
        fillMode: Image.PreserveAspectFit


    }
}

    }

}
