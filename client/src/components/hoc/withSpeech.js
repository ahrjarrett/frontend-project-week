import React, { Component } from 'react'
import propTypes from 'prop-types'

const head = arr => arr[0]

/* withSpeech Required Props: 

   @startListening = (Action Creator :: () -> {type, ...meta})
                       -> Action Object (no payload)

   @stopListening  = (Action Creator :: () -> {type, ...meta})
                       -> Action Object (no payload)

   @addToRegister  = (Action Creator :: Array(String) -> {type, ...meta, payload : Array(String)})
                       -> Action Object (with payload)
   
   `startListening` and `stopListening` are similar in that they 
   don't receive any particular payload from the withSpeech
   component; the action object they return can be as simple as:

       > const startListening = () => ({ type: WHAT_YOUR_REDUCERS_WILL_LISTEN_FOR })
   
   `addToRegister` is different in that the action creator implicitly
   receives (from withSpeech) a "register", which is an array of strings
   that you can assign to a `data` or `payload` property on your action.

   **Note: Currently this only officially supports a Redux or Flux-type model where
           you have reducers that listen for the actions that withSpeech returns,
	   and manages the logic for how this component actually mutates state.
	  
   **Note: PRs that abstract this component's functionality to React in general are
           absolutely welcome!

*/

const withSpeech = Comp => {
  class WithSpeech extends Component {
    componentDidMount = () => {
      window.SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition
      this.recognition = new window.SpeechRecognition()
      this.recognition.interimResults = true
    }

    componentWillUnmount = () => {
      this.recognition.removeEventListener('result', this.accumulateTranscript)
    }

    start = () => {
      this.props.startListening()
      this.recognition.addEventListener('result', this.accumulateTranscript)
      this.recognition.start()
    }

    stop = () => {
      this.props.stopListening()
      this.recognition.stop()
    }

    accumulateTranscript = e => {
      const transcript = Array.from(e.results)
        .map(head)
        .map(({ transcript }) => transcript)
        .join('')

      if (head(e.results).isFinal)
        this.props.addToRegister(transcript)
    }

    render() {
      return <Comp
        {...this.props}
        start={this.start}
        stop={this.stop}
      />
    }
  }

  WithSpeech.propTypes = {
    startListening: propTypes.func.isRequired,
    stopListening: propTypes.func.isRequired,
    addToRegister: propTypes.func,
  }

  return WithSpeech
}

export default withSpeech
