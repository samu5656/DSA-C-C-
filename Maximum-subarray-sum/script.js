// ============================================================
// MAXIMUM SUBARRAY SUM
// O(n²) BRUTE FORCE ANIMATION
// ============================================================


// ------------------------------------------------------------
// INPUT ARRAY
// ------------------------------------------------------------

const arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4];

const n = arr.length;


// ------------------------------------------------------------
// TOTAL NUMBER OF CONTIGUOUS SUBARRAYS
// n(n + 1) / 2
// ------------------------------------------------------------

const totalSubarrays =
    n * (n + 1) / 2;


// ------------------------------------------------------------
// DOM ELEMENTS
// ------------------------------------------------------------

const arrayContainer =
    document.getElementById("arrayContainer");

const pointerContainer =
    document.getElementById("pointerContainer");

const iValue =
    document.getElementById("iValue");

const jValue =
    document.getElementById("jValue");

const currentSumElement =
    document.getElementById("currentSum");

const maxSumElement =
    document.getElementById("maxSum");

const subarrayElement =
    document.getElementById("subarray");

const calculationElement =
    document.getElementById("calculation");

const explanation =
    document.getElementById("explanation");

const subarrayCount =
    document.getElementById("subarrayCount");

const progressFill =
    document.getElementById("progressFill");

const stepNumber =
    document.getElementById("stepNumber");

const nextBtn =
    document.getElementById("nextBtn");

const prevBtn =
    document.getElementById("prevBtn");

const autoBtn =
    document.getElementById("autoBtn");

const resetBtn =
    document.getElementById("resetBtn");

const result =
    document.getElementById("result");

const finalArray =
    document.getElementById("finalArray");

const finalSum =
    document.getElementById("finalSum");


// ------------------------------------------------------------
// ALGORITHM STATE
// ------------------------------------------------------------

let i = 0;

let j = 0;

let currentSum = 0;

let maxSum = -Infinity;
let bestStart = 0;
let bestEnd = 0;

let started = false;

let finished = false;

let step = 0;

let completedSubarrays = 0;

let autoPlaying = false;

let autoInterval = null;

let history = [];


// ------------------------------------------------------------
// EXECUTION STATE
//
// Each subarray requires two visual stages:
//
// 1. Add arr[j] to currentSum
// 2. Compare currentSum with maxSum
//
// ------------------------------------------------------------

let stage = 0;


// stage 0:
// add arr[j]
//
// stage 1:
// compare/update maxSum


// ------------------------------------------------------------
// HISTORY
// ------------------------------------------------------------

function getActiveLineId() {

    const activeLine =
        document.querySelector(".code-line.active");

    return activeLine
        ? activeLine.id
        : null;

}


function saveState() {

    history.push({
        i,
        j,
        currentSum,
        maxSum,
        bestStart,
        bestEnd,
        started,
        finished,
        step,
        completedSubarrays,
        stage,
        explanationHtml: explanation.innerHTML,
        calculationHtml: calculationElement.innerHTML,
        activeLineId: getActiveLineId(),
        resultVisible: result.classList.contains("show"),
        finalArrayText: finalArray.textContent,
        finalSumText: finalSum.textContent
    });

    updateButtonStates();

}


function restoreState(state) {

    i = state.i;
    j = state.j;
    currentSum = state.currentSum;
    maxSum = state.maxSum;
    bestStart = state.bestStart;
    bestEnd = state.bestEnd;
    started = state.started;
    finished = state.finished;
    step = state.step;
    completedSubarrays = state.completedSubarrays;
    stage = state.stage;

    explanation.innerHTML =
        state.explanationHtml;

    calculationElement.innerHTML =
        state.calculationHtml;

    finalArray.textContent =
        state.finalArrayText;

    finalSum.textContent =
        state.finalSumText;

    result.classList.toggle(
        "show",
        state.resultVisible
    );

    clearCodeHighlight();

    if (state.activeLineId) {

        const activeLine =
            document.getElementById(
                state.activeLineId
            );

        if (activeLine) {

            activeLine.classList.add(
                "active"
            );

        }

    }

    updateAll();

    if (finished) {

        document
            .querySelectorAll(".array-element")
            .forEach(element => {

                element.classList.remove("current");
                element.classList.remove("j-active");
                element.classList.remove("maximum");

            });

        for (
            let index = bestStart;
            index <= bestEnd;
            index++
        ) {

            const element =
                document.getElementById(
                    `array-${index}`
                );

            if (element) {

                element.classList.add(
                    "maximum"
                );

            }

        }

    }

    updateButtonStates();

}


