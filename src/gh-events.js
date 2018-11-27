// https://api.github.com/users/gillchristian/events
import trae from 'trae'
import distanceInWords from 'date-fns/distance_in_words'

// --- algebras

const typeEq = type => e => e.type === type

const any = fns => x => fns.some(fn => fn(x))

const both = (pred1, pred2) => x => pred1(x) && pred2(x)

const map = fn => xs => xs.map(x => fn(x))

const filter = fn => xs => xs.filter(x => fn(x))

const compose = (...fns) => x => fns.reduceRight((r, fn) => fn(r), x)

const cond = (...mts) => x => mts.filter(([m]) => m(x))[0][1](x)

// --- code

const isWatch = typeEq('WatchEvent')
const isIssues = typeEq('IssuesEvent')
const isPublic = typeEq('PublicEvent')
const isPullRequest = typeEq('PullRequestEvent')
const isPush = typeEq('PushEvent')
const isCreate = typeEq('CreateEvent')

const shouldIncludeEvent = any([
  both(isWatch, e => e.payload.action === 'started'),
  both(isIssues, e => e.payload.action === 'opened'),
  both(isPullRequest, e => e.payload.action === 'opened'),
  both(isCreate, e => e.payload.ref_type === 'branch'),
  both(isCreate, e => e.payload.ref_type === 'tag'),
  isPublic,
  isPush,
])

const base = e => ({
  repo: { name: e.repo.name, url: e.repo.url },
  createdAt: e.created_at,
})

const data = cond(
  [isWatch, e => ({ ...base(e), type: 'starred' })],
  [isIssues, e => ({ ...base(e), type: 'open_issue' })],
  [isPullRequest, e => ({ ...base(e), type: 'open_pr' })],
  [isPublic, e => ({ ...base(e), type: 'publish_repo' })],
  [
    isCreate,
    e => ({
      ...base(e),
      name: e.payload.ref,
      what: e.payload.ref_type,
      type: 'created',
    }),
  ],
  [
    isPush,
    e => ({ ...base(e), count: e.payload.commits.length, type: 'push' }),
  ],
)

const repoLink = ({ url, name }) => `
  <a hre="${url}" target="_blank" rel="noopener noreferrer">${name}</a>
`

const time = ({ createdAt }) => `
  <span>
    <i class="fa fa-clock-o"></i> ${distanceInWords(
      new Date(),
      new Date(createdAt),
      { addSuffix: true },
    )}
  </span>
`

const icon = ({ name }) => `
  <i class="fa fa-${name} fa-2x"></i>
`

const renderStarred = d => `
  <div>
    <span>
      ${icon({ name: 'star' })} ${repoLink(d.repo)}
    </span>
    ${time(d)}
  </div>
`

const renderOpenIssue = d => `
  <div>
    <span>${icon({ name: 'book' })} issue on ${repoLink(d.repo)}</span>
    ${time(d)}
  </div>
`

const renderOpenPR = d => `
  <div>
    <span>${icon({ name: 'book' })} PR on ${repoLink(d.repo)}</span>
    ${time(d)}
  </div>
`

const renderPublishRepo = d => `
  <div>
    <span>created ${repoLink(d.repo)}</span>
    ${time(d)}
  </div>
`

const renderCreated = d => `
  <div>
    <span>${icon({ name: 'code-fork' })} ${d.what} ${d.name} ${repoLink(
  d.repo,
)}</span>
    ${time(d)}
  </div>
`

const renderPushCommits = d => `
  <div>
    <span>
      ${icon({ name: 'arrow-up' })} ${d.count} commit${
  d.count > 1 ? 's' : ''
} to ${repoLink(d.repo)}
    </span>
    ${time(d)}
  </div>
`

const isStarred = typeEq('starred')
const isOpenIssue = typeEq('open_issue')
const isOpenPR = typeEq('open_pr')
const isPublishRepo = typeEq('publish_repo')
const isCreated = typeEq('created') // tag / branch
const isPushCommits = typeEq('push')

