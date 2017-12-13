import {markdown} from 'markdown'
import {readOrReject} from 'lib/fetch'

export async function loadMarkdown(targetId, url, andThen = s => s) {
  const target = document.getElementById(targetId)
  if (!target) {
    return
  }
  try {
    const response = await fetch(url)
    const text = await readOrReject(response, false)
    const processedText = andThen(text)
    target.innerHTML = markdown.toHTML(processedText)
    target.classList.remove('md-page--loading')
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
