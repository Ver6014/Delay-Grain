class MyView extends HTMLElement
{
    constructor (patchConnection)
    {
       super(); 
       this.patchConnection = patchConnection;
       this.innerHTML = this.getHTML();
       this.classList.add ("view-patch-element");
    }

    connectedCallback()
    {
        this.paramListener = event =>
        {
            const slider = this.querySelector ("#" + event.endpointID);

            if (slider)
                slider.value = event.value * 100.0; // Scale the value back to 0-1 range for the slider
        };

        this.patchConnection.addAllParameterListener (this.paramListener);

        for (const slider of this.querySelectorAll (".param"))
        {
            slider.oninput = () => this.patchConnection.sendEventOrValue (slider.id, slider.value / 100.0); // Scale the slider value to 0-1 range before sending
            this.patchConnection.requestParameterValue (slider.id);
        }
    }

    disconnectedCallback()
    {
        this.patchConnection.removeAllParameterListener (this.paramListener);
    }

    getHTML()
    {
        return `
            <link href='https://fonts.googleapis.com/css?family=Coral Pixels' rel='stylesheet'>
            <link rel="stylesheet" href="view/styles.css">
            
            <body>

                <h1>Delay Grain</h1>
                <p>Made By: Victor Schulhoff</p>
                <br>

                <div id="controls" class="controls">
                <p>Max Delay</p>
                <input type="range" min="0" max="100" value="50" class="rangeslider" id="maxDelayParam">
                <p>Feedback</p>
                <input type="range" min="0" max="100" value="40" class="rangeslider" id="feedbackParam">
                <p>Mix</p>
                <input type="range" min="0" max="100" value="50" class="rangeslider" id="mixParam">
                <p>Cutoff</p>
                <input type="range" min="0" max="100" value="50" class="rangeslider" id="cutoffParam">
                <p>Resonance</p>
                <input type="range" min="0" max="100" value="0" class="rangeslider" id="resonanceParam">
                </div>    

            </body>
        `;   
    }
}

window.customElements.define ("my-view", MyView);

export default function createPatchView (patchConnection)
{
    return new MyView (patchConnection);
}
