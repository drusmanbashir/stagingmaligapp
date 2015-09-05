import QtQuick 2.0
import Qt3D 2.0
//import "../qml"


Rectangle {
     //previously 'page'
    anchors.left: parent.left
    width: 400; height: parent.height
    color: "black"

    // delegate for the recipes.  this delegate has two modes:
    // 1. list mode (default), which just shows the picture and title of the singleItem.
    // 2. details mode, which also shows the ingredients and method.
    component {
        id: regionsDelegate
//! [0]
        item {
            id: singleItem//previously 'recipe'

            // create a property to contain the visibility of the details.
            // we can bind multiple element's opacity to this one property,
            // rather than having a "propertychanges" line for each element we
            // want to fade.
            property real detailsopacity : 0
//! [0]
            width: listview.width
            height: 70

            // a simple rounded rectangle for the background
            rectangle {
                id: background
                x: 2; y: 2; width: parent.width - x*2; height: parent.height - y*2
                color: "ivory"
                border.color: "orange"
                radius: 5
            }

            // this mouse region covers the entire delegate.
            // when clicked it changes mode to 'details'.  if we are already
            // in details mode, then no change will happen.
//! [1]
            mousearea {
                anchors.fill: parent
                onclicked: regionSingle.state = 'details';
            }

            // lay out the page: picture, title and ingredients at the top, and method at the
            // bottom.  note that elements that should not be visible in the list
            // mode have their opacity set to singleItem.detailsopacity.

            row {
  //! [1]
                column {

                    width: background.width - recipeimage.width - 20; height: recipeimage.height
                    spacing: 5

                    text {
                        text: regionName
                        font.bold: true; font.pointsize: 16
                    }

                 column{
                     opacity: singleItem.detailsopacity
                     id: details
                     width:100
                    text {
                        text: organName
                        font.bold: true; font.pointsize: 16
                    }
                 textbutton {
                         id:closedetails
                         y: 10
                         anchors { right: background.right; rightmargin: 10 }
                         opacity: singleItem.detailsopacity
                         text: "close"

                         onclicked: singleItem.state = '';
                     }

                 }
                }
            }

//! [2]


            // a button to close the detailed view, i.e. set the state back to default ('').


            states: state {
                name: "details"

                propertychanges { target: background; color: "white" }
             //   propertychanges { target: recipeimage; width: 130; height: 130 } // make picture bigger
                propertychanges { target: regionSingle; detailsopacity: 1; x: 0 } // make details visible
                propertychanges { target: regionSingle; height: listview.height } // fill the entire list area with the detailed view

                // move the list so that this item is at the top.
                propertychanges { target: regionSingle.listview.view; explicit: true; contenty: regionSingle.y }

                // Disallow flicking while we're in detailed view
                PropertyChanges { target: regionSingle.ListView.view; interactive: false }
            }

            transitions: Transition {
                // Make the state changes smooth
                ParallelAnimation {
                    ColorAnimation { property: "color"; duration: 500 }
                    NumberAnimation { duration: 300; properties: "detailsOpacity,x,contentY,height,width" }
                }
            }
        }
//! [3]
    }

    // The actual list
    ListView {
        id: listView
        anchors.fill: parent
        model: RecipesModel {}
        delegate: regionsDelegate
    }
}
