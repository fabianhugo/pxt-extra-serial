---
layout: layouts/catalog-page
title: Extra Extra Serial
info: >-
    Extra Serial adds block-based serial read and write helpers for Rib:bit projects, including line padding, buffer reads, delimiter handling, and serial configuration.
plugins:
    - ts-to-blocks
tags:
    - software
---

## Overview

Extra Serial helps you send and receive serial data in MakeCode projects using simple, visual blocks.

This page is designed for beginners. Start in the blocks guide, then use TypeScript docs if you need advanced control.

## What you can build

- Debug consoles and telemetry streams
- Board-to-board command channels
- Host tools that parse line-based serial messages
- Classroom experiments with serial protocols

## Learning path

- Start with blocks: [Extra Serial Blocks Guide](blocks/)
- Use TypeScript when ready: [Extra Serial TypeScript Reference](typescript/)
- Browse the full API structure: [Extra Serial API Index](api/)

## Example

This example sets baud rate and line padding, then handles line-based incoming data.

```ts
extraserial.setBaudRate(ExtraBaudRate.BaudRate115200)
extraserial.setWriteLinePadding(16)

extraserial.onDataReceived("\n", function () {
	let line = extraserial.readLine()
	console.log(line)
})

extraserial.writeLine("hello world")
```

## More resources

- TypeScript namespace docs: [Extra Serial Namespace](namespace_extraserial/)
- TypeScript enum docs: [Extra Serial Pin Enum](enum_extraserialpin/), [Extra Baud Rate Enum](enum_extrabaudrate/)
