const http = require("http");
const express = require("express");
const bodyParser = require("body-parser");
const app = express();

const { check, validationResult } = require("express-validator");

app.set("view engine", "ejs");

app.set("views", "./views");

app.use(express.urlencoded({ extended: true }));

app.use(bodyParser.urlencoded({ extended: true }));

app.get("/", (req, res) => {
  res.render("form");
});

app.post(
  "/print",
  [
    check("imie").notEmpty(),
    check("nazwisko").notEmpty(),
    check("zadanie1")
      .optional({ checkFalsy: true })
      .isInt(),
    check("zadanie2")
      .optional({ checkFalsy: true })
      .isInt(),
    check("zadanie3")
      .optional({ checkFalsy: true })
      .isInt(),
    check("zadanie4")
      .optional({ checkFalsy: true })
      .isInt(),
    check("zadanie5")
      .optional({ checkFalsy: true })
      .isInt(),
    check("zadanie6")
      .optional({ checkFalsy: true })
      .isInt(),
    check("zadanie7")
      .optional({ checkFalsy: true })
      .isInt(),
    check("zadanie8")
      .optional({ checkFalsy: true })
      .isInt(),
    check("zadanie9")
      .optional({ checkFalsy: true })
      .isInt(),
    check("zadanie10")
      .optional({ checkFalsy: true })
      .isInt()
  ],
  (req, res) => {
    const {
      imie,
      nazwisko,
      zadanie1,
      zadanie2,
      zadanie3,
      zadanie4,
      zadanie5,
      zadanie6,
      zadanie7,
      zadanie8,
      zadanie9,
      zadanie10
    } = req.body;

    const errors = validationResult(req);
    if (!errors.isEmpty()) {
      return res.redirect("/");
    }

    res.render("print", {
      imie,
      nazwisko,
      zadania: [
        zadanie1 || 0,
        zadanie2 || 0,
        zadanie3 || 0,
        zadanie4 || 0,
        zadanie5 || 0,
        zadanie6 || 0,
        zadanie7 || 0,
        zadanie8 || 0,
        zadanie9 || 0,
        zadanie10 || 0
      ]
    });
  }
);

http.createServer(app).listen(3000);
console.log("start");