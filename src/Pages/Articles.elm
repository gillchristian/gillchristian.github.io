module Pages.Articles exposing (Model, Msg, page)

import Components.Header exposing (Page(..))
import Components.Sidebar
import Components.Tags as Tags
import Html exposing (Html)
import Html.Attributes as Attr
import Http
import Json.Decode as D
import Page exposing (Page)
import RemoteData exposing (RemoteData)
import View exposing (View)


page : Page Model Msg
page =
    Page.element
        { init = init
        , update = update
        , subscriptions = subscriptions
        , view = view
        }


subscriptions : Model -> Sub Msg
subscriptions _ =
    Sub.none


view : Model -> View Msg
view model =
    Components.Sidebar.view
        Articles
        { page =
            { title = "Writing"
            , body =
                [ quote
                , Html.h1 [] [ Html.text "Writings" ]
                , Html.div
                    []
                  <|
                    case model.articles of
                        RemoteData.NotAsked ->
                            [ Html.text "..." ]

                        RemoteData.Loading ->
                            [ Html.text "..." ]

                        RemoteData.Success as_ ->
                            if List.isEmpty as_ then
                                [ Html.text "..." ]

                            else
                                List.map article as_

                        RemoteData.Failure msg ->
                            [ Html.text msg ]
                ]
            }
        }


type alias Model =
    { articles : RemoteData String (List Article) }


type Msg
    = GotArticles (RemoteData String (List Article))


init : ( Model, Cmd Msg )
init =
    ( { articles = RemoteData.NotAsked }
    , getArticles
    )


update : Msg -> Model -> ( Model, Cmd Msg )
update msg model =
    case msg of
        GotArticles as_ ->
            ( { model | articles = as_ }
            , Cmd.none
            )


url : String
url =
    "https://dev.to/api/articles?username=gillchristian"


getArticles : Cmd Msg
getArticles =
    Http.get
        { url = url
        , expect =
            Http.expectJson
                (Result.mapError
                    (\_ -> "Could not load articles")
                    >> RemoteData.fromResult
                    >> GotArticles
                )
            <|
                D.list articleD
        }


articleD : D.Decoder Article
articleD =
    D.map4 Article
        (D.field "title" D.string)
        (D.field "url" D.string)
        (D.field "readable_publish_date" D.string)
        (D.field "tag_list" (D.list D.string))


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


type alias Article =
    { title : String
    , url : String
    , date : String
    , tags : List String
    }


article : Article -> Html msg
article a =
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
        , Html.small
            []
            [ Html.span
                [ Attr.class "article-interactions" ]
                [ Html.text <| a.date ++ " " ]
            , Tags.view a.tags
            ]
        ]
