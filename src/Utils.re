module List = {
  let head = xs =>
    switch (xs) {
    | [] => None
    | [a, ..._] => Some(a)
    };

  let tail = xs =>
    switch (xs) {
    | [] => None
    | [_, ...rest] => Some(rest)
    };
};

module Time = {
  let formatDate: string => string = [%bs.raw
    {|((date) => {
      require('moment-timezone')
      const moment = require('moment')
      const datetime = moment.utc(date)

      return datetime.tz(moment.tz.guess()).format('llll')
    })|}
  ];

  let fromNow: string => string = [%bs.raw
    {|((date) => {
      require('moment-timezone')
      const moment = require('moment')
      const datetime = moment.utc(date)

      return datetime.tz(moment.tz.guess()).fromNow()
    })|}
  ];
};
