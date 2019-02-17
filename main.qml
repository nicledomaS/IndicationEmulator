import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Indication emulator")

    function updateSwitches() {
        if(!mainPower.checked && !usbPower.checked)
        {
            usbDataExchanged.checked = false
            activeError.checked = false
            unacknowledgeError.checked = false
        }
    }

    function getColor()
    {
        return diod.enabled ? diod.color : "gray"
    }

    RowLayout {
        Rectangle {
            id: indication
            height: 100
            width: 100
            color: getColor()
            radius: 50

            Connections {
                target: diod
                onDataChanged: indication.color =  getColor()
            }
        }

        ColumnLayout {
            Switch {
                id: mainPower
                text: "Main power"
                onCheckedChanged:  {
                    updateSwitches()
                    controller.eventMainPower(checked)
                }
            }

            Switch {
                id: usbPower
                text: "Usb power"
                onCheckedChanged:  {
                    updateSwitches()
                    controller.eventUsbPower(checked)
                }
            }

            Switch {
                id: usbDataExchanged
                text: "Usb data exchange"
                enabled: mainPower.checked || usbPower.checked
                onCheckedChanged: controller.eventUsbDataExchange(checked)
            }

            Switch {
                id: activeError
                text: "Active error"
                enabled: mainPower.checked || usbPower.checked

                onCheckedChanged: {
                    controller.eventActiveError(checked)
                    if(checked && !unacknowledgeError.checked)
                    {
                        unacknowledgeError.checked = checked
                    }
                }
            }

            Switch {
                id: unacknowledgeError
                text: "Unacknowledge error"
                enabled: mainPower.checked || usbPower.checked
                onCheckedChanged: controller.eventUnacknowledgeError(checked)
            }
        }
    }
}
