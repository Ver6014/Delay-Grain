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
            {
                slider.value = event.value * 100.0;
                this.updateKnob(slider);
            }
        };

        this.patchConnection.addAllParameterListener (this.paramListener);

        for (const slider of this.querySelectorAll (".knob"))
        {
            this.patchConnection.requestParameterValue (slider.id);
            slider.value = 50; // default
            this.createKnob(slider);
        }
    }

    createKnob(knob)
    {
        const svg = document.createElementNS("http://www.w3.org/2000/svg", "svg");
        svg.setAttribute("width", "80");
        svg.setAttribute("height", "80");
        svg.setAttribute("transform", "rotate(-90 40 40)");
        const circle = document.createElementNS("http://www.w3.org/2000/svg", "circle");
        circle.setAttribute("cx", "40");
        circle.setAttribute("cy", "40");
        circle.setAttribute("r", "35");
        circle.setAttribute("fill", "#ea3b93");
        circle.setAttribute("stroke", "#000");
        circle.setAttribute("stroke-width", "2");
        const line = document.createElementNS("http://www.w3.org/2000/svg", "line");
        line.setAttribute("x1", "40");
        line.setAttribute("y1", "40");
        line.setAttribute("stroke", "#000");
        line.setAttribute("stroke-width", "3");
        line.setAttribute("stroke-linecap", "round");
        svg.appendChild(circle);
        svg.appendChild(line);
        knob.appendChild(svg);
        this.updateKnob(knob);

        let isDragging = false;
        const startDrag = (e) => {
            isDragging = true;
            updateValue(e);
        };
        const drag = (e) => {
            if (isDragging) updateValue(e);
        };
        const endDrag = () => {
            isDragging = false;
        };
        const updateValue = (e) => {
            const rect = svg.getBoundingClientRect();
            const relativeY = e.clientY - rect.top;
            const value = Math.max(0, Math.min(100, ((rect.height - relativeY) / rect.height) * 100));
            knob.value = value;
            this.updateKnob(knob);
            this.patchConnection.sendEventOrValue(knob.id, value / 100.0);
        };
        svg.addEventListener('mousedown', startDrag);
        document.addEventListener('mousemove', drag);
        document.addEventListener('mouseup', endDrag);
    }

    updateKnob(knob)
    {
        const line = knob.querySelector('line');
        const angle = (knob.value / 100) * 270 - 225;
        const rad = angle * Math.PI / 180;
        const x2 = 40 + 25 * Math.cos(rad);
        const y2 = 40 + 25 * Math.sin(rad);
        line.setAttribute('x2', x2);
        line.setAttribute('y2', y2);

        const valueId = knob.id.replace('Param', 'Value');
        const valueDiv = this.querySelector('#' + valueId);
        if (valueDiv) valueDiv.textContent = knob.value.toFixed(0);
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
            <div id="console" class="console">
                
                <p>Max Delay</p>
                <div class="knob" id="maxDelayParam"></div>
                <div class="value-display" id="maxDelayValue">50</div>
                
                <p>Feedback</p>
                <div class="knob" id="feedbackParam"></div>
                <div class="value-display" id="feedbackValue">50</div>
               
                <p>Mix</p>
                <div class="knob" id="mixParam"></div>
                <div class="value-display" id="mixValue">50</div>
                
                <p>Cutoff</p>
                <div class="knob" id="cutoffParam"></div>
                <div class="value-display" id="cutoffValue">50</div>
                
               
                <p>Resonance</p>
                <div class="knob" id="resonanceParam"></div>
                <div class="value-display" id="resonanceValue">50</div>
               
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