const markup = cond(
  [isStarred, renderStarred],
  [isOpenIssue, renderOpenIssue],
  [isOpenPR, renderOpenPR],
  [isPublishRepo, renderPublishRepo],
  [isCreated, renderCreated],
  [isPushCommits, renderPushCommits],
)

export const githubFeed = () =>
  trae
    .get('https://api.github.com/users/gillchristian/events')
    .then(d => d.data)
    .then(filter(shouldIncludeEvent))
    .then(map(data))
    .then(map(markup))
    .then(xs => xs.join('\n'))

// ---------------------------------------------------------------------------------------------------------------------

/*

https://developer.github.com/v3/activity/events/types/

Types of events

Open issue
  Rule: both(typeEq('IssuesEvent'), propEq('action', 'opened'))

Stared repo
  Rule: both(pathEq('stared', ['payload', 'action']), typeEq('WatchEvent'))

Create branch
  Rule:  both(pathEq('branch', ['payload', 'ref_type']), typeEq('CreateEvent'))

Create tag
  Rule:  both(pathEq('tag', ['payload', 'ref_type']), typeEq('CreateEvent'))

Push to repo
  Rule: typeEq('PushEvent')

Make repo public
  Rule: typeEq('PublicEvent')

Open pull request
  Rule: both(typeEq('PullRequestEvent'), pathEq('opened', ['payload', 'action']))
  Data: event.payload.pull_request

// [
//   'PushEvent',
//   'WatchEvent',
//   'PublicEvent',
//   'PullRequestEvent',
//   'CreateEvent',
//   'PullRequestReviewCommentEvent',
//   'IssueCommentEvent',
//   'ForkEvent',
//   'IssuesEvent',
//   'RepositoryEvent',
//   '',
//   '',
// ]

// const isPullRequestReviewComment = typeEq('PullRequestReviewCommentEvent')
// const isIssueComment = typeEq('IssueCommentEvent')
// const isFork = typeEq('ForkEvent')
// const isRepository = typeEq('RepositoryEvent')

  // .then(es => es.filter(e => e.type === 'WatchEvent'))
  // .then(es => es.filter(e => e.payload.action === 'started'))

// CreateEvent
// [ { id: '7848393047',
//     type: 'CreateEvent',
//     actor:
//      { id: 8309423,
//        login: 'gillchristian',
//        display_login: 'gillchristian',
//        gravatar_id: '',
//        url: 'https://api.github.com/users/gillchristian',
//        avatar_url: 'https://avatars.githubusercontent.com/u/8309423?' },
//     repo:
//      { id: 137524685,
//        name: 'fvictorio/mundial',
//        url: 'https://api.github.com/repos/fvictorio/mundial' },
//     payload:
//      { ref: 'layout-tweaks',
//        ref_type: 'branch',
//        master_branch: 'master',
//        description: 'See today\'s FIFA World Cup matches results in your terminal',
//        pusher_type: 'user' },
//     public: true,
//     created_at: '2018-06-19T21:39:15Z' },
//   { id: '7836557076',
//     type: 'CreateEvent',
//     actor:
//      { id: 8309423,
//        login: 'gillchristian',
//        display_login: 'gillchristian',
//        gravatar_id: '',
//        url: 'https://api.github.com/users/gillchristian',
//        avatar_url: 'https://avatars.githubusercontent.com/u/8309423?' },
//     repo:
//      { id: 137524685,
//        name: 'fvictorio/mundial',
//        url: 'https://api.github.com/repos/fvictorio/mundial' },
//     payload:
//      { ref: 'v0.0.5',
//        ref_type: 'tag',
//        master_branch: 'master',
//        description: 'Show today\'s FIFA World Cup matches results',
//        pusher_type: 'user' },
//     public: true,
//     created_at: '2018-06-17T20:58:44Z' } ]

// Watch event
// { id: '7882092661',
//   type: 'WatchEvent',
//   actor:
//     { id: 8309423,
//       login: 'gillchristian',
//       display_login: 'gillchristian',
//       gravatar_id: '',
//       url: 'https://api.github.com/users/gillchristian',
//       avatar_url: 'https://avatars.githubusercontent.com/u/8309423?' },
//   repo:
//     { id: 97216102,
//       name: 'gitalk/gitalk',
//       url: 'https://api.github.com/repos/gitalk/gitalk' },
//   payload: { action: 'started' },
//   public: true,
//   created_at: '2018-06-26T21:18:26Z',
//   org:
//     { id: 29697133,
//       login: 'gitalk',
//       gravatar_id: '',
//       url: 'https://api.github.com/orgs/gitalk',
//       avatar_url: 'https://avatars.githubusercontent.com/u/29697133?' } },

// PushEvent
// { id: '7882183849',
//   type: 'PushEvent',
//   actor:
//    { id: 8309423,
//      login: 'gillchristian',
//      display_login: 'gillchristian',
//      gravatar_id: '',
//      url: 'https://api.github.com/users/gillchristian',
//      avatar_url: 'https://avatars.githubusercontent.com/u/8309423?' },
//   repo:
//    { id: 69824917,
//      name: 'gillchristian/raws',
//      url: 'https://api.github.com/repos/gillchristian/raws' },
//   payload:
//    { push_id: 2675316211,
//      size: 1,
//      distinct_size: 1,
//      ref: 'refs/heads/master',
//      head: '18c9ae9222f6f8fad68766026197655c5e8af44f',
//      before: '9adab0938faee0ca427c9f97f32b9d2a4ff921b6',
//      commits: [Array] },
//   public: true,
//   created_at: '2018-06-26T21:38:18Z' },

// PublicEvent
// { id: '7848413974',
//   type: 'PublicEvent',
//   actor:
//     { id: 8309423,
//       login: 'gillchristian',
//       display_login: 'gillchristian',
//       gravatar_id: '',
//       url: 'https://api.github.com/users/gillchristian',
//       avatar_url: 'https://avatars.githubusercontent.com/u/8309423?' },
//   repo:
//     { id: 137809971,
//       name: 'gillchristian/the-rust-programming-language',
//       url: 'https://api.github.com/repos/gillchristian/the-rust-programming-language' },
//   payload: {},
//   public: true,
//   created_at: '2018-06-19T21:44:08Z' }


  // PullRequestEvent
// [ { id: '7848408673',
//     type: 'PullRequestEvent',
//     actor:
//      { id: 8309423,
//        login: 'gillchristian',
//        display_login: 'gillchristian',
//        gravatar_id: '',
//        url: 'https://api.github.com/users/gillchristian',
//        avatar_url: 'https://avatars.githubusercontent.com/u/8309423?' },
//     repo:
//      { id: 137524685,
//        name: 'fvictorio/mundial',
//        url: 'https://api.github.com/repos/fvictorio/mundial' },
//     payload: { action: 'opened', number: 5, pull_request: [Object] },
//     public: true,
//     created_at: '2018-06-19T21:42:53Z' },
//   { id: '7834766582',
//     type: 'PullRequestEvent',
//     actor:
//      { id: 8309423,
//        login: 'gillchristian',
//        display_login: 'gillchristian',
//        gravatar_id: '',
//        url: 'https://api.github.com/users/gillchristian',
//        avatar_url: 'https://avatars.githubusercontent.com/u/8309423?' },
//     repo:
//      { id: 137524685,
//        name: 'fvictorio/mundial',
//        url: 'https://api.github.com/repos/fvictorio/mundial' },
//     payload: { action: 'opened', number: 2, pull_request: [Object] },
//     public: true,
//     created_at: '2018-06-16T18:16:20Z' } ]

*/
