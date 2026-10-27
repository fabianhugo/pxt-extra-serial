---
layout: layouts/catalog-page
title: Extra Serial TypeScript Reference
---

## Overview

This page documents the TypeScript-facing API for Extra Serial.

If you are learning, start with [Extra Extra Serial](../) and [Extra Serial Blocks Guide](../blocks/).

## Quick call summary

- Writing: `writeLine()`, `writeString()`, `writeNumber()`, `writeNumbers()`, `writeValue()`, `setWriteLinePadding()`
- Reading and callbacks: `readLine()`, `readUntil()`, `readString()`, `readBuffer()`, `onDataReceived()`, `delimiters()`
- Configuration: `redirect()`, `setBaudRate()`, `setRxBufferSize()`, `setTxBufferSize()`

## Example

```ts
extraserial.setBaudRate(ExtraBaudRate.BaudRate115200)
extraserial.setWriteLinePadding(16)

extraserial.onDataReceived("\n", function () {
    let line = extraserial.readLine()
    console.log(line)
})

extraserial.writeLine("hello world")
```

## API details

- API index: [Extra Serial API Index](../api/)
- Namespace details: [Extra Serial Namespace](../namespace_extraserial/)
- Enum details: [Extra Serial Pin Enum](../enum_extraserialpin/), [Extra Baud Rate Enum](../enum_extrabaudrate/)
