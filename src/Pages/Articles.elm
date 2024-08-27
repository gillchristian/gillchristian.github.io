module Pages.Articles exposing (page)

import Components.Header exposing (Page(..))
import Components.Sidebar
import Html exposing (Html)
import Html.Attributes as Attr
import View exposing (View)


page : View msg
page =
    Components.Sidebar.view
        Articles
        { page =
            { title = "Writing"
            , body =
                [ quote
                , Html.h1 [] [ Html.text "Writing" ]
                , Html.div
                    [ Attr.class "articles" ]
                    [ link
                        { title = "Blog 📝"
                        , url = "https://blog.gillchristian.xyz/"
                        , description = Just "Mostly technical stuff."
                        }
                    , link
                        { title = "Digital Garden 🪴"
                        , url = "https://garden.gillchristian.xyz/"
                        , description = Just "Less polished notes and thoughts, on software and a bunch of other things."
                        }
                    , link
                        { title = "Stream 🌊"
                        , url = "https://stream.gillchristian.xyz/"
                        , description = Just "Stream of consciousness."
                        }
                    , link
                        { title = "Ferrum Field 🦀"
                        , url = "https://ferrum-field.vercel.app/"
                        , description = Just "Notes on Rust and systems programming."
                        }
                    , link
                        { title = "Library 📚"
                        , url = "https://library.gillchristian.xyz/"
                        , description = Just "Books I've read and I'm reading."
                        }
                    ]
                ]
            }
        }


quote : Html msg
quote =
    Html.blockquote
        []
        [ Html.p
            []
            [ Html.text "I have only one method that I recommended extensively - it's called think before you write."
            , Html.text "Take historical note of the textile and steel industries:"
            ]
        , Html.p
            []
            [ Html.i [] [ Html.text "Richard Hamming." ] ]
        ]


type alias Link =
    { title : String
    , url : String
    , description : Maybe String
    }


link : Link -> Html msg
link a =
    Html.div
        [ Attr.class "article" ]
        [ Html.div
            []
            [ Html.a
                [ Attr.class "article-title"
                , Attr.href a.url
                , Attr.target "_blank"
                , Attr.rel "noopener noreferrer"
                ]
                [ Html.text a.title ]
            ]
        , case a.description of
            Just desc ->
                Html.p [] [ Html.text desc ]

            Nothing ->
                Html.text ""
        ]
