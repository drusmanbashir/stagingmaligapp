import Qt3D 2.0
import QtQuick 2.0

Rectangle {
    //model is a list of {"name":"somename", "url":"file:///some/url/mainfile.qml"}
    //function used to add to model A) to enforce scheme B) to allow Qt.resolveUrl in url assignments

    color: "#eee"
    function addExample(name, desc, url)
    {
        myModel.append({"name":name, "description":desc, "url":url})
    }
    function hideExample()
    {
        ei.visible = false;
    }

    ListView {
        clip: true
        delegate: SimpleLauncherDelegate{exampleItem: ei}
        model: ListModel {id:myModel}
        anchors.fill: parent
    }

    Item {
        id: ei
        visible: false
        clip: true
        property url exampleUrl
        onExampleUrlChanged: visible = (exampleUrl == '' ? false : true); //Setting exampleUrl automatically shows example
        anchors.fill: parent
        anchors.bottomMargin: 40
        Rectangle {
            id: bg
            anchors.fill: parent
            color: "white"
        }
        MouseArea{
            anchors.fill: parent
            enabled: ei.visible
            //Eats mouse events
        }
        Loader{
            focus: true
            source: ei.exampleUrl
            anchors.fill: parent
        }
    }
    Rectangle {
        id: bar
        visible: ei.visible
        anchors.bottom: parent.bottom
        width: parent.width
        height: 40

        Rectangle {
            height: 1
            color: "#ccc"
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
        }

        Rectangle {
            height: 1
            color: "#fff"
            anchors.top: parent.top
            anchors.topMargin: 1
            anchors.left: parent.left
            anchors.right: parent.right
        }

        gradient: Gradient {
            GradientStop { position: 0 ; color: "#eee" }
            GradientStop { position: 1 ; color: "#ccc" }
        }

        MouseArea{
            anchors.fill: parent
            enabled: ei.visible
            //Eats mouse events
        }

        Image {
            id: back
            source: "images/back.png"
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 2
            anchors.left: parent.left
            anchors.leftMargin: 16

            MouseArea {
                id: mouse
                hoverEnabled: true
                anchors.centerIn: parent
                width: 38
                height: 31
                anchors.verticalCenterOffset: -1
                onClicked: ei.exampleUrl = ""
                Rectangle {
                    anchors.fill: parent
                    opacity: mouse.pressed ? 1 : 0
                    Behavior on opacity { NumberAnimation{ duration: 100 }}
                    gradient: Gradient {
                        GradientStop { position: 0 ; color: "#22000000" }
                        GradientStop { position: 0.2 ; color: "#11000000" }
                    }
                    border.color: "darkgray"
                    antialiasing: true
                    radius: 4
                }
            }
        }
    }
}