function updateButtonStates() {

    prevBtn.disabled =
        history.length === 0;

    nextBtn.disabled =
        finished;

}


// ------------------------------------------------------------
// CREATE ARRAY
// ------------------------------------------------------------

function createArray() {

    arrayContainer.innerHTML = "";

    arr.forEach((value, index) => {

        const element =
            document.createElement("div");

        element.classList.add(
            "array-element"
        );

        element.id =
            `array-${index}`;

        element.textContent =
            value;

        arrayContainer.appendChild(
            element
        );

    });

}


// ------------------------------------------------------------
// CREATE POINTER
// ------------------------------------------------------------

function createPointer(type, label) {

    const pointer =
        document.createElement("div");

    pointer.classList.add(
        "pointer"
    );

    pointer.classList.add(
        `pointer-${type}`
    );

    pointer.id =
        `pointer-${type}`;

    pointer.innerHTML = `
        <div class="pointer-arrow">↓</div>
        <div>${label}</div>
    `;

    pointerContainer.appendChild(
        pointer
    );

}


// ------------------------------------------------------------
// MOVE POINTER
// ------------------------------------------------------------

function updatePointer(
    pointerId,
    index
) {

    const pointer =
        document.getElementById(
            pointerId
        );

    if (!pointer) {
        return;
    }


    const element =
        document.getElementById(
            `array-${index}`
        );

    if (!element) {
        return;
    }


    const containerRect =
        arrayContainer.getBoundingClientRect();

    const elementRect =
        element.getBoundingClientRect();


    const position =
        elementRect.left -
        containerRect.left +
        elementRect.width / 2;


    pointer.style.left =
        `${position}px`;

}


// ------------------------------------------------------------
// CLEAR CODE HIGHLIGHT
// ------------------------------------------------------------

function clearCodeHighlight() {

    document
        .querySelectorAll(".code-line")
        .forEach(line => {

            line.classList.remove(
                "active"
            );

        });

}


// ------------------------------------------------------------
// HIGHLIGHT CODE LINE
// ------------------------------------------------------------

function highlightLine(
    lineNumber
) {

    clearCodeHighlight();


    const line =
        document.getElementById(
            `line${lineNumber}`
        );


    if (line) {

        line.classList.add(
            "active"
        );

    }

}


// ------------------------------------------------------------
// UPDATE ARRAY VISUALIZATION
// ------------------------------------------------------------

function updateArray() {

    document
        .querySelectorAll(
            ".array-element"
        )
        .forEach(element => {

            element.classList.remove(
                "current"
            );

            element.classList.remove(
                "j-active"
            );

            element.classList.remove(
                "maximum"
            );

        });


    if (!started) {
        return;
    }


    // Highlight current subarray

    for (
        let index = i;
        index <= j;
        index++
    ) {

        const element =
            document.getElementById(
                `array-${index}`
            );


        if (element) {

            element.classList.add(
                "current"
            );

        }

    }


    // Highlight current j

    const jElement =
        document.getElementById(
            `array-${j}`
        );


    if (jElement) {

        jElement.classList.add(
            "j-active"
        );

    }

}


// ------------------------------------------------------------
// UPDATE VARIABLES
// ------------------------------------------------------------

function updateVariables() {

    iValue.textContent =
        started ? i : "-";


    jValue.textContent =
        started ? j : "-";


    currentSumElement.textContent =
        currentSum;


    maxSumElement.textContent =
        maxSum === -Infinity
            ? "-"
            : maxSum;

}


// ------------------------------------------------------------
// UPDATE CURRENT SUBARRAY
// ------------------------------------------------------------

function updateSubarray() {

    if (!started) {

        subarrayElement.textContent =
            "-";

        return;

    }


    const subarray =
        arr.slice(
            i,
            j + 1
        );


    subarrayElement.textContent =
        `[${subarray.join(", ")}]`;

}


// ------------------------------------------------------------
// UPDATE PROGRESS
// ------------------------------------------------------------

function updateProgress() {

    subarrayCount.textContent =
        `${completedSubarrays} / ${totalSubarrays}`;


    const percentage =
        (
            completedSubarrays /
            totalSubarrays
        ) * 100;


    progressFill.style.width =
        `${percentage}%`;


    stepNumber.textContent =
        step;

}


// ------------------------------------------------------------
// UPDATE EVERYTHING
// ------------------------------------------------------------

