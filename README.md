My final frontend project for LambdaSchool, a 1-year coding bootcamp that I completed in May of 2018.

The client includes [react-speak](https://www.npmjs.com/package/react-speak), an npm package I created and open-sourced in May 2018. At its highest point it was getting over 100 downloads/week.

# Hosting

Frontend: https://react-speak.herokuapp.com/
Backend: https://react-speak-server.herokuapp.com

# Environment Variables

## Frontend

In `client/.env` make sure you have:
`REACT_APP_SERVER_URI=http://localhost:7000`

And in the Heroku app, make sure you set the config var:
`REACT_APP_SERVER_URI=https://react-speak-server.herokuapp.com`

# Front End Project Week

This week you will be building a minimum viable product (MVP) for a note taking app called "Lambda Notes."

You are to treat this week as if you are working at a company and the instructor is your client. The teaching assistants are acting as your project managers and will be your main support throughout the week.

The main objective of this week is to develop the MVP feature set listed below using react and any other technologies you have learned here at Lambda School. There are design files in this repository you should use as a creative guide.

## Git Commits

- You are required to showcase progress with at least 1 commit a day. This will let your project manager know where you are and if you need help. This also allows the client to get progress reports from the company in a real world setting.

## Trello Set Up:

- [ ] Create a Trello account
- [ ] Create a new board called "Lambda Notes - {Your Name}"
- [ ] Create lists titled `backlog`,`To Do`, `In Progress`, and `Done`
- [ ] Fill in the `To Do` list with the MVP features listed below
- [ ] Fill in the `backlog` list with all the extra features listed below
- [ ] Share your board with the project manager that has been assigned to you. If you have not been assigned yet, reach out to your lead TA for guidance
- [ ] Add your Trello URL to your project's README.md file. Commit the change, push it to your repository & submit a pull request

## MVP Features:

- [ ] Display a list of notes
- [ ] Create a note with a title and content
- [ ] View an existing note
- [ ] Edit an existing note
- [ ] Delete an existing note

Upon your first commit, please submit a Pull Request and add _both_ the **Trello Set Up** and **MVP Features** Task lists to your first Pull Request comment:

```markdown
## Trello Set Up:

- [ ] Create a Trello account
- [ ] Create a new board called "Lambda Notes - {Your Name}"
- [ ] Create lists titled `backlog`,`To Do`, `In Progress`, and `Done`
- [ ] Fill in the `To Do` list with the MVP features listed below
- [ ] Fill in the `backlog` list with all the extra features listed below
- [ ] Share your board with the project manager that has been assigned to you. If you have not been assigned yet, reach out to your lead TA for guidance
- [ ] Add your Trello URL to your project's README.md file. Commit the change, push it to your repository & submit a pull request

## MVP Features:

- [ ] Display a list of notes
- [ ] Create a note with a title and content
- [ ] View an existing note
- [ ] Edit an existing note
- [ ] Delete an existing note
```

---

## Once you have completed the Minimum Viable Product requirements, direct message your project manager for approval. If approved, you may continue working on the Extra Features.

Once your MVP has been approved, you have been given a feature list that the client would love to have completed. Your goal would be to finish MVP as soon as you can and get working the list of features.

## Extra Features:

- [ ] Make the data persist with arrays / object literals (JSON) or a 3rd party service like Firebase
- [ ] Search functionality
- [ ] Markdown support in notes
- [ ] Sorting options in the list view
- [ ] Create and display tags that can be added to notes
- [ ] Drag sorting in the list view
- [ ] Add the ability to have checklists within the note view
- [ ] Export all notes to a CSV
- [ ] Create a login system around the MVP

You will notice that this repository does not have any starter code. This is on purpose. You are to start from scratch using any files you have built throughout your time here at Lambda School.
