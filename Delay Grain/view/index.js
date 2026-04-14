
/*
    This simple web component just manually creates a set of plain sliders for the
    known parameters, and uses some listeners to connect them to the patch.
*/

import "../view/webaudio-controls.js";

class DemoView extends HTMLElement
{
    constructor (patchConnection)
    {
        super();
        this.patchConnection = patchConnection;
        this.classList = "demo-patch-element";
        this.innerHTML = this.getHTML();
    }

    connectedCallback()
    {
        this.paramListener = (event) =>
        {
            // Each of our sliders has the same IDs as an endpoint, so we can find
            // the HTML element from the endpointID that has changed:
            const slider = this.querySelector ("#" + event.endpointID);

            if (slider)
                slider.value = event.value;
        };

        // Attach a parameter listener that will be triggered when any param is moved
        this.patchConnection.addAllParameterListener (this.paramListener);

        for (const knob of this.querySelectorAll ("webaudio-knob"))
        {
            const sendKnobValue = () => this.patchConnection.sendEventOrValue (knob.id, knob.value);
            knob.addEventListener ("change", sendKnobValue);
            knob.addEventListener ("input", sendKnobValue);

            // for each knob, request an initial update, to make sure it shows the right value
            this.patchConnection.requestParameterValue (knob.id);
        }
    }

    disconnectedCallback()
    {
        // when our element goes offscreen, we should remove any listeners
        // from the PatchConnection (which may be shared with other clients)
        this.patchConnection.removeAllParameterListener (this.paramListener);
    }

    getHTML()
    {
        return `
        <style>
            .demo-patch-element {
                background: rgb(96, 102, 108);
                display: block;
                width: 100%;
                height: auto;
                padding: 10px;
                overflow: auto;
            }

            .param {
                display: inline-flex;
                flex-direction: column;
                align-items: center;
                justify-content: center;
                margin: 30px;
                width: 100px;
                
                float: right;
            }

            .mix-param {
                width: 180px;
            }

            #mix {
                display: flex;
                width: 100%;
                margin-bottom: 20px;
                margin-top: 30px;
                float: left;
                vertical-align: auto;
                border: 1px solid rgb(0, 0, 0);
                background: #132f3d;
                background: radial-gradient(circle, rgba(19, 47, 61, 1) 0%, rgba(102, 185, 196, 1) 100%);
            }

            #controls {
                
                float: right;
                display: inline-flex;  
                flex-direction: row;
            }

            webaudio-knob {
                transform-origin: center center;
            }

            #mixParam {
                transform-origin: center center;
            }

            webaudio-knob::part(label) {
                display: none;
            }

            .knob-label {
                margin-top: 8px;
                text-align: center;
                color: white;
                font-size: 0.85rem;
                user-select: none;
            }

            .param::slotted(*) {
                pointer-events: none;
            }
            
            #dly{
            position: right;
            }

            #fbk{
            position: left;
            }

        </style>

        <header style="text-align: center; color: white; font-size: 1.5rem; margin-bottom: 20px; font-weight: bold;">
            Delay Grain<br>
            <span style="font-size: 1rem; font-weight: normal;">by Victor Schulhoff</span>
        </header>
        
        <div style="display: inline-flex;  flex-direction: row; horizontal-align: center; border: 1px solid rgb(0, 0, 0); background: rgba(102, 185, 196, 1);">
        <div id="mix" class="param">
            <div style="display:flex;flex-direction:column;align-items:center;">
              <webaudio-knob class="param mix-param" style="vertical-align: middle;" id="mixParam" min="0" max="1" step="0.001" src="view/Sky_Blue_Bevel.png" width="140" height="140"></webaudio-knob>
              <div class="knob-label">Mix</div>
            </div>
        </div>
        <section id="controls" style="background: #020f1a; background: radial-gradient(circle, rgba(2, 15, 26, 1) 0%, rgba(102, 185, 196, 1) 100%); border-left: 1px solid rgb(0, 0, 0);">
            <article class="param" id="dly">
                <div style="display:flex;flex-direction:column;align-items:center;">
                  <webaudio-knob class="param" id="maxDelayParam" min="0" max="0.03" step="0.0001" width="80"  src="view/Middle_Potion.png" height="80"></webaudio-knob>
                  <div class="knob-label">Max Delay</div>
                </div>
                <div style="display:flex;flex-direction:column;align-items:center;">
                  <webaudio-knob class="param" id="feedbackParam"  min="0" max="1" step="0.001" src="view/Middle_Potion.png"  width="80" height="80"></webaudio-knob>
                  <div class="knob-label">Feedback</div>
                </div>
            </article>
            <br><br>
            <article class="param" id="fbk">   
                <div style="display:flex;flex-direction:column;align-items:center;">
                  <webaudio-knob class="param" id="cutoffParam" min="0" max="1" step="0.001"  src="view/Middle_Potion.png"  width="80" height="80"></webaudio-knob>
                  <div class="knob-label">Cutoff</div>
                </div>
                <div style="display:flex;flex-direction:column;align-items:center;">
                  <webaudio-knob class="param" id="resonanceParam" min="0" max="1" step="0.001"  src="view/Middle_Potion.png" width="80" height="80"></webaudio-knob>
                  <div class="knob-label">Resonance</div>
                </div>
            </article>
        </section>
        </div>
        `;

    }
}


/* This is the function that a host (the command line patch player, or a Cmajor plugin
   loader, or our VScode extension, etc) will call in order to create a view for your patch.

   Ultimately, a DOM element must be returned to the caller for it to append to its document.
   However, this function can be `async` if you need to perform asyncronous tasks, such as
   fetching remote resources for use in the view, before completing.

   When using libraries such as React, this is where the call to `ReactDOM.createRoot` would
   go, rendering into a container component before returning.
*/
export default function createPatchView (patchConnection)
{
    const customElementName = "demo-patch-view";

    if (! window.customElements.get (customElementName))
        window.customElements.define (customElementName, DemoView);

    return new (window.customElements.get (customElementName)) (patchConnection);
}
