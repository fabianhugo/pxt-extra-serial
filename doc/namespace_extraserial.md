---
layout: layouts/catalog-page
title: Extra Serial Namespace
---

## Namespace `extraserial`

Provides serial read/write helpers, event callbacks, and transport configuration calls.

## Calls

### `writeLine(text)`

- **Parameters:**
  - `text`: Line text to send.
- **Returns:** `void`
- **Description:** Writes line text with configured padding and newline.

### `writeString(data)`

- **Parameters:**
  - `data`: Raw string payload.
- **Returns:** `void`
- **Description:** Writes raw string data.

### `setWriteLinePadding(length)`

- **Parameters:**
  - `length`: Line alignment byte count.
- **Returns:** `void`
- **Description:** Sets padding size for `writeLine()` output.

### `writeNumber(value)`

- **Parameters:**
  - `value`: Numeric value to send.
- **Returns:** `void`
- **Description:** Writes a number as text.

### `writeNumbers(values)`

- **Parameters:**
  - `values`: Numeric array.
- **Returns:** `void`
- **Description:** Writes numbers as comma-separated text.

### `writeValue(name, value)`

- **Parameters:**
  - `name`: Label prefix.
  - `value`: Numeric value.
- **Returns:** `void`
- **Description:** Writes `name:value` text.

### `readLine()`

- **Parameters:** None
- **Returns:** `string`
- **Description:** Reads one line from receive buffer.

### `delimiters(del)`

- **Parameters:**
  - `del`: Delimiter enum value.
- **Returns:** `string`
- **Description:** Converts delimiter enum to string form.

### `onDataReceived(delimiters, body)`

- **Parameters:**
  - `delimiters`: Delimiter(s) to match.
  - `body`: Callback to run on match.
- **Returns:** `void`
- **Description:** Registers receive callback.

### `readUntil(delimiter)`

- **Parameters:**
  - `delimiter`: Stop delimiter.
- **Returns:** `string`
- **Description:** Reads serial data until delimiter is found.

### `readString()`

- **Parameters:** None
- **Returns:** `string`
- **Description:** Reads current receive buffer as string.

### `readBuffer(length)`

- **Parameters:**
  - `length`: Number of bytes.
- **Returns:** `Buffer`
- **Description:** Reads raw bytes from receive buffer.

### `redirect(tx, rx, rate)`

- **Parameters:**
  - `tx`: TX pin from [ExtraSerialPin](../enum_extraserialpin/).
  - `rx`: RX pin from [ExtraSerialPin](../enum_extraserialpin/).
  - `rate`: Baud rate from [ExtraBaudRate](../enum_extrabaudrate/).
- **Returns:** `void`
- **Description:** Redirects serial to selected pins and baud rate.

### `setBaudRate(rate)`

- **Parameters:**
  - `rate`: Baud rate from [ExtraBaudRate](../enum_extrabaudrate/).
- **Returns:** `void`
- **Description:** Sets active baud rate.

### `setRxBufferSize(size)`

- **Parameters:**
  - `size`: New RX buffer size.
- **Returns:** `void`
- **Description:** Sets receive buffer size.

### `setTxBufferSize(size)`

- **Parameters:**
  - `size`: New TX buffer size.
- **Returns:** `void`
- **Description:** Sets transmit buffer size.

## Related enums

- [Extra Serial Pin Enum](../enum_extraserialpin/)
- [Extra Baud Rate Enum](../enum_extrabaudrate/)
