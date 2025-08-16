import QtQuick
import QtQuick.Controls
import com.franco.custom

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QJSValue")
    property var myApi: Singleton.getJSValue()

    Button {
        id: btnId
        text: qsTr("Click me")
        onClicked: {
            console.log("Property = " + MySingleton.someProperty);

             console.log("mArray[0] = " + MySingleton.mArray[0]) // Prints undefined, we din't set up anything with key 0.
             console.log("mArray[1] = " + MySingleton.mArray[1]) //Prints the first value

             MySingleton.mArray.forEach(function(idx, element){
                 console.log("element[" + idx + "] = " + element)
             })
        }
    }

    // Use this with getJSValue method
    Button {
        id: btn2Id
        anchors {
            top: btnId.bottom
            margins: 20
        }

        text: qsTr("Click me again !")
        onClicked: {
            console.log("Property = " + myApi.someProperty)

            console.log("mArray[0] = " + myApi.mArray[0])
            console.log("mArray[1] = " + myApi.mArray[1])

            myApi.mArray.forEach((idx, element) => {
                console.log("element[" + idx + "] = " + element)
            })
        }
    }
}
