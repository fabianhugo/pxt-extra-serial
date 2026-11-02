extraserial.setRxBufferSize(128)
extraserial.setWriteLinePadding(0)
extraserial.redirect(ExtraSerialPin.A1_RX, ExtraSerialPin.A1_TX, ExtraBaudRate.BaudRate115200)
input.onButtonEvent(Button.A, input.buttonEventClick(), function () {
    extraserial.writeLine("testesr")
})
basic.forever(function () {
    let b = extraserial.readBuffer(0)
    if (b.length > 0) serial.writeLine(control.millis() + " " + b.toHex())
    
    basic.pause(5)
})
