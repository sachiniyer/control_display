// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
const fs = require('fs')

let filePath = `${process.env.DATA}`
export default async function handler(req, res) {
  return new Promise((resolve, _) => {
    if (req.method === 'POST') {
      fs.writeFile(filePath, req.body, function (err) {
        if (err) { throw err }
        res.status(200).json({
          message: "File changed to: " + req.body
        })
        resolve()
      })
    } else {
      fs.readFile(filePath, 'utf-8', (err, data) => {
        if (err) throw err;
        res.status(200)
        res.send(data)
        resolve()
      })
    }
  })
}