function updateAll() {

    updateVariables();

    updateSubarray();

    updateProgress();

    updateArray();

    const iPointer =
        document.getElementById("pointer-i");

    const jPointer =
        document.getElementById("pointer-j");


    if (started) {

        if (iPointer) {

            iPointer.style.display =
                "block";

        }

        if (jPointer) {

            jPointer.style.display =
                "block";

        }

        updatePointer(
            "pointer-i",
            i
        );


        updatePointer(
            "pointer-j",
            j
        );

    }
    else {

        if (iPointer) {

            iPointer.style.display =
                "none";

        }

        if (jPointer) {

            jPointer.style.display =
                "none";

        }

    }

}


// ------------------------------------------------------------
// START
// ------------------------------------------------------------

function startAnimation() {

    started = true;

    i = 0;

    j = 0;

    currentSum = 0;

    maxSum = -Infinity;

    completedSubarrays = 0;

    step = 1;

    stage = 0;

    finished = false;


    highlightLine(1);


    explanation.innerHTML = `
        <strong>Step ${step}:</strong><br><br>

        The outer loop starts with
        <strong>i = 0</strong>.

        This means the subarray starts
        from index 0.
    `;


    calculationElement.textContent =
        "currentSum = 0";


    updateAll();

}


// ------------------------------------------------------------
// NEXT STEP
// ------------------------------------------------------------

function nextStep() {

    saveState();

    // First click

    if (!started) {

        startAnimation();

        return;

    }


    // Stop when completed

    if (finished) {

        return;

    }


    step++;


    // ========================================================
    // STAGE 0
    //
    // currentSum += arr[j]
    // ========================================================

    if (stage === 0) {

        highlightLine(4);


        const oldSum =
            currentSum;


        currentSum += arr[j];


        calculationElement.innerHTML = `
            currentSum = ${oldSum}
            + (${arr[j]})
            = <strong>${currentSum}</strong>
        `;


        explanation.innerHTML = `
            <strong>Step ${step}:</strong><br><br>

            j = <strong>${j}</strong><br>

            arr[j] = <strong>${arr[j]}</strong><br><br>

            Add the current element to
            the running sum.

            <br><br>

            ${oldSum} + (${arr[j]})
            =
            <strong>${currentSum}</strong>
        `;


        stage = 1;


        updateAll();


        return;

    }


    // ========================================================
    // STAGE 1
    //
    // if currentSum > maxSum
    // ========================================================

    if (stage === 1) {

        highlightLine(5);

        if (currentSum > maxSum) {

            maxSum = currentSum;

            bestStart = i;
            bestEnd = j;

            highlightLine(6);

            explanation.innerHTML = `
        <strong>Step ${step}:</strong><br><br>

        Current Sum =
        <strong>${currentSum}</strong><br><br>

        This is greater than the previous
        maximum.

        <br><br>

        Therefore:

        <br>

        maxSum =
        <strong>${maxSum}</strong>

        <br><br>

        Best Subarray =
        <strong>[${arr.slice(bestStart, bestEnd + 1).join(", ")}]</strong>
    `;
        }
        else {

            explanation.innerHTML = `
                <strong>Step ${step}:</strong><br><br>

                Current Sum =
                <strong>${currentSum}</strong><br>

                Maximum Sum =
                <strong>${maxSum}</strong>

                <br><br>

                Since the current sum is not
                greater, maxSum remains unchanged.
            `;

        }


        // Current subarray completed

        completedSubarrays++;


        calculationElement.innerHTML = `
            maxSum = <strong>${maxSum}</strong>
        `;


        stage = 2;


        updateAll();


        return;

    }


    // ========================================================
    // STAGE 2
    //
    // Move j forward
    // ========================================================

    if (stage === 2) {

        j++;


        if (j < n) {

            highlightLine(3);


            explanation.innerHTML = `
                <strong>Step ${step}:</strong><br><br>

                Move <strong>j</strong> to the next
                position.

                <br><br>

                i = <strong>${i}</strong><br>

                j = <strong>${j}</strong>

                <br><br>

                The subarray now expands by
                one element.
            `;


            calculationElement.innerHTML =
                `Ready to add arr[${j}]`;


            stage = 0;


            updateAll();


            return;

        }


        // ====================================================
        // j reached the end
        // Move i forward
        // ====================================================

        i++;


        if (i < n) {

            j = i;

            currentSum = 0;

            highlightLine(1);


            explanation.innerHTML = `
                <strong>Step ${step}:</strong><br><br>

                All subarrays starting from
                the previous <strong>i</strong>
                have been checked.

                <br><br>

                Move to the next starting index:

                <br>

                i = <strong>${i}</strong>
            `;


            calculationElement.innerHTML =
                "currentSum = 0";


            stage = 0;


            updateAll();


            return;

        }


        // ====================================================
        // COMPLETE
        // ====================================================

        finishAnimation();

    }

}


