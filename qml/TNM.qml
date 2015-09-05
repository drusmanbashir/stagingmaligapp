import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2


Rectangle{

    property int genericFontSize: 12
    property color boxColor: '#F0E9D1'
    property color sideMenuColor:'#D6C176'
    property color topMenuColor: '#574E30'

    property alias labelText: organLabel.text
    Component.onCompleted: populate("Lung")

    id: mainView
    visible: true
    width:700
    height:1400
    function populate(organName){
        console.log("Populating ..")
                labelText=organName;
        var List = mWindow.getTNM(organName)
        t.content = List[1]
        node.content = List[2]
        mets.content = List[3]



    }


    function applyState()         {  if(sideMenuContainer.contentX > mainView.width/3 )
        {
      console.log("Goin back to base state")
            sideMenuContainer.state='baseState'
 console.log(".. Base state. Content X should be ", sideMenuContainer.width," is:", sideMenuContainer.contentX)

        }
           else{
            console.log("Going to open Menu because ",sideMenuContainer.contentX," is < ",mainView.width/3)
            sideMenuContainer.state="sideMenuOpen"
 console.log(".. side menu open. Content X should be 20, is:", sideMenuContainer.contentX)
            sideMenuContainer.contentX=0;
        }    }

   MessageDialog{
       id: disclaimerDialog
       title: "Disclaimer"
       text:"The information provided in this app is for educational purposes only. It does not substitute for medical or professional care, and you should not use the information in place of the advice of your physician or other healthcare provider. We are not liable or responsible for any advice, diagnosis, or any other information you obtain through this app."
 icon:StandardIcon.Information
   }


    Column{
            id: dummyColumn

        Rectangle {
            id: topMenu
            z: 1
            width: mainView.width  ;
            height: mainView.height*.1
            color: topMenuColor

            Text {
                 id:organLabel
              anchors.centerIn: parent
                 verticalAlignment: Text.AlignVCenter
                font.capitalization: Font.AllUppercase

                 color:'white'
                  font.bold: true
                  font.pointSize: 16


             }


            Buttoni{

                anchors.left: parent.left
                z:1
                id:menuButton
                size:parent.height*.6
                src:"qrc:/content/bars.png"
                onClunked:   {console.log("h")
                    sideMenuContainer.state = "sideMenuOpen"}


            }
            Buttoni{
                anchors.right: parent.right
                size:parent.height*.5
                z:1
                id:closeButton
                x:400
                src:"qrc:/content/close.png"

              onClunked: { Qt.quit()}
            }
            Buttoni{
                anchors.right:closeButton.left
                anchors.rightMargin: 5
                size:parent.height*.6
                id:disclaimer
                src:"qrc:/content/gear2small.png"
                onClunked: {disclaimerDialog.visible=true}

            }


        }


        Rectangle {
            id: contentBox
            width: mainView.width
            height: mainView.height-topMenu.height

            VisualItemModel{

                id: cancerModel
                Rectangle{
                    id: tnmPage
                    anchors.fill: parent


                    Flickable {
                        id: flick
                        boundsBehavior: Flickable.StopAtBounds

                        flickableDirection: Flickable.VerticalFlick
                        anchors.topMargin: topMenu.bottom
                        width: parent. width
                        height: parent. height - topMenu.height
                        contentWidth: parent.width
                        contentHeight: container.height // this is calculated on amount of text
                        PinchArea {
                            width: Math.max(flick.contentWidth, flick.width)
                            height: Math.max(flick.height, flick.height)
                            pinch.minimumScale: 0.5
                            pinch.maximumScale: 3

                            property real initialWidth
                            property real initialHeight
                            x: 0
                            y: 0
                            //![0]
                            onPinchStarted: {
                                initialWidth = flick.contentWidth
                                initialHeight = flick.contentHeight
                                flick.interactive = false
                            }
                            onPinchUpdated: {
                                t.fontSize = t.size*pinch.scale
                                node.fontSize = node.size * pinch.scale
                                mets.fontSize = mets.size * pinch.scale

                            }

                            onPinchFinished: {
                                flick.returnToBounds()
                                flick.interactive = true
                            }



                            Rectangle {
                                color:"white"
                                id: container

                                MouseArea {
                                    anchors.fill: parent
                                    onDoubleClicked: {

                                        t.fontSize = 12
                                        node.fontSize = t.size
                                        mets.fontSize = t.size
                                    }


                                }


                                anchors.top: flick.top
                                width: parent.width
                                height: t.height + node.height + mets.height

                                StageBox {
                                    id: t
                                    anchors.top: container.top
                                    anchors.margins: 10
                                    color: boxColor

                                }

                                StageBox {
                                    id: node
                                    anchors.top: t.bottom
                                       anchors.margins: 10

                                    color: boxColor
                                }
                                StageBox {
                                    id: mets
                                    anchors.top: node.bottom
                                       anchors.margins: 10
                                    color: boxColor
                                }
                            }
                        }


                    }

                }


//                Rectangle {
//                    id: oncoPage
//                    anchors.fill: parent


//                    Flickable {
//                        id: flick2
//                        Rectangle {
//                            width: parent.width
//                            height: mainView.height-topMenu.height
//                            anchors.topMargin: topMenu.bottom
//                            z:1
//                            Image {
//                                id: oncoImage
//                                source: "qrc:/qml/tnm/content/lungStages.png"
//                                opacity: 1

//                            }

//                        }
//                    }
//                }


//                Rectangle {
//                    id: imagePage
//                    anchors.fill: parent
//                    Flickable {
//                        id: flick3
//                        Rectangle{
//                            width: parent.width
//                            height: mainView.height-topMenu.height
//                            anchors.topMargin: topMenu.bottom
//                            z:1
//                            Image {
//                                id: imageImage
//                                source: "qrc:/qml/tnm/content/lungStages.png"
//                                opacity: 1

//                            }
//                        }

//                    }
//                }
            }







            PathView {
                focus: true
                anchors.fill: parent
                pathItemCount: 1
                snapMode: PathView.SnapOneItem
                id: paginator
                z: 0
                model: cancerModel
                path: Path {

                    startX: 0; startY: mainView.height *.5
                    PathLine { x: mainView.width+300; y: mainView.height * .5 }
                }
            }

        }



    }


    Component {
        id:regionSidelistDelegate

        Text{
            font.pointSize: genericFontSize
            id:regionEntity
            text: modelData
            height:100
            width:regionSidelist.width
            MouseArea{
                anchors.fill:parent
                onClicked: {

                    sideMenuContainer.state = "sideMenuOpen"
//                    console.log("Sidemenu open state ",sideMenuContainer.contentX)
                    organSidelistview.model=mWindow.getOrganNames(text)
                }
            }
        }
    }
    Component {
        id:organSidelistDelegate
        Rectangle{
            id:organSidelistBox

            color:sideMenu.color
            width:parent.width
            height:100;


            Text{
                wrapMode: Text.Wrap
                     font.pointSize: genericFontSize
                id:organLabel
                width:parent.width
                text: modelData
                height:100
                MouseArea{

                    anchors.fill:parent
                    onClicked: {

                        sideMenuContainer.state = "baseState"
//                          console.log("Base state",sideMenuContainer.contentX)
                        populate(organLabel.text)


                    }
                }

            }
        }
    }



    Flickable{
z:1
state:"baseState"

        id:sideMenuContainer
        visible: true
        width:mainView.width*.7

        height:mainView.height
        boundsBehavior: Flickable.StopAtBounds
       contentWidth:width*2


       onFlickEnded:
       {
           console.log("Flick ended")
           applyState()
     }
       onDragEnded:{
           console.log("Drag ended")
           applyState()
   }
       onMovementEnded: {
           console.log("Move ended")
           applyState()
       }

    Rectangle{
        id:sideMenu
        color:sideMenuColor


        width:mainView.width*0.7
        height:mainView.height
        anchors.left:mainView.left


        Rectangle{
            id: regionSidelist
            anchors.left:sideMenu.left
            z:1
            width:sideMenu.width *.5
            height:parent.height*.7
            color:parent.color
            Label{
                id:regionlistLabel
                text: "Systems"
height: Math.max(parent.height*.1,100)
anchors.top:parent.top
            }

            ListView{
                id:regionSidelistview
                height:parent.height

                model:regionNames
                delegate: regionSidelistDelegate
                anchors.top:regionlistLabel.bottom
            }
        }


        Rectangle{
            anchors.left:regionSidelist.right
            width:sideMenu.width*.5

          height:mainView.height
            z:1
            id:organSidelist
            color:parent.color

            Label{

                id:organlistLabel
                text: "Organs"
height: Math.max(parent.height*.1,100)
anchors.top:parent.top
            }



            ListView{
                anchors.top:organlistLabel.bottom

                id:organSidelistview
                width:sideMenu.width *.5
                height:parent.height*.7
                model:mWindow.getOrganNames("Chest")
                delegate: organSidelistDelegate
            }


        }

    }



    states:[
        State {

            name:"baseState"

            PropertyChanges {
                target: sideMenuContainer
                contentX:sideMenuContainer.width
           interactive:false
           z:0

            }


        },
        State {
            name: "sideMenuOpen"
            PropertyChanges{
                target: sideMenuContainer
                contentX: 0
                interactive: true
                z:2

            }

        }


                ]
    transitions: [
    Transition{
//            from:"baseState"
//        to:"sideMenuOpen"
        NumberAnimation{
            properties: "contentX"; duration: 300;
        }

    }
]
    }
}


