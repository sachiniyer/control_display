import Head from 'next/head'

import { useEffect,useState } from 'react';

import Button from '@mui/material/Button';
import Box from '@mui/material/Box';
import TextField from '@mui/material/TextField';
import Container from '@mui/material/Container';
import Typography from '@mui/material/Typography';

export default function Home() {

  const [word,setWord] = useState("");

  function submit() {
    fetch("http://localhost:3000/api/word", {
      method: 'POST',
      body: word
    })
      .then(res => {
        console.log('Response: ', res)
      })
      .catch(err => {
        alert("Failure")
      })
  }
  return (
    <>
      <Head>
        <title>School Demo </title>
        <meta name="description" content="Arduino demonstration for school" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
      </Head>
    <main>
        <Container maxWidth="sm" sx={{marginTop: '5vw' }}>
          <Typography variant="h3" sx={{marginBottom: '10vw' }}>
            LED School Demo
          </Typography>
          <TextField fullWidth id="standard-basic" label="Word"
                     variant="filled" color='success' inputProps={{ maxLength: 12 }}
                     onChange={(newValue) => setWord(newValue.target.value)} />

          <Box>
            <Button variant="contained" sx={{marginTop: '5vw' }} onClick={() => submit()}>Submit</Button>
          </Box>
        </Container>
      </main>
    </>
  )
}