// ------------------------------------------------------------
// FINISH
// ------------------------------------------------------------

function finishAnimation() {

    finished = true;

    completedSubarrays = totalSubarrays;

    clearCodeHighlight();

    /*
        bestStart and bestEnd contain
        the actual maximum subarray.

        For the sample:

        bestStart = 3
        bestEnd   = 6

        [4, -1, 2, 1]
    */


    // Remove all previous highlighting

    document
        .querySelectorAll(".array-element")
        .forEach(element => {

            element.classList.remove("current");
            element.classList.remove("j-active");
            element.classList.remove("maximum");

        });


    // Highlight the COMPLETE maximum subarray

    for (
        let index = bestStart;
        index <= bestEnd;
        index++
    ) {

        const element =
            document.getElementById(
                `array-${index}`
            );

        if (element) {

            element.classList.add(
                "maximum"
            );

        }

    }


    // Display final result

    const bestSubarray =
        arr.slice(
            bestStart,
            bestEnd + 1
        );


    finalArray.textContent =
        `[${bestSubarray.join(", ")}]`;


    finalSum.textContent =
        maxSum;


    result.classList.add(
        "show"
    );


    /*
        IMPORTANT:

        Keep i and j at the actual
        maximum subarray instead of
        displaying 9 and 9.
    */

    i = bestStart;

    j = bestEnd;


    updateVariables();

    updateSubarray();


    explanation.innerHTML = `
        <strong>Algorithm Complete!</strong>

        <br><br>

        Every possible contiguous subarray
        has been checked.

        <br><br>

        Maximum Subarray:

        <strong>
            [${bestSubarray.join(", ")}]
        </strong>

        <br>

        Maximum Sum:

        <strong>${maxSum}</strong>
    `;


    calculationElement.innerHTML = `
        Final Answer =
        <strong>${maxSum}</strong>
    `;


    updateProgress();


    stopAutoPlay();

    updateButtonStates();

}


// ------------------------------------------------------------
// NEXT BUTTON
// ------------------------------------------------------------

nextBtn.addEventListener(
    "click",
    nextStep
);


// ------------------------------------------------------------
// PREVIOUS BUTTON
// ------------------------------------------------------------

prevBtn.addEventListener(
    "click",
    previousStep
);


function previousStep() {

    if (history.length === 0) {

        return;

    }

    stopAutoPlay();

    const previousState =
        history.pop();

    restoreState(
        previousState
    );

}


// ------------------------------------------------------------
// AUTO PLAY
// ------------------------------------------------------------

autoBtn.addEventListener(
    "click",
    () => {

        if (autoPlaying) {

            stopAutoPlay();

        }
        else {

            startAutoPlay();

        }

    }
);


function startAutoPlay() {

    if (finished) {

        resetAnimation();

    }


    autoPlaying = true;

    autoBtn.textContent =
        "Pause";


    autoInterval =
        setInterval(
            () => {

                nextStep();


                if (finished) {

                    stopAutoPlay();

                }

            },
            700
        );

}


function stopAutoPlay() {

    autoPlaying = false;

    autoBtn.textContent =
        "Auto Play";


    clearInterval(
        autoInterval
    );

}


// ------------------------------------------------------------
// RESET
// ------------------------------------------------------------

resetBtn.addEventListener(
    "click",
    resetAnimation
);


function resetAnimation() {

    stopAutoPlay();


    i = 0;

    j = 0;

    currentSum = 0;

    maxSum = -Infinity;

    bestStart = 0;

    bestEnd = 0;

    started = false;

    finished = false;

    step = 0;

    completedSubarrays = 0;

    stage = 0;

    history = [];


    result.classList.remove(
        "show"
    );


    clearCodeHighlight();


    calculationElement.textContent =
        'Click "Next Step" to begin.';


    explanation.innerHTML = `
        Click <strong>Next Step</strong>
        to start the dry run.
    `;


    updateAll();

    updateButtonStates();

}


// ------------------------------------------------------------
// INITIALIZE
// ------------------------------------------------------------

createArray();


createPointer(
    "i",
    "i"
);


createPointer(
    "j",
    "j"
);


updateAll();


updateButtonStates();
