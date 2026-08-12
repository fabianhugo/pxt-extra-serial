---
layout: layouts/catalog-page
title: Edge Serial TypeScript Reference
---

## Overview

This page documents the TypeScript-facing API for Edge Serial.

If you are learning, start with [Extra Edge Serial](../) and [Edge Serial Blocks Guide](../blocks/).

## Quick call summary

- Writing: `writeLine()`, `writeString()`, `writeNumber()`, `writeNumbers()`, `writeValue()`, `setWriteLinePadding()`
- Reading and callbacks: `readLine()`, `readUntil()`, `readString()`, `readBuffer()`, `onDataReceived()`, `delimiters()`
- Configuration: `redirect()`, `setBaudRate()`, `setRxBufferSize()`, `setTxBufferSize()`

## Example

```ts
edgeserial.setBaudRate(EdgeBaudRate.BaudRate115200)
edgeserial.setWriteLinePadding(16)

edgeserial.onDataReceived("\n", function () {
    let line = edgeserial.readLine()
    console.log(line)
})

edgeserial.writeLine("hello world")
```

## API details

- API index: [Edge Serial API Index](../api/)
- Namespace details: [Edge Serial Namespace](../namespace_edgeserial/)
- Enum details: [Edge Serial Pin Enum](../enum_edgeserialpin/), [Edge Baud Rate Enum](../enum_edgebaudrate/)
