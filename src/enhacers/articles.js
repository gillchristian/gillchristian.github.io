import { readOrReject } from 'lib/fetch'

const listTags = tags =>
  tags
    .map(
      tag => `
        <i><a href="https://dev.to/t/${tag}" target="_blank">${tag}</a></i>
      `,
    )
    .join(', ')

export async function fetchDevToArticles(targetId) {
  const target = document.getElementById(targetId)
  if (!target) {
    return
  }

  const URL = 'https://dev.to/api/articles?username=gillchristian'

  try {
    const response = await fetch(URL)
    const json = await readOrReject(response)

    target.innerHTML = ''
    target.classList.remove('md-page--loading')

    target.innerHTML = json
      .map(
        ({ url, title, description, tag_list }) => `
          <h2 class="m-b-0">
            <a href="${url}" target="_blank">${title}</a>
          </h2>
          <p class="m-y-10">${description}</p>
          <div class="m-t-5 m-b-40">
            [ ${listTags(tag_list)} ]
          </div>
       `,
      )
      .join('\n')
  } catch (e) {
    console.log(e)
    target.innerHTML = `
      <div class="alert alert-error">
        Ups there was an error loading the content =/
        <br>
        You can still view my articles in <a href="https://dev.to/gillchristian">dev.to</a>
      </div>
      <br>
      <div><a href="" onclick="location.reload()">reload maybe?</a></div>
    `
  }
}
