module Pages.Stream exposing (page)

import Components.Header exposing (Page(..))
import Components.Sidebar
import Html
import Html.Attributes as Attr
import View exposing (View)



-- TODO
-- - List the projects I worked on?


page : View msg
page =
    Components.Sidebar.view
        Stream
        { page =
            { title = "Pages.Stream"
            , body =
                [ Html.div
                    [ Attr.class "notice" ]
                    [ Html.blockquote
                        []
                        [ Html.text "🙈 At the moment I'm taking a break from sreaming, but I'll be back!"
                        ]
                    , Html.img
                        [ Attr.src "https://media3.giphy.com/media/JROv0JzhSjDHFGJhvG/giphy.gif?cid=ecf05e47nmodnvepesnh46xr0d0uacbccfjwmolaa2v6gd4a&rid=giphy.gif&ct=g" ]
                        []
                    ]
                , Html.h1 [ Attr.class "events-title" ] [ Html.text "Stream schedule" ]
                , Html.h2
                    [ Attr.class "events-title-stream" ]
                    [ Html.a
                        [ Attr.href "https://twitch.tv/gillchristian"
                        , Attr.target "_blank"
                        , Attr.rel "noopener noreferrer"
                        ]
                        [ Html.text "twitch.tv/gillchristian" ]
                    , Html.text " / "
                    , Html.a
                        [ Attr.href "https://discord.gg/UMdeMUq"
                        , Attr.target "_blank"
                        , Attr.rel "noopener noreferrer"
                        ]
                        [ Html.text "Discord #ttv_gillchristian" ]
                    ]
                , Html.p
                    []
                    [ Html.text "I write code for random side projects, mostly in FP languages like Haskell and Elm." ]
                , Html.p
                    []
                    [ Html.text "Come say Hi and chat, or just lurk if that's your thing." ]
                ]
            }
        }
