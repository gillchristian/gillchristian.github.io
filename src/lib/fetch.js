export const readOrReject = (response, asJson = true) => {
  if (response.ok) {
    return asJson ? response.json() : response.text()
  }
  throw new Error(`${response.status}: ${response.statusText}`)
}
