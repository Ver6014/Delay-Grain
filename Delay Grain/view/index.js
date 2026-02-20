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
            <style>
                .view-patch-element
                {
                    font-family: 'Coral Pixels';font-size: 22px;
                    text-align: center;
                    display: block;
                    width: 100%;
                    height: 100%;
                    padding: 10px;
                    overflow: auto;
                    flex-direction: column;
                    align-items: left; 
                    background-color: lightpink;
                }

                .param
                {
                    -webkit-appearance: none;
                    width: 100%;
                    height: 20px;
                    background: #d3d3d3;
                    outline: none;
                    opacity: 0.7;
                    -webkit-transition: .2s;
                    transition: opacity .2s;
                }
                    .param:hover {
                        opacity: 1;
                }
                

                    .param::-webkit-slider-thumb {
                    -webkit-appearance: none;
                    appearance: none;
                    width: 25px;
                    height: 25px;
                    background: #f3768f;
                    cursor: pointer;
                }

                    .param::-moz-range-thumb {
                    width: 25px;
                    height: 25px;
                    background: #d8506b;
                    cursor: pointer;
                }
                    .controls
                    {
                        border: 1px solid black;
                        padding: 10px;
                        border-radius: 5px;
                        display: flex;
                        flex-direction: column;
                        gap: 10px;
                        width: 300px;
                        margin: 0 auto;
                        width: 100%;
                        background: #f3768f;

                    }
                        

            </style>

            <body>

                <h1>Delay Grain</h1>
                <p>Made By: Victor Schulhoff</p>
                <br>

                <div id="controls" class="controls">
                <p>Max Delay</p>
                <input type="range" min="0" max="100" value="50" class="param" id="maxDelayParam">
                <p>Feedback</p>
                <input type="range" min="0" max="100" value="40" class="param" id="feedbackParam">
                <p>Mix</p>
                <input type="range" min="0" max="100" value="50" class="param" id="mixParam">
                <p>Cutoff</p>
                <input type="range" min="0" max="100" value="50" class="param" id="cutoffParam">
                <p>Resonance</p>
                <input type="range" min="0" max="100" value="0" class="param" id="resonanceParam">
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
