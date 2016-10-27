import {markdown} from 'markdown'
import {readOrReject} from 'lib/fetch'

export async function loadMarkdown(targetId, url) {
  const target = document.getElementById(targetId)
  if (!target) {
    return
  }
  try {
    const response = await fetch(url)
    const text = await readOrReject(response, false)
    target.innerHTML = markdown.toHTML(text)
    target.classList.remove(`${targetId}-loading`)
  } catch (err) {
    console.error(err)
    target.innerHTML = `
      <div class="alert alert-error">
        Ups there was an error loading the content =/
      </div>
      <br>
      <div><a href="" onclick="location.reload()">reload maybe?</a></div>
    `
  }
}
