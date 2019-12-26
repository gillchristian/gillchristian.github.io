module Link = {
  [@bs.module "next/link"] [@react.component]
  external make:
    (
      ~href: string=?,
      ~_as: string=?,
      ~prefetch: option(bool)=?,
      ~replace: option(bool)=?,
      ~shallow: option(bool)=?,
      ~passHref: option(bool)=?,
      ~children: React.element
    ) =>
    React.element =
    "default";
};

module Head = {
  [@bs.module "next/head"] [@react.component]
  external make: (~children: React.element) => React.element = "default";
};

module Error = {
  [@bs.module "next/head"] [@react.component]
  external make: (~statusCode: int, ~children: React.element) => React.element =
    "default";
};

// Next bindings
// @link: https://github.com/sync/with-reasonml/blob/a094134bb9f8a384c4eef6eda3ce084a81a46f8f/src/bindings/Next.re
//
// Usage
// https://github.com/sync/with-reasonml/blob/a094134bb9f8a384c4eef6eda3ce084a81a46f8f/src/components/ActiveLink.re
module Router = {
  [@gentype]
  type t = {. "pathname": string};

  [@bs.module "next/router"] [@bs.return nullable]
  external useRouter: unit => option(t) = "useRouter";
};
