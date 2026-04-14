//
//     ,ad888ba,                              88
//    d8"'    "8b
//   d8            88,dba,,adba,   ,aPP8A.A8  88     The Cmajor Toolkit
//   Y8,           88    88    88  88     88  88
//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd
//     '"Y888Y"'   88    88    88  '"8bbP"Y8  88     https://cmajor.dev
//                                           ,88
//                                        888P"
//
//  The Cmajor project is subject to commercial or open-source licensing.
//  You may use it under the terms of the GPLv3 (see www.gnu.org/licenses), or
//  visit https://cmajor.dev to learn about our commercial licence options.
//
//  CMAJOR IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER
//  EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE
//  DISCLAIMED.

// Auto-generated Cmajor code for patch 'SmoothRandomDelayFilter'

#include <JuceHeader.h>
#include "cmajor/helpers/cmaj_JUCEPlugin.h"
#include "choc/javascript/choc_javascript_QuickJS.h"



#include <cstdint>
#include <cmath>
#include <string>
#include <cstring>
#include <array>
#include <stdexcept>

//==============================================================================
/// Auto-generated C++ class for the 'SmoothRandomDelayFilter' processor
///

#if ! (defined (__cplusplus) && (__cplusplus >= 201703L))
 #error "This code requires that your compiler is set to use C++17 or later!"
#endif

namespace performer
{
    struct SmoothRandomDelayFilter
    {
        SmoothRandomDelayFilter() = default;
        ~SmoothRandomDelayFilter() = default;

        static constexpr std::string_view name = "SmoothRandomDelayFilter";

        //==============================================================================
        using EndpointHandle = uint32_t;

        enum class EndpointType
        {
            stream,
            event,
            value
        };

        struct EndpointInfo
        {
            uint32_t handle;
            const char* name;
            EndpointType endpointType;
        };

        //==============================================================================
        static constexpr uint32_t numInputEndpoints  = 6;
        static constexpr uint32_t numOutputEndpoints = 1;

        static constexpr uint32_t maxFramesPerBlock  = 512;
        static constexpr uint32_t eventBufferSize    = 32;
        static constexpr uint32_t maxOutputEventSize = 0;
        static constexpr double   latency            = 0.000000;

        enum class EndpointHandles
        {
            in             = 1,
            out            = 7,
            maxDelayParam  = 2,
            feedbackParam  = 3,
            mixParam       = 4,
            cutoffParam    = 5,
            resonanceParam = 6
        };

        static constexpr uint32_t getEndpointHandleForName (std::string_view endpointName)
        {
            if (endpointName == "in")              return static_cast<uint32_t> (EndpointHandles::in);
            if (endpointName == "out")             return static_cast<uint32_t> (EndpointHandles::out);
            if (endpointName == "maxDelayParam")   return static_cast<uint32_t> (EndpointHandles::maxDelayParam);
            if (endpointName == "feedbackParam")   return static_cast<uint32_t> (EndpointHandles::feedbackParam);
            if (endpointName == "mixParam")        return static_cast<uint32_t> (EndpointHandles::mixParam);
            if (endpointName == "cutoffParam")     return static_cast<uint32_t> (EndpointHandles::cutoffParam);
            if (endpointName == "resonanceParam")  return static_cast<uint32_t> (EndpointHandles::resonanceParam);
            return 0;
        }

        static constexpr EndpointInfo inputEndpoints[] =
        {
            { 1,  "in",              EndpointType::stream },
            { 2,  "maxDelayParam",   EndpointType::event  },
            { 3,  "feedbackParam",   EndpointType::event  },
            { 4,  "mixParam",        EndpointType::event  },
            { 5,  "cutoffParam",     EndpointType::event  },
            { 6,  "resonanceParam",  EndpointType::event  }
        };

        static constexpr EndpointInfo outputEndpoints[] =
        {
            { 7,  "out",  EndpointType::stream }
        };

        //==============================================================================
        static constexpr uint32_t numAudioInputChannels  = 1;
        static constexpr uint32_t numAudioOutputChannels = 1;

        static constexpr std::array outputAudioStreams
        {
            outputEndpoints[0]
        };

        static constexpr std::array<EndpointInfo, 0> outputEvents {};

        static constexpr std::array<EndpointInfo, 0> outputMIDIEvents {};

        static constexpr std::array inputAudioStreams
        {
            inputEndpoints[0]
        };

        static constexpr std::array inputEvents
        {
            inputEndpoints[1],
            inputEndpoints[2],
            inputEndpoints[3],
            inputEndpoints[4],
            inputEndpoints[5]
        };

        static constexpr std::array<EndpointInfo, 0> inputMIDIEvents {};

        static constexpr std::array inputParameters
        {
            inputEndpoints[1],
            inputEndpoints[2],
            inputEndpoints[3],
            inputEndpoints[4],
            inputEndpoints[5]
        };

        static constexpr const char* programDetailsJSON =
                "{\n"
                "  \"mainProcessor\": \"SmoothRandomDelayFilter\",\n"
                "  \"inputs\": [\n"
                "    {\n"
                "      \"endpointID\": \"in\",\n"
                "      \"endpointType\": \"stream\",\n"
                "      \"dataType\": {\n"
                "        \"type\": \"float32\"\n"
                "      },\n"
                "      \"purpose\": \"audio in\",\n"
                "      \"numAudioChannels\": 1\n"
                "    },\n"
                "    {\n"
                "      \"endpointID\": \"maxDelayParam\",\n"
                "      \"endpointType\": \"event\",\n"
                "      \"dataType\": {\n"
                "        \"type\": \"float32\"\n"
                "      },\n"
                "      \"annotation\": {\n"
                "        \"name\": \"Max Grain\",\n"
                "        \"min\": 0.0,\n"
                "        \"max\": 0.03,\n"
                "        \"init\": 0\n"
                "      },\n"
                "      \"purpose\": \"parameter\"\n"
                "    },\n"
                "    {\n"
                "      \"endpointID\": \"feedbackParam\",\n"
                "      \"endpointType\": \"event\",\n"
                "      \"dataType\": {\n"
                "        \"type\": \"float32\"\n"
                "      },\n"
                "      \"annotation\": {\n"
                "        \"name\": \"Feedback\",\n"
                "        \"min\": 0.0,\n"
                "        \"max\": 1,\n"
                "        \"init\": 0\n"
                "      },\n"
                "      \"purpose\": \"parameter\"\n"
                "    },\n"
                "    {\n"
                "      \"endpointID\": \"mixParam\",\n"
                "      \"endpointType\": \"event\",\n"
                "      \"dataType\": {\n"
                "        \"type\": \"float32\"\n"
                "      },\n"
                "      \"annotation\": {\n"
                "        \"name\": \"Mix\",\n"
                "        \"min\": 0.0,\n"
                "        \"max\": 1,\n"
                "        \"init\": 0\n"
                "      },\n"
                "      \"purpose\": \"parameter\"\n"
                "    },\n"
                "    {\n"
                "      \"endpointID\": \"cutoffParam\",\n"
                "      \"endpointType\": \"event\",\n"
                "      \"dataType\": {\n"
                "        \"type\": \"float32\"\n"
                "      },\n"
                "      \"annotation\": {\n"
                "        \"name\": \"Cutoff\",\n"
                "        \"min\": 0.0,\n"
                "        \"max\": 1,\n"
                "        \"init\": 0\n"
                "      },\n"
                "      \"purpose\": \"parameter\"\n"
                "    },\n"
                "    {\n"
                "      \"endpointID\": \"resonanceParam\",\n"
                "      \"endpointType\": \"event\",\n"
                "      \"dataType\": {\n"
                "        \"type\": \"float32\"\n"
                "      },\n"
                "      \"annotation\": {\n"
                "        \"name\": \"Resonance\",\n"
                "        \"min\": 0.0,\n"
                "        \"max\": 1,\n"
                "        \"init\": 0\n"
                "      },\n"
                "      \"purpose\": \"parameter\"\n"
                "    }\n"
                "  ],\n"
                "  \"outputs\": [\n"
                "    {\n"
                "      \"endpointID\": \"out\",\n"
                "      \"endpointType\": \"stream\",\n"
                "      \"dataType\": {\n"
                "        \"type\": \"float32\"\n"
                "      },\n"
                "      \"purpose\": \"audio out\",\n"
                "      \"numAudioChannels\": 1\n"
                "    }\n"
                "  ]\n"
                "}";

        //==============================================================================
        struct intrinsics;

        using SizeType = int32_t;
        using IndexType = int32_t;
        using StringHandle = uint32_t;

        struct Null
        {
            template <typename AnyType> operator AnyType() const    { return {}; }
            Null operator[] (IndexType) const                       { return {}; }
        };

        //==============================================================================
        template <typename ElementType, SizeType numElements>
        struct Array
        {
            Array() = default;
            Array (Null) {}
            Array (const Array&) = default;

            template <typename ElementOrList>
            Array (const ElementOrList& value) noexcept
            {
                if constexpr (std::is_convertible<ElementOrList, ElementType>::value)
                {
                    for (IndexType i = 0; i < numElements; ++i)
                        this->elements[i] = static_cast<ElementType> (value);
                }
                else
                {
                    for (IndexType i = 0; i < numElements; ++i)
                        this->elements[i] = static_cast<ElementType> (value[i]);
                }
            }

            template <typename... Others>
            Array (ElementType e0, ElementType e1, Others... others) noexcept
            {
                this->elements[0] = static_cast<ElementType> (e0);
                this->elements[1] = static_cast<ElementType> (e1);

                if constexpr (numElements > 2)
                {
                    const ElementType initialisers[] = { static_cast<ElementType> (others)... };

                    for (size_t i = 0; i < sizeof...(others); ++i)
                        this->elements[i + 2] = initialisers[i];
                }
            }

            Array (const ElementType* rawArray, size_t) noexcept
            {
                for (IndexType i = 0; i < numElements; ++i)
                    this->elements[i] = rawArray[i];
            }

            Array& operator= (const Array&) noexcept = default;
            Array& operator= (Null) noexcept                 { this->clear(); return *this; }

            template <typename ElementOrList>
            Array& operator= (const ElementOrList& value) noexcept
            {
                if constexpr (std::is_convertible<ElementOrList, ElementType>::value)
                {
                    for (IndexType i = 0; i < numElements; ++i)
                        this->elements[i] = static_cast<ElementType> (value);
                }
                else
                {
                    for (IndexType i = 0; i < numElements; ++i)
                        this->elements[i] = static_cast<ElementType> (value[i]);
                }
            }

            static constexpr SizeType size()                                    { return numElements; }

            const ElementType& operator[] (IndexType index) const noexcept      { return this->elements[index]; }
            ElementType& operator[] (IndexType index) noexcept                  { return this->elements[index]; }

            void clear() noexcept
            {
                for (auto& element : elements)
                    element = ElementType();
            }

            void clear (SizeType numElementsToClear) noexcept
            {
                for (SizeType i = 0; i < numElementsToClear; ++i)
                    elements[i] = ElementType();
            }

            ElementType elements[numElements] = {};
        };

        //==============================================================================
        template <typename ElementType, SizeType numElements>
        struct Vector  : public Array<ElementType, numElements>
        {
            Vector() = default;
            Vector (Null) {}

            template <typename ElementOrList>
            Vector (const ElementOrList& value) noexcept  : Array<ElementType, numElements> (value) {}

            template <typename... Others>
            Vector (ElementType e0, ElementType e1, Others... others) noexcept  : Array<ElementType, numElements> (e0, e1, others...) {}

            Vector (const ElementType* rawArray, size_t) noexcept  : Array<ElementType, numElements> (rawArray, size_t()) {}

            template <typename ElementOrList>
            Vector& operator= (const ElementOrList& value) noexcept { return Array<ElementType, numElements>::operator= (value); }

            Vector& operator= (Null) noexcept { this->clear(); return *this; }

            operator ElementType() const noexcept
            {
                static_assert (numElements == 1);
                return this->elements[0];
            }

            constexpr auto operator!() const noexcept     { return performUnaryOp ([] (ElementType n) { return ! n; }); }
            constexpr auto operator~() const noexcept     { return performUnaryOp ([] (ElementType n) { return ~n; }); }
            constexpr auto operator-() const noexcept     { return performUnaryOp ([] (ElementType n) { return -n; }); }

            constexpr auto operator+ (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a + b; }); }
            constexpr auto operator- (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a - b; }); }
            constexpr auto operator* (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a * b; }); }
            constexpr auto operator/ (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a / b; }); }
            constexpr auto operator% (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return intrinsics::modulo (a, b); }); }
            constexpr auto operator& (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a & b; }); }
            constexpr auto operator| (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a | b; }); }
            constexpr auto operator<< (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a << b; }); }
            constexpr auto operator>> (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a >> b; }); }

            constexpr auto operator== (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a == b; }); }
            constexpr auto operator!= (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a != b; }); }
            constexpr auto operator<  (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a < b; }); }
            constexpr auto operator<= (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a <= b; }); }
            constexpr auto operator>  (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a > b; }); }
            constexpr auto operator>= (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a >= b; }); }

            template <typename Functor>
            constexpr Vector performUnaryOp (Functor&& f) const noexcept
            {
                Vector result;

                for (IndexType i = 0; i < numElements; ++i)
                    result.elements[i] = f (this->elements[i]);

                return result;
            }

            template <typename Functor>
            constexpr Vector performBinaryOp (const Vector& rhs, Functor&& f) const noexcept
            {
                Vector result;

                for (IndexType i = 0; i < numElements; ++i)
                    result.elements[i] = f (this->elements[i], rhs.elements[i]);

                return result;
            }

            template <typename Functor>
            constexpr Vector<bool, numElements> performComparison (const Vector& rhs, Functor&& f) const noexcept
            {
                Vector<bool, numElements> result;

                for (IndexType i = 0; i < numElements; ++i)
                    result.elements[i] = f (this->elements[i], rhs.elements[i]);

                return result;
            }
        };

        //==============================================================================
        template <typename ElementType>
        struct Slice
        {
            Slice() = default;
            Slice (Null) {}
            Slice (ElementType* e, SizeType size) : elements (e), numElements (size) {}
            Slice (const Slice&) = default;
            Slice& operator= (const Slice&) = default;
            template <typename ArrayType> Slice (const ArrayType& a) : elements (const_cast<ArrayType&> (a).elements), numElements (a.size()) {}
            template <typename ArrayType> Slice (const ArrayType& a, SizeType offset, SizeType size) : elements (const_cast<ArrayType&> (a).elements + offset), numElements (size) {}

            constexpr SizeType size() const                                     { return numElements; }
            ElementType operator[] (IndexType index) const noexcept             { return numElements == 0 ? ElementType() : elements[index]; }
            ElementType& operator[] (IndexType index) noexcept                  { return numElements == 0 ? emptyValue : elements[index]; }

            Slice slice (IndexType start, IndexType end) noexcept
            {
                if (numElements == 0) return {};
                if (start >= numElements) return {};

                return { elements + start, std::min (static_cast<SizeType> (end - start), numElements - start) };
            }

            const Slice slice (IndexType start, IndexType end) const noexcept
            {
                if (numElements == 0) return {};
                if (start >= numElements) return {};

                return { elements + start, std::min (static_cast<SizeType> (end - start), numElements - start) };
            }

            ElementType* elements = nullptr;
            SizeType numElements = 0;

            static inline ElementType emptyValue {};
        };

        //==============================================================================
        #if __clang__
         #pragma clang diagnostic push
         #pragma clang diagnostic ignored "-Wunused-variable"
         #pragma clang diagnostic ignored "-Wunused-parameter"
         #pragma clang diagnostic ignored "-Wunused-label"
         #pragma clang diagnostic ignored "-Wtautological-compare"

         #if __clang_major__ >= 14
          #pragma clang diagnostic ignored "-Wunused-but-set-variable"
         #endif

         #if __clang_major__ >= 17
          #pragma clang diagnostic ignored "-Wnan-infinity-disabled"
         #endif

        #elif __GNUC__
         #pragma GCC diagnostic push
         #pragma GCC diagnostic ignored "-Wunused-variable"
         #pragma GCC diagnostic ignored "-Wunused-parameter"
         #pragma GCC diagnostic ignored "-Wunused-but-set-variable"
         #pragma GCC diagnostic ignored "-Wunused-label"
        #else
         #pragma warning (push, 0)
         #pragma warning (disable: 4702)
         #pragma warning (disable: 4706)
        #endif

        //==============================================================================
        struct _SmoothRandomDelayFilter_State
        {
            float maxDelay = {};
            float feedback = {};
            float mix = {};
            float cutoffVal = {};
            float resonance = {};
            Array<float, 44100> delayBuffer;
            int32_t writeIndex = {};
            float s1 = {};
            float s2 = {};
            int32_t randState = {};
            float currentDelay = {};
            float targetDelay = {};
            int32_t _sessionID = {};
            double _frequency = {};
            int32_t _resumeIndex = {};
        };

        struct SmoothRandomDelayFilter_State
        {
            int32_t _currentFrame = {};
            _SmoothRandomDelayFilter_State _state;
        };

        struct SmoothRandomDelayFilter_IO
        {
            Array<float, 512> in;
            Array<float, 512> out;
        };

        struct _SmoothRandomDelayFilter_IO
        {
            float in = {};
            float out = {};
        };

        using std_intrinsics_T = float;

        //==============================================================================
        double getMaxFrequency() const
        {
            return 192000.0;
        }

        void initialise (int32_t sessionID, double frequency)
        {
            if (frequency > getMaxFrequency()) throw std::runtime_error ("frequency out of range");
            initSessionID = sessionID;
            initFrequency = frequency;
            reset();
        }

        void reset()
        {
            std::memset (reinterpret_cast<char*> (&cmajState), 0, sizeof (cmajState));
            int32_t processorID = 0;
            _initialise (cmajState, processorID, initSessionID, initFrequency);
        }

        void advance (int32_t frames)
        {
            cmajIO.out.clear (static_cast<SizeType> (frames));
            _advance (cmajState, cmajIO, frames);
        }

        void copyOutputValue (EndpointHandle endpointHandle, void* dest)
        {
            (void) endpointHandle; (void) dest;

            throw std::runtime_error ("Unknown value endpointHandle:" + std::to_string (endpointHandle));
        }

        void copyOutputFrames (EndpointHandle endpointHandle, void* dest, uint32_t numFramesToCopy)
        {
            if (endpointHandle == 7) { std::memcpy (reinterpret_cast<char*> (dest), std::addressof (cmajIO.out), 4 * numFramesToCopy); std::memset (reinterpret_cast<char*> (std::addressof (cmajIO.out)), 0, 4 * numFramesToCopy); return; }
            throw std::runtime_error ("Unknown stream endpointHandle:" + std::to_string (endpointHandle));
        }

        uint32_t getNumOutputEvents (EndpointHandle endpointHandle)
        {
            (void) endpointHandle;

            throw std::runtime_error ("Unknown event endpointHandle:" + std::to_string (endpointHandle));
            return {};
        }

        void resetOutputEventCount (EndpointHandle endpointHandle)
        {
            (void) endpointHandle;
        }

        uint32_t getOutputEventType (EndpointHandle endpointHandle, uint32_t index)
        {
            (void) endpointHandle; (void) index;

            throw std::runtime_error ("Unknown event endpointHandle:" + std::to_string (endpointHandle));
            return {};
        }

        static uint32_t getOutputEventDataSize (EndpointHandle endpointHandle, uint32_t typeIndex)
        {
            (void) endpointHandle; (void) typeIndex;

            throw std::runtime_error ("Unknown event endpointHandle:" + std::to_string (endpointHandle));
            return 0;
        }

        uint32_t readOutputEvent (EndpointHandle endpointHandle, uint32_t index, unsigned char* dest)
        {

            (void) endpointHandle; (void) index; (void) dest;

            throw std::runtime_error ("Unknown event endpointHandle:" + std::to_string (endpointHandle));
            return {};
        }

        void addEvent_maxDelayParam (float event)
        {
            _sendEvent_maxDelayParam (cmajState, event);
        }

        void addEvent_feedbackParam (float event)
        {
            _sendEvent_feedbackParam (cmajState, event);
        }

        void addEvent_mixParam (float event)
        {
            _sendEvent_mixParam (cmajState, event);
        }

        void addEvent_cutoffParam (float event)
        {
            _sendEvent_cutoffParam (cmajState, event);
        }

        void addEvent_resonanceParam (float event)
        {
            _sendEvent_resonanceParam (cmajState, event);
        }

        void addEvent (EndpointHandle endpointHandle, uint32_t typeIndex, const unsigned char* eventData)
        {
            (void) endpointHandle; (void) typeIndex; (void) eventData;

            if (endpointHandle == 2)
            {
                float value;
                memcpy (&value, eventData, 4);
                eventData += 4;
                return addEvent_maxDelayParam (value);
            }

            if (endpointHandle == 3)
            {
                float value;
                memcpy (&value, eventData, 4);
                eventData += 4;
                return addEvent_feedbackParam (value);
            }

            if (endpointHandle == 4)
            {
                float value;
                memcpy (&value, eventData, 4);
                eventData += 4;
                return addEvent_mixParam (value);
            }

            if (endpointHandle == 5)
            {
                float value;
                memcpy (&value, eventData, 4);
                eventData += 4;
                return addEvent_cutoffParam (value);
            }

            if (endpointHandle == 6)
            {
                float value;
                memcpy (&value, eventData, 4);
                eventData += 4;
                return addEvent_resonanceParam (value);
            }
        }

        void setValue (EndpointHandle endpointHandle, const void* value, int32_t frames)
        {
            (void) endpointHandle; (void) value; (void) frames;
        }

        void setInputFrames_in (const void* data, uint32_t numFrames, uint32_t numTrailingFramesToClear)
        {
            memcpy (cmajIO.in.elements, data, numFrames * 4);
            if (numTrailingFramesToClear != 0) memset (reinterpret_cast<char*> (cmajIO.in.elements + numFrames), 0, numTrailingFramesToClear * 4);
        }

        void setInputFrames (EndpointHandle endpointHandle, const void* frameData, uint32_t numFrames, uint32_t numTrailingFramesToClear)
        {
            if (endpointHandle == 1) return setInputFrames_in (frameData, numFrames, numTrailingFramesToClear);
        }

        //==============================================================================
        // Rendering state values
        int32_t initSessionID;
        double initFrequency;
        SmoothRandomDelayFilter_State cmajState = {};
        SmoothRandomDelayFilter_IO cmajIO = {};

        //==============================================================================
        void _sendEvent_maxDelayParam (SmoothRandomDelayFilter_State& _state, float value) noexcept
        {
            _SmoothRandomDelayFilter__maxDelayParam (_state._state, value);
        }

        void _SmoothRandomDelayFilter__maxDelayParam (_SmoothRandomDelayFilter_State& _state, float v) noexcept
        {
            _state.maxDelay = v;
        }

        void _sendEvent_feedbackParam (SmoothRandomDelayFilter_State& _state, float value) noexcept
        {
            _SmoothRandomDelayFilter__feedbackParam (_state._state, value);
        }

        void _SmoothRandomDelayFilter__feedbackParam (_SmoothRandomDelayFilter_State& _state, float v) noexcept
        {
            _state.feedback = v;
        }

        void _sendEvent_mixParam (SmoothRandomDelayFilter_State& _state, float value) noexcept
        {
            _SmoothRandomDelayFilter__mixParam (_state._state, value);
        }

        void _SmoothRandomDelayFilter__mixParam (_SmoothRandomDelayFilter_State& _state, float v) noexcept
        {
            _state.mix = v;
        }

        void _sendEvent_cutoffParam (SmoothRandomDelayFilter_State& _state, float value) noexcept
        {
            _SmoothRandomDelayFilter__cutoffParam (_state._state, value);
        }

        void _SmoothRandomDelayFilter__cutoffParam (_SmoothRandomDelayFilter_State& _state, float v) noexcept
        {
            _state.cutoffVal = v;
        }

        void _sendEvent_resonanceParam (SmoothRandomDelayFilter_State& _state, float value) noexcept
        {
            _SmoothRandomDelayFilter__resonanceParam (_state._state, value);
        }

        void _SmoothRandomDelayFilter__resonanceParam (_SmoothRandomDelayFilter_State& _state, float v) noexcept
        {
            _state.resonance = v;
        }

        void _initialise (SmoothRandomDelayFilter_State& _state, int32_t& processorID, int32_t sessionID, double frequency) noexcept
        {
            _SmoothRandomDelayFilter___initialise (_state._state, processorID, sessionID, frequency);
        }

        void _SmoothRandomDelayFilter___initialise (_SmoothRandomDelayFilter_State& _state, int32_t& processorID, int32_t sessionID, double frequency) noexcept
        {
            g__sessionID = sessionID;
            g__frequency = frequency;
            _state.maxDelay = 0.25f;
            _state.feedback = 0.4f;
            _state.mix = 0.5f;
            _state.cutoffVal = 0.5f;
            _state.resonance = 0.0f;
            _state.randState = int32_t {1};
            _state.targetDelay = 0.25f;
            _state.currentDelay = 0.25f;
            _state.s1 = 0.0f;
            _state.s2 = 0.0f;
        }

        void _advance (SmoothRandomDelayFilter_State& _state, SmoothRandomDelayFilter_IO& _io, int32_t _frames) noexcept
        {
            _SmoothRandomDelayFilter_IO  ioCopy;

            for (;;)
            {
                if (_state._currentFrame == _frames)
                {
                    break;
                }
                ioCopy = _SmoothRandomDelayFilter_IO {};
                ioCopy.in = _io.in[_state._currentFrame];
                _SmoothRandomDelayFilter__main (_state._state, ioCopy);
                _io.out[_state._currentFrame] = ioCopy.out;
                ++_state._currentFrame;
            }
            _state._currentFrame = int32_t {0};
        }

        void _SmoothRandomDelayFilter__main (_SmoothRandomDelayFilter_State& _state, _SmoothRandomDelayFilter_IO& _io) noexcept
        {
            float  maxD;
            float  fb;
            float  mx;
            float  cutoffHz;
            float  delaySamples;
            int32_t  baseIndex;
            float  frac;
            int32_t  index0;
            int32_t  index1;
            float  delayed;
            float  f;

            for (;;)
            {
                maxD = intrinsics::clamp (_state.maxDelay, 0.0f, 1.0f);
                fb = intrinsics::clamp (_state.feedback, 0.0f, 0.95f);
                mx = intrinsics::clamp (_state.mix, 0.0f, 1.0f);
                cutoffHz = 100.0f + (intrinsics::clamp (_state.cutoffVal, 0.0f, 1.0f) * 8000.0f);
                _state.targetDelay = (_SmoothRandomDelayFilter__random (_state) * maxD);
                _state.currentDelay = (_state.currentDelay + ((_state.targetDelay - _state.currentDelay) * g_smoothFactor));
                delaySamples = _state.currentDelay * static_cast<float> (1.0 * g__frequency);
                baseIndex = _state.writeIndex - static_cast<int32_t> (delaySamples);
                frac = delaySamples - static_cast<float> (static_cast<int32_t> (delaySamples));
                index0 = intrinsics::modulo (baseIndex + int32_t {44100}, int32_t {44100});
                index1 = intrinsics::modulo ((index0 - int32_t {1}) + int32_t {44100}, int32_t {44100});
                delayed = (_state.delayBuffer[std__intrinsics___wrap_44100 (index0)] * (1.0f - frac)) + (_state.delayBuffer[std__intrinsics___wrap_44100 (index1)] * frac);
                _state.delayBuffer[_state.writeIndex] = (_io.in + (delayed * fb));
                f = cutoffHz / static_cast<float> (1.0 * g__frequency);
                f = intrinsics::clamp (f, 0.0f, 0.9f);
                _state.s1 = (_state.s1 + (f * (delayed - _state.s1)));
                _state.s2 = (_state.s2 + (f * (_state.s1 - _state.s2)));
                _io.out = (_io.out + ((_io.in * (1.0f - mx)) + (_state.s2 * mx)));
                std__intrinsics___wrapped_post_inc_44100 (_state.writeIndex);
                return;
            }
        }

        float std__intrinsics__clamp (float value, float minimum, float maximum) noexcept
        {
            return (value > maximum) ? maximum : ((value < minimum) ? minimum : value);
        }

        float _SmoothRandomDelayFilter__random (_SmoothRandomDelayFilter_State& _state) noexcept
        {
            int32_t  masked;

            _state.randState = ((_state.randState * int32_t {0x19660d}) + int32_t {0x3c6ef35f});
            masked = _state.randState & int32_t {0x7fffffff};
            return static_cast<float> (masked) / 2147483600.0f;
        }

        int32_t std__intrinsics___wrap_44100 (int32_t n) noexcept
        {
            int32_t  x;

            x = intrinsics::modulo (n, int32_t {44100});
            return (x < int32_t {0}) ? (x + int32_t {44100}) : x;
        }

        int32_t std__intrinsics___wrapped_post_inc_44100 (int32_t& n) noexcept
        {
            int32_t  result;

            result = n;
            n = std__intrinsics___wrap_44100 (n + int32_t {1});
            return result;
        }

        //==============================================================================
        const char* getStringForHandle (uint32_t handle, size_t& stringLength)
        {
            (void) handle; (void) stringLength;
            return "";
        }

        //==============================================================================
        int32_t g__sessionID {};
        double g__frequency {};
        static constexpr float g_smoothFactor { 0.002f };

        //==============================================================================
        struct intrinsics
        {
            template <typename T> static T modulo (T a, T b)
            {
                if constexpr (std::is_floating_point<T>::value)
                    return std::fmod (a, b);
                else
                    return a % b;
            }

            template <typename T> static T addModulo2Pi (T a, T b)
            {
                constexpr auto twoPi = static_cast<T> (3.141592653589793238 * 2);
                auto n = a + b;
                return n >= twoPi ? std::remainder (n, twoPi) : n;
            }

            template <typename T> static T abs           (T a)              { return std::abs (a); }
            template <typename T> static T min           (T a, T b)         { return std::min (a, b); }
            template <typename T> static T max           (T a, T b)         { return std::max (a, b); }
            template <typename T> static T clamp         (T a, T b, T c)    { return a < b ? b : (a > c ? c : a); }
            template <typename T> static T wrap          (T a, T b)         { if (b == 0) return 0; auto n = modulo (a, b); if (n < 0) n += b; return n; }
            template <typename T> static T fmod          (T a, T b)         { return b != 0 ? std::fmod (a, b) : 0; }
            template <typename T> static T remainder     (T a, T b)         { return b != 0 ? std::remainder (a, b) : 0; }
            template <typename T> static T floor         (T a)              { return std::floor (a); }
            template <typename T> static T ceil          (T a)              { return std::ceil (a); }
            template <typename T> static T rint          (T a)              { return std::rint (a); }
            template <typename T> static T sqrt          (T a)              { return std::sqrt (a); }
            template <typename T> static T pow           (T a, T b)         { return std::pow (a, b); }
            template <typename T> static T exp           (T a)              { return std::exp (a); }
            template <typename T> static T log           (T a)              { return std::log (a); }
            template <typename T> static T log10         (T a)              { return std::log10 (a); }
            template <typename T> static T sin           (T a)              { return std::sin (a); }
            template <typename T> static T cos           (T a)              { return std::cos (a); }
            template <typename T> static T tan           (T a)              { return std::tan (a); }
            template <typename T> static T sinh          (T a)              { return std::sinh (a); }
            template <typename T> static T cosh          (T a)              { return std::cosh (a); }
            template <typename T> static T tanh          (T a)              { return std::tanh (a); }
            template <typename T> static T asinh         (T a)              { return std::asinh (a); }
            template <typename T> static T acosh         (T a)              { return std::acosh (a); }
            template <typename T> static T atanh         (T a)              { return std::atanh (a); }
            template <typename T> static T asin          (T a)              { return std::asin (a); }
            template <typename T> static T acos          (T a)              { return std::acos (a); }
            template <typename T> static T atan          (T a)              { return std::atan (a); }
            template <typename T> static T atan2         (T a, T b)         { return std::atan2 (a, b); }
            template <typename T> static T isnan         (T a)              { return std::isnan (a) ? 1 : 0; }
            template <typename T> static T isinf         (T a)              { return std::isinf (a) ? 1 : 0; }
            template <typename T> static T select        (bool c, T a, T b) { return c ? a : b; }

            static int32_t reinterpretFloatToInt (float   a)                { int32_t i; memcpy (std::addressof(i), std::addressof(a), sizeof(i)); return i; }
            static int64_t reinterpretFloatToInt (double  a)                { int64_t i; memcpy (std::addressof(i), std::addressof(a), sizeof(i)); return i; }
            static float   reinterpretIntToFloat (int32_t a)                { float   f; memcpy (std::addressof(f), std::addressof(a), sizeof(f)); return f; }
            static double  reinterpretIntToFloat (int64_t a)                { double  f; memcpy (std::addressof(f), std::addressof(a), sizeof(f)); return f; }

            static int32_t rightShiftUnsigned (int32_t a, int32_t b)        { return static_cast<int32_t> (static_cast<uint32_t> (a) >> b); }
            static int64_t rightShiftUnsigned (int64_t a, int64_t b)        { return static_cast<int64_t> (static_cast<uint64_t> (a) >> b); }

            struct VectorOps
            {
                template <typename Vec> static Vec abs     (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::abs (x); }); }
                template <typename Vec> static Vec min     (Vec a, Vec b)     { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::min (x, y); }); }
                template <typename Vec> static Vec max     (Vec a, Vec b)     { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::max (x, y); }); }
                template <typename Vec> static Vec sqrt    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::sqrt (x); }); }
                template <typename Vec> static Vec log     (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::log (x); }); }
                template <typename Vec> static Vec log10   (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::log10 (x); }); }
                template <typename Vec> static Vec sin     (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::sin (x); }); }
                template <typename Vec> static Vec cos     (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::cos (x); }); }
                template <typename Vec> static Vec tan     (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::tan (x); }); }
                template <typename Vec> static Vec sinh    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::sinh (x); }); }
                template <typename Vec> static Vec cosh    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::cosh (x); }); }
                template <typename Vec> static Vec tanh    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::tanh (x); }); }
                template <typename Vec> static Vec asinh   (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::asinh (x); }); }
                template <typename Vec> static Vec acosh   (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::acosh (x); }); }
                template <typename Vec> static Vec atanh   (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::atanh (x); }); }
                template <typename Vec> static Vec asin    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::asin (x); }); }
                template <typename Vec> static Vec acos    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::acos (x); }); }
                template <typename Vec> static Vec atan    (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::atan (x); }); }
                template <typename Vec> static Vec atan2   (Vec a, Vec b)     { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::atan2 (x, y); }); }
                template <typename Vec> static Vec pow     (Vec a, Vec b)     { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::pow (x, y); }); }
                template <typename Vec> static Vec exp     (Vec a)            { return a.performUnaryOp ([] (auto x) { return intrinsics::exp (x); }); }

                template <typename Vec> static Vec rightShiftUnsigned (Vec a, Vec b) { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::rightShiftUnsigned (x, y); }); }
            };
        };

        static constexpr float  _inf32  =  std::numeric_limits<float>::infinity();
        static constexpr double _inf64  =  std::numeric_limits<double>::infinity();
        static constexpr float  _ninf32 = -std::numeric_limits<float>::infinity();
        static constexpr double _ninf64 = -std::numeric_limits<double>::infinity();
        static constexpr float  _nan32  =  std::numeric_limits<float>::quiet_NaN();
        static constexpr double _nan64  =  std::numeric_limits<double>::quiet_NaN();

        //==============================================================================
        #if __clang__
         #pragma clang diagnostic pop
        #elif __GNUC__
         #pragma GCC diagnostic pop
        #else
         #pragma warning (pop)
        #endif
    };
} // namespace performer



struct SmoothRandomDelayFilter
{
    using PerformerClass = performer::SmoothRandomDelayFilter;
    static constexpr auto filename = "delaygrain.cmajorpatch";

    struct File { std::string_view name, content; };

    static constexpr const char* cmaj_api_cmajaudioworklethelper_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "import { PatchConnection } from \"./cmaj-patch-connection.js\"\n"
        "\n"
        "//==============================================================================\n"
        "// N.B. code will be serialised to a string, so all `registerWorkletProcessor`s\n"
        "// dependencies must be self contained and not capture things in the outer scope\n"
        "async function serialiseWorkletProcessorFactoryToDataURI (CmajorClass, workletName, hostDescription)\n"
        "{\n"
        "    const serialisedInvocation = `(${registerWorkletProcessor.toString()}) (\"${workletName}\", ${CmajorClass.toString()}, \"${hostDescription}\");`\n"
        "\n"
        "    let reader = new FileReader();\n"
        "    reader.readAsDataURL (new Blob ([serialisedInvocation], { type: \"text/javascript\" }));\n"
        "\n"
        "    return await new Promise (res => { reader.onloadend = () => res (reader.result); });\n"
        "}\n"
        "\n"
        "function registerWorkletProcessor (workletName, CmajorClass, hostDescription)\n"
        "{\n"
        "    function makeConsumeOutputEvents ({ wrapper, eventOutputs, dispatchOutputEvent })\n"
        "    {\n"
        "        const outputEventHandlers = eventOutputs.map (({ endpointID }) =>\n"
        "        {\n"
        "            const readCount = wrapper[`getOutputEventCount_${endpointID}`]?.bind (wrapper);\n"
        "            const reset = wrapper[`resetOutputEventCount_${endpointID}`]?.bind (wrapper);\n"
        "            const readEventAtIndex = wrapper[`getOutputEvent_${endpointID}`]?.bind (wrapper);\n"
        "\n"
        "            return () =>\n"
        "            {\n"
        "                const count = readCount();\n"
        "\n"
        "                for (let i = 0; i < count; ++i)\n"
        "                    dispatchOutputEvent (endpointID, readEventAtIndex (i));\n"
        "\n"
        "                reset();\n"
        "            };\n"
        "        });\n"
        "\n"
        "        return () => outputEventHandlers.forEach ((consume) => consume() );\n"
        "    }\n"
        "\n"
        "    function setInitialParameterValues (parametersMap)\n"
        "    {\n"
        "        for (const { initialise } of Object.values (parametersMap))\n"
        "            initialise();\n"
        "    }\n"
        "\n"
        "    function makeEndpointMap (wrapper, endpoints, initialValueOverrides)\n"
        "    {\n"
        "        const toKey = ({ endpointType, endpointID }) =>\n"
        "        {\n"
        "            switch (endpointType)\n"
        "            {\n"
        "                case \"event\": return `sendInputEvent_${endpointID}`;\n"
        "                case \"value\": return `setInputValue_${endpointID}`;\n"
        "            }\n"
        "\n"
        "            throw \"Unhandled endpoint type\";\n"
        "        };\n"
        "\n"
        "        const lookup = {};\n"
        "\n"
        "        for (const { endpointID, endpointType, annotation, purpose } of endpoints)\n"
        "        {\n"
        "            const key = toKey ({ endpointType, endpointID });\n"
        "            const wrapperUpdate = wrapper[key]?.bind (wrapper);\n"
        "\n"
        "            const snapAndConstrainValue = (value) =>\n"
        "            {\n"
        "                if (annotation.step != null)\n"
        "                    value = Math.round (value / annotation.step) * annotation.step;\n"
        "\n"
        "                if (annotation.min != null && annotation.max != null)\n"
        "                    value = Math.min (Math.max (value, annotation.min), annotation.max);\n"
        "\n"
        "                return value;\n"
        "            };\n"
        "\n"
        "            const update = (value, rampFrames) =>\n"
        "            {\n"
        "                // N.B. value clamping and rampFrames from annotations not currently applied\n"
        "                const entry = lookup[endpointID];\n"
        "                entry.cachedValue = value;\n"
        "                wrapperUpdate (value, rampFrames);\n"
        "            };\n"
        "\n"
        "            if (update)\n"
        "            {\n"
        "                const initialValue = initialValueOverrides[endpointID] ?\? annotation?.init;\n"
        "\n"
        "                lookup[endpointID] = {\n"
        "                    snapAndConstrainValue,\n"
        "                    update,\n"
        "                    initialise: initialValue != null ? () => update (initialValue) : () => {},\n"
        "                    purpose,\n"
        "                    cachedValue: undefined,\n"
        "                };\n"
        "            }\n"
        "        }\n"
        "\n"
        "        return lookup;\n"
        "    }\n"
        "\n"
        "    function makeStreamEndpointHandler ({ wrapper, toEndpoints, wrapperMethodNamePrefix })\n"
        "    {\n"
        "        const endpoints = toEndpoints (wrapper);\n"
        "        if (endpoints.length === 0)\n"
        "            return () => {};\n"
        "\n"
        "        let handlers = [];\n"
        "        let targetChannels = [];\n"
        "        let channelCount = 0;\n"
        "\n"
        "        for (const endpoint of endpoints)\n"
        "        {\n"
        "            const handleFrames = wrapper[`${wrapperMethodNamePrefix}_${endpoint.endpointID}`]?.bind (wrapper);\n"
        "\n"
        "            if (! handleFrames)\n"
        "                return () => {};\n"
        "\n"
        "            handlers.push (handleFrames);\n"
        "            targetChannels.push (channelCount);\n"
        "            channelCount += endpoint.numAudioChannels;\n"
        "        }\n"
        "\n"
        "        return (channels, blockSize) =>\n"
        "        {\n"
        "            for (let i = 0; i < handlers.length; i++)\n"
        "                handlers[i] (channels, blockSize, targetChannels[i]);\n"
        "        }\n"
        "    }\n"
        "\n"
        "    function makeInputStreamEndpointHandler (wrapper)\n"
        "    {\n"
        "        return makeStreamEndpointHandler ({\n"
        "            wrapper,\n"
        "            toEndpoints: wrapper => wrapper.getInputEndpoints().filter (({ purpose }) => purpose === \"audio in\"),\n"
        "            wrapperMethodNamePrefix: \"setInputStreamFrames\",\n"
        "        });\n"
        "    }\n"
        "\n"
        "    function makeOutputStreamEndpointHandler (wrapper)\n"
        "    {\n"
        "        return makeStreamEndpointHandler ({\n"
        "            wrapper,\n"
        "            toEndpoints: wrapper => wrapper.getOutputEndpoints().filter (({ purpose }) => purpose === \"audio out\"),\n"
        "            wrapperMethodNamePrefix: \"getOutputFrames\",\n"
        "        });\n"
        "    }\n"
        "\n"
        "    class WorkletProcessor extends AudioWorkletProcessor\n"
        "    {\n"
        "        static get parameterDescriptors()\n"
        "        {\n"
        "            return [];\n"
        "        }\n"
        "\n"
        "        constructor ({ processorOptions, ...options })\n"
        "        {\n"
        "            super (options);\n"
        "\n"
        "            this.processImpl = undefined;\n"
        "            this.consumeOutputEvents = undefined;\n"
        "\n"
        "            const { sessionID = Date.now() & 0x7fffffff, initialValueOverrides = {} } = processorOptions;\n"
        "\n"
        "            const wrapper = new CmajorClass();\n"
        "\n"
        "            wrapper.initialise (sessionID, sampleRate)\n"
        "                .then (() => this.initialisePatch (wrapper, initialValueOverrides))\n"
        "                .catch (error => { throw new Error (error)});\n"
        "        }\n"
        "\n"
        "        process (inputs, outputs)\n"
        "        {\n"
        "            const input = inputs[0];\n"
        "            const output = outputs[0];\n"
        "\n"
        "            this.processImpl?.(input, output);\n"
        "            this.consumeOutputEvents?.();\n"
        "\n"
        "            return true;\n"
        "        }\n"
        "\n"
        "        sendPatchMessage (payload)\n"
        "        {\n"
        "            this.port.postMessage ({ type: \"patch\", payload });\n"
        "        }\n"
        "\n"
        "        sendParameterValueChanged (endpointID, value)\n"
        "        {\n"
        "            this.sendPatchMessage ({\n"
        "                type: \"param_value\",\n"
        "                message: { endpointID, value }\n"
        "            });\n"
        "        }\n"
        "\n"
        "        initialisePatch (wrapper, initialValueOverrides)\n"
        "        {\n"
        "            try\n"
        "            {\n"
        "                const inputParameters = wrapper.getInputEndpoints().filter (({ purpose }) => purpose === \"parameter\");\n"
        "                const parametersMap = makeEndpointMap (wrapper, inputParameters, initialValueOverrides);\n"
        "\n"
        "                setInitialParameterValues (parametersMap);\n"
        "\n"
        "                const toParameterValuesWithKey = (endpointKey, parametersMap) =>\n"
        "                {\n"
        "                    const toValue = ([endpoint, { cachedValue }]) => ({ [endpointKey]: endpoint, value: cachedValue });\n"
        "                    return Object.entries (parametersMap).map (toValue);\n"
        "                };\n"
        "\n"
        "                const initialValues = toParameterValuesWithKey (\"endpointID\", parametersMap);\n"
        "                const initialState = wrapper.getState();\n"
        "\n"
        "                const resetState = () =>\n"
        "                {\n"
        "                    wrapper.restoreState (initialState);\n"
        "\n"
        "                    // N.B. update cache used for `req_param_value` messages (we don't currently read from the wasm heap)\n"
        "                    setInitialParameterValues (parametersMap);\n"
        "                };\n"
        "\n"
        "                const isNonAudioOrParameterEndpoint = ({ purpose }) => ! [\"audio in\", \"parameter\"].includes (purpose);\n"
        "                const otherInputs = wrapper.getInputEndpoints().filter (isNonAudioOrParameterEndpoint);\n"
        "                const otherInputEndpointsMap = makeEndpointMap (wrapper, otherInputs, initialValueOverrides);\n"
        "\n"
        "                const isEvent = ({ endpointType }) => endpointType === \"event\";\n"
        "                const eventInputs = wrapper.getInputEndpoints().filter (isEvent);\n"
        "                const eventOutputs = wrapper.getOutputEndpoints().filter (isEvent);\n"
        "\n"
        "                const makeEndpointListenerMap = (eventEndpoints) =>\n"
        "                {\n"
        "                    const listeners = {};\n"
        "\n"
        "                    for (const { endpointID } of eventEndpoints)\n"
        "                        listeners[endpointID] = [];\n"
        "\n"
        "                    return listeners;\n"
        "                };\n"
        "\n"
        "                const inputEventListeners = makeEndpointListenerMap (eventInputs);\n"
        "                const outputEventListeners = makeEndpointListenerMap (eventOutputs);\n"
        "\n"
        "                this.consumeOutputEvents = makeConsumeOutputEvents ({\n"
        "                    eventOutputs,\n"
        "                    wrapper,\n"
        "                    dispatchOutputEvent: (endpointID, event) =>\n"
        "                    {\n"
        "                        for (const { replyType } of outputEventListeners[endpointID] ?\? [])\n"
        "                        {\n"
        "                            this.sendPatchMessage ({\n"
        "                                type: replyType,\n"
        "                                message: event.event, // N.B. chucking away frame and typeIndex info for now\n"
        "                            });\n"
        "                        }\n"
        "                    },\n"
        "                });\n"
        "\n"
        "                const blockSize = 128;\n"
        "                const prepareInputFrames = makeInputStreamEndpointHandler (wrapper);\n"
        "                const processOutputFrames = makeOutputStreamEndpointHandler (wrapper);\n"
        "\n"
        "                this.processImpl = (input, output) =>\n"
        "                {\n"
        "                    prepareInputFrames (input, blockSize);\n"
        "                    wrapper.advance (blockSize);\n"
        "                    processOutputFrames (output, blockSize);\n"
        "                };\n"
        "\n"
        "                // N.B. the message port makes things straightforward, but it allocates (when sending + receiving).\n"
        "                // so, we aren't doing ourselves any favours. we probably ought to marshal raw bytes over to the gui in\n"
        "                // a pre-allocated lock-free message queue (using `SharedArrayBuffer` + `Atomic`s) and transform the raw\n"
        "                // messages there.\n"
        "                this.port.addEventListener (\"message\", e =>\n"
        "                {\n"
        "                    if (e.data.type !== \"patch\")\n"
        "                        return;\n"
        "\n"
        "                    const msg = e.data.payload;\n"
        "\n"
        "                    switch (msg.type)\n"
        "                    {\n"
        "                        case \"req_status\":\n"
        "                        {\n"
        "                            this.sendPatchMessage ({\n"
        "                                type: \"status\",\n"
        "                                message: {\n"
        "                                    details: {\n"
        "                                        inputs: wrapper.getInputEndpoints(),\n"
        "                                        outputs: wrapper.getOutputEndpoints(),\n"
        "                                    },\n"
        "                                    sampleRate,\n"
        "                                    host: hostDescription ? hostDescription : \"WebAudio\"\n"
        "                                },\n"
        "                            });\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        case \"req_reset\":\n"
        "                        {\n"
        "                            resetState();\n"
        "                            initialValues.forEach (v => this.sendParameterValueChanged (v.endpointID, v.value));\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        case \"req_param_value\":\n"
        "                        {\n"
        "                            // N.B. keep a local cache here so that we can send the values back when requested.\n"
        "                            // we could instead have accessors into the wasm heap.\n"
        "                            const endpointID = msg.id;\n"
        "                            const parameter = parametersMap[endpointID];\n"
        "                            if (! parameter)\n"
        "                                return;\n"
        "\n"
        "                            const value = parameter.cachedValue;\n"
        "                            this.sendParameterValueChanged (endpointID, value);\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        case \"send_value\":\n"
        "                        {\n"
        "                            const endpointID = msg.id;\n"
        "                            const parameter = parametersMap[endpointID];\n"
        "\n"
        "                            if (parameter)\n"
        "                            {\n"
        "                                const newValue = parameter.snapAndConstrainValue (msg.value);\n"
        "                                parameter.update (newValue, msg.rampFrames);\n"
        "\n"
        "                                this.sendParameterValueChanged (endpointID, newValue);\n"
        "                                return;\n"
        "                            }\n"
        "\n"
        "                            const inputEndpoint = otherInputEndpointsMap[endpointID];\n"
        "\n"
        "                            if (inputEndpoint)\n"
        "                            {\n"
        "                                inputEndpoint.update (msg.value);\n"
        "\n"
        "                                for (const { replyType } of inputEventListeners[endpointID] ?\? [])\n"
        "                                {\n"
        "                                    this.sendPatchMessage ({\n"
        "                                        type: replyType,\n"
        "                                        message: inputEndpoint.cachedValue,\n"
        "                                    });\n"
        "                                }\n"
        "                            }\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        case \"send_gesture_start\": break;\n"
        "                        case \"send_gesture_end\": break;\n"
        "\n"
        "                        case \"req_full_state\":\n"
        "                            this.sendPatchMessage ({\n"
        "                                type: msg?.replyType,\n"
        "                                message: {\n"
        "                                    parameters: toParameterValuesWithKey (\"name\", parametersMap),\n"
        "                                },\n"
        "                            });\n"
        "                            break;\n"
        "\n"
        "                        case \"send_full_state\":\n"
        "                        {\n"
        "                            const { parameters = [] } = e.data.payload?.value || [];\n"
        "\n"
        "                            for (const [endpointID, parameter] of Object.entries (parametersMap))\n"
        "                            {\n"
        "                                const namedNextValue = parameters.find (({ name }) => name === endpointID);\n"
        "\n"
        "                                if (namedNextValue)\n"
        "                                    parameter.update (namedNextValue.value);\n"
        "                                else\n"
        "                                    parameter.initialise();\n"
        "\n"
        "                                this.sendParameterValueChanged (endpointID, parameter.cachedValue);\n"
        "                            }\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        case \"add_endpoint_listener\":\n"
        "                        {\n"
        "                            const insertIfValidEndpoint = (lookup, msg) =>\n"
        "                            {\n"
        "                                const endpointID = msg?.endpoint;\n"
        "                                const listeners = lookup[endpointID]\n"
        "\n"
        "                                if (! listeners)\n"
        "                                    return false;\n"
        "\n"
        "                                return listeners.push ({ replyType: msg?.replyType }) > 0;\n"
        "                            };\n"
        "\n"
        "                            if (! insertIfValidEndpoint (inputEventListeners, msg))\n"
        "                                insertIfValidEndpoint (outputEventListeners, msg)\n"
        "\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        case \"remove_endpoint_listener\":\n"
        "                        {\n"
        "                            const removeIfValidReplyType = (lookup, msg) =>\n"
        "                            {\n"
        "                                const endpointID = msg?.endpoint;\n"
        "                                const listeners = lookup[endpointID];\n"
        "\n"
        "                                if (! listeners)\n"
        "                                    return false;\n"
        "\n"
        "                                const index = listeners.indexOf (msg?.replyType);\n"
        "\n"
        "                                if (index === -1)\n"
        "                                    return false;\n"
        "\n"
        "                                return listeners.splice (index, 1).length === 1;\n"
        "                            };\n"
        "\n"
        "                            if (! removeIfValidReplyType (inputEventListeners, msg))\n"
        "                                removeIfValidReplyType (outputEventListeners, msg)\n"
        "\n"
        "                            break;\n"
        "                        }\n"
        "\n"
        "                        default:\n"
        "                            break;\n"
        "                    }\n"
        "                });\n"
        "\n"
        "                this.port.postMessage ({ type: \"initialised\" });\n"
        "                this.port.start();\n"
        "            }\n"
        "            catch (e)\n"
        "            {\n"
        "                this.port.postMessage (e.toString());\n"
        "            }\n"
        "        }\n"
        "    }\n"
        "\n"
        "    registerProcessor (workletName, WorkletProcessor);\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "async function connectToAudioIn (audioContext, node)\n"
        "{\n"
        "    try\n"
        "    {\n"
        "        const input = await navigator.mediaDevices.getUserMedia ({\n"
        "            audio: {\n"
        "                echoCancellation: false,\n"
        "                noiseSuppression: false,\n"
        "                autoGainControl:  false,\n"
        "        }});\n"
        "\n"
        "        if (! input)\n"
        "            throw new Error();\n"
        "\n"
        "        const source = audioContext.createMediaStreamSource (input);\n"
        "\n"
        "        if (! source)\n"
        "            throw new Error();\n"
        "\n"
        "        source.connect (node);\n"
        "    }\n"
        "    catch (e)\n"
        "    {\n"
        "        console.warn (`Could not open audio input`);\n"
        "    }\n"
        "}\n"
        "\n"
        "async function connectToMIDI (connection, midiEndpointID)\n"
        "{\n"
        "    try\n"
        "    {\n"
        "        if (! navigator.requestMIDIAccess)\n"
        "            throw new Error (\"Web MIDI API not supported.\");\n"
        "\n"
        "        const midiAccess = await navigator.requestMIDIAccess ({ sysex: true, software: true });\n"
        "\n"
        "        for (const input of midiAccess.inputs.values())\n"
        "        {\n"
        "            input.onmidimessage = ({ data }) =>\n"
        "                connection.sendMIDIInputEvent (midiEndpointID, data[2] | (data[1] << 8) | (data[0] << 16));\n"
        "        }\n"
        "    }\n"
        "    catch (e)\n"
        "    {\n"
        "        console.warn (`Could not open MIDI devices: ${e}`);\n"
        "    }\n"
        "}\n"
        "\n"
        "\n"
        "//==============================================================================\n"
        "/**  This class provides a PatchConnection that controls a Cmajor audio worklet\n"
        " *   node.\n"
        " */\n"
        "export class AudioWorkletPatchConnection extends PatchConnection\n"
        "{\n"
        "    constructor (manifest)\n"
        "    {\n"
        "        super();\n"
        "\n"
        "        this.manifest = manifest;\n"
        "        this.cachedState = {};\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /**  Initialises this connection to load and control the given Cmajor class.\n"
        "     *\n"
        "     *   @param {Object} parameters - the parameters to use\n"
        "     *   @param {Object} parameters.CmajorClass - the generated Cmajor class\n"
        "     *   @param {AudioContext} parameters.audioContext - a web audio AudioContext object\n"
        "     *   @param {string} parameters.workletName - the name to give the new worklet that is created\n"
        "     *   @param {string} parameters.hostDescription - a description of the host that is using the patch\n"
        "     *   @param {number} [parameters.sessionID] - an integer to use for the session ID, or undefined to use a default\n"
        "     *   @param {Object} [parameters.initialValueOverrides] - optional initial values for parameter endpoints\n"
        "     *   @param {string} [parameters.rootResourcePath] - optionally, a root to use when resolving resource paths\n"
        "     */\n"
        "    async initialise ({ CmajorClass,\n"
        "                        audioContext,\n"
        "                        workletName,\n"
        "                        hostDescription,\n"
        "                        sessionID,\n"
        "                        initialValueOverrides,\n"
        "                        rootResourcePath })\n"
        "    {\n"
        "        this.audioContext = audioContext;\n"
        "\n"
        "        if (rootResourcePath)\n"
        "        {\n"
        "            this.rootResourcePath = rootResourcePath.toString();\n"
        "\n"
        "            if (! this.rootResourcePath.endsWith (\"/\"))\n"
        "                this.rootResourcePath += \"/\";\n"
        "        }\n"
        "        else\n"
        "        {\n"
        "            const getBaseUrl = (relativeURL) =>\n"
        "            {\n"
        "                const baseURL = relativeURL.href.substring(0, relativeURL.href.lastIndexOf('/'));\n"
        "                return baseURL;\n"
        "            };\n"
        "\n"
        "            this.rootResourcePath = getBaseUrl(new URL('.', import.meta.url));\n"
        "\n"
        "            if (! this.rootResourcePath.endsWith (\"/\"))\n"
        "                this.rootResourcePath += \"/../\";\n"
        "        }\n"
        "\n"
        "        const dataURI = await serialiseWorkletProcessorFactoryToDataURI (CmajorClass, workletName, hostDescription);\n"
        "        await audioContext.audioWorklet.addModule (dataURI);\n"
        "\n"
        "        this.inputEndpoints = CmajorClass.prototype.getInputEndpoints();\n"
        "        this.outputEndpoints = CmajorClass.prototype.getOutputEndpoints();\n"
        "\n"
        "        const audioInputEndpoints  = this.inputEndpoints.filter (({ purpose }) => purpose === \"audio in\");\n"
        "        const audioOutputEndpoints = this.outputEndpoints.filter (({ purpose }) => purpose === \"audio out\");\n"
        "\n"
        "        let inputChannelCount = 0;\n"
        "        let outputChannelCount = 0;\n"
        "\n"
        "        audioInputEndpoints.forEach  ((endpoint) => { inputChannelCount = inputChannelCount + endpoint.numAudioChannels; });\n"
        "        audioOutputEndpoints.forEach ((endpoint) => { outputChannelCount = outputChannelCount + endpoint.numAudioChannels; });\n"
        "\n"
        "        const hasInput = inputChannelCount > 0;\n"
        "        const hasOutput = outputChannelCount > 0;\n"
        "\n"
        "        const node = new AudioWorkletNode (audioContext, workletName, {\n"
        "            numberOfInputs: +hasInput,\n"
        "            numberOfOutputs: +hasOutput,\n"
        "            channelCountMode: \"explicit\",\n"
        "            channelCount: hasInput ? inputChannelCount : undefined,\n"
        "            outputChannelCount: hasOutput ? [outputChannelCount] : [],\n"
        "\n"
        "            processorOptions:\n"
        "            {\n"
        "                sessionID,\n"
        "                initialValueOverrides\n"
        "            }\n"
        "        });\n"
        "\n"
        "        const waitUntilWorkletInitialised = async () =>\n"
        "        {\n"
        "            return new Promise ((resolve) =>\n"
        "            {\n"
        "                const filterForInitialised = (e) =>\n"
        "                {\n"
        "                    if (e.data.type === \"initialised\")\n"
        "                    {\n"
        "                        node.port.removeEventListener (\"message\", filterForInitialised);\n"
        "                        resolve();\n"
        "                    }\n"
        "                };\n"
        "\n"
        "                node.port.addEventListener (\"message\", filterForInitialised);\n"
        "            });\n"
        "        };\n"
        "\n"
        "        node.port.start();\n"
        "\n"
        "        await waitUntilWorkletInitialised();\n"
        "\n"
        "        this.audioNode = node;\n"
        "\n"
        "        node.port.addEventListener (\"message\", e =>\n"
        "        {\n"
        "            if (e.data.type === \"patch\")\n"
        "            {\n"
        "                const msg = e.data.payload;\n"
        "\n"
        "                if (msg?.type === \"status\")\n"
        "                    msg.message = { manifest: this.manifest, ...msg.message };\n"
        "\n"
        "                this.deliverMessageFromServer (msg)\n"
        "            }\n"
        "        });\n"
        "\n"
        "        await this.startPatchWorker();\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /**  Attempts to connect this connection to the default audio and MIDI channels.\n"
        "     *   This must only be called once initialise() has completed successfully.\n"
        "     *\n"
        "     *   @param {AudioContext} audioContext - a web audio AudioContext object\n"
        "     */\n"
        "    async connectDefaultAudioAndMIDI (audioContext)\n"
        "    {\n"
        "        if (! this.audioNode)\n"
        "            throw new Error (\"AudioWorkletPatchConnection.initialise() must have been successfully completed before calling connectDefaultAudioAndMIDI()\");\n"
        "\n"
        "        const getInputWithPurpose = (purpose) =>\n"
        "        {\n"
        "            for (const i of this.inputEndpoints)\n"
        "                if (i.purpose === purpose)\n"
        "                    return i.endpointID;\n"
        "        }\n"
        "\n"
        "        const midiEndpointID = getInputWithPurpose (\"midi in\");\n"
        "\n"
        "        if (midiEndpointID)\n"
        "            connectToMIDI (this, midiEndpointID);\n"
        "\n"
        "        if (getInputWithPurpose (\"audio in\"))\n"
        "            connectToAudioIn (audioContext, this.audioNode);\n"
        "\n"
        "        this.audioNode.connect (audioContext.destination);\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    sendMessageToServer (msg)\n"
        "    {\n"
        "        this.audioNode.port.postMessage ({ type: \"patch\", payload: msg });\n"
        "    }\n"
        "\n"
        "    requestStoredStateValue (key)\n"
        "    {\n"
        "        this.dispatchEvent (\"state_key_value\", { key, value: this.cachedState[key] });\n"
        "    }\n"
        "\n"
        "    sendStoredStateValue (key, newValue)\n"
        "    {\n"
        "        const changed = this.cachedState[key] != newValue;\n"
        "\n"
        "        if (changed)\n"
        "        {\n"
        "            const shouldRemove = newValue == null;\n"
        "            if (shouldRemove)\n"
        "            {\n"
        "                delete this.cachedState[key];\n"
        "                return;\n"
        "            }\n"
        "\n"
        "            this.cachedState[key] = newValue;\n"
        "            // N.B. notifying the client only when updating matches behaviour of the patch player\n"
        "            this.dispatchEvent (\"state_key_value\", { key, value: newValue });\n"
        "        }\n"
        "    }\n"
        "\n"
        "    sendFullStoredState (fullState)\n"
        "    {\n"
        "        const currentStateCleared = (() =>\n"
        "        {\n"
        "            const out = {};\n"
        "            Object.keys (this.cachedState).forEach (k => out[k] = undefined);\n"
        "            return out;\n"
        "        })();\n"
        "\n"
        "        const incomingStateValues = fullState.values ?\? {};\n"
        "        const nextStateValues = { ...currentStateCleared, ...incomingStateValues };\n"
        "\n"
        "        Object.entries (nextStateValues).forEach (([key, value]) => this.sendStoredStateValue (key, value));\n"
        "\n"
        "        // N.B. worklet will handle the `parameters` part\n"
        "        super.sendFullStoredState (fullState);\n"
        "    }\n"
        "\n"
        "    requestFullStoredState (callback)\n"
        "    {\n"
        "        // N.B. the worklet only handles the `parameters` part, so we patch the key-value state in here\n"
        "        super.requestFullStoredState (msg => callback ({ values: { ...this.cachedState }, ...msg }));\n"
        "    }\n"
        "\n"
        "    getResourceAddress (path)\n"
        "    {\n"
        "        return this.rootResourcePath + path;\n"
        "    }\n"
        "\n"
        "    async readResource (path)\n"
        "    {\n"
        "        return fetch (path);\n"
        "    }\n"
        "\n"
        "    async readResourceAsAudioData (path)\n"
        "    {\n"
        "        const response = await this.readResource (path);\n"
        "        const buffer = await this.audioContext.decodeAudioData (await response.arrayBuffer());\n"
        "\n"
        "        let frames = [];\n"
        "\n"
        "        for (let i = 0; i < buffer.length; ++i)\n"
        "            frames.push ([]);\n"
        "\n"
        "        for (let chan = 0; chan < buffer.numberOfChannels; ++chan)\n"
        "        {\n"
        "            const src = buffer.getChannelData (chan);\n"
        "\n"
        "            for (let i = 0; i < buffer.length; ++i)\n"
        "                frames[i].push (src[i]);\n"
        "        }\n"
        "\n"
        "        return { frames, sampleRate: buffer.sampleRate };\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** @private */\n"
        "    async startPatchWorker()\n"
        "    {\n"
        "        if (this.manifest.worker?.length > 0)\n"
        "        {\n"
        "            const module = await import (this.getResourceAddress (this.manifest.worker));\n"
        "            module.default (this);\n"
        "        }\n"
        "    }\n"
        "}\n";
    static constexpr const char* delaygrain_cmajorpatch =
        "{\n"
        "  \"CmajorVersion\": 1,\n"
        "  \"ID\": \"victorschulhoff.delaygrain\",\n"
        "  \"version\": \"4.5\",\n"
        "  \"name\": \"Delay Grain\",\n"
        "  \"description\": \"Delay grain effect\",\n"
        "  \"manufacturer\": \"Victor Schulhoff\",\n"
        "  \"category\": \"effect\",\n"
        "  \"isInstrument\": false,\n"
        "  \"source\": \"DelayGrain.cmajor\",\n"
        "  \"view\": {\n"
        "    \"src\": \"view/index.js\",\n"
        "    \"width\": 645,\n"
        "    \"height\": 500,\n"
        "    \"resizable\": false\n"
        "  }\n"
        "}";
    static constexpr const char* cmaj_api_assets_cmajorlogo_svg =
        "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"150 140 1620 670\">\n"
        "  <g>\n"
        "    <path\n"
        "      d=\"M944.511,462.372V587.049H896.558V469.165c0-27.572-13.189-44.757-35.966-44.757-23.577,0-39.958,19.183-39.958,46.755V587.049H773.078V469.165c0-27.572-13.185-44.757-35.962-44.757-22.378,0-39.162,19.581-39.162,46.755V587.049H650.4v-201.4h47.551v28.77c8.39-19.581,28.771-32.766,54.346-32.766,27.572,0,46.353,11.589,56.343,35.166,11.589-23.577,33.57-35.166,65.934-35.166C918.937,381.652,944.511,412.42,944.511,462.372Zm193.422-76.724h47.953v201.4h-47.953V557.876c-6.794,19.581-31.167,33.567-64.335,33.567q-42.558,0-71.928-29.969c-19.183-20.381-28.771-45.155-28.771-75.128s9.588-54.743,28.771-74.726c19.581-20.377,43.556-30.366,71.928-30.366,33.168,0,57.541,13.985,64.335,33.566Zm3.6,100.7c0-17.579-5.993-32.368-17.981-43.953-11.589-11.59-26.374-17.583-43.559-17.583s-31.167,5.993-42.756,17.583c-11.187,11.585-16.783,26.374-16.783,43.953s5.6,32.369,16.783,43.958c11.589,11.589,25.575,17.583,42.756,17.583s31.97-5.994,43.559-17.583C1135.537,518.715,1141.53,503.929,1141.53,486.346Zm84.135,113.49c0,21.177-7.594,29.571-25.575,29.571-2.8,0-7.192-.4-13.185-.8v42.357c4.393.8,11.187,1.2,19.979,1.2,44.355,0,66.734-22.776,66.734-67.932V385.648h-47.953Zm23.978-294.108c-15.987,0-28.774,12.385-28.774,28.372s12.787,28.369,28.774,28.369a28.371,28.371,0,0,0,0-56.741Zm239.674,104.694c21.177,20.381,31.966,45.956,31.966,75.924s-10.789,55.547-31.966,75.928-47.154,30.769-77.926,30.769-56.741-10.392-77.922-30.769-31.966-45.955-31.966-75.928,10.789-55.543,31.966-75.924,47.154-30.768,77.922-30.768S1468.136,390.041,1489.317,410.422Zm-15.585,75.924c0-17.981-5.994-32.766-17.985-44.753-11.988-12.39-26.773-18.383-44.356-18.383-17.981,0-32.766,5.993-44.754,18.383-11.589,11.987-17.583,26.772-17.583,44.753s5.994,32.77,17.583,45.156c11.988,11.987,26.773,17.985,44.754,17.985q26.374,0,44.356-17.985C1467.738,519.116,1473.732,504.331,1473.732,486.346Zm184.122-104.694c-28.373,0-50.349,12.787-59.941,33.964V385.648h-47.551v201.4h47.551v-105.9c0-33.169,21.177-53.948,54.345-53.948a102.566,102.566,0,0,1,19.979,2V382.85A74.364,74.364,0,0,0,1657.854,381.652ZM58"
        "0.777,569.25l33.909,30.087c-40.644,47.027-92.892,70.829-156.173,70.829-58.637,0-108.567-19.737-149.788-59.8C268.082,570.31,247.763,519.8,247.763,460s20.319-109.726,60.962-149.786c41.221-40.059,91.151-60.38,149.788-60.38,62.119,0,113.789,22.643,154.432,68.507l-33.864,30.134c-16.261-19.069-35.272-32.933-56.978-41.783V486.346H496.536V621.1Q546.954,610.231,580.777,569.25Zm-237.74,9.1A150.247,150.247,0,0,0,396.5,614.04V486.346H370.929V319.387a159.623,159.623,0,0,0-27.892,22.829Q297.187,389.16,297.186,460C297.186,507.229,312.47,547.06,343.037,578.354Zm115.476,46.66a187.178,187.178,0,0,0,27.28-1.94V486.346H474.548V295.666c-5.236-.426-10.567-.677-16.035-.677a177.387,177.387,0,0,0-40.029,4.4V486.346H407.239v131.4A175.161,175.161,0,0,0,458.513,625.014Z\"\n"
        "      fill=\"#fff\" />\n"
        "  </g>\n"
        "</svg>\n";
    static constexpr const char* cmaj_api_cmajeventlistenerlist_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "\n"
        "/** This event listener management class allows listeners to be attached and\n"
        " *  removed from named event types.\n"
        " */\n"
        "export class EventListenerList\n"
        "{\n"
        "    constructor()\n"
        "    {\n"
        "        this.listenersPerType = {};\n"
        "    }\n"
        "\n"
        "    /** Adds a listener for a specifc event type.\n"
        "     *  If the listener is already registered, this will simply add it again.\n"
        "     *  Each call to addEventListener() must be paired with a removeventListener()\n"
        "     *  call to remove it.\n"
        "     *\n"
        "     *  @param {string} type\n"
        "     */\n"
        "    addEventListener (type, listener)\n"
        "    {\n"
        "        if (type && listener)\n"
        "        {\n"
        "            const list = this.listenersPerType[type];\n"
        "\n"
        "            if (list)\n"
        "                list.push (listener);\n"
        "            else\n"
        "                this.listenersPerType[type] = [listener];\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** Removes a listener that was previously added for the given event type.\n"
        "     *  @param {string} type\n"
        "     */\n"
        "    removeEventListener (type, listener)\n"
        "    {\n"
        "        if (type && listener)\n"
        "        {\n"
        "            const list = this.listenersPerType[type];\n"
        "\n"
        "            if (list)\n"
        "            {\n"
        "                const i = list.indexOf (listener);\n"
        "\n"
        "                if (i >= 0)\n"
        "                    list.splice (i, 1);\n"
        "            }\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** Attaches a callback function that will be automatically unregistered\n"
        "     *  the first time it is invoked.\n"
        "     *\n"
        "     *  @param {string} type\n"
        "     */\n"
        "    addSingleUseListener (type, listener)\n"
        "    {\n"
        "        const l = message =>\n"
        "        {\n"
        "            this.removeEventListener (type, l);\n"
        "            listener?.(message);\n"
        "        };\n"
        "\n"
        "        this.addEventListener (type, l);\n"
        "    }\n"
        "\n"
        "    /** Synchronously dispatches an event object to all listeners\n"
        "     *  that are registered for the given type.\n"
        "     *\n"
        "     *  @param {string} type\n"
        "     */\n"
        "    dispatchEvent (type, event)\n"
        "    {\n"
        "        const list = this.listenersPerType[type];\n"
        "\n"
        "        if (list)\n"
        "            for (const listener of list)\n"
        "                listener?.(event);\n"
        "    }\n"
        "\n"
        "    /** Returns the number of listeners that are currently registered\n"
        "     *  for the given type of event.\n"
        "     *\n"
        "     *  @param {string} type\n"
        "     */\n"
        "    getNumListenersForType (type)\n"
        "    {\n"
        "        const list = this.listenersPerType[type];\n"
        "        return list ? list.length : 0;\n"
        "    }\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajgenericpatchview_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "import * as Controls from \"./cmaj-parameter-controls.js\"\n"
        "\n"
        "//==============================================================================\n"
        "/** A simple, generic view which can control any type of patch */\n"
        "class GenericPatchView extends HTMLElement\n"
        "{\n"
        "    /** Creates a view for a patch.\n"
        "     *  @param {PatchConnection} patchConnection - the connection to the target patch\n"
        "     */\n"
        "    constructor (patchConnection)\n"
        "    {\n"
        "        super();\n"
        "\n"
        "        this.patchConnection = patchConnection;\n"
        "\n"
        "        this.statusListener = status =>\n"
        "        {\n"
        "            this.status = status;\n"
        "            this.createControlElements();\n"
        "        };\n"
        "\n"
        "        this.attachShadow ({ mode: \"open\" });\n"
        "        this.shadowRoot.innerHTML = this.getHTML();\n"
        "\n"
        "        this.titleElement      = this.shadowRoot.querySelector (\"cmaj-generic-patch-title\");\n"
        "        this.parametersElement = this.shadowRoot.querySelector (\"cmaj-generic-patch-parameters\");\n"
        "    }\n"
        "\n"
        "    /** This is picked up by some of our wrapper code to know whether it makes\n"
        "     *  sense to put a title bar/logo above the GUI.\n"
        "     */\n"
        "    hasOwnTitleBar()\n"
        "    {\n"
        "        return true;\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** @private */\n"
        "    connectedCallback()\n"
        "    {\n"
        "        this.patchConnection.addStatusListener (this.statusListener);\n"
        "        this.patchConnection.requestStatusUpdate();\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    disconnectedCallback()\n"
        "    {\n"
        "        this.patchConnection.removeStatusListener (this.statusListener);\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    createControlElements()\n"
        "    {\n"
        "        this.parametersElement.innerHTML = \"\";\n"
        "        this.titleElement.innerText = this.status?.manifest?.name ?\? \"Cmajor\";\n"
        "\n"
        "        if (this.status?.details?.inputs)\n"
        "        {\n"
        "            for (const endpointInfo of this.status.details.inputs)\n"
        "            {\n"
        "                if (! endpointInfo.annotation?.hidden)\n"
        "                {\n"
        "                    const control = Controls.createLabelledControl (this.patchConnection, endpointInfo);\n"
        "\n"
        "                    if (control)\n"
        "                        this.parametersElement.appendChild (control);\n"
        "                }\n"
        "            }\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    getHTML()\n"
        "    {\n"
        "        const baseUrl = import.meta.url;\n"
        "\n"
        "        return `\n"
        "            <style>\n"
        "            * {\n"
        "                box-sizing: border-box;\n"
        "                user-select: none;\n"
        "                -webkit-user-select: none;\n"
        "                -moz-user-select: none;\n"
        "                -ms-user-select: none;\n"
        "                font-family: Avenir, 'Avenir Next LT Pro', Montserrat, Corbel, 'URW Gothic', source-sans-pro, sans-serif;\n"
        "                font-size: 0.9rem;\n"
        "            }\n"
        "\n"
        "            :host {\n"
        "                --header-height: 2.5rem;\n"
        "                --foreground: #ffffff;\n"
        "                --background: #1a1a1a;\n"
        "\n"
        "                display: block;\n"
        "                height: 100%;\n"
        "                background-color: var(--background);\n"
        "            }\n"
        "\n"
        "            cmaj-generic-patch-main {\n"
        "                background: var(--background);\n"
        "                height: 100%;\n"
        "            }\n"
        "\n"
        "            cmaj-generic-patch-header {\n"
        "                width: 100%;\n"
        "                height: var(--header-height);\n"
        "                border-bottom: 0.1rem solid var(--foreground);\n"
        "                display: flex;\n"
        "                justify-content: space-between;\n"
        "                align-items: center;\n"
        "            }\n"
        "\n"
        "            cmaj-generic-patch-title {\n"
        "                color: var(--foreground);\n"
        "                text-overflow: ellipsis;\n"
        "                white-space: nowrap;\n"
        "                overflow: hidden;\n"
        "                cursor: default;\n"
        "                font-size: 140%;\n"
        "                font-weight: bold;\n"
        "            }\n"
        "\n"
        "            cmaj-generic-patch-logo {\n"
        "                flex: 1;\n"
        "                height: 80%;\n"
        "                margin-left: 0.3rem;\n"
        "                margin-right: 0.3rem;\n"
        "                background-color: var(--foreground);\n"
        "                mask: url(${baseUrl}/../assets/cmajor-logo.svg);\n"
        "                mask-repeat: no-repeat;\n"
        "                -webkit-mask: url(${baseUrl}/../assets/cmajor-logo.svg);\n"
        "                -webkit-mask-repeat: no-repeat;\n"
        "                min-width: 6.25rem;\n"
        "            }\n"
        "\n"
        "            cmaj-generic-patch-padding {\n"
        "                flex: 1;\n"
        "            }\n"
        "\n"
        "            cmaj-generic-patch-parameters {\n"
        "                display: flex;\n"
        "                flex-flow: row wrap;\n"
        "                justify-content: center;\n"
        "                height: calc(100% - var(--header-height));\n"
        "                overflow: auto;\n"
        "                padding: 1rem;\n"
        "                text-align: center;\n"
        "            }\n"
        "\n"
        "            ${Controls.getAllCSS()}\n"
        "\n"
        "            </style>\n"
        "\n"
        "            <cmaj-generic-patch-main>\n"
        "              <cmaj-generic-patch-header>\n"
        "                <cmaj-generic-patch-logo></cmaj-generic-patch-logo>\n"
        "                <cmaj-generic-patch-title></cmaj-generic-patch-title>\n"
        "                <cmaj-generic-patch-padding></cmaj-generic-patch-padding>\n"
        "              </cmaj-generic-patch-header>\n"
        "              <cmaj-generic-patch-parameters></cmaj-generic-patch-parameters>\n"
        "            </cmaj-generic-patch-main>`;\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** Creates a generic view element which can be used to control any patch.\n"
        " *  @param {PatchConnection} patchConnection - the connection to the target patch\n"
        " */\n"
        "export default function createPatchView (patchConnection)\n"
        "{\n"
        "    const genericPatchViewName = \"cmaj-generic-patch-view\";\n"
        "\n"
        "    if (! window.customElements.get (genericPatchViewName))\n"
        "        window.customElements.define (genericPatchViewName, GenericPatchView);\n"
        "\n"
        "    return new (window.customElements.get (genericPatchViewName)) (patchConnection);\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajmidihelpers_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "\n"
        "export function getByte0 (message)     { return (message >> 16) & 0xff; }\n"
        "export function getByte1 (message)     { return (message >> 8) & 0xff; }\n"
        "export function getByte2 (message)     { return message & 0xff; }\n"
        "\n"
        "function isVoiceMessage (message, type)     { return ((message >> 16) & 0xf0) == type; }\n"
        "function get14BitValue (message)            { return getByte1 (message) | (getByte2 (message) << 7); }\n"
        "\n"
        "export function getChannel0to15 (message)   { return getByte0 (message) & 0x0f; }\n"
        "export function getChannel1to16 (message)   { return getChannel0to15 (message) + 1; }\n"
        "\n"
        "export function getMessageSize (message)\n"
        "{\n"
        "    const mainGroupLengths = (3 << 0) | (3 << 2) | (3 << 4) | (3 << 6)\n"
        "                           | (2 << 8) | (2 << 10) | (3 << 12);\n"
        "\n"
        "    const lastGroupLengths = (1 <<  0) | (2 <<  2) | (3 <<  4) | (2 <<  6)\n"
        "                           | (1 <<  8) | (1 << 10) | (1 << 12) | (1 << 14)\n"
        "                           | (1 << 16) | (1 << 18) | (1 << 20) | (1 << 22)\n"
        "                           | (1 << 24) | (1 << 26) | (1 << 28) | (1 << 30);\n"
        "\n"
        "    const firstByte = getByte0 (message);\n"
        "    const group = (firstByte >> 4) & 7;\n"
        "\n"
        "    return (group != 7 ? (mainGroupLengths >> (2 * group))\n"
        "                       : (lastGroupLengths >> (2 * (firstByte & 15)))) & 3;\n"
        "}\n"
        "\n"
        "export function isNoteOn  (message)                         { return isVoiceMessage (message, 0x90) && getVelocity (message) != 0; }\n"
        "export function isNoteOff (message)                         { return isVoiceMessage (message, 0x80) || (isVoiceMessage (message, 0x90) && getVelocity (message) == 0); }\n"
        "\n"
        "export function getNoteNumber (message)                     { return getByte1 (message); }\n"
        "export function getVelocity (message)                       { return getByte2 (message); }\n"
        "\n"
        "export function isProgramChange (message)                   { return isVoiceMessage (message, 0xc0); }\n"
        "export function getProgramChangeNumber (message)            { return getByte1 (message); }\n"
        "export function isPitchWheel (message)                      { return isVoiceMessage (message, 0xe0); }\n"
        "export function getPitchWheelValue (message)                { return get14BitValue (message); }\n"
        "export function isAftertouch (message)                      { return isVoiceMessage (message, 0xa0); }\n"
        "export function getAfterTouchValue (message)                { return getByte2 (message); }\n"
        "export function isChannelPressure (message)                 { return isVoiceMessage (message, 0xd0); }\n"
        "export function getChannelPressureValue (message)           { return getByte1 (message); }\n"
        "export function isController (message)                      { return isVoiceMessage (message, 0xb0); }\n"
        "export function getControllerNumber (message)               { return getByte1 (message); }\n"
        "export function getControllerValue (message)                { return getByte2 (message); }\n"
        "export function isControllerNumber (message, number)        { return getByte1 (message) == number && isController (message); }\n"
        "export function isAllNotesOff (message)                     { return isControllerNumber (message, 123); }\n"
        "export function isAllSoundOff (message)                     { return isControllerNumber (message, 120); }\n"
        "export function isQuarterFrame (message)                    { return getByte0 (message) == 0xf1; }\n"
        "export function isClock (message)                           { return getByte0 (message) == 0xf8; }\n"
        "export function isStart (message)                           { return getByte0 (message) == 0xfa; }\n"
        "export function isContinue (message)                        { return getByte0 (message) == 0xfb; }\n"
        "export function isStop (message)                            { return getByte0 (message) == 0xfc; }\n"
        "export function isActiveSense (message)                     { return getByte0 (message) == 0xfe; }\n"
        "export function isMetaEvent (message)                       { return getByte0 (message) == 0xff; }\n"
        "export function isSongPositionPointer (message)             { return getByte0 (message) == 0xf2; }\n"
        "export function getSongPositionPointerValue (message)       { return get14BitValue (message); }\n"
        "\n"
        "export function getChromaticScaleIndex (note)               { return (note % 12) & 0xf; }\n"
        "export function getOctaveNumber (note, octaveForMiddleC)    { return ((Math.floor (note / 12) + (octaveForMiddleC ? octaveForMiddleC : 3)) & 0xff) - 5; }\n"
        "export function getNoteName (note)                          { const names = [\"C\", \"C#\", \"D\", \"Eb\", \"E\", \"F\", \"F#\", \"G\", \"G#\", \"A\", \"Bb\", \"B\"]; return names[getChromaticScaleIndex (note)]; }\n"
        "export function getNoteNameWithSharps (note)                { const names = [\"C\", \"C#\", \"D\", \"Eb\", \"E\", \"F\", \"F#\", \"G\", \"G#\", \"A\", \"Bb\", \"B\"]; return names[getChromaticScaleIndex (note)]; }\n"
        "export function getNoteNameWithFlats (note)                 { const names = [\"C\", \"Db\", \"D\", \"Eb\", \"E\", \"F\", \"Gb\", \"G\", \"Ab\", \"A\", \"Bb\", \"B\"]; return names[getChromaticScaleIndex (note)]; }\n"
        "export function getNoteNameWithOctaveNumber (note)          { return getNoteName (note) + getOctaveNumber (note); }\n"
        "export function isNatural (note)                            { const nats = [true, false, true, false, true, true, false, true, false, true, false, true]; return nats[getChromaticScaleIndex (note)]; }\n"
        "export function isAccidental (note)                         { return ! isNatural (note); }\n"
        "\n"
        "export function printHexMIDIData (message)\n"
        "{\n"
        "    const numBytes = getMessageSize (message);\n"
        "\n"
        "    if (numBytes == 0)\n"
        "        return \"[empty]\";\n"
        "\n"
        "    let s = \"\";\n"
        "\n"
        "    for (let i = 0; i < numBytes; ++i)\n"
        "    {\n"
        "        if (i != 0)  s += ' ';\n"
        "\n"
        "        const byte = message >> (16 - 8 * i) & 0xff;\n"
        "        s += \"0123456789abcdef\"[byte >> 4];\n"
        "        s += \"0123456789abcdef\"[byte & 15];\n"
        "    }\n"
        "\n"
        "    return s;\n"
        "}\n"
        "\n"
        "export function getMIDIDescription (message)\n"
        "{\n"
        "    const channelText = \" Channel \" + getChannel1to16 (message);\n"
        "    function getNote (m)   { const s = getNoteNameWithOctaveNumber (getNoteNumber (message)); return s.length < 4 ? s + \" \" : s; };\n"
        "\n"
        "    if (isNoteOn (message))                return \"Note-On:  \"   + getNote (message) + channelText + \"  Velocity \" + getVelocity (message);\n"
        "    if (isNoteOff (message))               return \"Note-Off: \"   + getNote (message) + channelText + \"  Velocity \" + getVelocity (message);\n"
        "    if (isAftertouch (message))            return \"Aftertouch: \" + getNote (message) + channelText +  \": \" + getAfterTouchValue (message);\n"
        "    if (isPitchWheel (message))            return \"Pitch wheel: \" + getPitchWheelValue (message) + ' ' + channelText;\n"
        "    if (isChannelPressure (message))       return \"Channel pressure: \" + getChannelPressureValue (message) + ' ' + channelText;\n"
        "    if (isController (message))            return \"Controller:\" + channelText + \": \" + getControllerName (getControllerNumber (message)) + \" = \" + getControllerValue (message);\n"
        "    if (isProgramChange (message))         return \"Program change: \" + getProgramChangeNumber (message) + ' ' + channelText;\n"
        "    if (isAllNotesOff (message))           return \"All notes off:\" + channelText;\n"
        "    if (isAllSoundOff (message))           return \"All sound off:\" + channelText;\n"
        "    if (isQuarterFrame (message))          return \"Quarter-frame\";\n"
        "    if (isClock (message))                 return \"Clock\";\n"
        "    if (isStart (message))                 return \"Start\";\n"
        "    if (isContinue (message))              return \"Continue\";\n"
        "    if (isStop (message))                  return \"Stop\";\n"
        "    if (isMetaEvent (message))             return \"Meta-event: type \" + getByte1 (message);\n"
        "    if (isSongPositionPointer (message))   return \"Song Position: \" + getSongPositionPointerValue (message);\n"
        "\n"
        "    return printHexMIDIData (message);\n"
        "}\n"
        "\n"
        "export function getControllerName (controllerNumber)\n"
        "{\n"
        "    if (controllerNumber < 128)\n"
        "    {\n"
        "        const controllerNames = [\n"
        "            \"Bank Select\",                  \"Modulation Wheel (coarse)\",      \"Breath controller (coarse)\",       undefined,\n"
        "            \"Foot Pedal (coarse)\",          \"Portamento Time (coarse)\",       \"Data Entry (coarse)\",              \"Volume (coarse)\",\n"
        "            \"Balance (coarse)\",             undefined,                        \"Pan position (coarse)\",            \"Expression (coarse)\",\n"
        "            \"Effect Control 1 (coarse)\",    \"Effect Control 2 (coarse)\",      undefined,                          undefined,\n"
        "            \"General Purpose Slider 1\",     \"General Purpose Slider 2\",       \"General Purpose Slider 3\",         \"General Purpose Slider 4\",\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            \"Bank Select (fine)\",           \"Modulation Wheel (fine)\",        \"Breath controller (fine)\",         undefined,\n"
        "            \"Foot Pedal (fine)\",            \"Portamento Time (fine)\",         \"Data Entry (fine)\",                \"Volume (fine)\",\n"
        "            \"Balance (fine)\",               undefined,                        \"Pan position (fine)\",              \"Expression (fine)\",\n"
        "            \"Effect Control 1 (fine)\",      \"Effect Control 2 (fine)\",        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            \"Hold Pedal\",                   \"Portamento\",                     \"Sustenuto Pedal\",                  \"Soft Pedal\",\n"
        "            \"Legato Pedal\",                 \"Hold 2 Pedal\",                   \"Sound Variation\",                  \"Sound Timbre\",\n"
        "            \"Sound Release Time\",           \"Sound Attack Time\",              \"Sound Brightness\",                 \"Sound Control 6\",\n"
        "            \"Sound Control 7\",              \"Sound Control 8\",                \"Sound Control 9\",                  \"Sound Control 10\",\n"
        "            \"General Purpose Button 1\",     \"General Purpose Button 2\",       \"General Purpose Button 3\",         \"General Purpose Button 4\",\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          \"Reverb Level\",\n"
        "            \"Tremolo Level\",                \"Chorus Level\",                   \"Celeste Level\",                    \"Phaser Level\",\n"
        "            \"Data Button increment\",        \"Data Button decrement\",          \"Non-registered Parameter (fine)\",  \"Non-registered Parameter (coarse)\",\n"
        "            \"Registered Parameter (fine)\",  \"Registered Parameter (coarse)\",  undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            undefined,                      undefined,                        undefined,                          undefined,\n"
        "            \"All Sound Off\",                \"All Controllers Off\",            \"Local Keyboard\",                   \"All Notes Off\",\n"
        "            \"Omni Mode Off\",                \"Omni Mode On\",                   \"Mono Operation\",                   \"Poly Operation\"\n"
        "        ];\n"
        "\n"
        "        const name = controllerNames[controllerNumber];\n"
        "\n"
        "        if (name)\n"
        "            return name;\n"
        "    }\n"
        "\n"
        "    return controllerNumber.toString();\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajparametercontrols_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "import { PatchConnection } from \"./cmaj-patch-connection.js\";\n"
        "\n"
        "\n"
        "//==============================================================================\n"
        "/** A base class for parameter controls, which automatically connects to a\n"
        " *  PatchConnection to monitor a parameter and provides methods to modify it.\n"
        " */\n"
        "export class ParameterControlBase  extends HTMLElement\n"
        "{\n"
        "    constructor()\n"
        "    {\n"
        "        super();\n"
        "\n"
        "        // prevent any clicks from focusing on this element\n"
        "        this.onmousedown = e => e.stopPropagation();\n"
        "    }\n"
        "\n"
        "    /** Attaches the control to a given PatchConnection and endpoint.\n"
        "     *\n"
        "     * @param {PatchConnection} patchConnection - the connection to connect to, or pass\n"
        "     *                                            undefined to disconnect the control.\n"
        "     * @param {Object} endpointInfo - the endpoint details, as provided by a PatchConnection\n"
        "     *                                in its status callback.\n"
        "     */\n"
        "    setEndpoint (patchConnection, endpointInfo)\n"
        "    {\n"
        "        this.detachListener();\n"
        "\n"
        "        this.patchConnection = patchConnection;\n"
        "        this.endpointInfo = endpointInfo;\n"
        "        this.defaultValue = endpointInfo.annotation?.init || endpointInfo.defaultValue || 0;\n"
        "\n"
        "        if (this.isConnected)\n"
        "            this.attachListener();\n"
        "    }\n"
        "\n"
        "    /** Override this method in a child class, and it will be called when the parameter value changes,\n"
        "     *  so you can update the GUI appropriately.\n"
        "     */\n"
        "    valueChanged (newValue) {}\n"
        "\n"
        "    /** Your GUI can call this when it wants to change the parameter value. */\n"
        "    setValue (value)     { this.patchConnection?.sendEventOrValue (this.endpointInfo.endpointID, value); }\n"
        "\n"
        "    /** Call this before your GUI begins a modification gesture.\n"
        "     *  You might for example call this if the user begins a mouse-drag operation.\n"
        "     */\n"
        "    beginGesture()       { this.patchConnection?.sendParameterGestureStart (this.endpointInfo.endpointID); }\n"
        "\n"
        "    /** Call this after your GUI finishes a modification gesture */\n"
        "    endGesture()         { this.patchConnection?.sendParameterGestureEnd (this.endpointInfo.endpointID); }\n"
        "\n"
        "    /** This calls setValue(), but sandwiches it between some start/end gesture calls.\n"
        "     *  You should use this to make sure a DAW correctly records automatiion for individual value changes\n"
        "     *  that are not part of a gesture.\n"
        "     */\n"
        "    setValueAsGesture (value)\n"
        "    {\n"
        "        this.beginGesture();\n"
        "        this.setValue (value);\n"
        "        this.endGesture();\n"
        "    }\n"
        "\n"
        "    /** Resets the parameter to its default value */\n"
        "    resetToDefault()\n"
        "    {\n"
        "        if (this.defaultValue !== null)\n"
        "            this.setValueAsGesture (this.defaultValue);\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** @private */\n"
        "    connectedCallback()\n"
        "    {\n"
        "        this.attachListener();\n"
        "    }\n"
        "\n"
        "    /** @protected */\n"
        "    disconnectedCallback()\n"
        "    {\n"
        "        this.detachListener();\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    detachListener()\n"
        "    {\n"
        "        if (this.listener)\n"
        "        {\n"
        "            this.patchConnection?.removeParameterListener?.(this.listener.endpointID, this.listener);\n"
        "            this.listener = undefined;\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    attachListener()\n"
        "    {\n"
        "        if (this.patchConnection && this.endpointInfo)\n"
        "        {\n"
        "            this.detachListener();\n"
        "\n"
        "            this.listener = newValue => this.valueChanged (newValue);\n"
        "            this.listener.endpointID = this.endpointInfo.endpointID;\n"
        "\n"
        "            this.patchConnection.addParameterListener (this.endpointInfo.endpointID, this.listener);\n"
        "            this.patchConnection.requestParameterValue (this.endpointInfo.endpointID);\n"
        "        }\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** A simple rotary parameter knob control. */\n"
        "export class Knob  extends ParameterControlBase\n"
        "{\n"
        "    constructor (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super();\n"
        "        this.setEndpoint (patchConnection, endpointInfo);\n"
        "    }\n"
        "\n"
        "    setEndpoint (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super.setEndpoint (patchConnection, endpointInfo);\n"
        "\n"
        "        this.innerHTML = \"\";\n"
        "        this.className = \"knob-container\";\n"
        "        const min = endpointInfo?.annotation?.min || 0;\n"
        "        const max = endpointInfo?.annotation?.max || 1;\n"
        "        const mid = endpointInfo?.annotation?.mid || undefined;\n"
        "\n"
        "        const createSvgElement = tag => window.document.createElementNS (\"http://www.w3.org/2000/svg\", tag);\n"
        "\n"
        "        const svg = createSvgElement (\"svg\");\n"
        "        svg.setAttribute (\"viewBox\", \"0 0 100 100\");\n"
        "\n"
        "        const trackBackground = createSvgElement (\"path\");\n"
        "        trackBackground.setAttribute (\"d\", \"M20,76 A 40 40 0 1 1 80 76\");\n"
        "        trackBackground.classList.add (\"knob-path\");\n"
        "        trackBackground.classList.add (\"knob-track-background\");\n"
        "\n"
        "        const maxKnobRotation = 132;\n"
        "        const isBipolar = min + max === 0;\n"
        "        const dashLength = isBipolar ? 251.5 : 184;\n"
        "        const valueOffset = isBipolar ? 0 : 132;\n"
        "        this.getDashOffset = val => dashLength - 184 / (maxKnobRotation * 2) * (val + valueOffset);\n"
        "\n"
        "        this.trackValue = createSvgElement (\"path\");\n"
        "\n"
        "        this.trackValue.setAttribute (\"d\", isBipolar ? \"M50.01,10 A 40 40 0 1 1 50 10\"\n"
        "                                                     : \"M20,76 A 40 40 0 1 1 80 76\");\n"
        "        this.trackValue.setAttribute (\"stroke-dasharray\", dashLength);\n"
        "        this.trackValue.classList.add (\"knob-path\");\n"
        "        this.trackValue.classList.add (\"knob-track-value\");\n"
        "\n"
        "        this.dial = document.createElement (\"div\");\n"
        "        this.dial.className = \"knob-dial\";\n"
        "\n"
        "        const dialTick = document.createElement (\"div\");\n"
        "        dialTick.className = \"knob-dial-tick\";\n"
        "        this.dial.appendChild (dialTick);\n"
        "\n"
        "        svg.appendChild (trackBackground);\n"
        "        svg.appendChild (this.trackValue);\n"
        "\n"
        "        this.appendChild (svg);\n"
        "        this.appendChild (this.dial);\n"
        "\n"
        "        const remap = (source, sourceFrom, sourceTo, targetFrom, targetTo) =>\n"
        "                        (targetFrom + (source - sourceFrom) * (targetTo - targetFrom) / (sourceTo - sourceFrom));\n"
        "\n"
        "        const toValue = (knobRotation) =>\n"
        "        {\n"
        "            if (mid > min && mid < max)\n"
        "            {\n"
        "                const normalisedKnob = remap (knobRotation, -maxKnobRotation, maxKnobRotation, 0, 1);\n"
        "                const range = max - min;\n"
        "                const power = Math.log ((mid - min) / (range)) / Math.log (0.5);\n"
        "\n"
        "                return min + range * Math.pow (normalisedKnob, power);\n"
        "            }\n"
        "            else\n"
        "            {\n"
        "                return remap (knobRotation, -maxKnobRotation, maxKnobRotation, min, max);\n"
        "            }\n"
        "        };\n"
        "\n"
        "        this.toRotation = (value) =>\n"
        "        {\n"
        "            if (mid > min && mid < max)\n"
        "            {\n"
        "                const range = max - min;\n"
        "                const power = Math.log ((mid - min) / (range)) / Math.log (0.5);\n"
        "\n"
        "                const normalisedKnob = Math.pow ((value - min) / range, 1 / power);\n"
        "\n"
        "                return remap (normalisedKnob, 0, 1, -maxKnobRotation, maxKnobRotation);\n"
        "            }\n"
        "            else\n"
        "            {\n"
        "                return remap (value, min, max, -maxKnobRotation, maxKnobRotation);\n"
        "            }\n"
        "        };\n"
        "\n"
        "        this.rotation = this.toRotation (this.defaultValue);\n"
        "        this.setRotation (this.rotation, true);\n"
        "\n"
        "        const onMouseMove = (event) =>\n"
        "        {\n"
        "            event.preventDefault(); // avoid scrolling whilst dragging\n"
        "\n"
        "            const nextRotation = (rotation, delta) =>\n"
        "            {\n"
        "                const clamp = (v, min, max) => Math.min (Math.max (v, min), max);\n"
        "                return clamp (rotation - delta, -maxKnobRotation, maxKnobRotation);\n"
        "            };\n"
        "\n"
        "            const workaroundBrowserIncorrectlyCalculatingMovementY = event.movementY === event.screenY;\n"
        "            const movementY = workaroundBrowserIncorrectlyCalculatingMovementY ? event.screenY - this.previousScreenY\n"
        "                                                                               : event.movementY;\n"
        "            this.previousScreenY = event.screenY;\n"
        "\n"
        "            const speedMultiplier = event.shiftKey ? 0.25 : 1.5;\n"
        "            this.accumulatedRotation = nextRotation (this.accumulatedRotation, movementY * speedMultiplier);\n"
        "            this.setValue (toValue (this.accumulatedRotation));\n"
        "        };\n"
        "\n"
        "        const onMouseUp = (event) =>\n"
        "        {\n"
        "            this.previousScreenY = undefined;\n"
        "            this.accumulatedRotation = undefined;\n"
        "            window.removeEventListener (\"mousemove\", onMouseMove);\n"
        "            window.removeEventListener (\"mouseup\", onMouseUp);\n"
        "            this.endGesture();\n"
        "        };\n"
        "\n"
        "        const onMouseDown = (event) =>\n"
        "        {\n"
        "            this.previousScreenY = event.screenY;\n"
        "            this.accumulatedRotation = this.rotation;\n"
        "            this.beginGesture();\n"
        "            window.addEventListener (\"mousemove\", onMouseMove);\n"
        "            window.addEventListener (\"mouseup\", onMouseUp);\n"
        "            event.preventDefault();\n"
        "        };\n"
        "\n"
        "        const onTouchStart = (event) =>\n"
        "        {\n"
        "            this.previousClientY = event.changedTouches[0].clientY;\n"
        "            this.accumulatedRotation = this.rotation;\n"
        "            this.touchIdentifier = event.changedTouches[0].identifier;\n"
        "            this.beginGesture();\n"
        "            window.addEventListener (\"touchmove\", onTouchMove);\n"
        "            window.addEventListener (\"touchend\", onTouchEnd);\n"
        "            event.preventDefault();\n"
        "        };\n"
        "\n"
        "        const onTouchMove = (event) =>\n"
        "        {\n"
        "            for (const touch of event.changedTouches)\n"
        "            {\n"
        "                if (touch.identifier == this.touchIdentifier)\n"
        "                {\n"
        "                    const nextRotation = (rotation, delta) =>\n"
        "                    {\n"
        "                        const clamp = (v, min, max) => Math.min (Math.max (v, min), max);\n"
        "                        return clamp (rotation - delta, -maxKnobRotation, maxKnobRotation);\n"
        "                    };\n"
        "\n"
        "                    const movementY = touch.clientY - this.previousClientY;\n"
        "                    this.previousClientY = touch.clientY;\n"
        "\n"
        "                    const speedMultiplier = event.shiftKey ? 0.25 : 1.5;\n"
        "                    this.accumulatedRotation = nextRotation (this.accumulatedRotation, movementY * speedMultiplier);\n"
        "                    this.setValue (toValue (this.accumulatedRotation));\n"
        "                }\n"
        "            }\n"
        "        };\n"
        "\n"
        "        const onTouchEnd = (event) =>\n"
        "        {\n"
        "            this.previousClientY = undefined;\n"
        "            this.accumulatedRotation = undefined;\n"
        "            window.removeEventListener (\"touchmove\", onTouchMove);\n"
        "            window.removeEventListener (\"touchend\", onTouchEnd);\n"
        "            this.endGesture();\n"
        "        };\n"
        "\n"
        "        this.addEventListener (\"mousedown\", onMouseDown);\n"
        "        this.addEventListener (\"dblclick\", () => this.resetToDefault());\n"
        "        this.addEventListener ('touchstart', onTouchStart);\n"
        "    }\n"
        "\n"
        "    /** Returns true if this type of control is suitable for the given endpoint info */\n"
        "    static canBeUsedFor (endpointInfo)\n"
        "    {\n"
        "        return endpointInfo.purpose === \"parameter\";\n"
        "    }\n"
        "\n"
        "    /** @override */\n"
        "    valueChanged (newValue)       { this.setRotation (this.toRotation (newValue), false); }\n"
        "\n"
        "    /** Returns a string version of the given value */\n"
        "    getDisplayValue (v)           { return toFloatDisplayValueWithUnit (v, this.endpointInfo); }\n"
        "\n"
        "    /** @private */\n"
        "    setRotation (degrees, force)\n"
        "    {\n"
        "        if (force || this.rotation !== degrees)\n"
        "        {\n"
        "            this.rotation = degrees;\n"
        "            this.trackValue.setAttribute (\"stroke-dashoffset\", this.getDashOffset (this.rotation));\n"
        "            this.dial.style.transform = `translate(-50%,-50%) rotate(${degrees}deg)`;\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    static getCSS()\n"
        "    {\n"
        "        return `\n"
        "        .knob-container {\n"
        "            --knob-track-background-color: var(--background);\n"
        "            --knob-track-value-color: var(--foreground);\n"
        "\n"
        "            --knob-dial-border-color: var(--foreground);\n"
        "            --knob-dial-background-color: var(--background);\n"
        "            --knob-dial-tick-color: var(--foreground);\n"
        "\n"
        "            position: relative;\n"
        "            display: inline-block;\n"
        "            height: 5rem;\n"
        "            width: 5rem;\n"
        "            margin: 0;\n"
        "            padding: 0;\n"
        "        }\n"
        "\n"
        "        .knob-path {\n"
        "            fill: none;\n"
        "            stroke-linecap: round;\n"
        "            stroke-width: 0.15rem;\n"
        "        }\n"
        "\n"
        "        .knob-track-background {\n"
        "            stroke: var(--knob-track-background-color);\n"
        "        }\n"
        "\n"
        "        .knob-track-value {\n"
        "            stroke: var(--knob-track-value-color);\n"
        "        }\n"
        "\n"
        "        .knob-dial {\n"
        "            position: absolute;\n"
        "            text-align: center;\n"
        "            height: 60%;\n"
        "            width: 60%;\n"
        "            top: 50%;\n"
        "            left: 50%;\n"
        "            border: 0.15rem solid var(--knob-dial-border-color);\n"
        "            border-radius: 100%;\n"
        "            box-sizing: border-box;\n"
        "            transform: translate(-50%,-50%);\n"
        "            background-color: var(--knob-dial-background-color);\n"
        "        }\n"
        "\n"
        "        .knob-dial-tick {\n"
        "            position: absolute;\n"
        "            display: inline-block;\n"
        "\n"
        "            height: 1rem;\n"
        "            width: 0.15rem;\n"
        "            background-color: var(--knob-dial-tick-color);\n"
        "        }`;\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** A boolean switch control */\n"
        "export class Switch  extends ParameterControlBase\n"
        "{\n"
        "    constructor (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super();\n"
        "        this.setEndpoint (patchConnection, endpointInfo);\n"
        "    }\n"
        "\n"
        "    setEndpoint (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super.setEndpoint (patchConnection, endpointInfo);\n"
        "\n"
        "        const outer = document.createElement (\"div\");\n"
        "        outer.classList = \"switch-outline\";\n"
        "\n"
        "        const inner = document.createElement (\"div\");\n"
        "        inner.classList = \"switch-thumb\";\n"
        "\n"
        "        this.innerHTML = \"\";\n"
        "        this.currentValue = this.defaultValue > 0.5;\n"
        "        this.valueChanged (this.currentValue);\n"
        "        this.classList.add (\"switch-container\");\n"
        "\n"
        "        outer.appendChild (inner);\n"
        "        this.appendChild (outer);\n"
        "        this.addEventListener (\"click\", () => this.setValueAsGesture (this.currentValue ? 0 : 1.0));\n"
        "    }\n"
        "\n"
        "    /** Returns true if this type of control is suitable for the given endpoint info */\n"
        "    static canBeUsedFor (endpointInfo)\n"
        "    {\n"
        "        return endpointInfo.purpose === \"parameter\"\n"
        "                && endpointInfo.annotation?.boolean;\n"
        "    }\n"
        "\n"
        "    /** @override */\n"
        "    valueChanged (newValue)\n"
        "    {\n"
        "        const b = newValue > 0.5;\n"
        "        this.currentValue = b;\n"
        "        this.classList.remove (! b ? \"switch-on\" : \"switch-off\");\n"
        "        this.classList.add (b ? \"switch-on\" : \"switch-off\");\n"
        "    }\n"
        "\n"
        "    /** Returns a string version of the given value */\n"
        "    getDisplayValue (v)   { return `${v > 0.5 ? \"On\" : \"Off\"}`; }\n"
        "\n"
        "    /** @private */\n"
        "    static getCSS()\n"
        "    {\n"
        "        return `\n"
        "        .switch-container {\n"
        "            --switch-outline-color: var(--foreground);\n"
        "            --switch-thumb-color: var(--foreground);\n"
        "            --switch-on-background-color: var(--background);\n"
        "            --switch-off-background-color: var(--background);\n"
        "\n"
        "            position: relative;\n"
        "            display: flex;\n"
        "            align-items: center;\n"
        "            justify-content: center;\n"
        "            height: 100%;\n"
        "            width: 100%;\n"
        "            margin: 0;\n"
        "            padding: 0;\n"
        "        }\n"
        "\n"
        "        .switch-outline {\n"
        "            position: relative;\n"
        "            display: inline-block;\n"
        "            height: 1.5rem;\n"
        "            width: 2.5rem;\n"
        "            border-radius: 1rem;\n"
        "            border: var(--switch-outline-color) solid 0.15rem;\n"
        "            transition: background-color 0.1s cubic-bezier(0.5, 0, 0.2, 1);\n"
        "        }\n"
        "\n"
        "        .switch-thumb {\n"
        "            position: absolute;\n"
        "            top: 50%;\n"
        "            left: 50%;\n"
        "            transform: translate(-50%,-50%);\n"
        "            height: 0.9rem;\n"
        "            width:  0.9rem;\n"
        "            background-color: var(--switch-thumb-color);\n"
        "            border-radius: 100%;\n"
        "            transition: left 0.1s cubic-bezier(0.5, 0, 0.2, 1);\n"
        "        }\n"
        "\n"
        "        .switch-off .switch-thumb {\n"
        "            left: 25%;\n"
        "            background: none;\n"
        "            border: var(--switch-thumb-color) solid 0.1rem;\n"
        "            height: 0.8rem;\n"
        "            width: 0.8rem;\n"
        "        }\n"
        "        .switch-on .switch-thumb {\n"
        "            left: 75%;\n"
        "        }\n"
        "\n"
        "        .switch-off .switch-outline {\n"
        "            background-color: var(--switch-on-background-color);\n"
        "        }\n"
        "        .switch-on .switch-outline {\n"
        "            background-color: var(--switch-off-background-color);\n"
        "        }`;\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "function toFloatDisplayValueWithUnit (v, endpointInfo)\n"
        "{\n"
        "    return `${v.toFixed (2)} ${endpointInfo.annotation?.unit ?\? \"\"}`;\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** A control that allows an item to be selected from a drop-down list of options */\n"
        "export class Options  extends ParameterControlBase\n"
        "{\n"
        "    constructor (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super();\n"
        "        this.setEndpoint (patchConnection, endpointInfo);\n"
        "    }\n"
        "\n"
        "    setEndpoint (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super.setEndpoint (patchConnection, endpointInfo);\n"
        "\n"
        "        const toValue = (min, step, index) => min + (step * index);\n"
        "        const toStepCount = count => count > 0 ? count - 1 : 1;\n"
        "\n"
        "        const { min, max, options } = (() =>\n"
        "        {\n"
        "            if (Options.hasTextOptions (endpointInfo))\n"
        "            {\n"
        "                const optionList = endpointInfo.annotation.text.split (\"|\");\n"
        "                const stepCount = toStepCount (optionList.length);\n"
        "                let min = 0, max = stepCount, step = 1;\n"
        "\n"
        "                if (endpointInfo.annotation.min != null && endpointInfo.annotation.max != null)\n"
        "                {\n"
        "                    min = endpointInfo.annotation.min;\n"
        "                    max = endpointInfo.annotation.max;\n"
        "                    step = (max - min) / stepCount;\n"
        "                }\n"
        "\n"
        "                const options = optionList.map ((text, index) => ({ value: toValue (min, step, index), text }));\n"
        "\n"
        "                return { min, max, options };\n"
        "            }\n"
        "\n"
        "            if (Options.isExplicitlyDiscrete (endpointInfo))\n"
        "            {\n"
        "                const step = endpointInfo.annotation.step;\n"
        "\n"
        "                const min = endpointInfo.annotation?.min || 0;\n"
        "                const max = endpointInfo.annotation?.max || 1;\n"
        "\n"
        "                const numDiscreteOptions = (((max - min) / step) | 0) + 1;\n"
        "\n"
        "                const options = new Array (numDiscreteOptions);\n"
        "                for (let i = 0; i < numDiscreteOptions; ++i)\n"
        "                {\n"
        "                    const value = toValue (min, step, i);\n"
        "                    options[i] = { value, text: toFloatDisplayValueWithUnit (value, endpointInfo) };\n"
        "                }\n"
        "\n"
        "                return { min, max, options };\n"
        "            }\n"
        "        })();\n"
        "\n"
        "        this.options = options;\n"
        "\n"
        "        const stepCount = toStepCount (this.options.length);\n"
        "        const normalise = value => (value - min) / (max - min);\n"
        "        this.toIndex = value => Math.min (stepCount, normalise (value) * this.options.length) | 0;\n"
        "\n"
        "        this.innerHTML = \"\";\n"
        "\n"
        "        this.select = document.createElement (\"select\");\n"
        "\n"
        "        for (const option of this.options)\n"
        "        {\n"
        "            const optionElement = document.createElement (\"option\");\n"
        "            optionElement.innerText = option.text;\n"
        "            this.select.appendChild (optionElement);\n"
        "        }\n"
        "\n"
        "        this.selectedIndex = this.toIndex (this.defaultValue);\n"
        "\n"
        "        this.select.addEventListener (\"change\", (e) =>\n"
        "        {\n"
        "            const newIndex = e.target.selectedIndex;\n"
        "\n"
        "            // prevent local state change. the caller will update us when the backend actually applies the update\n"
        "            e.target.selectedIndex = this.selectedIndex;\n"
        "\n"
        "            this.setValueAsGesture (this.options[newIndex].value)\n"
        "        });\n"
        "\n"
        "        this.valueChanged (this.selectedIndex);\n"
        "\n"
        "        this.className = \"select-container\";\n"
        "        this.appendChild (this.select);\n"
        "\n"
        "        const icon = document.createElement (\"span\");\n"
        "        icon.className = \"select-icon\";\n"
        "        this.appendChild (icon);\n"
        "    }\n"
        "\n"
        "    /** Returns true if this type of control is suitable for the given endpoint info */\n"
        "    static canBeUsedFor (endpointInfo)\n"
        "    {\n"
        "        return endpointInfo.purpose === \"parameter\"\n"
        "                && (this.hasTextOptions (endpointInfo) || this.isExplicitlyDiscrete (endpointInfo));\n"
        "    }\n"
        "\n"
        "    /** @override */\n"
        "    valueChanged (newValue)\n"
        "    {\n"
        "        const index = this.toIndex (newValue);\n"
        "        this.selectedIndex = index;\n"
        "        this.select.selectedIndex = index;\n"
        "    }\n"
        "\n"
        "    /** Returns a string version of the given value */\n"
        "    getDisplayValue (v)    { return this.options[this.toIndex(v)].text; }\n"
        "\n"
        "    /** @private */\n"
        "    static hasTextOptions (endpointInfo)\n"
        "    {\n"
        "        return endpointInfo.annotation?.text?.split?.(\"|\").length > 1\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    static isExplicitlyDiscrete (endpointInfo)\n"
        "    {\n"
        "        return endpointInfo.annotation?.discrete && endpointInfo.annotation?.step > 0;\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    static getCSS()\n"
        "    {\n"
        "        return `\n"
        "        .select-container {\n"
        "            position: relative;\n"
        "            display: block;\n"
        "            font-size: 0.8rem;\n"
        "            width: 100%;\n"
        "            color: var(--foreground);\n"
        "            border: 0.15rem solid var(--foreground);\n"
        "            border-radius: 0.6rem;\n"
        "            margin: 0;\n"
        "            padding: 0;\n"
        "        }\n"
        "\n"
        "        select {\n"
        "            background: none;\n"
        "            appearance: none;\n"
        "            -webkit-appearance: none;\n"
        "            font-family: inherit;\n"
        "            font-size: 0.8rem;\n"
        "\n"
        "            overflow: hidden;\n"
        "            text-overflow: ellipsis;\n"
        "\n"
        "            padding: 0 1.5rem 0 0.6rem;\n"
        "\n"
        "            outline: none;\n"
        "            color: var(--foreground);\n"
        "            height: 2rem;\n"
        "            box-sizing: border-box;\n"
        "            margin: 0;\n"
        "            border: none;\n"
        "\n"
        "            width: 100%;\n"
        "        }\n"
        "\n"
        "        select option {\n"
        "            background: var(--background);\n"
        "            color: var(--foreground);\n"
        "        }\n"
        "\n"
        "        .select-icon {\n"
        "            position: absolute;\n"
        "            right: 0.3rem;\n"
        "            top: 0.5rem;\n"
        "            pointer-events: none;\n"
        "            background-color: var(--foreground);\n"
        "            width: 1.4em;\n"
        "            height: 1.4em;\n"
        "            mask: url(\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24'%3E%3Cpath d='M17,9.17a1,1,0,0,0-1.41,0L12,12.71,8.46,9.17a1,1,0,0,0-1.41,0,1,1,0,0,0,0,1.42l4.24,4.24a1,1,0,0,0,1.42,0L17,10.59A1,1,0,0,0,17,9.17Z'/%3E%3C/svg%3E\");\n"
        "            mask-repeat: no-repeat;\n"
        "            -webkit-mask: url(\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 24'%3E%3Cpath d='M17,9.17a1,1,0,0,0-1.41,0L12,12.71,8.46,9.17a1,1,0,0,0-1.41,0,1,1,0,0,0,0,1.42l4.24,4.24a1,1,0,0,0,1.42,0L17,10.59A1,1,0,0,0,17,9.17Z'/%3E%3C/svg%3E\");\n"
        "            -webkit-mask-repeat: no-repeat;\n"
        "        }`;\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** A control which wraps a child control, adding a label and value display box below it */\n"
        "export class LabelledControlHolder  extends ParameterControlBase\n"
        "{\n"
        "    constructor (patchConnection, endpointInfo, childControl)\n"
        "    {\n"
        "        super();\n"
        "        this.childControl = childControl;\n"
        "        this.setEndpoint (patchConnection, endpointInfo);\n"
        "    }\n"
        "\n"
        "    setEndpoint (patchConnection, endpointInfo)\n"
        "    {\n"
        "        super.setEndpoint (patchConnection, endpointInfo);\n"
        "\n"
        "        this.innerHTML = \"\";\n"
        "        this.className = \"labelled-control\";\n"
        "\n"
        "        const centeredControl = document.createElement (\"div\");\n"
        "        centeredControl.className = \"labelled-control-centered-control\";\n"
        "\n"
        "        centeredControl.appendChild (this.childControl);\n"
        "\n"
        "        const titleValueHoverContainer = document.createElement (\"div\");\n"
        "        titleValueHoverContainer.className = \"labelled-control-label-container\";\n"
        "\n"
        "        const nameText = document.createElement (\"div\");\n"
        "        nameText.classList.add (\"labelled-control-name\");\n"
        "        nameText.innerText = endpointInfo.annotation?.name || endpointInfo.name || endpointInfo.endpointID || \"\";\n"
        "\n"
        "        this.valueText = document.createElement (\"div\");\n"
        "        this.valueText.classList.add (\"labelled-control-value\");\n"
        "\n"
        "        titleValueHoverContainer.appendChild (nameText);\n"
        "        titleValueHoverContainer.appendChild (this.valueText);\n"
        "\n"
        "        this.appendChild (centeredControl);\n"
        "        this.appendChild (titleValueHoverContainer);\n"
        "    }\n"
        "\n"
        "    /** @override */\n"
        "    valueChanged (newValue)\n"
        "    {\n"
        "        this.valueText.innerText = this.childControl?.getDisplayValue (newValue);\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    static getCSS()\n"
        "    {\n"
        "        return `\n"
        "        .labelled-control {\n"
        "            --labelled-control-font-color: var(--foreground);\n"
        "            --labelled-control-font-size: 0.8rem;\n"
        "\n"
        "            position: relative;\n"
        "            display: inline-block;\n"
        "            margin: 0 0.4rem 0.4rem;\n"
        "            vertical-align: top;\n"
        "            text-align: left;\n"
        "            padding: 0;\n"
        "        }\n"
        "\n"
        "        .labelled-control-centered-control {\n"
        "            position: relative;\n"
        "            display: flex;\n"
        "            align-items: center;\n"
        "            justify-content: center;\n"
        "\n"
        "            width: 5.5rem;\n"
        "            height: 5rem;\n"
        "        }\n"
        "\n"
        "        .labelled-control-label-container {\n"
        "            position: relative;\n"
        "            display: block;\n"
        "            max-width: 5.5rem;\n"
        "            margin: -0.4rem auto 0.4rem;\n"
        "            text-align: center;\n"
        "            font-size: var(--labelled-control-font-size);\n"
        "            color: var(--labelled-control-font-color);\n"
        "            cursor: default;\n"
        "        }\n"
        "\n"
        "        .labelled-control-name {\n"
        "            overflow: hidden;\n"
        "            text-overflow: ellipsis;\n"
        "        }\n"
        "\n"
        "        .labelled-control-value {\n"
        "            position: absolute;\n"
        "            top: 0;\n"
        "            left: 0;\n"
        "            right: 0;\n"
        "            overflow: hidden;\n"
        "            text-overflow: ellipsis;\n"
        "            opacity: 0;\n"
        "        }\n"
        "\n"
        "        .labelled-control:hover .labelled-control-name,\n"
        "        .labelled-control:active .labelled-control-name {\n"
        "            opacity: 0;\n"
        "        }\n"
        "        .labelled-control:hover .labelled-control-value,\n"
        "        .labelled-control:active .labelled-control-value {\n"
        "            opacity: 1;\n"
        "        }`;\n"
        "    }\n"
        "}\n"
        "\n"
        "if (! window.customElements.get (\"cmaj-knob-control\"))             window.customElements.define (\"cmaj-knob-control\", Knob);\n"
        "if (! window.customElements.get (\"cmaj-switch-control\"))           window.customElements.define (\"cmaj-switch-control\", Switch);\n"
        "if (! window.customElements.get (\"cmaj-options-control\"))          window.customElements.define (\"cmaj-options-control\", Options);\n"
        "if (! window.customElements.get (\"cmaj-labelled-control-holder\"))  window.customElements.define (\"cmaj-labelled-control-holder\", LabelledControlHolder);\n"
        "\n"
        "\n"
        "//==============================================================================\n"
        "/** Fetches all the CSS for the controls defined in this module */\n"
        "export function getAllCSS()\n"
        "{\n"
        "    return `\n"
        "        ${Options.getCSS()}\n"
        "        ${Knob.getCSS()}\n"
        "        ${Switch.getCSS()}\n"
        "        ${LabelledControlHolder.getCSS()}`;\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** Creates a suitable control for the given endpoint.\n"
        " *\n"
        " *  @param {PatchConnection} patchConnection - the connection to connect to\n"
        " *  @param {Object} endpointInfo - the endpoint details, as provided by a PatchConnection\n"
        " *                                 in its status callback.\n"
        "*/\n"
        "export function createControl (patchConnection, endpointInfo)\n"
        "{\n"
        "    if (Switch.canBeUsedFor (endpointInfo))\n"
        "        return new (window.customElements.get (\"cmaj-switch-control\")) (patchConnection, endpointInfo);\n"
        "\n"
        "    if (Options.canBeUsedFor (endpointInfo))\n"
        "        return new (window.customElements.get (\"cmaj-options-control\")) (patchConnection, endpointInfo);\n"
        "\n"
        "    if (Knob.canBeUsedFor (endpointInfo))\n"
        "        return new (window.customElements.get (\"cmaj-knob-control\")) (patchConnection, endpointInfo);\n"
        "\n"
        "    return undefined;\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** Creates a suitable labelled control for the given endpoint.\n"
        " *\n"
        " *  @param {PatchConnection} patchConnection - the connection to connect to\n"
        " *  @param {Object} endpointInfo - the endpoint details, as provided by a PatchConnection\n"
        " *                                 in its status callback.\n"
        "*/\n"
        "export function createLabelledControl (patchConnection, endpointInfo)\n"
        "{\n"
        "    const control = createControl (patchConnection, endpointInfo);\n"
        "\n"
        "    if (control)\n"
        "        return new (window.customElements.get (\"cmaj-labelled-control-holder\")) (patchConnection, endpointInfo, control);\n"
        "\n"
        "    return undefined;\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** Takes a patch connection and its current status object, and tries to create\n"
        " *  a control for the given endpoint ID.\n"
        " *\n"
        " *  @param {PatchConnection} patchConnection - the connection to connect to\n"
        " *  @param {Object} status - the connection's current status\n"
        " *  @param {string} endpointID - the endpoint you'd like to control\n"
        " */\n"
        "export function createLabelledControlForEndpointID (patchConnection, status, endpointID)\n"
        "{\n"
        "    for (const endpointInfo of status?.details?.inputs)\n"
        "        if (endpointInfo.endpointID == endpointID)\n"
        "            return createLabelledControl (patchConnection, endpointInfo);\n"
        "\n"
        "    return undefined;\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajpatchconnection_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "import { EventListenerList } from \"./cmaj-event-listener-list.js\"\n"
        "import * as midi from \"./cmaj-midi-helpers.js\"\n"
        "import PianoKeyboard from \"./cmaj-piano-keyboard.js\"\n"
        "import GenericPatchView from \"./cmaj-generic-patch-view.js\"\n"
        "import * as ParameterControls from \"./cmaj-parameter-controls.js\"\n"
        "\n"
        "//==============================================================================\n"
        "/** This class implements the API and much of the logic for communicating with\n"
        " *  an instance of a patch that is running.\n"
        " */\n"
        "export class PatchConnection  extends EventListenerList\n"
        "{\n"
        "    constructor()\n"
        "    {\n"
        "        super();\n"
        "    }\n"
        "\n"
        "    /** Returns the current Cmajor version */\n"
        "    async getCmajorVersion()\n"
        "    {\n"
        "        const version = await import (\"/cmaj_api/cmaj-version.js\");\n"
        "        return version.getCmajorVersion();\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Status-handling methods:\n"
        "\n"
        "    /** Calling this will trigger an asynchronous callback to any status listeners with the\n"
        "     *  patch's current state. Use addStatusListener() to attach a listener to receive it.\n"
        "     */\n"
        "    requestStatusUpdate()                             { this.sendMessageToServer ({ type: \"req_status\" }); }\n"
        "\n"
        "    /** Attaches a listener function that will be called whenever the patch's status changes.\n"
        "     *  The function will be called with a parameter object containing many properties describing the status,\n"
        "     *  including whether the patch is loaded, any errors, endpoint descriptions, its manifest, etc.\n"
        "     */\n"
        "    addStatusListener (listener)                      { this.addEventListener    (\"status\", listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added with addStatusListener()\n"
        "     */\n"
        "    removeStatusListener (listener)                   { this.removeEventListener (\"status\", listener); }\n"
        "\n"
        "    /** Causes the patch to be reset to its \"just loaded\" state. */\n"
        "    resetToInitialState()                             { this.sendMessageToServer ({ type: \"req_reset\" }); }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Methods for sending data to input endpoints:\n"
        "\n"
        "    /** Sends a value to one of the patch's input endpoints.\n"
        "     *\n"
        "     *  This can be used to send a value to either an 'event' or 'value' type input endpoint.\n"
        "     *  If the endpoint is a 'value' type, then the rampFrames parameter can optionally be used to specify\n"
        "     *  the number of frames over which the current value should ramp to the new target one.\n"
        "     *  The value parameter will be coerced to the type that is expected by the endpoint. So for\n"
        "     *  examples, numbers will be converted to float or integer types, javascript objects and arrays\n"
        "     *  will be converted into more complex types in as good a fashion is possible.\n"
        "     */\n"
        "    sendEventOrValue (endpointID, value, rampFrames, timeoutMillisecs)  { this.sendMessageToServer ({ type: \"send_value\", id: endpointID, value, rampFrames, timeout: timeoutMillisecs }); }\n"
        "\n"
        "    /** Sends a short MIDI message value to a MIDI endpoint.\n"
        "     *  The value must be a number encoded with `(byte0 << 16) | (byte1 << 8) | byte2`.\n"
        "     */\n"
        "    sendMIDIInputEvent (endpointID, shortMIDICode)    { this.sendEventOrValue (endpointID, { message: shortMIDICode }); }\n"
        "\n"
        "    /** Tells the patch that a series of changes that constitute a gesture is about to take place\n"
        "     *  for the given endpoint. Remember to call sendParameterGestureEnd() after they're done!\n"
        "     */\n"
        "    sendParameterGestureStart (endpointID)            { this.sendMessageToServer ({ type: \"send_gesture_start\", id: endpointID }); }\n"
        "\n"
        "    /** Tells the patch that a gesture started by sendParameterGestureStart() has finished.\n"
        "     */\n"
        "    sendParameterGestureEnd (endpointID)              { this.sendMessageToServer ({ type: \"send_gesture_end\", id: endpointID }); }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Stored state control methods:\n"
        "\n"
        "    /** Requests a callback to any stored-state value listeners with the current value of a given key-value pair.\n"
        "     *  To attach a listener to receive these events, use addStoredStateValueListener().\n"
        "     *  @param {string} key\n"
        "     */\n"
        "    requestStoredStateValue (key)                     { this.sendMessageToServer ({ type: \"req_state_value\", key: key }); }\n"
        "\n"
        "    /** Modifies a key-value pair in the patch's stored state.\n"
        "     *  @param {string} key\n"
        "     *  @param {Object | null | undefined} newValue\n"
        "     */\n"
        "    sendStoredStateValue (key, newValue)              { this.sendMessageToServer ({ type: \"send_state_value\", key: key, value: newValue }); }\n"
        "\n"
        "    /** Removes all stored state values in the patch.\n"
        "     */\n"
        "    clearAllStoredStateValues()                       { this.sendMessageToServer ({ type: \"clear_all_state_values\" }); }\n"
        "\n"
        "    /** Attaches a listener function that will be called when any key-value pair in the stored state is changed.\n"
        "     *  The listener function will receive a message parameter with properties 'key' and 'value'.\n"
        "     */\n"
        "    addStoredStateValueListener (listener)            { this.addEventListener    (\"state_key_value\", listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added with addStoredStateValueListener().\n"
        "     */\n"
        "    removeStoredStateValueListener (listener)         { this.removeEventListener (\"state_key_value\", listener); }\n"
        "\n"
        "    /** Applies a complete stored state to the patch.\n"
        "     *  To get the current complete state, use requestFullStoredState().\n"
        "     */\n"
        "    sendFullStoredState (fullState)                   { this.sendMessageToServer ({ type: \"send_full_state\", value: fullState }); }\n"
        "\n"
        "    /** Asynchronously requests the full stored state of the patch.\n"
        "     *  The listener function that is supplied will be called asynchronously with the state as its argument.\n"
        "     */\n"
        "    requestFullStoredState (callback)\n"
        "    {\n"
        "        const replyType = \"fullstate_response_\" + (Math.floor (Math.random() * 100000000)).toString();\n"
        "        this.addSingleUseListener (replyType, callback);\n"
        "        this.sendMessageToServer ({ type: \"req_full_state\", replyType: replyType });\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Listener methods:\n"
        "\n"
        "    /** Attaches a listener function that will receive updates with the events or audio data\n"
        "     *  that is being sent or received by an endpoint.\n"
        "     *\n"
        "     *  If the endpoint is an event or value, the callback will be given an argument which is\n"
        "     *  the new value.\n"
        "     *\n"
        "     *  If the endpoint has the right shape to be treated as \"audio\" then the callback will receive\n"
        "     *  a stream of updates of the min/max range of chunks of data that is flowing through it.\n"
        "     *  There will be one callback per chunk of data, and the size of chunks is specified by\n"
        "     *  the optional granularity parameter.\n"
        "     *\n"
        "     *  @param {string} endpointID\n"
        "     *  @param {number} granularity - if defined, this specifies the number of frames per callback\n"
        "     *  @param {boolean} sendFullAudioData - if false, the listener will receive an argument object containing\n"
        "     *     two properties 'min' and 'max', which are each an array of values, one element per audio\n"
        "     *     channel. This allows you to find the highest and lowest samples in that chunk for each channel.\n"
        "     *     If sendFullAudioData is true, the listener's argument will have a property 'data' which is an\n"
        "     *     array containing one array per channel of raw audio samples data.\n"
        "     */\n"
        "    addEndpointListener (endpointID, listener, granularity, sendFullAudioData)\n"
        "    {\n"
        "        const listenerID = \"event_\" + endpointID + \"_\" + (Math.floor (Math.random() * 100000000)).toString();\n"
        "        listener[\"cmaj_endpointListenerID_\" + endpointID] = listenerID;\n"
        "        this.addEventListener (listenerID, listener);\n"
        "        this.sendMessageToServer ({ type: \"add_endpoint_listener\", endpoint: endpointID, replyType: listenerID,\n"
        "                                    granularity: granularity, fullAudioData: sendFullAudioData });\n"
        "    }\n"
        "\n"
        "    /** Removes a listener that was previously added with addEndpointListener()\n"
        "     *  @param {string} endpointID\n"
        "    */\n"
        "    removeEndpointListener (endpointID, listener)\n"
        "    {\n"
        "        const listenerID = listener[\"cmaj_endpointListenerID_\" + endpointID];\n"
        "        listener[\"cmaj_endpointListenerID_\" + endpointID] = undefined;\n"
        "        this.removeEventListener (listenerID, listener);\n"
        "        this.sendMessageToServer ({ type: \"remove_endpoint_listener\", endpoint: endpointID, replyType: listenerID });\n"
        "    }\n"
        "\n"
        "    /** This will trigger an asynchronous callback to any parameter listeners that are\n"
        "     *  attached, providing them with its up-to-date current value for the given endpoint.\n"
        "     *  Use addAllParameterListener() to attach a listener to receive the result.\n"
        "     *  @param {string} endpointID\n"
        "     */\n"
        "    requestParameterValue (endpointID)                  { this.sendMessageToServer ({ type: \"req_param_value\", id: endpointID }); }\n"
        "\n"
        "    /** Attaches a listener function which will be called whenever the value of a specific parameter changes.\n"
        "     *  The listener function will be called with an argument which is the new value.\n"
        "     *  @param {string} endpointID\n"
        "     */\n"
        "    addParameterListener (endpointID, listener)         { this.addEventListener (\"param_value_\" + endpointID.toString(), listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added with addParameterListener()\n"
        "     *  @param {string} endpointID\n"
        "    */\n"
        "    removeParameterListener (endpointID, listener)      { this.removeEventListener (\"param_value_\" + endpointID.toString(), listener); }\n"
        "\n"
        "    /** Attaches a listener function which will be called whenever the value of any parameter changes in the patch.\n"
        "     *  The listener function will be called with an argument object with the fields 'endpointID' and 'value'.\n"
        "     */\n"
        "    addAllParameterListener (listener)                  { this.addEventListener (\"param_value\", listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added with addAllParameterListener()\n"
        "     */\n"
        "    removeAllParameterListener (listener)               { this.removeEventListener (\"param_value\", listener); }\n"
        "\n"
        "    /** This takes a relative path to an asset within the patch bundle, and converts it to a\n"
        "     *  path relative to the root of the browser that is showing the view.\n"
        "     *\n"
        "     *  You need to use this in your view code to translate your asset URLs to a form that\n"
        "     *  can be safely used in your view's HTML DOM (e.g. in its CSS). This is needed because the\n"
        "     *  host's HTTP server (which is delivering your view pages) may have a different '/' root\n"
        "     *  than the root of your patch (e.g. if a single server is serving multiple patch GUIs).\n"
        "     *\n"
        "     *  @param {string} path\n"
        "     */\n"
        "    getResourceAddress (path)                           { return path; }\n"
        "\n"
        "    //==============================================================================\n"
        "    /**\n"
        "     *  This property contains various utility classes and functions from the Cmajor API,\n"
        "     *  for use in your GUI or worker code.\n"
        "     */\n"
        "    utilities = {\n"
        "        /** MIDI utility functions from cmaj-midi-helpers.js */\n"
        "        midi,\n"
        "        /** On-screen keyboard class from cmaj-piano-keyboard.js */\n"
        "        PianoKeyboard,\n"
        "        /** Basic parameter control GUI elements, from cmaj-parameter-controls.js */\n"
        "        ParameterControls,\n"
        "        /** The default view GUI, from cmaj-generic-patch-view.js */\n"
        "        GenericPatchView\n"
        "    };\n"
        "\n"
        "    //==============================================================================\n"
        "    // Private methods follow this point..\n"
        "\n"
        "    /** @private */\n"
        "    deliverMessageFromServer (msg)\n"
        "    {\n"
        "        if (msg.type === \"status\")\n"
        "            this.manifest = msg.message?.manifest;\n"
        "\n"
        "        if (msg.type == \"param_value\")\n"
        "            this.dispatchEvent (\"param_value_\" + msg.message.endpointID, msg.message.value);\n"
        "\n"
        "        this.dispatchEvent (msg.type, msg.message);\n"
        "    }\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajpatchview_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "import { PatchConnection } from \"./cmaj-patch-connection.js\"\n"
        "\n"
        "//==============================================================================\n"
        "/** Returns a list of types of view that can be created for this patch.\n"
        " */\n"
        "export function getAvailableViewTypes (patchConnection)\n"
        "{\n"
        "    if (! patchConnection)\n"
        "        return [];\n"
        "\n"
        "    if (patchConnection.manifest?.view?.src)\n"
        "        return [\"custom\", \"generic\"];\n"
        "\n"
        "    return [\"generic\"];\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** Creates and returns a HTMLElement view which can be shown to control this patch.\n"
        " *\n"
        " *  If no preferredType argument is supplied, this will return either a custom patch-specific\n"
        " *  view (if the manifest specifies one), or a generic view if not. The preferredType argument\n"
        " *  can be used to choose one of the types of view returned by getAvailableViewTypes().\n"
        " *\n"
        " *  @param {PatchConnection} patchConnection - the connection to use\n"
        " *  @param {string} preferredType - the name of the type of view to open, e.g. \"generic\"\n"
        " *                                  or the name of one of the views in the manifest\n"
        " *  @returns {HTMLElement} a HTMLElement that can be displayed as the patch GUI\n"
        " */\n"
        "export async function createPatchView (patchConnection, preferredType)\n"
        "{\n"
        "    if (patchConnection?.manifest)\n"
        "    {\n"
        "        let view = patchConnection.manifest.view;\n"
        "\n"
        "        if (view && preferredType === \"generic\")\n"
        "            if (view.src)\n"
        "                view = undefined;\n"
        "\n"
        "        const viewModuleURL = view?.src ? patchConnection.getResourceAddress (view.src) : \"./cmaj-generic-patch-view.js\";\n"
        "        const viewModule = await import (viewModuleURL);\n"
        "        const patchView = await viewModule?.default (patchConnection);\n"
        "\n"
        "        if (patchView)\n"
        "        {\n"
        "            patchView.style.display = \"block\";\n"
        "\n"
        "            if (view?.width > 10)\n"
        "                patchView.style.width = view.width + \"px\";\n"
        "            else\n"
        "                patchView.style.width = undefined;\n"
        "\n"
        "            if (view?.height > 10)\n"
        "                patchView.style.height = view.height + \"px\";\n"
        "            else\n"
        "                patchView.style.height = undefined;\n"
        "\n"
        "            return patchView;\n"
        "        }\n"
        "    }\n"
        "\n"
        "    return undefined;\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** If a patch view declares itself to be scalable, this will attempt to scale it to fit\n"
        " *  into a given parent element.\n"
        " *\n"
        " *  @param {HTMLElement} view - the patch view\n"
        " *  @param {HTMLElement} parentToScale - the patch view's direct parent element, to which\n"
        " *                                       the scale factor will be applied\n"
        " *  @param {HTMLElement} parentContainerToFitTo - an outer parent of the view, whose bounds\n"
        " *                                                the view will be made to fit\n"
        " */\n"
        "export function scalePatchViewToFit (view, parentToScale, parentContainerToFitTo)\n"
        "{\n"
        "    function getClientSize (view)\n"
        "    {\n"
        "        const clientStyle = getComputedStyle (view);\n"
        "\n"
        "        return {\n"
        "            width:  view.clientHeight - parseFloat (clientStyle.paddingTop)  - parseFloat (clientStyle.paddingBottom),\n"
        "            height: view.clientWidth  - parseFloat (clientStyle.paddingLeft) - parseFloat (clientStyle.paddingRight)\n"
        "        };\n"
        "    }\n"
        "\n"
        "    const scaleLimits = view.getScaleFactorLimits?.();\n"
        "\n"
        "    if (scaleLimits && (scaleLimits.minScale || scaleLimits.maxScale) && parentContainerToFitTo)\n"
        "    {\n"
        "        const minScale = scaleLimits.minScale || 0.25;\n"
        "        const maxScale = scaleLimits.maxScale || 5.0;\n"
        "\n"
        "        const targetSize = getClientSize (parentContainerToFitTo);\n"
        "        const clientSize = getClientSize (view);\n"
        "\n"
        "        const scaleW = targetSize.width / clientSize.width;\n"
        "        const scaleH = targetSize.height / clientSize.height;\n"
        "\n"
        "        const scale = Math.min (maxScale, Math.max (minScale, Math.min (scaleW, scaleH)));\n"
        "\n"
        "        parentToScale.style.transform = `scale(${scale})`;\n"
        "    }\n"
        "    else\n"
        "    {\n"
        "        parentToScale.style.transform = \"none\";\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "class PatchViewHolder extends HTMLElement\n"
        "{\n"
        "    constructor (view)\n"
        "    {\n"
        "        super();\n"
        "        this.view = view;\n"
        "        this.style = `display: block; position: relative; width: 100%; height: 100%; overflow: visible; transform-origin: 0% 0%;`;\n"
        "    }\n"
        "\n"
        "    connectedCallback()\n"
        "    {\n"
        "        this.appendChild (this.view);\n"
        "        this.resizeObserver = new ResizeObserver (() => scalePatchViewToFit (this.view, this, this.parentElement));\n"
        "        this.resizeObserver.observe (this.parentElement);\n"
        "        scalePatchViewToFit (this.view, this, this.parentElement);\n"
        "    }\n"
        "\n"
        "    disconnectedCallback()\n"
        "    {\n"
        "        this.resizeObserver = undefined;\n"
        "        this.innerHTML = \"\";\n"
        "    }\n"
        "}\n"
        "\n"
        "//==============================================================================\n"
        "/** Creates and returns a HTMLElement view which can be shown to control this patch.\n"
        " *\n"
        " *  Unlike createPatchView(), this will return a holder element that handles scaling\n"
        " *  and resizing, and which follows changes to the size of the parent that you\n"
        " *  append it to.\n"
        " *\n"
        " *  If no preferredType argument is supplied, this will return either a custom patch-specific\n"
        " *  view (if the manifest specifies one), or a generic view if not. The preferredType argument\n"
        " *  can be used to choose one of the types of view returned by getAvailableViewTypes().\n"
        " *\n"
        " *  @param {PatchConnection} patchConnection - the connection to use\n"
        " *  @param {string} preferredType - the name of the type of view to open, e.g. \"generic\"\n"
        " *                                  or the name of one of the views in the manifest\n"
        " *  @returns {HTMLElement} a HTMLElement that can be displayed as the patch GUI\n"
        " */\n"
        "export async function createPatchViewHolder (patchConnection, preferredType)\n"
        "{\n"
        "    const view = await createPatchView (patchConnection, preferredType);\n"
        "\n"
        "    if (view)\n"
        "    {\n"
        "        const patchViewHolderName = \"cmaj-patch-view-holder\";\n"
        "\n"
        "        if (! window.customElements.get (patchViewHolderName)) window.customElements.define (patchViewHolderName, PatchViewHolder);\n"
        "\n"
        "        return new (window.customElements.get (patchViewHolderName)) (view);\n"
        "    }\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajpianokeyboard_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88     The Cmajor Toolkit\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  The Cmajor project is subject to commercial or open-source licensing.\n"
        "//  You may use it under the terms of the GPLv3 (see www.gnu.org/licenses), or\n"
        "//  visit https://cmajor.dev to learn about our commercial licence options.\n"
        "//\n"
        "//  CMAJOR IS PROVIDED \"AS IS\" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER\n"
        "//  EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE\n"
        "//  DISCLAIMED.\n"
        "\n"
        "import * as midi from \"./cmaj-midi-helpers.js\"\n"
        "\n"
        "/**\n"
        " *  An general-purpose on-screen piano keyboard component that allows clicks or\n"
        " *  key-presses to be used to play things.\n"
        " *\n"
        " *  To receive events, you can attach \"note-down\" and \"note-up\" event listeners via\n"
        " *  the standard HTMLElement/EventTarget event system, e.g.\n"
        " *\n"
        " *  myKeyboardElement.addEventListener(\"note-down\", (note) => { ...handle note on... });\n"
        " *  myKeyboardElement.addEventListener(\"note-up\",   (note) => { ...handle note off... });\n"
        " *\n"
        " *  The `note` object will contain a `note` property with the MIDI note number.\n"
        " *  (And obviously you can remove them with removeEventListener)\n"
        " *\n"
        " *  Or, if you're connecting the keyboard to a PatchConnection, you can use the helper\n"
        " *  method attachToPatchConnection() to create and attach some suitable listeners.\n"
        " *\n"
        " */\n"
        "export default class PianoKeyboard extends HTMLElement\n"
        "{\n"
        "    constructor ({ naturalNoteWidth,\n"
        "                   accidentalWidth,\n"
        "                   accidentalPercentageHeight,\n"
        "                   naturalNoteBorder,\n"
        "                   accidentalNoteBorder,\n"
        "                   pressedNoteColour } = {})\n"
        "    {\n"
        "        super();\n"
        "\n"
        "        this.naturalWidth = naturalNoteWidth || 20;\n"
        "        this.accidentalWidth = accidentalWidth || 12;\n"
        "        this.accidentalPercentageHeight = accidentalPercentageHeight || 66;\n"
        "        this.naturalBorder = naturalNoteBorder || \"2px solid #333\";\n"
        "        this.accidentalBorder = accidentalNoteBorder || \"2px solid #333\";\n"
        "        this.pressedColour = pressedNoteColour || \"#8ad\";\n"
        "\n"
        "        this.root = this.attachShadow({ mode: \"open\" });\n"
        "\n"
        "        this.root.addEventListener (\"mousedown\",   (event) => this.handleMouse (event, true, false) );\n"
        "        this.root.addEventListener (\"mouseup\",     (event) => this.handleMouse (event, false, true) );\n"
        "        this.root.addEventListener (\"mousemove\",   (event) => this.handleMouse (event, false, false) );\n"
        "        this.root.addEventListener (\"mouseenter\",  (event) => this.handleMouse (event, false, false) );\n"
        "        this.root.addEventListener (\"mouseout\",    (event) => this.handleMouse (event, false, false) );\n"
        "\n"
        "        this.addEventListener (\"keydown\",  (event) => this.handleKey (event, true));\n"
        "        this.addEventListener (\"keyup\",    (event) => this.handleKey (event, false));\n"
        "        this.addEventListener (\"focusout\", (event) => this.allNotesOff());\n"
        "\n"
        "        this.currentDraggedNote = -1;\n"
        "        this.currentExternalNotesOn = new Set();\n"
        "        this.currentKeyboardNotes = new Set();\n"
        "        this.currentPlayedNotes = new Set();\n"
        "        this.currentDisplayedNotes = new Set();\n"
        "        this.notes = [];\n"
        "        this.modifierKeys = 0;\n"
        "        this.currentTouches = new Map();\n"
        "\n"
        "        this.refreshHTML();\n"
        "\n"
        "        for (let child of this.root.children)\n"
        "        {\n"
        "            child.addEventListener (\"touchstart\", (event) => this.touchStart (event), {passive:false} );\n"
        "            child.addEventListener (\"touchend\",   (event) => this.touchEnd (event) );\n"
        "        }\n"
        "    }\n"
        "\n"
        "    static get observedAttributes()\n"
        "    {\n"
        "        return [\"root-note\", \"note-count\", \"key-map\"];\n"
        "    }\n"
        "\n"
        "    get config()\n"
        "    {\n"
        "        return {\n"
        "            rootNote: parseInt(this.getAttribute(\"root-note\") || \"36\"),\n"
        "            numNotes: parseInt(this.getAttribute(\"note-count\") || \"61\"),\n"
        "            keymap: this.getAttribute(\"key-map\") || \"KeyA KeyW KeyS KeyE KeyD KeyF KeyT KeyG KeyY KeyH KeyU KeyJ KeyK KeyO KeyL KeyP Semicolon\",\n"
        "        };\n"
        "    }\n"
        "\n"
        "    /** This attaches suitable listeners to make this keyboard control the given MIDI\n"
        "     *  endpoint of a PatchConnection object. Use detachPatchConnection() to remove\n"
        "     *  a connection later on.\n"
        "     *\n"
        "     *  @param {PatchConnection} patchConnection\n"
        "     *  @param {string} midiInputEndpointID\n"
        "     */\n"
        "    attachToPatchConnection (patchConnection, midiInputEndpointID)\n"
        "    {\n"
        "        const velocity = 100;\n"
        "\n"
        "        const callbacks = {\n"
        "            noteDown: e => patchConnection.sendMIDIInputEvent (midiInputEndpointID, 0x900000 | (e.detail.note << 8) | velocity),\n"
        "            noteUp:   e => patchConnection.sendMIDIInputEvent (midiInputEndpointID, 0x800000 | (e.detail.note << 8) | velocity),\n"
        "            midiIn:   e => this.handleExternalMIDI (e.message),\n"
        "            midiInputEndpointID\n"
        "        };\n"
        "\n"
        "        if (! this.callbacks)\n"
        "            this.callbacks = new Map();\n"
        "\n"
        "        this.callbacks.set (patchConnection, callbacks);\n"
        "\n"
        "        this.addEventListener (\"note-down\", callbacks.noteDown);\n"
        "        this.addEventListener (\"note-up\",   callbacks.noteUp);\n"
        "        patchConnection.addEndpointListener (midiInputEndpointID, callbacks.midiIn);\n"
        "    }\n"
        "\n"
        "    /** This removes the connection to a PatchConnection object that was previously attached\n"
        "     *  with attachToPatchConnection().\n"
        "     *\n"
        "     *  @param {PatchConnection} patchConnection\n"
        "     */\n"
        "    detachPatchConnection (patchConnection)\n"
        "    {\n"
        "        const callbacks = this.callbacks.get (patchConnection);\n"
        "\n"
        "        if (callbacks)\n"
        "        {\n"
        "            this.removeEventListener (\"note-down\", callbacks.noteDown);\n"
        "            this.removeEventListener (\"note-up\",   callbacks.noteUp);\n"
        "            patchConnection.removeEndpointListener (callbacks.midiInputEndpointID, callbacks.midiIn);\n"
        "        }\n"
        "\n"
        "        this.callbacks[patchConnection] = undefined;\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** Can be overridden to return the color to use for a note index */\n"
        "    getNoteColour (note)    { return undefined; }\n"
        "\n"
        "    /** Can be overridden to return the text label to draw on a note index */\n"
        "    getNoteLabel (note)     { return midi.getChromaticScaleIndex (note) == 0 ? midi.getNoteNameWithOctaveNumber (note) : \"\"; }\n"
        "\n"
        "    /** Clients should call this to deliver a MIDI message, which the keyboard will use to\n"
        "     *  highlight the notes that are currently playing.\n"
        "     */\n"
        "    handleExternalMIDI (message)\n"
        "    {\n"
        "        if (midi.isNoteOn (message))\n"
        "        {\n"
        "            const note = midi.getNoteNumber (message);\n"
        "            this.currentExternalNotesOn.add (note);\n"
        "            this.refreshActiveNoteElements();\n"
        "        }\n"
        "        else if (midi.isNoteOff (message))\n"
        "        {\n"
        "            const note = midi.getNoteNumber (message);\n"
        "            this.currentExternalNotesOn.delete (note);\n"
        "            this.refreshActiveNoteElements();\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** This method will be called when the user plays a note. The default behaviour is\n"
        "     *  to dispath an event, but you could override this if you needed to.\n"
        "    */\n"
        "    sendNoteOn (note)   { this.dispatchEvent (new CustomEvent('note-down', { detail: { note: note }})); }\n"
        "\n"
        "    /** This method will be called when the user releases a note. The default behaviour is\n"
        "     *  to dispath an event, but you could override this if you needed to.\n"
        "    */\n"
        "    sendNoteOff (note)  { this.dispatchEvent (new CustomEvent('note-up',   { detail: { note: note } })); }\n"
        "\n"
        "    /** Clients can call this to force all the notes to turn off, e.g. in a \"panic\". */\n"
        "    allNotesOff()\n"
        "    {\n"
        "        this.setDraggedNote (-1);\n"
        "        this.modifierKeys = 0;\n"
        "\n"
        "        for (let note of this.currentKeyboardNotes.values())\n"
        "            this.removeKeyboardNote (note);\n"
        "\n"
        "        this.currentExternalNotesOn.clear();\n"
        "        this.refreshActiveNoteElements();\n"
        "    }\n"
        "\n"
        "    setDraggedNote (newNote)\n"
        "    {\n"
        "        if (newNote != this.currentDraggedNote)\n"
        "        {\n"
        "            if (this.currentDraggedNote >= 0)\n"
        "                this.sendNoteOff (this.currentDraggedNote);\n"
        "\n"
        "            this.currentDraggedNote = newNote;\n"
        "\n"
        "            if (this.currentDraggedNote >= 0)\n"
        "                this.sendNoteOn (this.currentDraggedNote);\n"
        "\n"
        "            this.refreshActiveNoteElements();\n"
        "        }\n"
        "    }\n"
        "\n"
        "    addKeyboardNote (note)\n"
        "    {\n"
        "        if (! this.currentKeyboardNotes.has (note))\n"
        "        {\n"
        "            this.sendNoteOn (note);\n"
        "            this.currentKeyboardNotes.add (note);\n"
        "            this.refreshActiveNoteElements();\n"
        "        }\n"
        "    }\n"
        "\n"
        "    removeKeyboardNote (note)\n"
        "    {\n"
        "        if (this.currentKeyboardNotes.has (note))\n"
        "        {\n"
        "            this.sendNoteOff (note);\n"
        "            this.currentKeyboardNotes.delete (note);\n"
        "            this.refreshActiveNoteElements();\n"
        "        }\n"
        "    }\n"
        "\n"
        "    isNoteActive (note)\n"
        "    {\n"
        "        return note == this.currentDraggedNote\n"
        "            || this.currentExternalNotesOn.has (note)\n"
        "            || this.currentKeyboardNotes.has (note);\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** @private */\n"
        "    touchEnd (event)\n"
        "    {\n"
        "        for (const touch of event.changedTouches)\n"
        "        {\n"
        "            const note = this.currentTouches.get (touch.identifier);\n"
        "            this.currentTouches.delete (touch.identifier);\n"
        "            this.removeKeyboardNote (note);\n"
        "        }\n"
        "\n"
        "        event.preventDefault();\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    touchStart (event)\n"
        "    {\n"
        "        for (const touch of event.changedTouches)\n"
        "        {\n"
        "            const note = touch.target.id.substring (4);\n"
        "            this.currentTouches.set (touch.identifier, note);\n"
        "            this.addKeyboardNote (note);\n"
        "        }\n"
        "\n"
        "        event.preventDefault();\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    handleMouse (event, isDown, isUp)\n"
        "    {\n"
        "        if (isDown)\n"
        "            this.isDragging = true;\n"
        "\n"
        "        if (this.isDragging)\n"
        "        {\n"
        "            let newActiveNote = -1;\n"
        "\n"
        "            if (event.buttons != 0 && event.type != \"mouseout\")\n"
        "            {\n"
        "                const note = event.target.id.substring (4);\n"
        "\n"
        "                if (note !== undefined)\n"
        "                    newActiveNote = parseInt (note);\n"
        "            }\n"
        "\n"
        "            this.setDraggedNote (newActiveNote);\n"
        "\n"
        "            if (! isDown)\n"
        "                event.preventDefault();\n"
        "        }\n"
        "\n"
        "        if (isUp)\n"
        "            this.isDragging = false;\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    handleKey (event, isDown)\n"
        "    {\n"
        "        if (event.key == \"Meta\" || event.key == \"Alt\" || event.key == \"Control\" || event.key == \"Shift\")\n"
        "        {\n"
        "            this.modifierKeys += isDown ? 1 : -1;\n"
        "            return;\n"
        "        }\n"
        "\n"
        "        if (this.modifierKeys != 0)\n"
        "            return;\n"
        "\n"
        "        const config = this.config;\n"
        "        const index = config.keymap.split (\" \").indexOf (event.code);\n"
        "\n"
        "        if (index >= 0)\n"
        "        {\n"
        "            const note = Math.floor ((config.rootNote + (config.numNotes / 4) + 11) / 12) * 12 + index;\n"
        "\n"
        "            if (isDown)\n"
        "                this.addKeyboardNote (note);\n"
        "            else\n"
        "                this.removeKeyboardNote (note);\n"
        "\n"
        "            event.preventDefault();\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    refreshHTML()\n"
        "    {\n"
        "        this.root.innerHTML = `<style>${this.getCSS()}</style>${this.getNoteElements()}`;\n"
        "\n"
        "        for (let i = 0; i < 128; ++i)\n"
        "        {\n"
        "            const elem = this.shadowRoot.getElementById (`note${i.toString()}`);\n"
        "            this.notes.push ({ note: i, element: elem });\n"
        "        }\n"
        "\n"
        "        this.style.maxWidth = window.getComputedStyle (this).scrollWidth;\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    refreshActiveNoteElements()\n"
        "    {\n"
        "        for (let note of this.notes)\n"
        "        {\n"
        "            if (note.element)\n"
        "            {\n"
        "                if (this.isNoteActive (note.note))\n"
        "                    note.element.classList.add (\"active\");\n"
        "                else\n"
        "                    note.element.classList.remove (\"active\");\n"
        "            }\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    getAccidentalOffset (note)\n"
        "    {\n"
        "        let index = midi.getChromaticScaleIndex (note);\n"
        "\n"
        "        let negativeOffset = -this.accidentalWidth / 16;\n"
        "        let positiveOffset = 3 * this.accidentalWidth / 16;\n"
        "\n"
        "        const accOffset = this.naturalWidth - (this.accidentalWidth / 2);\n"
        "        const offsets = [ 0, negativeOffset, 0, positiveOffset, 0, 0, negativeOffset, 0, 0, 0, positiveOffset, 0 ];\n"
        "\n"
        "        return accOffset + offsets[index];\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    getNoteElements()\n"
        "    {\n"
        "        const config = this.config;\n"
        "        let naturals = \"\", accidentals = \"\";\n"
        "        let x = 0;\n"
        "\n"
        "        for (let i = 0; i < config.numNotes; ++i)\n"
        "        {\n"
        "            const note = config.rootNote + i;\n"
        "            const name = this.getNoteLabel (note);\n"
        "\n"
        "            if (midi.isNatural (note))\n"
        "            {\n"
        "                naturals += `<div class=\"natural-note note\" id=\"note${note}\" style=\" left: ${x + 1}px\"><p>${name}</p></div>`;\n"
        "            }\n"
        "            else\n"
        "            {\n"
        "                let accidentalOffset = this.getAccidentalOffset (note);\n"
        "                accidentals += `<div class=\"accidental-note note\" id=\"note${note}\" style=\"left: ${x + accidentalOffset}px\"></div>`;\n"
        "            }\n"
        "\n"
        "            if (midi.isNatural (note + 1) || i == config.numNotes - 1)\n"
        "                x += this.naturalWidth;\n"
        "        }\n"
        "\n"
        "        this.style.maxWidth = (x + 1) + \"px\";\n"
        "\n"
        "        return `<div tabindex=\"0\" class=\"note-holder\" style=\"width: ${x + 1}px;\">\n"
        "                ${naturals}\n"
        "                ${accidentals}\n"
        "                </div>`;\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    getCSS()\n"
        "    {\n"
        "        let extraColours = \"\";\n"
        "        const config = this.config;\n"
        "\n"
        "        for (let i = 0; i < config.numNotes; ++i)\n"
        "        {\n"
        "            const note = config.rootNote + i;\n"
        "            const colourOverride = this.getNoteColour (note);\n"
        "\n"
        "            if (colourOverride)\n"
        "                extraColours += `#note${note}:not(.active) { background: ${colourOverride}; }`;\n"
        "        }\n"
        "\n"
        "        return `\n"
        "            * {\n"
        "                box-sizing: border-box;\n"
        "                user-select: none;\n"
        "                -webkit-user-select: none;\n"
        "                -moz-user-select: none;\n"
        "                -ms-user-select: none;\n"
        "                margin: 0;\n"
        "                padding: 0;\n"
        "            }\n"
        "\n"
        "            :host {\n"
        "                display: block;\n"
        "                overflow: auto;\n"
        "                position: relative;\n"
        "            }\n"
        "\n"
        "            .natural-note {\n"
        "                position: absolute;\n"
        "                border: ${this.naturalBorder};\n"
        "                background: #fff;\n"
        "                width: ${this.naturalWidth}px;\n"
        "                height: 100%;\n"
        "\n"
        "                display: flex;\n"
        "                align-items: end;\n"
        "                justify-content: center;\n"
        "            }\n"
        "\n"
        "            p {\n"
        "                pointer-events: none;\n"
        "                text-align: center;\n"
        "                font-size: 0.7rem;\n"
        "                color: grey;\n"
        "            }\n"
        "\n"
        "            .accidental-note {\n"
        "                position: absolute;\n"
        "                top: 0;\n"
        "                border: ${this.accidentalBorder};\n"
        "                background: #333;\n"
        "                width: ${this.accidentalWidth}px;\n"
        "                height: ${this.accidentalPercentageHeight}%;\n"
        "            }\n"
        "\n"
        "            .note-holder {\n"
        "                position: relative;\n"
        "                height: 100%;\n"
        "            }\n"
        "\n"
        "            .active {\n"
        "                background: ${this.pressedColour};\n"
        "            }\n"
        "\n"
        "            ${extraColours}\n"
        "            `\n"
        "    }\n"
        "}\n";
    static constexpr const char* cmaj_api_cmajserversession_js =
        "//\n"
        "//     ,ad888ba,                              88\n"
        "//    d8\"'    \"8b\n"
        "//   d8            88,dba,,adba,   ,aPP8A.A8  88\n"
        "//   Y8,           88    88    88  88     88  88\n"
        "//    Y8a.   .a8P  88    88    88  88,   ,88  88     (C)2024 Cmajor Software Ltd\n"
        "//     '\"Y888Y\"'   88    88    88  '\"8bbP\"Y8  88     https://cmajor.dev\n"
        "//                                           ,88\n"
        "//                                        888P\"\n"
        "//\n"
        "//  This file may be used under the terms of the ISC license:\n"
        "//\n"
        "//  Permission to use, copy, modify, and/or distribute this software for any purpose with or\n"
        "//  without fee is hereby granted, provided that the above copyright notice and this permission\n"
        "//  notice appear in all copies. THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL\n"
        "//  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY\n"
        "//  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR\n"
        "//  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,\n"
        "//  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n"
        "//  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n"
        "\n"
        "import { PatchConnection } from \"./cmaj-patch-connection.js\"\n"
        "import { EventListenerList } from \"./cmaj-event-listener-list.js\"\n"
        "\n"
        "\n"
        "//==============================================================================\n"
        "/*\n"
        " *  This class provides the API and manages the communication protocol between\n"
        " *  a javascript application and a Cmajor session running on some kind of server\n"
        " *  (which may be local or remote).\n"
        " *\n"
        " *  This is an abstract base class: some kind of transport layer will create a\n"
        " *  subclass of ServerSession which a client application can then use to control\n"
        " *  and interact with the server.\n"
        " */\n"
        "export class ServerSession   extends EventListenerList\n"
        "{\n"
        "    /** A server session must be given a unique sessionID.\n"
        "     * @param {string} sessionID - this must be a unique string which is safe for\n"
        "     *                             use as an identifier or filename\n"
        "    */\n"
        "    constructor (sessionID)\n"
        "    {\n"
        "        super();\n"
        "\n"
        "        this.sessionID = sessionID;\n"
        "        this.activePatchConnections = new Set();\n"
        "        this.status = { connected: false, loaded: false };\n"
        "        this.lastServerMessageTime = Date.now();\n"
        "        this.checkForServerTimer = setInterval (() => this.checkServerStillExists(), 2000);\n"
        "    }\n"
        "\n"
        "    /** Call `dispose()` when this session is no longer needed and should be released. */\n"
        "    dispose()\n"
        "    {\n"
        "        if (this.checkForServerTimer)\n"
        "        {\n"
        "            clearInterval (this.checkForServerTimer);\n"
        "            this.checkForServerTimer = undefined;\n"
        "        }\n"
        "\n"
        "        this.status = { connected: false, loaded: false };\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Session status methods:\n"
        "\n"
        "    /** Attaches a listener function which will be called when the session status changes.\n"
        "     *  The listener will be called with an argument object containing lots of properties\n"
        "     *  describing the state, including any errors, loaded patch manifest, etc.\n"
        "     */\n"
        "    addStatusListener (listener)                        { this.addEventListener    (\"session_status\", listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added by `addStatusListener()`\n"
        "     */\n"
        "    removeStatusListener (listener)                     { this.removeEventListener (\"session_status\", listener); }\n"
        "\n"
        "    /** Asks the server to asynchronously send a status update message with the latest status.\n"
        "     */\n"
        "    requestSessionStatus()                              { this.sendMessageToServer ({ type: \"req_session_status\" }); }\n"
        "\n"
        "    /** Returns the session's last known status object. */\n"
        "    getCurrentStatus()                                  { return this.status; }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Patch loading:\n"
        "\n"
        "    /** Asks the server to load the specified patch into our session.\n"
        "     */\n"
        "    loadPatch (patchFileToLoad)\n"
        "    {\n"
        "        this.currentPatchLocation = patchFileToLoad;\n"
        "        this.sendMessageToServer ({ type: \"load_patch\", file: patchFileToLoad });\n"
        "    }\n"
        "\n"
        "    /** Asynchronously returns a list of patches that it has access to.\n"
        "     *  The return value is an array of manifest objects describing each of the patches.\n"
        "     */\n"
        "    async requestAvailablePatchList()\n"
        "    {\n"
        "        return await this.sendMessageToServerWithReply ({ type: \"req_patchlist\" });\n"
        "    }\n"
        "\n"
        "    /** Creates and returns a new PatchConnection object which can be used to control the\n"
        "     *  patch that this session has loaded.\n"
        "     */\n"
        "    createPatchConnection()\n"
        "    {\n"
        "        class ServerPatchConnection  extends PatchConnection\n"
        "        {\n"
        "            constructor (session)\n"
        "            {\n"
        "                super();\n"
        "                this.session = session;\n"
        "                this.manifest = session.status?.manifest;\n"
        "                this.session.activePatchConnections.add (this);\n"
        "            }\n"
        "\n"
        "            dispose()\n"
        "            {\n"
        "                this.session.activePatchConnections.delete (this);\n"
        "                this.session = undefined;\n"
        "            }\n"
        "\n"
        "            sendMessageToServer (message)\n"
        "            {\n"
        "                this.session?.sendMessageToServer (message);\n"
        "            }\n"
        "\n"
        "            getResourceAddress (path)\n"
        "            {\n"
        "                if (! this.session?.status?.httpRootURL)\n"
        "                    return undefined;\n"
        "\n"
        "                return this.session.status.httpRootURL\n"
        "                        + (path.startsWith (\"/\") ? path.substr (1) : path);\n"
        "            }\n"
        "        }\n"
        "\n"
        "        return new ServerPatchConnection (this);\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Audio input source handling:\n"
        "\n"
        "    /**\n"
        "     *  Sets a custom audio input source for a particular endpoint.\n"
        "     *\n"
        "     *  When a source is changed, a callback is sent to any audio input mode listeners (see\n"
        "     *  `addAudioInputModeListener()`)\n"
        "     *\n"
        "     *  @param {Object} endpointID\n"
        "     *  @param {boolean} shouldMute - if true, the endpoint will be muted\n"
        "     *  @param {Uint8Array | Array} fileDataToPlay - if this is some kind of array containing\n"
        "     *  binary data that can be parsed as an audio file, then it will be sent across for the\n"
        "     *  server to play as a looped input sample.\n"
        "     */\n"
        "    setAudioInputSource (endpointID, shouldMute, fileDataToPlay)\n"
        "    {\n"
        "        const loopFile = \"_audio_source_\" + endpointID;\n"
        "\n"
        "        if (fileDataToPlay)\n"
        "        {\n"
        "            this.registerFile (loopFile,\n"
        "            {\n"
        "               size: fileDataToPlay.byteLength,\n"
        "               read: (start, length) => { return new Blob ([fileDataToPlay.slice (start, start + length)]); }\n"
        "            });\n"
        "\n"
        "            this.sendMessageToServer ({ type: \"set_custom_audio_input\",\n"
        "                                        endpoint: endpointID,\n"
        "                                        file: loopFile });\n"
        "        }\n"
        "        else\n"
        "        {\n"
        "            this.removeFile (loopFile);\n"
        "\n"
        "            this.sendMessageToServer ({ type: \"set_custom_audio_input\",\n"
        "                                        endpoint: endpointID,\n"
        "                                        mute: !! shouldMute });\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** Attaches a listener function to be told when the input source for a particular\n"
        "     *  endpoint is changed by a call to `setAudioInputSource()`.\n"
        "     */\n"
        "    addAudioInputModeListener (endpointID, listener)    { this.addEventListener    (\"audio_input_mode_\" + endpointID, listener); }\n"
        "\n"
        "    /** Removes a listener previously added with `addAudioInputModeListener()` */\n"
        "    removeAudioInputModeListener (endpointID, listener) { this.removeEventListener (\"audio_input_mode_\" + endpointID, listener); }\n"
        "\n"
        "    /** Asks the server to send an update with the latest status to any audio mode listeners that\n"
        "     *  are attached to the given endpoint.\n"
        "     *  @param {string} endpointID\n"
        "     */\n"
        "    requestAudioInputMode (endpointID)                  { this.sendMessageToServer ({ type: \"req_audio_input_mode\", endpoint: endpointID }); }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Audio device methods:\n"
        "\n"
        "    /** Enables or disables audio playback.\n"
        "     *  When playback state changes, a status update is sent to any status listeners.\n"
        "     * @param {boolean} shouldBeActive\n"
        "     */\n"
        "    setAudioPlaybackActive (shouldBeActive)             { this.sendMessageToServer ({ type: \"set_audio_playback_active\", active: shouldBeActive }); }\n"
        "\n"
        "    /** Asks the server to apply a new set of audio device properties.\n"
        "     *  The properties object uses the same format as the object that is passed to the listeners\n"
        "     *  (see `addAudioDevicePropertiesListener()`).\n"
        "     */\n"
        "    setAudioDeviceProperties (newProperties)            { this.sendMessageToServer ({ type: \"set_audio_device_props\", properties: newProperties }); }\n"
        "\n"
        "    /** Attaches a listener function which will be called when the audio device properties are\n"
        "     *  changed.\n"
        "     *\n"
        "     *  You can remove the listener when it's no longer needed with `removeAudioDevicePropertiesListener()`.\n"
        "     *\n"
        "     *  @param listener - this callback will receive an argument object containing all the\n"
        "     *                    details about the device.\n"
        "     */\n"
        "    addAudioDevicePropertiesListener (listener)         { this.addEventListener    (\"audio_device_properties\", listener); }\n"
        "\n"
        "    /** Removes a listener that was added with `addAudioDevicePropertiesListener()` */\n"
        "    removeAudioDevicePropertiesListener (listener)      { this.removeEventListener (\"audio_device_properties\", listener); }\n"
        "\n"
        "    /** Causes an asynchronous callback to any audio device listeners that are registered. */\n"
        "    requestAudioDeviceProperties()                      { this.sendMessageToServer ({ type: \"req_audio_device_props\" }); }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** Asks the server to asynchronously generate some code from the currently loaded patch.\n"
        "     *\n"
        "     *  @param {string} codeType - this must be one of the strings that are listed in the\n"
        "     *                             status's `codeGenTargets` property. For example, \"cpp\"\n"
        "     *                             would request a C++ version of the patch.\n"
        "     *  @param {Object} [extraOptions] - this optionally provides target-specific properties.\n"
        "     *  @returns an object containing the code, errors and other metadata about the patch.\n"
        "     */\n"
        "    async requestGeneratedCode (codeType, extraOptions)\n"
        "    {\n"
        "        return await this.sendMessageToServerWithReply ({ type: \"req_codegen\",\n"
        "                                                          codeType: codeType,\n"
        "                                                          options: extraOptions, });\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    // File change monitoring:\n"
        "\n"
        "    /** Attaches a listener to be told when a file change is detected in the currently-loaded\n"
        "     *  patch. The function will be called with an object that gives rough details about the\n"
        "     *  type of change, i.e. whether it's a manifest or asset file, or a cmajor file, but it\n"
        "     *  won't provide any information about exactly which files are involved.\n"
        "     */\n"
        "    addFileChangeListener (listener)                    { this.addEventListener    (\"patch_source_changed\", listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added with `addFileChangeListener()`.\n"
        "     */\n"
        "    removeFileChangeListener (listener)                 { this.removeEventListener (\"patch_source_changed\", listener); }\n"
        "\n"
        "    //==============================================================================\n"
        "    // CPU level monitoring methods:\n"
        "\n"
        "    /** Attaches a listener function which will be sent messages containing CPU info.\n"
        "     *  To remove the listener, call `removeCPUListener()`. To change the rate of these\n"
        "     *  messages, use `setCPULevelUpdateRate()`.\n"
        "     */\n"
        "    addCPUListener (listener)                       { this.addEventListener    (\"cpu_info\", listener); this.updateCPULevelUpdateRate(); }\n"
        "\n"
        "    /** Removes a listener that was previously attached with `addCPUListener()`. */\n"
        "    removeCPUListener (listener)                    { this.removeEventListener (\"cpu_info\", listener); this.updateCPULevelUpdateRate(); }\n"
        "\n"
        "    /** Changes the frequency at which CPU level update messages are sent to listeners. */\n"
        "    setCPULevelUpdateRate (framesPerUpdate)         { this.cpuFramesPerUpdate = framesPerUpdate; this.updateCPULevelUpdateRate(); }\n"
        "\n"
        "    /** Attaches a listener to be told when a file change is detected in the currently-loaded\n"
        "     *  patch. The function will be called with an object that gives rough details about the\n"
        "     *  type of change, i.e. whether it's a manifest or asset file, or a cmajor file, but it\n"
        "     *  won't provide any information about exactly which files are involved.\n"
        "     */\n"
        "    addInfiniteLoopListener (listener)              { this.addEventListener    (\"infinite_loop_detected\", listener); }\n"
        "\n"
        "    /** Removes a listener that was previously added with `addFileChangeListener()`. */\n"
        "    removeInfiniteLoopListener (listener)           { this.removeEventListener (\"infinite_loop_detected\", listener); }\n"
        "\n"
        "    //==============================================================================\n"
        "    /** Registers a virtual file with the server, under the given name.\n"
        "     *\n"
        "     *  @param {string} filename - the full path name of the file\n"
        "     *  @param {Object} contentProvider - this object must have a property called `size` which is a\n"
        "     *            constant size in bytes for the file, and a method `read (offset, size)` which\n"
        "     *            returns an array (or UInt8Array) of bytes for the data in a given chunk of the file.\n"
        "     *            The server may repeatedly call this method at any time until `removeFile()` is\n"
        "     *            called to deregister the file.\n"
        "     */\n"
        "    registerFile (filename, contentProvider)\n"
        "    {\n"
        "        if (! this.files)\n"
        "            this.files = new Map();\n"
        "\n"
        "        this.files.set (filename, contentProvider);\n"
        "\n"
        "        this.sendMessageToServer ({ type: \"register_file\",\n"
        "                                    filename: filename,\n"
        "                                    size: contentProvider.size });\n"
        "    }\n"
        "\n"
        "    /** Removes a file that was previously registered with `registerFile()`. */\n"
        "    removeFile (filename)\n"
        "    {\n"
        "        this.sendMessageToServer ({ type: \"remove_file\",\n"
        "                                    filename: filename });\n"
        "        this.files?.delete (filename);\n"
        "    }\n"
        "\n"
        "    //==============================================================================\n"
        "    // Private methods from this point...\n"
        "\n"
        "    /** An implementation subclass must call this when the session first connects\n"
        "     *  @private\n"
        "     */\n"
        "    handleSessionConnection()\n"
        "    {\n"
        "        if (! this.status.connected)\n"
        "        {\n"
        "            this.requestSessionStatus();\n"
        "            this.requestAudioDeviceProperties();\n"
        "\n"
        "            if (this.currentPatchLocation)\n"
        "            {\n"
        "                this.loadPatch (this.currentPatchLocation);\n"
        "                this.currentPatchLocation = undefined;\n"
        "            }\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** An implementation subclass must call this when a message arrives\n"
        "     *  @private\n"
        "     */\n"
        "    handleMessageFromServer (msg)\n"
        "    {\n"
        "        this.lastServerMessageTime = Date.now();\n"
        "        const type = msg.type;\n"
        "        const message = msg.message;\n"
        "\n"
        "        switch (type)\n"
        "        {\n"
        "            case \"cpu_info\":\n"
        "            case \"audio_device_properties\":\n"
        "            case \"patch_source_changed\":\n"
        "            case \"infinite_loop_detected\":\n"
        "                this.dispatchEvent (type, message);\n"
        "                break;\n"
        "\n"
        "            case \"session_status\":\n"
        "                message.connected = true;\n"
        "                this.setNewStatus (message);\n"
        "                break;\n"
        "\n"
        "            case \"req_file_read\":\n"
        "                this.handleFileReadRequest (message);\n"
        "                break;\n"
        "\n"
        "            case \"ping\":\n"
        "                this.sendMessageToServer ({ type: \"ping\" });\n"
        "                break;\n"
        "\n"
        "            default:\n"
        "                if (type.startsWith (\"audio_input_mode_\") || type.startsWith (\"reply_\"))\n"
        "                {\n"
        "                    this.dispatchEvent (type, message);\n"
        "                    break;\n"
        "                }\n"
        "\n"
        "                for (const c of this.activePatchConnections)\n"
        "                    c.deliverMessageFromServer (msg);\n"
        "\n"
        "                break;\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    checkServerStillExists()\n"
        "    {\n"
        "        if (Date.now() > this.lastServerMessageTime + 10000)\n"
        "            this.setNewStatus ({\n"
        "                connected: false,\n"
        "                loaded: false,\n"
        "                status: \"Cannot connect to the Cmajor server\"\n"
        "            });\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    setNewStatus (newStatus)\n"
        "    {\n"
        "        this.status = newStatus;\n"
        "        this.dispatchEvent (\"session_status\", this.status);\n"
        "        this.updateCPULevelUpdateRate();\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    updateCPULevelUpdateRate()\n"
        "    {\n"
        "        const rate = this.getNumListenersForType (\"cpu_info\") > 0 ? (this.cpuFramesPerUpdate || 15000) : 0;\n"
        "        this.sendMessageToServer ({ type: \"set_cpu_info_rate\",\n"
        "                                    framesPerCallback: rate });\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    handleFileReadRequest (request)\n"
        "    {\n"
        "        const contentProvider = this.files?.get (request?.file);\n"
        "\n"
        "        if (contentProvider && request.offset !== null && request.size != 0)\n"
        "        {\n"
        "            const data = contentProvider.read (request.offset, request.size);\n"
        "            const reader = new FileReader();\n"
        "\n"
        "            reader.onloadend = (e) =>\n"
        "            {\n"
        "                const base64 = e.target?.result?.split?.(\",\", 2)[1];\n"
        "\n"
        "                if (base64)\n"
        "                    this.sendMessageToServer ({ type: \"file_content\",\n"
        "                                                file: request.file,\n"
        "                                                data: base64,\n"
        "                                                start: request.offset });\n"
        "            };\n"
        "\n"
        "            reader.readAsDataURL (data);\n"
        "        }\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    sendMessageToServerWithReply (message)\n"
        "    {\n"
        "        return new Promise ((resolve, reject) =>\n"
        "        {\n"
        "            const replyType = \"reply_\" + message.type + \"_\" + this.createRandomID();\n"
        "            this.addSingleUseListener (replyType, resolve);\n"
        "            this.sendMessageToServer ({ ...message, replyType });\n"
        "        });\n"
        "    }\n"
        "\n"
        "    /** @private */\n"
        "    createRandomID()\n"
        "    {\n"
        "        return (Math.floor (Math.random() * 100000000)).toString();\n"
        "    }\n"
        "}\n";
    static constexpr const char* view_LICENSE =
        "Apache License\n"
        "Version 2.0, January 2004\n"
        "http://www.apache.org/licenses/\n"
        "\n"
        "TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION\n"
        "\n"
        "1. Definitions.\n"
        "\n"
        "\"License\" shall mean the terms and conditions for use, reproduction, and\n"
        "distribution as defined by Sections 1 through 9 of this document.\n"
        "\n"
        "\"Licensor\" shall mean the copyright owner or entity authorized by the copyright\n"
        "owner that is granting the License.\n"
        "\n"
        "\"Legal Entity\" shall mean the union of the acting entity and all other entities\n"
        "that control, are controlled by, or are under common control with that entity.\n"
        "For the purposes of this definition, \"control\" means (i) the power, direct or\n"
        "indirect, to cause the direction or management of such entity, whether by\n"
        "contract or otherwise, or (ii) ownership of fifty percent (50%) or more of the\n"
        "outstanding shares, or (iii) beneficial ownership of such entity.\n"
        "\n"
        "\"You\" (or \"Your\") shall mean an individual or Legal Entity exercising\n"
        "permissions granted by this License.\n"
        "\n"
        "\"Source\" form shall mean the preferred form for making modifications, including\n"
        "but not limited to software source code, documentation source, and configuration\n"
        "files.\n"
        "\n"
        "\"Object\" form shall mean any form resulting from mechanical transformation or\n"
        "translation of a Source form, including but not limited to compiled object code,\n"
        "generated documentation, and conversions to other media types.\n"
        "\n"
        "\"Work\" shall mean the work of authorship, whether in Source or Object form, made\n"
        "available under the License, as indicated by a copyright notice that is included\n"
        "in or attached to the work (an example is provided in the Appendix below).\n"
        "\n"
        "\"Derivative Works\" shall mean any work, whether in Source or Object form, that\n"
        "is based on (or derived from) the Work and for which the editorial revisions,\n"
        "annotations, elaborations, or other modifications represent, as a whole, an\n"
        "original work of authorship. For the purposes of this License, Derivative Works\n"
        "shall not include works that remain separable from, or merely link (or bind by\n"
        "name) to the interfaces of, the Work and Derivative Works thereof.\n"
        "\n"
        "\"Contribution\" shall mean any work of authorship, including the original version\n"
        "of the Work and any modifications or additions to that Work or Derivative Works\n"
        "thereof, that is intentionally submitted to Licensor for inclusion in the Work\n"
        "by the copyright owner or by an individual or Legal Entity authorized to submit\n"
        "on behalf of the copyright owner. For the purposes of this definition,\n"
        "\"submitted\" means any form of electronic, verbal, or written communication sent\n"
        "to the Licensor or its representatives, including but not limited to\n"
        "communication on electronic mailing lists, source code control systems, and\n"
        "issue tracking systems that are managed by, or on behalf of, the Licensor for\n"
        "the purpose of discussing and improving the Work, but excluding communication\n"
        "that is conspicuously marked or otherwise designated in writing by the copyright\n"
        "owner as \"Not a Contribution.\"\n"
        "\n"
        "\"Contributor\" shall mean Licensor and any individual or Legal Entity on behalf\n"
        "of whom a Contribution has been received by Licensor and subsequently\n"
        "incorporated within the Work.\n"
        "\n"
        "2. Grant of Copyright License.\n"
        "\n"
        "Subject to the terms and conditions of this License, each Contributor hereby\n"
        "grants to You a perpetual, worldwide, non-exclusive, no-charge, royalty-free,\n"
        "irrevocable copyright license to reproduce, prepare Derivative Works of,\n"
        "publicly display, publicly perform, sublicense, and distribute the Work and such\n"
        "Derivative Works in Source or Object form.\n"
        "\n"
        "3. Grant of Patent License.\n"
        "\n"
        "Subject to the terms and conditions of this License, each Contributor hereby\n"
        "grants to You a perpetual, worldwide, non-exclusive, no-charge, royalty-free,\n"
        "irrevocable (except as stated in this section) patent license to make, have\n"
        "made, use, offer to sell, sell, import, and otherwise transfer the Work, where\n"
        "such license applies only to those patent claims licensable by such Contributor\n"
        "that are necessarily infringed by their Contribution(s) alone or by combination\n"
        "of their Contribution(s) with the Work to which such Contribution(s) was\n"
        "submitted. If You institute patent litigation against any entity (including a\n"
        "cross-claim or counterclaim in a lawsuit) alleging that the Work or a\n"
        "Contribution incorporated within the Work constitutes direct or contributory\n"
        "patent infringement, then any patent licenses granted to You under this License\n"
        "for that Work shall terminate as of the date such litigation is filed.\n"
        "\n"
        "4. Redistribution.\n"
        "\n"
        "You may reproduce and distribute copies of the Work or Derivative Works thereof\n"
        "in any medium, with or without modifications, and in Source or Object form,\n"
        "provided that You meet the following conditions:\n"
        "\n"
        "You must give any other recipients of the Work or Derivative Works a copy of\n"
        "this License; and\n"
        "You must cause any modified files to carry prominent notices stating that You\n"
        "changed the files; and\n"
        "You must retain, in the Source form of any Derivative Works that You distribute,\n"
        "all copyright, patent, trademark, and attribution notices from the Source form\n"
        "of the Work, excluding those notices that do not pertain to any part of the\n"
        "Derivative Works; and\n"
        "If the Work includes a \"NOTICE\" text file as part of its distribution, then any\n"
        "Derivative Works that You distribute must include a readable copy of the\n"
        "attribution notices contained within such NOTICE file, excluding those notices\n"
        "that do not pertain to any part of the Derivative Works, in at least one of the\n"
        "following places: within a NOTICE text file distributed as part of the\n"
        "Derivative Works; within the Source form or documentation, if provided along\n"
        "with the Derivative Works; or, within a display generated by the Derivative\n"
        "Works, if and wherever such third-party notices normally appear. The contents of\n"
        "the NOTICE file are for informational purposes only and do not modify the\n"
        "License. You may add Your own attribution notices within Derivative Works that\n"
        "You distribute, alongside or as an addendum to the NOTICE text from the Work,\n"
        "provided that such additional attribution notices cannot be construed as\n"
        "modifying the License.\n"
        "You may add Your own copyright statement to Your modifications and may provide\n"
        "additional or different license terms and conditions for use, reproduction, or\n"
        "distribution of Your modifications, or for any such Derivative Works as a whole,\n"
        "provided Your use, reproduction, and distribution of the Work otherwise complies\n"
        "with the conditions stated in this License.\n"
        "\n"
        "5. Submission of Contributions.\n"
        "\n"
        "Unless You explicitly state otherwise, any Contribution intentionally submitted\n"
        "for inclusion in the Work by You to the Licensor shall be under the terms and\n"
        "conditions of this License, without any additional terms or conditions.\n"
        "Notwithstanding the above, nothing herein shall supersede or modify the terms of\n"
        "any separate license agreement you may have executed with Licensor regarding\n"
        "such Contributions.\n"
        "\n"
        "6. Trademarks.\n"
        "\n"
        "This License does not grant permission to use the trade names, trademarks,\n"
        "service marks, or product names of the Licensor, except as required for\n"
        "reasonable and customary use in describing the origin of the Work and\n"
        "reproducing the content of the NOTICE file.\n"
        "\n"
        "7. Disclaimer of Warranty.\n"
        "\n"
        "Unless required by applicable law or agreed to in writing, Licensor provides the\n"
        "Work (and each Contributor provides its Contributions) on an \"AS IS\" BASIS,\n"
        "WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied,\n"
        "including, without limitation, any warranties or conditions of TITLE,\n"
        "NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A PARTICULAR PURPOSE. You are\n"
        "solely responsible for determining the appropriateness of using or\n"
        "redistributing the Work and assume any risks associated with Your exercise of\n"
        "permissions under this License.\n"
        "\n"
        "8. Limitation of Liability.\n"
        "\n"
        "In no event and under no legal theory, whether in tort (including negligence),\n"
        "contract, or otherwise, unless required by applicable law (such as deliberate\n"
        "and grossly negligent acts) or agreed to in writing, shall any Contributor be\n"
        "liable to You for damages, including any direct, indirect, special, incidental,\n"
        "or consequential damages of any character arising as a result of this License or\n"
        "out of the use or inability to use the Work (including but not limited to\n"
        "damages for loss of goodwill, work stoppage, computer failure or malfunction, or\n"
        "any and all other commercial damages or losses), even if such Contributor has\n"
        "been advised of the possibility of such damages.\n"
        "\n"
        "9. Accepting Warranty or Additional Liability.\n"
        "\n"
        "While redistributing the Work or Derivative Works thereof, You may choose to\n"
        "offer, and charge a fee for, acceptance of support, warranty, indemnity, or\n"
        "other liability obligations and/or rights consistent with this License. However,\n"
        "in accepting such obligations, You may act only on Your own behalf and on Your\n"
        "sole responsibility, not on behalf of any other Contributor, and only if You\n"
        "agree to indemnify, defend, and hold each Contributor harmless for any liability\n"
        "incurred by, or claims asserted against, such Contributor by reason of your\n"
        "accepting any such warranty or additional liability.\n"
        "\n"
        "END OF TERMS AND CONDITIONS\n"
        "\n"
        "APPENDIX: How to apply the Apache License to your work\n"
        "\n"
        "To apply the Apache License to your work, attach the following boilerplate\n"
        "notice, with the fields enclosed by brackets \"[]\" replaced with your own\n"
        "identifying information. (Don't include the brackets!) The text should be\n"
        "enclosed in the appropriate comment syntax for the file format. We also\n"
        "recommend that a file or class name and description of purpose be included on\n"
        "the same \"printed page\" as the copyright notice for easier identification within\n"
        "third-party archives.\n"
        "\n"
        "   Copyright [yyyy] [name of copyright owner]\n"
        "\n"
        "   Licensed under the Apache License, Version 2.0 (the \"License\");\n"
        "   you may not use this file except in compliance with the License.\n"
        "   You may obtain a copy of the License at\n"
        "\n"
        "     http://www.apache.org/licenses/LICENSE-2.0\n"
        "\n"
        "   Unless required by applicable law or agreed to in writing, software\n"
        "   distributed under the License is distributed on an \"AS IS\" BASIS,\n"
        "   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n"
        "   See the License for the specific language governing permissions and\n"
        "   limitations under the License.\n";
    static constexpr const char view_Middle_Potion_png[] = {
        (char)-119,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,(char)-128,0,0,0,(char)-128,8,6,0,0,0,(char)-61,62,97,(char)-53,0,0,16,0,73,68,65,84,120,1,(char)-20,(char)-35,105,(char)-84,93,(char)-41,117,31,
        (char)-16,75,82,19,53,112,(char)-108,68,106,(char)-78,36,(char)-54,34,37,106,(char)-116,(char)-121,(char)-56,(char)-82,(char)-29,65,(char)-114,(char)-121,(char)-92,105,20,(char)-57,114,(char)-101,
        (char)-44,(char)-114,29,(char)-60,109,82,(char)-92,77,(char)-13,(char)-91,64,63,20,5,90,(char)-96,64,(char)-127,126,42,(char)-112,6,8,18,55,14,(char)-20,(char)-60,73,(char)-36,(char)-58,(char)-114,
        (char)-21,(char)-44,69,60,(char)-43,(char)-106,29,79,74,42,(char)-53,(char)-102,108,13,(char)-106,(char)-84,121,38,37,(char)-118,34,37,(char)-114,(char)-3,(char)-1,54,(char)-33,(char)-70,(char)-34,
        60,(char)-70,(char)-113,(char)-78,(char)-93,119,31,31,(char)-59,39,(char)-100,(char)-1,93,107,(char)-81,(char)-67,(char)-10,62,123,(char)-81,(char)-75,(char)-10,(char)-38,(char)-5,(char)-100,123,
        31,(char)-75,116,(char)-76,(char)-8,(char)-33,81,109,(char)-127,(char)-59,0,56,(char)-86,(char)-35,63,26,45,6,(char)-64,98,0,28,(char)-27,22,56,(char)-54,(char)-89,(char)-65,(char)-104,1,22,3,(char)-32,
        40,(char)-73,(char)-64,81,62,(char)-3,(char)-59,12,(char)-80,24,0,71,(char)-71,5,(char)-114,(char)-46,(char)-23,(char)-41,(char)-76,23,51,64,89,(char)-30,40,(char)-91,(char)-117,1,112,(char)-108,
        58,(char)-66,(char)-90,(char)-67,24,0,101,(char)-119,(char)-93,(char)-108,46,6,(char)-64,81,(char)-22,(char)-8,(char)-102,(char)-10,98,0,(char)-108,37,(char)-114,82,(char)-70,24,0,71,(char)-87,(char)-29,
        107,(char)-38,(char)-117,1,80,(char)-106,56,74,(char)-23,98,0,28,101,(char)-114,31,78,119,49,0,(char)-122,22,57,(char)-54,(char)-54,(char)-117,1,112,(char)-108,57,124,56,(char)-35,(char)-59,0,24,
        90,(char)-28,40,43,47,6,(char)-64,81,(char)-26,(char)-16,(char)-31,116,(char)-113,(char)-122,0,88,(char)-110,73,(char)-125,(char)-71,(char)-62,(char)-78,(char)-108,(char)-113,(char)-103,(char)-63,
        (char)-79,51,(char)-76,(char)-54,(char)-22,(char)-128,126,33,42,47,(char)-33,(char)-117,65,94,110,(char)-77,(char)-29,56,(char)-13,(char)-30,(char)-44,(char)-29,50,57,56,41,(char)-12,(char)-28,96,
        69,(char)-80,42,88,25,(char)-84,14,(char)-42,116,32,(char)-125,83,34,3,109,(char)-76,5,(char)-127,(char)-94,79,125,(char)-89,(char)-6,(char)-27,115,(char)-103,(char)-44,(char)-53,97,54,28,83,14,
        95,(char)-98,9,113,54,7,(char)-97,22,(char)-2,(char)-52,(char)-32,(char)-84,(char)-32,(char)-20,(char)-32,(char)-4,(char)-32,(char)-126,96,99,(char)-80,41,120,101,(char)-128,94,24,10,(char)-54,(char)-25,
        (char)-122,127,69,(char)-96,(char)-35,(char)-6,(char)-48,83,3,(char)-127,35,40,78,12,127,124,32,75,(char)-124,28,(char)-7,(char)-41,(char)-111,28,0,(char)-100,(char)-50,17,86,40,(char)-57,112,(char)-6,
        (char)-38,(char)-72,(char)-28,(char)-116,(char)-32,(char)-68,(char)-128,67,57,(char)-9,(char)-78,(char)-29,(char)-114,59,(char)-18,85,(char)-57,30,123,(char)-20,(char)-21,86,(char)-83,90,(char)-11,
        (char)-26,(char)-107,43,87,(char)-66,(char)-23,(char)-44,83,79,125,123,(char)-16,(char)-114,(char)-32,(char)-99,107,(char)-41,(char)-82,125,103,100,111,62,(char)-19,(char)-76,(char)-45,(char)-34,
        22,(char)-6,(char)-106,(char)-109,79,62,(char)-7,(char)-115,39,(char)-100,112,(char)-62,85,(char)-53,(char)-106,45,(char)-69,50,(char)-72,(char)-30,(char)-104,99,(char)-114,(char)-71,120,(char)-90,
        47,65,(char)-79,46,(char)-68,(char)-84,33,32,42,67,44,(char)-115,(char)-52,88,66,22,(char)-18,53,(char)-37,(char)-56,12,126,(char)-74,(char)-70,(char)-123,42,103,108,(char)-114,63,33,3,(char)-28,
        (char)-8,114,(char)-6,(char)-7,(char)-100,21,(char)-89,93,118,(char)-30,(char)-119,39,94,(char)-75,122,(char)-11,(char)-22,(char)-85,(char)-49,58,(char)-21,(char)-84,(char)-97,63,(char)-1,(char)-4,
        (char)-13,(char)-33,(char)-13,(char)-54,87,(char)-66,(char)-14,(char)-105,46,(char)-71,(char)-28,(char)-110,95,(char)-35,(char)-72,113,(char)-29,123,47,(char)-69,(char)-20,(char)-78,127,118,(char)-47,
        69,23,(char)-67,(char)-17,(char)-118,43,(char)-82,(char)-8,(char)-51,75,47,(char)-67,(char)-12,(char)-125,(char)-105,95,126,(char)-7,7,(char)-82,(char)-68,(char)-14,(char)-54,95,(char)-33,(char)-76,
        105,(char)-45,(char)-81,68,(char)-10,(char)-21,(char)-111,(char)-3,70,(char)-22,63,(char)-80,121,(char)-13,(char)-26,95,59,(char)-17,(char)-68,(char)-13,(char)-34,125,(char)-6,(char)-23,(char)-89,
        (char)-65,(char)-13,(char)-108,83,78,105,65,(char)-111,(char)-5,93,22,8,42,89,98,125,120,(char)-9,(char)-106,25,100,(char)-123,(char)-91,41,27,91,(char)-56,(char)-111,115,25,(char)-12,(char)-111,
        51,(char)-38,(char)-47,(char)-88,(char)-46,(char)-4,(char)-54,12,90,106,(char)-74,42,47,(char)-116,(char)-45,47,93,(char)-75,106,(char)-107,(char)-107,(char)-3,(char)-114,56,(char)-14,(char)-67,
        (char)-63,(char)-5,94,(char)-3,(char)-22,87,(char)-1,(char)-10,(char)-58,(char)-115,27,127,57,(char)-4,123,(char)-50,57,(char)-25,(char)-100,119,(char)-98,113,(char)-58,25,(char)-81,(char)-53,(char)-118,
        127,(char)-51,(char)-118,21,43,54,6,23,30,127,(char)-4,(char)-15,107,19,40,103,45,95,(char)-66,(char)-4,(char)-100,(char)-109,78,58,(char)-23,(char)-36,56,121,99,(char)-54,(char)-25,(char)-89,(char)-97,
        (char)-51,103,(char)-98,121,(char)-26,27,19,60,63,(char)-67,97,(char)-61,(char)-122,107,18,12,(char)-1,52,65,(char)-13,(char)-85,9,(char)-108,15,38,(char)-104,(char)-34,(char)-67,110,(char)-35,(char)-70,
        119,(char)-90,(char)-3,79,37,(char)-85,92,(char)-103,49,108,8,108,47,(char)-74,26,103,(char)-117,35,46,16,(char)-106,102,2,11,(char)-3,(char)-78,(char)-86,(char)-64,(char)-118,(char)-73,(char)-38,
        (char)-92,(char)-31,(char)-26,(char)-8,(char)-92,(char)-22,(char)-41,(char)-84,89,(char)-77,(char)-26,(char)-51,23,92,112,(char)-63,(char)-75,89,(char)-27,(char)-17,(char)-50,42,127,127,(char)-100,
        (char)-9,(char)-42,(char)-11,(char)-21,(char)-41,(char)-65,33,14,58,53,(char)-50,93,(char)-65,116,(char)-23,(char)-46,(char)-27,(char)-53,(char)-106,45,59,97,(char)-55,(char)-110,37,(char)-74,10,
        (char)-3,44,13,(char)-65,100,(char)-1,(char)-2,(char)-3,80,115,39,39,94,(char)-106,15,(char)-39,101,73,(char)-38,101,(char)-41,56,118,117,(char)-18,113,(char)-106,(char)-96,(char)-56,86,(char)-15,
        (char)-38,11,47,(char)-68,(char)-16,93,9,(char)-124,127,(char)-66,105,(char)-45,(char)-90,95,126,(char)-59,43,94,113,77,2,(char)-22,109,(char)-71,(char)-49,(char)-85,(char)-46,(char)-55,43,3,103,
        (char)-116,(char)-45,67,87,6,2,(char)-95,(char)-11,25,126,65,95,11,61,0,(char)-116,(char)-49,9,(char)-100,(char)-29,(char)-83,120,(char)-85,109,83,(char)-100,(char)-14,19,113,(char)-4,(char)-101,
        (char)-78,(char)-78,127,62,(char)-85,(char)-13,87,(char)-50,62,(char)-5,(char)-20,(char)-73,39,85,(char)-1,(char)-125,56,99,93,(char)-80,54,(char)-50,(char)-109,41,(char)-106,(char)-58,(char)-55,
        99,(char)-29,(char)-29,123,44,89,(char)-78,100,(char)-76,100,(char)-55,(char)-110,86,79,(char)-34,(char)-104,(char)-63,(char)-57,(char)-116,(char)-100,(char)-46,(char)-110,(char)-4,(char)-105,29,
        (char)-26,(char)-104,21,(char)-119,(char)-118,53,113,(char)-4,(char)-85,5,93,(char)-78,(char)-61,63,73,86,120,87,(char)-78,(char)-62,(char)-37,19,100,63,(char)-111,(char)-26,21,8,107,(char)-61,59,
        (char)-109,24,(char)-121,(char)-10,41,46,(char)-52,(char)-117,(char)-127,23,(char)-30,(char)-56,24,(char)-51,(char)-40,106,(char)-43,59,(char)-111,59,(char)-63,95,22,99,(char)-65,53,(char)-58,(char)-1,
        69,(char)-85,48,(char)-85,(char)-2,31,101,(char)-107,111,72,64,(char)-56,10,(char)-57,(char)-60,73,86,(char)-17,(char)-120,(char)-29,96,(char)-46,(char)-60,(char)-94,(char)-45,(char)-22,81,(char)-96,
        (char)-125,2,(char)-66,48,91,(char)-5,(char)-44,47,(char)-115,(char)-77,79,72,52,(char)-100,100,(char)-37,(char)-104,(char)-39,38,(char)-34,(char)-101,(char)-79,92,(char)-101,(char)-20,(char)-13,
        51,9,(char)-64,(char)-53,(char)-93,99,(char)-84,(char)-21,67,109,11,(char)-26,(char)-48,(char)-58,(char)-107,(char)-14,(char)-126,(char)-69,24,121,(char)-95,13,(char)-86,(char)-100,111,5,89,73,78,
        (char)-12,30,(char)-37,(char)-82,(char)-52,(char)-98,(char)-2,(char)-113,(char)-109,(char)-122,127,49,(char)-5,(char)-13,(char)-43,(char)-55,0,(char)-101,(char)-30,(char)-76,(char)-29,(char)-125,
        99,(char)-122,(char)-50,(char)-118,(char)-84,(char)-51,(char)-87,(char)-88,2,30,(char)-118,71,11,37,79,(char)-26,104,89,(char)-95,(char)-6,43,121,(char)-23,(char)-95,100,(char)-5,(char)-10,(char)-19,
        (char)-85,32,58,38,109,(char)-114,(char)-51,(char)-39,(char)-31,(char)-100,4,(char)-62,63,(char)-52,(char)-40,126,(char)-23,(char)-36,115,(char)-49,(char)-107,17,(char)-34,(char)-110,32,(char)-39,
        28,125,(char)-127,(char)-21,(char)-87,(char)-63,19,(char)-125,76,22,(char)-47,(char)-62,(char)-70,22,90,0,24,15,67,(char)-39,71,(char)-83,106,(char)-89,(char)-19,(char)-117,(char)-13,120,(char)-10,
        (char)-58,(char)-85,(char)-82,(char)-70,(char)-22,95,100,(char)-33,(char)-67,58,7,(char)-80,77,89,125,(char)-126,(char)-93,57,(char)-117,67,96,104,(char)-42,73,(char)-78,(char)-46,(char)-23,(char)-21,
        122,126,82,125,(char)-55,(char)-48,73,(char)-70,(char)-126,37,114,(char)-25,(char)-118,101,9,(char)-124,(char)-77,(char)-78,37,(char)-4,92,(char)-126,(char)-31,23,(char)-78,45,(char)-67,35,(char)-29,
        (char)-2,(char)-55,(char)-76,115,80,20,(char)-56,(char)-58,(char)-20,108,96,(char)-114,17,47,(char)-116,107,33,13,(char)-58,(char)-54,103,32,(char)-5,(char)-67,103,121,(char)-122,(char)-69,(char)-12,
        (char)-68,(char)-13,(char)-50,(char)-69,(char)-26,13,111,120,(char)-61,(char)-65,(char)-50,(char)-118,(char)-33,(char)-104,(char)-12,42,(char)-91,30,100,(char)-71,24,(char)-65,(char)-107,57,(char)-94,
        49,(char)-7,(char)-64,(char)-105,60,(char)-59,118,41,67,43,(char)-52,124,(char)-48,43,16,(char)-31,81,24,(char)-22,(char)-110,65,(char)-81,51,44,(char)-89,(char)-51,(char)-78,4,(char)-25,9,113,(char)-4,
        (char)-26,4,(char)-63,(char)-69,(char)-78,37,(char)-68,61,(char)-113,(char)-93,(char)-81,75,54,(char)-72,40,(char)-70,(char)-26,36,8,28,70,(char)-25,(char)-51,(char)-18,(char)-71,(char)-17,33,(char)-81,
        5,51,(char)-112,(char)-116,(char)-46,94,105,(char)-27,59,77,59,76,109,(char)-50,1,(char)-17,(char)-3,57,(char)-39,95,27,(char)-61,30,23,(char)-56,12,81,59,112,(char)-107,35,34,31,103,(char)-126,
        3,53,(char)-93,86,30,(char)-27,63,117,33,7,93,(char)-109,100,(char)-67,66,(char)-43,87,(char)-1,125,(char)-35,36,(char)-103,122,114,(char)-19,102,(char)-80,36,14,63,49,(char)-25,(char)-110,(char)-45,
        (char)-13,(char)-24,(char)-7,22,25,65,16,36,120,5,(char)-63,57,(char)-47,55,(char)-57,5,19,4,11,33,0,(char)-116,97,121,12,(char)-29,(char)-43,(char)-83,(char)-125,(char)-45,(char)-58,28,(char)-82,
        94,(char)-9,(char)-6,(char)-41,(char)-65,(char)-2,55,115,(char)-54,(char)-65,42,(char)-58,117,(char)-102,(char)-105,29,(char)-94,114,(char)-32,(char)-38,(char)-69,119,111,(char)-37,(char)-125,83,
        55,(char)-86,(char)-3,(char)-8,64,(char)-51,15,63,(char)-43,65,73,(char)-118,71,11,85,(char)-57,113,(char)-59,(char)-1,40,(char)-76,(char)-41,(char)-57,67,(char)-75,(char)-85,(char)-66,35,59,102,
        (char)-7,(char)-14,(char)-27,(char)-89,(char)-27,(char)-119,(char)-31,(char)-14,28,90,(char)-81,(char)-55,(char)-69,(char)-122,87,37,8,(char)-100,101,4,(char)-72,115,(char)-63,(char)-15,(char)-43,
        (char)-26,112,82,(char)-58,63,(char)-36,(char)-9,(char)-73,(char)-78,57,(char)-33,(char)-127,(char)-23,(char)-94,(char)-92,(char)-51,(char)-85,95,(char)-13,(char)-102,(char)-41,(char)-4,90,(char)-46,
        (char)-88,(char)-3,127,124,122,(char)-114,65,(char)-101,(char)-45,13,54,43,108,(char)-68,(char)-54,(char)-107,(char)-25,2,(char)-6,(char)-121,(char)-22,(char)-85,(char)-25,(char)-55,(char)-6,50,
        39,(char)-105,(char)-116,28,(char)-56,(char)-122,(char)-63,72,(char)-106,(char)-57,(char)-58,(char)-43,(char)-39,(char)-66,54,(char)-25,41,(char)-31,(char)-102,60,(char)-86,(char)-66,49,(char)-19,
        100,55,(char)-37,(char)-127,57,11,(char)-4,(char)-125,(char)-126,59,(char)-11,(char)-13,122,29,(char)-50,0,112,111,(char)-87,(char)-48,(char)-66,(char)-50,32,23,(char)-28,4,(char)-3,(char)-45,89,
        45,(char)-17,56,(char)-2,(char)-8,(char)-29,87,(char)-25,116,125,28,(char)-61,2,67,2,126,(char)-110,117,(char)-122,114,(char)-114,40,61,(char)-19,(char)-16,116,(char)-118,87,(char)-18,65,(char)-34,
        (char)-93,(char)-22,(char)-76,(char)-127,(char)-39,(char)-54,(char)-38,(char)-88,43,74,23,(char)-56,0,63,51,(char)-106,(char)-29,(char)-14,93,(char)-61,101,14,(char)-79,(char)-103,(char)-29,(char)-37,
        82,(char)-25,123,(char)-118,122,105,100,(char)-21,99,(char)-117,(char)-120,(char)-25,(char)-1,58,108,55,(char)-50,84,(char)-83,124,(char)-113,71,103,36,53,94,(char)-112,83,(char)-13,79,(char)-27,
        (char)-15,(char)-18,(char)-11,(char)-7,50,102,3,(char)-25,(char)-89,126,(char)-68,(char)-30,25,82,(char)-71,71,47,43,7,84,125,95,(char)-105,(char)-66,74,60,107,(char)-42,(char)-96,15,99,(char)-59,
        9,76,(char)-35,(char)-93,104,(char)-87,(char)-52,56,(char)-72,(char)-118,(char)-121,(char)-92,(char)-85,86,(char)-83,(char)-38,(char)-100,67,(char)-19,(char)-43,(char)-55,114,111,(char)-118,(char)-94,
        32,(char)-16,(char)-92,(char)-29,(char)-5,(char)-116,(char)-61,(char)-10,(char)-62,(char)-24,112,5,(char)-64,(char)-79,49,(char)-128,(char)-119,123,115,(char)-73,33,123,(char)-27,(char)-27,57,48,
        (char)-67,57,6,(char)-70,36,(char)-114,104,41,113,104,(char)-24,(char)-24,31,(char)-28,(char)-64,73,(char)-11,37,75,31,(char)-44,27,74,(char)-122,22,90,69,(char)-9,49,(char)-101,(char)-100,(char)-118,
        58,20,(char)-16,(char)-128,(char)-17,81,(char)-78,(char)-94,85,39,56,106,44,51,117,75,114,56,60,(char)-25,(char)-30,(char)-117,47,126,119,(char)-50,57,94,33,123,(char)-57,(char)-79,62,(char)-6,22,
        2,95,(char)-76,(char)-71,(char)-89,60,111,(char)-105,(char)-101,(char)-50,(char)-37,(char)-51,102,110,100,95,(char)-73,(char)-9,(char)-83,(char)-54,94,126,110,(char)-98,(char)-21,(char)-81,(char)-56,
        43,(char)-43,(char)-97,(char)-53,97,(char)-55,(char)-73,108,51,42,(char)-93,(char)-79,(char)-77,25,(char)-114,17,1,63,(char)-54,127,(char)-8,66,(char)-118,(char)-19,(char)-86,50,74,111,8,(char)-50,
        (char)-40,(char)-77,103,79,(char)-53,42,(char)-69,118,(char)-19,26,(char)-11,32,87,70,(char)-23,105,(char)-37,(char)-9,(char)-45,110,48,(char)-8,(char)-96,3,(char)-60,116,(char)-47,66,(char)-107,
        123,90,124,(char)-26,(char)-100,(char)-124,119,(char)-36,(char)-22,60,(char)-31,92,27,125,(char)-113,(char)-70,14,(char)-123,(char)-89,(char)-122,23,4,47,(char)-5,0,48,65,(char)-5,(char)-66,103,
        (char)-3,(char)-77,(char)-29,124,(char)-49,(char)-7,111,(char)-50,106,56,55,6,34,(char)-113,29,70,(char)-51,(char)-7,41,(char)-113,(char)-22,63,(char)-122,(char)-122,(char)-66,92,(char)-4,36,(char)-38,
        (char)-73,(char)-35,(char)-67,123,(char)-9,(char)-120,99,(char)-97,125,(char)-10,(char)-39,(char)-47,(char)-114,29,59,70,91,(char)-73,110,29,109,(char)-37,(char)-74,109,(char)-76,101,(char)-53,(char)-106,
        (char)-47,(char)-45,79,63,(char)-35,80,(char)-78,(char)-89,(char)-98,122,(char)-86,(char)-43,(char)-47,(char)-35,(char)-71,115,(char)-25,72,(char)-37,(char)-2,(char)-66,(char)-126,99,120,(char)-65,
        (char)-2,94,(char)-61,(char)-70,73,101,(char)-6,(char)-39,(char)-106,(char)-114,91,(char)-75,106,(char)-43,(char)-122,124,(char)-11,(char)-4,(char)-98,(char)-24,120,109,108,43,(char)-16,120,56,103,
        (char)-25,(char)-127,(char)-12,(char)-5,35,93,(char)-13,(char)-103,1,(char)-106,100,68,(char)-10,58,47,67,78,(char)-51,41,(char)-1,(char)-94,124,107,(char)-9,(char)-38,4,(char)-63,(char)-26,44,9,
        39,(char)-30,84,31,(char)-72,24,29,14,(char)-108,70,45,32,70,(char)-125,(char)-1,(char)-6,122,60,(char)-108,(char)-118,(char)-43,(char)-52,121,28,(char)-6,(char)-52,51,(char)-49,(char)-116,(char)-48,
        (char)-25,(char)-97,127,(char)-66,(char)-83,(char)-6,24,127,(char)-108,85,56,74,42,30,(char)-27,(char)-124,62,(char)-54,(char)-117,(char)-101,6,50,117,30,49,5,(char)-128,32,41,8,(char)-100,(char)-34,
        (char)-7,(char)-100,88,112,95,112,111,50,84,25,15,(char)-54,61,(char)-44,(char)-51,(char)-108,(char)-105,(char)-27,49,(char)-9,117,(char)-63,91,83,(char)-74,21,56,20,(char)-54,(char)-116,108,(char)-60,
        86,17,79,(char)-1,(char)-102,(char)-49,0,48,27,17,46,(char)-11,(char)-97,(char)-105,21,112,101,14,67,111,112,(char)-30,87,49,(char)-60,(char)-48,120,125,(char)-71,120,78,97,(char)-48,42,(char)-21,
        (char)-93,(char)-100,102,85,11,4,117,9,(char)-80,(char)-26,(char)-16,60,(char)-117,(char)-113,114,(char)-34,24,(char)-27,(char)-107,109,(char)-61,108,60,(char)-67,(char)-116,107,36,32,(char)-12,
        33,32,100,11,89,(char)-63,(char)-3,(char)-64,(char)-67,80,(char)-3,(char)-125,114,15,117,80,(char)-78,94,(char)-89,(char)-109,47,(char)-55,(char)-117,(char)-82,107,(char)-78,24,(char)-82,(char)-120,
        (char)-98,111,58,(char)-3,(char)-82,(char)-128,(char)-115,82,(char)-100,(char)-97,107,(char)-66,2,64,68,123,(char)-15,(char)-79,34,(char)-45,90,(char)-105,(char)-3,(char)-2,(char)-78,56,(char)-1,
        39,(char)-77,(char)-6,86,(char)-59,48,34,62,(char)-30,23,94,(char)-87,27,(char)-81,(char)-2,50,26,25,(char)-51,(char)-66,108,(char)-43,90,(char)-31,(char)-113,63,(char)-2,(char)-8,(char)-120,(char)-109,
        4,6,7,114,36,103,115,116,(char)-83,120,(char)-85,30,114,(char)-17,(char)-106,1,4,(char)-57,16,116,(char)-75,1,(char)-19,(char)-23,(char)-37,70,(char)-12,45,(char)-64,(char)-36,(char)-53,24,10,53,
        (char)-90,(char)-94,37,(char)-97,68,(char)-115,27,(char)-44,69,(char)-33,(char)-75,52,103,(char)-96,(char)-97,77,(char)-39,123,15,1,(char)-64,70,108,21,(char)-47,(char)-12,(char)-81,(char)-7,12,
        0,(char)-23,109,77,(char)-116,(char)-35,14,126,(char)-119,(char)-6,75,(char)-110,118,(char)-105,(char)-57,2,99,39,(char)-101,(char)-82,50,90,70,26,(char)-14,85,46,61,(char)-114,(char)-79,66,(char)-97,
        124,(char)-14,73,85,(char)-93,(char)-12,63,94,(char)-35,28,41,16,56,48,(char)-9,58,40,(char)-43,91,(char)-35,(char)-6,40,40,3,61,(char)-48,70,95,(char)-38,(char)-9,(char)-127,96,107,(char)-39,(char)-66,
        125,123,59,43,24,(char)-93,(char)-10,(char)-88,(char)-101,23,37,83,(char)-18,(char)-95,14,74,(char)-122,119,(char)-65,(char)-24,30,(char)-101,51,(char)-48,89,9,(char)-126,(char)-85,83,(char)-25,
        64,(char)-24,44,(char)-64,86,(char)-77,46,(char)-116,(char)-24,(char)-51,(char)-39,53,31,1,96,(char)-11,59,(char)-32,57,(char)-8,121,53,122,(char)-123,(char)-43,(char)-97,(char)-55,123,(char)-47,
        (char)-93,(char)-82,(char)-99,(char)-52,(char)-51,40,(char)-58,64,90,(char)-103,(char)-127,(char)-96,9,38,124,(char)-88,(char)-29,124,43,(char)-46,30,(char)-51,73,5,(char)-114,(char)-29,64,(char)-114,
        (char)-44,103,(char)-18,53,14,50,(char)-27,(char)-22,(char)-82,(char)-105,(char)-105,12,(char)-91,(char)-93,14,(char)-6,76,33,(char)-96,(char)-36,(char)-125,92,(char)-48,57,95,(char)-56,10,(char)-38,
        (char)-12,48,54,125,64,47,87,(char)-18,81,122,9,(char)-78,85,121,81,(char)-76,121,(char)-35,(char)-70,117,126,75,(char)-32,(char)-115,40,91,9,(char)-128,102,(char)-97,(char)-66,(char)-113,(char)-71,
        (char)-26,(char)-25,43,0,60,(char)-13,(char)-37,(char)-5,(char)-49,73,(char)-76,95,(char)-108,(char)-76,106,(char)-65,91,(char)-58,0,96,82,61,45,35,(char)-107,(char)-68,(char)-54,104,(char)-23,(char)-39,
        (char)-101,(char)-19,(char)-13,86,36,(char)-57,0,(char)-57,115,24,(char)-48,(char)-43,30,(char)-86,(char)-51,(char)-95,(char)-8,97,(char)-99,50,(char)-24,7,(char)-12,41,(char)-88,(char)-30,(char)-84,
        118,(char)-98,16,8,(char)-100,47,27,(char)-96,116,123,(char)-72,39,104,(char)-37,(char)-53,(char)-15,37,83,15,100,(char)-23,(char)-17,(char)-84,108,(char)-115,(char)-105,100,30,(char)-78,(char)-128,
        (char)-17,10,(char)-40,108,(char)-22,(char)-2,(char)-103,(char)-10,13,68,(char)-80,(char)-43,(char)-17,25,119,109,38,(char)-72,41,39,127,81,78,110,(char)-34,99,48,10,99,(char)-96,99,97,(char)-57,
        (char)-88,3,(char)-11,12,46,(char)-27,(char)-29,99,(char)-80,(char)-26,16,(char)-50,1,(char)-85,(char)-109,(char)-68,(char)-48,117,49,102,(char)-11,(char)-93,64,7,(char)-113,86,25,5,(char)-14,(char)-98,
        (char)-46,(char)-47,119,5,(char)-126,(char)-5,38,(char)-112,(char)-87,(char)-116,(char)-97,50,(char)-100,61,(char)-102,96,(char)-62,(char)-121,(char)-10,(char)-67,(char)-72,47,(char)-69,87,(char)-6,
        61,57,79,68,126,(char)-104,(char)-22,44,32,0,(char)-40,(char)-116,(char)-19,94,96,(char)-85,(char)-66,(char)-97,(char)-105,(char)-54,(char)-49,71,0,56,(char)-48,(char)-100,(char)-110,(char)-43,121,
        (char)-42,(char)-52,4,(char)-49,(char)-52,(char)-28,125,(char)-61,55,49,(char)-43,51,70,63,41,(char)-27,(char)-34,(char)-80,(char)-100,47,(char)-3,114,118,(char)-6,108,(char)-50,(char)-113,(char)-15,
        (char)-38,(char)-93,93,(char)-75,(char)-45,6,95,52,(char)-9,83,28,(char)-93,47,(char)-29,11,99,(char)-123,(char)-114,(char)-87,(char)-70,(char)-66,47,91,(char)-117,123,(char)-70,63,(char)-32,61,
        106,(char)-38,(char)-110,(char)-6,(char)-79,(char)-22,(char)-90,(char)-38,(char)-95,(char)-43,23,57,40,(char)-93,(char)-22,(char)-48,60,25,(char)-99,(char)-73,118,(char)-19,(char)-38,75,19,92,(char)-66,
        54,118,24,(char)-76,13,(char)-4,88,62,(char)-46,(char)-49,(char)-113,(char)-125,(char)-87,118,(char)-98,(char)-127,(char)-104,(char)-128,84,(char)-74,58,(char)-50,(char)-65,32,25,(char)-32,(char)-30,
        76,118,28,(char)-47,101,(char)-128,(char)-94,(char)-47,63,(char)-24,(char)-118,110,43,(char)-93,(char)-64,(char)-72,78,(char)-32,78,(char)-3,82,49,112,6,80,(char)-84,126,(char)-118,(char)-110,(char)-67,
        24,(char)-86,95,116,54,(char)-35,(char)-66,14,(char)-81,127,(char)-9,(char)-28,120,99,16,4,(char)-38,58,19,24,27,(char)-98,30,(char)-32,65,27,101,(char)-64,(char)-109,1,30,(char)-16,(char)-63,(char)-78,
        (char)-68,18,(char)-9,119,13,126,(char)-11,92,(char)-65,34,(char)-14,(char)-26,52,85,(char)-45,(char)-71,(char)-90,29,0,(char)-19,(char)-99,127,12,(char)-76,62,(char)-47,(char)-67,33,65,112,110,
        (char)-46,(char)-88,(char)-96,(char)-104,120,40,(char)-85,41,118,6,105,122,(char)-54,96,(char)-65,117,(char)-32,43,(char)-93,(char)-53,2,28,(char)-95,14,(char)-76,71,(char)-95,120,(char)-108,(char)-47,
        (char)-47,66,(char)-43,(char)-109,23,(char)-86,(char)-82,40,121,(char)-15,(char)-91,(char)-81,92,124,(char)-26,(char)-47,(char)-98,42,42,8,(char)-78,106,(char)-37,(char)-101,67,25,74,38,(char)-24,
        117,(char)-15,125,127,2,(char)-71,47,(char)-85,(char)-121,(char)-12,125,76,(char)-26,(char)-76,50,11,(char)-59,(char)-17,6,106,27,96,(char)-61,(char)-15,(char)-94,(char)-95,55,(char)-105,(char)-104,
        102,0,(char)-120,92,123,(char)-40,41,49,(char)-50,25,(char)-85,87,(char)-81,(char)-66,32,19,(char)-12,(char)-69,(char)-5,54,126,6,(char)-128,86,(char)-104,(char)-16,17,(char)-35,81,65,(char)-75,
        (char)-107,(char)-17,(char)-64,87,(char)-50,103,120,(char)-11,(char)-22,10,85,62,84,(char)-65,67,(char)-35,106,83,(char)-14,(char)-94,(char)-28,(char)-48,(char)-105,(char)-117,71,(char)-35,67,125,
        5,66,(char)-126,(char)-68,61,(char)-126,10,(char)-46,10,0,122,64,(char)-81,(char)-89,(char)-59,(char)-21,3,(char)-108,11,(char)-103,(char)-33,(char)-38,124,35,(char)-6,(char)-118,44,24,103,1,79,
        3,2,(char)-128,45,75,101,78,(char)-23,52,3,(char)-64,74,(char)-9,86,107,(char)-107,19,110,86,(char)-1,(char)-90,24,75,64,(char)-116,29,91,(char)-122,(char)-103,52,(char)-93,(char)-34,48,120,43,75,
        122,101,104,(char)-50,(char)-73,(char)-14,(char)-45,95,107,(char)-86,(char)-66,49,51,31,85,126,(char)-79,(char)-2,(char)-5,(char)-6,(char)-30,(char)-117,(char)-50,116,53,38,37,71,(char)-95,42,(char)-16,
        (char)-58,98,76,(char)-58,(char)-106,21,(char)-36,(char)-34,17,84,61,90,(char)-29,65,(char)-95,(char)-105,(char)-31,65,63,104,(char)-22,(char)-105,100,(char)-79,(char)-68,(char)-46,(char)-94,73,
        (char)-97,94,(char)-111,123,39,48,53,63,77,(char)-85,99,41,75,0,24,(char)-4,(char)-54,(char)-100,(char)-106,(char)-49,(char)-116,(char)-111,60,(char)-9,(char)-73,(char)-5,101,(char)-110,(char)-26,
        58,17,12,81,(char)-11,40,(char)-89,115,(char)-66,85,(char)-107,(char)-43,(char)-47,(char)-34,(char)-34,(char)-59,48,45,(char)-120,116,64,(char)-65,(char)-96,12,21,24,(char)-8,(char)-86,67,(char)-107,
        (char)-11,9,120,(char)-78,66,(char)-55,122,121,(char)-55,(char)-24,(char)-112,(char)-9,32,(char)-85,122,114,(char)-9,(char)-28,124,32,119,30,32,31,66,59,32,(char)-89,7,120,32,15,100,(char)-55,19,
        (char)-42,(char)-84,89,(char)-77,33,117,14,(char)-126,(char)-50,80,108,(char)-55,(char)-90,(char)-44,(char)-26,20,(char)-51,33,115,(char)-38,(char)-29,(char)-127,(char)-50,12,(char)-42,(char)-96,
        79,74,36,(char)-97,(char)-106,(char)-109,(char)-83,(char)-65,(char)-33,59,49,19,106,39,(char)-1,3,42,(char)-109,63,(char)-23,(char)-12,53,(char)-54,(char)-98,(char)-7,(char)-55,56,62,(char)-127,
        52,90,(char)-70,116,(char)-14,(char)-80,(char)-23,(char)-46,(char)-21,105,(char)-15,(char)-28,67,12,(char)-9,(char)-30,24,127,(char)-84,(char)-46,(char)-73,43,126,82,61,25,24,(char)-109,(char)-79,
        (char)-55,2,120,(char)-37,21,(char)-24,(char)-80,(char)-38,(char)-29,(char)-23,(char)-94,(char)-48,(char)-13,(char)-54,64,(char)-106,32,90,(char)-111,96,63,61,(char)-16,106,(char)-40,(char)-29,32,
        91,(char)-78,41,(char)-107,57,(char)-59,100,75,(char)-66,(char)-12,91,(char)-40,(char)-77,12,(char)-6,(char)-92,76,102,117,(char)-116,(char)-78,34,19,35,123,(char)-47,(char)-98,123,99,81,126,(char)-18,
        (char)-71,(char)-25,(char)-38,(char)-41,(char)-71,(char)-23,(char)-89,29,(char)-70,24,(char)-103,60,(char)-3,33,99,12,(char)-37,(char)-115,43,(char)-62,(char)-88,(char)-125,(char)-80,(char)-29,(char)-52,
        81,101,(char)-78,33,94,(char)-84,(char)-82,(char)-81,(char)-57,27,11,112,(char)-68,32,5,25,75,(char)-65,125,(char)-67,50,(char)-112,(char)-95,(char)-38,0,(char)-98,(char)-84,(char)-112,(char)-14,
        (char)-46,44,(char)-102,(char)-117,19,0,(char)-89,(char)-121,(char)-9,(char)-19,(char)-87,71,(char)-23,(char)-87,(char)-8,106,42,(char)-99,102,(char)-48,(char)-94,(char)-11,(char)-8,24,(char)-30,
        (char)-92,(char)-68,(char)-7,59,45,19,89,105,(char)-94,(char)-112,(char)-70,118,(char)-103,108,99,38,124,(char)-12,122,(char)-75,(char)-118,(char)-46,(char)-41,(char)-8,89,95,91,(char)-24,(char)-11,
        (char)-122,(char)-35,(char)-88,39,(char)-101,(char)-92,67,6,(char)-22,(char)-95,120,109,(char)-96,(char)-54,(char)-22,(char)-96,(char)-54,(char)-22,(char)-128,(char)-84,(char)-89,50,9,25,61,16,(char)-84,
        (char)-88,(char)-9,21,40,(char)-88,7,(char)-19,(char)-108,65,(char)-71,71,(char)-55,66,(char)-105,(char)-90,(char)-49,125,(char)-55,(char)-98,126,40,(char)-30,28,(char)-27,(char)-20,116,72,95,(char)-11,
        (char)-3,(char)-4,56,(char)-4,52,58,(char)-27,124,56,54,(char)-109,61,41,7,(char)-64,(char)-45,(char)-29,60,105,108,(char)-4,(char)-41,(char)-72,(char)-111,(char)-113,(char)-57,(char)-104,(char)-55,
        (char)-114,121,(char)-116,85,(char)-124,(char)-126,(char)-3,31,(char)-84,(char)-6,(char)-12,49,78,(char)-3,(char)-43,(char)-90,(char)-17,(char)-121,126,65,61,40,79,(char)-46,(char)-119,113,85,(char)-115,
        49,(char)-44,25,(char)-42,(char)-113,21,(char)-61,84,(char)-65,97,(char)-37,(char)-91,108,(char)-52,40,(char)-32,(char)-115,23,(char)-116,93,0,15,(char)-5,(char)-41,(char)-112,108,120,31,50,117,
        (char)-112,(char)-84,(char)-71,50,(char)-88,119,1,2,(char)-128,77,65,(char)-11,(char)-100,97,26,1,96,112,30,93,(char)-92,(char)-83,19,114,0,92,23,99,(char)-100,(char)-36,79,(char)-114,(char)-95,
        40,13,41,25,61,(char)-64,75,(char)-93,(char)-116,(char)-104,(char)-10,(char)-29,(char)-44,93,109,(char)-44,(char)-9,(char)-4,(char)-117,(char)-107,57,(char)-122,14,12,(char)-37,(char)-111,(char)-71,
        39,(char)-88,3,(char)-78,2,57,84,25,(char)-19,(char)-5,83,46,(char)-112,27,(char)-81,(char)-128,(char)-27,96,(char)-19,10,(char)-91,(char)-93,(char)-36,(char)-13,(char)-54,80,50,52,(char)-27,37,
        (char)-79,(char)-35,(char)-118,4,(char)-127,(char)-59,35,0,(char)-40,84,(char)-43,(char)-100,98,90,1,(char)-96,(char)-33,(char)-29,(char)-110,10,79,(char)-119,49,78,12,(char)-4,(char)-27,110,27,
        120,25,(char)-105,(char)-95,8,50,(char)-47,118,48,44,74,86,(char)-32,124,70,76,(char)-5,(char)-74,(char)-6,(char)-75,(char)-123,(char)-86,(char)-41,(char)-90,120,84,25,(char)-76,81,(char)-18,(char)-47,
        (char)-53,(char)-12,1,125,(char)-67,50,104,(char)-33,(char)-53,(char)-15,47,38,83,15,116,(char)-63,(char)-36,4,0,(char)-34,(char)-5,11,(char)-3,(char)-30,(char)-23,64,(char)-15,104,(char)-127,(char)-114,
        58,(char)-108,44,116,105,(char)-74,(char)-128,(char)-43,(char)-111,121,(char)-110,114,126,98,(char)-45,35,34,3,24,40,(char)-8,59,(char)-71,(char)-20,0,(char)-53,77,98,(char)-33,(char)-52,(char)-92,
        (char)-22,86,(char)-78,(char)-75,0,0,16,0,73,68,65,84,(char)-102,(char)-77,(char)-15,(char)-103,(char)-40,(char)-104,87,(char)-50,(char)-124,(char)-37,42,47,(char)-54,97,(char)-46,103,(char)-126,
        (char)-24,5,123,127,(char)-81,(char)-113,47,84,(char)-37,(char)-94,(char)-18,(char)-95,(char)-114,67,(char)-48,30,116,(char)-86,(char)-116,(char)-17,81,(char)-14,(char)-94,(char)-22,(char)-16,61,
        45,(char)-98,124,8,117,117,79,65,12,(char)-91,(char)-93,(char)-82,(char)-58,(char)-123,47,84,125,(char)-43,(char)-91,125,(char)-90,126,(char)-20,(char)-14,(char)-109,78,58,(char)-55,(char)-93,(char)-96,
        108,(char)-54,(char)-90,(char)-91,54,103,116,42,(char)-99,102,116,(char)-6,61,62,43,(char)-9,(char)-60,(char)-52,98,121,77,(char)-86,104,(char)-22,(char)-101,(char)-13,(char)-121,101,78,7,114,(char)-44,
        22,80,6,42,(char)-86,(char)-19,108,(char)-48,78,29,93,(char)-76,80,(char)-14,(char)-66,76,86,122,(char)-8,2,(char)-99,(char)-110,(char)-29,11,100,116,(char)-108,(char)-117,(char)-30,(char)-121,(char)-96,
        71,(char)-122,102,(char)-2,(char)-19,9,38,(char)-50,108,(char)-13,37,7,117,(char)-128,(char)-17,49,(char)-112,(char)-19,79,(char)-6,63,37,(char)-9,(char)-14,52,37,(char)-3,(char)-53,2,71,68,6,48,
        72,88,(char)-102,52,120,92,28,(char)-71,55,6,104,(char)-33,(char)-2,(char)-51,54,(char)-39,76,(char)-78,85,(char)-11,6,40,(char)-103,(char)-118,(char)-76,71,(char)-58,(char)-24,(char)-11,(char)-58,
        (char)-62,48,(char)-28,16,118,108,(char)-16,42,(char)-109,(char)-11,(char)-48,63,(char)-108,(char)-116,30,84,25,61,84,(char)-71,111,75,87,25,(char)-16,(char)-38,25,51,10,50,25,10,(char)-22,11,(char)-12,
        11,37,67,(char)-23,5,(char)-82,(char)-91,121,(char)-126,(char)-14,34,(char)-120,(char)-13,91,(char)-107,(char)-113,(char)-71,(char)-124,(char)-107,58,(char)-105,(char)-3,85,95,6,(char)-68,44,47,
        112,(char)-10,(char)-59,16,(char)-57,(char)-101,100,85,(char)-12,52,51,108,(char)-114,66,123,(char)-48,(char)-79,122,(char)-76,75,123,(char)-59,(char)-74,61,52,102,(char)-16,(char)-95,93,(char)-119,
        (char)-24,67,(char)-107,(char)-5,(char)-70,(char)-98,(char)-97,84,95,(char)-19,80,(char)-24,(char)-11,(char)-107,19,(char)-56,109,(char)-84,(char)-43,118,72,(char)-23,67,47,87,(char)-114,13,122,
        (char)-47,(char)-104,(char)-41,(char)-89,(char)-126,(char)-7,(char)-47,(char)-61,3,94,29,(char)-60,(char)-7,107,114,95,25,(char)-128,61,(char)-89,(char)-30,(char)-85,(char)-87,116,106,34,(char)-63,
        (char)-46,(char)-92,(char)-80,19,51,65,(char)-125,(char)-49,(char)-68,(char)-106,52,3,(char)-102,88,(char)-22,(char)-38,85,124,(char)-47,38,(char)-52,(char)-121,(char)-78,85,19,(char)-10,(char)-96,
        43,(char)-99,(char)-116,3,(char)-127,14,28,(char)-92,48,83,32,(char)-97,77,(char)-105,124,70,(char)-83,(char)-115,(char)-89,(char)-8,(char)-94,(char)-22,97,(char)-74,114,(char)-55,(char)-117,(char)-10,
        (char)-70,(char)-109,100,21,(char)-56,85,87,84,59,80,46,(char)-118,55,118,52,88,18,27,60,(char)-97,0,8,59,(char)-38,(char)-97,15,(char)-66,(char)-110,89,(char)-61,(char)-2,(char)-16,122,(char)-87,
        (char)-100,78,95,106,31,(char)-61,(char)-10,6,9,(char)-5,50,(char)-79,125,(char)-103,80,(char)-69,71,104,115,94,100,(char)-115,106,84,60,(char)-86,92,72,(char)-48,20,59,(char)-90,67,29,101,24,43,
        12,24,(char)-9,99,60,(char)-76,(char)-86,122,(char)-3,(char)-30,(char)-5,122,124,(char)-75,(char)-63,67,(char)-33,86,(char)-101,66,(char)-55,123,(char)-99,(char)-110,(char)-95,(char)-12,122,90,60,
        121,(char)-127,12,(char)-122,125,84,125,40,27,(char)-78,31,8,2,(char)-48,100,(char)-50,(char)-96,(char)-29,57,(char)-21,108,(char)-90,35,(char)-125,116,(char)-22,23,4,94,(char)-33,(char)-38,2,(char)-56,
        (char)-102,(char)-29,51,(char)-87,25,(char)-75,3,100,88,38,101,16,114,(char)-121,64,(char)-27,30,(char)-22,102,43,107,(char)-45,(char)-41,(char)-31,75,86,(char)-76,(char)-38,23,(char)-91,83,32,(char)-93,
        7,37,19,16,(char)-59,(char)-85,47,(char)-108,(char)-84,(char)-41,45,25,74,15,(char)-123,28,(char)-124,(char)-111,(char)-106,113,122,57,(char)-31,(char)-80,(char)-36,(char)-55,82,(char)-75,127,111,
        (char)-74,(char)-112,29,(char)-111,(char)-79,103,(char)-56,(char)-36,95,(char)-45,8,0,(char)-93,52,96,(char)-121,(char)-65,61,(char)-103,(char)-64,(char)-106,50,82,102,52,54,2,(char)-98,98,81,60,
        61,(char)-64,(char)-109,51,28,90,(char)-27,(char)-30,(char)-107,97,88,38,(char)-85,(char)-10,(char)-8,(char)-62,80,54,44,15,(char)-11,38,(char)-11,91,58,61,(char)-43,(char)-49,108,(char)-70,(char)-28,
        64,(char)-57,99,32,10,(char)-38,(char)-109,3,(char)-66,(char)-96,12,125,57,(char)-19,(char)-98,(char)-49,(char)-69,0,62,(char)-38,27,57,(char)-124,(char)-52,(char)-19,(char)-91,(char)-13,(char)-71,
        (char)-19,113,(char)-44,(char)-10,43,125,(char)-18,(char)-51,75,(char)-112,29,(char)-103,(char)-108,96,104,25,(char)-128,48,101,100,86,(char)-88,7,(char)-50,(char)-89,(char)-124,(char)-73,10,81,
        (char)-27,(char)-126,114,97,40,(char)-85,50,(char)-38,(char)-73,(char)-91,79,(char)-122,22,(char)-54,41,37,71,123,(char)-12,(char)-11,(char)-109,120,50,(char)-24,(char)-37,(char)-24,(char)-69,(char)-18,
        (char)-117,87,(char)-113,2,(char)-67,(char)-94,120,24,(char)-106,103,100,(char)-5,114,126,112,(char)-112,(char)-34,(char)-107,114,(char)-39,112,108,(char)-57,(char)-56,(char)-26,(char)-28,(char)-102,
        86,0,(char)-120,(char)-42,(char)-35,(char)-103,(char)-72,12,(char)-16,76,70,26,(char)-74,(char)-19,8,(char)-29,109,96,(char)-46,62,(char)-49,16,16,(char)-3,(char)-106,41,4,65,86,(char)-63,65,(char)-1,
        12,(char)-116,122,(char)-96,(char)-13,(char)-93,(char)-126,62,(char)-48,(char)-49,64,(char)-38,24,(char)-118,71,123,(char)-48,3,122,(char)-24,(char)-92,(char)-70,94,54,(char)-119,(char)-41,(char)-82,
        96,14,(char)-61,(char)-66,(char)-108,(char)-75,43,(char)-118,47,104,(char)-121,71,(char)-77,(char)-128,118,102,(char)-2,(char)-74,(char)-128,(char)-25,35,19,4,33,115,123,77,35,0,(char)-116,(char)-48,
        96,(char)-97,(char)-49,(char)-73,97,(char)-37,(char)-78,5,(char)-20,(char)-52,106,(char)-40,29,52,(char)-61,(char)-101,24,80,(char)-102,4,70,1,1,2,120,109,(char)-23,(char)-30,1,15,120,(char)-64,
        3,30,(char)-16,(char)-77,(char)-63,(char)-67,65,125,81,60,104,91,24,(char)-42,(char)-87,(char)-121,(char)-66,(char)-98,(char)-114,(char)-79,1,94,61,10,100,(char)-50,48,121,23,(char)-46,(char)-26,
        (char)-83,93,(char)-43,(char)-29,(char)-127,14,25,40,3,30,(char)-62,47,(char)-51,87,(char)-31,91,(char)-45,(char)-57,(char)-50,(char)-108,45,40,54,(char)-123,20,(char)-25,(char)-18,(char)-102,70,
        0,72,83,6,(char)-70,55,(char)-109,(char)-40,(char)-103,0,(char)-40,(char)-102,(char)-31,58,(char)-51,(char)-74,85,29,89,(char)-118,(char)-77,95,85,(char)-113,(char)-26,57,(char)-72,(char)-83,(char)-2,
        (char)-84,(char)-126,70,25,118,(char)-10,(char)-106,(char)-39,123,(char)-10,(char)-69,(char)-11,(char)-63,26,(char)-6,33,25,(char)-74,45,(char)-71,(char)-70,33,4,30,(char)-39,80,103,(char)-40,7,
        (char)-99,66,(char)-81,(char)-53,(char)-79,(char)-58,76,(char)-106,52,(char)-34,(char)-66,(char)-57,(char)-104,(char)-92,(char)-89,126,18,(char)-36,39,(char)-40,(char)-109,62,118,(char)-28,81,80,
        6,(char)-83,109,(char)-96,(char)-70,(char)-103,51,58,(char)-115,0,48,(char)-72,(char)-35,(char)-7,(char)-120,(char)-17,119,37,9,60,(char)-69,45,6,(char)-39,95,19,(char)-115,(char)-68,93,(char)-103,
        96,(char)-93,37,47,(char)-38,(char)-124,(char)-35,7,3,(char)-58,16,63,82,0,104,86,(char)-3,(char)-30,(char)-85,(char)-49,(char)-94,85,(char)-89,(char)-84,30,74,(char)-122,47,100,(char)-68,(char)-115,
        (char)-19,(char)-11,8,(char)-108,1,(char)-33,(char)-125,12,(char)-56,(char)-12,(char)-89,61,24,(char)-69,12,64,14,116,0,15,120,(char)-6,120,84,27,60,121,86,(char)-2,(char)-10,29,59,118,60,(char)-102,
        (char)-14,115,(char)-127,45,(char)-128,77,(char)-61,30,(char)-72,(char)-26,(char)-22,115,26,1,96,25,(char)-126,(char)-88,(char)-35,(char)-98,40,120,50,81,(char)-4,(char)-76,9,14,7,109,(char)-94,
        37,71,11,(char)-91,(char)-105,23,73,(char)-19,(char)-117,(char)-96,(char)-76,111,(char)-17,(char)-44,25,(char)-120,78,(char)-43,(char)-9,84,95,125,25,79,23,(char)-16,(char)-22,11,(char)-109,100,
        116,122,(char)-108,46,25,30,5,109,1,79,14,120,50,48,70,1,27,7,(char)-74,(char)-79,87,0,(char)-108,30,93,(char)-96,11,(char)-8,66,(char)-89,(char)-77,63,(char)-19,(char)-97,(char)-35,(char)-71,115,
        (char)-25,99,(char)-111,61,(char)-101,122,(char)-50,103,83,72,113,(char)-18,(char)-82,105,4,(char)-128,(char)-47,(char)-39,2,4,64,(char)-74,(char)-79,(char)-25,(char)-98,(char)-56,36,124,23,(char)-32,
        (char)-91,(char)-112,(char)-70,49,(char)-54,0,69,(char)-93,(char)-41,(char)-10,(char)-53,(char)-79,66,(char)-104,124,27,(char)-42,(char)-74,(char)-114,24,100,(char)-60,(char)-80,(char)-91,(char)-101,
        (char)-86,(char)-15,(char)-91,(char)-99,66,81,(char)-4,36,84,125,(char)-47,73,58,(char)-67,(char)-52,(char)-67,(char)-122,(char)-70,100,(char)-91,(char)-125,(char)-17,(char)-21,(char)-107,(char)-115,
        17,(char)-56,5,48,93,(char)-68,(char)-70,2,(char)-39,108,40,(char)-35,28,0,(char)-97,126,(char)-26,(char)-103,103,30,(char)-49,(char)-68,5,(char)-128,12,48,(char)-25,(char)-50,55,(char)-122,105,
        6,(char)-128,65,111,(char)-49,68,30,(char)-37,(char)-70,117,(char)-21,119,115,(char)-77,118,14,48,(char)-63,66,100,7,93,101,32,(char)-11,85,17,3,(char)-76,(char)-96,72,38,57,100,22,(char)-88,(char)-74,
        (char)-43,(char)-82,(char)-54,40,25,90,80,(char)-18,(char)-17,65,78,(char)-42,(char)-125,108,8,(char)-85,(char)-69,(char)-41,(char)-63,(char)-45,65,65,61,(char)-25,27,(char)-85,(char)-12,(char)-97,
        103,(char)-8,54,118,58,(char)-77,(char)-35,(char)-113,28,(char)-76,71,(char)-23,6,123,51,(char)-17,109,(char)-55,124,(char)-50,79,2,96,79,(char)-22,29,4,67,(char)-26,(char)-10,(char)-102,86,0,(char)-120,
        86,(char)-125,126,54,1,(char)-16,120,(char)-16,88,38,(char)-77,45,19,59,(char)-28,(char)-24,(char)-85,(char)-66,40,(char)-125,38,13,(char)-74,(char)-65,(char)-72,(char)-63,(char)-89,(char)-113,(char)-106,
        5,(char)-16,116,24,(char)-84,58,84,(char)-122,42,(char)-85,43,(char)-108,(char)-84,104,(char)-23,(char)-87,47,(char)-39,(char)-117,81,(char)-70,14,(char)-121,(char)-128,31,(char)-22,115,60,24,(char)-93,
        122,7,88,(char)-76,80,(char)-9,28,(char)-74,(char)-21,(char)-27,120,(char)-120,(char)-13,119,62,(char)-15,(char)-60,19,119,37,125,62,30,(char)-3,10,0,54,77,113,110,(char)-81,105,7,(char)-64,(char)-114,
        24,96,(char)-37,(char)-106,45,91,(char)-18,(char)-114,97,(char)-98,(char)-53,(char)-28,(char)-10,6,(char)-29,25,(char)-92,(char)-82,(char)-83,(char)-112,18,40,(char)-29,81,(char)-58,(char)-12,23,
        (char)-64,123,(char)-10,(char)-20,25,(char)-83,91,(char)-73,(char)-82,(char)-99,(char)-92,(char)-45,71,(char)-5,119,126,(char)-44,(char)-23,7,(char)-24,(char)-93,(char)-38,(char)-12,32,(char)-81,
        114,(char)-15,40,(char)-35,(char)-94,(char)-59,43,31,10,(char)-6,(char)-87,(char)-6,106,83,50,(char)-27,125,(char)-5,(char)-10,(char)-75,(char)-64,52,(char)-66,4,123,(char)-37,(char)-5,43,0,(char)-86,
        93,79,(char)-75,(char)-127,(char)-110,(char)-11,124,100,(char)-74,(char)-54,(char)-25,115,0,124,48,(char)-4,(char)-45,(char)-63,(char)-50,(char)-64,98,58,(char)-94,2,32,99,30,57,7,(char)-20,(char)-116,
        3,(char)-73,38,(char)-110,31,(char)-50,126,118,87,(char)-124,7,77,(char)-62,(char)-60,33,(char)-14,(char)-125,2,65,10,(char)-51,(char)-74,(char)-47,12,(char)-71,114,(char)-27,(char)-54,70,87,(char)-84,
        88,(char)-47,50,1,35,67,5,(char)-127,(char)-74,61,(char)-12,7,100,40,(char)-32,39,(char)-95,(char)-100,56,(char)-87,110,40,(char)-21,117,57,(char)-68,(char)-17,87,57,(char)-13,108,(char)-29,(char)-85,
        (char)-44,(char)-113,(char)-22,(char)-93,(char)-41,83,(char)-122,(char)-66,(char)-81,(char)-98,87,(char)-105,(char)-66,118,61,(char)-3,(char)-12,(char)-45,(char)-73,39,(char)-13,9,(char)-128,(char)-89,
        34,(char)-13,20,32,0,(char)-62,(char)-50,(char)-3,53,(char)-83,12,96,(char)-92,(char)-10,44,(char)-89,(char)-41,103,(char)-98,122,(char)-22,(char)-87,123,(char)-73,111,(char)-33,126,95,2,(char)-31,
        73,6,(char)-55,36,(char)-43,(char)-113,81,70,64,57,63,(char)-49,(char)-114,109,(char)-59,47,95,(char)-66,124,100,37,73,(char)-69,(char)-34,(char)-88,(char)-99,124,(char)-14,(char)-55,45,3,48,(char)-74,
        0,(char)-48,15,(char)-116,59,(char)-22,24,125,117,(char)-59,(char)-15,99,100,(char)-55,81,99,65,123,(char)-67,73,60,61,(char)-14,(char)-94,(char)-38,(char)-128,(char)-78,(char)-5,27,(char)-113,113,
        103,126,(char)-19,47,(char)-105,(char)-20,(char)-3,(char)-12,11,116,64,89,27,(char)-76,111,95,50,(char)-14,96,111,(char)-126,(char)-1,(char)-5,(char)-23,(char)-21,(char)-31,(char)-16,(char)-11,14,
        (char)-128,45,83,(char)-100,(char)-5,107,(char)-102,1,96,(char)-75,11,0,123,(char)-40,(char)-106,(char)-20,105,119,(char)-60,8,82,(char)-38,(char)-98,(char)-102,124,77,(char)-121,1,(char)-128,83,
        51,(char)-15,17,112,(char)-68,0,(char)-96,11,30,(char)-89,78,60,(char)-15,(char)-60,22,16,(char)-46,44,(char)-125,(char)-45,(char)-41,78,63,40,(char)-48,(char)-123,(char)-98,87,79,6,67,(char)-98,
        30,(char)-39,16,(char)-67,(char)-82,58,122,100,5,(char)-27,(char)-52,(char)-89,29,76,(char)-115,(char)-59,(char)-104,(char)-115,79,(char)-112,(char)-46,47,(char)-48,(char)-61,87,70,16,(char)-52,
        (char)-6,32,43,84,57,(char)-70,123,(char)-78,80,(char)-18,77,6,(char)-72,59,125,62,(char)-110,122,(char)-81,(char)-127,(char)-39,48,(char)-20,(char)-127,107,(char)-82,63,(char)-89,25,0,(char)-58,
        42,114,(char)-73,(char)-121,121,50,123,(char)-38,125,15,60,(char)-16,(char)-64,45,(char)-103,100,123,26,(char)-120,(char)-20,5,87,38,62,(char)-54,86,49,(char)-110,(char)-18,25,(char)-109,66,(char)-12,
        (char)-111,6,65,112,(char)-54,41,(char)-2,96,118,(char)-44,(char)-126,(char)-124,(char)-47,(char)-83,62,(char)-114,40,(char)-67,(char)-94,26,(char)-32,1,95,80,6,109,74,(char)-42,83,(char)-50,0,58,
        37,87,46,(char)-98,28,4,31,(char)-60,81,45,43,(char)-55,80,86,126,57,(char)-70,(char)-12,(char)-75,(char)-123,42,107,91,60,57,84,57,116,(char)-1,99,(char)-113,61,(char)-10,(char)-35,109,(char)-37,
        (char)-74,125,63,(char)-68,39,0,1,48,(char)-75,(char)-12,(char)-97,123,(char)-116,(char)-90,29,0,(char)-50,1,38,(char)-80,45,(char)-50,(char)-70,63,(char)-87,(char)-19,(char)-26,56,(char)-7,(char)-98,
        (char)-34,8,120,(char)-122,(char)-52,65,(char)-79,(char)-19,(char)-95,(char)-89,(char)-99,118,90,(char)-5,(char)-73,(char)-4,106,(char)-91,(char)-108,(char)-127,(char)-24,25,48,3,59,23,112,124,(char)-6,
        108,(char)-127,32,35,(char)-24,(char)-125,83,(char)-95,116,(char)-23,15,81,(char)-3,13,(char)-27,(char)-77,(char)-75,33,7,(char)-6,40,(char)-72,(char)-73,115,72,(char)-10,(char)-23,118,127,65,32,
        96,5,0,(char)-67,33,(char)-22,(char)-98,69,(char)-11,81,58,(char)-8,25,(char)-20,(char)-53,34,121,40,(char)-50,(char)-65,35,(char)-3,(char)-39,(char)-1,(char)-91,127,(char)-113,(char)-46,50,105,
        (char)-87,(char)-49,57,(char)-99,118,0,24,(char)-68,23,66,109,27,(char)-56,4,(char)-17,53,(char)-63,24,111,(char)-69,73,(char)-101,13,(char)-57,109,(char)-33,(char)-66,(char)-67,29,2,(char)-83,110,
        (char)-85,(char)-100,(char)-13,(char)-43,(char)-47,1,124,25,(char)-113,62,39,43,115,(char)-124,32,16,0,(char)-23,(char)-77,(char)-19,(char)-13,116,65,59,(char)-64,15,(char)-95,109,97,88,(char)-89,
        60,(char)-87,29,25,(char)-72,103,28,(char)-44,28,(char)-17,(char)-34,100,(char)-89,(char)-98,122,106,(char)-5,(char)-89,(char)-23,(char)-76,29,66,(char)-67,(char)-15,(char)-94,48,(char)-84,(char)-81,
        114,(char)-58,(char)-77,(char)-1,(char)-111,71,30,(char)-71,41,91,(char)-27,(char)-19,(char)-111,(char)-7,55,(char)-17,(char)-40,(char)-116,(char)-19,(char)-40,48,(char)-94,(char)-23,92,(char)-45,
        14,0,(char)-93,(char)-106,5,(char)-92,(char)-78,45,49,(char)-40,3,(char)-103,(char)-32,(char)-83,(char)-95,15,102,(char)-62,(char)-51,97,(char)-116,(char)-55,(char)-87,(char)-34,(char)-102,89,65,
        (char)-28,26,49,22,20,(char)-49,(char)-16,9,(char)-96,(char)-111,3,98,(char)-6,104,6,(char)-73,85,56,43,88,(char)-119,(char)-126,0,4,2,48,122,(char)-75,(char)-43,15,(char)-24,27,(char)-16,(char)-96,
        (char)-66,64,(char)-114,47,(char)-71,50,40,(char)-21,(char)-53,24,(char)-115,(char)-63,61,50,(char)-2,22,0,(char)-46,(char)-2,(char)-22,(char)-43,(char)-85,(char)-37,(char)-63,79,91,(char)-96,(char)-113,
        (char)-126,(char)-10,(char)-128,(char)-97,13,51,(char)-11,123,51,(char)-81,7,(char)-77,(char)-3,125,47,(char)-9,(char)-71,63,(char)-70,78,(char)-1,108,54,85,(char)-25,(char)-25,62,83,(char)-33,2,
        (char)-36,(char)-61,36,108,3,82,(char)-38,67,(char)-113,62,(char)-6,(char)-24,77,(char)-10,(char)-71,24,(char)-14,41,(char)-122,(char)-76,(char)-6,57,81,10,(char)-75,(char)-14,25,(char)-92,55,34,
        (char)-29,115,112,(char)-98,36,(char)-38,(char)-65,2,42,96,108,19,(char)-78,(char)-123,3,(char)-105,32,(char)-16,(char)-70,56,(char)-122,107,(char)-1,24,(char)-76,62,(char)-23,112,22,104,(char)-33,
        6,(char)-111,111,10,(char)-5,126,(char)-55,38,(char)-127,78,65,(char)-97,32,(char)-96,50,(char)-34,118,127,99,113,15,(char)-9,52,6,91,(char)-110,49,(char)-21,75,59,116,(char)-120,(char)-86,71,97,
        80,(char)-97,102,(char)-5,119,61,(char)-12,(char)-48,67,(char)-41,39,(char)-80,(char)-65,(char)-109,58,47,127,(char)-40,106,(char)-22,(char)-85,63,(char)-9,(char)-102,(char)-105,0,112,31,1,(char)-32,
        (char)-123,(char)-58,(char)-45,73,(char)-15,15,127,(char)-1,(char)-5,(char)-33,(char)-1,122,28,26,(char)-33,111,(char)-33,(char)-57,(char)-119,117,(char)-38,(char)-89,88,40,(char)-61,71,(char)-81,
        (char)-3,51,108,105,(char)-41,(char)-2,69,48,(char)-23,(char)-106,(char)-66,96,(char)-95,(char)-117,10,2,(char)-50,16,72,(char)-100,(char)-59,73,(char)-64,105,(char)-54,32,16,4,(char)-124,126,(char)-15,
        (char)-79,122,(char)-53,64,120,80,(char)-82,58,84,16,1,103,(char)-21,75,(char)-10,(char)-47,31,(char)-67,53,107,(char)-42,(char)-76,12,36,3,(char)-72,(char)-65,113,(char)-112,(char)-93,61,(char)-56,
        122,(char)-121,43,67,(char)-81,(char)-109,49,61,(char)-105,115,(char)-47,(char)-83,(char)-63,77,(char)-71,(char)-33,(char)-67,(char)-87,(char)-37,18,(char)-52,(char)-53,(char)-22,(char)-49,125,(char)-26,
        45,0,(char)-36,(char)-53,(char)-127,70,100,63,(char)-65,126,(char)-3,(char)-6,77,49,(char)-14,(char)-46,56,(char)-50,(char)-33,(char)-65,(char)-75,103,126,(char)-122,98,28,96,116,6,(char)-49,(char)-95,
        (char)-79,(char)-67,97,99,112,43,78,(char)-80,48,56,29,(char)-48,105,(char)-75,(char)-77,(char)-123,(char)-92,(char)-65,(char)-26,24,(char)-85,(char)-110,(char)-45,(char)-53,113,(char)-6,(char)-125,
        24,(char)-72,(char)-99,(char)-40,99,(char)-12,118,(char)-32,(char)-92,83,80,(char)-121,(char)-25,100,(char)-70,(char)-43,54,(char)-87,121,68,(char)-90,79,91,(char)-108,(char)-20,(char)-125,42,(char)-69,
        (char)-1,108,(char)-88,113,(char)-43,56,39,(char)-23,37,(char)-16,124,(char)-25,(char)-65,(char)-43,(char)-22,(char)-49,91,(char)-49,(char)-101,(char)-94,(char)-29,(char)-21,(char)-33,109,(char)-95,
        (char)-13,(char)-78,(char)-6,115,(char)-97,121,13,(char)-128,81,78,(char)-17,(char)-89,(char)-98,125,(char)-10,(char)-39,111,(char)-118,17,95,(char)-69,106,(char)-43,(char)-86,51,(char)-83,(char)-96,
        50,100,(char)-116,(char)-47,(char)-98,(char)-87,(char)-77,15,(char)-114,83,45,(char)-89,71,(char)-73,61,(char)-5,(char)-53,0,(char)-116,9,6,(char)-50,(char)-64,40,(char)-32,11,(char)-78,(char)-125,
        64,(char)-48,86,(char)-1,(char)-12,57,(char)-76,(char)-6,21,88,5,(char)-50,(char)-27,104,(char)-11,100,(char)-8,(char)-110,113,(char)-70,(char)-74,(char)-78,(char)-118,125,94,(char)-122,(char)-47,
        (char)-81,(char)-5,(char)-72,39,(char)-88,7,(char)-4,16,(char)-26,67,(char)-73,71,(char)-23,84,(char)-101,4,29,(char)-25,127,45,89,(char)-18,(char)-58,44,(char)-120,31,(char)-92,(char)-34,(char)-34,
        (char)-17,(char)-51,95,(char)-40,(char)-125,(char)-81,105,(char)-107,(char)-26,(char)-29,16,(char)-40,(char)-58,30,71,94,112,(char)-6,(char)-23,(char)-89,(char)-65,109,(char)-19,(char)-38,(char)-75,
        (char)-17,77,32,92,(char)-50,81,86,51,67,89,(char)-111,(char)-100,(char)-32,81,80,(char)-103,(char)-77,19,32,35,78,(char)-44,(char)-72,55,34,(char)-29,41,(char)-109,67,95,46,(char)-71,(char)-96,
        (char)-46,63,(char)-121,1,(char)-25,1,121,12,(char)-35,(char)-78,(char)-118,(char)-43,14,113,66,59,59,(char)-72,47,8,26,43,(char)-68,(char)-100,(char)-98,(char)-79,(char)-74,67,30,121,(char)-11,
        95,(char)-9,(char)-83,123,(char)-93,61,(char)-44,31,10,(char)-6,(char)-55,(char)-67,(char)-73,(char)-58,(char)-15,(char)-73,(char)-27,(char)-28,(char)-1,(char)-73,73,(char)-1,(char)-33,(char)-117,
        (char)-2,19,(char)-63,(char)-10,(char)-64,118,(char)-23,(char)-36,20,118,(char)-6,(char)-41,124,4,(char)-64,(char)-78,124,(char)-103,115,126,28,(char)-1,(char)-77,113,(char)-58,(char)-65,(char)-119,
        35,54,115,(char)-114,(char)-87,113,(char)-68,85,(char)-105,(char)-43,(char)-7,124,(char)-80,87,(char)-118,(char)-25,116,96,112,58,12,(char)-53,49,120,96,60,(char)-76,7,29,101,(char)-76,(char)-22,
        81,1,(char)-90,31,(char)-9,(char)-45,119,(char)-18,63,42,(char)-57,102,60,50,82,3,94,(char)-67,(char)-96,(char)-53,(char)-8,70,32,8,(char)-75,(char)-43,(char)-81,(char)-66,(char)-48,(char)-22,95,
        25,(char)-12,79,14,(char)-54,61,(char)-59,(char)-45,(char)-17,65,6,(char)-111,(char)-19,(char)-50,(char)-29,(char)-16,(char)-67,(char)-9,(char)-35,119,(char)-33,117,(char)-95,(char)-73,68,(char)-10,
        64,96,123,(char)-100,(char)-73,(char)-44,(char)-97,(char)-5,(char)-75,107,(char)-38,1,(char)-80,44,(char)-5,(char)-3,(char)-102,24,(char)-3,(char)-38,(char)-100,(char)-14,(char)-1,101,28,112,118,
        86,(char)-105,(char)-65,117,107,(char)-5,106,78,(char)-127,(char)-49,102,(char)-17,(char)-5,(char)-10,(char)-61,15,63,124,125,(char)-100,(char)-76,37,(char)-5,(char)-8,46,70,47,(char)-61,50,42,24,
        (char)-87,32,(char)-128,24,(char)-81,(char)-3,64,(char)-124,108,(char)-120,(char)-46,(char)-99,77,(char)-82,95,(char)-114,(char)-51,125,(char)-38,(char)-71,3,(char)-107,(char)-30,(char)-117,(char)-86,
        (char)-105,37,(char)-76,(char)-41,23,(char)-32,(char)-121,48,6,(char)-78,(char)-94,(char)-91,(char)-121,14,65,111,(char)-120,(char)-100,(char)-10,(char)-65,(char)-105,(char)-1,62,19,(char)-25,127,
        103,(char)-17,(char)-34,(char)-67,14,126,82,(char)-65,67,(char)-78,55,(char)-89,67,(char)-11,(char)-87,(char)-106,(char)-89,29,0,43,99,(char)-32,(char)-33,(char)-56,(char)-118,126,95,(char)-126,
        96,67,(char)-100,(char)-69,60,19,(char)-34,(char)-101,(char)-119,(char)-17,72,(char)-6,(char)-5,118,14,121,(char)-65,(char)-97,3,(char)-48,31,(char)-34,127,(char)-1,(char)-3,31,(char)-70,(char)-21,
        (char)-82,(char)-69,62,(char)-103,125,(char)-9,(char)-2,24,(char)-75,(char)-3,126,(char)-112,51,(char)-52,60,(char)-27,(char)-10,(char)-110,(char)-88,12,75,6,(char)-54,(char)-109,40,(char)-39,16,
        125,31,125,93,(char)-11,81,(char)-78,73,(char)-27,(char)-95,76,95,(char)-67,126,95,38,87,6,(char)-4,16,(char)-111,(char)-17,(char)-49,(char)-68,111,77,(char)-64,95,(char)-105,(char)-52,119,115,(char)-74,
        (char)-97,(char)-69,(char)-93,(char)-29,(char)-32,(char)-25,(char)-44,63,(char)-43,119,(char)-2,(char)-71,(char)-49,(char)-60,107,106,1,(char)-112,(char)-107,(char)-66,(char)-31,(char)-4,(char)-13,
        (char)-49,(char)-1,87,121,108,(char)-69,54,(char)-5,(char)-24,(char)-107,49,(char)-28,113,(char)-39,(char)-25,(char)-97,(char)-50,62,127,111,28,(char)-1,(char)-47,(char)-32,63,62,(char)-8,(char)-32,
        (char)-125,127,(char)-112,12,(char)-16,(char)-87,4,(char)-59,45,49,(char)-54,(char)-105,(char)-109,18,(char)-65,20,3,(char)-35,22,67,53,(char)-89,27,113,(char)-38,33,13,120,80,(char)-96,(char)-125,
        22,(char)-108,(char)-95,(char)-54,(char)-77,(char)-47,106,(char)-81,(char)-66,(char)-25,(char)-107,127,92,28,(char)-22,126,(char)-61,(char)-66,(char)-109,(char)-67,118,(char)-27,(char)-96,121,119,
        (char)-26,(char)-4,(char)-115,124,39,(char)-14,55,113,(char)-66,(char)-81,(char)-57,125,(char)-29,(char)-25,(char)-115,(char)-33,97,113,(char)-66,(char)-7,78,37,0,(char)-78,(char)-121,110,(char)-52,
        105,(char)-1,23,(char)-14,(char)-8,(char)-10,(char)-98,(char)-92,(char)-2,(char)-53,51,(char)-7,(char)-3,(char)-39,(char)-29,(char)-17,(char)-116,(char)-13,(char)-65,(char)-110,(char)-43,(char)-1,
        (char)-97,66,127,(char)-9,(char)-98,123,(char)-18,(char)-7,92,100,119,100,16,(char)-98,123,(char)-83,(char)-126,59,35,(char)-5,66,(char)-78,(char)-63,(char)-105,30,127,(char)-4,(char)-15,(char)-101,
        19,20,(char)-2,(char)-80,36,(char)-43,63,(char)-68,(char)-46,(char)-49,56,(char)-3,(char)-105,(char)-127,123,39,(char)-108,(char)-84,90,(char)-12,(char)-27,(char)-46,43,74,(char)-89,120,122,5,114,
        80,(char)-82,122,101,32,3,60,(char)-32,11,(char)-54,67,(char)-88,35,75,63,(char)-69,28,(char)-6,(char)-18,(char)-68,(char)-13,(char)-50,(char)-49,(char)-35,123,(char)-17,(char)-67,95,(char)-116,
        (char)-84,(char)-100,47,(char)-11,(char)-37,(char)-9,(char)-67,45,(char)-115,120,(char)-2,(char)-81,(char)-71,14,(char)-128,37,89,(char)-15,103,102,(char)-33,(char)-1,(char)-103,28,(char)-86,126,
        43,(char)-5,(char)-23,5,(char)-69,119,(char)-17,(char)-10,(char)-117,(char)-96,(char)-65,(char)-50,105,(char)-9,35,(char)-39,(char)-13,(char)-1,109,(char)-24,95,5,(char)-73,102,(char)-86,30,119,
        (char)-100,118,(char)-19,125,(char)-66,(char)-7,(char)-78,26,(char)-18,(char)-54,91,(char)-62,(char)-81,(char)-34,113,(char)-57,29,(char)-97,78,(char)-112,(char)-36,(char)-102,45,(char)-127,60,(char)-86,
        7,46,6,(char)-75,53,(char)-96,49,(char)-22,1,(char)-31,(char)-52,39,25,22,5,60,(char)-99,66,(char)-107,(char)-47,30,67,93,117,(char)-38,(char)-12,(char)-63,70,(char)-42,(char)-93,(char)-38,(char)-108,
        (char)-116,62,84,25,85,(char)-122,(char)-16,123,115,(char)-54,(char)-65,(char)-9,(char)-6,(char)-21,(char)-81,(char)-1,(char)-93,108,119,95,74,(char)-39,(char)-119,(char)-33,92,(char)-51,(char)-51,
        (char)-54,63,108,(char)-50,(char)-49,88,(char)-26,(char)-4,61,(char)-64,(char)-78,(char)-84,(char)-8,(char)-9,(char)-25,(char)-96,(char)-11,(char)-17,98,(char)-64,(char)-107,73,(char)-7,55,37,(char)-91,
        (char)-1,78,82,(char)-34,127,77,(char)-28,(char)-1,(char)-105,31,(char)-4,(char)-32,7,119,101,(char)-43,(char)-5,(char)-94,(char)-61,(char)-67,123,60,(char)-97,(char)-126,76,(char)-16,64,82,(char)-29,
        29,(char)-39,31,111,(char)-56,106,17,4,55,(char)-91,(char)-113,(char)-57,99,72,(char)-113,70,(char)-29,109,33,(char)-70,47,(char)-72,(char)-94,(char)-45,(char)-78,67,(char)-47,82,(char)-32,44,(char)-88,
        114,81,50,40,(char)-3,(char)-98,(char)-110,23,74,31,(char)-19,117,(char)-108,(char)-23,20,45,94,121,6,(char)-5,35,(char)-37,(char)-105,109,(char)-19,91,95,(char)-1,(char)-6,(char)-41,127,47,(char)-13,
        (char)-2,70,(char)-28,50,94,57,95,(char)-32,(char)-65,(char)-88,(char)-13,(char)-45,102,(char)-86,(char)-41,92,102,(char)-128,(char)-109,(char)-49,56,(char)-29,(char)-116,(char)-1,(char)-112,19,
        (char)-11,7,(char)-29,(char)-4,61,89,(char)-67,31,75,(char)-28,(char)-1,(char)-5,56,(char)-3,(char)-61,89,(char)-51,(char)-97,(char)-49,44,56,17,(char)-62,(char)-66,(char)-32,98,8,(char)-87,(char)-48,
        15,70,(char)-18,79,16,124,47,109,(char)-65,(char)-103,45,(char)-31,51,(char)-50,6,9,(char)-126,(char)-57,(char)-14,(char)-56,(char)-72,51,14,(char)-112,49,90,(char)-29,24,(char)-9,(char)-112,1,(char)-47,
        (char)-108,38,124,(char)-92,(char)-113,22,40,(char)-86,122,94,127,(char)-78,11,(char)-88,3,50,(char)-64,15,65,(char)-82,61,121,81,60,(char)-92,(char)-68,59,(char)-40,117,(char)-13,(char)-51,55,127,
        (char)-30,(char)-106,91,110,(char)-7,(char)-29,(char)-56,110,11,124,(char)-57,(char)-17,113,(char)-49,28,101,(char)-65,(char)-120,14,(char)-1,53,39,1,(char)-112,71,(char)-72,115,(char)-50,61,(char)-9,
        (char)-36,(char)-33,(char)-50,105,(char)-1,(char)-94,56,(char)-1,7,121,(char)-52,(char)-7,(char)-83,28,(char)-14,(char)-2,115,86,(char)-3,(char)-41,(char)-30,(char)-68,(char)-5,126,(char)-60,105,
        86,16,120,25,(char)-14,112,(char)-50,0,(char)-33,75,31,(char)-33,76,(char)-38,(char)-4,(char)-4,(char)-35,119,(char)-33,(char)-3,(char)-87,(char)-84,(char)-96,91,(char)-45,119,(char)-5,97,105,(char)-11,
        23,35,23,123,16,(char)-27,28,56,72,56,83,40,121,(char)-75,(char)-19,(char)-53,37,(char)-101,81,109,(char)-127,50,(char)-108,85,(char)-35,108,52,91,94,(char)-110,(char)-34,83,119,100,(char)-43,(char)-115,
        (char)-93,57,48,0,0,4,(char)-23,73,68,65,84,(char)-1,(char)-73,(char)-84,(char)-2,79,71,(char)-49,115,(char)-66,(char)-45,(char)-2,67,(char)-31,15,(char)-53,(char)-77,126,(char)-18,59,(char)-21,
        (char)-11,(char)-110,3,32,111,(char)-8,(char)-42,(char)-25,(char)-64,(char)-25,(char)-1,1,(char)-24,(char)-105,(char)-84,(char)-41,(char)-59,89,31,(char)-56,(char)-55,(char)-2,(char)-45,(char)-39,
        (char)-53,29,(char)-20,(char)-92,(char)-10,89,111,62,(char)-95,66,16,104,35,8,108,21,119,39,19,92,(char)-97,45,(char)-28,115,(char)-23,(char)-9,127,(char)-27,75,(char)-92,(char)-49,(char)-28,85,
        (char)-19,(char)-125,113,(char)-54,(char)-34,96,(char)-4,(char)-53,34,78,(char)-124,(char)-22,47,117,(char)-51,121,85,30,(char)-46,94,23,79,(char)-65,116,18,100,45,(char)-77,12,(char)-27,85,63,27,
        77,(char)-122,(char)-38,(char)-98,32,(char)-67,(char)-35,33,(char)-10,27,(char)-33,(char)-8,(char)-58,(char)-17,103,(char)-36,95,(char)-119,(char)-82,(char)-107,(char)-17,21,47,91,120,(char)-57,
        127,(char)-40,(char)-9,(char)-4,(char)-116,(char)-23,(char)-96,(char)-21,(char)-91,6,(char)-64,(char)-79,121,(char)-50,95,22,(char)-93,61,18,(char)-89,127,49,(char)-85,(char)-11,119,(char)-45,(char)-69,
        (char)-55,114,100,(char)-40,(char)-65,(char)-9,(char)-59,80,30,(char)-113,(char)-100,11,30,74,54,(char)-72,45,95,35,127,57,25,(char)-27,83,57,27,124,60,(char)-63,(char)-16,127,118,(char)-20,(char)-40,
        113,127,(char)-18,43,(char)-43,(char)-18,(char)-31,(char)-64,30,117,87,78,(char)-20,49,(char)-108,43,107,71,7,(char)-113,2,(char)-66,(char)-28,85,38,43,(char)-112,(char)-87,15,(char)-10,100,12,(char)-69,
        (char)-110,(char)-87,110,(char)-49,(char)-29,(char)-35,(char)-105,114,120,(char)-3,(char)-53,(char)-68,(char)-32,(char)-7,(char)-97,(char)-47,(char)-69,49,(char)-80,(char)-33,123,(char)-55,99,14,
        2,(char)-102,77,(char)-58,91,88,(char)-22,23,(char)-60,(char)-11,82,3,32,25,111,(char)-9,83,121,(char)-76,(char)-5,78,(char)-14,(char)-98,73,(char)-49,(char)-27,(char)-92,(char)-68,21,(char)-77,
        87,122,84,(char)-14,3,(char)-55,123,114,54,(char)-72,41,65,(char)-10,(char)-41,(char)-55,4,(char)-97,(char)-8,(char)-18,119,(char)-65,(char)-5,(char)-89,9,(char)-124,79,(char)-25,(char)-34,119,36,
        64,(char)-98,(char)-115,35,(char)-24,50,114,91,(char)-3,(char)-99,(char)-109,(char)-58,99,34,83,(char)-120,(char)-29,(char)-102,14,(char)-98,(char)-84,64,(char)-114,39,7,60,25,(char)-66,(char)-112,
        (char)-78,(char)-20,(char)-77,39,91,(char)-37,(char)-93,121,(char)-86,(char)-71,59,1,(char)-7,(char)-65,111,(char)-65,(char)-3,(char)-10,(char)-113,103,76,127,(char)-103,32,(char)-3,(char)-65,(char)-47,
        (char)-13,(char)-83,(char)-34,61,(char)-95,82,(char)-66,85,95,(char)-29,90,112,(char)-50,(char)-49,24,95,(char)-6,83,64,38,(char)-3,108,(char)-98,(char)-37,69,(char)-72,(char)-2,(char)-26,26,(char)-116,
        (char)-26,(char)-32,(char)-88,127,91,(char)-126,67,(char)-44,93,(char)-119,(char)-70,111,(char)-25,(char)-66,(char)-97,(char)-49,33,(char)-15,83,49,(char)-2,(char)-1,(char)-120,(char)-15,63,(char)-111,
        12,(char)-12,(char)-1,(char)-110,(char)-122,(char)-73,(char)-92,(char)-50,62,43,43,104,11,(char)-51,(char)-39,113,(char)-36,120,108,67,62,(char)-63,(char)-45,126,27,64,94,(char)-96,(char)-116,(char)-97,
        (char)-95,81,(char)-39,(char)-73,39,1,(char)-24,87,77,(char)-113,(char)-26,49,(char)-10,(char)-21,(char)-39,(char)-106,62,127,(char)-21,(char)-83,(char)-73,(char)-2,73,86,(char)-66,(char)-89,(char)-107,
        (char)-21,18,16,(char)-33,(char)-114,(char)-82,(char)-97,115,113,124,(char)-1,(char)-59,78,11,(char)-54,(char)-44,45,(char)-56,(char)-21,(char)-91,102,(char)-128,(char)-7,(char)-104,20,39,(char)-126,
        (char)-77,(char)-127,19,(char)-12,99,(char)-71,105,11,(char)-124,56,(char)-28,(char)-122,28,56,(char)-65,(char)-32,(char)-80,(char)-107,64,(char)-8,(char)-13,(char)-101,110,(char)-70,(char)-23,(char)-65,
        39,24,62,21,(char)-39,(char)-33,38,35,(char)-35,(char)-106,(char)-57,(char)-55,7,19,20,91,(char)-29,72,91,(char)-54,(char)-2,120,(char)-47,(char)-22,(char)-35,(char)-101,(char)-107,(char)-83,63,
        72,87,(char)-19,(char)-38,(char)-97,(char)-45,(char)-65,(char)-78,(char)-65,(char)-54,(char)-119,(char)-6,(char)-2,93,(char)-55,42,(char)-49,69,63,93,(char)-20,124,36,(char)-9,121,34,1,(char)-9,
        (char)-75,100,(char)-97,47,38,(char)-13,(char)-4,113,50,(char)-49,39,(char)-109,(char)-18,63,(char)-111,(char)-89,27,(char)-114,(char)-1,(char)-69,(char)-12,112,103,(char)-32,(char)-80,107,(char)-5,
        19,(char)-128,86,(char)-67,(char)-2,32,85,11,(char)-9,58,18,2,(char)-96,(char)-84,(char)-57,(char)-104,86,(char)-109,64,(char)-80,45,(char)-8,(char)-23,(char)-108,95,(char)-49,(char)-6,13,(char)-3,
        (char)-115,(char)-39,10,(char)-2,38,78,(char)-6,108,(char)-78,(char)-62,39,(char)-14,(char)-8,(char)-11,(char)-31,(char)-32,35,9,(char)-118,63,75,64,124,58,(char)-85,(char)-43,(char)-7,(char)-28,
        (char)-85,(char)-126,34,103,(char)-121,123,(char)-94,123,71,14,(char)-109,(char)-9,(char)-122,(char)-65,63,120,48,89,(char)-29,(char)-55,28,(char)-32,(char)-18,12,(char)-18,72,38,(char)-7,(char)-69,
        60,122,126,51,(char)-121,(char)-71,(char)-49,(char)-90,(char)-3,95,(char)-60,(char)-47,127,126,(char)-61,13,55,(char)-4,78,(char)-8,(char)-113,5,127,(char)-106,(char)-32,(char)-6,92,(char)-6,(char)-7,
        74,6,(char)-27,116,95,(char)-114,(char)-73,(char)-30,5,(char)-89,71,89,25,43,(char)-43,47,(char)-19,(char)-102,(char)-81,(char)-42,71,82,0,(char)-108,77,(char)-6,64,(char)-80,(char)-38,108,13,(char)-50,
        8,14,92,82,(char)-16,(char)-51,73,(char)-57,(char)-33,(char)-118,51,(char)-65,(char)-102,39,(char)-111,(char)-49,(char)-26,61,(char)-60,39,111,(char)-69,(char)-19,(char)-74,63,(char)-54,(char)-31,
        (char)-20,(char)-93,9,(char)-118,63,(char)-72,(char)-15,(char)-58,27,63,20,71,(char)-2,73,(char)-100,(char)-6,(char)-95,(char)-108,63,(char)-102,(char)-84,(char)-15,(char)-31,(char)-56,126,47,(char)-78,
        (char)-113,(char)-91,(char)-4,(char)-121,113,(char)-8,(char)-97,38,(char)-75,127,36,95,78,125,60,(char)-63,(char)-12,23,73,(char)-15,127,(char)-107,67,(char)-34,(char)-105,18,40,(char)-33,74,86,
        (char)-72,41,25,(char)-59,95,58,(char)-37,(char)-29,(char)-67,(char)-48,113,(char)-17,29,25,(char)-104,21,(char)-17,(char)-52,98,108,41,30,57,(char)-41,(char)-111,24,0,101,93,(char)-58,(char)-106,
        17,(char)-84,58,79,12,(char)-37,82,(char)-31,(char)-60,45,13,75,(char)-57,119,114,86,(char)-100,(char)-26,43,(char)-41,27,5,69,14,109,95,(char)-51,(char)-29,(char)-39,(char)-105,115,102,(char)-7,
        66,2,(char)-28,(char)-70,(char)-84,(char)-10,(char)-49,38,(char)-115,127,(char)-42,(char)-86,78,(char)-80,124,62,117,95,(char)-55,(char)-22,(char)-66,46,25,(char)-31,(char)-101,73,(char)-5,55,(char)-92,
        (char)-65,(char)-101,3,65,101,(char)-91,(char)-9,78,119,38,(char)-31,120,(char)-9,62,34,29,(char)-97,121,(char)-75,(char)-21,72,14,(char)-128,54,(char)-127,(char)-18,(char)-125,35,108,15,28,35,51,
        8,8,(char)-87,89,118,112,48,19,20,(char)-78,(char)-124,47,98,56,20,56,87,25,(char)-11,(char)-40,(char)-26,109,29,71,59,99,(char)-40,94,(char)-76,(char)-77,(char)-43,8,44,65,(char)-26,(char)-11,45,
        (char)-89,75,(char)-13,2,(char)-80,(char)-69,(char)-3,(char)-111,(char)-55,(char)-66,(char)-100,2,(char)-96,60,(char)-64,49,50,(char)-125,(char)-125,31,103,1,(char)-25,9,10,(char)-80,87,3,(char)-89,
        22,124,49,67,(char)-26,108,33,112,(char)-84,112,109,(char)-76,5,(char)-63,(char)-91,79,125,(char)-41,125,94,22,(char)-12,(char)-27,24,0,67,(char)-57,112,90,(char)-127,35,(char)-63,10,46,8,(char)-108,
        (char)-30,(char)-43,113,52,84,(char)-101,97,127,47,(char)-85,(char)-14,(char)-47,16,0,47,43,(char)-121,(char)-51,(char)-11,100,22,3,96,(char)-82,45,122,(char)-124,(char)-11,(char)-73,24,0,11,(char)-52,
        97,(char)-13,61,(char)-100,(char)-59,0,(char)-104,111,(char)-117,47,(char)-80,(char)-5,45,6,(char)-64,2,115,(char)-56,124,15,103,49,0,(char)-26,(char)-37,(char)-30,11,(char)-20,126,(char)-117,1,
        (char)-80,(char)-64,28,50,(char)-33,(char)-61,89,12,(char)-128,(char)-7,(char)-74,(char)-8,2,(char)-69,(char)-33,98,0,44,48,(char)-121,(char)-52,(char)-9,112,22,3,96,(char)-66,45,(char)-66,(char)-64,
        (char)-18,(char)-73,24,0,11,(char)-60,33,(char)-121,107,24,(char)-117,1,112,(char)-72,44,(char)-65,64,(char)-18,(char)-69,24,0,11,(char)-60,17,(char)-121,107,24,(char)-117,1,112,(char)-72,44,(char)-65,
        64,(char)-18,(char)-69,24,0,11,(char)-60,17,(char)-121,107,24,(char)-117,1,112,(char)-72,44,(char)-65,64,(char)-18,(char)-69,24,0,11,(char)-60,17,(char)-121,107,24,(char)-117,1,112,(char)-72,44,
        (char)-65,64,(char)-18,(char)-69,24,0,(char)-121,(char)-39,17,(char)-121,(char)-5,(char)-10,(char)-1,31,0,0,(char)-1,(char)-1,127,88,(char)-75,(char)-123,0,0,0,6,73,68,65,84,3,0,(char)-63,109,(char)-60,
        60,(char)-72,101,(char)-44,(char)-77,0,0,0,0,73,69,78,68,(char)-82,66,96,(char)-126, 0 };

    static constexpr const char view_Sky_Blue_Bevel_png[] = {
        (char)-119,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,(char)-128,0,0,0,(char)-128,8,6,0,0,0,(char)-61,62,97,(char)-53,0,0,16,0,73,68,65,84,120,1,(char)-20,(char)-35,11,(char)-36,(char)-18,99,(char)-99,
        47,(char)-2,123,57,(char)-82,(char)-78,66,(char)-118,84,(char)-118,66,(char)-91,(char)-116,(char)-45,36,(char)-103,76,84,(char)-86,105,(char)-121,(char)-15,(char)-9,(char)-33,(char)-43,(char)-88,
        81,(char)-10,84,74,19,83,42,(char)-121,36,68,(char)-120,82,(char)-93,(char)-125,(char)-50,91,(char)-103,50,105,111,(char)-69,65,(char)-25,(char)-109,26,51,34,17,57,21,(char)-119,106,74,36,(char)-44,
        114,(char)-116,101,127,(char)-34,(char)-41,122,(char)-66,(char)-73,(char)-21,(char)-7,(char)-83,(char)-5,89,107,97,57,(char)-43,(char)-10,(char)-70,63,(char)-49,(char)-9,120,125,(char)-81,(char)-61,
        (char)-9,123,93,(char)-65,(char)-61,(char)-3,(char)-84,(char)-57,82,(char)-93,(char)-1,(char)-9,(char)-33,(char)-97,(char)-11,10,(char)-4,(char)-65,2,(char)-8,(char)-77,78,(char)-1,104,(char)-12,
        (char)-25,88,0,53,(char)-25,89,(char)-107,(char)-5,3,14,56,96,1,93,(char)-39,(char)-2,(char)-44,105,77,(char)-4,79,102,(char)-98,(char)-107,(char)-52,(char)-83,(char)-74,(char)-38,106,(char)-103,
        76,106,(char)-103,(char)-29,(char)-113,63,126,(char)-71,125,(char)-10,(char)-39,(char)-25,97,(char)-33,(char)-2,(char)-10,(char)-73,87,62,(char)-23,(char)-92,(char)-109,(char)-98,116,(char)-18,(char)-71,
        (char)-25,(char)-82,117,(char)-20,(char)-79,(char)-57,110,120,(char)-3,(char)-11,(char)-41,111,(char)-68,(char)-25,(char)-98,123,(char)-82,(char)-9,(char)-58,55,(char)-66,(char)-15,(char)-87,(char)-95,
        107,(char)-4,(char)-31,15,127,88,63,88,111,(char)-81,(char)-67,(char)-10,122,(char)-20,14,59,(char)-20,(char)-80,(char)-58,90,107,(char)-83,53,(char)-5,35,31,(char)-7,(char)-56,(char)-125,(char)-33,
        (char)-4,(char)-26,55,(char)-81,(char)-16,(char)-94,23,(char)-67,104,(char)-23,(char)-60,(char)-6,(char)-109,(char)-4,(char)-4,73,20,(char)-64,(char)-109,(char)-97,(char)-4,(char)-28,(char)-27,(char)-50,
        59,(char)-17,(char)-68,(char)-27,78,59,(char)-19,(char)-76,(char)-75,(char)-34,(char)-16,(char)-122,55,(char)-84,117,(char)-35,117,(char)-41,(char)-67,(char)-32,83,(char)-97,(char)-6,(char)-44,(char)-1,
        119,(char)-47,69,23,(char)-67,(char)-23,57,(char)-49,121,(char)-50,(char)-66,73,(char)-14,59,(char)-30,(char)-13,(char)-2,(char)-51,54,(char)-37,(char)-20,(char)-128,(char)-43,86,91,(char)-19,(char)-29,
        (char)-49,125,(char)-18,115,(char)-33,(char)-109,2,(char)-8,108,(char)-110,(char)-5,(char)-39,36,(char)-4,(char)-3,115,(char)-25,(char)-50,(char)-3,(char)-41,27,111,(char)-68,(char)-15,(char)-56,
        27,110,(char)-72,(char)-31,(char)-24,61,(char)-10,(char)-40,(char)-29,19,71,31,125,(char)-12,59,(char)-65,(char)-15,(char)-115,111,28,(char)-75,(char)-51,54,(char)-37,(char)-20,25,(char)-7,101,71,
        30,121,(char)-28,118,(char)-15,(char)-37,(char)-30,31,(char)-1,(char)-15,31,(char)-97,(char)-16,(char)-106,(char)-73,(char)-68,101,(char)-11,(char)-117,47,(char)-66,120,(char)-7,51,(char)-49,60,
        115,(char)-39,42,(char)-74,7,114,101,60,96,11,96,(char)-85,(char)-83,(char)-74,(char)-102,(char)-109,(char)-99,(char)-7,(char)-96,(char)-41,(char)-67,(char)-18,117,(char)-101,126,(char)-13,(char)-101,
        (char)-33,(char)-36,112,(char)-11,(char)-43,87,(char)-33,99,(char)-19,(char)-75,(char)-41,126,(char)-61,77,55,(char)-35,(char)-12,(char)-79,(char)-32,(char)-128,(char)-27,(char)-105,95,(char)-2,
        (char)-93,43,(char)-81,(char)-68,(char)-14,(char)-34,127,(char)-4,(char)-29,31,(char)-9,(char)-71,(char)-3,(char)-10,(char)-37,95,(char)-103,36,(char)-67,56,(char)-12,(char)-59,(char)-95,(char)-49,
        12,(char)-98,21,126,(char)-35,96,(char)-93,(char)-16,79,15,(char)-123,(char)-25,(char)-124,(char)-1,(char)-85,96,(char)-85,96,(char)-89,57,115,(char)-26,(char)-4,(char)-113,(char)-91,(char)-106,
        90,(char)-22,(char)-115,(char)-63,65,(char)-53,46,(char)-69,(char)-20,(char)-31,41,(char)-124,127,125,(char)-5,(char)-37,(char)-33,(char)-2,(char)-119,(char)-48,(char)-3,30,(char)-6,(char)-48,(char)-121,
        (char)-66,(char)-31,113,(char)-113,123,(char)-36,(char)-10,47,127,(char)-7,(char)-53,31,(char)-13,(char)-16,(char)-121,63,(char)-4,33,(char)-37,110,(char)-69,(char)-19,(char)-125,(char)-45,102,86,
        (char)-16,(char)-128,(char)-5,60,(char)-112,10,96,(char)-42,(char)-26,(char)-101,111,(char)-66,(char)-54,23,(char)-65,(char)-8,(char)-59,(char)-43,79,62,(char)-7,(char)-28,(char)-19,(char)-114,59,
        (char)-18,(char)-72,(char)-105,(char)-65,(char)-17,125,(char)-17,(char)-5,(char)-40,(char)-2,(char)-5,(char)-17,(char)-1,(char)-98,36,(char)-23,(char)-124,(char)-37,110,(char)-69,(char)-19,(char)-51,
        (char)-13,(char)-26,(char)-51,123,125,50,(char)-16,(char)-41,73,(char)-24,(char)-90,(char)-95,43,5,43,7,(char)-53,70,94,62,88,46,(char)-112,(char)-92,(char)-91,103,(char)-51,(char)-102,101,(char)-34,
        48,10,63,(char)-94,79,(char)-37,(char)-91,66,(char)-37,101,35,109,(char)-8,(char)-31,87,(char)-116,110,(char)-75,(char)-56,(char)-21,(char)-124,62,42,116,(char)-13,(char)-12,(char)-11,(char)-22,
        (char)-12,(char)-75,(char)-41,(char)-83,(char)-73,(char)-34,122,80,(char)-118,(char)-28,(char)-104,47,125,(char)-23,75,71,125,(char)-14,(char)-109,(char)-97,124,(char)-39,(char)-17,126,(char)-9,
        (char)-69,103,(char)-28,68,88,39,(char)-105,(char)-109,(char)-121,(char)-124,(char)-74,(char)-40,(char)-15,(char)-65,(char)-33,127,(char)-18,(char)-9,3,(char)-75,(char)-45,(char)-65,(char)-9,(char)-67,
        (char)-17,61,(char)-30,91,(char)-33,(char)-6,(char)-42,(char)-13,78,56,(char)-31,(char)-124,(char)-1,(char)-79,(char)-55,38,(char)-101,124,96,(char)-45,77,55,125,111,18,(char)-9,(char)-50,101,(char)-106,
        89,(char)-26,37,73,(char)-116,(char)-124,(char)-81,17,(char)-6,(char)-80,96,(char)-23,64,(char)-62,37,112,86,120,(char)-55,29,39,33,109,26,79,(char)-33,(char)-104,(char)-87,31,(char)-12,48,(char)-109,
        (char)-66,(char)-36,66,(char)-35,11,(char)-120,(char)-81,(char)-80,(char)-98,(char)-104,(char)-94,(char)-39,114,(char)-51,53,(char)-41,(char)-36,57,(char)-12,(char)-48,(char)-100,52,71,(char)-19,
        (char)-70,(char)-21,(char)-82,(char)-121,(char)-28,18,(char)-15,119,57,(char)-103,54,(char)-35,123,(char)-17,(char)-67,31,26,127,(char)-29,8,(char)-71,(char)-1,125,106,68,(char)-9,(char)-53,2,(char)-56,
        2,46,(char)-19,(char)-102,126,(char)-22,(char)-87,(char)-89,62,(char)-27,(char)-13,(char)-97,(char)-1,(char)-4,(char)-106,107,(char)-83,(char)-75,(char)-42,(char)-37,114,13,(char)-33,47,73,122,75,
        (char)-80,77,18,(char)-11,(char)-8,76,64,18,(char)-20,(char)-46,(char)-80,(char)-13,63,(char)-39,(char)-99,109,71,(char)-57,103,(char)-66,98,(char)-16,51,(char)-19,(char)-90,105,122,89,27,(char)-96,
        3,60,76,107,112,(char)-121,(char)-48,(char)-118,43,98,(char)-93,41,0,(char)-59,(char)-73,81,(char)-28,109,(char)-45,118,(char)-65,92,22,62,(char)-106,(char)-5,(char)-114,(char)-67,115,(char)-97,
        (char)-79,(char)-35,(char)-37,(char)-34,(char)-10,(char)-74,117,119,(char)-39,101,(char)-105,101,99,(char)-69,95,126,(char)-18,119,5,(char)-112,(char)-59,122,(char)-16,(char)-5,(char)-33,(char)-1,
        (char)-2,(char)-121,101,17,119,94,103,(char)-99,117,118,(char)-53,(char)-30,(char)-66,39,43,(char)-9,(char)-46,(char)-32,25,(char)-63,35,(char)-126,(char)-27,(char)-125,(char)-106,(char)-24,(char)-94,
        18,5,(char)-28,30,116,(char)-48,(char)-21,(char)-118,79,(char)-94,(char)-118,109,(char)-89,68,47,51,(char)-112,11,(char)-28,30,98,2,29,31,124,96,(char)-73,(char)-49,(char)-50,120,31,19,(char)-35,
        83,(char)-126,(char)-41,(char)-26,(char)-87,(char)-30,(char)-109,(char)-69,(char)-17,(char)-66,(char)-5,(char)-111,(char)-5,(char)-19,(char)-73,(char)-33,(char)-50,87,93,117,(char)-43,83,(char)-65,
        (char)-6,(char)-43,(char)-81,(char)-82,(char)-96,(char)-51,(char)-3,9,(char)-9,(char)-89,2,88,(char)-22,(char)-35,(char)-17,126,(char)-9,(char)-102,(char)-71,(char)-90,111,(char)-99,(char)-59,(char)-5,
        88,22,105,(char)-9,(char)-32,53,(char)-31,(char)-97,16,(char)-70,74,48,(char)-29,39,62,19,(char)-109,88,13,(char)-110,(char)-100,(char)-58,(char)-94,(char)-48,(char)-124,(char)-87,31,73,88,107,75,
        28,(char)-38,74,71,15,(char)-28,33,122,(char)-67,113,(char)-112,3,(char)-21,(char)-70,98,(char)-24,42,(char)-47,109,(char)-99,(char)-101,(char)-56,67,(char)-45,(char)-49,91,55,(char)-36,112,(char)-61,
        29,127,(char)-13,(char)-101,(char)-33,108,(char)-32,(char)-47,116,24,(char)-25,(char)-66,(char)-110,13,(char)-12,(char)-66,(char)-22,123,(char)-36,111,30,(char)-49,(char)-42,(char)-56,115,(char)-6,
        14,47,123,(char)-39,(char)-53,(char)-10,(char)-52,117,(char)-3,(char)-8,28,(char)-27,(char)-49,(char)-51,(char)-30,61,37,(char)-32,99,103,(char)-95,109,(char)-41,(char)-45,65,83,44,(char)-58,(char)-113,
        (char)-14,45,58,108,50,(char)-44,15,(char)-27,(char)-34,63,(char)-55,(char)-20,(char)-59,105,124,(char)-39,(char)-118,(char)-118,51,(char)-59,(char)-49,14,(char)-81,(char)-128,(char)-97,23,122,112,
        26,(char)-67,105,(char)-53,45,(char)-73,(char)-36,54,55,(char)-118,(char)-85,(char)-121,(char)-65,(char)-49,63,(char)-9,121,1,(char)-20,(char)-68,(char)-13,(char)-50,127,115,(char)-30,(char)-119,
        39,(char)-70,(char)-58,(char)-17,(char)-109,5,122,93,22,(char)-51,17,(char)-1,(char)-96,73,43,19,(char)-37,2,(char)-22,73,(char)-70,(char)-60,25,(char)-5,(char)-107,29,45,(char)-80,15,81,13,(char)-8,
        20,(char)-113,(char)-14,67,75,95,(char)-108,14,122,(char)-103,47,25,(char)-40,(char)-56,(char)-39,(char)-7,78,24,(char)-9,10,43,68,(char)-17,(char)-119,98,(char)-121,(char)-40,62,(char)-4,(char)-102,
        (char)-41,(char)-68,(char)-26,45,7,30,120,(char)-32,115,82,8,115,34,(char)-33,103,(char)-97,(char)-5,(char)-78,0,(char)-106,122,(char)-49,123,(char)-34,(char)-77,(char)-1,97,(char)-121,29,118,80,
        22,(char)-58,(char)-35,(char)-4,38,(char)-75,10,(char)-111,(char)-117,(char)-99,70,45,104,(char)-81,40,63,(char)-6,30,(char)-67,15,(char)-98,95,97,(char)-110,76,(char)-89,61,31,(char)-4,36,(char)-80,
        79,(char)-46,(char)-9,58,(char)-19,(char)-53,15,(char)-49,70,46,62,116,86,10,98,78,(char)-24,(char)-61,(char)-93,127,101,(char)-118,(char)-32,83,(char)-81,125,(char)-19,107,95,(char)-103,123,(char)-124,
        (char)-65,116,(char)-29,(char)-53,(char)-1,(char)-34,(char)-58,125,82,0,(char)-71,22,110,(char)-100,(char)-57,(char)-70,(char)-81,(char)-2,(char)-3,(char)-33,(char)-1,(char)-3,63,102,(char)-62,79,
        13,86,(char)-50,(char)-126,(char)-124,(char)-36,(char)-15,(char)-55,34,(char)-39,57,99,69,(char)-39,75,(char)-113,(char)-106,17,15,100,20,(char)-16,80,(char)-19,114,89,25,1,93,(char)-95,108,104,
        (char)-33,(char)-90,(char)-20,40,125,(char)-127,(char)-52,23,(char)-91,67,(char)-55,5,(char)-14,(char)-62,(char)-96,127,(char)-66,83,62,(char)-34,83,120,(char)-73,(char)-80,119,(char)-34,48,30,117,
        (char)-8,(char)-31,(char)-121,111,(char)-99,34,120,(char)-12,(char)-108,(char)-19,94,35,(char)-9,122,1,(char)-20,(char)-76,(char)-45,78,(char)-81,(char)-2,(char)-6,(char)-41,(char)-65,(char)-2,31,
        121,(char)-84,123,102,22,113,85,11,2,(char)-61,25,(char)-57,54,86,77,(char)-78,(char)-113,(char)-115,(char)-117,(char)-63,104,95,(char)-15,(char)-16,(char)-102,20,(char)-91,7,58,40,125,(char)-49,
        (char)-77,(char)-45,3,61,25,45,(char)-112,(char)-95,(char)-28,33,29,36,(char)-66,(char)-65,(char)-105,113,127,(char)-29,94,96,(char)-93,7,61,(char)-24,65,(char)-17,(char)-52,77,(char)-16,78,95,(char)-2,
        (char)-14,(char)-105,(char)-41,(char)-54,101,113,(char)-10,48,(char)-58,(char)-110,(char)-110,(char)-121,113,(char)-18,(char)-43,2,(char)-56,4,(char)-113,(char)-50,(char)-79,(char)-1,(char)-31,28,
        (char)-125,38,(char)-72,92,13,102,(char)-72,120,22,(char)-38,(char)-94,(char)-107,125,113,(char)-88,54,(char)-30,(char)-96,(char)-67,63,29,(char)-48,(char)-95,48,(char)-28,(char)-55,(char)-123,(char)-78,
        (char)-109,(char)-121,60,25,(char)-40,122,(char)-48,13,(char)-5,37,(char)-45,15,49,108,55,37,63,56,(char)-2,27,(char)-26,(char)-11,(char)-11,43,(char)-14,(char)-94,107,(char)-49,(char)-125,14,58,
        (char)-24,9,27,108,(char)-80,(char)-63,(char)-67,(char)-14,(char)-56,120,(char)-81,20,(char)-64,(char)-6,(char)-21,(char)-81,(char)-65,65,(char)-98,(char)-127,(char)-65,(char)-101,(char)-35,(char)-1,
        (char)-86,36,95,(char)-97,42,(char)-65,(char)-19,(char)-124,(char)-87,5,88,40,(char)-87,69,76,(char)-37,105,126,89,(char)-76,38,(char)-77,(char)-105,13,79,(char)-55,6,(char)-8,(char)-59,(char)-127,
        118,5,(char)-19,(char)-96,(char)-38,(char)-11,124,(char)-81,43,61,(char)-86,109,(char)-39,(char)-48,(char)-110,(char)-39,(char)-128,(char)-82,(char)-64,6,37,(char)-93,(char)-111,(char)-105,(char)-119,
        (char)-33,(char)-109,(char)-62,111,55,123,(char)-10,(char)-20,55,(char)-25,85,(char)-73,55,(char)-100,94,116,89,(char)-81,(char)-88,(char)-17,(char)-103,(char)-49,61,26,(char)-36,(char)-112,115,
        (char)-99,(char)-1,(char)-1,(char)-65,(char)-10,(char)-75,(char)-81,(char)-99,(char)-76,(char)-47,70,27,61,(char)-51,36,(char)-23,32,(char)-109,(char)-99,88,0,(char)-12,(char)-20,(char)-15,69,(char)-90,
        (char)-95,108,(char)-45,(char)-108,83,(char)-62,(char)-48,54,(char)-87,61,87,122,(char)-64,23,(char)-56,(char)-38,3,29,25,(char)-16,11,3,31,40,(char)-97,106,95,114,81,62,108,(char)-123,(char)-46,
        (char)-9,(char)-108,(char)-49,20,30,(char)-107,98,126,113,94,(char)-124,(char)-67,42,(char)-17,12,94,(char)-100,119,6,(char)-66,104,(char)-22,93,(char)-105,40,127,(char)-113,22,(char)-64,(char)-69,
        (char)-34,(char)-11,(char)-82,(char)-41,(char)-27,(char)-56,63,32,(char)-57,(char)-7,106,(char)-103,(char)-100,(char)-57,(char)-69,105,(char)-125,(char)-113,110,(char)-102,76,(char)-104,(char)-92,
        (char)-93,(char)-97,(char)-76,120,124,(char)-127,29,122,(char)-98,(char)-100,(char)-123,68,(char)-58,55,(char)-109,(char)-67,29,95,(char)-32,84,(char)-68,126,(char)-56,(char)-123,(char)-46,(char)-109,
        (char)-15,104,(char)-17,(char)-125,47,(char)-80,(char)-51,(char)-124,106,(char)-37,(char)-37,(char)-85,(char)-35,(char)-128,122,100,(char)-12,(char)-27,(char)-43,(char)-10,(char)-47,(char)-17,(char)-70,
        (char)-59,22,91,108,(char)-105,39,37,55,(char)-116,125,(char)-45,37,(char)-58,(char)-33,35,5,(char)-80,(char)-15,(char)-58,27,(char)-81,(char)-102,(char)-101,(char)-103,(char)-35,115,51,(char)-77,
        83,38,(char)-2,(char)-108,(char)-116,(char)-42,53,63,100,(char)-2,39,19,107,73,(char)-119,(char)-83,81,90,60,10,61,79,(char)-26,(char)-113,(char)-50,(char)-124,73,(char)-10,(char)-118,(char)-95,
        8,32,(char)-33,(char)-34,(char)-115,(char)-14,45,(char)-34,(char)-88,(char)-89,(char)-7,2,103,4,(char)-73,(char)-36,114,75,(char)-45,(char)-77,(char)-111,81,109,42,70,(char)-33,111,(char)-11,(char)-59,
        6,(char)-67,(char)-83,120,122,40,(char)-71,40,29,12,(char)-27,(char)-46,21,101,79,63,75,(char)-121,110,(char)-110,(char)-51,115,120,46,(char)-99,91,(char)-18,(char)-72,(char)-29,(char)-114,94,(char)-125,
        71,(char)-75,100,63,75,(char)-68,0,12,(char)-12,(char)-33,(char)-2,(char)-19,(char)-33,(char)-74,(char)-50,(char)-51,(char)-52,(char)-114,(char)-103,(char)-48,(char)-45,51,(char)-36,118,(char)-67,
        15,29,127,(char)-94,31,(char)-13,61,(char)-109,73,(char)-73,(char)-53,66,(char)-47,(char)-34,(char)-90,13,(char)-80,(char)-11,122,60,61,(char)-32,37,78,2,37,(char)-14,(char)-26,(char)-101,111,30,
        (char)-63,13,55,(char)-36,48,(char)-54,23,51,(char)-93,(char)-71,115,(char)-25,(char)-114,126,(char)-1,(char)-5,(char)-33,55,92,115,(char)-51,53,35,(char)-72,(char)-10,(char)-38,107,(char)-101,(char)-100,
        (char)-9,(char)-10,35,(char)-32,(char)-61,31,110,(char)-70,(char)-23,(char)-90,86,32,98,(char)-119,(char)-87,15,69,(char)-92,15,125,(char)-11,99,(char)-95,(char)-125,(char)-46,(char)-105,77,27,40,
        61,(char)-38,(char)-93,(char)-4,(char)-118,(char)-106,77,(char)-101,(char)-64,(char)-15,(char)-1,(char)-56,(char)-91,(char)-105,94,(char)-6,(char)-112,(char)-100,(char)-90,(char)-49,(char)-74,(char)-79,
        (char)-54,(char)-66,(char)-92,(char)-24,18,45,0,71,85,(char)-18,(char)-12,55,(char)-53,(char)-69,(char)-17,125,51,(char)-8,(char)-89,(char)-101,84,97,113,6,(char)-100,54,(char)-117,116,(char)-101,
        (char)-28,99,(char)-31,37,70,(char)-94,110,(char)-68,(char)-15,(char)-58,(char)-111,(char)-28,93,119,(char)-35,117,(char)-93,124,71,63,(char)-70,(char)-14,(char)-54,43,71,87,92,113,(char)-59,(char)-24,
        (char)-41,(char)-65,(char)-2,(char)-11,(char)-24,(char)-14,(char)-53,47,31,93,118,(char)-39,101,(char)-93,75,46,(char)-71,100,116,(char)-23,(char)-91,(char)-105,54,(char)-2,(char)-89,63,(char)-3,
        105,(char)-29,75,(char)-2,(char)-81,(char)-1,(char)-6,(char)-81,17,(char)-16,(char)-41,(char)-10,(char)-73,(char)-65,(char)-3,109,43,12,5,36,(char)-74,(char)-126,82,12,(char)-6,51,(char)-106,(char)-62,
        (char)-92,121,(char)-78,13,39,52,(char)-55,(char)-113,(char)-82,124,123,74,(char)-97,(char)-10,114,(char)-12,(char)-108,60,33,(char)-20,126,(char)-56,33,(char)-121,(char)-20,24,121,(char)-119,126,
        4,95,18,1,(char)-105,(char)-54,(char)-51,(char)-54,(char)-100,(char)-105,(char)-65,(char)-4,(char)-27,47,76,(char)-75,126,40,3,95,(char)-81,38,34,120,(char)-49,(char)-57,(char)-42,118,57,(char)-3,
        36,(char)-16,45,76,(char)-78,(char)-105,78,(char)-46,37,(char)-62,(char)-15,45,49,118,(char)-18,(char)-43,87,95,(char)-35,18,(char)-2,(char)-117,95,(char)-4,98,(char)-12,(char)-77,(char)-97,(char)-3,
        (char)-84,37,(char)-6,(char)-126,11,46,24,(char)-99,127,(char)-2,(char)-7,(char)-93,(char)-77,(char)-49,62,123,(char)-12,(char)-61,31,(char)-2,(char)-80,1,15,103,(char)-98,121,(char)-26,(char)-24,
        7,63,(char)-8,65,(char)-61,89,103,(char)-99,(char)-43,124,(char)-48,115,(char)-50,57,(char)-89,(char)-75,(char)-71,(char)-24,(char)-94,(char)-117,90,12,(char)-79,20,69,(char)-66,(char)-47,107,(char)-89,
        (char)-122,83,(char)-92,78,7,(char)-29,0,(char)-29,50,(char)-73,(char)-94,(char)-59,(char)-9,(char)-78,121,(char)-111,(char)-95,(char)-20,116,64,(char)-41,(char)-125,(char)-67,(char)-41,(char)-121,
        127,(char)-70,83,53,39,(char)-63,(char)-21,122,(char)-65,(char)-59,(char)-27,103,(char)-14,91,34,5,(char)-112,(char)-63,45,(char)-11,(char)-52,103,62,115,(char)-69,36,127,(char)-41,12,(char)-36,
        47,66,44,21,(char)-38,(char)-82,(char)-17,(char)-79,(char)-75,(char)-124,(char)-109,97,(char)-90,(char)-127,44,76,47,70,(char)-39,45,(char)-74,(char)-60,75,(char)-128,93,(char)-23,24,(char)-73,83,
        127,(char)-2,(char)-13,(char)-97,(char)-73,100,93,120,(char)-31,(char)-123,(char)-93,31,(char)-3,(char)-24,71,35,73,(char)-108,96,(char)-119,(char)-106,(char)-28,115,(char)-49,61,119,116,(char)-34,
        121,(char)-25,53,(char)-16,97,87,28,120,(char)-64,(char)-45,(char)-15,(char)-1,97,10,69,27,(char)-59,0,100,49,(char)-7,56,49,126,(char)-11,(char)-85,95,(char)-115,114,(char)-121,(char)-34,78,24,
        (char)-105,(char)-115,(char)-31,(char)-87,96,(char)-84,(char)-3,(char)-104,(char)-55,67,(char)-12,118,(char)-21,2,(char)-67,15,25,122,93,(char)-38,108,(char)-106,77,(char)-74,(char)-85,39,(char)-85,
        94,127,119,(char)-8,(char)-69,93,0,94,88,100,113,125,(char)-123,(char)-69,67,6,(char)-72,121,(char)-32,(char)-91,70,75,(char)-70,(char)-127,(char)-103,68,116,(char)-40,49,(char)-122,(char)-14,(char)-40,
        (char)-48,49,(char)-38,17,(char)-7,(char)-126,(char)-60,59,(char)-30,45,118,29,(char)-17,18,(char)-31,(char)-24,(char)-2,(char)-15,(char)-113,127,(char)-36,18,46,81,18,39,(char)-111,120,71,(char)-67,
        (char)-35,(char)-21,56,(char)-73,123,93,18,(char)-20,94,73,19,(char)-53,(char)-55,81,(char)-123,68,(char)-17,20,17,(char)-101,(char)-81,(char)-40,117,(char)-71,112,(char)-126,(char)-120,(char)-85,
        56,(char)-60,6,(char)-89,3,(char)-69,(char)-53,(char)-117,(char)-72,98,26,(char)-101,75,(char)-125,(char)-79,26,(char)-77,(char)-15,(char)-9,(char)-13,32,3,91,(char)-23,(char)-117,(char)-46,23,95,
        (char)-76,(char)-9,99,15,98,(char)-102,(char)-75,(char)-50,17,71,28,113,(char)-92,119,43,(char)-111,(char)-17,(char)-10,(char)-25,110,21,64,(char)-18,(char)-14,103,127,(char)-31,11,95,88,123,(char)-75,
        (char)-43,86,123,105,70,(char)-74,77,70,(char)-29,(char)-50,53,100,(char)-44,118,63,(char)-58,36,80,(char)-64,67,124,(char)-119,13,100,104,66,(char)-9,(char)-125,14,44,38,88,92,9,114,(char)-52,75,
        (char)-114,(char)-60,75,(char)-116,(char)-99,105,(char)-105,(char)-38,(char)-99,(char)-110,(char)-14,(char)-53,95,(char)-2,(char)-78,93,6,36,22,42,33,98,(char)-120,7,(char)-70,25,(char)-54,(char)-12,
        67,56,105,20,(char)-119,(char)-94,(char)-48,(char)-81,83,(char)-90,(char)-6,84,4,64,54,22,(char)-105,8,(char)-9,11,(char)-58,104,(char)-84,(char)-38,86,31,(char)-6,3,(char)-13,(char)-42,7,30,37,
        23,79,(char)-58,(char)-105,14,15,(char)-91,(char)-57,79,(char)-63,(char)-41,(char)-53,(char)-113,(char)-56,(char)-29,(char)-11,7,(char)-90,(char)-28,(char)-69,69,(char)-18,86,1,(char)-68,(char)-28,
        37,47,89,61,(char)-17,(char)-80,95,(char)-101,65,63,59,(char)-104,(char)-15,(char)-43,(char)-82,73,88,12,35,(char)-115,95,43,14,(char)-108,12,61,(char)-49,23,(char)-24,81,11,(char)-23,(char)-88,
        (char)-73,(char)-53,(char)-20,(char)-28,(char)-117,47,(char)-66,120,(char)-28,(char)-56,(char)-82,(char)-59,(char)-105,120,(char)-117,111,(char)-41,74,(char)-72,(char)-99,93,109,(char)-75,(char)-57,
        3,(char)-66,(char)-121,62,(char)-95,108,(char)-24,16,(char)-58,(char)-84,13,61,42,(char)-74,(char)-28,(char)-70,(char)-20,56,89,20,(char)-100,2,116,(char)-38,40,4,58,(char)-59,(char)-87,88,20,(char)-114,
        (char)-79,107,(char)-89,125,(char)-11,(char)-123,47,(char)-80,(char)-63,80,46,(char)-99,54,80,(char)-10,(char)-114,46,(char)-97,47,(char)-44,54,63,(char)-4,(char)-16,(char)-61,(char)-113,(char)-18,
        116,119,(char)-119,(char)-67,(char)-53,5,(char)-32,(char)-101,(char)-85,124,(char)-95,(char)-13,119,25,(char)-32,(char)-77,(char)-46,(char)-13,(char)-93,51,(char)-24,105,(char)-113,123,(char)-47,
        71,(char)-67,(char)-32,39,126,(char)-45,(char)-108,67,(char)-65,(char)-110,(char)-19,92,9,(char)-75,(char)-93,28,(char)-77,(char)-18,(char)-32,37,(char)-37,117,92,(char)-14,29,(char)-17,110,(char)-10,
        (char)-40,(char)-7,13,(char)-109,53,(char)-20,(char)-89,58,21,(char)-97,13,5,122,20,(char)-16,5,62,(char)-59,15,(char)-87,(char)-66,(char)-116,(char)-49,(char)-79,(char)-17,(char)-60,113,9,82,0,
        (char)-58,(char)-91,40,(char)-116,75,65,(char)-70,(char)-84,24,91,95,8,(char)-61,88,51,(char)-55,(char)-6,47,(char)-52,(char)-32,(char)-77,(char)-52,(char)-50,59,(char)-17,(char)-68,75,(char)-16,
        (char)-22,25,(char)-20,(char)-117,(char)-91,(char)-66,75,5,(char)-112,(char)-28,47,(char)-99,35,104,(char)-3,60,(char)-102,(char)-4,(char)-9,44,(char)-36,58,(char)-63,2,(char)-99,25,124,41,(char)-39,
        (char)-95,100,(char)-76,(char)-73,(char)-109,11,(char)-75,(char)-72,30,(char)-27,(char)-20,52,11,(char)-20,(char)-120,(char)-75,(char)-64,(char)-110,(char)-17,4,(char)-80,(char)-72,18,(char)-49,
        23,(char)-122,(char)-79,(char)-86,(char)-81,(char)-94,98,(char)-29,(char)-95,120,(char)-76,80,(char)-6,(char)-68,116,105,(char)-9,46,21,(char)-81,(char)-12,(char)-27,(char)-121,(char)-46,85,(char)-97,
        69,(char)-19,118,(char)-29,(char)-108,124,99,116,42,(char)-4,(char)-28,39,63,105,(char)-113,(char)-98,(char)-26,96,46,78,15,(char)-2,(char)-38,(char)-9,(char)-88,(char)-66,(char)-60,46,(char)-108,
        (char)-114,31,(char)-35,80,(char)-90,(char)-125,(char)-24,103,(char)-27,(char)-87,(char)-32,(char)-97,115,26,108,76,(char)-66,43,(char)-72,75,5,(char)-16,(char)-92,39,61,105,(char)-93,(char)-27,
        (char)-106,91,(char)-18,(char)-19,(char)-23,(char)-48,(char)-29,(char)-98,47,44,(char)-62,78,(char)-2,(char)-104,4,(char)-12,(char)-42,12,(char)-68,23,(char)-37,37,(char)-127,(char)-126,(char)-34,
        66,(char)-39,57,117,103,111,33,(char)-19,124,5,(char)-32,120,(char)-107,120,59,(char)-118,(char)-65,(char)-72,5,114,15,(char)-6,94,(char)-18,(char)-7,(char)-34,(char)-42,(char)-13,(char)-27,51,73,
        (char)-57,54,73,111,(char)-52,(char)-64,110,(char)-73,(char)-69,79,(char)-88,49,43,8,(char)-78,34,48,110,(char)-113,(char)-84,78,14,(char)-2,5,(char)-19,64,108,(char)-64,67,111,47,61,29,91,33,(char)-78,
        (char)-41,(char)-58,54,(char)-29,(char)-31,(char)-47,(char)-35,(char)-91,92,(char)-34,(char)-23,70,126,(char)-123,105,(char)-73,(char)-35,118,(char)-37,34,(char)-125,(char)-14,(char)-85,(char)-39,
        (char)-34,84,(char)-115,19,(char)-104,65,44,(char)-16,(char)-55,32,23,(char)-80,(char)-89,109,(char)-37,105,(char)-27,(char)-52,(char)-57,(char)-62,88,64,11,(char)-27,17,(char)-53,(char)-111,(char)-17,
        104,117,(char)-67,7,(char)-6,74,124,(char)-75,67,(char)-59,66,(char)-59,64,1,95,122,50,(char)-112,1,95,(char)-32,87,(char)-96,(char)-61,(char)-93,48,(char)-12,(char)-91,(char)-125,(char)-34,103,
        40,(char)-77,(char)-39,(char)-27,(char)-34,46,122,92,52,110,69,(char)-32,114,(char)-91,(char)-96,(char)-51,(char)-63,61,(char)-124,(char)-71,106,11,(char)-43,(char)-113,(char)-74,80,(char)-70,58,
        (char)-115,(char)-56,48,(char)-55,(char)-113,62,109,(char)-106,(char)-53,19,(char)-63,(char)-122,(char)-17,125,(char)-17,123,(char)-9,35,15,(char)-79,40,(char)-7,78,23,64,6,(char)-78,89,58,125,75,
        48,(char)-15,(char)-35,116,(char)-20,51,(char)-10,(char)-55,6,(char)-67,67,(char)-30,52,(char)-47,(char)-18,(char)-80,(char)-13,(char)-19,114,55,83,(char)-107,124,(char)-123,96,81,(char)-95,57,78,
        (char)-3,(char)-88,118,(char)-30,21,(char)-90,76,(char)-29,(char)-30,(char)-94,47,93,(char)-47,73,(char)-70,(char)-78,(char)-95,101,(char)-81,(char)-8,116,(char)-123,73,58,54,122,(char)-19,10,(char)-58,
        42,(char)-47,(char)-18,93,20,0,40,8,115,51,71,115,85,4,(char)-38,105,63,19,38,(char)-39,(char)-85,(char)-113,65,(char)-101,85,(char)-13,10,126,(char)-101,(char)-36,15,(char)-4,(char)-51,64,(char)-65,
        72,(char)-15,78,21,64,118,(char)-1,(char)-22,(char)-69,(char)-20,(char)-78,(char)-53,127,(char)-53,(char)-64,(char)-4,34,(char)-29,(char)-76,(char)-101,(char)-66,73,61,(char)-59,(char)-81,(char)-19,
        126,(char)-76,(char)-73,(char)-101,68,(char)-55,22,(char)-53,(char)-50,(char)-73,107,(char)-20,124,11,(char)-27,8,(char)-75,104,30,(char)-85,(char)-76,(char)-123,(char)-14,71,107,(char)-15,(char)-24,
        (char)-75,71,(char)-23,123,(char)-48,65,(char)-23,(char)-118,71,11,101,(char)-21,(char)-57,83,(char)-70,(char)-123,(char)-47,(char)-34,31,15,(char)-27,95,(char)-79,81,(char)-119,(char)-106,(char)-16,
        42,104,(char)-44,(char)-109,(char)-116,(char)-71,42,16,99,(char)-41,110,(char)-40,(char)-98,14,102,(char)-46,(char)-77,(char)-119,(char)-113,118,62,(char)-21,(char)-28,126,96,(char)-5,(char)-51,
        54,(char)-37,108,13,(char)-6,(char)-59,(char)-59,98,23,64,94,(char)-11,46,(char)-73,(char)-21,(char)-82,(char)-69,62,35,29,(char)-66,60,(char)-63,103,(char)-4,122,(char)-78,38,21,(char)-97,(char)-74,
        19,(char)-29,(char)-33,40,25,12,(char)-68,32,(char)-111,(char)-82,(char)-7,22,68,(char)-14,29,(char)-107,110,(char)-14,(char)-20,126,(char)-57,37,63,109,64,(char)-100,(char)-110,(char)-13,(char)-58,
        113,90,76,(char)-10,(char)-69,11,(char)-15,(char)-95,(char)-30,(char)-12,60,93,47,(char)-41,56,(char)-24,10,116,(char)-26,(char)-114,(char)-14,7,(char)-68,34,48,63,(char)-9,2,(char)-26,(char)-27,
        (char)-122,(char)-42,(char)-55,(char)-32,(char)-35,66,95,4,(char)-4,65,60,116,18,(char)-60,43,125,(char)-7,21,(char)-115,(char)-34,(char)-17,85,110,(char)-102,(char)-17,99,124,1,(char)-73,(char)-40,
        121,93,108,(char)-57,45,(char)-73,(char)-36,(char)-14,73,(char)-103,(char)-32,118,(char)-23,104,(char)-4,(char)-43,(char)-82,1,117,3,(char)-120,105,(char)-44,126,(char)-15,(char)-110,110,18,(char)-102,
        (char)-61,(char)-44,(char)-113,74,(char)-66,(char)-123,(char)-112,124,11,35,(char)-7,22,74,81,84,108,113,(char)-16,(char)-128,(char)-97,106,62,(char)-115,12,(char)-11,25,(char)-25,(char)-40,(char)-82,
        29,(char)-127,79,(char)-15,(char)-28,30,(char)-12,61,(char)-54,(char)-90,13,(char)-52,36,107,(char)-61,86,(char)-108,47,(char)-48,1,(char)-34,88,(char)-52,(char)-43,60,93,2,20,(char)-71,(char)-109,
        (char)-64,61,(char)-127,(char)-57,(char)-56,42,2,(char)-66,(char)-96,29,(char)-120,9,120,96,115,95,80,60,25,95,62,(char)-28,(char)-16,(char)-101,(char)-28,(char)-47,(char)-4,89,(char)-7,66,(char)-18,
        49,108,(char)-117,(char)-125,(char)-59,42,(char)-128,(char)-81,126,(char)-11,(char)-85,43,(char)-92,(char)-13,(char)-89,(char)-91,(char)-109,(char)-25,39,104,(char)-5,93,(char)-75,116,22,(char)-10,
        (char)-114,55,126,77,(char)-56,(char)-113,(char)-46,(char)-121,29,127,(char)-24,10,(char)-108,22,69,(char)-110,(char)-19,114,11,(char)-31,(char)-71,(char)-39,(char)-47,(char)-17,120,(char)-12,(char)-46,
        (char)-121,(char)-99,(char)-97,54,104,(char)-6,69,(char)-90,(char)-95,(char)-41,(char)-107,95,57,(char)-12,(char)-74,(char)-116,(char)-69,(char)-44,51,(char)-98,26,(char)-4,97,(char)-20,56,(char)-127,
        (char)-87,62,(char)-118,(char)-106,75,(char)-115,(char)-75,(char)-28,(char)-123,81,(char)-105,3,(char)-113,(char)-117,(char)-118,(char)-67,(char)-118,(char)-64,124,(char)-99,18,(char)-30,(char)-12,
        (char)-79,(char)-115,(char)-121,12,61,95,(char)-15,(char)-23,(char)-117,(char)-17,105,124,95,(char)-103,(char)-5,(char)-127,13,115,(char)-87,110,55,(char)-24,(char)-67,109,18,(char)-65,88,5,(char)-112,
        111,(char)-95,60,(char)-18,(char)-3,(char)-73,4,24,95,(char)-5,(char)-45,(char)-47,120,(char)-73,71,(char)-33,(char)-82,(char)-11,40,24,28,12,(char)-7,(char)-110,(char)-35,(char)-51,123,54,(char)-10,
        (char)-58,(char)-84,(char)-110,111,119,88,32,62,80,(char)-19,(char)-15,5,125,22,63,(char)-55,94,(char)-70,73,126,108,(char)-123,(char)-118,81,116,38,61,59,27,10,120,(char)-64,(char)-9,40,93,(char)-47,
        (char)-78,73,106,(char)-115,(char)-123,13,36,92,1,(char)-8,30,(char)-63,(char)-36,109,0,58,(char)-89,4,127,62,(char)-43,6,5,(char)-103,11,85,97,0,0,16,0,73,68,65,84,(char)-70,(char)-118,(char)-119,
        14,101,58,(char)-96,15,(char)-26,45,(char)-77,(char)-52,50,(char)-81,124,(char)-57,59,(char)-34,(char)-31,(char)-17,39,(char)-116,95,(char)-51,(char)-77,79,(char)-62,34,11,32,(char)-107,(char)-76,
        108,110,(char)-46,54,78,(char)-32,103,102,48,11,84,85,(char)-12,45,(char)-18,(char)-92,(char)-99,54,(char)-76,(char)-111,77,52,(char)-15,(char)-38,47,97,(char)-40,13,118,2,(char)-38,39,95,(char)-64,
        (char)-12,(char)-123,(char)-76,(char)-62,(char)-62,(char)-125,(char)-10,(char)-108,(char)-8,2,25,74,70,(char)-7,13,97,113,21,30,(char)-67,29,(char)-41,(char)-125,(char)-98,(char)-116,(char)-14,(char)-29,
        (char)-45,(char)-57,17,127,8,62,64,(char)-49,23,45,(char)-108,(char)-36,(char)-45,(char)-30,(char)-75,(char)-47,(char)-105,121,123,(char)-62,113,63,(char)-32,61,(char)-127,13,(char)-63,(char)-58,
        15,5,(char)-15,(char)-56,(char)-128,95,24,(char)-8,79,(char)-63,(char)-65,(char)-86,90,59,(char)-66,(char)-37,(char)-17,(char)-65,(char)-1,(char)-2,119,(char)-65,0,(char)-14,69,(char)-49,90,(char)-53,
        46,(char)-69,(char)-84,107,(char)-65,(char)-93,63,99,(char)-103,53,62,74,117,(char)-104,(char)-114,(char)-58,50,30,(char)-24,(char)-29,(char)-120,(char)-99,6,(char)-117,107,(char)-14,(char)-82,125,
        (char)-114,123,59,0,92,10,(char)-76,41,103,109,(char)-95,100,54,(char)-24,(char)-27,(char)-30,39,(char)-47,(char)-66,(char)-83,75,(char)-115,(char)-60,(char)-38,101,22,(char)-39,98,43,54,(char)-33,
        45,(char)-72,46,67,(char)-23,(char)-36,(char)-84,(char)-79,(char)-15,(char)-11,118,79,(char)-37,(char)-66,95,(char)-29,31,(char)-10,(char)-41,(char)-9,53,(char)-76,77,(char)-110,(char)-7,(char)-117,
        105,(char)-50,(char)-3,41,96,77,(char)-22,126,(char)-128,125,(char)-40,86,(char)-69,66,111,(char)-21,117,(char)-75,9,(char)-45,(char)-2,41,(char)-15,(char)-39,36,(char)-13,89,55,116,(char)-95,(char)-97,
        69,(char)-99,0,(char)-77,(char)-10,(char)-36,115,(char)-49,39,(char)-89,19,127,58,101,(char)-38,(char)-51,95,31,53,29,(char)-74,(char)-99,(char)-118,(char)-106,126,(char)-56,(char)-109,43,17,(char)-114,
        126,55,123,32,1,22,(char)-70,(char)-38,(char)-95,124,1,15,(char)-23,31,(char)-103,(char)-122,(char)-34,(char)-114,(char)-121,114,80,100,98,102,1,(char)-38,111,(char)-13,(char)-96,22,(char)-105,(char)-34,
        34,121,(char)-118,(char)-104,61,123,(char)-10,40,(char)-123,61,(char)-54,113,(char)-39,64,(char)-57,(char)-26,(char)-124,82,0,10,(char)-95,(char)-96,112,(char)-6,(char)-28,27,79,65,(char)-65,(char)-96,
        111,58,(char)-108,(char)-116,7,114,15,54,50,(char)-22,(char)-107,(char)-74,83,(char)-64,9,(char)-120,87,116,(char)-42,(char)-120,(char)-115,15,(char)-32,11,37,(char)-93,(char)-123,(char)-34,86,(char)-70,
        (char)-48,(char)-37,(char)-45,(char)-9,86,79,124,(char)-30,19,(char)-41,(char)-38,106,(char)-85,(char)-83,92,(char)-74,71,51,(char)-3,(char)-73,(char)-48,2,(char)-40,123,(char)-17,(char)-67,87,(char)-50,
        (char)-96,(char)-2,42,(char)-99,(char)-116,95,(char)-9,(char)-122,(char)-97,41,86,(char)-45,(char)-77,(char)-89,(char)-13,5,78,5,11,40,9,18,(char)-18,(char)-37,59,112,(char)-9,47,41,(char)-83,(char)-31,
        (char)-32,(char)-121,24,(char)-67,(char)-86,(char)-105,(char)-117,23,(char)-77,(char)-6,43,(char)-33,74,(char)-102,93,45,54,(char)-33,(char)-68,(char)-74,30,73,(char)-8,10,43,(char)-84,48,(char)-54,
        (char)-73,(char)-105,(char)-93,7,63,(char)-8,(char)-63,13,51,(char)-15,(char)-4,(char)-14,61,71,(char)-69,(char)-57,17,67,65,24,119,(char)-42,98,90,(char)-95,87,(char)-33,(char)-6,(char)-88,(char)-2,
        (char)-117,(char)-78,65,(char)-55,(char)-67,79,(char)-23,81,5,96,35,56,17,109,12,(char)-105,(char)-57,(char)-102,23,59,84,(char)-116,(char)-98,(char)-89,(char)-21,99,(char)-110,59,(char)-52,(char)-118,
        (char)-17,(char)-86,41,(char)-26,(char)-65,(char)-55,99,(char)-95,(char)-109,(char)-69,51,77,103,103,44,(char)-128,(char)-68,(char)-12,89,106,(char)-89,(char)-99,118,(char)-14,111,(char)-13,95,(char)-112,
        38,(char)-83,(char)-118,18,52,(char)-20,104,90,114,75,55,(char)-54,127,6,4,116,(char)-123,(char)-88,71,38,100,71,58,(char)-10,84,(char)-70,(char)-118,55,97,(char)-117,(char)-53,(char)-113,(char)-49,
        36,(char)-120,5,108,(char)-27,55,73,(char)-50,68,(char)-37,47,127,(char)-118,45,73,(char)-6,(char)-109,64,(char)-119,(char)-108,108,(char)-119,(char)-98,61,(char)-75,(char)-29,(char)-19,122,(char)-80,
        (char)-13,81,(char)-59,49,4,95,109,64,123,126,118,(char)-90,(char)-40,10,76,33,27,83,(char)-95,(char)-58,84,(char)-76,(char)-12,(char)-109,(char)-88,121,0,27,127,(char)-80,30,96,(char)-4,(char)-30,
        91,(char)-85,(char)-78,(char)-93,(char)-64,(char)-49,9,(char)-123,(char)-110,123,(char)-48,65,(char)-59,(char)-99,(char)-78,(char)-7,39,(char)-23,27,(char)-25,(char)-12,(char)-14,(char)-105,75,102,
        77,(char)-23,22,32,51,22,64,26,(char)-82,(char)-112,(char)-21,(char)-1,6,9,(char)-68,114,90,77,(char)-13,(char)-21,59,(char)-118,61,(char)-26,81,43,(char)-118,(char)-30,71,(char)-7,(char)-113,79,
        (char)-55,18,100,(char)-15,28,(char)-59,18,15,120,122,62,(char)-112,38,(char)-19,83,(char)-68,(char)-10,77,(char)-111,31,61,31,(char)-79,(char)-19,(char)-62,(char)-14,(char)-109,24,59,(char)-44,
        (char)-18,97,(char)-109,76,73,(char)-109,60,(char)-119,84,8,18,(char)-24,(char)-120,(char)-105,116,(char)-44,66,(char)-126,24,5,50,(char)-80,(char)-125,54,98,105,47,(char)-106,(char)-104,116,(char)-110,
        (char)-93,(char)-112,37,(char)-54,(char)-72,(char)-76,71,(char)-11,93,(char)-108,(char)-114,(char)-36,(char)-125,13,74,(char)-121,(char)-41,(char)-97,98,53,126,39,(char)-94,117,17,(char)-41,41,96,
        94,108,(char)-67,127,(char)-15,104,(char)-33,(char)-121,88,64,15,120,8,(char)-65,(char)-50,122,(char)-21,(char)-83,(char)-73,(char)-2,(char)-26,(char)-101,111,(char)-18,(char)-41,(char)-12,34,46,
        (char)-8,(char)-103,(char)-106,(char)-40,(char)-34,(char)-100,9,63,34,3,120,110,(char)-80,42,(char)-67,(char)-128,125,(char)-89,116,(char)-67,(char)-52,78,7,(char)-12,38,71,(char)-105,(char)-10,
        (char)-19,87,(char)-85,45,(char)-102,10,55,81,(char)-113,62,(char)-12,(char)-4,(char)-8,(char)-13,67,123,(char)-103,14,(char)-24,39,(char)-127,(char)-51,34,89,(char)-80,20,107,59,(char)-38,37,10,
        36,78,(char)-78,36,82,76,99,65,(char)-59,41,(char)-118,(char)-17,(char)-11,(char)-28,2,31,54,80,52,98,(char)-119,(char)-87,(char)-96,(char)-60,(char)-89,(char)-105,52,55,110,10,(char)-69,(char)-38,
        21,53,54,49,(char)-96,116,40,(char)-71,71,(char)-7,(char)-39,8,110,74,61,17,(char)-72,44,90,43,115,99,(char)-41,14,(char)-76,43,25,79,(char)-73,48,(char)-39,24,(char)-29,103,(char)-13,110,(char)-2,
        (char)-74,(char)-73,(char)-67,109,(char)-4,(char)-53,58,(char)-38,(char)-11,(char)-104,(char)-87,0,102,(char)-19,(char)-66,(char)-5,(char)-18,(char)-2,(char)-43,(char)-22,58,113,(char)-10,(char)-81,
        84,66,(char)-26,127,18,116,(char)-68,(char)-37,107,0,(char)-13,45,(char)-13,127,(char)-78,(char)-45,3,(char)-115,68,(char)-85,104,(char)-119,50,57,69,80,(char)-117,(char)-58,7,(char)-8,(char)-11,
        84,12,40,61,(char)-66,80,126,46,31,(char)-82,(char)-13,118,(char)-92,(char)-60,(char)-128,36,73,24,(char)-16,(char)-41,30,(char)-86,(char)-51,(char)-62,(char)-8,(char)-95,(char)-115,12,(char)-30,
        (char)-128,(char)-104,10,(char)-63,(char)-119,(char)-96,47,(char)-123,96,30,(char)-110,(char)-123,(char)-14,(char)-19,(char)-95,79,(char)-48,(char)-74,(char)-41,(char)-29,75,(char)-57,14,116,(char)-42,
        (char)-56,9,96,125,(char)-52,75,81,91,59,(char)-74,73,(char)-88,118,101,19,19,74,102,15,(char)-106,(char)-113,(char)-50,35,(char)-4,(char)-45,74,63,(char)-92,19,11,96,(char)-37,109,(char)-73,125,
        80,(char)-86,114,(char)-67,56,63,54,72,(char)-116,89,45,(char)-23,(char)-31,(char)-37,(char)-15,(char)-101,(char)-64,99,74,23,7,(char)-92,(char)-23,26,51,(char)-11,(char)-61,4,36,(char)-56,2,(char)-87,
        112,5,80,71,(char)-75,24,83,110,(char)-115,(char)-120,65,(char)-121,54,(char)-59,(char)-32,7,27,(char)-80,(char)-117,39,14,94,50,64,114,96,(char)-86,(char)-14,(char)-37,120,(char)-39,7,97,(char)-102,
        40,14,(char)-122,29,(char)-113,(char)-106,(char)-116,2,125,79,(char)-7,(char)-120,93,(char)-123,(char)-96,(char)-49,(char)-100,(char)-110,92,70,46,103,(char)-18,11,(char)-52,(char)-73,41,38,(char)-4,
        (char)-48,(char)-66,87,(char)-9,(char)-78,(char)-66,(char)-20,120,(char)-59,100,(char)-115,(char)-60,83,0,(char)-118,(char)-100,(char)-83,111,71,6,(char)-70,(char)-118,65,6,50,(char)-80,21,34,(char)-81,
        (char)-78,(char)-23,(char)-90,(char)-101,(char)-82,49,(char)-45,(char)-45,(char)-64,(char)-60,2,56,(char)-19,(char)-76,(char)-45,(char)-106,(char)-50,(char)-117,10,(char)-113,126,15,(char)-85,64,
        67,(char)-102,(char)-64,109,(char)-111,(char)-23,117,(char)-114,66,(char)-15,40,88,24,71,(char)-91,99,95,(char)-46,84,58,(char)-3,16,(char)-38,2,61,90,32,(char)-9,11,43,(char)-7,(char)-114,95,(char)-55,
        (char)-74,(char)-29,37,66,82,28,(char)-9,125,27,(char)-68,(char)-74,(char)-88,(char)-79,(char)-94,(char)-123,94,(char)-58,23,(char)-54,(char)-34,(char)-45,(char)-78,(char)-11,(char)-79,(char)-12,
        (char)-91,79,(char)-3,3,94,(char)-46,36,(char)-79,31,(char)-85,56,(char)-43,14,(char)-83,88,(char)-12,64,70,(char)-39,80,(char)-13,(char)-78,70,(char)-118,(char)-64,(char)-102,(char)-119,(char)-105,
        (char)-115,(char)-40,54,22,31,(char)-32,(char)-41,(char)-93,98,(char)-48,(char)-79,3,(char)-66,(char)-45,(char)-69,(char)-127,(char)-1,(char)-85,85,87,93,(char)-11,54,(char)-6,33,22,40,0,119,(char)-1,
        103,(char)-100,113,(char)-58,42,107,(char)-27,(char)-65,4,(char)-69,(char)-67,26,(char)-44,(char)-60,(char)-70,(char)-64,101,(char)-102,(char)-111,26,(char)-68,(char)-124,91,28,71,27,(char)-38,59,
        87,(char)-84,(char)-94,(char)-67,13,(char)-97,(char)-2,(char)-111,(char)-15,2,24,(char)-125,(char)-126,18,(char)-41,81,12,(char)-110,1,28,43,78,81,(char)-70,69,65,31,(char)-30,(char)-94,51,(char)-7,
        (char)-10,54,(char)-68,(char)-8,(char)-6,(char)-108,120,99,80,4,(char)-38,74,(char)-102,(char)-79,(char)-31,(char)-7,1,30,(char)-76,33,3,(char)-98,14,(char)-16,(char)-128,7,39,(char)-91,34,(char)-80,
        86,78,1,99,(char)-93,(char)-25,3,(char)-8,(char)-126,88,64,95,40,91,(char)-47,(char)-40,61,(char)-62,63,54,5,(char)-80,126,(char)-23,122,(char)-70,84,47,(char)-32,(char)-73,(char)-39,102,(char)-101,
        (char)-91,87,90,105,37,(char)-1,(char)-108,(char)-5,(char)-111,(char)-111,19,119,86,(char)-56,(char)-4,79,(char)-126,(char)-51,103,(char)-14,19,31,99,(char)-72,59,62,(char)-67,(char)-50,(char)-64,
        85,(char)-80,73,(char)-104,80,93,(char)-41,(char)-8,104,81,109,(char)-117,(char)-46,21,122,29,(char)-66,(char)-32,(char)-120,20,(char)-81,22,(char)-35,41,32,17,101,(char)-41,126,(char)-56,(char)-45,
        85,(char)-97,120,(char)-32,(char)-125,(char)-46,23,(char)-56,61,(char)-24,75,46,127,114,(char)-15,117,57,(char)-88,34,112,18,(char)-43,(char)-27,(char)-50,(char)-68,123,95,124,31,(char)-49,(char)-38,
        (char)-12,50,59,(char)-48,107,107,(char)-67,(char)-86,0,(char)-60,(char)-20,125,(char)-11,95,(char)-48,(char)-122,(char)-83,7,29,(char)-48,(char)-95,83,120,(char)-36,126,(char)-5,(char)-19,55,(char)-54,
        55,(char)-123,11,(char)-36,12,46,80,0,73,(char)-66,(char)-65,(char)-103,(char)-21,(char)-41,(char)-67,86,75,71,(char)-119,51,(char)-1,16,8,(char)-33,98,69,(char)-47,(char)-88,31,61,(char)-49,110,
        81,(char)-24,(char)-63,100,(char)-20,86,73,(char)-109,124,19,(char)-30,(char)-49,(char)-113,29,15,(char)-8,73,(char)-32,87,96,23,(char)-53,98,84,(char)-14,45,60,59,91,(char)-95,(char)-28,(char)-123,
        (char)-59,29,(char)-6,86,(char)-101,(char)-46,23,(char)-91,(char)-121,94,46,30,(char)-43,7,(char)-69,57,27,(char)-117,83,0,(char)-52,87,18,(char)-7,20,(char)-8,(char)-31,(char)-117,22,47,6,(char)-112,
        11,(char)-82,(char)-5,98,(char)-8,101,24,84,44,107,57,(char)-12,(char)-29,79,87,49,(char)-117,(char)-46,23,(char)-40,(char)-15,(char)-95,15,(char)-54,70,121,(char)-50,(char)-15,(char)-57,31,79,(char)-100,
        (char)-122,5,10,(char)-32,(char)-93,31,(char)-3,(char)-24,67,115,(char)-116,(char)-71,(char)-7,115,(char)-19,(char)-72,99,(char)-5,(char)-89,(char)-39,(char)-92,78,(char)-24,32,(char)-99,(char)-60,
        99,(char)-2,(char)-41,(char)-61,(char)-8,(char)-60,24,(char)-103,(char)-116,(char)-69,127,(char)-55,(char)-9,38,(char)-51,68,56,(char)-15,47,(char)-112,39,65,(char)-116,(char)-46,(char)-29,93,(char)-5,
        (char)-59,(char)-76,(char)-56,22,60,19,106,111,(char)-22,(char)-8,(char)-80,(char)-93,(char)-123,(char)-110,(char)-11,81,(char)-70,33,(char)-27,(char)-45,(char)-37,(char)-117,47,58,(char)-12,47,
        61,10,101,(char)-57,27,(char)-117,49,25,(char)-101,83,(char)-55,(char)-100,(char)-53,(char)-114,(char)-22,(char)-85,104,(char)-49,(char)-45,21,(char)-60,(char)-63,(char)-77,107,111,(char)-67,(char)-48,
        (char)-102,55,(char)-3,16,(char)-4,11,108,98,64,(char)-23,(char)-16,83,122,(char)-113,(char)-125,(char)-85,(char)-25,18,(char)-27,(char)-113,82,(char)-107,(char)-71,(char)-47,5,10,32,71,(char)-20,
        (char)-118,(char)-79,108,16,52,(char)-101,32,(char)-31,(char)-37,71,48,76,(char)-47,(char)-30,75,70,11,42,(char)-41,(char)-11,63,(char)-99,(char)-114,76,(char)-122,(char)-98,63,(char)-12,60,(char)-71,
        (char)-121,(char)-2,(char)-54,(char)-114,74,(char)-70,69,16,(char)-49,(char)-18,(char)-73,(char)-64,22,(char)-101,(char)-97,118,104,(char)-127,12,118,37,10,101,67,(char)-55,98,2,(char)-98,(char)-82,
        80,(char)-70,94,95,58,62,(char)-12,61,(char)-24,(char)-54,78,(char)-81,79,99,3,122,(char)-13,(char)-90,31,66,59,(char)-96,(char)-25,7,120,(char)-96,39,(char)-101,(char)-77,77,35,(char)-122,53,52,
        119,122,62,(char)-117,3,113,(char)-8,(char)-95,16,126,94,(char)-38,(char)-1,69,94,10,45,(char)-27,30,47,(char)-14,(char)-8,(char)-45,(char)-110,60,(char)-106,(char)-62,(char)-52,(char)-103,51,(char)-57,
        31,51,124,92,88,(char)-105,(char)-126,118,3,22,126,(char)-38,71,80,(char)-104,(char)-90,(char)-116,64,103,33,(char)-46,89,(char)-5,99,12,41,(char)-90,(char)-10,(char)-75,(char)-81,75,64,77,(char)-126,
        45,(char)-82,51,126,(char)-122,118,(char)-78,(char)-109,68,3,(char)-119,(char)-73,(char)-37,(char)-12,65,30,(char)-126,47,93,79,(char)-117,(char)-89,31,(char)-62,(char)-119,(char)-44,(char)-37,(char)-115,
        (char)-65,124,122,125,(char)-15,(char)-109,(char)-20,116,96,76,(char)-58,(char)-26,20,(char)-64,(char)-69,92,(char)-127,120,(char)-43,30,(char)-49,23,(char)-123,(char)-98,39,3,(char)-99,118,(char)-75,
        118,(char)-118,95,65,24,43,123,(char)-95,(char)-113,(char)-39,(char)-21,122,125,(char)-57,(char)-69,17,(char)-100,(char)-109,24,79,76,1,(char)-52,43,127,116,90,1,(char)-8,7,31,(char)-81,127,(char)-3,
        (char)-21,(char)-67,(char)-7,(char)-69,49,(char)-58,105,(char)-57,127,(char)-28,(char)-10,49,64,104,(char)-62,(char)-32,(char)-121,14,33,29,(char)-115,11,64,21,(char)-101,0,(char)-3,(char)-64,125,
        (char)-94,56,(char)-12,(char)-85,29,96,103,85,1,104,56,28,(char)-61,(char)-80,29,(char)-97,2,27,(char)-112,(char)-85,93,(char)-55,116,67,44,(char)-54,(char)-42,(char)-37,(char)-15,98,(char)-126,
        (char)-60,27,35,40,120,113,123,59,25,(char)-24,80,109,0,79,87,32,59,53,(char)-83,(char)-99,71,67,(char)-9,63,108,124,(char)-121,(char)-32,59,4,(char)-33,94,71,14,(char)-98,(char)-112,49,(char)-51,
        (char)-55,(char)-5,0,(char)-59,48,54,79,43,(char)-128,53,(char)-41,92,115,118,(char)-86,(char)-40,(char)-33,(char)-18,115,25,104,78,105,(char)-40,(char)-98,(char)-9,117,76,65,70,(char)-127,(char)-82,
        64,6,118,5,96,(char)-48,(char)-86,(char)-40,36,84,(char)-12,36,63,(char)-2,(char)-109,(char)-64,(char)-73,(char)-12,(char)-38,(char)-30,45,106,(char)-58,(char)-122,109,(char)-89,(char)-110,126,122,
        (char)-65,102,(char)-24,126,(char)-80,19,39,(char)-7,(char)-48,1,59,20,(char)-81,13,(char)-108,(char)-52,6,37,(char)-77,1,93,79,(char)-51,(char)-105,(char)-114,31,40,86,84,(char)-14,80,96,7,(char)-19,
        (char)-56,64,(char)-18,81,58,62,(char)-12,117,15,96,13,(char)-86,15,(char)-6,(char)-78,(char)-29,11,(char)-117,(char)-96,9,61,(char)-53,(char)-91,(char)-8,(char)-15,(char)-89,(char)-100,114,(char)-54,
        52,(char)-41,105,5,(char)-80,(char)-18,(char)-70,(char)-2,47,42,(char)-73,63,42,29,(char)-116,(char)-65,(char)-5,79,(char)-53,(char)-74,(char)-32,90,(char)-31,(char)-47,(char)-40,(char)-57,(char)-70,
        (char)-110,81,40,(char)-101,65,(char)-37,(char)-67,(char)-112,(char)-54,99,26,(char)-73,(char)-31,(char)-45,20,(char)-7,81,49,(char)-61,(char)-74,(char)-113,93,(char)-44,(char)-104,(char)-4,112,
        114,(char)-128,(char)-60,43,(char)-128,(char)-78,85,(char)-101,62,78,(char)-36,(char)-57,31,118,(char)-96,(char)-104,(char)-28,(char)-45,47,(char)-26,36,(char)-97,(char)-95,(char)-99,79,(char)-95,
        (char)-30,(char)-10,(char)-78,113,(char)-47,3,(char)-34,120,(char)-63,(char)-40,(char)-83,(char)-61,(char)-92,49,(char)-48,13,(char)-5,(char)-95,(char)-85,(char)-72,(char)-38,89,59,79,2,46,(char)-127,
        124,(char)-59,(char)-21,125,(char)-54,87,(char)-65,(char)-59,(char)-9,(char)-108,111,103,91,97,(char)-107,85,86,121,112,(char)-98,4,(char)-90,(char)-27,124,(char)-102,112,(char)-24,(char)-95,(char)-121,
        (char)-50,(char)-53,53,71,1,60,88,(char)-121,2,84,64,60,(char)-108,(char)-116,(char)-110,1,(char)-33,117,(char)-44,(char)-2,(char)-32,(char)-110,65,59,1,64,1,(char)-108,95,(char)-17,91,109,(char)-118,
        (char)-78,(char)-15,3,(char)-68,118,38,109,49,(char)-53,(char)-89,40,123,(char)-49,47,74,(char)-106,24,62,48,108,71,(char)-89,79,96,3,(char)-70,2,61,(char)-108,(char)-116,(char)-10,(char)-15,(char)-56,
        5,122,(char)-29,85,(char)-80,(char)-75,(char)-122,(char)-38,66,(char)-7,12,121,50,(char)-108,29,37,39,23,(char)-19,107,110,107,105,45,(char)-24,(char)-40,(char)-96,(char)-58,72,7,116,(char)-123,
        (char)-78,(char)-111,(char)-53,22,58,47,49,30,126,(char)-10,(char)-39,103,63,(char)-124,(char)-66,48,(char)-83,0,54,(char)-39,100,(char)-109,(char)-121,(char)-81,(char)-72,(char)-30,(char)-118,(char)-53,
        (char)-57,(char)-24,(char)-1,(char)-85,(char)-45,(char)-114,(char)-2,(char)-16,119,(char)-22,99,(char)-46,(char)-110,102,(char)-48,42,88,37,11,80,(char)-125,42,106,(char)-95,(char)-24,51,(char)-80,
        118,50,20,(char)-91,43,(char)-120,35,(char)-98,5,(char)-27,(char)-81,45,(char)-108,93,(char)-101,(char)-30,81,50,104,67,(char)-18,(char)-47,(char)-21,(char)-60,(char)-128,(char)-34,78,6,(char)-19,
        123,61,126,81,58,118,(char)-32,11,(char)-58,(char)-86,0,(char)-16,46,(char)-123,(char)-30,(char)-30,(char)-7,64,(char)-15,104,(char)-127,15,27,74,(char)-121,55,127,107,(char)-120,26,63,29,27,(char)-97,
        (char)-98,(char)-89,(char)-21,(char)-63,6,(char)-4,96,(char)-54,(char)-26,(char)-98,110,(char)-59,(char)-25,61,(char)-17,121,(char)-45,94,9,79,43,(char)-128,92,2,(char)-4,105,23,(char)-49,(char)-118,
        (char)-73,9,48,(char)-43,(char)-80,21,66,(char)-55,2,22,(char)-54,(char)-114,(char)-78,23,12,(char)-42,(char)-96,21,(char)-127,2,(char)-96,(char)-25,(char)-93,93,(char)-15,40,(char)-48,3,91,15,49,
        (char)-76,117,61,85,0,124,(char)-8,3,(char)-66,124,(char)-15,(char)-123,(char)-46,21,45,95,9,41,(char)-97,(char)-94,124,122,(char)-98,92,40,125,81,122,124,79,(char)-117,(char)-89,31,(char)-126,(char)-83,
        (char)-6,(char)-76,14,80,62,108,53,46,124,(char)-95,(char)-20,101,35,103,(char)-57,(char)-74,(char)-81,(char)-46,(char)-83,(char)-93,(char)-11,(char)-96,(char)-101,9,(char)-61,56,(char)-67,(char)-116,
        79,(char)-69,101,67,(char)-105,(char)-51,37,(char)-59,(char)-73,(char)-68,17,(char)-25,127,(char)-6,2,(char)-104,(char)-107,(char)-17,(char)-115,61,42,44,23,(char)-57,(char)-7,(char)-42,(char)-87,
        (char)-97,53,40,20,(char)-90,(char)-44,(char)-115,12,125,(char)-101,50,63,36,(char)-81,38,16,(char)-79,125,(char)-6,(char)-74,120,104,(char)-122,(char)-4,(char)-64,(char)-101,36,20,(char)-81,(char)-67,
        (char)-8,61,(char)-30,58,(char)-29,71,59,70,(char)-2,104,(char)-95,(char)-12,(char)-67,76,87,126,(char)-8,2,(char)-97,(char)-46,(char)-29,11,116,124,(char)-56,69,(char)-15,67,(char)-16,(char)-93,
        67,21,(char)-82,57,40,(char)-122,(char)-66,13,27,(char)-16,(char)-21,49,(char)-44,89,67,(char)-55,23,(char)-93,47,(char)-94,62,(char)-106,(char)-10,(char)-43,110,(char)-88,39,23,(char)-30,(char)-29,
        (char)-15,111,(char)-75,(char)-36,(char)-24,(char)-33,(char)-110,54,(char)-29,(char)-68,(char)-113,(char)-103,40,(char)-67,(char)-13,117,2,(char)-36,28,(char)-25,(char)-116,121,(char)-87,(char)-74,
        (char)-13,(char)-61,79,(char)-93,(char)-15,27,31,(char)-39,(char)-59,(char)-93,61,116,42,(char)-111,6,(char)-98,64,(char)-51,68,(char)-41,(char)-104,(char)-87,31,(char)-30,78,(char)-79,45,30,126,
        (char)-110,(char)-114,(char)-66,98,(char)-32,(char)-95,(char)-9,35,23,(char)-24,(char)-127,92,(char)-3,(char)-107,76,(char)-41,(char)-125,29,74,(char)-57,15,74,70,23,38,(char)-9,109,(char)-7,(char)-110,
        1,(char)-81,(char)-99,49,(char)-93,32,(char)-111,40,(char)-80,23,(char)-8,23,74,(char)-121,(char)-10,126,(char)-42,80,(char)-14,(char)-59,(char)-21,125,103,(char)-30,(char)-75,47,(char)-16,(char)-23,
        120,(char)-65,39,56,(char)-17,(char)-100,115,(char)-50,113,15,(char)-96,24,(char)-102,105,(char)-87,(char)-10,51,63,14,56,(char)-32,(char)-128,(char)-91,82,(char)-79,(char)-65,15,59,39,13,57,(char)-113,
        19,19,57,(char)-22,(char)-55,(char)-97,126,(char)-80,60,(char)-8,(char)-42,(char)-96,13,28,(char)-24,39,65,91,(char)-2,104,15,(char)-66,25,75,(char)-21,(char)-33,(char)-60,(char)-55,(char)-20,(char)-24,
        16,(char)-67,94,44,40,(char)-97,(char)-34,(char)-42,(char)-13,(char)-109,(char)-20,(char)-43,14,(char)-123,(char)-34,(char)-97,(char)-84,(char)-96,(char)-47,106,59,(char)-92,(char)-4,(char)-95,(char)-41,
        (char)-109,(char)-19,(char)-32,94,87,124,(char)-59,50,63,126,(char)-91,(char)-57,(char)-105,(char)-51,(char)-3,(char)-125,126,(char)-63,58,(char)-106,(char)-66,124,(char)-117,(char)-78,23,(char)-33,
        83,(char)-79,74,(char)-58,7,107,(char)-20,(char)-80,(char)-61,14,75,71,(char)-25,126,32,100,116,(char)-57,(char)-1,60,58,5,48,111,(char)-33,125,(char)-9,(char)-11,22,112,86,44,16,(char)-78,(char)-32,
        39,65,(char)-38,(char)-119,(char)-64,(char)-126,(char)-17,105,(char)-15,6,106,80,(char)-123,94,(char)-49,70,(char)-122,(char)-30,(char)-117,(char)-46,1,(char)-39,(char)-82,(char)-63,(char)-9,(char)-48,
        31,(char)-48,(char)-15,1,(char)-4,16,(char)-12,(char)-4,(char)-128,(char)-115,12,(char)-8,(char)-46,(char)-31,75,(char)-121,47,(char)-80,(char)-61,76,114,(char)-23,(char)-117,(char)-10,(char)-66,
        (char)-109,116,85,(char)-56,101,43,(char)-86,29,(char)-112,(char)-117,(char)-30,107,76,40,(char)-67,53,68,(char)-55,5,126,85,56,67,(char)-98,60,3,108,(char)-16,27,15,60,(char)-16,64,47,(char)-7,
        (char)-100,(char)-10,(char)-51,109,124,2,(char)-112,114,(char)-61,117,125,(char)-24,108,29,(char)-123,(char)-74,79,(char)-49,83,(char)-112,(char)-95,(char)-8,(char)-98,(char)-42,64,(char)-23,12,
        (char)-112,95,15,(char)-10,2,(char)-97,(char)-30,81,114,65,(char)-37,(char)-30,(char)-117,14,125,(char)-56,80,(char)-10,33,(char)-43,(char)-81,(char)-59,67,(char)-53,(char)-42,(char)-5,23,(char)-33,
        (char)-37,(char)-15,(char)-43,6,15,125,91,109,10,(char)-91,(char)-17,125,74,(char)-121,(char)-14,(char)-21,105,(char)-15,(char)-12,5,58,24,(char)-58,40,(char)-69,117,(char)-64,27,19,(char)-65,33,
        (char)-54,94,122,(char)-66,120,84,76,32,3,62,39,115,14,(char)-107,(char)-101,125,(char)-55,71,(char)-43,(char)-48,23,(char)-64,(char)-84,(char)-3,(char)-9,(char)-33,(char)-1,65,113,(char)-12,79,
        (char)-117,(char)-58,(char)-41,(char)-120,(char)-26,53,(char)-31,(char)-121,78,38,(char)-88,(char)-37,(char)-23,(char)-64,(char)-106,56,(char)-19,(char)-37,58,71,87,(char)-7,(char)-47,67,(char)-55,
        (char)-24,80,(char)-90,(char)-45,(char)-106,62,3,38,78,3,91,(char)-81,(char)-24,101,109,122,27,(char)-66,116,69,(char)-53,(char)-65,40,(char)-97,2,29,63,40,93,(char)-65,(char)-8,(char)-20,(char)-123,
        (char)-78,(char)-9,(char)-66,(char)-91,67,(char)-7,(char)-95,(char)-112,(char)-115,(char)-123,(char)-76,75,90,(char)-81,(char)-89,28,(char)-54,(char)-67,78,108,73,(char)-122,(char)-30,(char)-47,
        (char)-14,(char)-87,(char)-74,(char)-91,(char)-93,47,(char)-66,40,(char)-35,20,(char)-20,(char)-6,121,123,(char)-19,(char)-75,(char)-41,(char)-107,57,(char)-19,(char)-57,121,31,51,113,(char)-70,
        (char)-3,(char)-124,19,78,(char)-16,(char)-116,(char)-8,(char)-53,(char)-16,109,(char)-80,(char)-24,(char)-124,64,45,(char)-55,108,51,(char)-63,(char)-79,7,6,(char)-18,23,37,(char)-54,(char)-49,
        (char)-128,123,(char)-48,(char)-109,81,(char)-48,23,(char)-32,(char)-23,45,28,90,114,(char)-15,100,24,(char)-54,116,(char)-43,30,95,24,(char)-22,(char)-122,(char)-14,(char)-48,111,82,(char)-36,(char)-14,
        (char)-23,(char)-87,56,51,(char)-7,(char)-46,3,31,(char)-101,0,5,(char)-19,(char)-23,1,95,32,67,47,(char)-41,26,90,71,60,(char)-101,24,(char)-128,47,127,20,74,(char)-89,104,75,(char)-90,(char)-125,
        (char)-76,(char)-15,(char)-81,(char)-123,(char)-26,62,36,(char)-1,(char)-91,0,(char)-58,27,(char)-68,47,(char)-128,(char)-91,54,(char)-36,112,(char)-61,63,(char)-60,(char)-47,(char)-109,0,(char)-25,
        25,19,(char)-35,7,(char)-57,(char)-89,(char)-115,62,26,(char)-16,96,(char)-48,94,(char)-122,(char)-32,(char)-95,25,(char)-13,(char)-125,127,(char)-56,(char)-116,31,118,(char)-112,124,78,(char)-8,
        73,19,(char)-94,47,(char)-16,(char)-125,(char)-95,76,(char)-41,(char)-73,101,(char)-89,67,11,(char)-117,26,91,111,(char)-97,(char)-60,(char)-45,(char)-127,(char)-72,5,(char)-79,(char)-85,95,60,59,
        10,124,(char)-118,(char)-30,97,40,(char)-45,105,35,(char)-122,117,(char)-24,(char)-109,(char)-49,6,(char)-20,104,(char)-33,(char)-74,(char)-25,(char)-39,6,(char)-16,(char)-107,(char)-80,(char)-105,
        124,(char)-110,63,(char)-66,(char)-57,(char)-21,11,96,(char)-34,(char)-27,(char)-105,95,(char)-18,29,(char)-64,(char)-107,(char)-23,(char)-72,(char)-41,(char)-113,(char)-29,(char)-24,20,(char)-58,
        (char)-118,48,58,(char)-123,(char)-46,(char)-93,6,108,(char)-32,(char)-96,8,(char)-30,54,46,38,118,80,32,(char)-12,61,(char)-60,1,58,84,123,(char)-69,39,(char)-29,25,(char)-97,72,(char)-12,(char)-64,
        103,113,(char)-63,31,(char)-8,(char)-21,27,(char)-118,71,123,(char)-16,3,62,(char)-24,36,91,(char)-81,(char)-101,(char)-60,107,87,48,(char)-121,97,44,(char)-78,118,69,(char)-15,5,(char)-19,(char)-16,
        (char)-88,117,(char)-76,126,21,(char)-125,(char)-66,111,51,(char)-28,75,70,123,104,55,(char)-123,91,14,62,(char)-8,(char)-32,(char)-71,(char)-31,93,14,66,70,119,60,5,(char)-112,(char)-26,(char)-52,
        (char)-103,115,69,22,(char)-4,(char)-113,105,(char)-4,71,(char)-78,65,0,62,58,100,(char)-116,(char)-95,(char)-98,92,(char)-32,100,(char)-48,(char)-66,27,55,1,(char)-78,36,(char)-118,(char)-47,(char)-5,
        (char)-48,15,(char)-63,7,20,8,(char)-32,(char)-75,(char)-27,(char)-121,7,60,(char)-32,1,15,120,(char)-64,(char)-49,(char)-124,(char)-66,127,124,(char)-17,(char)-89,109,97,104,43,(char)-65,(char)-34,
        (char)-50,(char)-57,(char)-40,0,(char)-49,7,5,58,(char)-9,48,(char)-26,95,109,(char)-54,94,50,31,58,40,29,(char)-66,(char)-32,23,96,106,13,21,3,(char)-97,(char)-78,(char)-23,3,74,(char)-121,103,
        35,23,(char)-56,64,14,(char)-11,122,(char)-1,87,23,95,124,(char)-79,19,32,(char)-30,(char)-4,(char)-49,(char)-76,(char)-99,(char)-2,(char)-75,(char)-81,125,(char)-115,(char)-109,119,1,(char)-119,
        55,46,(char)-110,(char)-7,(char)-98,(char)-7,25,(char)-27,120,39,70,28,127,(char)-90,58,104,(char)-78,(char)-92,(char)-127,1,(char)-69,(char)-2,(char)-9,11,(char)-96,125,(char)-17,(char)-37,26,12,
        126,(char)-108,29,(char)-75,0,22,41,69,(char)-39,(char)-2,125,(char)-95,(char)-10,3,(char)-9,105,(char)-30,36,(char)-69,56,(char)-100,(char)-122,(char)-74,(char)-46,(char)-77,13,97,(char)-4,116,
        67,(char)-97,97,12,62,(char)-123,(char)-34,(char)-73,(char)-58,76,103,29,42,30,95,58,20,(char)-16,(char)-109,80,54,(char)-101,(char)-88,(char)-42,80,12,(char)-66,(char)-58,0,120,126,120,20,38,(char)-15,
        (char)-99,(char)-18,(char)-74,124,(char)-67,124,(char)-13,89,103,(char)-99,(char)-11,91,(char)-66,(char)-123,105,5,(char)-80,(char)-15,(char)-58,27,(char)-1,33,29,(char)-3,54,(char)-63,(char)-35,
        7,(char)-76,99,59,124,(char)-13,(char)-19,2,53,(char)-71,(char)-1,81,54,(char)-66,32,(char)-23,(char)-110,(char)-25,95,(char)-49,(char)-44,63,(char)-106,114,(char)-70,105,0,0,16,0,73,68,65,84,(char)-98,
        (char)-96,(char)-121,106,55,108,(char)-61,6,101,47,106,1,23,(char)-73,0,(char)-76,(char)-87,(char)-72,120,(char)-15,122,(char)-108,(char)-115,(char)-114,29,74,(char)-121,47,72,32,(char)-66,(char)-9,
        43,121,(char)-88,27,(char)-22,(char)-59,(char)-45,30,(char)-116,(char)-35,90,(char)-16,1,109,1,15,120,(char)-2,120,84,27,60,104,103,(char)-19,(char)-84,97,(char)-99,2,(char)-4,(char)-39,96,38,(char)-120,
        (char)-45,(char)-37,(char)-86,77,(char)-24,13,(char)-119,(char)-11,(char)-85,125,(char)-10,(char)-39,103,90,(char)-50,(char)-89,9,47,126,(char)-15,(char)-117,(char)-25,93,125,(char)-11,(char)-43,
        55,36,(char)-64,(char)-11,105,16,50,(char)-1,(char)-45,(char)-13,(char)-13,53,(char)-13,127,(char)-106,(char)-66,40,45,30,84,(char)-81,9,(char)-88,96,19,24,14,(char)-84,124,75,(char)-113,22,(char)-40,
        64,59,(char)-117,(char)-24,(char)-91,(char)-112,(char)-29,(char)-44,2,(char)-15,97,27,66,(char)-97,67,29,95,(char)-96,103,47,76,(char)-46,(char)-15,(char)-23,81,(char)-66,116,120,20,(char)-76,5,
        60,61,(char)-32,(char)-23,(char)-64,24,21,(char)-84,(char)-15,26,(char)-69,68,(char)-78,(char)-105,31,30,(char)-8,2,(char)-66,(char)-48,(char)-5,104,(char)-105,(char)-124,(char)-75,127,(char)-13,
        104,45,(char)-39,122,(char)-1,(char)-98,103,(char)-125,(char)-118,(char)-45,(char)-37,(char)-24,(char)-56,(char)-63,77,(char)-15,113,9,(char)-104,69,87,(char)-104,86,0,91,109,(char)-75,(char)-43,
        104,(char)-107,85,86,(char)-71,116,(char)-54,(char)-40,(char)-82,1,105,(char)-72,(char)-48,99,63,65,(char)-101,29,(char)-99,106,55,50,113,(char)-55,(char)-109,(char)-4,(char)-36,87,(char)-116,(char)-19,
        98,(char)-107,15,90,114,81,49,(char)-128,(char)-83,(char)-32,(char)-97,120,(char)-77,91,80,11,(char)-117,47,91,(char)-47,106,83,(char)-76,(char)-12,67,90,(char)-10,(char)-94,67,(char)-5,80,(char)-42,
        (char)-41,(char)-48,(char)-105,(char)-82,(char)-4,(char)-16,(char)-67,(char)-99,108,(char)-116,64,111,13,(char)-8,(char)-30,(char)-39,10,116,51,(char)-127,47,(char)-101,(char)-92,91,(char)-69,(char)-38,
        68,57,(char)-103,(char)-37,(char)-119,(char)-52,(char)-58,7,(char)-60,35,23,(char)-24,(char)-118,(char)-97,64,127,(char)-97,113,93,(char)-107,27,(char)-3,(char)-101,122,(char)-37,(char)-76,2,56,
        (char)-27,(char)-108,83,110,77,(char)-27,(char)-71,75,(char)-4,73,57,45,34,104,75,46,(char)-33,26,12,(char)-86,(char)-115,75,(char)-128,(char)-28,(char)-27,(char)-79,115,(char)-76,(char)-14,(char)-54,
        43,(char)-73,(char)-63,(char)-45,(char)-9,(char)-48,(char)-82,(char)-121,(char)-74,(char)-64,(char)-89,(char)-12,18,79,(char)-10,78,29,111,(char)-121,(char)-15,41,123,81,58,24,(char)-54,(char)-91,
        67,11,124,(char)-60,68,(char)-127,30,(char)-19,65,55,(char)-124,(char)-66,123,31,60,31,20,(char)-40,(char)-77,(char)-56,(char)-19,(char)-41,(char)-31,109,2,27,64,63,124,80,62,64,70,(char)-127,30,
        (char)-118,103,35,87,1,56,5,(char)-60,(char)-94,43,(char)-16,1,(char)-78,118,(char)-8,2,(char)-71,80,(char)-10,(char)-56,54,(char)-13,(char)-125,62,(char)-16,(char)-127,15,92,(char)-11,(char)-7,
        (char)-49,127,(char)-34,(char)-69,(char)-98,(char)-88,(char)-26,127,(char)-90,21,64,94,16,(char)-92,(char)-48,(char)-106,(char)-6,113,76,(char)-118,(char)-32,(char)-42,(char)-48,113,(char)-126,(char)-15,
        2,22,(char)-56,58,69,123,(char)-80,39,72,123,11,104,(char)-16,43,(char)-82,(char)-72,98,59,(char)-58,82,88,(char)-45,98,(char)-11,109,(char)-118,(char)-81,120,69,45,(char)-88,(char)-33,(char)-118,
        113,9,(char)-64,(char)-93,22,24,(char)-49,71,95,125,91,(char)-70,(char)-110,(char)-39,10,(char)-91,43,90,126,(char)-20,(char)-91,91,20,(char)-27,91,(char)-13,(char)-62,15,(char)-3,(char)-115,11,
        (char)-116,(char)-111,(char)-35,6,64,11,(char)-43,(char)-25,(char)-80,93,(char)-81,(char)-57,(char)-125,(char)-124,(char)-81,(char)-76,(char)-46,74,35,107,103,19,89,59,125,107,(char)-53,(char)-114,
        86,92,60,(char)-108,30,(char)-33,99,74,63,47,(char)-2,63,(char)-101,59,119,(char)-18,(char)-107,(char)-67,13,63,44,(char)-128,121,23,94,120,33,(char)-25,31,(char)-91,97,(char)-5,(char)-75,112,78,
        (char)-112,0,72,75,98,108,(char)-115,54,69,126,(char)-108,45,(char)-20,120,(char)-89,(char)-85,96,59,(char)-64,36,30,(char)-6,(char)-48,(char)-121,(char)-74,(char)-126,(char)-32,(char)-89,45,63,
        32,3,30,(char)-118,71,45,102,(char)-18,71,(char)-38,(char)-81,(char)-105,61,(char)-30,17,(char)-113,104,(char)-19,45,(char)-82,(char)-109,(char)-128,77,28,(char)-48,14,(char)-43,(char)-90,7,125,
        (char)-55,(char)-59,(char)-93,124,(char)-117,22,79,94,24,(char)-60,41,123,(char)-75,41,29,89,65,26,(char)-109,(char)-15,(char)-27,101,123,(char)-69,4,86,1,84,(char)-69,(char)-98,106,3,(char)-91,
        (char)-21,121,113,37,(char)-37,(char)-87,105,(char)-19,(char)-84,(char)-95,2,(char)-96,47,(char)-1,(char)-30,(char)-121,(char)-19,(char)-54,94,(char)-44,(char)-72,(char)-90,124,(char)-68,4,58,55,
        (char)-105,19,79,120,101,110,116,90,1,(char)-48,(char)-28,(char)-56,(char)-2,85,(char)-24,21,(char)-63,(char)-75,26,67,(char)-8,(char)-106,(char)-16,(char)-30,(char)-55,96,32,64,(char)-113,66,(char)-23,
        77,34,29,(char)-114,84,(char)-78,(char)-55,(char)-96,108,61,(char)-76,3,(char)-70,106,(char)-117,(char)-105,100,(char)-1,(char)-106,(char)-96,118,2,106,49,44,112,(char)-63,(char)-126,87,91,109,10,
        116,64,70,1,63,9,125,(char)-97,(char)-109,(char)-20,(char)-67,(char)-82,(char)-9,(char)-19,22,(char)-74,(char)-71,(char)-112,93,(char)-98,(char)-116,(char)-51,88,37,13,101,(char)-100,(char)-44,127,
        31,(char)-85,(char)-25,(char)-7,91,55,115,(char)-75,102,(char)-88,(char)-5,8,58,(char)-74,30,(char)-30,(char)-10,(char)-24,109,3,(char)-34,91,(char)-35,(char)-71,25,(char)-49,(char)-49,119,(char)-39,
        101,(char)-105,107,6,(char)-74,(char)-23,47,(char)-126,24,(char)-13,36,(char)-32,119,(char)-6,(char)-65,(char)-103,(char)-127,(char)-35,24,(char)-76,29,77,111,(char)-110,104,(char)-127,(char)-83,
        (char)-8,26,72,(char)-55,40,(char)-69,(char)-54,117,35,(char)-13,(char)-80,(char)-121,61,108,(char)-124,(char)-102,12,(char)-33,(char)-103,98,105,35,(char)-7,126,(char)-99,(char)-38,(char)-92,93,
        66,(char)-20,36,(char)-68,19,69,12,118,(char)-117,(char)-83,0,(char)-60,1,(char)-3,13,33,86,(char)-81,(char)-29,(char)-89,(char)-17,(char)-46,(char)-93,(char)-67,(char)-36,(char)-5,14,121,126,116,
        69,(char)-75,5,(char)-78,(char)-72,(char)-58,99,92,126,127,(char)-49,56,21,0,(char)-1,2,31,32,107,(char)-125,(char)-10,(char)-19,123,(char)-99,(char)-71,58,49,115,51,(char)-34,(char)-42,(char)-52,
        (char)-4,(char)-109,(char)-68,113,30,(char)-76,(char)-19,(char)-3,(char)-59,(char)-127,(char)-46,(char)-79,23,(char)-24,(char)-61,(char)-69,(char)-21,(char)-65,50,(char)-4,(char)-91,(char)-41,93,
        119,(char)-35,(char)-76,(char)-105,64,(char)-79,45,88,0,23,92,112,(char)-63,45,7,29,116,16,(char)-37,(char)-49,(char)-4,0,(char)-63,13,44,65,(char)-120,(char)-29,(char)-63,(char)-48,67,(char)-23,
        (char)-15,5,58,(char)-117,(char)-31,20,80,(char)-51,(char)-118,64,1,84,28,126,45,88,126,(char)-32,65,82,45,34,(char)-104,(char)-72,2,16,7,20,(char)-109,88,(char)-12,(char)-114,89,11,(char)-50,95,
        (char)-69,(char)-124,24,(char)-97,80,124,(char)-127,30,5,118,20,(char)-122,60,63,(char)-70,33,122,95,54,126,116,5,(char)-78,(char)-92,(char)-10,(char)-55,55,62,69,(char)-54,(char)-65,(char)-64,15,
        47,(char)-119,104,(char)-51,31,95,16,(char)-77,120,115,(char)-106,124,16,(char)-49,26,(char)-106,93,44,126,69,(char)-121,60,(char)-71,124,(char)-15,16,(char)-39,9,(char)-16,(char)-21,36,(char)-1,
        (char)-116,(char)-109,79,62,121,(char)-38,13,32,(char)-5,2,(char)-105,0,(char)-54,(char)-85,(char)-82,(char)-70,(char)-22,(char)-68,(char)-48,(char)-97,(char)-89,113,(char)-69,17,12,(char)-115,56,
        (char)-1,31,126,54,102,17,63,(char)-8,(char)-125,73,(char)-101,68,21,(char)-128,(char)-54,(char)-90,(char)-121,73,33,50,(char)-56,(char)-10,119,(char)-3,28,125,(char)-38,(char)-15,(char)-23,39,(char)-85,
        8,114,(char)-119,(char)-94,30,41,18,(char)-112,0,(char)-119,40,(char)-65,(char)-94,(char)-100,(char)-16,(char)-128,47,(char)-112,65,(char)-101,(char)-46,(char)-11,(char)-44,(char)-40,(char)-128,
        79,(char)-23,(char)-55,(char)-59,(char)-45,(char)-125,(char)-30,3,(char)-123,8,18,101,(char)-25,(char)-101,115,(char)-7,(char)-94,(char)-38,2,30,(char)-76,69,(char)-127,30,(char)-16,5,107,(char)-12,
        (char)-16,(char)-121,63,(char)-68,93,58,(char)-5,120,125,(char)-69,(char)-14,69,(char)-85,125,(char)-47,9,126,(char)-77,46,(char)-67,(char)-12,(char)-46,(char)-53,(char)-98,(char)-10,(char)-76,(char)-89,
        (char)-3,46,55,(char)-7,(char)-117,62,1,4,77,1,(char)-8,(char)-75,(char)-95,(char)-1,12,(char)-17,105,32,100,(char)-15,63,53,16,84,(char)-75,91,24,9,93,109,(char)-75,(char)-43,70,78,1,119,(char)-75,
        (char)-3,32,(char)-15,22,(char)-46,31,70,112,13,93,117,(char)-43,85,(char)-37,83,(char)-125,(char)-74,98,(char)-128,(char)-34,(char)-7,(char)-95,22,(char)-40,(char)-3,(char)-124,(char)-60,43,0,112,
        34,(char)-120,33,(char)-87,80,(char)-66,(char)-4,(char)-121,(char)-88,120,67,(char)-3,76,109,(char)-24,(char)-127,63,10,(char)-6,54,86,79,40,(char)-6,87,0,10,86,(char)-62,(char)-8,13,81,125,22,21,
        (char)-93,124,(char)-16,64,(char)-74,(char)-5,(char)-83,(char)-111,2,80,(char)-24,78,59,109,38,(char)-127,127,(char)-75,(char)-61,3,63,20,(char)-118,(char)-113,(char)-49,(char)-43,107,(char)-81,
        (char)-67,(char)-10,127,110,(char)-66,(char)-7,(char)-26,11,(char)-20,126,126,19,79,(char)-128,(char)-68,15,(char)-104,(char)-5,(char)-3,(char)-17,127,(char)-33,(char)-17,5,(char)-4,(char)-114,(char)-45,
        36,36,(char)-16,36,117,(char)-45,85,(char)-25,(char)-110,(char)-91,0,76,76,101,(char)-69,(char)-101,119,68,(char)-38,(char)-55,(char)-43,94,(char)-30,(char)-14,120,(char)-46,46,43,38,(char)-51,38,
        (char)-7,2,(char)-15,1,124,(char)-59,(char)-28,47,(char)-55,100,(char)-119,(char)-112,0,5,32,33,(char)-12,124,65,59,(char)-64,15,(char)-95,109,97,104,35,79,106,71,7,(char)-6,(char)-108,112,(char)-3,
        2,(char)-99,(char)-124,41,0,109,(char)-121,96,55,46,20,(char)-122,(char)-10,(char)-110,(char)-115,(char)-57,(char)-79,(char)-33,111,20,107,65,95,62,104,31,99,97,54,126,(char)-79,123,(char)-2,(char)-1,
        121,(char)-14,112,(char)-31,73,39,(char)-99,(char)-28,87,(char)-63,(char)-124,(char)-104,(char)-122,(char)-119,5,(char)-64,35,(char)-115,(char)-49,(char)-56,(char)-64,(char)-49,14,(char)-67,(char)-103,
        60,68,(char)-12,67,(char)-43,88,(char)-42,121,65,50,45,(char)-114,2,(char)-80,(char)-69,87,95,125,(char)-11,(char)-10,87,59,(char)-75,79,(char)-4,(char)-10,(char)-46,68,82,(char)-35,31,(char)-40,
        65,(char)-12,2,85,(char)-5,(char)-30,45,(char)-68,127,101,(char)-28,6,(char)-47,31,79,16,(char)-45,(char)-55,98,(char)-105,(char)-40,(char)-119,(char)-118,0,20,2,(char)-120,93,109,43,(char)-106,
        (char)-40,80,50,123,(char)-127,30,(char)-49,(char)-122,(char)-110,(char)-127,44,(char)-106,49,26,(char)-125,62,36,30,20,(char)-73,121,(char)-95,(char)-38,0,127,20,(char)-76,7,(char)-4,76,96,(char)-73,
        70,54,73,(char)-83,(char)-113,19,(char)-50,(char)-68,(char)-24,(char)-85,29,63,40,(char)-71,(char)-24,36,93,(char)-39,50,(char)-106,(char)-101,19,(char)-29,(char)-110,(char)-93,(char)-114,58,(char)-54,
        83,(char)-99,98,40,(char)-45,(char)-104,(char)-50,88,0,(char)-7,(char)-34,(char)-8,(char)-106,52,62,45,(char)-98,(char)-41,6,(char)-29,(char)-113,14,19,120,44,15,(char)-103,(char)-78,(char)-15,99,
        75,(char)-116,(char)-10,(char)-73,120,29,(char)-3,78,(char)-128,71,62,(char)-14,(char)-111,(char)-19,82,(char)-112,(char)-86,108,(char)-41,113,(char)-69,(char)-33,100,37,(char)-108,(char)-81,118,
        21,67,123,(char)-117,47,(char)-63,(char)-2,(char)-67,60,106,(char)-9,89,40,(char)-89,(char)-123,(char)-45,68,17,(char)-120,45,65,10,68,98,(char)-8,72,22,104,47,(char)-114,(char)-104,(char)-128,95,
        24,(char)-8,20,(char)-60,4,5,37,(char)-15,(char)-6,7,125,(char)-24,(char)-45,24,(char)-52,(char)-61,(char)-104,(char)-59,(char)-44,14,29,(char)-94,(char)-20,40,12,(char)-19,(char)-26,109,109,30,
        (char)-3,(char)-24,71,(char)-113,(char)-52,(char)-51,(char)-68,108,8,122,(char)-2,125,92,50,12,99,(char)-52,32,95,(char)-107,24,95,(char)-49,(char)-70,(char)-4,102,6,(char)-5,(char)-126,79,1,(char)-27,
        120,(char)-38,105,(char)-89,93,115,(char)-2,(char)-7,(char)-25,(char)-69,25,(char)-68,(char)-92,116,104,13,(char)-90,104,58,(char)-96,110,24,14,(char)-116,12,22,(char)-55,(char)-18,86,(char)-39,
        78,0,(char)-109,(char)-108,36,(char)-69,(char)-39,100,85,63,(char)-65,22,100,(char)-22,71,45,(char)-68,(char)-60,(char)-125,(char)-29,80,12,(char)-57,45,(char)-1,(char)-22,23,85,4,(char)-110,(char)-95,
        (char)-112,36,75,(char)-110,64,(char)-46,(char)-56,(char)-96,16,20,(char)-124,(char)-72,120,(char)-29,71,11,(char)-28,(char)-78,(char)-95,(char)-58,7,(char)-110,45,86,22,(char)-79,(char)-3,59,61,
        126,(char)-114,106,5,107,(char)-25,(char)-21,(char)-33,(char)-112,(char)-23,(char)-47,30,116,(char)-3,(char)-68,(char)-56,(char)-48,(char)-5,88,(char)-101,90,(char)-105,71,61,(char)-22,81,35,55,
        (char)-52,(char)-26,71,(char)-81,109,65,59,(char)-24,(char)-37,46,(char)-116,79,59,47,(char)-12,(char)-82,(char)-67,(char)-14,(char)-54,43,(char)-67,0,(char)-14,(char)-53,(char)-66,19,(char)-35,
        103,60,1,(char)-30,125,123,38,(char)-7,(char)-61,116,(char)-22,50,(char)-16,(char)-69,4,(char)-116,106,(char)-6,(char)-121,(char)-50,2,(char)-46,(char)-58,(char)-81,61,(char)-118,(char)-31,(char)-23,
        1,79,(char)-113,(char)-105,28,(char)-55,78,(char)-52,(char)-10,127,(char)-35,(char)-106,12,73,(char)-109,84,(char)-117,(char)-56,(char)-121,47,88,116,11,(char)-18,101,(char)-112,100,88,112,59,78,
        123,(char)-66,124,64,(char)-4,106,103,(char)-57,40,4,(char)-15,45,(char)-98,(char)-92,87,(char)-30,(char)-60,3,9,5,125,(char)-77,(char)-9,(char)-96,39,43,26,(char)-66,(char)-43,86,(char)-111,(char)-46,
        (char)-119,105,(char)-84,(char)-118,23,37,(char)-21,127,38,(char)-44,(char)-72,106,(char)-100,(char)-109,(char)-4,(char)-8,88,23,(char)-89,(char)-30,26,107,(char)-84,49,82,(char)-36,(char)-26,(char)-88,
        (char)-80,(char)-40,(char)-86,13,30,(char)-56,(char)-61,120,67,(char)-103,(char)-49,20,(char)-26,102,(char)-83,(char)-66,124,(char)-20,(char)-79,(char)-57,(char)-2,100,(char)-46,(char)-35,(char)-1,
        (char)-108,(char)-49,(char)-52,39,0,(char)-121,(char)-67,(char)-9,(char)-34,(char)-5,(char)-6,76,(char)-12,43,(char)-31,(char)-81,10,(char)-58,(char)-41,(char)-112,26,76,116,(char)-19,(char)-26,
        (char)-83,40,61,24,20,(char)-48,23,(char)-24,127,(char)-1,(char)-5,(char)-33,(char)-113,(char)-14,(char)-98,97,(char)-28,79,(char)-94,74,(char)-84,(char)-119,38,126,115,81,72,18,(char)-29,(char)-17,
        9,88,124,(char)-112,116,11,110,(char)-111,(char)-100,0,98,(char)-126,6,(char)-30,(char)-95,(char)-128,47,(char)-40,61,10,65,91,(char)-15,(char)-7,75,104,(char)-59,85,88,5,(char)-55,(char)-43,15,
        59,29,(char)-66,116,(char)-110,(char)-82,(char)-83,(char)-66,93,(char)-25,21,(char)-85,(char)-72,(char)-6,(char)-47,39,(char)-80,3,126,8,(char)-13,(char)-31,(char)-37,(char)-93,124,(char)-86,(char)-115,
        (char)-94,53,(char)-65,(char)-57,60,(char)-26,49,35,(char)-57,(char)-65,(char)-109,64,113,37,113,(char)-27,58,(char)-34,84,99,69,(char)-104,106,31,118,(char)-30,71,(char)-97,49,(char)-36,(char)-102,
        (char)-79,(char)-1,(char)-25,97,(char)-121,29,54,(char)-19,18,30,(char)-3,(char)-76,(char)-49,(char)-62,78,(char)-128,(char)-111,(char)-89,(char)-127,31,(char)-1,(char)-8,(char)-57,(char)-105,(char)-91,
        (char)-59,41,(char)-23,(char)-44,27,(char)-91,(char)-80,(char)-13,63,83,(char)-99,52,(char)-95,(char)-8,(char)-8,52,121,(char)-8,(char)-125,(char)-35,(char)-1,18,(char)-26,(char)-20,(char)-77,(char)-49,
        30,(char)-99,126,(char)-6,(char)-23,35,55,113,18,101,(char)-94,22,74,(char)-30,37,(char)-63,(char)-93,32,89,(char)-78,29,(char)-123,(char)-110,40,(char)-106,(char)-10,5,125,(char)-32,(char)-23,(char)-95,
        (char)-105,75,(char)-81,(char)-88,(char)-60,(char)-105,48,(char)-112,60,(char)-96,87,120,96,(char)-73,(char)-125,(char)-99,47,(char)-7,(char)-6,5,69,35,9,(char)-107,116,73,(char)-95,(char)-125,(char)-118,
        95,(char)-3,86,(char)-33,104,15,(char)-10,(char)-123,65,28,(char)-55,55,(char)-74,(char)-57,62,(char)-10,(char)-79,35,5,96,(char)-9,(char)-101,(char)-81,(char)-71,(char)-77,(char)-9,(char)-19,(char)-115,
        75,124,58,20,(char)-16,(char)-128,(char)-17,49,(char)-91,(char)-69,41,(char)-70,(char)-1,60,(char)-4,(char)-16,(char)-61,47,(char)-120,60,(char)-34,(char)-72,(char)-31,23,(char)-8,44,(char)-76,0,
        120,39,17,23,39,(char)-40,89,(char)-31,(char)-49,15,22,(char)-8,(char)-60,(char)-42,116,53,(char)-24,(char)-110,41,(char)-15,6,47,(char)-7,103,(char)-98,121,(char)-26,40,111,(char)-94,70,(char)-66,
        (char)-32,(char)-111,28,118,(char)-119,(char)-73,(char)-21,(char)-64,(char)-50,115,(char)-4,89,4,(char)-80,(char)-32,124,42,6,30,(char)-86,31,124,(char)-127,15,30,45,59,(char)-86,(char)-64,(char)-60,
        (char)-47,(char)-97,(char)-40,22,(char)-68,18,(char)-21,121,91,114,1,(char)-49,(char)-98,(char)-71,(char)-114,20,10,72,(char)-124,(char)-74,(char)-30,(char)-118,(char)-123,86,124,50,(char)-120,79,
        15,(char)-28,(char)-98,(char)-30,(char)-7,(char)-9,(char)-96,3,(char)-19,(char)-12,87,(char)-55,119,95,68,86,20,21,(char)-121,31,104,(char)-113,2,(char)-98,29,(char)-56,(char)-128,(char)-121,(char)-30,
        67,37,(char)-36,(char)-55,125,98,(char)-82,(char)-1,54,111,84,51,127,22,89,0,7,30,120,(char)-96,23,8,95,72,39,63,77,(char)-104,(char)-10,(char)-3,64,104,(char)-5,24,16,(char)-90,40,(char)-66,64,
        103,(char)-89,121,(char)-69,119,(char)-22,(char)-87,(char)-89,(char)-114,(char)-66,(char)-14,(char)-107,(char)-81,(char)-76,71,62,(char)-109,(char)-28,(char)-29,(char)-120,101,(char)-105,16,(char)-57,
        32,(char)-72,126,91,116,11,(char)-60,39,125,(char)-114,47,49,10,9,(char)-60,5,(char)-10,33,(char)-8,15,117,(char)-28,(char)-46,(char)-117,43,(char)-79,(char)-58,(char)-128,71,115,76,(char)-114,(char)-118,
        (char)-46,57,37,(char)-86,77,(char)-75,35,(char)-9,(char)-88,(char)-2,(char)-117,(char)-106,31,58,68,(char)-33,(char)-82,120,5,(char)-26,(char)-102,(char)-65,(char)-42,90,107,(char)-115,80,69,104,
        28,(char)-6,(char)-42,(char)-66,(char)-30,(char)-14,39,67,(char)-15,61,(char)-59,23,(char)-54,39,(char)-14,13,(char)-31,(char)-65,27,122,(char)-10,71,63,(char)-6,(char)-47,(char)-10,(char)-53,(char)-67,
        (char)-31,103,(char)-4,44,(char)-78,0,(char)-4,2,(char)-63,(char)-37,(char)-33,(char)-2,(char)-10,(char)-71,(char)-39,(char)-83,(char)-97,(char)-56,2,(char)-115,(char)-3,(char)-5,65,(char)-118,62,
        (char)-108,51,(char)-120,(char)-111,(char)-93,(char)-43,(char)-82,87,0,118,121,37,80,(char)-14,37,(char)-4,25,(char)-49,120,(char)-58,(char)-24,89,(char)-49,122,86,(char)-61,19,(char)-98,(char)-16,
        (char)-124,(char)-10,(char)-27,(char)-121,88,(char)-38,(char)-90,47,108,(char)-69,6,(char)-110,11,77,(char)-103,31,(char)-28,(char)-112,113,(char)-127,(char)-108,76,55,(char)-124,(char)-79,(char)-79,
        67,111,91,28,121,(char)-24,35,86,(char)-59,96,(char)-21,101,122,50,(char)-32,39,(char)-63,41,(char)-28,110,(char)-1,113,(char)-113,123,(char)-36,(char)-8,(char)-24,(char)-81,(char)-62,23,79,(char)-101,
        (char)-94,(char)-8,33,38,(char)-39,(char)-24,32,(char)-66,118,(char)-65,(char)-101,(char)-65,47,(char)-99,117,(char)-42,89,23,70,94,(char)-28,103,(char)-100,(char)-48,(char)-123,121,(char)-90,(char)-110,
        110,56,(char)-18,(char)-72,(char)-29,(char)-50,(char)-55,(char)-60,62,(char)-63,47,20,(char)-103,(char)-120,(char)-87,(char)-127,(char)-116,(char)-4,(char)-23,(char)-13,19,78,56,97,(char)-12,(char)-125,
        31,(char)-4,(char)-96,93,(char)-13,(char)-19,118,73,85,(char)-27,79,127,(char)-6,(char)-45,71,47,122,(char)-47,(char)-117,70,47,124,(char)-31,11,71,127,(char)-3,(char)-41,127,61,(char)-110,(char)-4,
        117,(char)-42,89,(char)-89,(char)-19,6,11,36,126,(char)-59,41,(char)-86,51,60,(char)-32,(char)-7,(char)-96,5,50,(char)-108,60,19,(char)-83,(char)-10,(char)-20,61,79,(char)-66,(char)-77,88,88,127,
        (char)-61,(char)-40,(char)-26,(char)-18,(char)-46,(char)-26,(char)-114,63,(char)-81,102,71,107,(char)-82,(char)-71,(char)-26,(char)-56,(char)-77,63,(char)-99,19,(char)-120,125,(char)-90,(char)-2,
        43,86,(char)-47,(char)-95,(char)-97,113,64,(char)-12,(char)-41,(char)-121,126,53,27,(char)-19,(char)-116,(char)-25,63,(char)-1,(char)-7,51,62,(char)-6,(char)-59,111,(char)-4,89,(char)-84,2,(char)-32,
        (char)-3,(char)-26,55,(char)-65,(char)-7,23,(char)-71,(char)-125,(char)-1,118,120,(char)-9,3,33,(char)-13,63,(char)-3,(char)-96,(char)-118,(char)-9,127,2,(char)-77,(char)-21,93,(char)-9,21,66,6,
        (char)-43,126,(char)-69,(char)-59,113,(char)-25,(char)-21,(char)-26,109,(char)-73,(char)-35,118,(char)-76,(char)-39,102,(char)-101,(char)-115,92,3,29,127,94,127,90,20,69,80,119,(char)-61,98,(char)-63,
        (char)-4,94,(char)-26,(char)-1,(char)-52,(char)-60,(char)-38,(char)-119,64,42,(char)-101,(char)-40,100,40,29,30,122,(char)-71,(char)-4,(char)-118,(char)-78,23,(char)-49,(char)-81,64,15,(char)-28,
        (char)-78,(char)-109,(char)-127,14,(char)-16,(char)-128,47,(char)-112,(char)-121,96,(char)-93,(char)-109,92,73,54,(char)-33,117,(char)-41,93,119,(char)-12,(char)-8,(char)-57,63,(char)-66,37,(char)-33,
        61,7,125,(char)-7,(char)-15,(char)-59,3,30,(char)-118,47,74,55,28,23,29,(char)-60,(char)-25,(char)-90,(char)-12,117,(char)-30,119,(char)-66,(char)-13,(char)-99,(char)-117,(char)-56,(char)-117,(char)-125,
        (char)-59,46,(char)-128,4,(char)-101,(char)-105,(char)-57,(char)-62,(char)-17,(char)-123,126,63,24,63,90,(char)-12,(char)-125,(char)-111,(char)-96,124,(char)-111,52,(char)-54,(char)-9,8,(char)-93,
        47,125,(char)-23,75,(char)-19,113,(char)-49,53,93,114,(char)-13,101,(char)-60,(char)-24,85,(char)-81,122,(char)-43,8,(char)-75,0,(char)-12,25,108,123,45,(char)-84,8,(char)-20,6,(char)-6,39,62,(char)-15,
        (char)-119,(char)-83,48,(char)-100,4,(char)-82,(char)-41,(char)-23,107,(char)-4,(char)-55,4,(char)-37,111,6,(char)-95,125,(char)-65,28,(char)-24,(char)-118,22,(char)-49,(char)-89,(char)-64,(char)-122,
        71,123,12,125,(char)-39,(char)-8,(char)-103,11,74,30,(char)-94,(char)-38,(char)-108,(char)-98,31,(char)-108,(char)-116,(char)-110,(char)-127,(char)-81,27,60,(char)-89,(char)-100,(char)-28,91,11,
        115,53,103,(char)-13,115,34,(char)-14,(char)-47,(char)-90,(char)-88,118,100,(char)-104,(char)-119,103,(char)-21,(char)-111,(char)-74,(char)-41,69,(char)-2,(char)-12,(char)-47,71,31,(char)-3,31,(char)-39,
        100,(char)-2,10,72,(char)-60,69,127,(char)-18,76,1,120,(char)-124,(char)-5,(char)-27,94,123,(char)-19,(char)-11,(char)-123,(char)-124,29,(char)-65,29,(char)-20,7,104,(char)-47,(char)-36,(char)-20,
        (char)-3,(char)-53,(char)-65,(char)-4,75,(char)-5,90,(char)-41,(char)-29,(char)-51,(char)-42,91,111,61,(char)-6,(char)-37,(char)-65,(char)-3,(char)-37,(char)-47,75,95,(char)-6,(char)-46,118,(char)-51,
        51,(char)-15,(char)-76,31,127,50,(char)-16,(char)-111,27,32,(char)-69,(char)-63,(char)-15,(char)-24,(char)-38,(char)-88,8,20,3,29,27,31,13,(char)-118,(char)-30,(char)-121,48,(char)-114,30,101,(char)-41,
        6,74,46,74,7,125,(char)-101,(char)-30,(char)-23,11,(char)-27,(char)-113,(char)-106,29,37,(char)-13,41,90,60,(char)-71,64,(char)-25,(char)-15,(char)-18,73,79,122,82,(char)-69,(char)-52,73,(char)-66,
        59,126,107,(char)-32,81,(char)-45,6,40,95,84,92,(char)-64,23,(char)-60,40,30,29,(char)-38,(char)-23,(char)-30,115,123,48,(char)-9,(char)-29,31,(char)-1,(char)-8,(char)-105,(char)-14,(char)-46,(char)-57,
        123,127,(char)-22,(char)-59,(char)-62,(char)-99,42,0,17,(char)-113,57,(char)-26,(char)-104,(char)-81,124,(char)-26,51,(char)-97,57,57,3,(char)-15,114,(char)-120,(char)-86,(char)-63,77,(char)-34,
        39,63,(char)-7,(char)-55,(char)-47,23,(char)-65,(char)-8,(char)-59,38,111,(char)-71,(char)-27,(char)-106,(char)-93,(char)-105,(char)-67,(char)-20,101,(char)-93,23,(char)-68,(char)-32,5,(char)-93,
        77,55,(char)-35,(char)-76,125,31,(char)-96,(char)-30,51,(char)-48,102,(char)-81,31,22,(char)-63,46,112,20,90,24,55,72,(char)-110,(char)-81,8,(char)-64,(char)-126,41,2,62,(char)-43,6,21,7,(char)-16,
        119,6,25,(char)-9,(char)-8,50,(char)-46,(char)-13,98,25,11,84,60,58,40,(char)-71,(char)-89,(char)-12,(char)-38,(char)-45,21,(char)-59,(char)-125,24,(char)-32,58,(char)-65,(char)-34,122,(char)-21,
        (char)-75,(char)-28,(char)-69,(char)-29,55,55,39,91,37,95,12,(char)-2,(char)-123,97,(char)-100,(char)-78,(char)-45,(char)-37,92,(char)-27,55,(char)-127,(char)-2,38,(char)-10,35,(char)-14,94,(char)-29,
        (char)-12,9,(char)-74,(char)-123,(char)-86,(char)-18,116,1,(char)-120,(char)-10,(char)-90,55,(char)-67,(char)-23,(char)-96,(char)-13,(char)-50,59,(char)-17,(char)-100,12,(char)-16,(char)-106,96,
        (char)-28,(char)-1,112,113,(char)-4,(char)-15,(char)-57,(char)-113,46,(char)-65,(char)-4,(char)-14,(char)-111,(char)-124,(char)-67,(char)-31,13,111,104,59,(char)-2,47,(char)-2,(char)-30,47,(char)-38,
        (char)-75,78,27,(char)-109,0,60,104,7,(char)-59,75,(char)-80,34,112,92,58,34,(char)-35,15,88,60,(char)-69,103,(char)-19,(char)-75,(char)-41,110,(char)-65,32,97,81,(char)-7,23,(char)-6,120,(char)-91,
        67,(char)-59,5,(char)-4,16,(char)-91,(char)-81,(char)-74,(char)-67,92,(char)-70,106,67,(char)-122,(char)-110,23,(char)-121,(char)-70,(char)-76,73,(char)-14,(char)-109,(char)-97,(char)-4,(char)-28,
        (char)-111,(char)-79,43,98,(char)-123,(char)-32,116,51,(char)-73,42,(char)-26,(char)-22,(char)-73,98,(char)-110,(char)-95,(char)-28,(char)-98,(char)-46,67,(char)-23,(char)-6,49,69,127,67,(char)-28,
        75,63,(char)-8,(char)-63,15,(char)-98,(char)-102,(char)-35,127,(char)-89,127,127,(char)-29,46,21,64,6,50,47,55,(char)-123,123,(char)-122,(char)-34,(char)-106,(char)-73,119,(char)-73,(char)-25,(char)-26,
        (char)-80,61,75,111,(char)-78,(char)-55,38,35,(char)-1,99,(char)-126,45,(char)-74,(char)-40,(char)-94,125,(char)-29,39,(char)-95,(char)-15,(char)-103,(char)-10,(char)-55,96,23,(char)-112,75,(char)-89,
        8,44,(char)-96,(char)-57,34,(char)-17,(char)-1,(char)-35,52,41,2,(char)-117,105,33,93,82,(char)-68,(char)-44,(char)-55,(char)-92,91,(char)-116,(char)-98,22,(char)-49,32,30,(char)-32,39,(char)-95,
        (char)-9,(char)-59,(char)-9,(char)-66,(char)-39,73,(char)-19,(char)-47,114,(char)-88,(char)-97,20,(char)-89,(char)-41,57,(char)-35,36,(char)-40,46,31,(char)-114,(char)-39,35,(char)-81,103,127,115,
        51,(char)-57,106,(char)-89,(char)-113,(char)-30,(char)-5,126,75,103,92,(char)-123,(char)-46,(char)-95,93,(char)-69,91,99,(char)-65,48,111,51,(char)-33,113,(char)-47,69,23,(char)-3,(char)-112,(char)-19,
        (char)-50,(char)-30,(char)-82,22,(char)-64,(char)-24,(char)-100,115,(char)-50,57,123,(char)-113,61,(char)-10,(char)-8,(char)-89,12,(char)-4,118,111,(char)-46,(char)-98,(char)-6,(char)-44,(char)-89,
        (char)-114,118,(char)-40,97,7,(char)-1,(char)-78,(char)-88,(char)-35,(char)-88,(char)-11,3,(char)-55,32,(char)-57,(char)-57,(char)-18,80,63,(char)-108,77,(char)-50,66,41,2,47,(char)-119,(char)-20,
        28,55,79,(char)-21,(char)-81,(char)-65,(char)-2,8,20,(char)-126,39,(char)-123,42,4,(char)-2,98,84,31,40,25,(char)-40,122,(char)-48,65,(char)-23,(char)-16,(char)-4,(char)-55,120,20,(char)-16,(char)-91,
        47,(char)-103,(char)-82,64,87,118,(char)-89,(char)-110,(char)-28,74,(char)-78,113,62,(char)-27,41,79,25,(char)-127,83,(char)-53,83,(char)-113,66,(char)-10,(char)-88,(char)-57,79,(char)-69,(char)-118,
        (char)-95,61,(char)-112,(char)-23,1,95,58,124,(char)-113,(char)-46,(char)-13,3,(char)-74,(char)-24,46,(char)-55,(char)-91,(char)-9,127,(char)-27,68,62,(char)-49,(char)-5,26,(char)-70,59,(char)-117,
        (char)-69,92,0,58,(char)-6,(char)-52,103,62,(char)-13,(char)-79,60,(char)-21,127,52,119,(char)-72,(char)-73,(char)-102,60,93,15,3,5,(char)-70,33,(char)-91,27,(char)-126,79,(char)-63,78,(char)-103,
        61,123,118,59,(char)-6,45,(char)-82,(char)-45,(char)-64,(char)-111,(char)-70,(char)-31,(char)-122,27,(char)-74,5,86,8,22,(char)-40,(char)-30,(char)-13,(char)-75,(char)-64,21,47,11,(char)-45,118,
        49,10,(char)-91,23,27,79,7,120,(char)-70,2,29,(char)-98,30,(char)-16,116,(char)-8,2,29,24,(char)-101,34,53,6,(char)-105,43,(char)-29,114,(char)-55,(char)-109,124,71,(char)-66,(char)-53,(char)-104,
        (char)-79,41,(char)-44,26,(char)-97,118,(char)-61,56,(char)-91,43,90,(char)-10,(char)-98,(char)-78,(char)-43,(char)-4,(char)-90,(char)-58,(char)-29,(char)-123,(char)-49,127,(char)-59,(char)-25,(char)-37,
        (char)-39,(char)-7,(char)-1,45,(char)-84,3,102,0,0,10,(char)-36,73,68,65,84,(char)-102,(char)-28,(char)-29,35,(char)-34,(char)-7,(char)-49,(char)-35,42,0,(char)-35,(char)-27,45,(char)-31,(char)-82,
        (char)-7,(char)-62,(char)-24,(char)-76,12,(char)-78,(char)-3,(char)-26,80,104,91,124,(char)-74,2,93,(char)-15,83,19,(char)-104,(char)-15,68,40,95,(char)-44,(char)-92,(char)-99,6,(char)-114,86,(char)-89,
        (char)-63,(char)-22,(char)-85,(char)-81,62,(char)-14,(char)-108,(char)-32,(char)-110,96,(char)-63,(char)-99,8,(char)-118,(char)-126,(char)-50,41,36,41,(char)-4,(char)-75,(char)-85,(char)-2,80,125,
        2,30,(char)-122,124,78,(char)-79,(char)-15,63,63,103,(char)-125,(char)-95,(char)-97,(char)-15,(char)-72,(char)-92,(char)-71,(char)-122,43,72,(char)-119,(char)-105,108,48,22,(char)-57,(char)-66,66,
        112,98,25,(char)-117,93,63,(char)-45,88,(char)-60,6,(char)-3,(char)-12,(char)-96,3,125,(char)-11,20,(char)-49,15,(char)-99,(char)-62,45,(char)-111,(char)-65,(char)-107,(char)-35,(char)-1,(char)-31,
        (char)-49,125,(char)-18,115,119,(char)-22,(char)-82,127,(char)-86,(char)-3,(char)-104,(char)-36,(char)-19,2,16,41,71,(char)-48,(char)-21,51,32,(char)-65,117,50,(char)-2,(char)-121,(char)-121,53,
        (char)-119,(char)-24,(char)-71,44,22,(char)-86,77,79,37,(char)-45,14,(char)-110,92,55,87,30,(char)-85,92,103,61,41,40,(char)-128,(char)-115,54,(char)-38,104,(char)-76,(char)-63,6,27,(char)-76,(char)-53,
        (char)-125,(char)-62,112,82,56,118,61,81,(char)-40,(char)-95,(char)-110,38,70,(char)-59,52,(char)-112,(char)-98,47,(char)-71,(char)-9,(char)-63,67,(char)-11,(char)-85,111,47,(char)-85,92,122,(char)-12,
        1,125,(char)-65,(char)-58,(char)-62,86,(char)-119,(char)-41,(char)-89,(char)-74,98,(char)-120,63,(char)-124,53,81,116,104,(char)-39,106,76,67,90,(char)-10,(char)-114,(char)-34,(char)-106,(char)-74,
        39,(char)-25,(char)-117,(char)-98,(char)-49,110,(char)-65,(char)-3,(char)-10,63,(char)-51,83,(char)-39,120,(char)-51,59,(char)-97,(char)-59,102,(char)-105,72,1,(char)-28,(char)-119,(char)-32,(char)-36,
        (char)-36,20,(char)-18,(char)-111,(char)-63,123,63,(char)-112,121,(char)-35,(char)-34,118,120,(char)-104,54,(char)-112,(char)-24,27,(char)-99,(char)-12,(char)-93,(char)-73,(char)-107,127,(char)-7,
        (char)-79,(char)-107,(char)-50,98,(char)-70,(char)-47,(char)-110,12,71,(char)-85,(char)-59,86,8,118,127,37,68,82,(char)-36,(char)-120,(char)-2,(char)-27,95,(char)-2,(char)-91,(char)-1,67,(char)-42,
        (char)-56,(char)-114,116,28,(char)-37,(char)-107,118,(char)-83,(char)-94,112,(char)-102,40,36,59,(char)-44,(char)-15,12,18,38,38,(char)-67,(char)-72,(char)-118,(char)-84,78,27,49,54,(char)-34,120,
        (char)-29,(char)-111,93,46,(char)-82,62,20,(char)-100,75,(char)-112,(char)-60,27,(char)-125,(char)-126,(char)-45,(char)-42,(char)-23,96,(char)-41,75,(char)-66,(char)-79,(char)-9,(char)-13,(char)-24,
        (char)-27,94,95,124,(char)-51,(char)-109,(char)-116,(char)-17,105,18,78,4,119,(char)-4,78,(char)-37,19,50,(char)-122,111,(char)-100,123,(char)-18,(char)-71,(char)-117,(char)-11,(char)-70,87,(char)-61,
        (char)-103,(char)-80,68,10,64,(char)-16,(char)-68,(char)-4,(char)-7,(char)-33,(char)-87,(char)-58,(char)-93,(char)-61,79,123,22,53,(char)-15,(char)-102,80,108,(char)-29,15,61,(char)-116,21,83,76,
        (char)-17,(char)-37,(char)-13,83,(char)-26,118,121,(char)-79,(char)-56,10,65,50,(char)-67,44,(char)-78,59,29,(char)-55,(char)-18,67,20,(char)-125,107,(char)-79,(char)-124,41,6,(char)-88,(char)-60,
        73,30,56,(char)-82,123,(char)-16,37,59,81,(char)-86,(char)-83,(char)-101,90,(char)-119,71,(char)-39,(char)-23,(char)-7,(char)-72,(char)-71,115,(char)-54,(char)-72,(char)-58,(char)-69,44,41,36,99,
        (char)-111,116,69,90,(char)-29,44,106,14,80,114,(char)-47,126,(char)-18,120,(char)-32,7,124,80,58,60,26,(char)-8,21,(char)-81,107,(char)-94,63,(char)-6,(char)-69,(char)-33,(char)-3,(char)-18,(char)-119,
        100,(char)-74,(char)-69,(char)-117,37,86,0,6,(char)-110,(char)-73,(char)-124,31,(char)-54,(char)-73,80,(char)-57,101,33,(char)-68,50,110,(char)-55,(char)-54,(char)-128,(char)-103,26,50,(char)-24,
        70,(char)-23,10,77,(char)-79,(char)-120,31,(char)-109,124,(char)-59,74,63,35,(char)-59,(char)-32,(char)-88,(char)-73,3,(char)-19,68,59,93,49,72,(char)-108,(char)-35,(char)-21,30,(char)-95,(char)-82,
        (char)-45,18,(char)-86,0,(char)-86,40,36,23,(char)-24,(char)-23,(char)-128,(char)-99,(char)-84,(char)-115,98,18,(char)-61,78,(char)-9,8,42,(char)-23,78,8,(char)-89,(char)-123,62,(char)-99,28,78,
        37,(char)-29,(char)-128,(char)-102,(char)-122,(char)-15,22,111,(char)-100,(char)-109,(char)-8,(char)-46,21,(char)-19,(char)-37,(char)-48,(char)-11,(char)-19,(char)-56,(char)-79,95,(char)-104,111,
        100,95,(char)-9,(char)-23,79,127,(char)-6,(char)-117,121,(char)-43,(char)-21,121,127,(char)-127,127,(char)-28,(char)-63,(char)-17,(char)-50,98,(char)-119,22,(char)-128,(char)-50,(char)-33,(char)-6,
        (char)-42,(char)-73,30,(char)-105,55,82,71,(char)-123,(char)-9,11,36,109,(char)-112,53,(char)-103,76,34,(char)-22,(char)-55,(char)-97,(char)-78,(char)-107,111,81,(char)-34,120,(char)-64,67,(char)-15,
        (char)-88,(char)-123,71,(char)-19,64,9,(char)-79,27,(char)-99,12,(char)-96,32,(char)-100,14,46,1,(char)-118,66,18,31,(char)-105,(char)-81,97,37,21,(char)-107,88,(char)-88,98,113,(char)-71,(char)-80,
        (char)-69,(char)-7,(char)-69,4,40,38,9,119,(char)-54,72,(char)-72,(char)-40,10,(char)-82,(char)-110,(char)-82,(char)-33,26,119,81,(char)-29,(char)-125,94,(char)-26,55,(char)-44,(char)-79,67,(char)-81,
        47,63,(char)-108,13,(char)-16,(char)-15,(char)-7,94,(char)-98,(char)-11,(char)-33,(char)-103,(char)-53,(char)-20,(char)-23,(char)-7,62,(char)-58,59,(char)-1,(char)-88,(char)-106,(char)-52,103,(char)-119,
        23,(char)-64,(char)-39,103,(char)-97,125,85,6,(char)-6,(char)-83,124,(char)-3,(char)-5,(char)-42,76,(char)-32,(char)-41,25,(char)-26,13,(char)-63,(char)-116,(char)-97,(char)-8,52,(char)-101,(char)-119,
        2,(char)-95,40,126,81,(char)-32,11,(char)-27,(char)-89,16,64,(char)-94,92,(char)-109,(char)-63,117,94,2,29,(char)-41,118,(char)-81,(char)-30,(char)-112,(char)-44,30,(char)-12,78,17,54,126,(char)-4,
        37,92,81,(char)-119,87,73,(char)-81,(char)-126,(char)-85,(char)-2,122,(char)-38,(char)-113,(char)-93,(char)-41,(char)-101,35,(char)-108,(char)-82,(char)-4,(char)-118,(char)-46,(char)-29,123,31,(char)-70,
        (char)-64,(char)-29,(char)-34,(char)-9,(char)-78,(char)-90,(char)-57,(char)-27,(char)-5,(char)-108,111,(char)-28,43,121,55,(char)-38,81,47,(char)-71,(char)-49,18,47,0,67,51,(char)-48,99,(char)-113,
        61,(char)-10,59,(char)-71,121,(char)-39,51,19,(char)-13,(char)-11,(char)-15,109,(char)-12,61,(char)-94,111,(char)-105,(char)-120,(char)-46,(char)-111,(char)-15,(char)-73,(char)-33,126,(char)-57,
        13,36,(char)-98,110,113,80,(char)-19,123,95,58,9,(char)-109,(char)-68,74,34,30,20,8,72,112,47,(char)-13,3,(char)-19,64,12,(char)-88,(char)-72,(char)-58,(char)-44,99,104,(char)-29,87,(char)-70,(char)-14,
        (char)-93,(char)-21,(char)-111,117,(char)-23,(char)-59,(char)-58,(char)-9,58,(char)-19,(char)-94,(char)-12,55,125,(char)-50,(char)-49,125,(char)-43,(char)-79,(char)-7,62,(char)-27,(char)-88,20,(char)-63,
        (char)-76,(char)-17,94,98,95,34,(char)-97,123,(char)-92,0,(char)-116,(char)-52,81,117,(char)-22,(char)-87,(char)-89,(char)-98,(char)-104,(char)-55,(char)-72,49,(char)-12,13,(char)-94,(char)-9,4,
        (char)-66,(char)-75,90,32,(char)-15,(char)-3,(char)-126,105,(char)-69,(char)-72,(char)-80,104,(char)-119,(char)-33,(char)-98,56,(char)-76,(char)-87,56,120,40,27,(char)-54,86,9,45,74,(char)-57,(char)-81,
        104,(char)-15,100,40,25,(char)-19,33,30,(char)-71,124,(char)-122,124,(char)-39,(char)-23,11,124,11,(char)-91,27,(char)-46,(char)-82,(char)-35,(char)-51,(char)-103,(char)-37,(char)-107,121,(char)-68,
        62,(char)-64,125,(char)-43,(char)-48,111,73,(char)-54,(char)-9,88,1,24,100,110,86,110,(char)-56,(char)-115,(char)-45,(char)-15,(char)-65,(char)-3,(char)-19,111,63,(char)-98,(char)-55,31,31,(char)-99,
        63,62,17,50,(char)-1,(char)-45,77,(char)-72,37,(char)-79,100,20,(char)-26,123,(char)-115,90,(char)-63,(char)-92,(char)-3,(char)-88,(char)-2,43,(char)-37,80,87,122,126,108,5,122,(char)-56,(char)-94,
        50,(char)-51,8,(char)-2,51,26,59,3,63,(char)-24,84,109,(char)-4,(char)-28,(char)-95,(char)-98,14,(char)-12,95,(char)-104,(char)-28,67,55,(char)-123,91,(char)-13,(char)-102,(char)-3,(char)-116,(char)-25,
        61,(char)-17,121,(char)-37,122,(char)-78,(char)-46,(char)-10,(char)-98,(char)-60,61,90,0,25,(char)-72,71,(char)-105,91,119,(char)-36,113,(char)-57,127,(char)-49,77,(char)-52,(char)-69,51,65,39,(char)-62,
        69,(char)-47,(char)-5,18,35,100,(char)-44,22,(char)-50,(char)-62,16,98,111,50,90,(char)-96,(char)-121,(char)-14,(char)-63,3,123,79,123,(char)-66,108,116,80,50,58,(char)-116,(char)-61,(char)-66,40,
        104,(char)-73,48,(char)-97,(char)-34,94,(char)-15,123,(char)-99,(char)-74,67,61,123,(char)-81,(char)-117,124,123,78,(char)-90,121,(char)-71,116,126,(char)-4,(char)-7,(char)-49,127,(char)-2,51,(char)-67,
        91,(char)-47,(char)-18,(char)-98,(char)-58,61,93,0,109,(char)-4,(char)-25,(char)-26,(char)-123,69,(char)-66,37,(char)-4,73,30,17,15,(char)-65,(char)-7,(char)-26,(char)-101,63,(char)-107,(char)-119,
        (char)-97,19,67,(char)-69,57,12,31,118,(char)-2,39,(char)-117,(char)-48,118,59,9,(char)-113,66,(char)-7,(char)-96,(char)-48,(char)-21,(char)-16,(char)-64,(char)-65,(char)-73,(char)-11,50,123,(char)-113,
        (char)-14,(char)-93,(char)-29,(char)-41,83,124,15,(char)-66,(char)-64,15,122,91,(char)-15,(char)-20,(char)-59,(char)-93,51,(char)-7,(char)-79,13,125,(char)-23,2,(char)-65,(char)-63,115,83,(char)-114,
        (char)-4,(char)-41,(char)-26,6,122,(char)-41,(char)-56,(char)-9,(char)-38,(char)-25,94,41,0,(char)-77,(char)-55,(char)-51,(char)-52,77,(char)-71,(char)-103,(char)-71,44,19,60,54,(char)-89,(char)-63,
        (char)-66,(char)-47,(char)-3,48,11,117,69,(char)-86,(char)-34,(char)-99,110,(char)-60,59,62,(char)-47,55,(char)-63,98,21,(char)-33,20,(char)-35,15,122,40,21,(char)-33,(char)-30,75,95,(char)-76,(char)-12,
        (char)-109,104,(char)-75,43,(char)-38,(char)-5,44,(char)-84,61,127,(char)-10,30,125,(char)-37,(char)-98,(char)-25,(char)-109,121,(char)-114,(char)-117,(char)-69,108,(char)-12,(char)-63,85,63,(char)-6,
        (char)-47,(char)-113,(char)-66,(char)-101,35,(char)-1,25,(char)-39,(char)-3,31,43,(char)-37,(char)-67,69,(char)-17,(char)-75,2,(char)-88,9,(char)-7,(char)-26,42,(char)-107,(char)-2,(char)-115,15,
        126,(char)-16,(char)-125,(char)-69,103,17,15,11,(char)-36,23,(char)-76,103,(char)-37,(char)-16,(char)-51,13,(char)-123,38,12,126,100,(char)-63,(char)-38,66,(char)-78,(char)-61,(char)-64,60,22,23,
        102,27,59,117,(char)-116,(char)-72,68,(char)-76,64,(char)-18,(char)-47,(char)-57,(char)-28,(char)-45,(char)-37,122,(char)-98,31,(char)-12,(char)-70,(char)-30,(char)-69,118,(char)-41,70,119,(char)-26,
        103,63,(char)-5,(char)-39,15,110,(char)-67,(char)-11,(char)-42,(char)-49,(char)-49,117,(char)-1,(char)-20,(char)-56,(char)-9,(char)-6,(char)-25,94,47,0,51,76,17,(char)-36,118,(char)-48,65,7,(char)-3,
        (char)-32,(char)-61,31,(char)-2,(char)-16,39,62,(char)-14,(char)-111,(char)-113,(char)-68,34,(char)-117,(char)-27,(char)-41,(char)-51,(char)-3,17,(char)-29,(char)-71,89,(char)-96,(char)-15,(char)-119,
        16,(char)-66,(char)-35,19,104,3,100,(char)-64,23,(char)-46,(char)-74,(char)-40,86,24,101,(char)-17,105,(char)-15,28,(char)-15,(char)-128,(char)-17,33,14,(char)-48,(char)-95,(char)-123,(char)-110,
        (char)-47,30,98,(char)-108,79,(char)-47,(char)-34,78,71,(char)-18,(char)-3,(char)-56,16,(char)-35,89,(char)-63,(char)-25,(char)-14,(char)-92,(char)-76,(char)-33,27,(char)-33,(char)-8,(char)-58,3,
        (char)-93,107,47,(char)-52,66,(char)-17,(char)-11,(char)-49,125,82,0,53,75,(char)-65,(char)-62,(char)-76,(char)-1,(char)-2,(char)-5,127,51,69,112,68,22,(char)-28,(char)-75,57,38,79,(char)-120,(char)-51,
        95,(char)-76,(char)-14,37,71,(char)-42,112,92,11,(char)-45,(char)-110,27,(char)-97,(char)-123,126,(char)-46,112,92,56,61,(char)-33,55,74,127,45,102,(char)-81,(char)-61,(char)-13,71,123,(char)-16,
        (char)-99,(char)-92,(char)-17,125,122,(char)-98,127,(char)-26,50,45,126,116,(char)-2,66,(char)-121,71,(char)-31,15,93,112,(char)-63,5,(char)-121,110,(char)-73,(char)-35,118,7,31,115,(char)-52,49,
        (char)-2,(char)-31,109,(char)-33,(char)-12,94,(char)-25,(char)-17,(char)-45,2,(char)-88,(char)-39,(char)-90,16,(char)-82,(char)-8,(char)-50,119,(char)-66,115,82,22,(char)-7,61,89,(char)-72,(char)-73,
        69,(char)-1,(char)-75,(char)-64,(char)-97,(char)-89,25,127,(char)-43,25,91,75,106,(char)-47,(char)-40,(char)-37,2,103,97,(char)-79,99,(char)-80,(char)-113,(char)-123,(char)-114,25,(char)-6,117,(char)-90,
        105,(char)-20,(char)-62,(char)-4,(char)-60,6,13,(char)-118,(char)-30,65,59,(char)-64,119,(char)-74,(char)-86,(char)-32,(char)-13,(char)-13,8,(char)-6,(char)-11,(char)-68,(char)-53,127,113,(char)-82,
        (char)-13,(char)-121,63,(char)-21,89,(char)-49,58,(char)-31,(char)-12,(char)-45,79,(char)-9,39,120,(char)-72,(char)-33,(char)-89,(char)-72,95,20,(char)-128,21,(char)-56,59,(char)-125,91,(char)-14,
        (char)-50,(char)-32,(char)-36,60,41,(char)-8,50,(char)-23,(char)-112,(char)-68,(char)-115,(char)-37,39,11,(char)-7,(char)-115,(char)-40,20,(char)-126,(char)-65,112,57,(char)-19,(char)-104,(char)-100,
        (char)-80,(char)-40,(char)-83,64,(char)-30,63,(char)-19,(char)-61,15,(char)-110,(char)-128,102,79,(char)-52,102,71,(char)-127,(char)-83,(char)-64,64,(char)-121,78,2,(char)-65,(char)-46,(char)-9,
        60,93,(char)-75,(char)-93,(char)-121,(char)-24,(char)-116,(char)-5,39,(char)-47,127,36,(char)-4,81,(char)-47,(char)-67,(char)-6,(char)-64,3,15,(char)-4,70,110,(char)-126,47,(char)-113,60,109,46,
        (char)-111,(char)-17,(char)-77,(char)-49,(char)-3,(char)-90,0,106,5,(char)-14,12,124,125,(char)-66,(char)-124,57,115,(char)-33,125,(char)-9,61,38,55,(char)-118,123,(char)-28,(char)-99,(char)-4,63,
        100,(char)-15,62,28,(char)-8,114,(char)-23,23,(char)-95,94,(char)-111,(char)-42,(char)-50,106,(char)-51,(char)-94,(char)-101,120,26,48,38,1,45,(char)-15,120,32,(char)-93,67,(char)-48,67,(char)-81,
        (char)-81,(char)-72,67,29,(char)-71,(char)-9,(char)-19,120,71,(char)-4,111,(char)-46,(char)-18,63,82,112,(char)-97,13,(char)-34,116,(char)-55,37,(char)-105,(char)-68,63,47,(char)-62,(char)-114,(char)-39,
        109,(char)-73,(char)-35,(char)-82,(char)-10,79,(char)-20,(char)-76,(char)-99,(char)-124,(char)-5,74,119,(char)-65,43,(char)-128,90,(char)-120,44,(char)-42,31,15,62,(char)-8,(char)-32,(char)-117,
        (char)-13,5,(char)-51,(char)-119,(char)-17,125,(char)-17,123,15,(char)-53,34,(char)-66,58,(char)-89,(char)-62,65,89,(char)-36,(char)-109,2,(char)-65,1,123,(char)-11,(char)-44,(char)-62,87,49,20,
        (char)-83,16,(char)-45,104,(char)-38,(char)-116,(char)-117,68,(char)-69,(char)-110,57,(char)-111,(char)-95,120,(char)-76,71,(char)-17,75,79,70,33,(char)-4,(char)-83,(char)-63,(char)-75,(char)-71,
        116,93,(char)-102,(char)-124,(char)-97,28,(char)-35,17,121,(char)-119,115,(char)-48,(char)-7,(char)-25,(char)-97,127,112,94,(char)-128,125,103,(char)-117,45,(char)-74,56,127,(char)-3,(char)-11,(char)-41,
        (char)-65,(char)-59,(char)-115,111,108,(char)-9,(char)-69,(char)-49,(char)-3,(char)-74,0,(char)-70,(char)-107,(char)-70,(char)-3,(char)-80,(char)-61,14,(char)-69,38,11,(char)-8,(char)-3,35,(char)-114,
        56,(char)-30,95,63,(char)-12,(char)-95,15,(char)-67,53,95,(char)-34,(char)-20,(char)-98,5,(char)-33,(char)-25,(char)-78,(char)-53,46,59,38,126,(char)-33,13,126,28,92,27,(char)-8,(char)-25,(char)-48,
        (char)-66,120,90,104,49,(char)-60,(char)-81,125,42,(char)-23,(char)-124,36,113,92,32,(char)-28,30,(char)-15,107,(char)-97,(char)-24,90,(char)-4,8,87,(char)-57,(char)-1,(char)-105,25,(char)-61,(char)-65,
        71,(char)-9,(char)-71,(char)-16,(char)-5,(char)-98,113,(char)-58,25,111,(char)-52,(char)-27,(char)-21,(char)-11,(char)-37,111,(char)-65,(char)-3,(char)-1,124,(char)-10,(char)-77,(char)-97,(char)-3,
        (char)-75,60,(char)-38,(char)-3,(char)-26,(char)-108,83,78,(char)-15,(char)-67,125,92,(char)-18,(char)-65,(char)-97,7,66,1,(char)-76,(char)-43,(char)-53,(char)-115,(char)-30,(char)-68,(char)-61,
        15,63,(char)-4,15,(char)-95,(char)-105,(char)-28,123,(char)-2,(char)-1,(char)-8,(char)-121,127,(char)-8,(char)-121,(char)-49,108,(char)-77,(char)-51,54,(char)-69,95,115,(char)-51,53,59,(char)-89,
        32,(char)-10,(char)-53,(char)-23,(char)-16,(char)-82,56,126,44,(char)-55,(char)-16,43,83,(char)-65,10,(char)-67,36,(char)-16,(char)-25,(char)-47,(char)-35,63,(char)-36,26,(char)-101,47,(char)-94,
        (char)-20,86,(char)-16,(char)-41,(char)-77,91,(char)-111,36,(char)-103,49,(char)-115,92,(char)-109,(char)-67,(char)-74,110,(char)-59,(char)-109,118,(char)-2,(char)-63,(char)-117,(char)-29,(char)-36,
        (char)-1,64,(char)-21,(char)-38,(char)-56,(char)-41,5,(char)-33,15,(char)-2,61,73,(char)-1,64,(char)-16,(char)-18,(char)-20,(char)-10,29,50,(char)-106,55,(char)-67,(char)-2,(char)-11,(char)-81,127,
        (char)-11,75,94,(char)-14,(char)-110,79,103,44,39,(char)-66,(char)-16,(char)-123,47,(char)-68,(char)-30,(char)-76,(char)-45,78,115,(char)-19,111,(char)-79,5,(char)-66,(char)-65,(char)-29,1,83,0,
        (char)-125,(char)-123,(char)-68,(char)-3,(char)-92,(char)-109,78,(char)-70,33,(char)-105,(char)-123,63,124,(char)-18,115,(char)-97,(char)-5,(char)-7,(char)-49,126,(char)-10,(char)-77,47,(char)-92,
        16,(char)-34,(char)-9,(char)-18,119,(char)-65,(char)-5,(char)-96,119,(char)-68,(char)-29,29,(char)-81,60,(char)-14,(char)-56,35,(char)-1,(char)-18,(char)-74,(char)-37,110,(char)-37,51,(char)-40,
        47,120,(char)-17,(char)-36,(char)-71,115,(char)-1,103,(char)-110,119,108,98,(char)-100,18,(char)-8,11,(char)-88,(char)-2,24,(char)-10,(char)-9,(char)-94,59,61,(char)-55,(char)-12,70,(char)-14,(char)-30,
        (char)-24,(char)-65,(char)-99,98,(char)-8,110,(char)-28,(char)-29,33,(char)-74,79,(char)-92,(char)-80,14,(char)-67,(char)-18,(char)-70,(char)-21,14,(char)-69,(char)-23,(char)-90,(char)-101,118,(char)-103,
        61,123,(char)-10,1,(char)-53,47,(char)-65,(char)-4,(char)-85,127,(char)-6,(char)-45,(char)-97,(char)-66,(char)-17,(char)-54,43,(char)-81,60,(char)-14,57,(char)-49,121,(char)-50,57,57,(char)-115,
        (char)-66,(char)-97,(char)-109,(char)-23,(char)-58,7,(char)-62,78,(char)-49,(char)-4,38,126,30,(char)-88,5,48,(char)-98,(char)-52,1,7,28,48,(char)-17,(char)-87,79,125,(char)-22,31,(char)-41,93,119,
        (char)-35,(char)-101,115,(char)-119,(char)-72,34,55,(char)-114,63,121,(char)-41,(char)-69,(char)-34,117,(char)-22,63,(char)-3,(char)-45,63,(char)-99,(char)-104,66,(char)-8,(char)-52,(char)-55,39,
        (char)-97,124,120,(char)-114,(char)-29,(char)-35,119,(char)-35,117,(char)-41,125,35,(char)-65,50,55,(char)-107,(char)-69,6,123,(char)-92,48,118,60,(char)-28,(char)-112,67,118,75,(char)-47,(char)-68,
        116,(char)-50,(char)-100,57,47,(char)-3,(char)-6,(char)-41,(char)-65,(char)-2,(char)-90,36,(char)-10,85,121,60,59,(char)-32,(char)-68,(char)-13,(char)-50,(char)-37,45,(char)-9,29,111,(char)-1,(char)-26,
        55,(char)-65,(char)-7,(char)-50,(char)-60,125,(char)-49,43,94,(char)-15,(char)-118,(char)-1,(char)-77,(char)-46,74,43,125,(char)-7,125,(char)-17,123,(char)-33,101,(char)-101,111,(char)-66,(char)-7,
        101,(char)-82,(char)-23,121,(char)-106,(char)-9,(char)-2,126,60,(char)-114,7,42,(char)-13,(char)-128,47,(char)-128,(char)-103,22,62,59,(char)-13,(char)-74,36,(char)-9,(char)-6,(char)-41,(char)-68,
        (char)-26,53,55,(char)-28,94,(char)-31,(char)-90,19,78,56,(char)-31,(char)-105,41,(char)-116,(char)-97,63,(char)-28,33,15,(char)-71,48,56,47,55,(char)-103,(char)-65,(char)-8,(char)-25,127,(char)-2,
        (char)-25,(char)-17,(char)-25,(char)-78,114,(char)-31,10,43,(char)-84,112,(char)-10,78,59,(char)-19,116,(char)-50,6,27,108,112,(char)-39,(char)-74,(char)-37,110,123,81,(char)-98,(char)-45,(char)-81,
        61,(char)-12,(char)-48,67,(char)-81,(char)-10,104,(char)-102,(char)-8,(char)-73,102,(char)-121,(char)-69,(char)-124,(char)-116,20,91,(char)-28,63,(char)-87,(char)-49,(char)-97,108,1,44,36,75,(char)-73,
        (char)-77,13,(char)-110,(char)-39,116,(char)-47,(char)-69,23,8,(char)-7,(char)-13,(char)-7,(char)-4,57,22,(char)-64,(char)-3,42,(char)-69,(char)-9,(char)-11,96,(char)-2,47,0,0,0,(char)-1,(char)-1,
        125,(char)-50,(char)-58,(char)-120,0,0,0,6,73,68,65,84,3,0,33,(char)-74,52,104,(char)-105,124,59,10,0,0,0,0,73,69,78,68,(char)-82,66,96,(char)-126, 0 };

    static constexpr const char* view_index_js =
        "\n"
        "/*\n"
        "    This simple web component just manually creates a set of plain sliders for the\n"
        "    known parameters, and uses some listeners to connect them to the patch.\n"
        "*/\n"
        "\n"
        "import \"../view/webaudio-controls.js\";\n"
        "\n"
        "class DemoView extends HTMLElement\n"
        "{\n"
        "    constructor (patchConnection)\n"
        "    {\n"
        "        super();\n"
        "        this.patchConnection = patchConnection;\n"
        "        this.classList = \"demo-patch-element\";\n"
        "        this.innerHTML = this.getHTML();\n"
        "    }\n"
        "\n"
        "    connectedCallback()\n"
        "    {\n"
        "        this.paramListener = (event) =>\n"
        "        {\n"
        "            // Each of our sliders has the same IDs as an endpoint, so we can find\n"
        "            // the HTML element from the endpointID that has changed:\n"
        "            const slider = this.querySelector (\"#\" + event.endpointID);\n"
        "\n"
        "            if (slider)\n"
        "                slider.value = event.value;\n"
        "        };\n"
        "\n"
        "        // Attach a parameter listener that will be triggered when any param is moved\n"
        "        this.patchConnection.addAllParameterListener (this.paramListener);\n"
        "\n"
        "        for (const knob of this.querySelectorAll (\"webaudio-knob\"))\n"
        "        {\n"
        "            const sendKnobValue = () => this.patchConnection.sendEventOrValue (knob.id, knob.value);\n"
        "            knob.addEventListener (\"change\", sendKnobValue);\n"
        "            knob.addEventListener (\"input\", sendKnobValue);\n"
        "\n"
        "            // for each knob, request an initial update, to make sure it shows the right value\n"
        "            this.patchConnection.requestParameterValue (knob.id);\n"
        "        }\n"
        "    }\n"
        "\n"
        "    disconnectedCallback()\n"
        "    {\n"
        "        // when our element goes offscreen, we should remove any listeners\n"
        "        // from the PatchConnection (which may be shared with other clients)\n"
        "        this.patchConnection.removeAllParameterListener (this.paramListener);\n"
        "    }\n"
        "\n"
        "    getHTML()\n"
        "    {\n"
        "        return `\n"
        "        <style>\n"
        "            .demo-patch-element {\n"
        "                background: rgb(96, 102, 108);\n"
        "                display: block;\n"
        "                width: 100%;\n"
        "                height: auto;\n"
        "                padding: 10px;\n"
        "                overflow: auto;\n"
        "            }\n"
        "\n"
        "            .param {\n"
        "                display: inline-flex;\n"
        "                flex-direction: column;\n"
        "                align-items: center;\n"
        "                justify-content: center;\n"
        "                margin: 30px;\n"
        "                width: 100px;\n"
        "                \n"
        "                float: right;\n"
        "            }\n"
        "\n"
        "            .mix-param {\n"
        "                width: 180px;\n"
        "            }\n"
        "\n"
        "            #mix {\n"
        "                display: flex;\n"
        "                width: 100%;\n"
        "                margin-bottom: 20px;\n"
        "                margin-top: 30px;\n"
        "                float: left;\n"
        "                vertical-align: auto;\n"
        "                border: 1px solid rgb(0, 0, 0);\n"
        "                background: #132f3d;\n"
        "                background: radial-gradient(circle, rgba(19, 47, 61, 1) 0%, rgba(102, 185, 196, 1) 100%);\n"
        "            }\n"
        "\n"
        "            #controls {\n"
        "                \n"
        "                float: right;\n"
        "                display: inline-flex;  \n"
        "                flex-direction: row;\n"
        "            }\n"
        "\n"
        "            webaudio-knob {\n"
        "                transform-origin: center center;\n"
        "            }\n"
        "\n"
        "            #mixParam {\n"
        "                transform-origin: center center;\n"
        "            }\n"
        "\n"
        "            webaudio-knob::part(label) {\n"
        "                display: none;\n"
        "            }\n"
        "\n"
        "            .knob-label {\n"
        "                margin-top: 8px;\n"
        "                text-align: center;\n"
        "                color: white;\n"
        "                font-size: 0.85rem;\n"
        "                user-select: none;\n"
        "            }\n"
        "\n"
        "            .param::slotted(*) {\n"
        "                pointer-events: none;\n"
        "            }\n"
        "            \n"
        "            #dly{\n"
        "            position: right;\n"
        "            }\n"
        "\n"
        "            #fbk{\n"
        "            position: left;\n"
        "            }\n"
        "\n"
        "        </style>\n"
        "\n"
        "        <header style=\"text-align: center; color: white; font-size: 1.5rem; margin-bottom: 20px; font-weight: bold;\">\n"
        "            Delay Grain<br>\n"
        "            <span style=\"font-size: 1rem; font-weight: normal;\">by Victor Schulhoff</span>\n"
        "        </header>\n"
        "        \n"
        "        <div style=\"display: inline-flex;  flex-direction: row; horizontal-align: center; border: 1px solid rgb(0, 0, 0); background: rgba(102, 185, 196, 1);\">\n"
        "        <div id=\"mix\" class=\"param\">\n"
        "            <div style=\"display:flex;flex-direction:column;align-items:center;\">\n"
        "              <webaudio-knob style=\"rotate: 265deg;\" class=\"param mix-param\" style=\"vertical-align: middle;\" id=\"mixParam\" min=\"0\" max=\"1\" step=\"0.001\" src=\"view/Sky_Blue_Bevel.png\" width=\"140\" height=\"140\"></webaudio-knob>\n"
        "              <div class=\"knob-label\">Mix</div>\n"
        "            </div>\n"
        "        </div>\n"
        "        <section id=\"controls\" style=\"background: #020f1a; background: radial-gradient(circle, rgba(2, 15, 26, 1) 0%, rgba(102, 185, 196, 1) 100%); border-left: 1px solid rgb(0, 0, 0);\">\n"
        "            <article class=\"param\" id=\"dly\">\n"
        "                <div style=\"display:flex;flex-direction:column;align-items:center;\">\n"
        "                  <webaudio-knob style=\"rotate: 265deg;\" class=\"param\" id=\"maxDelayParam\" min=\"0\" max=\"0.03\" step=\"0.0001\" width=\"80\"  src=\"view/Middle_Potion.png\" height=\"80\"></webaudio-knob>\n"
        "                  <div class=\"knob-label\">Max Delay</div>\n"
        "                </div>\n"
        "                <div style=\"display:flex;flex-direction:column;align-items:center;\">\n"
        "                  <webaudio-knob style=\"rotate: 265deg;\" class=\"param\" id=\"feedbackParam\"  min=\"0\" max=\"1\" step=\"0.001\" src=\"view/Middle_Potion.png\"  width=\"80\" height=\"80\"></webaudio-knob>\n"
        "                  <div class=\"knob-label\">Feedback</div>\n"
        "                </div>\n"
        "            </article>\n"
        "            <br><br>\n"
        "            <article class=\"param\" id=\"fbk\">   \n"
        "                <div style=\"display:flex;flex-direction:column;align-items:center;\">\n"
        "                  <webaudio-knob style=\"rotate: 265deg;\" class=\"param\" id=\"cutoffParam\" min=\"0\" max=\"1\" step=\"0.001\"  src=\"view/Middle_Potion.png\"  width=\"80\" height=\"80\"></webaudio-knob>\n"
        "                  <div class=\"knob-label\">Cutoff</div>\n"
        "                </div>\n"
        "                <div style=\"display:flex;flex-direction:column;align-items:center;\">\n"
        "                  <webaudio-knob style=\"rotate: 265deg;\" class=\"param\" id=\"resonanceParam\" min=\"0\" max=\"1\" step=\"0.001\"  src=\"view/Middle_Potion.png\" width=\"80\" height=\"80\"></webaudio-knob>\n"
        "                  <div class=\"knob-label\">Resonance</div>\n"
        "                </div>\n"
        "            </article>\n"
        "        </section>\n"
        "        </div>\n"
        "        `;\n"
        "\n"
        "    }\n"
        "}\n"
        "\n"
        "\n"
        "/* This is the function that a host (the command line patch player, or a Cmajor plugin\n"
        "   loader, or our VScode extension, etc) will call in order to create a view for your patch.\n"
        "\n"
        "   Ultimately, a DOM element must be returned to the caller for it to append to its document.\n"
        "   However, this function can be `async` if you need to perform asyncronous tasks, such as\n"
        "   fetching remote resources for use in the view, before completing.\n"
        "\n"
        "   When using libraries such as React, this is where the call to `ReactDOM.createRoot` would\n"
        "   go, rendering into a container component before returning.\n"
        "*/\n"
        "export default function createPatchView (patchConnection)\n"
        "{\n"
        "    const customElementName = \"demo-patch-view\";\n"
        "\n"
        "    if (! window.customElements.get (customElementName))\n"
        "        window.customElements.define (customElementName, DemoView);\n"
        "\n"
        "    return new (window.customElements.get (customElementName)) (patchConnection);\n"
        "}\n";
    static constexpr const char view_webaudiocontrols_js[] = {
        47,42,32,42,10,32,42,10,32,42,32,32,87,101,98,65,117,100,105,111,45,67,111,110,116,114,111,108,115,32,105,115,32,98,97,115,101,100,32,111,110,10,32,42,32,32,32,32,119,101,98,97,117,100,105,111,45,107,110,
        111,98,32,98,121,32,69,105,106,105,32,75,105,116,97,109,117,114,97,32,104,116,116,112,58,47,47,103,111,111,103,108,101,46,99,111,109,47,43,97,103,101,107,116,109,114,10,32,42,32,32,32,32,119,101,
        98,97,117,100,105,111,45,115,108,105,100,101,114,32,98,121,32,82,89,111,121,97,32,75,97,119,97,105,32,104,116,116,112,115,58,47,47,112,108,117,115,46,103,111,111,103,108,101,46,99,111,109,47,49,
        48,56,50,52,50,54,54,57,49,57,49,52,53,56,57,56,51,52,56,53,47,112,111,115,116,115,10,32,42,32,32,32,32,119,101,98,97,117,100,105,111,45,115,119,105,116,99,104,32,98,121,32,75,101,105,115,117,107,
        101,32,65,105,32,104,116,116,112,58,47,47,100,46,104,97,116,101,110,97,46,110,101,46,106,112,47,97,105,107,101,47,10,32,42,32,32,73,110,116,101,103,114,97,116,101,100,32,97,110,100,32,101,110,104,
        97,110,99,101,100,32,98,121,32,103,50,48,48,107,103,32,104,116,116,112,58,47,47,119,119,119,46,103,50,48,48,107,103,46,99,111,109,47,10,32,42,10,32,42,9,67,111,112,121,114,105,103,104,116,32,50,
        48,49,51,32,69,105,106,105,32,75,105,116,97,109,117,114,97,32,47,32,82,121,111,121,97,32,75,65,87,65,73,32,47,32,75,101,105,115,117,107,101,32,65,105,32,47,32,103,50,48,48,107,103,40,84,97,116,115,
        117,121,97,32,83,104,105,110,121,97,103,97,105,116,111,41,10,32,42,10,32,42,9,32,76,105,99,101,110,115,101,100,32,117,110,100,101,114,32,116,104,101,32,65,112,97,99,104,101,32,76,105,99,101,110,
        115,101,44,32,86,101,114,115,105,111,110,32,50,46,48,32,40,116,104,101,32,34,76,105,99,101,110,115,101,34,41,59,10,32,42,9,32,121,111,117,32,109,97,121,32,110,111,116,32,117,115,101,32,116,104,105,
        115,32,102,105,108,101,32,101,120,99,101,112,116,32,105,110,32,99,111,109,112,108,105,97,110,99,101,32,119,105,116,104,32,116,104,101,32,76,105,99,101,110,115,101,46,10,32,42,9,32,89,111,117,32,
        109,97,121,32,111,98,116,97,105,110,32,97,32,99,111,112,121,32,111,102,32,116,104,101,32,76,105,99,101,110,115,101,32,97,116,10,32,42,10,32,42,9,32,104,116,116,112,58,47,47,119,119,119,46,97,112,
        97,99,104,101,46,111,114,103,47,108,105,99,101,110,115,101,115,47,76,73,67,69,78,83,69,45,50,46,48,10,32,42,10,32,42,9,32,85,110,108,101,115,115,32,114,101,113,117,105,114,101,100,32,98,121,32,97,
        112,112,108,105,99,97,98,108,101,32,108,97,119,32,111,114,32,97,103,114,101,101,100,32,116,111,32,105,110,32,119,114,105,116,105,110,103,44,32,115,111,102,116,119,97,114,101,10,32,42,9,32,100,105,
        115,116,114,105,98,117,116,101,100,32,117,110,100,101,114,32,116,104,101,32,76,105,99,101,110,115,101,32,105,115,32,100,105,115,116,114,105,98,117,116,101,100,32,111,110,32,97,110,32,34,65,83,32,
        73,83,34,32,66,65,83,73,83,44,10,32,42,9,32,87,73,84,72,79,85,84,32,87,65,82,82,65,78,84,73,69,83,32,79,82,32,67,79,78,68,73,84,73,79,78,83,32,79,70,32,65,78,89,32,75,73,78,68,44,32,101,105,116,
        104,101,114,32,101,120,112,114,101,115,115,32,111,114,32,105,109,112,108,105,101,100,46,10,32,42,9,32,83,101,101,32,116,104,101,32,76,105,99,101,110,115,101,32,102,111,114,32,116,104,101,32,115,
        112,101,99,105,102,105,99,32,108,97,110,103,117,97,103,101,32,103,111,118,101,114,110,105,110,103,32,112,101,114,109,105,115,115,105,111,110,115,32,97,110,100,10,32,42,9,32,108,105,109,105,116,97,
        116,105,111,110,115,32,117,110,100,101,114,32,116,104,101,32,76,105,99,101,110,115,101,46,10,32,42,10,32,42,32,42,47,10,105,102,40,119,105,110,100,111,119,46,99,117,115,116,111,109,69,108,101,109,
        101,110,116,115,41,123,10,32,32,108,101,116,32,115,116,121,108,101,115,61,100,111,99,117,109,101,110,116,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,115,116,121,108,101,34,41,59,10,
        32,32,115,116,121,108,101,115,46,105,110,110,101,114,72,84,77,76,61,10,96,35,119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,32,123,10,32,32,100,105,
        115,112,108,97,121,58,32,110,111,110,101,59,10,32,32,112,111,115,105,116,105,111,110,58,32,97,98,115,111,108,117,116,101,59,10,32,32,122,45,105,110,100,101,120,58,32,49,48,59,10,32,32,112,97,100,
        100,105,110,103,58,32,48,59,10,32,32,119,105,100,116,104,58,32,49,48,48,112,120,59,10,32,32,99,111,108,111,114,58,35,101,101,101,59,10,32,32,98,97,99,107,103,114,111,117,110,100,45,99,111,108,111,
        114,58,32,35,50,54,56,59,10,32,32,98,111,114,100,101,114,58,32,115,111,108,105,100,32,49,112,120,32,35,56,56,56,59,10,32,32,98,111,120,45,115,104,97,100,111,119,58,32,49,112,120,32,49,112,120,32,
        50,112,120,32,35,56,56,56,59,10,32,32,102,111,110,116,45,102,97,109,105,108,121,58,32,115,97,110,115,45,115,101,114,105,102,59,10,32,32,102,111,110,116,45,115,105,122,101,58,32,49,49,112,120,59,
        10,32,32,108,105,110,101,45,104,101,105,103,104,116,58,49,46,55,101,109,59,10,32,32,116,101,120,116,45,97,108,105,103,110,58,99,101,110,116,101,114,59,10,32,32,99,117,114,115,111,114,58,112,111,
        105,110,116,101,114,59,10,32,32,99,111,108,111,114,58,35,102,102,102,59,10,32,32,108,105,115,116,45,115,116,121,108,101,58,32,110,111,110,101,59,10,125,10,35,119,101,98,97,117,100,105,111,99,116,
        114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,46,97,99,116,105,118,101,32,123,10,32,32,100,105,115,112,108,97,121,58,32,98,108,111,99,107,59,10,125,10,46,119,101,98,97,117,100,105,111,
        99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,95,95,105,116,101,109,32,123,10,32,32,100,105,115,112,108,97,121,58,32,98,108,111,99,107,59,10,32,32,109,97,114,103,105,110,58,32,
        48,59,10,32,32,112,97,100,100,105,110,103,58,32,48,59,10,32,32,99,111,108,111,114,58,32,35,48,48,48,59,10,32,32,98,97,99,107,103,114,111,117,110,100,45,99,111,108,111,114,58,35,101,101,101,59,10,
        32,32,116,101,120,116,45,100,101,99,111,114,97,116,105,111,110,58,32,110,111,110,101,59,10,125,10,46,119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,
        95,95,116,105,116,108,101,123,10,32,32,102,111,110,116,45,119,101,105,103,104,116,58,98,111,108,100,59,10,125,10,46,119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,101,120,116,45,
        109,101,110,117,95,95,105,116,101,109,58,108,97,115,116,45,99,104,105,108,100,32,123,10,32,32,109,97,114,103,105,110,45,98,111,116,116,111,109,58,32,48,59,10,125,10,46,119,101,98,97,117,100,105,
        111,99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,95,95,105,116,101,109,58,104,111,118,101,114,32,123,10,32,32,98,97,99,107,103,114,111,117,110,100,45,99,111,108,111,114,58,32,
        35,98,56,98,56,98,56,59,10,125,10,96,59,10,32,32,100,111,99,117,109,101,110,116,46,104,101,97,100,46,97,112,112,101,110,100,67,104,105,108,100,40,115,116,121,108,101,115,41,59,10,32,32,108,101,116,
        32,109,105,100,105,109,101,110,117,61,100,111,99,117,109,101,110,116,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,117,108,34,41,59,10,32,32,109,105,100,105,109,101,110,117,46,105,100,
        61,34,119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,34,59,10,32,32,109,105,100,105,109,101,110,117,46,105,110,110,101,114,72,84,77,76,61,10,96,60,
        108,105,32,99,108,97,115,115,61,34,119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,95,95,116,105,116,108,101,34,62,77,73,68,73,32,76,101,97,114,110,
        60,47,108,105,62,10,60,108,105,32,99,108,97,115,115,61,34,119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,95,95,105,116,101,109,34,32,105,100,61,34,
        119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,45,108,101,97,114,110,34,32,111,110,99,108,105,99,107,61,34,119,101,98,65,117,100,105,111,67,111,110,
        116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,46,99,111,110,116,101,120,116,77,101,110,117,76,101,97,114,110,40,41,34,62,76,101,97,114,110,60,47,108,105,62,10,60,108,105,32,
        99,108,97,115,115,61,34,119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,95,95,105,116,101,109,34,32,111,110,99,108,105,99,107,61,34,119,101,98,65,117,
        100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,46,99,111,110,116,101,120,116,77,101,110,117,67,108,101,97,114,40,41,34,62,67,108,101,97,114,60,47,108,
        105,62,10,60,108,105,32,99,108,97,115,115,61,34,119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,95,95,105,116,101,109,34,32,111,110,99,108,105,99,107,
        61,34,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,46,99,111,110,116,101,120,116,77,101,110,117,67,108,111,115,101,40,41,34,62,67,
        108,111,115,101,60,47,108,105,62,10,96,59,10,32,32,108,101,116,32,111,112,116,61,123,10,32,32,32,32,117,115,101,77,105,100,105,58,48,44,10,32,32,32,32,98,117,98,98,108,101,115,58,116,114,117,101,
        44,10,32,32,32,32,99,97,110,99,101,108,97,98,108,101,58,116,114,117,101,44,10,32,32,32,32,112,114,101,115,101,114,118,101,77,105,100,105,76,101,97,114,110,58,48,44,10,32,32,32,32,112,114,101,115,
        101,114,118,101,86,97,108,117,101,58,48,44,10,32,32,32,32,109,105,100,105,108,101,97,114,110,58,48,44,10,32,32,32,32,109,105,100,105,100,117,109,112,58,48,44,10,32,32,32,32,111,117,116,108,105,110,
        101,58,110,117,108,108,44,10,32,32,32,32,107,110,111,98,83,114,99,58,110,117,108,108,44,10,32,32,32,32,107,110,111,98,83,112,114,105,116,101,115,58,110,117,108,108,44,10,32,32,32,32,107,110,111,
        98,87,105,100,116,104,58,110,117,108,108,44,10,32,32,32,32,107,110,111,98,72,101,105,103,104,116,58,110,117,108,108,44,10,32,32,32,32,107,110,111,98,68,105,97,109,101,116,101,114,58,110,117,108,
        108,44,10,32,32,32,32,107,110,111,98,67,111,108,111,114,115,58,34,35,101,48,48,59,35,48,48,48,59,35,102,102,102,34,44,10,32,32,32,32,115,108,105,100,101,114,83,114,99,58,110,117,108,108,44,10,32,
        32,32,32,115,108,105,100,101,114,87,105,100,116,104,58,110,117,108,108,44,10,32,32,32,32,115,108,105,100,101,114,72,101,105,103,104,116,58,110,117,108,108,44,10,32,32,32,32,115,108,105,100,101,114,
        75,110,111,98,83,114,99,58,110,117,108,108,44,10,32,32,32,32,115,108,105,100,101,114,75,110,111,98,87,105,100,116,104,58,110,117,108,108,44,10,32,32,32,32,115,108,105,100,101,114,75,110,111,98,72,
        101,105,103,104,116,58,110,117,108,108,44,10,32,32,32,32,115,108,105,100,101,114,68,105,116,99,104,108,101,110,103,116,104,58,110,117,108,108,44,10,32,32,32,32,115,108,105,100,101,114,67,111,108,
        111,114,115,58,34,35,101,48,48,59,35,51,51,51,59,35,102,99,99,34,44,10,32,32,32,32,115,119,105,116,99,104,87,105,100,116,104,58,110,117,108,108,44,10,32,32,32,32,115,119,105,116,99,104,72,101,105,
        103,104,116,58,110,117,108,108,44,10,32,32,32,32,115,119,105,116,99,104,68,105,97,109,101,116,101,114,58,110,117,108,108,44,10,32,32,32,32,115,119,105,116,99,104,67,111,108,111,114,115,58,34,35,
        101,48,48,59,35,48,48,48,59,35,102,99,99,34,44,10,32,32,32,32,112,97,114,97,109,87,105,100,116,104,58,110,117,108,108,44,10,32,32,32,32,112,97,114,97,109,72,101,105,103,104,116,58,110,117,108,108,
        44,10,32,32,32,32,112,97,114,97,109,70,111,110,116,83,105,122,101,58,57,44,10,32,32,32,32,112,97,114,97,109,67,111,108,111,114,115,58,34,35,102,102,102,59,35,48,48,48,34,44,10,32,32,32,32,118,97,
        108,117,101,116,105,112,58,48,44,10,32,32,32,32,120,121,112,97,100,67,111,108,111,114,115,58,34,35,101,48,48,59,35,48,48,48,59,35,102,99,99,34,44,10,32,32,125,59,10,32,32,105,102,40,119,105,110,
        100,111,119,46,87,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,79,112,116,105,111,110,115,41,10,32,32,32,32,79,98,106,101,99,116,46,97,115,115,105,103,110,40,111,112,116,44,119,105,110,
        100,111,119,46,87,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,79,112,116,105,111,110,115,41,59,10,32,32,99,108,97,115,115,32,87,101,98,65,117,100,105,111,67,111,110,116,114,111,108,
        115,87,105,100,103,101,116,32,101,120,116,101,110,100,115,32,72,84,77,76,69,108,101,109,101,110,116,123,10,32,32,32,32,99,111,110,115,116,114,117,99,116,111,114,40,41,123,10,32,32,32,32,32,32,115,
        117,112,101,114,40,41,59,10,32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,107,101,121,100,111,119,110,34,44,116,104,105,115,46,107,101,121,
        100,111,119,110,41,59,10,32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,109,111,117,115,101,100,111,119,110,34,44,116,104,105,115,46,112,
        111,105,110,116,101,114,100,111,119,110,44,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,
        110,101,114,40,34,116,111,117,99,104,115,116,97,114,116,34,44,116,104,105,115,46,112,111,105,110,116,101,114,100,111,119,110,44,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,
        32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,119,104,101,101,108,34,44,116,104,105,115,46,119,104,101,101,108,44,123,112,97,115,115,105,
        118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,109,111,117,115,101,111,118,101,114,34,44,116,104,
        105,115,46,112,111,105,110,116,101,114,111,118,101,114,41,59,10,32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,109,111,117,115,101,111,117,
        116,34,44,116,104,105,115,46,112,111,105,110,116,101,114,111,117,116,41,59,10,32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,99,111,110,116,
        101,120,116,109,101,110,117,34,44,116,104,105,115,46,99,111,110,116,101,120,116,77,101,110,117,41,59,10,32,32,32,32,32,32,116,104,105,115,46,104,111,118,101,114,61,116,104,105,115,46,100,114,97,
        103,61,48,59,10,32,32,32,32,32,32,100,111,99,117,109,101,110,116,46,98,111,100,121,46,97,112,112,101,110,100,67,104,105,108,100,40,109,105,100,105,109,101,110,117,41,59,10,32,32,32,32,32,32,116,
        104,105,115,46,98,97,115,101,115,116,121,108,101,61,96,10,46,119,101,98,97,117,100,105,111,99,116,114,108,45,116,111,111,108,116,105,112,123,10,32,32,100,105,115,112,108,97,121,58,105,110,108,105,
        110,101,45,98,108,111,99,107,59,10,32,32,112,111,115,105,116,105,111,110,58,97,98,115,111,108,117,116,101,59,10,32,32,109,97,114,103,105,110,58,48,32,45,49,48,48,48,112,120,59,10,32,32,122,45,105,
        110,100,101,120,58,32,57,57,57,59,10,32,32,98,97,99,107,103,114,111,117,110,100,58,35,101,101,101,59,10,32,32,99,111,108,111,114,58,35,48,48,48,59,10,32,32,98,111,114,100,101,114,58,49,112,120,32,
        115,111,108,105,100,32,35,54,54,54,59,10,32,32,98,111,114,100,101,114,45,114,97,100,105,117,115,58,52,112,120,59,10,32,32,112,97,100,100,105,110,103,58,53,112,120,32,49,48,112,120,59,10,32,32,116,
        101,120,116,45,97,108,105,103,110,58,99,101,110,116,101,114,59,10,32,32,108,101,102,116,58,48,59,32,116,111,112,58,48,59,10,32,32,102,111,110,116,45,115,105,122,101,58,49,49,112,120,59,10,32,32,
        111,112,97,99,105,116,121,58,48,59,10,32,32,118,105,115,105,98,105,108,105,116,121,58,104,105,100,100,101,110,59,10,125,10,46,119,101,98,97,117,100,105,111,99,116,114,108,45,116,111,111,108,116,
        105,112,58,98,101,102,111,114,101,123,10,32,32,99,111,110,116,101,110,116,58,32,34,34,59,10,32,32,112,111,115,105,116,105,111,110,58,32,97,98,115,111,108,117,116,101,59,10,32,32,116,111,112,58,32,
        49,48,48,37,59,10,32,32,108,101,102,116,58,32,53,48,37,59,10,32,32,109,97,114,103,105,110,45,108,101,102,116,58,32,45,56,112,120,59,10,32,32,98,111,114,100,101,114,58,32,56,112,120,32,115,111,108,
        105,100,32,116,114,97,110,115,112,97,114,101,110,116,59,10,32,32,98,111,114,100,101,114,45,116,111,112,58,32,56,112,120,32,115,111,108,105,100,32,35,54,54,54,59,10,125,10,46,119,101,98,97,117,100,
        105,111,99,116,114,108,45,116,111,111,108,116,105,112,58,97,102,116,101,114,123,10,32,32,99,111,110,116,101,110,116,58,32,34,34,59,10,32,32,112,111,115,105,116,105,111,110,58,32,97,98,115,111,108,
        117,116,101,59,10,32,32,116,111,112,58,32,49,48,48,37,59,10,32,32,108,101,102,116,58,32,53,48,37,59,10,32,32,109,97,114,103,105,110,45,108,101,102,116,58,32,45,54,112,120,59,10,32,32,98,111,114,
        100,101,114,58,32,54,112,120,32,115,111,108,105,100,32,116,114,97,110,115,112,97,114,101,110,116,59,10,32,32,98,111,114,100,101,114,45,116,111,112,58,32,54,112,120,32,115,111,108,105,100,32,35,101,
        101,101,59,10,125,10,96,59,10,32,32,32,32,32,32,116,104,105,115,46,111,110,98,108,117,114,61,40,41,61,62,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,
        46,111,117,116,108,105,110,101,61,34,110,111,110,101,34,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,116,104,105,115,46,111,110,102,111,99,117,115,61,40,41,61,62,123,10,32,32,32,32,32,32,32,
        32,115,119,105,116,99,104,40,43,116,104,105,115,46,111,117,116,108,105,110,101,41,123,10,32,32,32,32,32,32,32,32,99,97,115,101,32,110,117,108,108,58,10,32,32,32,32,32,32,32,32,99,97,115,101,32,48,
        58,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,111,117,116,108,105,110,101,61,34,110,111,110,101,34,59,10,32,32,32,32,32,32,32,32,32,32,98,114,101,
        97,107,59,10,32,32,32,32,32,32,32,32,99,97,115,101,32,49,58,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,111,117,116,108,105,110,101,61,34,49,112,
        120,32,115,111,108,105,100,32,35,52,52,52,34,59,10,32,32,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,32,32,100,101,102,97,117,108,116,58,10,32,32,32,32,32,32,32,32,32,32,116,
        104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,111,117,116,108,105,110,101,61,116,104,105,115,46,111,117,116,108,105,110,101,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,125,
        10,32,32,32,32,125,10,32,32,32,32,115,101,110,100,69,118,101,110,116,40,101,118,41,123,10,32,32,32,32,32,32,108,101,116,32,101,118,101,110,116,32,61,32,110,101,119,32,69,118,101,110,116,40,101,118,
        44,32,123,98,117,98,98,108,101,115,58,111,112,116,46,98,117,98,98,108,101,115,63,116,114,117,101,58,102,97,108,115,101,44,32,99,97,110,99,101,108,97,98,108,101,58,111,112,116,46,99,97,110,99,101,
        108,97,98,108,101,63,116,114,117,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,100,105,115,112,97,116,99,104,69,118,101,110,116,40,101,118,101,110,116,41,59,10,32,32,
        32,32,125,10,32,32,32,32,103,101,116,65,116,116,114,40,110,44,100,101,102,41,123,10,32,32,32,32,32,32,108,101,116,32,118,61,116,104,105,115,46,103,101,116,65,116,116,114,105,98,117,116,101,40,110,
        41,59,10,32,32,32,32,32,32,105,102,40,118,61,61,110,117,108,108,41,32,114,101,116,117,114,110,32,100,101,102,59,10,32,32,32,32,32,32,115,119,105,116,99,104,40,116,121,112,101,111,102,40,100,101,
        102,41,41,123,10,32,32,32,32,32,32,99,97,115,101,32,34,110,117,109,98,101,114,34,58,10,32,32,32,32,32,32,32,32,105,102,40,118,61,61,34,116,114,117,101,34,41,32,114,101,116,117,114,110,32,49,59,10,
        32,32,32,32,32,32,32,32,118,61,43,118,59,10,32,32,32,32,32,32,32,32,105,102,40,105,115,78,97,78,40,118,41,41,32,114,101,116,117,114,110,32,48,59,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,
        32,118,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,114,101,116,117,114,110,32,118,59,10,32,32,32,32,125,10,32,32,32,32,115,104,111,119,116,105,112,40,100,41,123,10,32,32,32,32,32,32,102,117,
        110,99,116,105,111,110,32,118,97,108,115,116,114,40,120,44,99,44,116,121,112,101,41,123,10,32,32,32,32,32,32,32,32,115,119,105,116,99,104,40,116,121,112,101,41,123,10,32,32,32,32,32,32,32,32,99,
        97,115,101,32,34,120,34,58,32,114,101,116,117,114,110,32,40,120,124,48,41,46,116,111,83,116,114,105,110,103,40,49,54,41,59,10,32,32,32,32,32,32,32,32,99,97,115,101,32,34,88,34,58,32,114,101,116,
        117,114,110,32,40,120,124,48,41,46,116,111,83,116,114,105,110,103,40,49,54,41,46,116,111,85,112,112,101,114,67,97,115,101,40,41,59,10,32,32,32,32,32,32,32,32,99,97,115,101,32,34,100,34,58,32,114,
        101,116,117,114,110,32,40,120,124,48,41,46,116,111,83,116,114,105,110,103,40,41,59,10,32,32,32,32,32,32,32,32,99,97,115,101,32,34,102,34,58,32,114,101,116,117,114,110,32,112,97,114,115,101,70,108,
        111,97,116,40,120,41,46,116,111,70,105,120,101,100,40,99,41,59,10,32,32,32,32,32,32,32,32,99,97,115,101,32,34,115,34,58,32,114,101,116,117,114,110,32,120,46,116,111,83,116,114,105,110,103,40,41,
        59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,32,34,34,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,102,117,110,99,116,105,111,110,32,110,117,109,102,111,
        114,109,97,116,40,115,44,120,41,123,10,32,32,32,32,32,32,32,32,108,101,116,32,105,61,115,46,105,110,100,101,120,79,102,40,34,37,34,41,59,10,32,32,32,32,32,32,32,32,108,101,116,32,106,61,105,43,49,
        59,10,32,32,32,32,32,32,32,32,105,102,40,105,60,48,41,10,32,32,32,32,32,32,32,32,32,32,106,61,115,46,108,101,110,103,116,104,59,10,32,32,32,32,32,32,32,32,108,101,116,32,99,61,91,48,44,48,93,44,
        116,121,112,101,61,48,44,109,61,48,44,114,61,34,34,59,10,32,32,32,32,32,32,32,32,105,102,40,115,46,105,110,100,101,120,79,102,40,34,37,115,34,41,62,61,48,41,123,10,32,32,32,32,32,32,32,32,32,32,
        114,101,116,117,114,110,32,115,46,114,101,112,108,97,99,101,40,34,37,115,34,44,120,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,102,111,114,40,59,106,60,115,46,108,101,110,103,
        116,104,59,43,43,106,41,123,10,32,32,32,32,32,32,32,32,32,32,105,102,40,34,100,102,120,88,115,34,46,105,110,100,101,120,79,102,40,115,91,106,93,41,62,61,48,41,123,10,32,32,32,32,32,32,32,32,32,32,
        32,32,116,121,112,101,61,115,91,106,93,59,10,32,32,32,32,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,32,32,105,102,40,115,91,106,
        93,61,61,34,46,34,41,10,32,32,32,32,32,32,32,32,32,32,32,32,109,61,49,59,10,32,32,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,32,32,32,32,99,91,109,93,61,99,91,109,93,42,49,
        48,43,112,97,114,115,101,73,110,116,40,115,91,106,93,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,114,61,118,97,108,115,116,114,40,120,44,99,91,49,93,44,116,121,112,101,41,59,
        10,32,32,32,32,32,32,32,32,105,102,40,99,91,48,93,62,48,41,10,32,32,32,32,32,32,32,32,32,32,114,61,40,34,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,34,43,114,41,46,115,108,105,99,101,40,45,99,
        91,48,93,41,59,10,32,32,32,32,32,32,32,32,114,61,115,46,114,101,112,108,97,99,101,40,47,37,46,42,91,120,88,100,102,115,93,47,44,114,41,59,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,32,114,
        59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,108,101,116,32,115,61,116,104,105,115,46,116,111,111,108,116,105,112,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,100,114,97,103,124,124,
        116,104,105,115,46,104,111,118,101,114,41,123,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,118,97,108,117,101,116,105,112,41,123,10,32,32,32,32,32,32,32,32,32,32,105,102,40,115,61,61,
        110,117,108,108,41,10,32,32,32,32,32,32,32,32,32,32,32,32,115,61,96,37,115,96,59,10,32,32,32,32,32,32,32,32,32,32,101,108,115,101,32,105,102,40,115,46,105,110,100,101,120,79,102,40,34,37,34,41,60,
        48,41,10,32,32,32,32,32,32,32,32,32,32,32,32,115,43,61,96,32,58,32,37,115,96,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,105,102,40,115,41,123,10,32,32,32,32,32,32,32,32,32,32,116,
        104,105,115,46,116,116,102,114,97,109,101,46,105,110,110,101,114,72,84,77,76,61,110,117,109,102,111,114,109,97,116,40,115,44,116,104,105,115,46,99,111,110,118,86,97,108,117,101,41,59,10,32,32,32,
        32,32,32,32,32,32,32,116,104,105,115,46,116,116,102,114,97,109,101,46,115,116,121,108,101,46,100,105,115,112,108,97,121,61,34,105,110,108,105,110,101,45,98,108,111,99,107,34,59,10,32,32,32,32,32,
        32,32,32,32,32,116,104,105,115,46,116,116,102,114,97,109,101,46,115,116,121,108,101,46,119,105,100,116,104,61,34,97,117,116,111,34,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,116,116,
        102,114,97,109,101,46,115,116,121,108,101,46,104,101,105,103,104,116,61,34,97,117,116,111,34,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,116,116,102,114,97,109,101,46,115,116,121,108,
        101,46,116,114,97,110,115,105,116,105,111,110,61,34,111,112,97,99,105,116,121,32,48,46,53,115,32,34,43,100,43,34,115,44,118,105,115,105,98,105,108,105,116,121,32,48,46,53,115,32,34,43,100,43,34,
        115,34,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,116,116,102,114,97,109,101,46,115,116,121,108,101,46,111,112,97,99,105,116,121,61,48,46,57,59,10,32,32,32,32,32,32,32,32,32,32,116,104,
        105,115,46,116,116,102,114,97,109,101,46,115,116,121,108,101,46,118,105,115,105,98,105,108,105,116,121,61,34,118,105,115,105,98,108,101,34,59,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,114,
        99,61,116,104,105,115,46,103,101,116,66,111,117,110,100,105,110,103,67,108,105,101,110,116,82,101,99,116,40,41,44,114,99,50,61,116,104,105,115,46,116,116,102,114,97,109,101,46,103,101,116,66,111,
        117,110,100,105,110,103,67,108,105,101,110,116,82,101,99,116,40,41,44,114,99,51,61,100,111,99,117,109,101,110,116,46,100,111,99,117,109,101,110,116,69,108,101,109,101,110,116,46,103,101,116,66,111,
        117,110,100,105,110,103,67,108,105,101,110,116,82,101,99,116,40,41,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,116,116,102,114,97,109,101,46,115,116,121,108,101,46,108,101,102,116,61,
        40,40,114,99,46,119,105,100,116,104,45,114,99,50,46,119,105,100,116,104,41,42,48,46,53,43,49,48,48,48,41,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,116,116,102,114,97,
        109,101,46,115,116,121,108,101,46,116,111,112,61,40,45,114,99,50,46,104,101,105,103,104,116,45,56,41,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,
        32,32,32,32,125,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,116,104,105,115,46,116,116,102,114,97,109,101,46,115,116,121,108,101,46,116,114,97,110,115,105,116,105,111,110,61,34,111,112,97,99,105,
        116,121,32,48,46,49,115,32,34,43,100,43,34,115,44,118,105,115,105,98,105,108,105,116,121,32,48,46,49,115,32,34,43,100,43,34,115,34,59,10,32,32,32,32,32,32,116,104,105,115,46,116,116,102,114,97,109,
        101,46,115,116,121,108,101,46,111,112,97,99,105,116,121,61,48,59,10,32,32,32,32,32,32,116,104,105,115,46,116,116,102,114,97,109,101,46,115,116,121,108,101,46,118,105,115,105,98,105,108,105,116,121,
        61,34,104,105,100,100,101,110,34,59,10,32,32,32,32,125,10,32,32,32,32,115,101,116,117,112,76,97,98,101,108,40,41,123,10,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,108,112,111,115,61,116,
        104,105,115,46,103,101,116,65,116,116,114,40,34,108,97,98,101,108,112,111,115,34,44,32,34,98,111,116,116,111,109,32,48,112,120,34,41,59,10,32,32,32,32,32,32,99,111,110,115,116,32,108,112,111,115,
        61,116,104,105,115,46,108,97,98,101,108,112,111,115,46,115,112,108,105,116,40,34,32,34,41,59,10,32,32,32,32,32,32,108,101,116,32,111,102,102,115,61,34,34,59,10,32,32,32,32,32,32,105,102,40,108,112,
        111,115,46,108,101,110,103,116,104,61,61,51,41,10,32,32,32,32,32,32,32,32,111,102,102,115,61,96,116,114,97,110,115,108,97,116,101,40,36,123,108,112,111,115,91,49,93,125,44,36,123,108,112,111,115,
        91,50,93,125,41,96,59,10,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,108,46,115,116,121,108,101,46,112,111,115,105,116,105,111,110,61,34,97,98,115,111,108,117,116,101,34,59,10,32,32,32,32,
        32,32,115,119,105,116,99,104,40,108,112,111,115,91,48,93,41,123,10,32,32,32,32,32,32,99,97,115,101,32,34,99,101,110,116,101,114,34,58,10,32,32,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,
        108,46,115,116,121,108,101,46,116,111,112,61,34,53,48,37,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,108,46,115,116,121,108,101,46,108,101,102,116,61,34,53,48,37,34,59,10,32,
        32,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,108,46,115,116,121,108,101,46,116,114,97,110,115,102,111,114,109,61,96,116,114,97,110,115,108,97,116,101,40,45,53,48,37,44,45,53,48,37,41,32,
        36,123,111,102,102,115,125,96,59,10,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,99,97,115,101,32,34,114,105,103,104,116,34,58,10,32,32,32,32,32,32,32,32,116,104,105,115,46,
        108,97,98,101,108,46,115,116,121,108,101,46,116,111,112,61,34,53,48,37,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,108,46,115,116,121,108,101,46,108,101,102,116,61,34,49,48,
        48,37,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,108,46,115,116,121,108,101,46,116,114,97,110,115,102,111,114,109,61,96,116,114,97,110,115,108,97,116,101,89,40,45,53,48,37,
        41,32,36,123,111,102,102,115,125,96,59,10,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,99,97,115,101,32,34,108,101,102,116,34,58,10,32,32,32,32,32,32,32,32,116,104,105,115,46,
        108,97,98,101,108,46,115,116,121,108,101,46,116,111,112,61,34,53,48,37,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,108,46,115,116,121,108,101,46,108,101,102,116,61,34,48,37,
        34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,108,46,115,116,121,108,101,46,116,114,97,110,115,102,111,114,109,61,96,116,114,97,110,115,108,97,116,101,40,45,49,48,48,37,44,45,
        53,48,37,41,32,36,123,111,102,102,115,125,96,59,10,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,99,97,115,101,32,34,98,111,116,116,111,109,34,58,10,32,32,32,32,32,32,32,32,116,
        104,105,115,46,108,97,98,101,108,46,115,116,121,108,101,46,116,111,112,61,34,49,48,48,37,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,108,46,115,116,121,108,101,46,108,101,102,
        116,61,34,53,48,37,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,108,46,115,116,121,108,101,46,116,114,97,110,115,102,111,114,109,61,96,116,114,97,110,115,108,97,116,101,88,40,
        45,53,48,37,41,32,36,123,111,102,102,115,125,96,59,10,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,99,97,115,101,32,34,116,111,112,34,58,10,32,32,32,32,32,32,32,32,116,104,105,
        115,46,108,97,98,101,108,46,115,116,121,108,101,46,116,111,112,61,34,48,37,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,108,46,115,116,121,108,101,46,108,101,102,116,61,34,53,
        48,37,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,108,46,115,116,121,108,101,46,116,114,97,110,115,102,111,114,109,61,96,116,114,97,110,115,108,97,116,101,40,45,53,48,37,44,
        45,49,48,48,37,41,32,36,123,111,102,102,115,125,96,59,10,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,125,10,32,32,32,32,125,10,32,32,32,32,112,111,105,110,116,101,114,111,118,
        101,114,40,101,41,32,123,10,32,32,32,32,32,32,116,104,105,115,46,104,111,118,101,114,61,49,59,10,32,32,32,32,32,32,116,104,105,115,46,115,104,111,119,116,105,112,40,48,46,54,41,59,10,32,32,32,32,
        125,10,32,32,32,32,112,111,105,110,116,101,114,111,117,116,40,101,41,32,123,10,32,32,32,32,32,32,116,104,105,115,46,104,111,118,101,114,61,48,59,10,32,32,32,32,32,32,116,104,105,115,46,115,104,111,
        119,116,105,112,40,48,41,59,10,32,32,32,32,125,10,32,32,32,32,99,111,110,116,101,120,116,77,101,110,117,40,101,41,123,10,32,32,32,32,32,32,105,102,40,119,105,110,100,111,119,46,119,101,98,65,117,
        100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,32,38,38,32,116,104,105,115,46,109,105,100,105,108,101,97,114,110,41,10,32,32,32,32,32,32,32,32,119,101,
        98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,46,99,111,110,116,101,120,116,77,101,110,117,79,112,101,110,40,101,44,116,104,105,115,41,59,10,
        32,32,32,32,32,32,101,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,59,10,32,32,32,
        32,125,10,32,32,32,32,115,101,116,77,105,100,105,67,111,110,116,114,111,108,108,101,114,40,99,104,97,110,110,101,108,44,32,99,99,41,32,123,10,32,32,32,32,32,32,105,102,32,40,116,104,105,115,46,108,
        105,115,116,101,110,105,110,103,84,111,84,104,105,115,77,105,100,105,67,111,110,116,114,111,108,108,101,114,40,99,104,97,110,110,101,108,44,32,99,99,41,41,32,114,101,116,117,114,110,59,10,32,32,
        32,32,32,32,116,104,105,115,46,109,105,100,105,67,111,110,116,114,111,108,108,101,114,61,123,32,39,99,104,97,110,110,101,108,39,58,32,99,104,97,110,110,101,108,44,32,39,99,99,39,58,32,99,99,125,
        59,10,32,32,32,32,32,32,99,111,110,115,111,108,101,46,108,111,103,40,34,65,100,100,101,100,32,109,97,112,112,105,110,103,32,102,111,114,32,99,104,97,110,110,101,108,61,34,32,43,32,99,104,97,110,
        110,101,108,32,43,32,34,32,99,99,61,34,32,43,32,99,99,32,43,32,34,32,116,111,111,108,116,105,112,61,34,32,43,32,116,104,105,115,46,116,111,111,108,116,105,112,41,59,10,32,32,32,32,125,10,32,32,32,
        32,108,105,115,116,101,110,105,110,103,84,111,84,104,105,115,77,105,100,105,67,111,110,116,114,111,108,108,101,114,40,99,104,97,110,110,101,108,44,32,99,99,41,32,123,10,32,32,32,32,32,32,99,111,
        110,115,116,32,99,32,61,32,116,104,105,115,46,109,105,100,105,67,111,110,116,114,111,108,108,101,114,59,10,32,32,32,32,32,32,105,102,40,40,99,46,99,104,97,110,110,101,108,32,61,61,61,32,99,104,97,
        110,110,101,108,32,124,124,32,99,46,99,104,97,110,110,101,108,32,60,32,48,41,32,38,38,32,99,46,99,99,32,61,61,61,32,99,99,41,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,32,116,114,117,101,
        59,10,32,32,32,32,32,32,114,101,116,117,114,110,32,102,97,108,115,101,59,10,32,32,32,32,125,10,32,32,32,32,112,114,111,99,101,115,115,77,105,100,105,69,118,101,110,116,40,101,118,101,110,116,41,
        123,10,32,32,32,32,32,32,99,111,110,115,116,32,99,104,97,110,110,101,108,32,61,32,101,118,101,110,116,46,100,97,116,97,91,48,93,32,38,32,48,120,102,59,10,32,32,32,32,32,32,99,111,110,115,116,32,
        99,111,110,116,114,111,108,78,117,109,98,101,114,32,61,32,101,118,101,110,116,46,100,97,116,97,91,49,93,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,109,105,100,105,77,111,100,101,32,61,
        61,32,39,108,101,97,114,110,39,41,32,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,77,105,100,105,67,111,110,116,114,111,108,108,101,114,40,99,104,97,110,110,101,108,44,32,99,111,
        110,116,114,111,108,78,117,109,98,101,114,41,59,10,32,32,32,32,32,32,32,32,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,46,99,111,
        110,116,101,120,116,77,101,110,117,67,108,111,115,101,40,41,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,77,111,100,101,32,61,32,39,110,111,114,109,97,108,39,59,10,32,32,32,32,
        32,32,32,32,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,46,112,114,101,115,101,114,118,101,77,105,100,105,76,101,97,114,110,40,41,
        59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,108,105,115,116,101,110,105,110,103,84,111,84,104,105,115,77,105,100,105,67,111,110,116,114,111,108,108,101,114,40,
        99,104,97,110,110,101,108,44,32,99,111,110,116,114,111,108,78,117,109,98,101,114,41,41,32,123,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,116,97,103,78,97,109,101,61,61,34,87,69,66,
        65,85,68,73,79,45,83,87,73,84,67,72,34,41,123,10,32,32,32,32,32,32,32,32,32,32,115,119,105,116,99,104,40,116,104,105,115,46,116,121,112,101,41,123,10,32,32,32,32,32,32,32,32,32,32,99,97,115,101,
        32,34,116,111,103,103,108,101,34,58,10,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,101,118,101,110,116,46,100,97,116,97,91,50,93,62,61,54,52,41,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,116,
        104,105,115,46,115,101,116,86,97,108,117,101,40,49,45,116,104,105,115,46,118,97,108,117,101,44,116,114,117,101,41,59,10,32,32,32,32,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,
        32,32,32,32,32,99,97,115,101,32,34,107,105,99,107,34,58,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,101,118,101,110,116,46,100,97,116,97,91,50,93,62,
        61,54,52,63,49,58,48,41,59,10,32,32,32,32,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,32,32,32,32,99,97,115,101,32,34,114,97,100,105,111,34,58,10,32,32,32,32,32,32,32,32,32,
        32,32,32,108,101,116,32,101,108,115,61,100,111,99,117,109,101,110,116,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,34,119,101,98,97,117,100,105,111,45,115,119,105,116,99,104,
        91,116,121,112,101,61,39,114,97,100,105,111,39,93,91,103,114,111,117,112,61,39,34,43,116,104,105,115,46,103,114,111,117,112,43,34,39,93,34,41,59,10,32,32,32,32,32,32,32,32,32,32,32,32,102,111,114,
        40,108,101,116,32,105,61,48,59,105,60,101,108,115,46,108,101,110,103,116,104,59,43,43,105,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,101,108,115,91,105,93,61,61,116,104,105,115,
        41,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,101,108,115,91,105,93,46,115,101,116,86,97,108,117,101,40,49,41,59,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,
        32,32,32,32,32,32,32,32,32,32,32,32,32,101,108,115,91,105,93,46,115,101,116,86,97,108,117,101,40,48,41,59,10,32,32,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,32,32,32,32,98,114,
        101,97,107,59,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,101,108,115,101,123,10,32,32,32,32,32,32,32,32,32,32,99,111,110,115,116,32,118,97,108,
        32,61,32,116,104,105,115,46,109,105,110,43,40,116,104,105,115,46,109,97,120,45,116,104,105,115,46,109,105,110,41,42,101,118,101,110,116,46,100,97,116,97,91,50,93,47,49,50,55,59,10,32,32,32,32,32,
        32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,118,97,108,44,32,116,114,117,101,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,125,10,32,32,32,32,125,10,32,32,125,
        10,10,116,114,121,123,10,32,32,32,32,99,117,115,116,111,109,69,108,101,109,101,110,116,115,46,100,101,102,105,110,101,40,34,119,101,98,97,117,100,105,111,45,107,110,111,98,34,44,32,99,108,97,115,
        115,32,87,101,98,65,117,100,105,111,75,110,111,98,32,101,120,116,101,110,100,115,32,87,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,32,123,10,32,32,32,32,99,111,
        110,115,116,114,117,99,116,111,114,40,41,123,10,32,32,32,32,32,32,115,117,112,101,114,40,41,59,10,32,32,32,32,125,10,32,32,32,32,99,111,110,110,101,99,116,101,100,67,97,108,108,98,97,99,107,40,41,
        123,10,32,32,32,32,32,32,108,101,116,32,114,111,111,116,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,97,116,116,97,99,104,83,104,97,100,111,119,41,10,32,32,32,32,32,32,32,32,114,111,111,
        116,61,116,104,105,115,46,97,116,116,97,99,104,83,104,97,100,111,119,40,123,109,111,100,101,58,32,39,111,112,101,110,39,125,41,59,10,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,
        114,111,111,116,61,116,104,105,115,59,10,32,32,32,32,32,32,114,111,111,116,46,105,110,110,101,114,72,84,77,76,61,10,96,60,115,116,121,108,101,62,10,36,123,116,104,105,115,46,98,97,115,101,115,116,
        121,108,101,125,10,58,104,111,115,116,123,10,32,32,100,105,115,112,108,97,121,58,105,110,108,105,110,101,45,98,108,111,99,107,59,10,32,32,109,97,114,103,105,110,58,48,59,10,32,32,112,97,100,100,
        105,110,103,58,48,59,10,32,32,99,117,114,115,111,114,58,112,111,105,110,116,101,114,59,10,32,32,102,111,110,116,45,102,97,109,105,108,121,58,32,115,97,110,115,45,115,101,114,105,102,59,10,32,32,
        102,111,110,116,45,115,105,122,101,58,32,49,49,112,120,59,10,125,10,46,119,101,98,97,117,100,105,111,45,107,110,111,98,45,98,111,100,121,123,10,32,32,100,105,115,112,108,97,121,58,105,110,108,105,
        110,101,45,98,108,111,99,107,59,10,32,32,112,111,115,105,116,105,111,110,58,114,101,108,97,116,105,118,101,59,10,32,32,109,97,114,103,105,110,58,48,59,10,32,32,112,97,100,100,105,110,103,58,48,59,
        10,32,32,118,101,114,116,105,99,97,108,45,97,108,105,103,110,58,98,111,116,116,111,109,59,10,32,32,119,104,105,116,101,45,115,112,97,99,101,58,112,114,101,59,10,125,10,60,47,115,116,121,108,101,
        62,10,60,100,105,118,32,99,108,97,115,115,61,39,119,101,98,97,117,100,105,111,45,107,110,111,98,45,98,111,100,121,39,32,116,97,98,105,110,100,101,120,61,39,49,39,32,116,111,117,99,104,45,97,99,116,
        105,111,110,61,39,110,111,110,101,39,62,60,100,105,118,32,99,108,97,115,115,61,39,119,101,98,97,117,100,105,111,99,116,114,108,45,116,111,111,108,116,105,112,39,62,60,47,100,105,118,62,60,100,105,
        118,32,112,97,114,116,61,34,108,97,98,101,108,34,32,99,108,97,115,115,61,34,119,101,98,97,117,100,105,111,99,116,114,108,45,108,97,98,101,108,34,62,60,115,108,111,116,62,60,47,115,108,111,116,62,
        60,47,100,105,118,62,60,47,100,105,118,62,10,96,59,10,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,61,114,111,111,116,46,99,104,105,108,100,78,111,100,101,115,91,50,93,59,10,32,32,32,32,
        32,32,116,104,105,115,46,116,116,102,114,97,109,101,61,116,104,105,115,46,101,108,101,109,46,102,105,114,115,116,67,104,105,108,100,59,10,32,32,32,32,32,32,116,104,105,115,46,108,97,98,101,108,61,
        116,104,105,115,46,116,116,102,114,97,109,101,46,110,101,120,116,83,105,98,108,105,110,103,59,10,32,32,32,32,32,32,116,104,105,115,46,101,110,97,98,108,101,61,116,104,105,115,46,103,101,116,65,116,
        116,114,40,34,101,110,97,98,108,101,34,44,49,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,115,114,99,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,115,114,99,34,44,111,112,116,46,107,
        110,111,98,83,114,99,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,115,114,99,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,
        80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,115,114,99,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,115,114,99,125,44,115,101,116,58,40,118,
        41,61,62,123,116,104,105,115,46,95,115,114,99,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,118,97,108,117,101,
        61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,118,97,108,117,101,34,44,48,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,118,97,
        108,117,101,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,118,97,108,117,101,34,44,123,103,101,116,58,40,41,61,62,123,114,101,
        116,117,114,110,32,116,104,105,115,46,95,118,97,108,117,101,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,118,97,108,117,101,61,118,59,116,104,105,115,46,114,101,100,114,97,119,
        40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,100,101,102,118,97,108,117,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,100,101,102,118,97,108,117,101,34,44,116,104,105,
        115,46,95,118,97,108,117,101,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,109,105,110,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,109,105,110,34,44,48,41,59,32,105,102,32,40,33,116,
        104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,109,105,110,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,
        44,34,109,105,110,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,109,105,110,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,109,105,110,
        61,43,118,59,116,104,105,115,46,114,101,100,114,97,119,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,109,97,120,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,109,97,120,
        34,44,49,48,48,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,109,97,120,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,
        111,112,101,114,116,121,40,116,104,105,115,44,34,109,97,120,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,109,97,120,125,44,115,101,116,58,40,118,41,61,
        62,123,116,104,105,115,46,95,109,97,120,61,43,118,59,116,104,105,115,46,114,101,100,114,97,119,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,115,116,101,112,61,116,104,105,115,46,
        103,101,116,65,116,116,114,40,34,115,116,101,112,34,44,49,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,115,116,101,112,34,41,41,32,79,98,
        106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,115,116,101,112,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,
        115,46,95,115,116,101,112,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,115,116,101,112,61,43,118,59,116,104,105,115,46,114,101,100,114,97,119,40,41,125,125,41,59,10,32,32,32,32,
        32,32,116,104,105,115,46,95,115,112,114,105,116,101,115,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,115,112,114,105,116,101,115,34,44,111,112,116,46,107,110,111,98,83,112,114,105,116,
        101,115,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,115,112,114,105,116,101,115,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,
        101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,115,112,114,105,116,101,115,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,115,112,114,105,
        116,101,115,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,115,112,114,105,116,101,115,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,
        32,32,32,32,32,32,116,104,105,115,46,95,119,105,100,116,104,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,119,105,100,116,104,34,44,32,110,117,108,108,41,59,32,105,102,32,40,33,116,104,
        105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,119,105,100,116,104,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,
        115,44,34,119,105,100,116,104,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,119,105,100,116,104,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,
        115,46,95,119,105,100,116,104,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,104,101,105,103,104,116,61,116,104,
        105,115,46,103,101,116,65,116,116,114,40,34,104,101,105,103,104,116,34,44,32,110,117,108,108,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,
        34,104,101,105,103,104,116,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,104,101,105,103,104,116,34,44,123,103,101,116,58,40,
        41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,104,101,105,103,104,116,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,104,101,105,103,104,116,61,118,59,116,104,105,
        115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,100,105,97,109,101,116,101,114,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,
        100,105,97,109,101,116,101,114,34,44,32,110,117,108,108,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,100,105,97,109,101,116,101,114,34,
        41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,100,105,97,109,101,116,101,114,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,
        117,114,110,32,116,104,105,115,46,95,100,105,97,109,101,116,101,114,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,100,105,97,109,101,116,101,114,61,118,59,116,104,105,115,46,115,
        101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,99,111,108,111,114,115,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,99,111,108,111,114,
        115,34,44,111,112,116,46,107,110,111,98,67,111,108,111,114,115,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,99,111,108,111,114,115,34,41,
        41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,99,111,108,111,114,115,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,
        110,32,116,104,105,115,46,95,99,111,108,111,114,115,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,99,111,108,111,114,115,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,
        97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,111,117,116,108,105,110,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,111,117,116,108,105,110,101,34,44,111,112,
        116,46,111,117,116,108,105,110,101,41,59,10,32,32,32,32,32,32,116,104,105,115,46,115,101,116,117,112,76,97,98,101,108,40,41,59,10,32,32,32,32,32,32,116,104,105,115,46,108,111,103,61,116,104,105,
        115,46,103,101,116,65,116,116,114,40,34,108,111,103,34,44,48,41,59,10,32,32,32,32,32,32,116,104,105,115,46,115,101,110,115,105,116,105,118,105,116,121,61,116,104,105,115,46,103,101,116,65,116,116,
        114,40,34,115,101,110,115,105,116,105,118,105,116,121,34,44,49,41,59,10,32,32,32,32,32,32,116,104,105,115,46,118,97,108,117,101,116,105,112,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,
        118,97,108,117,101,116,105,112,34,44,111,112,116,46,118,97,108,117,101,116,105,112,41,59,10,32,32,32,32,32,32,116,104,105,115,46,116,111,111,108,116,105,112,61,116,104,105,115,46,103,101,116,65,
        116,116,114,40,34,116,111,111,108,116,105,112,34,44,110,117,108,108,41,59,10,32,32,32,32,32,32,116,104,105,115,46,99,111,110,118,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,99,111,110,
        118,34,44,110,117,108,108,41,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,99,111,110,118,41,123,10,32,32,32,32,32,32,32,32,99,111,110,115,116,32,120,61,116,104,105,115,46,95,118,97,108,
        117,101,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,99,111,110,118,86,97,108,117,101,61,101,118,97,108,40,116,104,105,115,46,99,111,110,118,41,59,10,32,32,32,32,32,32,32,32,105,102,40,116,121,
        112,101,111,102,40,116,104,105,115,46,99,111,110,118,86,97,108,117,101,41,61,61,34,102,117,110,99,116,105,111,110,34,41,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,111,110,118,86,97,108,
        117,101,61,116,104,105,115,46,99,111,110,118,86,97,108,117,101,40,120,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,116,104,105,115,46,99,111,110,
        118,86,97,108,117,101,61,116,104,105,115,46,95,118,97,108,117,101,59,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,108,101,97,114,110,61,116,104,105,115,46,103,101,116,65,116,116,114,40,
        34,109,105,100,105,108,101,97,114,110,34,44,111,112,116,46,109,105,100,105,108,101,97,114,110,41,59,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,99,99,61,116,104,105,115,46,103,101,116,
        65,116,116,114,40,34,109,105,100,105,99,99,34,44,110,117,108,108,41,59,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,67,111,110,116,114,111,108,108,101,114,61,123,125,59,10,32,32,32,32,
        32,32,116,104,105,115,46,109,105,100,105,77,111,100,101,61,34,110,111,114,109,97,108,34,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,109,105,100,105,99,99,41,32,123,10,32,32,32,32,32,32,
        32,32,32,32,108,101,116,32,99,104,32,61,32,112,97,114,115,101,73,110,116,40,116,104,105,115,46,109,105,100,105,99,99,46,115,117,98,115,116,114,105,110,103,40,48,44,32,116,104,105,115,46,109,105,
        100,105,99,99,46,108,97,115,116,73,110,100,101,120,79,102,40,34,46,34,41,41,41,32,45,32,49,59,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,99,99,32,61,32,112,97,114,115,101,73,110,116,40,116,
        104,105,115,46,109,105,100,105,99,99,46,115,117,98,115,116,114,105,110,103,40,116,104,105,115,46,109,105,100,105,99,99,46,108,97,115,116,73,110,100,101,120,79,102,40,34,46,34,41,32,43,32,49,41,41,
        59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,77,105,100,105,67,111,110,116,114,111,108,108,101,114,40,99,104,44,32,99,99,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,
        105,102,40,116,104,105,115,46,109,105,100,105,108,101,97,114,110,32,38,38,32,116,104,105,115,46,105,100,41,123,10,32,32,32,32,32,32,32,32,105,102,40,119,101,98,65,117,100,105,111,67,111,110,116,
        114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,32,38,38,32,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,46,109,105,
        100,105,76,101,97,114,110,84,97,98,108,101,41,123,10,32,32,32,32,32,32,32,32,32,32,99,111,110,115,116,32,109,108,61,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,
        116,77,97,110,97,103,101,114,46,109,105,100,105,76,101,97,114,110,84,97,98,108,101,59,10,32,32,32,32,32,32,32,32,32,32,102,111,114,40,108,101,116,32,105,61,48,59,32,105,32,60,32,109,108,46,108,101,
        110,103,116,104,59,32,43,43,105,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,109,108,91,105,93,46,105,100,61,61,116,104,105,115,46,105,100,41,123,10,32,32,32,32,32,32,32,32,32,32,32,
        32,32,32,116,104,105,115,46,115,101,116,77,105,100,105,67,111,110,116,114,111,108,108,101,114,40,109,108,91,105,93,46,99,99,46,99,104,97,110,110,101,108,44,32,109,108,91,105,93,46,99,99,46,99,99,
        41,59,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,125,10,32,32,32,
        32,32,32,125,10,32,32,32,32,32,32,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,59,10,32,32,32,32,32,32,116,104,105,115,46,100,105,103,105,116,115,61,48,59,10,32,32,32,32,32,32,
        105,102,40,116,104,105,115,46,115,116,101,112,32,38,38,32,116,104,105,115,46,115,116,101,112,32,60,32,49,41,32,123,10,32,32,32,32,32,32,32,32,102,111,114,40,108,101,116,32,110,32,61,32,116,104,105,
        115,46,115,116,101,112,32,59,32,110,32,60,32,49,59,32,110,32,42,61,32,49,48,41,10,32,32,32,32,32,32,32,32,32,32,43,43,116,104,105,115,46,100,105,103,105,116,115,59,10,32,32,32,32,32,32,125,10,32,
        32,32,32,32,32,116,104,105,115,46,95,115,101,116,86,97,108,117,101,40,116,104,105,115,46,95,118,97,108,117,101,41,59,10,32,32,32,32,32,32,116,104,105,115,46,99,111,108,116,97,98,61,91,34,35,101,
        48,48,34,44,34,35,48,48,48,34,44,34,35,48,48,48,34,93,59,10,32,32,32,32,32,32,105,102,40,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,
        116,77,97,110,97,103,101,114,41,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,
        46,97,100,100,87,105,100,103,101,116,40,116,104,105,115,41,59,10,32,32,32,32,125,10,32,32,32,32,100,105,115,99,111,110,110,101,99,116,101,100,67,97,108,108,98,97,99,107,40,41,123,125,10,32,32,32,
        32,115,101,116,117,112,73,109,97,103,101,40,41,123,10,32,32,32,32,32,32,116,104,105,115,46,107,119,61,116,104,105,115,46,95,119,105,100,116,104,124,124,116,104,105,115,46,95,100,105,97,109,101,116,
        101,114,124,124,111,112,116,46,107,110,111,98,87,105,100,116,104,124,124,111,112,116,46,107,110,111,98,68,105,97,109,101,116,101,114,59,10,32,32,32,32,32,32,116,104,105,115,46,107,104,61,116,104,
        105,115,46,95,104,101,105,103,104,116,124,124,116,104,105,115,46,95,100,105,97,109,101,116,101,114,124,124,111,112,116,46,107,110,111,98,72,101,105,103,104,116,124,124,111,112,116,46,107,110,111,
        98,68,105,97,109,101,116,101,114,59,10,32,32,32,32,32,32,105,102,40,33,116,104,105,115,46,115,114,99,41,123,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,99,111,108,111,114,115,41,10,
        32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,111,108,116,97,98,32,61,32,116,104,105,115,46,99,111,108,111,114,115,46,115,112,108,105,116,40,34,59,34,41,59,10,32,32,32,32,32,32,32,32,105,102,
        40,33,116,104,105,115,46,99,111,108,116,97,98,41,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,111,108,116,97,98,61,91,34,35,101,48,48,34,44,34,35,48,48,48,34,44,34,35,48,48,48,34,93,59,
        10,32,32,32,32,32,32,32,32,108,101,116,32,115,118,103,61,10,96,60,115,118,103,32,120,109,108,110,115,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,50,48,48,48,47,115,118,
        103,34,32,119,105,100,116,104,61,34,54,52,34,32,104,101,105,103,104,116,61,34,54,52,54,52,34,32,112,114,101,115,101,114,118,101,65,115,112,101,99,116,82,97,116,105,111,61,34,110,111,110,101,34,62,
        10,60,100,101,102,115,62,10,32,32,60,102,105,108,116,101,114,32,105,100,61,34,102,49,34,62,10,32,32,32,32,60,102,101,71,97,117,115,115,105,97,110,66,108,117,114,32,105,110,61,34,83,111,117,114,99,
        101,71,114,97,112,104,105,99,34,32,115,116,100,68,101,118,105,97,116,105,111,110,61,34,48,46,56,34,32,47,62,10,32,32,60,47,102,105,108,116,101,114,62,10,32,32,60,114,97,100,105,97,108,71,114,97,
        100,105,101,110,116,32,105,100,61,34,103,49,34,32,99,120,61,34,53,48,37,34,32,99,121,61,34,49,48,37,34,62,10,32,32,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,48,37,34,32,115,116,111,
        112,45,99,111,108,111,114,61,34,36,123,116,104,105,115,46,99,111,108,116,97,98,91,50,93,125,34,47,62,10,32,32,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,49,48,48,37,34,32,115,116,
        111,112,45,99,111,108,111,114,61,34,36,123,116,104,105,115,46,99,111,108,116,97,98,91,49,93,125,34,47,62,10,32,32,60,47,114,97,100,105,97,108,71,114,97,100,105,101,110,116,62,10,32,32,60,108,105,
        110,101,97,114,71,114,97,100,105,101,110,116,32,105,100,61,34,103,50,34,32,120,49,61,34,48,37,34,32,121,49,61,34,48,37,34,32,120,50,61,34,48,37,34,32,121,50,61,34,49,48,48,37,34,62,10,32,32,32,32,
        60,115,116,111,112,32,111,102,102,115,101,116,61,34,48,37,34,32,115,116,111,112,45,99,111,108,111,114,61,34,35,48,48,48,34,32,115,116,111,112,45,111,112,97,99,105,116,121,61,34,48,34,47,62,10,32,
        32,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,49,48,48,37,34,32,115,116,111,112,45,99,111,108,111,114,61,34,35,48,48,48,34,32,115,116,111,112,45,111,112,97,99,105,116,121,61,34,48,
        46,51,34,47,62,10,32,32,60,47,108,105,110,101,97,114,71,114,97,100,105,101,110,116,62,10,32,32,60,103,32,105,100,61,34,66,34,62,10,32,32,32,32,60,99,105,114,99,108,101,32,99,120,61,34,51,50,34,32,
        99,121,61,34,51,50,34,32,114,61,34,51,49,34,32,102,105,108,108,61,34,35,48,48,48,34,47,62,10,32,32,32,32,60,99,105,114,99,108,101,32,99,120,61,34,51,50,34,32,99,121,61,34,51,50,34,32,114,61,34,50,
        57,34,32,102,105,108,108,61,34,117,114,108,40,35,103,49,41,34,47,62,10,32,32,32,32,60,99,105,114,99,108,101,32,99,120,61,34,51,50,34,32,99,121,61,34,51,50,34,32,114,61,34,50,57,34,32,102,105,108,
        108,61,34,117,114,108,40,35,103,50,41,34,47,62,10,32,32,32,32,60,99,105,114,99,108,101,32,99,120,61,34,51,50,34,32,99,121,61,34,51,50,34,32,114,61,34,50,53,34,32,102,105,108,108,61,34,36,123,116,
        104,105,115,46,99,111,108,116,97,98,91,49,93,125,34,32,102,105,108,116,101,114,61,34,117,114,108,40,35,102,49,41,34,47,62,10,32,32,32,32,60,99,105,114,99,108,101,32,99,120,61,34,51,50,34,32,99,121,
        61,34,51,50,34,32,114,61,34,50,57,34,32,102,105,108,108,61,34,117,114,108,40,35,103,50,41,34,47,62,10,32,32,60,47,103,62,10,32,32,60,108,105,110,101,32,105,100,61,34,75,34,32,120,49,61,34,51,50,
        34,32,121,49,61,34,50,53,34,32,120,50,61,34,51,50,34,32,121,50,61,34,49,49,34,32,115,116,114,111,107,101,45,108,105,110,101,99,97,112,61,34,114,111,117,110,100,34,32,115,116,114,111,107,101,45,119,
        105,100,116,104,61,34,54,34,32,115,116,114,111,107,101,61,34,36,123,116,104,105,115,46,99,111,108,116,97,98,91,48,93,125,34,47,62,10,60,47,100,101,102,115,62,96,59,10,32,32,32,32,32,32,32,32,102,
        111,114,40,108,101,116,32,105,61,48,59,105,60,49,48,49,59,43,43,105,41,123,10,32,32,32,32,32,32,32,32,32,32,115,118,103,32,43,61,32,96,60,117,115,101,32,104,114,101,102,61,34,35,66,34,32,121,61,
        34,36,123,54,52,42,105,125,34,47,62,60,117,115,101,32,104,114,101,102,61,34,35,75,34,32,121,61,34,36,123,54,52,42,105,125,34,32,116,114,97,110,115,102,111,114,109,61,34,114,111,116,97,116,101,40,
        36,123,40,45,49,51,53,43,50,55,48,42,105,47,49,48,49,41,46,116,111,70,105,120,101,100,40,50,41,125,44,51,50,44,36,123,54,52,42,105,43,51,50,125,41,34,47,62,96,59,10,32,32,32,32,32,32,32,32,125,10,
        32,32,32,32,32,32,32,32,115,118,103,32,43,61,32,34,60,47,115,118,103,62,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,98,97,99,107,103,114,111,117,
        110,100,73,109,97,103,101,32,61,32,34,117,114,108,40,100,97,116,97,58,105,109,97,103,101,47,115,118,103,43,120,109,108,59,98,97,115,101,54,52,44,34,43,98,116,111,97,40,115,118,103,41,43,34,41,34,
        59,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,107,119,61,61,110,117,108,108,41,32,116,104,105,115,46,107,119,61,54,52,59,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,107,
        104,61,61,110,117,108,108,41,32,116,104,105,115,46,107,104,61,54,52,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,
        83,105,122,101,32,61,32,96,36,123,116,104,105,115,46,107,119,125,112,120,32,36,123,116,104,105,115,46,107,104,42,49,48,49,125,112,120,96,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,
        101,109,46,115,116,121,108,101,46,119,105,100,116,104,61,116,104,105,115,46,107,119,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,104,
        101,105,103,104,116,61,116,104,105,115,46,107,104,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,116,121,108,101,46,104,101,105,103,104,116,61,116,104,105,115,46,107,104,43,
        34,112,120,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,102,105,114,101,102,108,97,103,61,116,114,117,101,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,97,119,40,41,59,
        10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,101,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,105,109,103,61,110,101,119,32,
        73,109,97,103,101,40,41,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,105,109,103,46,111,110,108,111,97,100,61,40,41,61,62,123,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,
        109,46,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,73,109,97,103,101,32,61,32,34,117,114,108,40,34,43,40,116,104,105,115,46,115,114,99,41,43,34,41,34,59,10,32,32,32,32,32,32,32,32,
        32,32,105,102,40,116,104,105,115,46,95,115,112,114,105,116,101,115,61,61,110,117,108,108,41,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,95,115,112,114,105,116,101,115,61,116,104,105,
        115,46,105,109,103,46,104,101,105,103,104,116,47,116,104,105,115,46,105,109,103,46,119,105,100,116,104,32,45,32,49,59,10,32,32,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,
        32,32,32,32,116,104,105,115,46,95,115,112,114,105,116,101,115,61,43,116,104,105,115,46,95,115,112,114,105,116,101,115,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,107,119,61,
        61,110,117,108,108,41,32,116,104,105,115,46,107,119,61,116,104,105,115,46,105,109,103,46,119,105,100,116,104,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,107,104,61,61,110,117,
        108,108,41,32,116,104,105,115,46,107,104,61,116,104,105,115,46,105,109,103,46,104,101,105,103,104,116,47,40,116,104,105,115,46,115,112,114,105,116,101,115,43,49,41,59,10,32,32,32,32,32,32,32,32,
        32,32,105,102,40,33,116,104,105,115,46,115,112,114,105,116,101,115,41,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,98,97,99,107,103,114,111,
        117,110,100,83,105,122,101,32,61,32,34,49,48,48,37,32,49,48,48,37,34,59,10,32,32,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,
        46,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,83,105,122,101,32,61,32,96,36,123,116,104,105,115,46,107,119,125,112,120,32,36,123,116,104,105,115,46,107,104,42,40,116,104,105,115,
        46,115,112,114,105,116,101,115,43,49,41,125,112,120,96,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,119,105,100,116,104,61,116,104,105,115,46,
        107,119,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,104,101,105,103,104,116,61,116,104,105,115,46,107,104,43,34,112,120,34,59,
        10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,116,121,108,101,46,104,101,105,103,104,116,61,116,104,105,115,46,107,104,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,
        115,46,114,101,100,114,97,119,40,41,59,10,32,32,32,32,32,32,32,32,125,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,105,109,103,46,115,114,99,61,116,104,105,115,46,115,114,99,59,10,32,32,32,32,
        32,32,125,10,32,32,32,32,125,10,32,32,32,32,114,101,100,114,97,119,40,41,32,123,10,32,32,32,32,32,32,108,101,116,32,114,97,116,105,111,59,10,32,32,32,32,32,32,116,104,105,115,46,100,105,103,105,
        116,115,61,48,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,115,116,101,112,32,38,38,32,116,104,105,115,46,115,116,101,112,32,60,32,49,41,32,123,10,32,32,32,32,32,32,32,32,102,111,114,40,
        108,101,116,32,110,32,61,32,116,104,105,115,46,115,116,101,112,32,59,32,110,32,60,32,49,59,32,110,32,42,61,32,49,48,41,10,32,32,32,32,32,32,32,32,32,32,43,43,116,104,105,115,46,100,105,103,105,116,
        115,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,118,97,108,117,101,60,116,104,105,115,46,109,105,110,41,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,118,97,
        108,117,101,61,116,104,105,115,46,109,105,110,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,118,97,108,117,101,62,116,104,105,115,46,109,97,120,41,123,10,32,32,32,
        32,32,32,32,32,116,104,105,115,46,118,97,108,117,101,61,116,104,105,115,46,109,97,120,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,108,111,103,41,10,32,32,32,32,
        32,32,32,32,114,97,116,105,111,32,61,32,77,97,116,104,46,108,111,103,40,116,104,105,115,46,118,97,108,117,101,47,116,104,105,115,46,109,105,110,41,32,47,32,77,97,116,104,46,108,111,103,40,116,104,
        105,115,46,109,97,120,47,116,104,105,115,46,109,105,110,41,59,10,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,114,97,116,105,111,32,61,32,40,116,104,105,115,46,118,97,108,117,101,
        32,45,32,116,104,105,115,46,109,105,110,41,32,47,32,40,116,104,105,115,46,109,97,120,32,45,32,116,104,105,115,46,109,105,110,41,59,10,32,32,32,32,32,32,108,101,116,32,115,116,121,108,101,32,61,32,
        116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,59,10,32,32,32,32,32,32,108,101,116,32,115,112,32,61,32,116,104,105,115,46,115,114,99,63,116,104,105,115,46,115,112,114,105,116,101,115,
        58,49,48,48,59,10,32,32,32,32,32,32,105,102,40,115,112,62,61,49,41,123,10,32,32,32,32,32,32,32,32,108,101,116,32,111,102,102,115,101,116,32,61,32,40,115,112,32,42,32,114,97,116,105,111,41,32,124,
        32,48,59,10,32,32,32,32,32,32,32,32,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,80,111,115,105,116,105,111,110,32,61,32,34,48,112,120,32,34,32,43,32,40,45,111,102,102,115,101,116,
        42,116,104,105,115,46,107,104,41,32,43,32,34,112,120,34,59,10,32,32,32,32,32,32,32,32,115,116,121,108,101,46,116,114,97,110,115,102,111,114,109,32,61,32,39,114,111,116,97,116,101,40,50,50,53,100,
        101,103,41,39,59,10,32,32,32,32,32,32,125,32,101,108,115,101,32,123,10,32,32,32,32,32,32,32,32,108,101,116,32,100,101,103,32,61,32,50,50,53,32,43,32,50,55,48,32,42,32,40,114,97,116,105,111,32,45,
        32,48,46,53,41,59,10,32,32,32,32,32,32,32,32,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,80,111,115,105,116,105,111,110,61,34,48,112,120,32,48,112,120,34,59,10,32,32,32,32,32,32,
        32,32,115,116,121,108,101,46,116,114,97,110,115,102,111,114,109,32,61,32,39,114,111,116,97,116,101,40,39,32,43,32,100,101,103,32,43,32,39,100,101,103,41,39,59,10,32,32,32,32,32,32,125,10,32,32,32,
        32,125,10,32,32,32,32,95,115,101,116,86,97,108,117,101,40,118,41,123,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,115,116,101,112,41,10,32,32,32,32,32,32,32,32,118,61,40,77,97,116,104,46,114,
        111,117,110,100,40,40,118,45,116,104,105,115,46,109,105,110,41,47,116,104,105,115,46,115,116,101,112,41,41,42,116,104,105,115,46,115,116,101,112,43,116,104,105,115,46,109,105,110,59,10,32,32,32,
        32,32,32,116,104,105,115,46,95,118,97,108,117,101,61,77,97,116,104,46,109,105,110,40,116,104,105,115,46,109,97,120,44,77,97,116,104,46,109,97,120,40,116,104,105,115,46,109,105,110,44,118,41,41,59,
        10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,118,97,108,117,101,33,61,116,104,105,115,46,111,108,100,118,97,108,117,101,41,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,102,105,114,
        101,102,108,97,103,61,116,114,117,101,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,111,108,100,118,97,108,117,101,61,116,104,105,115,46,95,118,97,108,117,101,59,10,32,32,32,32,32,32,32,32,105,
        102,40,116,104,105,115,46,99,111,110,118,41,123,10,32,32,32,32,32,32,32,32,32,32,99,111,110,115,116,32,120,61,116,104,105,115,46,95,118,97,108,117,101,59,10,32,32,32,32,32,32,32,32,32,32,116,104,
        105,115,46,99,111,110,118,86,97,108,117,101,61,101,118,97,108,40,116,104,105,115,46,99,111,110,118,41,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,121,112,101,111,102,40,116,104,105,115,46,
        99,111,110,118,86,97,108,117,101,41,61,61,34,102,117,110,99,116,105,111,110,34,41,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,111,110,118,86,97,108,117,101,61,116,104,105,115,46,
        99,111,110,118,86,97,108,117,101,40,120,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,111,110,118,86,97,108,
        117,101,61,116,104,105,115,46,95,118,97,108,117,101,59,10,32,32,32,32,32,32,32,32,105,102,40,116,121,112,101,111,102,40,116,104,105,115,46,99,111,110,118,86,97,108,117,101,41,61,61,34,110,117,109,
        98,101,114,34,41,123,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,111,110,118,86,97,108,117,101,61,116,104,105,115,46,99,111,110,118,86,97,108,117,101,46,116,111,70,105,120,101,100,40,
        116,104,105,115,46,100,105,103,105,116,115,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,97,119,40,41,59,10,32,32,32,32,32,32,32,32,116,104,105,
        115,46,115,104,111,119,116,105,112,40,48,41,59,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,32,49,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,114,101,116,117,114,110,32,48,59,10,32,32,
        32,32,125,10,32,32,32,32,115,101,116,86,97,108,117,101,40,118,44,102,41,123,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,115,101,116,86,97,108,117,101,40,118,41,32,38,38,32,102,41,10,32,
        32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,100,69,118,101,110,116,40,34,105,110,112,117,116,34,41,44,116,104,105,115,46,115,101,110,100,69,118,101,110,116,40,34,99,104,97,110,103,101,34,
        41,59,10,32,32,32,32,125,10,32,32,32,32,107,101,121,100,111,119,110,40,101,41,123,10,32,32,32,32,32,32,99,111,110,115,116,32,100,101,108,116,97,32,61,32,116,104,105,115,46,115,116,101,112,59,10,
        32,32,32,32,32,32,105,102,40,100,101,108,116,97,61,61,48,41,10,32,32,32,32,32,32,32,32,100,101,108,116,97,61,49,59,10,32,32,32,32,32,32,115,119,105,116,99,104,40,101,46,107,101,121,41,123,10,32,
        32,32,32,32,32,99,97,115,101,32,34,65,114,114,111,119,85,112,34,58,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,116,104,105,115,46,118,97,108,117,101,43,100,101,
        108,116,97,44,116,114,117,101,41,59,10,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,99,97,115,101,32,34,65,114,114,111,119,68,111,119,110,34,58,10,32,32,32,32,32,32,32,32,116,
        104,105,115,46,115,101,116,86,97,108,117,101,40,116,104,105,115,46,118,97,108,117,101,45,100,101,108,116,97,44,116,114,117,101,41,59,10,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,
        32,32,100,101,102,97,117,108,116,58,10,32,32,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,46,112,114,101,118,101,110,116,68,101,102,97,117,
        108,116,40,41,59,10,32,32,32,32,32,32,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,59,10,32,32,32,32,125,10,32,32,32,32,119,104,101,101,108,40,101,41,32,123,10,32,32,32,
        32,32,32,105,102,32,40,33,116,104,105,115,46,101,110,97,98,108,101,41,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,108,111,103,41,123,
        10,32,32,32,32,32,32,32,32,108,101,116,32,114,61,77,97,116,104,46,108,111,103,40,116,104,105,115,46,118,97,108,117,101,47,116,104,105,115,46,109,105,110,41,47,77,97,116,104,46,108,111,103,40,116,
        104,105,115,46,109,97,120,47,116,104,105,115,46,109,105,110,41,59,10,32,32,32,32,32,32,32,32,108,101,116,32,100,32,61,32,40,101,46,100,101,108,116,97,89,62,48,63,45,48,46,48,49,58,48,46,48,49,41,
        59,10,32,32,32,32,32,32,32,32,105,102,40,33,101,46,115,104,105,102,116,75,101,121,41,10,32,32,32,32,32,32,32,32,32,32,100,42,61,53,59,10,32,32,32,32,32,32,32,32,114,32,43,61,32,100,59,10,32,32,32,
        32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,116,104,105,115,46,109,105,110,42,77,97,116,104,46,112,111,119,40,116,104,105,115,46,109,97,120,47,116,104,105,115,46,109,105,110,
        44,114,41,44,116,114,117,101,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,101,123,10,32,32,32,32,32,32,32,32,108,101,116,32,100,101,108,116,97,61,77,97,116,104,46,109,97,120,40,
        116,104,105,115,46,115,116,101,112,44,32,40,116,104,105,115,46,109,97,120,45,116,104,105,115,46,109,105,110,41,42,48,46,48,53,41,59,10,32,32,32,32,32,32,32,32,105,102,40,101,46,115,104,105,102,116,
        75,101,121,41,10,32,32,32,32,32,32,32,32,32,32,100,101,108,116,97,61,116,104,105,115,46,115,116,101,112,63,116,104,105,115,46,115,116,101,112,58,49,59,10,32,32,32,32,32,32,32,32,100,101,108,116,
        97,61,101,46,100,101,108,116,97,89,62,48,63,45,100,101,108,116,97,58,100,101,108,116,97,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,43,116,104,105,115,46,118,
        97,108,117,101,43,100,101,108,116,97,44,116,114,117,101,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,
        32,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,59,10,32,32,32,32,125,10,32,32,32,32,112,111,105,110,116,101,114,100,111,119,110,40,101,118,41,123,10,32,32,32,32,32,32,105,
        102,40,33,116,104,105,115,46,101,110,97,98,108,101,41,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,108,101,116,32,101,61,101,118,59,10,32,32,32,32,32,32,105,102,40,
        101,118,46,116,111,117,99,104,101,115,41,123,10,32,32,32,32,32,32,32,32,101,32,61,32,101,118,46,99,104,97,110,103,101,100,84,111,117,99,104,101,115,91,48,93,59,10,32,32,32,32,32,32,32,32,116,104,
        105,115,46,105,100,101,110,116,105,102,105,101,114,61,101,46,105,100,101,110,116,105,102,105,101,114,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,101,32,123,10,32,32,32,32,32,32,
        32,32,105,102,40,101,46,98,117,116,116,111,110,115,33,61,49,32,38,38,32,101,46,98,117,116,116,111,110,33,61,48,41,10,32,32,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,
        125,10,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,102,111,99,117,115,40,41,59,10,32,32,32,32,32,32,116,104,105,115,46,100,114,97,103,61,49,59,10,32,32,32,32,32,32,116,104,105,115,46,
        115,104,111,119,116,105,112,40,48,41,59,10,32,32,32,32,32,32,116,104,105,115,46,111,108,100,118,97,108,117,101,61,116,104,105,115,46,95,118,97,108,117,101,59,10,32,32,32,32,32,32,108,101,116,32,
        112,111,105,110,116,101,114,109,111,118,101,61,40,101,118,41,61,62,123,10,32,32,32,32,32,32,32,32,108,101,116,32,101,61,101,118,59,10,32,32,32,32,32,32,32,32,105,102,40,101,118,46,116,111,117,99,
        104,101,115,41,123,10,32,32,32,32,32,32,32,32,32,32,102,111,114,40,108,101,116,32,105,61,48,59,105,60,101,118,46,116,111,117,99,104,101,115,46,108,101,110,103,116,104,59,43,43,105,41,123,10,32,32,
        32,32,32,32,32,32,32,32,32,32,105,102,40,101,118,46,116,111,117,99,104,101,115,91,105,93,46,105,100,101,110,116,105,102,105,101,114,61,61,116,104,105,115,46,105,100,101,110,116,105,102,105,101,114,
        41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,101,32,61,32,101,118,46,116,111,117,99,104,101,115,91,105,93,59,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,
        32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,108,97,115,116,83,104,105,102,116,32,33,
        61,61,32,101,46,115,104,105,102,116,75,101,121,41,32,123,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,108,97,115,116,83,104,105,102,116,32,61,32,101,46,115,104,105,102,116,75,101,121,59,10,
        32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,116,97,114,116,80,111,115,88,32,61,32,101,46,112,97,103,101,88,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,116,97,114,116,80,111,
        115,89,32,61,32,101,46,112,97,103,101,89,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,116,97,114,116,86,97,108,32,61,32,116,104,105,115,46,118,97,108,117,101,59,10,32,32,32,32,32,32,
        32,32,125,10,32,32,32,32,32,32,32,32,108,101,116,32,111,102,102,115,101,116,32,61,32,40,116,104,105,115,46,115,116,97,114,116,80,111,115,89,32,45,32,101,46,112,97,103,101,89,32,45,32,116,104,105,
        115,46,115,116,97,114,116,80,111,115,88,32,43,32,101,46,112,97,103,101,88,41,32,42,32,116,104,105,115,46,115,101,110,115,105,116,105,118,105,116,121,59,10,32,32,32,32,32,32,32,32,105,102,40,116,
        104,105,115,46,108,111,103,41,123,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,114,32,61,32,77,97,116,104,46,108,111,103,40,116,104,105,115,46,115,116,97,114,116,86,97,108,32,47,32,116,104,105,
        115,46,109,105,110,41,32,47,32,77,97,116,104,46,108,111,103,40,116,104,105,115,46,109,97,120,32,47,32,116,104,105,115,46,109,105,110,41,59,10,32,32,32,32,32,32,32,32,32,32,114,32,43,61,32,111,102,
        102,115,101,116,47,40,40,101,46,115,104,105,102,116,75,101,121,63,52,58,49,41,42,49,50,56,41,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,114,60,48,41,32,114,61,48,59,10,32,32,32,32,32,32,32,32,
        32,32,105,102,40,114,62,49,41,32,114,61,49,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,95,115,101,116,86,97,108,117,101,40,116,104,105,115,46,109,105,110,32,42,32,77,97,116,104,46,112,
        111,119,40,116,104,105,115,46,109,97,120,47,116,104,105,115,46,109,105,110,44,32,114,41,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,101,108,115,101,123,10,32,32,32,32,32,32,32,
        32,32,32,116,104,105,115,46,95,115,101,116,86,97,108,117,101,40,116,104,105,115,46,109,105,110,32,43,32,40,40,40,40,116,104,105,115,46,115,116,97,114,116,86,97,108,32,43,32,40,116,104,105,115,46,
        109,97,120,32,45,32,116,104,105,115,46,109,105,110,41,32,42,32,111,102,102,115,101,116,32,47,32,40,40,101,46,115,104,105,102,116,75,101,121,32,63,32,52,32,58,32,49,41,32,42,32,49,50,56,41,41,32,
        45,32,116,104,105,115,46,109,105,110,41,32,47,32,116,104,105,115,46,115,116,101,112,41,32,124,32,48,41,32,42,32,116,104,105,115,46,115,116,101,112,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,
        32,32,32,32,32,105,102,40,116,104,105,115,46,102,105,114,101,102,108,97,103,41,123,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,100,69,118,101,110,116,40,34,105,110,112,117,116,
        34,41,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,102,105,114,101,102,108,97,103,61,102,97,108,115,101,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,105,102,40,101,46,112,
        114,101,118,101,110,116,68,101,102,97,117,108,116,41,10,32,32,32,32,32,32,32,32,32,32,101,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,32,32,105,102,40,
        101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,41,10,32,32,32,32,32,32,32,32,32,32,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,59,10,32,32,32,32,32,32,
        32,32,114,101,116,117,114,110,32,102,97,108,115,101,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,108,101,116,32,112,111,105,110,116,101,114,117,112,61,40,101,118,41,61,62,123,10,32,32,32,32,
        32,32,32,32,108,101,116,32,101,61,101,118,59,10,32,32,32,32,32,32,32,32,105,102,40,101,118,46,116,111,117,99,104,101,115,41,123,10,32,32,32,32,32,32,32,32,32,32,102,111,114,40,108,101,116,32,105,
        61,48,59,59,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,101,118,46,99,104,97,110,103,101,100,84,111,117,99,104,101,115,91,105,93,46,105,100,101,110,116,105,102,105,101,114,61,61,116,
        104,105,115,46,105,100,101,110,116,105,102,105,101,114,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,
        32,32,32,32,32,105,102,40,43,43,105,62,61,101,118,46,99,104,97,110,103,101,100,84,111,117,99,104,101,115,46,108,101,110,103,116,104,41,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,114,101,116,117,
        114,110,59,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,116,104,105,115,46,100,114,97,103,61,48,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,
        115,104,111,119,116,105,112,40,48,41,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,116,97,114,116,80,111,115,88,32,61,32,116,104,105,115,46,115,116,97,114,116,80,111,115,89,32,61,32,110,117,
        108,108,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,109,111,118,101,39,44,32,112,
        111,105,110,116,101,114,109,111,118,101,41,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,
        104,109,111,118,101,39,44,32,112,111,105,110,116,101,114,109,111,118,101,44,32,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,
        114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,117,112,39,44,32,112,111,105,110,116,101,114,117,112,41,59,10,32,32,32,32,32,32,32,32,119,105,
        110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,101,110,100,39,44,32,112,111,105,110,116,101,114,117,112,41,59,10,32,32,32,32,
        32,32,32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,99,97,110,99,101,108,39,44,32,112,111,105,110,116,101,114,
        117,112,41,59,10,32,32,32,32,32,32,32,32,100,111,99,117,109,101,110,116,46,98,111,100,121,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,115,
        116,97,114,116,39,44,32,112,114,101,118,101,110,116,83,99,114,111,108,108,44,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,
        110,100,69,118,101,110,116,40,34,99,104,97,110,103,101,34,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,108,101,116,32,112,114,101,118,101,110,116,83,99,114,111,108,108,61,40,101,41,61,62,
        123,10,32,32,32,32,32,32,32,32,101,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,101,46,99,116,114,108,75,101,121,32,
        124,124,32,101,46,109,101,116,97,75,101,121,41,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,116,104,105,115,46,100,101,102,118,97,108,117,101,44,116,114,117,101,
        41,59,10,32,32,32,32,32,32,101,108,115,101,32,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,116,97,114,116,80,111,115,88,32,61,32,101,46,112,97,103,101,88,59,10,32,32,32,32,32,32,32,32,116,
        104,105,115,46,115,116,97,114,116,80,111,115,89,32,61,32,101,46,112,97,103,101,89,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,116,97,114,116,86,97,108,32,61,32,116,104,105,115,46,118,97,
        108,117,101,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,109,111,118,101,39,44,32,112,111,105,110,
        116,101,114,109,111,118,101,41,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,109,111,118,101,39,44,
        32,112,111,105,110,116,101,114,109,111,118,101,44,32,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,
        100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,117,112,39,44,32,112,111,105,110,116,101,114,117,112,41,59,10,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,
        100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,101,110,100,39,44,32,112,111,105,110,116,101,114,117,112,41,59,10,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,
        100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,99,97,110,99,101,108,39,44,32,112,111,105,110,116,101,114,117,112,41,59,10,32,32,32,32,32,32,100,111,99,117,109,101,
        110,116,46,98,111,100,121,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,115,116,97,114,116,39,44,32,112,114,101,118,101,110,116,83,99,114,111,108,108,44,
        123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,101,118,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,101,118,46,115,
        116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,59,10,32,32,32,32,32,32,114,101,116,117,114,110,32,102,97,108,115,101,59,10,32,32,32,32,125,10,32,32,125,41,59,10,125,32,99,97,116,99,104,
        40,101,114,114,111,114,41,123,10,32,32,99,111,110,115,111,108,101,46,108,111,103,40,34,119,101,98,97,117,100,105,111,45,107,110,111,98,32,97,108,114,101,97,100,121,32,100,101,102,105,110,101,100,
        34,41,59,10,125,10,10,116,114,121,123,10,32,32,99,117,115,116,111,109,69,108,101,109,101,110,116,115,46,100,101,102,105,110,101,40,34,119,101,98,97,117,100,105,111,45,115,108,105,100,101,114,34,
        44,32,99,108,97,115,115,32,87,101,98,65,117,100,105,111,83,108,105,100,101,114,32,101,120,116,101,110,100,115,32,87,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,
        32,123,10,32,32,32,32,99,111,110,115,116,114,117,99,116,111,114,40,41,123,10,32,32,32,32,32,32,115,117,112,101,114,40,41,59,10,32,32,32,32,125,10,32,32,32,32,99,111,110,110,101,99,116,101,100,67,
        97,108,108,98,97,99,107,40,41,123,10,32,32,32,32,32,32,108,101,116,32,114,111,111,116,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,97,116,116,97,99,104,83,104,97,100,111,119,41,10,32,32,
        32,32,32,32,32,32,114,111,111,116,61,116,104,105,115,46,97,116,116,97,99,104,83,104,97,100,111,119,40,123,109,111,100,101,58,32,39,111,112,101,110,39,125,41,59,10,32,32,32,32,32,32,101,108,115,101,
        10,32,32,32,32,32,32,32,32,114,111,111,116,61,116,104,105,115,59,10,32,32,32,32,32,32,114,111,111,116,46,105,110,110,101,114,72,84,77,76,61,10,96,60,115,116,121,108,101,62,10,36,123,116,104,105,
        115,46,98,97,115,101,115,116,121,108,101,125,10,58,104,111,115,116,123,10,32,32,100,105,115,112,108,97,121,58,105,110,108,105,110,101,45,98,108,111,99,107,59,10,32,32,112,111,115,105,116,105,111,
        110,58,114,101,108,97,116,105,118,101,59,10,32,32,109,97,114,103,105,110,58,48,59,10,32,32,112,97,100,100,105,110,103,58,48,59,10,32,32,102,111,110,116,45,102,97,109,105,108,121,58,32,115,97,110,
        115,45,115,101,114,105,102,59,10,32,32,102,111,110,116,45,115,105,122,101,58,32,49,49,112,120,59,10,32,32,99,117,114,115,111,114,58,112,111,105,110,116,101,114,59,10,125,10,46,119,101,98,97,117,
        100,105,111,45,115,108,105,100,101,114,45,98,111,100,121,123,10,32,32,100,105,115,112,108,97,121,58,105,110,108,105,110,101,45,98,108,111,99,107,59,10,32,32,112,111,115,105,116,105,111,110,58,114,
        101,108,97,116,105,118,101,59,10,32,32,109,97,114,103,105,110,58,48,59,10,32,32,112,97,100,100,105,110,103,58,48,59,10,32,32,118,101,114,116,105,99,97,108,45,97,108,105,103,110,58,98,111,116,116,
        111,109,59,10,32,32,119,104,105,116,101,45,115,112,97,99,101,58,112,114,101,59,10,125,10,46,119,101,98,97,117,100,105,111,45,115,108,105,100,101,114,45,107,110,111,98,123,10,32,32,100,105,115,112,
        108,97,121,58,105,110,108,105,110,101,45,98,108,111,99,107,59,10,32,32,112,111,115,105,116,105,111,110,58,97,98,115,111,108,117,116,101,59,10,32,32,109,97,114,103,105,110,58,48,59,10,32,32,112,97,
        100,100,105,110,103,58,48,59,10,125,10,60,47,115,116,121,108,101,62,10,60,100,105,118,32,99,108,97,115,115,61,39,119,101,98,97,117,100,105,111,45,115,108,105,100,101,114,45,98,111,100,121,39,32,
        116,97,98,105,110,100,101,120,61,39,49,39,32,116,111,117,99,104,45,97,99,116,105,111,110,61,39,110,111,110,101,39,62,60,100,105,118,32,99,108,97,115,115,61,39,119,101,98,97,117,100,105,111,45,115,
        108,105,100,101,114,45,107,110,111,98,39,32,116,111,117,99,104,45,97,99,116,105,111,110,61,39,110,111,110,101,39,62,60,47,100,105,118,62,60,100,105,118,32,99,108,97,115,115,61,39,119,101,98,97,117,
        100,105,111,99,116,114,108,45,116,111,111,108,116,105,112,39,62,60,47,100,105,118,62,60,100,105,118,32,112,97,114,116,61,34,108,97,98,101,108,34,32,99,108,97,115,115,61,34,119,101,98,97,117,100,
        105,111,99,116,114,108,45,108,97,98,101,108,34,62,60,115,108,111,116,62,60,47,115,108,111,116,62,60,47,100,105,118,62,60,47,100,105,118,62,10,96,59,10,32,32,32,32,32,32,116,104,105,115,46,101,108,
        101,109,61,114,111,111,116,46,99,104,105,108,100,78,111,100,101,115,91,50,93,59,10,32,32,32,32,32,32,116,104,105,115,46,107,110,111,98,61,116,104,105,115,46,101,108,101,109,46,102,105,114,115,116,
        67,104,105,108,100,59,10,32,32,32,32,32,32,116,104,105,115,46,116,116,102,114,97,109,101,61,116,104,105,115,46,107,110,111,98,46,110,101,120,116,83,105,98,108,105,110,103,59,10,32,32,32,32,32,32,
        116,104,105,115,46,108,97,98,101,108,61,116,104,105,115,46,116,116,102,114,97,109,101,46,110,101,120,116,83,105,98,108,105,110,103,59,10,32,32,32,32,32,32,116,104,105,115,46,101,110,97,98,108,101,
        61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,101,110,97,98,108,101,34,44,49,41,59,10,32,32,32,32,32,32,116,104,105,115,46,116,114,97,99,107,105,110,103,61,116,104,105,115,46,103,101,116,
        65,116,116,114,40,34,116,114,97,99,107,105,110,103,34,44,34,114,101,108,34,41,59,32,10,32,32,32,32,32,32,116,104,105,115,46,95,115,114,99,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,115,
        114,99,34,44,111,112,116,46,115,108,105,100,101,114,83,114,99,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,115,114,99,34,41,41,32,79,98,
        106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,115,114,99,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,
        95,115,114,99,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,115,114,99,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,
        32,116,104,105,115,46,95,107,110,111,98,115,114,99,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,107,110,111,98,115,114,99,34,44,111,112,116,46,115,108,105,100,101,114,75,110,111,98,83,
        114,99,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,107,110,111,98,115,114,99,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,
        80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,107,110,111,98,115,114,99,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,107,110,111,98,115,114,
        99,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,107,110,111,98,115,114,99,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,
        32,32,116,104,105,115,46,95,118,97,108,117,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,118,97,108,117,101,34,44,48,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,
        80,114,111,112,101,114,116,121,40,34,118,97,108,117,101,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,118,97,108,117,101,34,
        44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,118,97,108,117,101,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,118,97,108,117,101,61,118,
        59,116,104,105,115,46,114,101,100,114,97,119,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,100,101,102,118,97,108,117,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,100,
        101,102,118,97,108,117,101,34,44,116,104,105,115,46,95,118,97,108,117,101,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,109,105,110,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,109,
        105,110,34,44,48,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,109,105,110,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,
        114,111,112,101,114,116,121,40,116,104,105,115,44,34,109,105,110,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,109,105,110,125,44,115,101,116,58,40,118,
        41,61,62,123,116,104,105,115,46,95,109,105,110,61,118,59,116,104,105,115,46,114,101,100,114,97,119,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,109,97,120,61,116,104,105,115,46,
        103,101,116,65,116,116,114,40,34,109,97,120,34,44,49,48,48,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,109,97,120,34,41,41,32,79,98,106,
        101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,109,97,120,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,
        109,97,120,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,109,97,120,61,118,59,116,104,105,115,46,114,101,100,114,97,119,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,
        46,95,115,116,101,112,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,115,116,101,112,34,44,49,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,
        121,40,34,115,116,101,112,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,115,116,101,112,34,44,123,103,101,116,58,40,41,61,62,
        123,114,101,116,117,114,110,32,116,104,105,115,46,95,115,116,101,112,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,115,116,101,112,61,118,59,116,104,105,115,46,114,101,100,114,
        97,119,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,115,112,114,105,116,101,115,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,115,112,114,105,116,101,115,34,44,48,41,59,
        32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,115,112,114,105,116,101,115,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,
        112,101,114,116,121,40,116,104,105,115,44,34,115,112,114,105,116,101,115,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,115,112,114,105,116,101,115,125,
        44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,115,112,114,105,116,101,115,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,
        116,104,105,115,46,95,100,105,114,101,99,116,105,111,110,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,100,105,114,101,99,116,105,111,110,34,44,110,117,108,108,41,59,32,105,102,32,40,33,
        116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,100,105,114,101,99,116,105,111,110,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,
        116,121,40,116,104,105,115,44,34,100,105,114,101,99,116,105,111,110,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,100,105,114,101,99,116,105,111,110,125,
        44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,100,105,114,101,99,116,105,111,110,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,
        32,32,32,116,104,105,115,46,108,111,103,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,108,111,103,34,44,48,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,119,105,100,116,104,61,116,104,
        105,115,46,103,101,116,65,116,116,114,40,34,119,105,100,116,104,34,44,111,112,116,46,115,108,105,100,101,114,87,105,100,116,104,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,
        80,114,111,112,101,114,116,121,40,34,119,105,100,116,104,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,119,105,100,116,104,34,
        44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,119,105,100,116,104,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,119,105,100,116,104,61,
        118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,104,101,105,103,104,116,61,116,104,105,115,46,103,101,116,65,116,116,
        114,40,34,104,101,105,103,104,116,34,44,111,112,116,46,115,108,105,100,101,114,72,101,105,103,104,116,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,
        121,40,34,104,101,105,103,104,116,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,104,101,105,103,104,116,34,44,123,103,101,116,
        58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,104,101,105,103,104,116,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,104,101,105,103,104,116,61,118,59,116,
        104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,107,110,111,98,119,105,100,116,104,61,116,104,105,115,46,103,101,116,65,116,116,
        114,40,34,107,110,111,98,119,105,100,116,104,34,44,111,112,116,46,115,108,105,100,101,114,75,110,111,98,87,105,100,116,104,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,
        111,112,101,114,116,121,40,34,107,110,111,98,119,105,100,116,104,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,107,110,111,98,
        119,105,100,116,104,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,107,110,111,98,119,105,100,116,104,125,44,115,101,116,58,40,118,41,61,62,123,116,104,
        105,115,46,95,107,110,111,98,119,105,100,116,104,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,107,110,111,98,
        104,101,105,103,104,116,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,107,110,111,98,104,101,105,103,104,116,34,44,111,112,116,46,115,108,105,100,101,114,75,110,111,98,72,101,105,103,104,
        116,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,107,110,111,98,104,101,105,103,104,116,34,41,41,32,79,98,106,101,99,116,46,100,101,102,
        105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,107,110,111,98,104,101,105,103,104,116,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,
        95,107,110,111,98,104,101,105,103,104,116,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,107,110,111,98,104,101,105,103,104,116,61,118,59,116,104,105,115,46,115,101,116,117,112,
        73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,100,105,116,99,104,108,101,110,103,116,104,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,100,105,116,99,
        104,108,101,110,103,116,104,34,44,111,112,116,46,115,108,105,100,101,114,68,105,116,99,104,108,101,110,103,116,104,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,
        101,114,116,121,40,34,100,105,116,99,104,108,101,110,103,116,104,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,100,105,116,99,
        104,108,101,110,103,116,104,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,100,105,116,99,104,108,101,110,103,116,104,125,44,115,101,116,58,40,118,41,61,
        62,123,116,104,105,115,46,95,100,105,116,99,104,108,101,110,103,116,104,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,
        46,95,99,111,108,111,114,115,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,99,111,108,111,114,115,34,44,111,112,116,46,115,108,105,100,101,114,67,111,108,111,114,115,41,59,32,105,102,32,
        40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,99,111,108,111,114,115,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,
        121,40,116,104,105,115,44,34,99,111,108,111,114,115,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,99,111,108,111,114,115,125,44,115,101,116,58,40,118,
        41,61,62,123,116,104,105,115,46,95,99,111,108,111,114,115,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,111,117,116,
        108,105,110,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,111,117,116,108,105,110,101,34,44,111,112,116,46,111,117,116,108,105,110,101,41,59,10,32,32,32,32,32,32,116,104,105,115,46,
        115,101,116,117,112,76,97,98,101,108,40,41,59,10,32,32,32,32,32,32,116,104,105,115,46,115,101,110,115,105,116,105,118,105,116,121,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,115,101,110,
        115,105,116,105,118,105,116,121,34,44,49,41,59,10,32,32,32,32,32,32,116,104,105,115,46,118,97,108,117,101,116,105,112,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,118,97,108,117,101,116,
        105,112,34,44,111,112,116,46,118,97,108,117,101,116,105,112,41,59,10,32,32,32,32,32,32,116,104,105,115,46,116,111,111,108,116,105,112,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,116,111,
        111,108,116,105,112,34,44,110,117,108,108,41,59,10,32,32,32,32,32,32,116,104,105,115,46,99,111,110,118,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,99,111,110,118,34,44,110,117,108,108,
        41,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,99,111,110,118,41,123,10,32,32,32,32,32,32,32,32,99,111,110,115,116,32,120,61,116,104,105,115,46,95,118,97,108,117,101,59,10,32,32,32,32,
        32,32,32,32,116,104,105,115,46,99,111,110,118,86,97,108,117,101,61,101,118,97,108,40,116,104,105,115,46,99,111,110,118,41,59,10,32,32,32,32,32,32,32,32,105,102,40,116,121,112,101,111,102,40,116,
        104,105,115,46,99,111,110,118,86,97,108,117,101,41,61,61,34,102,117,110,99,116,105,111,110,34,41,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,111,110,118,86,97,108,117,101,61,116,104,105,
        115,46,99,111,110,118,86,97,108,117,101,40,120,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,116,104,105,115,46,99,111,110,118,86,97,108,117,101,
        61,116,104,105,115,46,95,118,97,108,117,101,59,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,108,101,97,114,110,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,109,105,100,105,108,
        101,97,114,110,34,44,111,112,116,46,109,105,100,105,108,101,97,114,110,41,59,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,99,99,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,
        109,105,100,105,99,99,34,44,110,117,108,108,41,59,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,67,111,110,116,114,111,108,108,101,114,61,123,125,59,10,32,32,32,32,32,32,116,104,105,115,
        46,109,105,100,105,77,111,100,101,61,34,110,111,114,109,97,108,34,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,109,105,100,105,99,99,41,32,123,10,32,32,32,32,32,32,32,32,32,32,108,101,116,
        32,99,104,32,61,32,112,97,114,115,101,73,110,116,40,116,104,105,115,46,109,105,100,105,99,99,46,115,117,98,115,116,114,105,110,103,40,48,44,32,116,104,105,115,46,109,105,100,105,99,99,46,108,97,
        115,116,73,110,100,101,120,79,102,40,34,46,34,41,41,41,32,45,32,49,59,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,99,99,32,61,32,112,97,114,115,101,73,110,116,40,116,104,105,115,46,109,105,100,
        105,99,99,46,115,117,98,115,116,114,105,110,103,40,116,104,105,115,46,109,105,100,105,99,99,46,108,97,115,116,73,110,100,101,120,79,102,40,34,46,34,41,32,43,32,49,41,41,59,10,32,32,32,32,32,32,32,
        32,32,32,116,104,105,115,46,115,101,116,77,105,100,105,67,111,110,116,114,111,108,108,101,114,40,99,104,44,32,99,99,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,116,104,105,115,
        46,109,105,100,105,108,101,97,114,110,32,38,38,32,116,104,105,115,46,105,100,41,123,10,32,32,32,32,32,32,32,32,105,102,40,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,
        103,101,116,77,97,110,97,103,101,114,32,38,38,32,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,46,109,105,100,105,76,101,97,114,110,
        84,97,98,108,101,41,123,10,32,32,32,32,32,32,32,32,32,32,99,111,110,115,116,32,109,108,61,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,
        114,46,109,105,100,105,76,101,97,114,110,84,97,98,108,101,59,10,32,32,32,32,32,32,32,32,32,32,102,111,114,40,108,101,116,32,105,61,48,59,32,105,32,60,32,109,108,46,108,101,110,103,116,104,59,32,
        43,43,105,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,109,108,91,105,93,46,105,100,61,61,116,104,105,115,46,105,100,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,
        46,115,101,116,77,105,100,105,67,111,110,116,114,111,108,108,101,114,40,109,108,91,105,93,46,99,99,46,99,104,97,110,110,101,108,44,32,109,108,91,105,93,46,99,99,46,99,99,41,59,10,32,32,32,32,32,
        32,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,125,10,32,32,32,
        32,32,32,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,59,10,32,32,32,32,32,32,116,104,105,115,46,100,105,103,105,116,115,61,48,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,
        46,115,116,101,112,32,38,38,32,116,104,105,115,46,115,116,101,112,32,60,32,49,41,32,123,10,32,32,32,32,32,32,32,32,102,111,114,40,108,101,116,32,110,32,61,32,116,104,105,115,46,115,116,101,112,32,
        59,32,110,32,60,32,49,59,32,110,32,42,61,32,49,48,41,10,32,32,32,32,32,32,32,32,32,32,43,43,116,104,105,115,46,100,105,103,105,116,115,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,116,104,105,
        115,46,102,105,114,101,102,108,97,103,61,116,114,117,101,59,10,32,32,32,32,32,32,105,102,40,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,
        101,116,77,97,110,97,103,101,114,41,10,47,47,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,
        101,114,46,117,112,100,97,116,101,87,105,100,103,101,116,115,40,41,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,
        103,101,116,77,97,110,97,103,101,114,46,97,100,100,87,105,100,103,101,116,40,116,104,105,115,41,59,10,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,111,110,99,108,105,99,107,61,40,101,
        41,61,62,123,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,125,59,10,32,32,32,32,125,10,32,32,32,32,100,105,115,99,111,110,110,101,99,116,101,100,67,97,108,108,98,97,99,107,
        40,41,123,125,10,32,32,32,32,115,101,116,117,112,73,109,97,103,101,40,41,123,10,32,32,32,32,32,32,116,104,105,115,46,99,111,108,116,97,98,32,61,32,116,104,105,115,46,99,111,108,111,114,115,46,115,
        112,108,105,116,40,34,59,34,41,59,10,32,32,32,32,32,32,116,104,105,115,46,98,111,100,121,105,109,103,61,110,101,119,32,73,109,97,103,101,40,41,59,10,32,32,32,32,32,32,116,104,105,115,46,107,110,
        111,98,105,109,103,61,110,101,119,32,73,109,97,103,101,40,41,59,10,32,32,32,32,32,32,116,104,105,115,46,115,114,99,117,114,108,61,110,117,108,108,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,
        46,115,114,99,61,61,110,117,108,108,124,124,116,104,105,115,46,115,114,99,61,61,34,34,41,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,119,61,43,116,104,105,115,46,95,119,105,100,116,104,
        59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,104,61,43,116,104,105,115,46,104,101,105,103,104,116,59,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,100,105,114,101,99,116,105,
        111,110,61,61,34,104,111,114,122,34,41,123,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,119,105,100,116,104,61,61,110,117,108,108,41,32,116,104,105,115,46,115,119,61,49,50,56,
        59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,104,101,105,103,104,116,61,61,110,117,108,108,41,32,116,104,105,115,46,115,104,61,50,52,59,10,32,32,32,32,32,32,32,32,125,10,
        32,32,32,32,32,32,32,32,101,108,115,101,32,105,102,40,116,104,105,115,46,95,100,105,114,101,99,116,105,111,110,61,61,34,118,101,114,116,34,41,123,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,
        104,105,115,46,95,119,105,100,116,104,61,61,110,117,108,108,41,32,116,104,105,115,46,115,119,61,50,52,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,104,101,105,103,104,116,
        61,61,110,117,108,108,41,32,116,104,105,115,46,115,104,61,49,50,56,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,101,108,115,101,123,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,
        104,105,115,46,95,119,105,100,116,104,61,61,110,117,108,108,41,32,116,104,105,115,46,115,119,61,49,50,56,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,104,101,105,103,104,
        116,61,61,110,117,108,108,41,32,116,104,105,115,46,115,104,61,50,52,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,99,111,110,115,116,32,114,61,77,97,116,104,46,109,105,110,40,116,
        104,105,115,46,115,119,44,116,104,105,115,46,115,104,41,42,48,46,53,59,10,32,32,32,32,32,32,32,32,99,111,110,115,116,32,115,118,103,98,111,100,121,61,10,96,60,115,118,103,32,120,109,108,110,115,
        61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,50,48,48,48,47,115,118,103,34,32,119,105,100,116,104,61,34,36,123,116,104,105,115,46,115,119,125,34,32,104,101,105,103,104,
        116,61,34,36,123,116,104,105,115,46,115,104,125,34,32,112,114,101,115,101,114,118,101,65,115,112,101,99,116,82,97,116,105,111,61,34,110,111,110,101,34,62,10,60,100,101,102,115,62,10,32,32,60,102,
        105,108,116,101,114,32,105,100,61,34,102,49,34,62,10,32,32,32,32,60,102,101,71,97,117,115,115,105,97,110,66,108,117,114,32,105,110,61,34,83,111,117,114,99,101,71,114,97,112,104,105,99,34,32,115,
        116,100,68,101,118,105,97,116,105,111,110,61,34,48,46,56,34,32,47,62,10,32,32,60,47,102,105,108,116,101,114,62,10,32,32,60,108,105,110,101,97,114,71,114,97,100,105,101,110,116,32,105,100,61,34,103,
        49,34,32,120,49,61,34,48,37,34,32,121,49,61,34,48,37,34,32,36,123,40,116,104,105,115,46,115,119,62,116,104,105,115,46,115,104,41,63,39,120,50,61,34,48,37,34,32,121,50,61,34,49,48,48,37,34,39,58,
        39,120,50,61,34,49,48,48,37,34,32,121,50,61,34,48,37,34,39,125,62,10,32,32,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,48,37,34,32,115,116,111,112,45,99,111,108,111,114,61,34,35,48,
        48,48,34,32,115,116,111,112,45,111,112,97,99,105,116,121,61,34,48,34,47,62,10,32,32,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,49,48,48,37,34,32,115,116,111,112,45,99,111,108,111,
        114,61,34,35,48,48,48,34,32,115,116,111,112,45,111,112,97,99,105,116,121,61,34,48,46,51,34,47,62,10,32,32,60,47,108,105,110,101,97,114,71,114,97,100,105,101,110,116,62,10,60,47,100,101,102,115,62,
        10,60,114,101,99,116,32,120,61,34,49,34,32,121,61,34,49,34,32,114,120,61,34,36,123,114,125,34,32,114,121,61,34,36,123,114,125,34,32,119,105,100,116,104,61,34,36,123,116,104,105,115,46,115,119,45,
        50,125,34,32,104,101,105,103,104,116,61,34,36,123,116,104,105,115,46,115,104,45,50,125,34,32,102,105,108,108,61,34,35,48,48,48,34,47,62,10,60,114,101,99,116,32,120,61,34,51,34,32,121,61,34,51,34,
        32,114,120,61,34,36,123,114,125,34,32,114,121,61,34,36,123,114,125,34,32,119,105,100,116,104,61,34,36,123,116,104,105,115,46,115,119,45,54,125,34,32,104,101,105,103,104,116,61,34,36,123,116,104,
        105,115,46,115,104,45,54,125,34,32,102,105,108,108,61,34,36,123,116,104,105,115,46,99,111,108,116,97,98,91,49,93,125,34,32,102,105,108,116,101,114,61,34,117,114,108,40,35,102,49,41,34,47,62,10,60,
        114,101,99,116,32,120,61,34,49,34,32,121,61,34,49,34,32,114,120,61,34,36,123,114,125,34,32,114,121,61,34,36,123,114,125,34,32,119,105,100,116,104,61,34,36,123,116,104,105,115,46,115,119,45,50,125,
        34,32,104,101,105,103,104,116,61,34,36,123,116,104,105,115,46,115,104,45,50,125,34,32,102,105,108,108,61,34,117,114,108,40,35,103,49,41,34,47,62,10,60,47,115,118,103,62,96,59,10,32,32,32,32,32,32,
        32,32,116,104,105,115,46,115,114,99,117,114,108,32,61,32,34,100,97,116,97,58,105,109,97,103,101,47,115,118,103,43,120,109,108,59,98,97,115,101,54,52,44,34,43,98,116,111,97,40,115,118,103,98,111,
        100,121,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,101,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,114,99,117,114,108,32,61,32,116,104,105,115,46,115,114,99,59,10,
        32,32,32,32,32,32,125,10,32,32,32,32,32,32,116,104,105,115,46,98,111,100,121,105,109,103,46,111,110,108,111,97,100,61,40,41,61,62,123,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,115,
        114,99,33,61,34,34,41,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,73,109,97,103,101,32,61,32,34,117,114,108,
        40,34,43,116,104,105,115,46,115,114,99,117,114,108,43,34,41,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,119,61,43,116,104,105,115,46,95,119,105,100,116,104,59,10,32,32,32,32,32,32,32,
        32,116,104,105,115,46,115,104,61,43,116,104,105,115,46,95,104,101,105,103,104,116,59,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,119,105,100,116,104,61,61,110,117,108,108,41,32,116,
        104,105,115,46,115,119,61,116,104,105,115,46,98,111,100,121,105,109,103,46,119,105,100,116,104,59,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,104,101,105,103,104,116,61,61,110,117,
        108,108,41,32,116,104,105,115,46,115,104,61,116,104,105,115,46,98,111,100,121,105,109,103,46,104,101,105,103,104,116,59,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,100,114,61,61,110,
        117,108,108,41,123,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,115,119,62,116,104,105,115,46,115,104,41,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,100,114,61,34,
        104,111,114,122,34,59,10,32,32,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,100,114,61,34,118,101,114,116,34,59,10,32,32,32,32,32,32,32,32,125,
        10,32,32,32,32,32,32,32,32,116,104,105,115,46,107,119,61,43,116,104,105,115,46,95,107,110,111,98,119,105,100,116,104,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,107,104,61,43,116,104,105,115,
        46,95,107,110,111,98,104,101,105,103,104,116,59,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,107,110,111,98,115,114,99,61,61,110,117,108,108,41,123,10,32,32,32,32,32,32,32,32,32,32,
        105,102,40,116,104,105,115,46,95,107,110,111,98,119,105,100,116,104,61,61,110,117,108,108,41,32,116,104,105,115,46,107,119,61,77,97,116,104,46,109,105,110,40,116,104,105,115,46,115,119,44,116,104,
        105,115,46,115,104,41,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,107,110,111,98,104,101,105,103,104,116,61,61,110,117,108,108,41,32,116,104,105,115,46,107,104,61,77,97,
        116,104,46,109,105,110,40,116,104,105,115,46,115,119,44,116,104,105,115,46,115,104,41,59,10,32,32,32,32,32,32,32,32,32,32,99,111,110,115,116,32,109,109,61,77,97,116,104,46,109,105,110,40,116,104,
        105,115,46,107,119,44,116,104,105,115,46,107,104,41,42,48,46,53,59,10,32,32,32,32,32,32,32,32,32,32,99,111,110,115,116,32,107,119,50,61,77,97,116,104,46,109,97,120,40,49,44,116,104,105,115,46,107,
        119,45,49,50,41,59,10,32,32,32,32,32,32,32,32,32,32,99,111,110,115,116,32,107,104,50,61,77,97,116,104,46,109,97,120,40,49,44,116,104,105,115,46,107,104,45,49,50,41,59,10,32,32,32,32,32,32,32,32,
        32,32,99,111,110,115,116,32,115,118,103,107,110,111,98,61,10,96,60,115,118,103,32,120,109,108,110,115,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,50,48,48,48,47,115,118,
        103,34,32,119,105,100,116,104,61,34,36,123,116,104,105,115,46,107,119,125,34,32,104,101,105,103,104,116,61,34,36,123,116,104,105,115,46,107,104,125,34,32,112,114,101,115,101,114,118,101,65,115,112,
        101,99,116,82,97,116,105,111,61,34,110,111,110,101,34,62,10,60,100,101,102,115,62,10,32,32,60,102,105,108,116,101,114,32,105,100,61,34,102,49,34,62,10,32,32,32,32,60,102,101,71,97,117,115,115,105,
        97,110,66,108,117,114,32,105,110,61,34,83,111,117,114,99,101,71,114,97,112,104,105,99,34,32,115,116,100,68,101,118,105,97,116,105,111,110,61,34,48,46,56,34,32,47,62,10,32,32,60,47,102,105,108,116,
        101,114,62,10,32,32,60,108,105,110,101,97,114,71,114,97,100,105,101,110,116,32,105,100,61,34,103,49,34,32,120,49,61,34,48,37,34,32,121,49,61,34,48,37,34,32,120,50,61,34,48,37,34,32,121,50,61,34,
        49,48,48,37,34,62,10,32,32,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,48,37,34,32,115,116,111,112,45,99,111,108,111,114,61,34,36,123,116,104,105,115,46,99,111,108,116,97,98,91,50,
        93,125,34,47,62,10,32,32,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,53,48,37,34,32,115,116,111,112,45,99,111,108,111,114,61,34,36,123,116,104,105,115,46,99,111,108,116,97,98,91,48,
        93,125,34,47,62,10,32,32,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,49,48,48,37,34,32,115,116,111,112,45,99,111,108,111,114,61,34,36,123,116,104,105,115,46,99,111,108,116,97,98,91,
        48,93,125,34,32,115,116,111,112,45,111,112,97,99,105,116,121,61,34,48,46,53,34,47,62,10,32,32,60,47,108,105,110,101,97,114,71,114,97,100,105,101,110,116,62,10,32,32,60,108,105,110,101,97,114,71,
        114,97,100,105,101,110,116,32,105,100,61,34,103,50,34,32,120,49,61,34,48,37,34,32,121,49,61,34,48,37,34,32,120,50,61,34,48,37,34,32,121,50,61,34,49,48,48,37,34,62,10,32,32,32,32,60,115,116,111,112,
        32,111,102,102,115,101,116,61,34,48,37,34,32,115,116,111,112,45,99,111,108,111,114,61,34,36,123,116,104,105,115,46,99,111,108,116,97,98,91,48,93,125,34,47,62,10,32,32,32,32,60,115,116,111,112,32,
        111,102,102,115,101,116,61,34,49,48,48,37,34,32,115,116,111,112,45,99,111,108,111,114,61,34,36,123,116,104,105,115,46,99,111,108,116,97,98,91,48,93,125,34,47,62,10,32,32,60,47,108,105,110,101,97,
        114,71,114,97,100,105,101,110,116,62,10,32,32,60,108,105,110,101,97,114,71,114,97,100,105,101,110,116,32,105,100,61,34,103,51,34,32,120,49,61,34,48,37,34,32,121,49,61,34,48,37,34,32,120,50,61,34,
        48,37,34,32,121,50,61,34,49,48,48,37,34,62,10,32,32,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,48,37,34,32,115,116,111,112,45,99,111,108,111,114,61,34,35,48,48,48,34,32,115,116,111,
        112,45,111,112,97,99,105,116,121,61,34,48,34,47,62,10,32,32,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,49,48,48,37,34,32,115,116,111,112,45,99,111,108,111,114,61,34,35,48,48,48,34,
        32,115,116,111,112,45,111,112,97,99,105,116,121,61,34,48,46,51,34,47,62,10,32,32,60,47,108,105,110,101,97,114,71,114,97,100,105,101,110,116,62,10,60,47,100,101,102,115,62,10,60,114,101,99,116,32,
        120,61,34,50,34,32,121,61,34,50,34,32,119,105,100,116,104,61,34,36,123,116,104,105,115,46,107,119,45,52,125,34,32,104,101,105,103,104,116,61,34,36,123,116,104,105,115,46,107,104,45,52,125,34,32,
        114,120,61,34,36,123,109,109,125,34,32,114,121,61,34,36,123,109,109,125,34,32,102,105,108,108,61,34,35,48,48,48,34,47,62,10,60,114,101,99,116,32,120,61,34,51,34,32,121,61,34,51,34,32,119,105,100,
        116,104,61,34,36,123,116,104,105,115,46,107,119,45,54,125,34,32,104,101,105,103,104,116,61,34,36,123,116,104,105,115,46,107,104,45,54,125,34,32,114,120,61,34,36,123,109,109,125,34,32,114,121,61,
        34,36,123,109,109,125,34,32,102,105,108,108,61,34,117,114,108,40,35,103,49,41,34,47,62,10,60,114,101,99,116,32,120,61,34,54,34,32,121,61,34,54,34,32,119,105,100,116,104,61,34,36,123,107,119,50,125,
        34,32,104,101,105,103,104,116,61,34,36,123,107,104,50,125,34,32,114,120,61,34,36,123,109,109,125,34,32,114,121,61,34,36,123,109,109,125,34,32,102,105,108,108,61,34,117,114,108,40,35,103,50,41,34,
        32,102,105,108,116,101,114,61,34,117,114,108,40,35,102,49,41,34,47,62,10,60,114,101,99,116,32,120,61,34,51,34,32,121,61,34,51,34,32,119,105,100,116,104,61,34,36,123,116,104,105,115,46,107,119,45,
        54,125,34,32,104,101,105,103,104,116,61,34,36,123,116,104,105,115,46,107,104,45,54,125,34,32,114,120,61,34,36,123,109,109,125,34,32,114,121,61,34,36,123,109,109,125,34,32,102,105,108,108,61,34,117,
        114,108,40,35,103,51,41,34,47,62,10,60,47,115,118,103,62,96,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,107,110,111,98,115,114,99,117,114,108,32,61,32,34,100,97,116,97,58,105,109,97,103,
        101,47,115,118,103,43,120,109,108,59,98,97,115,101,54,52,44,34,43,98,116,111,97,40,115,118,103,107,110,111,98,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,101,108,115,101,123,
        10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,107,110,111,98,115,114,99,117,114,108,32,61,32,116,104,105,115,46,107,110,111,98,115,114,99,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,
        32,32,32,116,104,105,115,46,107,110,111,98,105,109,103,46,111,110,108,111,97,100,61,40,41,61,62,123,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,107,110,111,98,46,115,116,121,108,101,46,98,
        97,99,107,103,114,111,117,110,100,73,109,97,103,101,32,61,32,34,117,114,108,40,34,43,116,104,105,115,46,107,110,111,98,115,114,99,117,114,108,43,34,41,34,59,10,32,32,32,32,32,32,32,32,32,32,105,
        102,40,116,104,105,115,46,95,107,110,111,98,119,105,100,116,104,61,61,110,117,108,108,41,32,116,104,105,115,46,107,119,61,116,104,105,115,46,107,110,111,98,105,109,103,46,119,105,100,116,104,59,
        10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,107,110,111,98,104,101,105,103,104,116,61,61,110,117,108,108,41,32,116,104,105,115,46,107,104,61,116,104,105,115,46,107,110,111,
        98,105,109,103,46,104,101,105,103,104,116,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,100,108,101,110,61,116,104,105,115,46,100,105,116,99,104,108,101,110,103,116,104,59,10,32,32,32,32,
        32,32,32,32,32,32,105,102,40,116,104,105,115,46,100,108,101,110,61,61,110,117,108,108,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,100,114,61,61,34,104,111,114,122,
        34,41,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,100,108,101,110,61,116,104,105,115,46,115,119,45,116,104,105,115,46,107,119,59,10,32,32,32,32,32,32,32,32,32,32,32,32,101,108,
        115,101,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,100,108,101,110,61,116,104,105,115,46,115,104,45,116,104,105,115,46,107,104,59,10,32,32,32,32,32,32,32,32,32,32,125,10,32,
        32,32,32,32,32,32,32,32,32,116,104,105,115,46,107,110,111,98,46,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,83,105,122,101,32,61,32,34,49,48,48,37,32,49,48,48,37,34,59,10,32,32,32,
        32,32,32,32,32,32,32,116,104,105,115,46,107,110,111,98,46,115,116,121,108,101,46,119,105,100,116,104,32,61,32,116,104,105,115,46,107,119,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,32,32,116,
        104,105,115,46,107,110,111,98,46,115,116,121,108,101,46,104,101,105,103,104,116,32,61,32,116,104,105,115,46,107,104,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,
        101,109,46,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,83,105,122,101,32,61,32,34,49,48,48,37,32,49,48,48,37,34,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,
        109,46,115,116,121,108,101,46,119,105,100,116,104,61,116,104,105,115,46,115,119,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,
        104,101,105,103,104,116,61,116,104,105,115,46,115,104,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,97,119,40,41,59,10,32,32,32,32,32,32,32,32,125,59,10,
        32,32,32,32,32,32,32,32,116,104,105,115,46,107,110,111,98,105,109,103,46,115,114,99,61,116,104,105,115,46,107,110,111,98,115,114,99,117,114,108,59,10,32,32,32,32,32,32,125,59,10,32,32,32,32,32,32,
        116,104,105,115,46,98,111,100,121,105,109,103,46,115,114,99,61,116,104,105,115,46,115,114,99,117,114,108,59,10,32,32,32,32,125,10,32,32,32,32,114,101,100,114,97,119,40,41,32,123,10,32,32,32,32,32,
        32,108,101,116,32,114,97,116,105,111,59,10,32,32,32,32,32,32,116,104,105,115,46,100,105,103,105,116,115,61,48,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,115,116,101,112,32,38,38,32,116,
        104,105,115,46,115,116,101,112,32,60,32,49,41,32,123,10,32,32,32,32,32,32,32,32,102,111,114,40,108,101,116,32,110,32,61,32,116,104,105,115,46,115,116,101,112,32,59,32,110,32,60,32,49,59,32,110,32,
        42,61,32,49,48,41,10,32,32,32,32,32,32,32,32,32,32,43,43,116,104,105,115,46,100,105,103,105,116,115,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,118,97,108,117,
        101,60,116,104,105,115,46,109,105,110,41,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,118,97,108,117,101,61,116,104,105,115,46,109,105,110,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,
        102,40,116,104,105,115,46,118,97,108,117,101,62,116,104,105,115,46,109,97,120,41,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,118,97,108,117,101,61,116,104,105,115,46,109,97,120,59,10,32,32,
        32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,108,111,103,41,10,32,32,32,32,32,32,32,32,114,97,116,105,111,32,61,32,77,97,116,104,46,108,111,103,40,116,104,105,115,46,118,97,
        108,117,101,47,116,104,105,115,46,109,105,110,41,32,47,32,77,97,116,104,46,108,111,103,40,116,104,105,115,46,109,97,120,47,116,104,105,115,46,109,105,110,41,59,10,32,32,32,32,32,32,101,108,115,101,
        10,32,32,32,32,32,32,32,32,114,97,116,105,111,32,61,32,40,116,104,105,115,46,118,97,108,117,101,32,45,32,116,104,105,115,46,109,105,110,41,32,47,32,40,116,104,105,115,46,109,97,120,32,45,32,116,
        104,105,115,46,109,105,110,41,59,10,32,32,32,32,32,32,108,101,116,32,115,116,121,108,101,32,61,32,116,104,105,115,46,107,110,111,98,46,115,116,121,108,101,59,10,32,32,32,32,32,32,105,102,40,116,
        104,105,115,46,100,114,61,61,34,104,111,114,122,34,41,123,10,32,32,32,32,32,32,32,32,115,116,121,108,101,46,116,111,112,61,40,116,104,105,115,46,115,104,45,116,104,105,115,46,107,104,41,42,48,46,
        53,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,115,116,121,108,101,46,108,101,102,116,61,40,40,116,104,105,115,46,115,119,45,116,104,105,115,46,107,119,45,116,104,105,115,46,100,108,101,110,41,
        42,48,46,53,43,114,97,116,105,111,42,116,104,105,115,46,100,108,101,110,41,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,115,101,120,61,49,59,32,116,104,105,115,46,
        115,101,110,115,101,121,61,48,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,101,123,10,32,32,32,32,32,32,32,32,115,116,121,108,101,46,108,101,102,116,61,40,116,104,105,115,46,115,
        119,45,116,104,105,115,46,107,119,41,42,48,46,53,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,115,116,121,108,101,46,116,111,112,61,40,40,116,104,105,115,46,115,104,45,116,104,105,115,46,107,104,
        45,116,104,105,115,46,100,108,101,110,41,42,48,46,53,43,40,49,45,114,97,116,105,111,41,42,116,104,105,115,46,100,108,101,110,41,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,
        115,101,110,115,101,120,61,48,59,32,116,104,105,115,46,115,101,110,115,101,121,61,49,59,10,32,32,32,32,32,32,125,10,32,32,32,32,125,10,32,32,32,32,95,115,101,116,86,97,108,117,101,40,118,41,123,
        10,32,32,32,32,32,32,118,61,40,77,97,116,104,46,114,111,117,110,100,40,40,118,45,116,104,105,115,46,109,105,110,41,47,116,104,105,115,46,115,116,101,112,41,41,42,116,104,105,115,46,115,116,101,112,
        43,116,104,105,115,46,109,105,110,59,10,32,32,32,32,32,32,116,104,105,115,46,95,118,97,108,117,101,61,77,97,116,104,46,109,105,110,40,116,104,105,115,46,109,97,120,44,77,97,116,104,46,109,97,120,
        40,116,104,105,115,46,109,105,110,44,118,41,41,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,118,97,108,117,101,33,61,116,104,105,115,46,111,108,100,118,97,108,117,101,41,123,10,32,32,
        32,32,32,32,32,32,116,104,105,115,46,111,108,100,118,97,108,117,101,61,116,104,105,115,46,95,118,97,108,117,101,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,102,105,114,101,102,108,97,103,61,
        116,114,117,101,59,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,99,111,110,118,41,123,10,32,32,32,32,32,32,32,32,32,32,99,111,110,115,116,32,120,61,116,104,105,115,46,95,118,97,108,117,
        101,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,111,110,118,86,97,108,117,101,61,101,118,97,108,40,116,104,105,115,46,99,111,110,118,41,59,10,32,32,32,32,32,32,32,32,32,32,105,102,
        40,116,121,112,101,111,102,40,116,104,105,115,46,99,111,110,118,86,97,108,117,101,41,61,61,34,102,117,110,99,116,105,111,110,34,41,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,111,
        110,118,86,97,108,117,101,61,116,104,105,115,46,99,111,110,118,86,97,108,117,101,40,120,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,
        32,32,116,104,105,115,46,99,111,110,118,86,97,108,117,101,61,116,104,105,115,46,95,118,97,108,117,101,59,10,32,32,32,32,32,32,32,32,105,102,40,116,121,112,101,111,102,40,116,104,105,115,46,99,111,
        110,118,86,97,108,117,101,41,61,61,34,110,117,109,98,101,114,34,41,123,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,111,110,118,86,97,108,117,101,61,116,104,105,115,46,99,111,110,118,86,
        97,108,117,101,46,116,111,70,105,120,101,100,40,116,104,105,115,46,100,105,103,105,116,115,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,97,119,
        40,41,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,104,111,119,116,105,112,40,48,41,59,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,32,49,59,10,32,32,32,32,32,32,125,10,32,32,32,32,
        32,32,114,101,116,117,114,110,32,48,59,10,32,32,32,32,125,10,32,32,32,32,115,101,116,86,97,108,117,101,40,118,44,102,41,123,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,115,101,116,86,97,
        108,117,101,40,118,41,38,38,102,41,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,100,69,118,101,110,116,40,34,105,110,112,117,116,34,41,44,116,104,105,115,46,115,101,110,100,69,118,101,
        110,116,40,34,99,104,97,110,103,101,34,41,59,10,32,32,32,32,125,10,32,32,32,32,107,101,121,100,111,119,110,40,101,41,123,10,32,32,32,32,32,32,99,111,110,115,116,32,100,101,108,116,97,32,61,32,116,
        104,105,115,46,115,116,101,112,59,10,32,32,32,32,32,32,105,102,40,100,101,108,116,97,61,61,48,41,10,32,32,32,32,32,32,32,32,100,101,108,116,97,61,49,59,10,32,32,32,32,32,32,115,119,105,116,99,104,
        40,101,46,107,101,121,41,123,10,32,32,32,32,32,32,99,97,115,101,32,34,65,114,114,111,119,85,112,34,58,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,116,104,105,115,
        46,118,97,108,117,101,43,100,101,108,116,97,44,116,114,117,101,41,59,10,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,99,97,115,101,32,34,65,114,114,111,119,68,111,119,110,34,
        58,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,116,104,105,115,46,118,97,108,117,101,45,100,101,108,116,97,44,116,114,117,101,41,59,10,32,32,32,32,32,32,32,32,
        98,114,101,97,107,59,10,32,32,32,32,32,32,100,101,102,97,117,108,116,58,10,32,32,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,46,112,114,101,
        118,101,110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,59,10,32,32,32,32,125,10,32,32,32,32,119,104,101,101,
        108,40,101,41,32,123,10,32,32,32,32,32,32,105,102,32,40,33,116,104,105,115,46,101,110,97,98,108,101,41,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,105,102,40,116,104,
        105,115,46,108,111,103,41,123,10,32,32,32,32,32,32,32,32,108,101,116,32,114,61,77,97,116,104,46,108,111,103,40,116,104,105,115,46,118,97,108,117,101,47,116,104,105,115,46,109,105,110,41,47,77,97,
        116,104,46,108,111,103,40,116,104,105,115,46,109,97,120,47,116,104,105,115,46,109,105,110,41,59,10,32,32,32,32,32,32,32,32,108,101,116,32,100,32,61,32,40,101,46,100,101,108,116,97,89,62,48,63,45,
        48,46,48,49,58,48,46,48,49,41,59,10,32,32,32,32,32,32,32,32,105,102,40,33,101,46,115,104,105,102,116,75,101,121,41,10,32,32,32,32,32,32,32,32,32,32,100,42,61,53,59,10,32,32,32,32,32,32,32,32,114,
        32,43,61,32,100,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,116,104,105,115,46,109,105,110,42,77,97,116,104,46,112,111,119,40,116,104,105,115,46,109,97,120,
        47,116,104,105,115,46,109,105,110,44,114,41,44,116,114,117,101,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,101,123,10,32,32,32,32,32,32,32,32,108,101,116,32,100,101,108,116,97,
        61,77,97,116,104,46,109,97,120,40,116,104,105,115,46,115,116,101,112,44,32,40,116,104,105,115,46,109,97,120,45,116,104,105,115,46,109,105,110,41,42,48,46,48,53,41,59,10,32,32,32,32,32,32,32,32,105,
        102,40,101,46,115,104,105,102,116,75,101,121,41,10,32,32,32,32,32,32,32,32,32,32,100,101,108,116,97,61,116,104,105,115,46,115,116,101,112,63,116,104,105,115,46,115,116,101,112,58,49,59,10,32,32,
        32,32,32,32,32,32,100,101,108,116,97,61,101,46,100,101,108,116,97,89,62,48,63,45,100,101,108,116,97,58,100,101,108,116,97,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,
        101,40,43,116,104,105,115,46,118,97,108,117,101,43,100,101,108,116,97,44,116,114,117,101,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,46,112,114,101,118,101,110,116,68,101,102,97,117,
        108,116,40,41,59,10,32,32,32,32,32,32,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,59,10,32,32,32,32,125,10,32,32,32,32,112,111,105,110,116,101,114,100,111,119,110,40,101,
        118,41,123,10,32,32,32,32,32,32,105,102,40,33,116,104,105,115,46,101,110,97,98,108,101,41,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,108,101,116,32,101,61,101,118,
        59,10,32,32,32,32,32,32,105,102,40,101,118,46,116,111,117,99,104,101,115,41,123,10,32,32,32,32,32,32,32,32,101,32,61,32,101,118,46,99,104,97,110,103,101,100,84,111,117,99,104,101,115,91,48,93,59,
        10,32,32,32,32,32,32,32,32,116,104,105,115,46,105,100,101,110,116,105,102,105,101,114,61,101,46,105,100,101,110,116,105,102,105,101,114,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,
        101,32,123,10,32,32,32,32,32,32,32,32,105,102,40,101,46,98,117,116,116,111,110,115,33,61,49,32,38,38,32,101,46,98,117,116,116,111,110,33,61,48,41,10,32,32,32,32,32,32,32,32,32,32,114,101,116,117,
        114,110,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,102,111,99,117,115,40,41,59,10,32,32,32,32,32,32,116,104,105,115,46,100,114,97,103,61,49,59,10,32,32,
        32,32,32,32,116,104,105,115,46,115,104,111,119,116,105,112,40,48,41,59,10,32,32,32,32,32,32,108,101,116,32,112,111,105,110,116,101,114,109,111,118,101,61,40,101,118,41,61,62,123,10,32,32,32,32,32,
        32,32,32,108,101,116,32,101,61,101,118,59,10,32,32,32,32,32,32,32,32,105,102,40,101,118,46,116,111,117,99,104,101,115,41,123,10,32,32,32,32,32,32,32,32,32,32,102,111,114,40,108,101,116,32,105,61,
        48,59,105,60,101,118,46,116,111,117,99,104,101,115,46,108,101,110,103,116,104,59,43,43,105,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,101,118,46,116,111,117,99,104,101,115,91,105,93,
        46,105,100,101,110,116,105,102,105,101,114,61,61,116,104,105,115,46,105,100,101,110,116,105,102,105,101,114,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,101,32,61,32,101,118,46,116,111,117,
        99,104,101,115,91,105,93,59,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,
        32,32,125,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,108,97,115,116,83,104,105,102,116,32,33,61,61,32,101,46,115,104,105,102,116,75,101,121,41,32,123,10,32,32,32,32,32,32,32,32,32,
        32,116,104,105,115,46,108,97,115,116,83,104,105,102,116,32,61,32,101,46,115,104,105,102,116,75,101,121,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,116,97,114,116,80,111,115,88,32,
        61,32,101,46,112,97,103,101,88,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,116,97,114,116,80,111,115,89,32,61,32,101,46,112,97,103,101,89,59,10,32,32,32,32,32,32,32,32,32,32,116,104,
        105,115,46,115,116,97,114,116,86,97,108,32,61,32,116,104,105,115,46,118,97,108,117,101,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,116,114,97,99,107,
        105,110,103,61,61,34,97,98,115,34,41,123,10,32,32,32,32,32,32,32,32,32,32,99,111,110,115,116,32,114,99,32,61,32,116,104,105,115,46,103,101,116,66,111,117,110,100,105,110,103,67,108,105,101,110,116,
        82,101,99,116,40,41,59,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,118,97,108,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,100,114,61,61,34,104,111,114,122,34,41,10,32,32,
        32,32,32,32,32,32,32,32,32,32,118,97,108,32,61,32,77,97,116,104,46,109,97,120,40,48,44,77,97,116,104,46,109,105,110,40,49,44,40,101,46,112,97,103,101,88,45,114,99,46,108,101,102,116,45,119,105,110,
        100,111,119,46,112,97,103,101,88,79,102,102,115,101,116,45,116,104,105,115,46,107,119,42,48,46,53,41,47,40,116,104,105,115,46,119,105,100,116,104,45,116,104,105,115,46,107,119,41,41,41,59,10,32,
        32,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,32,32,32,32,118,97,108,32,61,32,49,32,45,32,77,97,116,104,46,109,97,120,40,48,44,77,97,116,104,46,109,105,110,40,49,44,40,101,
        46,112,97,103,101,89,45,114,99,46,116,111,112,45,119,105,110,100,111,119,46,112,97,103,101,89,79,102,102,115,101,116,45,116,104,105,115,46,107,104,42,48,46,53,41,47,40,116,104,105,115,46,104,101,
        105,103,104,116,45,116,104,105,115,46,107,104,41,41,41,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,108,111,103,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,
        46,95,115,101,116,86,97,108,117,101,40,116,104,105,115,46,109,105,110,32,42,32,77,97,116,104,46,112,111,119,40,116,104,105,115,46,109,97,120,47,116,104,105,115,46,109,105,110,44,32,118,97,108,41,
        41,59,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,95,115,101,116,86,97,108,117,101,40,116,104,
        105,115,46,109,105,110,32,43,32,40,116,104,105,115,46,109,97,120,32,45,32,116,104,105,115,46,109,105,110,41,42,118,97,108,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,101,108,
        115,101,123,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,111,102,102,115,101,116,32,61,32,40,40,116,104,105,115,46,115,116,97,114,116,80,111,115,89,32,45,32,101,46,112,97,103,101,89,41,42,116,
        104,105,115,46,115,101,110,115,101,121,32,45,32,40,116,104,105,115,46,115,116,97,114,116,80,111,115,88,32,45,32,101,46,112,97,103,101,88,41,42,116,104,105,115,46,115,101,110,115,101,120,41,32,42,
        32,116,104,105,115,46,115,101,110,115,105,116,105,118,105,116,121,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,108,111,103,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,108,
        101,116,32,114,32,61,32,77,97,116,104,46,108,111,103,40,116,104,105,115,46,115,116,97,114,116,86,97,108,32,47,32,116,104,105,115,46,109,105,110,41,32,47,32,77,97,116,104,46,108,111,103,40,116,104,
        105,115,46,109,97,120,32,47,32,116,104,105,115,46,109,105,110,41,59,10,32,32,32,32,32,32,32,32,32,32,32,32,114,32,43,61,32,111,102,102,115,101,116,47,40,40,101,46,115,104,105,102,116,75,101,121,
        63,52,58,49,41,42,49,50,56,41,59,10,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,114,60,48,41,32,114,61,48,59,10,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,114,62,49,41,32,114,61,49,59,10,
        32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,95,115,101,116,86,97,108,117,101,40,116,104,105,115,46,109,105,110,32,42,32,77,97,116,104,46,112,111,119,40,116,104,105,115,46,109,97,120,47,
        116,104,105,115,46,109,105,110,44,32,114,41,41,59,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,32,32,101,108,115,101,123,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,
        46,95,115,101,116,86,97,108,117,101,40,116,104,105,115,46,109,105,110,32,43,32,40,40,40,40,116,104,105,115,46,115,116,97,114,116,86,97,108,32,43,32,40,116,104,105,115,46,109,97,120,32,45,32,116,
        104,105,115,46,109,105,110,41,32,42,32,111,102,102,115,101,116,32,47,32,40,40,101,46,115,104,105,102,116,75,101,121,32,63,32,52,32,58,32,49,41,32,42,32,116,104,105,115,46,100,108,101,110,41,41,32,
        45,32,116,104,105,115,46,109,105,110,41,32,47,32,116,104,105,115,46,115,116,101,112,41,32,124,32,48,41,32,42,32,116,104,105,115,46,115,116,101,112,41,59,10,32,32,32,32,32,32,32,32,32,32,125,10,32,
        32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,102,105,114,101,102,108,97,103,41,123,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,100,69,118,
        101,110,116,40,34,105,110,112,117,116,34,41,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,102,105,114,101,102,108,97,103,61,102,97,108,115,101,59,10,32,32,32,32,32,32,32,32,125,10,32,32,
        32,32,32,32,32,32,105,102,40,101,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,41,10,32,32,32,32,32,32,32,32,32,32,101,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,59,
        10,32,32,32,32,32,32,32,32,105,102,40,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,41,10,32,32,32,32,32,32,32,32,32,32,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,
        111,110,40,41,59,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,32,102,97,108,115,101,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,108,101,116,32,112,111,105,110,116,101,114,117,112,61,40,
        101,118,41,61,62,123,10,32,32,32,32,32,32,32,32,108,101,116,32,101,61,101,118,59,10,32,32,32,32,32,32,32,32,105,102,40,101,118,46,116,111,117,99,104,101,115,41,123,10,32,32,32,32,32,32,32,32,32,
        32,102,111,114,40,108,101,116,32,105,61,48,59,59,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,101,118,46,99,104,97,110,103,101,100,84,111,117,99,104,101,115,91,105,93,46,105,100,101,
        110,116,105,102,105,101,114,61,61,116,104,105,115,46,105,100,101,110,116,105,102,105,101,114,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,32,32,32,
        32,32,32,125,10,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,43,43,105,62,61,101,118,46,99,104,97,110,103,101,100,84,111,117,99,104,101,115,46,108,101,110,103,116,104,41,10,32,32,32,32,32,32,32,
        32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,116,104,105,115,46,100,114,97,103,61,48,59,10,32,32,
        32,32,32,32,32,32,116,104,105,115,46,115,104,111,119,116,105,112,40,48,41,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,116,97,114,116,80,111,115,88,32,61,32,116,104,105,115,46,115,116,97,
        114,116,80,111,115,89,32,61,32,110,117,108,108,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,
        115,101,109,111,118,101,39,44,32,112,111,105,110,116,101,114,109,111,118,101,41,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,
        101,110,101,114,40,39,116,111,117,99,104,109,111,118,101,39,44,32,112,111,105,110,116,101,114,109,111,118,101,44,32,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,
        32,32,32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,117,112,39,44,32,112,111,105,110,116,101,114,117,112,41,
        59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,101,110,100,39,44,32,112,111,105,110,116,
        101,114,117,112,41,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,99,97,110,99,101,108,
        39,44,32,112,111,105,110,116,101,114,117,112,41,59,10,32,32,32,32,32,32,32,32,100,111,99,117,109,101,110,116,46,98,111,100,121,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,
        101,114,40,39,116,111,117,99,104,115,116,97,114,116,39,44,32,112,114,101,118,101,110,116,83,99,114,111,108,108,44,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,
        32,32,32,116,104,105,115,46,115,101,110,100,69,118,101,110,116,40,34,99,104,97,110,103,101,34,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,108,101,116,32,112,114,101,118,101,110,116,83,99,
        114,111,108,108,61,40,101,41,61,62,123,10,32,32,32,32,32,32,32,32,101,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,101,
        46,116,111,117,99,104,101,115,41,10,32,32,32,32,32,32,32,32,101,32,61,32,101,46,116,111,117,99,104,101,115,91,48,93,59,10,32,32,32,32,32,32,105,102,40,101,46,99,116,114,108,75,101,121,32,124,124,
        32,101,46,109,101,116,97,75,101,121,41,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,116,104,105,115,46,100,101,102,118,97,108,117,101,44,116,114,117,101,41,59,10,
        32,32,32,32,32,32,101,108,115,101,32,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,116,97,114,116,80,111,115,88,32,61,32,101,46,112,97,103,101,88,59,10,32,32,32,32,32,32,32,32,116,104,105,
        115,46,115,116,97,114,116,80,111,115,89,32,61,32,101,46,112,97,103,101,89,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,116,97,114,116,86,97,108,32,61,32,116,104,105,115,46,118,97,108,117,
        101,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,109,111,118,101,39,44,32,112,111,105,110,116,101,
        114,109,111,118,101,41,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,109,111,118,101,39,44,32,112,
        111,105,110,116,101,114,109,111,118,101,44,32,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,32,32,112,111,105,110,116,101,114,109,111,118,101,40,101,118,41,
        59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,117,112,39,44,32,112,111,105,110,
        116,101,114,117,112,41,59,10,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,101,110,100,39,44,32,112,111,105,110,
        116,101,114,117,112,41,59,10,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,99,97,110,99,101,108,39,44,32,112,
        111,105,110,116,101,114,117,112,41,59,10,32,32,32,32,32,32,100,111,99,117,109,101,110,116,46,98,111,100,121,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,
        115,116,97,114,116,39,44,32,112,114,101,118,101,110,116,83,99,114,111,108,108,44,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,101,46,112,114,101,118,101,110,
        116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,59,10,32,32,32,32,32,32,114,101,116,117,114,110,32,102,97,108,115,
        101,59,10,32,32,32,32,125,10,32,32,125,41,59,10,125,32,99,97,116,99,104,40,101,114,114,111,114,41,123,10,32,32,99,111,110,115,111,108,101,46,108,111,103,40,34,119,101,98,97,117,100,105,111,45,115,
        108,105,100,101,114,32,97,108,114,101,97,100,121,32,100,101,102,105,110,101,100,34,41,59,10,125,10,10,116,114,121,123,10,32,32,99,117,115,116,111,109,69,108,101,109,101,110,116,115,46,100,101,102,
        105,110,101,40,34,119,101,98,97,117,100,105,111,45,115,119,105,116,99,104,34,44,32,99,108,97,115,115,32,87,101,98,65,117,100,105,111,83,119,105,116,99,104,32,101,120,116,101,110,100,115,32,87,101,
        98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,32,123,10,32,32,32,32,99,111,110,115,116,114,117,99,116,111,114,40,41,123,10,32,32,32,32,32,32,115,117,112,101,114,40,
        41,59,10,32,32,32,32,125,10,32,32,32,32,99,111,110,110,101,99,116,101,100,67,97,108,108,98,97,99,107,40,41,123,10,32,32,32,32,32,32,108,101,116,32,114,111,111,116,59,10,32,32,32,32,32,32,105,102,
        40,116,104,105,115,46,97,116,116,97,99,104,83,104,97,100,111,119,41,10,32,32,32,32,32,32,32,32,114,111,111,116,61,116,104,105,115,46,97,116,116,97,99,104,83,104,97,100,111,119,40,123,109,111,100,
        101,58,32,39,111,112,101,110,39,125,41,59,10,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,114,111,111,116,61,116,104,105,115,59,10,32,32,32,32,32,32,114,111,111,116,46,105,110,110,
        101,114,72,84,77,76,61,10,96,60,115,116,121,108,101,62,10,36,123,116,104,105,115,46,98,97,115,101,115,116,121,108,101,125,10,58,104,111,115,116,123,10,32,32,100,105,115,112,108,97,121,58,105,110,
        108,105,110,101,45,98,108,111,99,107,59,10,32,32,112,111,115,105,116,105,111,110,58,114,101,108,97,116,105,118,101,59,10,32,32,109,97,114,103,105,110,58,48,59,10,32,32,112,97,100,100,105,110,103,
        58,48,59,10,32,32,102,111,110,116,45,102,97,109,105,108,121,58,32,115,97,110,115,45,115,101,114,105,102,59,10,32,32,102,111,110,116,45,115,105,122,101,58,32,49,49,112,120,59,10,32,32,99,117,114,
        115,111,114,58,112,111,105,110,116,101,114,59,10,125,10,46,119,101,98,97,117,100,105,111,45,115,119,105,116,99,104,45,98,111,100,121,123,10,32,32,100,105,115,112,108,97,121,58,105,110,108,105,110,
        101,45,98,108,111,99,107,59,10,32,32,112,111,115,105,116,105,111,110,58,114,101,108,97,116,105,118,101,59,10,32,32,109,97,114,103,105,110,58,48,59,10,32,32,112,97,100,100,105,110,103,58,48,59,10,
        32,32,118,101,114,116,105,99,97,108,45,97,108,105,103,110,58,98,111,116,116,111,109,59,10,32,32,119,104,105,116,101,45,115,112,97,99,101,58,112,114,101,59,10,125,10,46,119,101,98,97,117,100,105,
        111,99,116,114,108,45,108,97,98,101,108,123,10,32,32,112,111,115,105,116,105,111,110,58,97,98,115,111,108,117,116,101,59,10,32,32,108,101,102,116,58,53,48,37,59,10,32,32,116,111,112,58,53,48,37,
        59,10,125,10,60,47,115,116,121,108,101,62,10,60,100,105,118,32,99,108,97,115,115,61,39,119,101,98,97,117,100,105,111,45,115,119,105,116,99,104,45,98,111,100,121,39,32,116,97,98,105,110,100,101,120,
        61,39,49,39,32,116,111,117,99,104,45,97,99,116,105,111,110,61,39,110,111,110,101,39,62,60,100,105,118,32,99,108,97,115,115,61,39,119,101,98,97,117,100,105,111,99,116,114,108,45,116,111,111,108,116,
        105,112,39,62,60,47,100,105,118,62,60,100,105,118,32,112,97,114,116,61,34,108,97,98,101,108,34,32,99,108,97,115,115,61,34,119,101,98,97,117,100,105,111,99,116,114,108,45,108,97,98,101,108,34,62,
        60,115,108,111,116,62,60,47,115,108,111,116,62,60,47,100,105,118,62,60,47,100,105,118,62,10,96,59,10,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,61,114,111,111,116,46,99,104,105,108,100,
        78,111,100,101,115,91,50,93,59,10,32,32,32,32,32,32,116,104,105,115,46,116,116,102,114,97,109,101,61,116,104,105,115,46,101,108,101,109,46,102,105,114,115,116,67,104,105,108,100,59,10,32,32,32,32,
        32,32,116,104,105,115,46,108,97,98,101,108,61,116,104,105,115,46,116,116,102,114,97,109,101,46,110,101,120,116,83,105,98,108,105,110,103,59,10,32,32,32,32,32,32,116,104,105,115,46,101,110,97,98,
        108,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,101,110,97,98,108,101,34,44,49,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,115,114,99,61,116,104,105,115,46,103,101,116,65,116,
        116,114,40,34,115,114,99,34,44,110,117,108,108,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,115,114,99,34,41,41,32,79,98,106,101,99,116,
        46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,115,114,99,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,115,114,99,
        125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,115,114,99,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,
        115,46,95,118,97,108,117,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,118,97,108,117,101,34,44,48,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,
        101,114,116,121,40,34,118,97,108,117,101,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,118,97,108,117,101,34,44,123,103,101,
        116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,118,97,108,117,101,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,118,97,108,117,101,61,118,59,116,104,105,
        115,46,114,101,100,114,97,119,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,100,101,102,118,97,108,117,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,100,101,102,118,97,
        108,117,101,34,44,116,104,105,115,46,95,118,97,108,117,101,41,59,10,32,32,32,32,32,32,116,104,105,115,46,116,121,112,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,116,121,112,101,34,
        44,34,116,111,103,103,108,101,34,41,59,10,32,32,32,32,32,32,116,104,105,115,46,103,114,111,117,112,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,103,114,111,117,112,34,44,34,34,41,59,10,
        32,32,32,32,32,32,116,104,105,115,46,95,119,105,100,116,104,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,119,105,100,116,104,34,44,110,117,108,108,41,59,32,105,102,32,40,33,116,104,105,
        115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,119,105,100,116,104,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,
        44,34,119,105,100,116,104,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,119,105,100,116,104,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,
        46,95,119,105,100,116,104,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,104,101,105,103,104,116,61,116,104,105,
        115,46,103,101,116,65,116,116,114,40,34,104,101,105,103,104,116,34,44,110,117,108,108,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,104,
        101,105,103,104,116,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,104,101,105,103,104,116,34,44,123,103,101,116,58,40,41,61,
        62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,104,101,105,103,104,116,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,104,101,105,103,104,116,61,118,59,116,104,105,115,
        46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,100,105,97,109,101,116,101,114,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,100,
        105,97,109,101,116,101,114,34,44,110,117,108,108,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,100,105,97,109,101,116,101,114,34,41,41,32,
        79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,100,105,97,109,101,116,101,114,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,
        110,32,116,104,105,115,46,95,100,105,97,109,101,116,101,114,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,100,105,97,109,101,116,101,114,61,118,59,116,104,105,115,46,115,101,116,
        117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,105,110,118,101,114,116,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,105,110,118,101,114,116,34,44,
        48,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,99,111,108,111,114,115,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,99,111,108,111,114,115,34,44,111,112,116,46,115,119,105,116,99,104,
        67,111,108,111,114,115,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,99,111,108,111,114,115,34,41,41,32,79,98,106,101,99,116,46,100,101,
        102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,99,111,108,111,114,115,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,99,111,108,
        111,114,115,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,99,111,108,111,114,115,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,
        32,32,32,32,116,104,105,115,46,111,117,116,108,105,110,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,111,117,116,108,105,110,101,34,44,111,112,116,46,111,117,116,108,105,110,101,41,
        59,10,32,32,32,32,32,32,116,104,105,115,46,115,101,116,117,112,76,97,98,101,108,40,41,59,10,32,32,32,32,32,32,116,104,105,115,46,118,97,108,117,101,116,105,112,61,48,59,10,32,32,32,32,32,32,116,
        104,105,115,46,116,111,111,108,116,105,112,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,116,111,111,108,116,105,112,34,44,110,117,108,108,41,59,10,32,32,32,32,32,32,116,104,105,115,46,
        109,105,100,105,108,101,97,114,110,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,109,105,100,105,108,101,97,114,110,34,44,111,112,116,46,109,105,100,105,108,101,97,114,110,41,59,10,32,32,
        32,32,32,32,116,104,105,115,46,109,105,100,105,99,99,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,109,105,100,105,99,99,34,44,110,117,108,108,41,59,10,32,32,32,32,32,32,116,104,105,115,
        46,109,105,100,105,67,111,110,116,114,111,108,108,101,114,61,123,125,59,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,77,111,100,101,61,34,110,111,114,109,97,108,34,59,10,32,32,32,32,32,
        32,105,102,40,116,104,105,115,46,109,105,100,105,99,99,41,32,123,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,99,104,32,61,32,112,97,114,115,101,73,110,116,40,116,104,105,115,46,109,105,100,105,
        99,99,46,115,117,98,115,116,114,105,110,103,40,48,44,32,116,104,105,115,46,109,105,100,105,99,99,46,108,97,115,116,73,110,100,101,120,79,102,40,34,46,34,41,41,41,32,45,32,49,59,10,32,32,32,32,32,
        32,32,32,32,32,108,101,116,32,99,99,32,61,32,112,97,114,115,101,73,110,116,40,116,104,105,115,46,109,105,100,105,99,99,46,115,117,98,115,116,114,105,110,103,40,116,104,105,115,46,109,105,100,105,
        99,99,46,108,97,115,116,73,110,100,101,120,79,102,40,34,46,34,41,32,43,32,49,41,41,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,77,105,100,105,67,111,110,116,114,111,108,108,
        101,114,40,99,104,44,32,99,99,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,109,105,100,105,108,101,97,114,110,32,38,38,32,116,104,105,115,46,105,100,41,123,10,
        32,32,32,32,32,32,32,32,105,102,40,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,32,38,38,32,119,101,98,65,117,100,105,111,67,111,110,
        116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,46,109,105,100,105,76,101,97,114,110,84,97,98,108,101,41,123,10,32,32,32,32,32,32,32,32,32,32,99,111,110,115,116,32,109,108,61,
        119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,46,109,105,100,105,76,101,97,114,110,84,97,98,108,101,59,10,32,32,32,32,32,32,32,32,32,
        32,102,111,114,40,108,101,116,32,105,61,48,59,32,105,32,60,32,109,108,46,108,101,110,103,116,104,59,32,43,43,105,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,109,108,91,105,93,46,105,
        100,61,61,116,104,105,115,46,105,100,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,77,105,100,105,67,111,110,116,114,111,108,108,101,114,40,109,108,91,105,93,
        46,99,99,46,99,104,97,110,110,101,108,44,32,109,108,91,105,93,46,99,99,46,99,99,41,59,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,32,32,32,32,32,32,125,
        10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,59,10,32,32,32,32,
        32,32,116,104,105,115,46,100,105,103,105,116,115,61,48,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,115,116,101,112,32,38,38,32,116,104,105,115,46,115,116,101,112,32,60,32,49,41,32,123,
        10,32,32,32,32,32,32,32,32,102,111,114,40,108,101,116,32,110,32,61,32,116,104,105,115,46,115,116,101,112,32,59,32,110,32,60,32,49,59,32,110,32,42,61,32,49,48,41,10,32,32,32,32,32,32,32,32,32,32,
        43,43,116,104,105,115,46,100,105,103,105,116,115,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,
        87,105,100,103,101,116,77,97,110,97,103,101,114,41,10,47,47,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,
        77,97,110,97,103,101,114,46,117,112,100,97,116,101,87,105,100,103,101,116,115,40,41,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,111,
        108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,46,97,100,100,87,105,100,103,101,116,40,116,104,105,115,41,59,10,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,111,110,99,108,105,
        99,107,61,40,101,41,61,62,123,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,125,59,10,32,32,32,32,125,10,32,32,32,32,100,105,115,99,111,110,110,101,99,116,101,100,67,97,108,
        108,98,97,99,107,40,41,123,125,10,32,32,32,32,115,101,116,117,112,73,109,97,103,101,40,41,123,10,32,32,32,32,32,32,116,104,105,115,46,99,111,108,116,97,98,32,61,32,116,104,105,115,46,99,111,108,
        111,114,115,46,115,112,108,105,116,40,34,59,34,41,59,10,32,32,32,32,32,32,116,104,105,115,46,107,119,61,116,104,105,115,46,95,119,105,100,116,104,124,124,116,104,105,115,46,95,100,105,97,109,101,
        116,101,114,124,124,111,112,116,46,115,119,105,116,99,104,87,105,100,116,104,124,124,111,112,116,46,115,119,105,116,99,104,68,105,97,109,101,116,101,114,59,10,32,32,32,32,32,32,116,104,105,115,46,
        107,104,61,116,104,105,115,46,95,104,101,105,103,104,116,124,124,116,104,105,115,46,95,100,105,97,109,101,116,101,114,124,124,111,112,116,46,115,119,105,116,99,104,72,101,105,103,104,116,124,124,
        111,112,116,46,115,119,105,116,99,104,68,105,97,109,101,116,101,114,59,10,32,32,32,32,32,32,116,104,105,115,46,105,109,103,61,110,101,119,32,73,109,97,103,101,40,41,59,10,32,32,32,32,32,32,116,104,
        105,115,46,115,114,99,117,114,108,61,110,117,108,108,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,115,114,99,61,61,110,117,108,108,124,124,116,104,105,115,46,115,114,99,61,61,34,34,41,123,
        10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,107,119,61,61,110,117,108,108,41,32,116,104,105,115,46,107,119,61,51,50,59,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,107,104,
        61,61,110,117,108,108,41,32,116,104,105,115,46,107,104,61,51,50,59,10,32,32,32,32,32,32,32,32,99,111,110,115,116,32,109,109,61,77,97,116,104,46,109,105,110,40,116,104,105,115,46,107,119,44,116,104,
        105,115,46,107,104,41,59,10,32,32,32,32,32,32,32,32,99,111,110,115,116,32,107,119,61,116,104,105,115,46,107,119,44,107,104,61,116,104,105,115,46,107,104,59,10,32,32,32,32,32,32,32,32,99,111,110,
        115,116,32,115,118,103,61,10,96,60,115,118,103,32,120,109,108,110,115,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,50,48,48,48,47,115,118,103,34,32,119,105,100,116,104,
        61,34,36,123,116,104,105,115,46,107,119,125,34,32,104,101,105,103,104,116,61,34,36,123,116,104,105,115,46,107,104,42,50,125,34,32,112,114,101,115,101,114,118,101,65,115,112,101,99,116,82,97,116,
        105,111,61,34,110,111,110,101,34,62,10,60,100,101,102,115,62,10,60,108,105,110,101,97,114,71,114,97,100,105,101,110,116,32,105,100,61,34,103,49,34,32,120,49,61,34,48,37,34,32,121,49,61,34,48,37,
        34,32,120,50,61,34,48,37,34,32,121,50,61,34,49,48,48,37,34,62,10,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,48,37,34,32,115,116,111,112,45,99,111,108,111,114,61,34,35,48,48,48,34,
        32,115,116,111,112,45,111,112,97,99,105,116,121,61,34,48,34,47,62,10,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,49,48,48,37,34,32,115,116,111,112,45,99,111,108,111,114,61,34,35,48,
        48,48,34,32,115,116,111,112,45,111,112,97,99,105,116,121,61,34,48,46,50,34,47,62,10,60,47,108,105,110,101,97,114,71,114,97,100,105,101,110,116,62,10,60,114,97,100,105,97,108,71,114,97,100,105,101,
        110,116,32,105,100,61,34,103,50,34,32,99,120,61,34,53,48,37,34,32,99,121,61,34,51,48,37,34,62,10,32,32,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,48,37,34,32,115,116,111,112,45,99,
        111,108,111,114,61,34,36,123,116,104,105,115,46,99,111,108,116,97,98,91,50,93,125,34,47,62,10,32,32,32,32,60,115,116,111,112,32,111,102,102,115,101,116,61,34,49,48,48,37,34,32,115,116,111,112,45,
        99,111,108,111,114,61,34,36,123,116,104,105,115,46,99,111,108,116,97,98,91,48,93,125,34,47,62,10,32,32,60,47,114,97,100,105,97,108,71,114,97,100,105,101,110,116,62,10,32,32,60,102,105,108,116,101,
        114,32,105,100,61,34,102,49,34,62,10,32,32,32,32,60,102,101,71,97,117,115,115,105,97,110,66,108,117,114,32,105,110,61,34,83,111,117,114,99,101,71,114,97,112,104,105,99,34,32,115,116,100,68,101,118,
        105,97,116,105,111,110,61,34,46,52,34,32,47,62,10,32,32,60,47,102,105,108,116,101,114,62,10,60,47,100,101,102,115,62,10,60,103,32,105,100,61,34,112,49,34,62,10,32,32,60,114,101,99,116,32,120,61,
        34,36,123,107,119,42,46,48,55,53,125,34,32,121,61,34,36,123,107,104,42,46,48,55,53,125,34,32,119,105,100,116,104,61,34,36,123,107,119,42,46,56,53,125,34,32,104,101,105,103,104,116,61,34,36,123,107,
        104,42,46,56,53,125,34,32,114,120,61,34,36,123,109,109,42,46,49,125,34,32,114,121,61,34,36,123,109,109,42,46,49,125,34,32,102,105,108,108,61,34,35,48,48,48,34,47,62,10,32,32,60,114,101,99,116,32,
        120,61,34,36,123,107,119,42,46,49,125,34,32,121,61,34,36,123,107,104,42,46,49,125,34,32,119,105,100,116,104,61,34,36,123,107,119,42,46,56,125,34,32,104,101,105,103,104,116,61,34,36,123,107,104,42,
        46,56,125,34,32,114,120,61,34,36,123,109,109,42,46,49,125,34,32,114,121,61,34,36,123,109,109,42,46,49,125,34,32,102,105,108,108,61,34,36,123,116,104,105,115,46,99,111,108,116,97,98,91,49,93,125,
        34,47,62,10,60,47,103,62,10,60,103,32,105,100,61,34,112,50,34,62,10,32,32,60,99,105,114,99,108,101,32,99,120,61,34,36,123,107,119,42,48,46,53,125,34,32,99,121,61,34,36,123,107,104,42,48,46,53,125,
        34,32,114,61,34,36,123,109,109,42,48,46,51,53,125,34,32,115,116,114,111,107,101,61,34,35,48,48,48,34,32,115,116,114,111,107,101,45,119,105,100,116,104,61,34,36,123,109,109,42,46,48,51,125,34,32,
        102,105,108,108,61,34,36,123,116,104,105,115,46,99,111,108,116,97,98,91,48,93,125,34,32,102,105,108,116,101,114,61,34,117,114,108,40,35,102,49,41,34,47,62,10,32,32,60,99,105,114,99,108,101,32,99,
        120,61,34,36,123,107,119,42,48,46,53,125,34,32,99,121,61,34,36,123,107,104,42,48,46,53,125,34,32,114,61,34,36,123,109,109,42,48,46,50,55,125,34,32,115,116,114,111,107,101,61,34,35,48,48,48,34,32,
        115,116,114,111,107,101,45,119,105,100,116,104,61,34,36,123,109,109,42,46,48,51,125,34,32,102,105,108,108,61,34,35,48,48,48,34,32,102,105,108,116,101,114,61,34,117,114,108,40,35,102,49,41,34,47,
        62,10,32,32,60,114,101,99,116,32,120,61,34,36,123,107,119,42,46,48,55,53,125,34,32,121,61,34,36,123,107,104,42,46,48,55,53,125,34,32,119,105,100,116,104,61,34,36,123,107,119,42,46,56,53,125,34,32,
        104,101,105,103,104,116,61,34,36,123,107,104,42,46,56,53,125,34,32,114,120,61,34,36,123,109,109,42,46,49,125,34,32,114,121,61,34,36,123,109,109,42,46,49,125,34,32,102,105,108,108,61,34,117,114,108,
        40,35,103,49,41,34,47,62,10,60,47,103,62,10,60,117,115,101,32,104,114,101,102,61,34,35,112,49,34,32,121,61,34,36,123,107,104,125,34,47,62,10,60,117,115,101,32,104,114,101,102,61,34,35,112,50,34,
        32,121,61,34,36,123,107,104,125,34,47,62,10,60,99,105,114,99,108,101,32,99,120,61,34,36,123,107,119,42,46,53,125,34,32,99,121,61,34,36,123,107,104,42,49,46,53,125,34,32,114,61,34,36,123,109,109,
        42,46,50,53,125,34,32,102,105,108,108,61,34,117,114,108,40,35,103,50,41,34,32,102,105,108,116,101,114,61,34,117,114,108,40,35,102,49,41,34,47,62,10,60,99,105,114,99,108,101,32,99,120,61,34,36,123,
        107,119,42,46,53,125,34,32,99,121,61,34,36,123,107,104,42,49,46,53,125,34,32,114,61,34,36,123,109,109,42,46,50,53,125,34,32,102,105,108,108,61,34,117,114,108,40,35,103,49,41,34,47,62,10,60,47,115,
        118,103,62,96,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,114,99,117,114,108,61,34,100,97,116,97,58,105,109,97,103,101,47,115,118,103,43,120,109,108,59,98,97,115,101,54,52,44,34,43,98,116,
        111,97,40,115,118,103,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,114,99,117,114,108,61,116,104,105,115,46,115,114,99,59,
        10,32,32,32,32,32,32,116,104,105,115,46,105,109,103,46,111,110,108,111,97,100,61,40,41,61,62,123,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,107,119,61,61,110,117,108,108,41,32,116,
        104,105,115,46,107,119,61,116,104,105,115,46,105,109,103,46,119,105,100,116,104,59,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,107,104,61,61,110,117,108,108,41,32,116,104,105,115,46,
        107,104,61,116,104,105,115,46,105,109,103,46,104,101,105,103,104,116,42,48,46,53,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,98,97,99,107,103,114,111,
        117,110,100,73,109,97,103,101,32,61,32,34,117,114,108,40,34,43,116,104,105,115,46,115,114,99,117,114,108,43,34,41,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,
        108,101,46,98,97,99,107,103,114,111,117,110,100,83,105,122,101,32,61,32,34,49,48,48,37,32,50,48,48,37,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,
        119,105,100,116,104,61,116,104,105,115,46,107,119,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,104,101,105,103,104,116,61,116,104,105,
        115,46,107,104,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,97,119,40,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,116,104,105,115,46,105,109,103,46,115,
        114,99,61,116,104,105,115,46,115,114,99,117,114,108,59,10,32,32,32,32,125,10,32,32,32,32,114,101,100,114,97,119,40,41,32,123,10,32,32,32,32,32,32,108,101,116,32,115,116,121,108,101,32,61,32,116,
        104,105,115,46,101,108,101,109,46,115,116,121,108,101,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,118,97,108,117,101,94,116,104,105,115,46,105,110,118,101,114,116,41,10,32,32,32,32,32,
        32,32,32,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,80,111,115,105,116,105,111,110,32,61,32,34,48,112,120,32,45,49,48,48,37,34,59,10,32,32,32,32,32,32,101,108,115,101,10,32,32,32,
        32,32,32,32,32,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,80,111,115,105,116,105,111,110,32,61,32,34,48,112,120,32,48,112,120,34,59,10,32,32,32,32,125,10,32,32,32,32,115,101,116,
        86,97,108,117,101,40,118,44,102,41,123,10,32,32,32,32,32,32,116,104,105,115,46,118,97,108,117,101,61,118,59,10,32,32,32,32,32,32,116,104,105,115,46,99,104,101,99,107,101,100,61,40,33,33,118,41,59,
        10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,118,97,108,117,101,33,61,116,104,105,115,46,111,108,100,118,97,108,117,101,41,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,
        97,119,40,41,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,104,111,119,116,105,112,40,48,41,59,10,32,32,32,32,32,32,32,32,105,102,40,102,41,123,10,32,32,32,32,32,32,32,32,32,32,116,104,105,
        115,46,115,101,110,100,69,118,101,110,116,40,34,105,110,112,117,116,34,41,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,100,69,118,101,110,116,40,34,99,104,97,110,103,101,34,
        41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,116,104,105,115,46,111,108,100,118,97,108,117,101,61,116,104,105,115,46,118,97,108,117,101,59,10,32,32,32,32,32,32,125,10,32,32,32,
        32,125,10,32,32,32,32,112,111,105,110,116,101,114,100,111,119,110,40,101,118,41,123,10,32,32,32,32,32,32,105,102,40,33,116,104,105,115,46,101,110,97,98,108,101,41,10,32,32,32,32,32,32,32,32,114,
        101,116,117,114,110,59,10,32,32,32,32,32,32,108,101,116,32,101,61,101,118,59,10,32,32,32,32,32,32,105,102,40,101,118,46,116,111,117,99,104,101,115,41,123,10,32,32,32,32,32,32,32,32,101,32,61,32,
        101,118,46,99,104,97,110,103,101,100,84,111,117,99,104,101,115,91,48,93,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,105,100,101,110,116,105,102,105,101,114,61,101,46,105,100,101,110,116,105,
        102,105,101,114,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,101,32,123,10,32,32,32,32,32,32,32,32,105,102,40,101,46,98,117,116,116,111,110,115,33,61,49,32,38,38,32,101,46,98,117,
        116,116,111,110,33,61,48,41,10,32,32,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,102,111,99,117,115,40,
        41,59,10,32,32,32,32,32,32,116,104,105,115,46,100,114,97,103,61,49,59,10,32,32,32,32,32,32,116,104,105,115,46,115,104,111,119,116,105,112,40,48,41,59,10,32,32,32,32,32,32,108,101,116,32,112,111,
        105,110,116,101,114,109,111,118,101,61,40,101,41,61,62,123,10,32,32,32,32,32,32,32,32,101,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,32,32,101,46,115,
        116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,59,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,32,102,97,108,115,101,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,108,101,116,
        32,112,111,105,110,116,101,114,117,112,61,40,101,41,61,62,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,100,114,97,103,61,48,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,104,111,119,
        116,105,112,40,48,41,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,109,111,118,101,
        39,44,32,112,111,105,110,116,101,114,109,111,118,101,41,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,
        111,117,99,104,109,111,118,101,39,44,32,112,111,105,110,116,101,114,109,111,118,101,44,32,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,32,32,119,105,110,100,
        111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,117,112,39,44,32,112,111,105,110,116,101,114,117,112,41,59,10,32,32,32,32,32,32,32,
        32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,101,110,100,39,44,32,112,111,105,110,116,101,114,117,112,41,59,10,
        32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,99,97,110,99,101,108,39,44,32,112,111,105,110,
        116,101,114,117,112,41,59,10,32,32,32,32,32,32,32,32,100,111,99,117,109,101,110,116,46,98,111,100,121,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,
        99,104,115,116,97,114,116,39,44,32,112,114,101,118,101,110,116,83,99,114,111,108,108,44,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,32,32,105,102,40,116,104,
        105,115,46,116,121,112,101,61,61,34,107,105,99,107,34,41,123,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,118,97,108,117,101,61,48,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,
        104,101,99,107,101,100,61,102,97,108,115,101,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,97,119,40,41,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,
        100,69,118,101,110,116,40,34,99,104,97,110,103,101,34,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,100,69,118,101,110,116,40,34,99,108,105,99,107,
        34,41,59,10,32,32,32,32,32,32,32,32,101,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,32,32,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,
        40,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,108,101,116,32,112,114,101,118,101,110,116,83,99,114,111,108,108,61,40,101,41,61,62,123,10,32,32,32,32,32,32,32,32,101,46,112,114,101,118,101,
        110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,115,119,105,116,99,104,40,116,104,105,115,46,116,121,112,101,41,123,10,32,32,32,32,32,32,99,97,115,101,32,
        34,107,105,99,107,34,58,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,49,41,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,100,69,118,101,110,116,40,
        34,99,104,97,110,103,101,34,41,59,10,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,99,97,115,101,32,34,116,111,103,103,108,101,34,58,10,32,32,32,32,32,32,32,32,105,102,40,101,
        46,99,116,114,108,75,101,121,32,124,124,32,101,46,109,101,116,97,75,101,121,41,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,118,97,108,117,101,61,100,101,102,118,97,108,117,101,59,10,32,32,
        32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,118,97,108,117,101,61,49,45,116,104,105,115,46,118,97,108,117,101,59,10,32,32,32,32,32,32,32,32,116,104,105,
        115,46,99,104,101,99,107,101,100,61,33,33,116,104,105,115,46,118,97,108,117,101,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,100,69,118,101,110,116,40,34,99,104,97,110,103,101,34,
        41,59,10,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,32,32,32,32,32,99,97,115,101,32,34,114,97,100,105,111,34,58,10,32,32,32,32,32,32,32,32,108,101,116,32,101,108,115,61,100,111,99,117,109,
        101,110,116,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,34,119,101,98,97,117,100,105,111,45,115,119,105,116,99,104,91,116,121,112,101,61,39,114,97,100,105,111,39,93,91,103,
        114,111,117,112,61,39,34,43,116,104,105,115,46,103,114,111,117,112,43,34,39,93,34,41,59,10,32,32,32,32,32,32,32,32,102,111,114,40,108,101,116,32,105,61,48,59,105,60,101,108,115,46,108,101,110,103,
        116,104,59,43,43,105,41,123,10,32,32,32,32,32,32,32,32,32,32,105,102,40,101,108,115,91,105,93,61,61,116,104,105,115,41,10,32,32,32,32,32,32,32,32,32,32,32,32,101,108,115,91,105,93,46,115,101,116,
        86,97,108,117,101,40,49,41,59,10,32,32,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,32,32,32,32,101,108,115,91,105,93,46,115,101,116,86,97,108,117,101,40,48,41,59,10,32,32,
        32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,100,69,118,101,110,116,40,34,99,104,97,110,103,101,34,41,59,10,32,32,32,32,32,32,32,32,98,114,101,97,107,59,10,32,
        32,32,32,32,32,125,10,10,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,117,112,39,44,32,112,111,105,110,116,
        101,114,117,112,41,59,10,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,101,110,100,39,44,32,112,111,105,110,116,
        101,114,117,112,41,59,10,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,99,97,110,99,101,108,39,44,32,112,111,
        105,110,116,101,114,117,112,41,59,10,32,32,32,32,32,32,100,111,99,117,109,101,110,116,46,98,111,100,121,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,115,
        116,97,114,116,39,44,32,112,114,101,118,101,110,116,83,99,114,111,108,108,44,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,
        97,119,40,41,59,10,32,32,32,32,32,32,101,118,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,101,118,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,
        110,40,41,59,10,32,32,32,32,32,32,114,101,116,117,114,110,32,102,97,108,115,101,59,10,32,32,32,32,125,10,32,32,125,41,59,10,125,32,99,97,116,99,104,40,101,114,114,111,114,41,123,10,32,32,99,111,
        110,115,111,108,101,46,108,111,103,40,34,119,101,98,97,117,100,105,111,45,115,119,105,116,99,104,32,97,108,114,101,97,100,121,32,100,101,102,105,110,101,100,34,41,59,10,125,10,10,116,114,121,123,
        10,32,32,99,117,115,116,111,109,69,108,101,109,101,110,116,115,46,100,101,102,105,110,101,40,34,119,101,98,97,117,100,105,111,45,112,97,114,97,109,34,44,32,99,108,97,115,115,32,87,101,98,65,117,
        100,105,111,80,97,114,97,109,32,101,120,116,101,110,100,115,32,87,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,32,123,10,32,32,32,32,99,111,110,115,116,114,117,
        99,116,111,114,40,41,123,10,32,32,32,32,32,32,115,117,112,101,114,40,41,59,10,32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,107,101,121,
        100,111,119,110,34,44,116,104,105,115,46,107,101,121,100,111,119,110,41,59,10,32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,109,111,117,
        115,101,100,111,119,110,34,44,116,104,105,115,46,112,111,105,110,116,101,114,100,111,119,110,44,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,116,104,105,115,
        46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,116,111,117,99,104,115,116,97,114,116,34,44,116,104,105,115,46,112,111,105,110,116,101,114,100,111,119,110,44,123,112,97,115,
        115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,119,104,101,101,108,34,44,116,104,105,115,
        46,119,104,101,101,108,41,59,10,32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,109,111,117,115,101,111,118,101,114,34,44,116,104,105,115,
        46,112,111,105,110,116,101,114,111,118,101,114,41,59,10,32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,109,111,117,115,101,111,117,116,34,
        44,116,104,105,115,46,112,111,105,110,116,101,114,111,117,116,41,59,10,32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,99,111,110,116,101,
        120,116,109,101,110,117,34,44,116,104,105,115,46,99,111,110,116,101,120,116,77,101,110,117,41,59,10,32,32,32,32,125,10,32,32,32,32,99,111,110,110,101,99,116,101,100,67,97,108,108,98,97,99,107,40,
        41,123,10,32,32,32,32,32,32,108,101,116,32,114,111,111,116,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,97,116,116,97,99,104,83,104,97,100,111,119,41,10,32,32,32,32,32,32,32,32,114,111,
        111,116,61,116,104,105,115,46,97,116,116,97,99,104,83,104,97,100,111,119,40,123,109,111,100,101,58,32,39,111,112,101,110,39,125,41,59,10,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,
        32,114,111,111,116,61,116,104,105,115,59,10,32,32,32,32,32,32,114,111,111,116,46,105,110,110,101,114,72,84,77,76,61,10,96,60,115,116,121,108,101,62,10,36,123,116,104,105,115,46,98,97,115,101,115,
        116,121,108,101,125,10,58,104,111,115,116,123,10,32,32,100,105,115,112,108,97,121,58,105,110,108,105,110,101,45,98,108,111,99,107,59,10,32,32,117,115,101,114,45,115,101,108,101,99,116,58,110,111,
        110,101,59,10,32,32,109,97,114,103,105,110,58,48,59,10,32,32,112,97,100,100,105,110,103,58,48,59,10,32,32,102,111,110,116,45,102,97,109,105,108,121,58,32,115,97,110,115,45,115,101,114,105,102,59,
        10,32,32,102,111,110,116,45,115,105,122,101,58,32,56,112,120,59,10,32,32,99,117,114,115,111,114,58,112,111,105,110,116,101,114,59,10,32,32,112,111,115,105,116,105,111,110,58,114,101,108,97,116,105,
        118,101,59,10,32,32,118,101,114,116,105,99,97,108,45,97,108,105,103,110,58,98,97,115,101,108,105,110,101,59,10,125,10,46,119,101,98,97,117,100,105,111,45,112,97,114,97,109,45,98,111,100,121,123,
        10,32,32,100,105,115,112,108,97,121,58,105,110,108,105,110,101,45,98,108,111,99,107,59,10,32,32,112,111,115,105,116,105,111,110,58,114,101,108,97,116,105,118,101,59,10,32,32,116,101,120,116,45,97,
        108,105,103,110,58,99,101,110,116,101,114,59,10,32,32,98,97,99,107,103,114,111,117,110,100,58,110,111,110,101,59,10,32,32,109,97,114,103,105,110,58,48,59,10,32,32,112,97,100,100,105,110,103,58,48,
        59,10,32,32,102,111,110,116,45,102,97,109,105,108,121,58,115,97,110,115,45,115,101,114,105,102,59,10,32,32,102,111,110,116,45,115,105,122,101,58,49,49,112,120,59,10,32,32,118,101,114,116,105,99,
        97,108,45,97,108,105,103,110,58,98,111,116,116,111,109,59,10,32,32,98,111,114,100,101,114,58,110,111,110,101,59,10,125,10,60,47,115,116,121,108,101,62,10,60,105,110,112,117,116,32,99,108,97,115,
        115,61,39,119,101,98,97,117,100,105,111,45,112,97,114,97,109,45,98,111,100,121,39,32,118,97,108,117,101,61,39,48,39,32,116,97,98,105,110,100,101,120,61,39,49,39,32,116,111,117,99,104,45,97,99,116,
        105,111,110,61,39,110,111,110,101,39,47,62,60,100,105,118,32,99,108,97,115,115,61,39,119,101,98,97,117,100,105,111,99,116,114,108,45,116,111,111,108,116,105,112,39,62,60,47,100,105,118,62,10,96,
        59,10,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,61,114,111,111,116,46,99,104,105,108,100,78,111,100,101,115,91,50,93,59,10,32,32,32,32,32,32,116,104,105,115,46,116,116,102,114,97,109,
        101,61,114,111,111,116,46,99,104,105,108,100,78,111,100,101,115,91,51,93,59,10,32,32,32,32,32,32,116,104,105,115,46,101,110,97,98,108,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,101,
        110,97,98,108,101,34,44,49,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,118,97,108,117,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,118,97,108,117,101,34,44,48,41,59,32,105,102,
        32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,118,97,108,117,101,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,
        40,116,104,105,115,44,34,118,97,108,117,101,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,118,97,108,117,101,125,44,115,101,116,58,40,118,41,61,62,123,
        116,104,105,115,46,95,118,97,108,117,101,61,118,59,116,104,105,115,46,114,101,100,114,97,119,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,100,101,102,118,97,108,117,101,61,116,104,
        105,115,46,103,101,116,65,116,116,114,40,34,100,101,102,118,97,108,117,101,34,44,48,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,102,111,110,116,115,105,122,101,61,116,104,105,115,46,103,101,
        116,65,116,116,114,40,34,102,111,110,116,115,105,122,101,34,44,57,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,102,111,110,116,115,105,
        122,101,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,102,111,110,116,115,105,122,101,34,44,123,103,101,116,58,40,41,61,62,123,
        114,101,116,117,114,110,32,116,104,105,115,46,95,102,111,110,116,115,105,122,101,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,102,111,110,116,115,105,122,101,61,118,59,116,104,
        105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,115,114,99,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,115,114,99,34,44,
        111,112,116,46,112,97,114,97,109,83,114,99,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,115,114,99,34,41,41,32,79,98,106,101,99,116,46,
        100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,115,114,99,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,115,114,99,125,
        44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,115,114,99,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,
        46,108,105,110,107,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,108,105,110,107,34,44,34,34,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,119,105,100,116,104,61,116,104,105,115,46,103,
        101,116,65,116,116,114,40,34,119,105,100,116,104,34,44,111,112,116,46,112,97,114,97,109,87,105,100,116,104,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,
        116,121,40,34,119,105,100,116,104,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,119,105,100,116,104,34,44,123,103,101,116,58,
        40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,119,105,100,116,104,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,119,105,100,116,104,61,118,59,116,104,105,115,
        46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,104,101,105,103,104,116,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,104,101,105,
        103,104,116,34,44,111,112,116,46,112,97,114,97,109,72,101,105,103,104,116,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,104,101,105,103,
        104,116,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,104,101,105,103,104,116,34,44,123,103,101,116,58,40,41,61,62,123,114,101,
        116,117,114,110,32,116,104,105,115,46,95,104,101,105,103,104,116,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,104,101,105,103,104,116,61,118,59,116,104,105,115,46,115,101,116,
        117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,99,111,108,111,114,115,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,99,111,108,111,114,115,34,44,
        111,112,116,46,112,97,114,97,109,67,111,108,111,114,115,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,99,111,108,111,114,115,34,41,41,32,
        79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,99,111,108,111,114,115,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,
        116,104,105,115,46,95,99,111,108,111,114,115,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,99,111,108,111,114,115,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,
        101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,111,117,116,108,105,110,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,111,117,116,108,105,110,101,34,44,111,112,116,46,
        111,117,116,108,105,110,101,41,59,10,32,32,32,32,32,32,116,104,105,115,46,114,99,111,110,118,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,114,99,111,110,118,34,44,110,117,108,108,41,59,
        10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,67,111,110,116,114,111,108,108,101,114,61,123,125,59,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,77,111,100,101,61,34,110,111,
        114,109,97,108,34,59,10,32,32,32,32,32,32,116,104,105,115,46,99,117,114,114,101,110,116,76,105,110,107,61,110,117,108,108,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,109,105,100,105,99,
        99,41,32,123,10,32,32,32,32,32,32,32,32,108,101,116,32,99,104,32,61,32,112,97,114,115,101,73,110,116,40,116,104,105,115,46,109,105,100,105,99,99,46,115,117,98,115,116,114,105,110,103,40,48,44,32,
        116,104,105,115,46,109,105,100,105,99,99,46,108,97,115,116,73,110,100,101,120,79,102,40,34,46,34,41,41,41,32,45,32,49,59,10,32,32,32,32,32,32,32,32,108,101,116,32,99,99,32,61,32,112,97,114,115,101,
        73,110,116,40,116,104,105,115,46,109,105,100,105,99,99,46,115,117,98,115,116,114,105,110,103,40,116,104,105,115,46,109,105,100,105,99,99,46,108,97,115,116,73,110,100,101,120,79,102,40,34,46,34,41,
        32,43,32,49,41,41,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,77,105,100,105,67,111,110,116,114,111,108,108,101,114,40,99,104,44,32,99,99,41,59,10,32,32,32,32,32,32,125,10,32,32,
        32,32,32,32,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,59,10,32,32,32,32,32,32,105,102,40,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,
        115,87,105,100,103,101,116,77,97,110,97,103,101,114,41,10,47,47,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,
        116,77,97,110,97,103,101,114,46,117,112,100,97,116,101,87,105,100,103,101,116,115,40,41,59,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,
        111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,46,97,100,100,87,105,100,103,101,116,40,116,104,105,115,41,59,10,32,32,32,32,32,32,116,104,105,115,46,102,114,111,109,76,105,110,107,61,
        40,40,101,41,61,62,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,101,46,116,97,114,103,101,116,46,99,111,110,118,86,97,108,117,101,46,116,111,70,105,120,101,
        100,40,101,46,116,97,114,103,101,116,46,100,105,103,105,116,115,41,41,59,10,32,32,32,32,32,32,125,41,46,98,105,110,100,40,116,104,105,115,41,59,10,32,32,32,32,32,32,116,104,105,115,46,101,108,101,
        109,46,111,110,99,104,97,110,103,101,61,40,41,61,62,123,10,32,32,32,32,32,32,32,32,105,102,40,33,116,104,105,115,46,99,117,114,114,101,110,116,76,105,110,107,46,116,97,114,103,101,116,46,99,111,
        110,118,32,124,124,32,40,116,104,105,115,46,99,117,114,114,101,110,116,76,105,110,107,46,116,97,114,103,101,116,46,99,111,110,118,38,38,116,104,105,115,46,114,99,111,110,118,41,41,123,10,32,32,32,
        32,32,32,32,32,32,32,108,101,116,32,118,97,108,32,61,32,116,104,105,115,46,118,97,108,117,101,61,116,104,105,115,46,101,108,101,109,46,118,97,108,117,101,59,10,32,32,32,32,32,32,32,32,32,32,105,
        102,40,116,104,105,115,46,114,99,111,110,118,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,108,101,116,32,120,61,43,116,104,105,115,46,101,108,101,109,46,118,97,108,117,101,59,10,32,32,32,32,32,
        32,32,32,32,32,32,32,118,97,108,61,101,118,97,108,40,116,104,105,115,46,114,99,111,110,118,41,59,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,
        46,99,117,114,114,101,110,116,76,105,110,107,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,117,114,114,101,110,116,76,105,110,107,46,116,97,114,103,101,116,46,115,101,116,86,
        97,108,117,101,40,118,97,108,44,32,116,114,117,101,41,59,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,125,10,32,32,32,32,125,10,32,32,32,32,100,105,115,
        99,111,110,110,101,99,116,101,100,67,97,108,108,98,97,99,107,40,41,123,125,10,32,32,32,32,115,101,116,117,112,73,109,97,103,101,40,41,123,10,32,32,32,32,32,32,116,104,105,115,46,105,109,103,108,
        111,97,100,101,100,61,40,41,61,62,123,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,115,114,99,33,61,34,34,38,38,116,104,105,115,46,115,114,99,33,61,110,117,108,108,41,123,10,32,32,32,
        32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,73,109,97,103,101,32,61,32,34,117,114,108,40,34,43,116,104,105,115,46,115,114,
        99,43,34,41,34,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,83,105,122,101,32,61,32,34,49,48,48,37,32,49,
        48,48,37,34,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,119,105,100,116,104,61,61,110,117,108,108,41,32,116,104,105,115,46,95,119,105,100,116,104,61,116,104,105,115,46,105,
        109,103,46,119,105,100,116,104,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,104,101,105,103,104,116,61,61,110,117,108,108,41,32,116,104,105,115,46,95,104,101,105,103,104,
        116,61,116,104,105,115,46,105,109,103,46,104,101,105,103,104,116,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,101,108,115,101,123,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,
        104,105,115,46,95,119,105,100,116,104,61,61,110,117,108,108,41,32,116,104,105,115,46,95,119,105,100,116,104,61,51,50,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,104,101,
        105,103,104,116,61,61,110,117,108,108,41,32,116,104,105,115,46,95,104,101,105,103,104,116,61,50,48,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,
        46,115,116,121,108,101,46,119,105,100,116,104,61,116,104,105,115,46,95,119,105,100,116,104,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,
        46,104,101,105,103,104,116,61,116,104,105,115,46,95,104,101,105,103,104,116,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,102,111,110,
        116,83,105,122,101,61,116,104,105,115,46,102,111,110,116,115,105,122,101,43,34,112,120,34,59,10,32,32,32,32,32,32,32,32,108,101,116,32,108,61,100,111,99,117,109,101,110,116,46,103,101,116,69,108,
        101,109,101,110,116,66,121,73,100,40,116,104,105,115,46,108,105,110,107,41,59,10,32,32,32,32,32,32,32,32,105,102,40,108,38,38,116,121,112,101,111,102,40,108,46,118,97,108,117,101,41,33,61,34,117,
        110,100,101,102,105,110,101,100,34,41,123,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,121,112,101,111,102,40,108,46,99,111,110,118,86,97,108,117,101,41,61,61,34,110,117,109,98,101,114,34,41,
        10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,108,46,99,111,110,118,86,97,108,117,101,46,116,111,70,105,120,101,100,40,108,46,100,105,103,105,116,115,
        41,41,59,10,32,32,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,108,46,99,111,110,118,86,97,108,117,101,41,59,
        10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,99,117,114,114,101,110,116,76,105,110,107,41,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,117,114,114,101,110,116,76,
        105,110,107,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,105,110,112,117,116,34,44,116,104,105,115,46,99,117,114,114,101,110,116,76,105,110,107,46,102,117,110,
        99,41,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,117,114,114,101,110,116,76,105,110,107,61,123,116,97,114,103,101,116,58,108,44,32,102,117,110,99,58,40,101,41,61,62,123,10,32,32,32,
        32,32,32,32,32,32,32,32,32,105,102,40,116,121,112,101,111,102,40,108,46,99,111,110,118,86,97,108,117,101,41,61,61,34,110,117,109,98,101,114,34,41,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,116,
        104,105,115,46,115,101,116,86,97,108,117,101,40,108,46,99,111,110,118,86,97,108,117,101,46,116,111,70,105,120,101,100,40,108,46,100,105,103,105,116,115,41,41,59,10,32,32,32,32,32,32,32,32,32,32,
        32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,86,97,108,117,101,40,108,46,99,111,110,118,86,97,108,117,101,41,59,10,32,32,32,32,32,32,32,32,32,
        32,125,125,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,117,114,114,101,110,116,76,105,110,107,46,116,97,114,103,101,116,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,
        114,40,34,105,110,112,117,116,34,44,116,104,105,115,46,99,117,114,114,101,110,116,76,105,110,107,46,102,117,110,99,41,59,10,32,32,47,47,32,32,32,32,32,32,32,32,108,46,97,100,100,69,118,101,110,116,
        76,105,115,116,101,110,101,114,40,34,105,110,112,117,116,34,44,40,101,41,61,62,123,116,104,105,115,46,115,101,116,86,97,108,117,101,40,108,46,99,111,110,118,86,97,108,117,101,46,116,111,70,105,120,
        101,100,40,108,46,100,105,103,105,116,115,41,41,125,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,97,119,40,41,59,10,32,32,32,32,32,32,125,59,
        10,32,32,32,32,32,32,116,104,105,115,46,99,111,108,116,97,98,32,61,32,116,104,105,115,46,99,111,108,111,114,115,46,115,112,108,105,116,40,34,59,34,41,59,10,32,32,32,32,32,32,116,104,105,115,46,101,
        108,101,109,46,115,116,121,108,101,46,99,111,108,111,114,61,116,104,105,115,46,99,111,108,116,97,98,91,48,93,59,10,32,32,32,32,32,32,116,104,105,115,46,105,109,103,61,110,101,119,32,73,109,97,103,
        101,40,41,59,10,32,32,32,32,32,32,116,104,105,115,46,105,109,103,46,111,110,108,111,97,100,61,116,104,105,115,46,105,109,103,108,111,97,100,101,100,46,98,105,110,100,40,41,59,10,32,32,32,32,32,32,
        105,102,40,116,104,105,115,46,115,114,99,61,61,110,117,108,108,41,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,
        67,111,108,111,114,61,116,104,105,115,46,99,111,108,116,97,98,91,49,93,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,105,109,103,108,111,97,100,101,100,40,41,59,10,32,32,32,32,32,32,125,10,32,
        32,32,32,32,32,101,108,115,101,32,105,102,40,116,104,105,115,46,115,114,99,61,61,34,34,41,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,115,116,121,108,101,46,98,97,99,107,
        103,114,111,117,110,100,61,34,110,111,110,101,34,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,105,109,103,108,111,97,100,101,100,40,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,
        115,101,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,105,109,103,46,115,114,99,61,116,104,105,115,46,115,114,99,59,10,32,32,32,32,32,32,125,10,32,32,32,32,125,10,32,32,32,32,114,101,100,114,
        97,119,40,41,32,123,10,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,118,97,108,117,101,61,116,104,105,115,46,118,97,108,117,101,59,10,32,32,32,32,125,10,32,32,32,32,115,101,116,86,97,
        108,117,101,40,118,44,102,41,123,10,32,32,32,32,32,32,116,104,105,115,46,118,97,108,117,101,61,118,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,118,97,108,117,101,33,61,116,104,105,115,
        46,111,108,100,118,97,108,117,101,41,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,97,119,40,41,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,104,111,119,116,105,112,40,
        48,41,59,10,32,32,32,32,32,32,32,32,105,102,40,102,41,123,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,101,118,101,110,116,32,61,32,110,101,119,32,69,118,101,110,116,40,34,99,104,97,110,103,101,
        34,44,32,123,98,117,98,98,108,101,115,58,111,112,116,46,98,117,98,98,108,101,115,63,116,114,117,101,58,102,97,108,115,101,44,32,99,97,110,99,101,108,97,98,108,101,58,111,112,116,46,99,97,110,99,
        101,108,97,98,108,101,63,116,114,117,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,100,105,115,112,97,116,99,104,69,118,101,110,116,40,101,118,101,110,116,
        41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,116,104,105,115,46,111,108,100,118,97,108,117,101,61,116,104,105,115,46,118,97,108,117,101,59,10,32,32,32,32,32,32,125,10,32,32,32,
        32,125,10,32,32,32,32,112,111,105,110,116,101,114,100,111,119,110,40,101,118,41,123,10,32,32,32,32,32,32,105,102,40,33,116,104,105,115,46,101,110,97,98,108,101,41,10,32,32,32,32,32,32,32,32,114,
        101,116,117,114,110,59,10,32,32,32,32,32,32,108,101,116,32,101,61,101,118,59,10,32,32,32,32,32,32,105,102,40,101,118,46,116,111,117,99,104,101,115,41,10,32,32,32,32,32,32,32,32,32,32,101,32,61,32,
        101,118,46,116,111,117,99,104,101,115,91,48,93,59,10,32,32,32,32,32,32,101,108,115,101,32,123,10,32,32,32,32,32,32,32,32,105,102,40,101,46,98,117,116,116,111,110,115,33,61,49,32,38,38,32,101,46,
        98,117,116,116,111,110,33,61,48,41,10,32,32,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,46,102,111,99,117,
        115,40,41,59,10,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,97,119,40,41,59,10,32,32,32,32,125,10,32,32,125,41,59,10,125,32,99,97,116,99,104,40,101,114,114,111,114,41,123,10,32,32,99,111,
        110,115,111,108,101,46,108,111,103,40,34,119,101,98,97,117,100,105,111,45,112,97,114,97,109,32,97,108,114,101,97,100,121,32,100,101,102,105,110,101,100,34,41,59,10,125,10,10,116,114,121,123,10,32,
        32,99,117,115,116,111,109,69,108,101,109,101,110,116,115,46,100,101,102,105,110,101,40,34,119,101,98,97,117,100,105,111,45,107,101,121,98,111,97,114,100,34,44,32,99,108,97,115,115,32,87,101,98,65,
        117,100,105,111,75,101,121,98,111,97,114,100,32,101,120,116,101,110,100,115,32,87,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,32,123,10,32,32,32,32,99,111,110,
        115,116,114,117,99,116,111,114,40,41,123,10,32,32,32,32,32,32,115,117,112,101,114,40,41,59,10,32,32,32,32,125,10,32,32,32,32,99,111,110,110,101,99,116,101,100,67,97,108,108,98,97,99,107,40,41,123,
        10,32,32,32,32,32,32,108,101,116,32,114,111,111,116,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,97,116,116,97,99,104,83,104,97,100,111,119,41,10,32,32,32,32,32,32,32,32,114,111,111,116,
        61,116,104,105,115,46,97,116,116,97,99,104,83,104,97,100,111,119,40,123,109,111,100,101,58,32,39,111,112,101,110,39,125,41,59,10,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,114,
        111,111,116,61,116,104,105,115,59,10,32,32,32,32,32,32,114,111,111,116,46,105,110,110,101,114,72,84,77,76,61,10,96,60,115,116,121,108,101,62,10,36,123,116,104,105,115,46,98,97,115,101,115,116,121,
        108,101,125,10,58,104,111,115,116,123,10,32,32,100,105,115,112,108,97,121,58,105,110,108,105,110,101,45,98,108,111,99,107,59,10,32,32,112,111,115,105,116,105,111,110,58,114,101,108,97,116,105,118,
        101,59,10,32,32,109,97,114,103,105,110,58,48,59,10,32,32,112,97,100,100,105,110,103,58,48,59,10,32,32,102,111,110,116,45,102,97,109,105,108,121,58,32,115,97,110,115,45,115,101,114,105,102,59,10,
        32,32,102,111,110,116,45,115,105,122,101,58,32,49,49,112,120,59,10,125,10,46,119,101,98,97,117,100,105,111,45,107,101,121,98,111,97,114,100,45,98,111,100,121,123,10,32,32,100,105,115,112,108,97,
        121,58,105,110,108,105,110,101,45,98,108,111,99,107,59,10,32,32,109,97,114,103,105,110,58,48,59,10,32,32,112,97,100,100,105,110,103,58,48,59,10,32,32,118,101,114,116,105,99,97,108,45,97,108,105,
        103,110,58,98,111,116,116,111,109,59,10,125,10,60,47,115,116,121,108,101,62,10,60,99,97,110,118,97,115,32,99,108,97,115,115,61,39,119,101,98,97,117,100,105,111,45,107,101,121,98,111,97,114,100,45,
        98,111,100,121,39,32,116,97,98,105,110,100,101,120,61,39,49,39,32,116,111,117,99,104,45,97,99,116,105,111,110,61,39,110,111,110,101,39,62,60,47,99,97,110,118,97,115,62,60,100,105,118,32,99,108,97,
        115,115,61,39,119,101,98,97,117,105,111,99,116,114,108,45,116,111,111,108,116,105,112,39,62,60,47,100,105,118,62,10,96,59,10,32,32,32,32,32,32,116,104,105,115,46,101,108,101,109,61,116,104,105,115,
        46,99,118,61,114,111,111,116,46,99,104,105,108,100,78,111,100,101,115,91,50,93,59,10,32,32,32,32,32,32,116,104,105,115,46,116,116,102,114,97,109,101,61,114,111,111,116,46,99,104,105,108,100,78,111,
        100,101,115,91,51,93,59,10,32,32,32,32,32,32,116,104,105,115,46,99,116,120,61,116,104,105,115,46,99,118,46,103,101,116,67,111,110,116,101,120,116,40,34,50,100,34,41,59,10,32,32,32,32,32,32,116,104,
        105,115,46,95,118,97,108,117,101,115,61,91,93,59,10,32,32,32,32,32,32,116,104,105,115,46,101,110,97,98,108,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,101,110,97,98,108,101,34,44,
        49,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,119,105,100,116,104,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,119,105,100,116,104,34,44,52,56,48,41,59,32,105,102,32,40,33,116,104,
        105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,119,105,100,116,104,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,
        115,44,34,119,105,100,116,104,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,119,105,100,116,104,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,
        115,46,95,119,105,100,116,104,61,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,104,101,105,103,104,116,61,116,104,
        105,115,46,103,101,116,65,116,116,114,40,34,104,101,105,103,104,116,34,44,49,50,56,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,104,101,
        105,103,104,116,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,104,101,105,103,104,116,34,44,123,103,101,116,58,40,41,61,62,123,
        114,101,116,117,114,110,32,116,104,105,115,46,95,104,101,105,103,104,116,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,104,101,105,103,104,116,61,118,59,116,104,105,115,46,115,
        101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,109,105,110,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,109,105,110,34,44,48,41,59,32,
        105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,109,105,110,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,
        121,40,116,104,105,115,44,34,109,105,110,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,109,105,110,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,
        115,46,95,109,105,110,61,43,118,59,116,104,105,115,46,114,101,100,114,97,119,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,95,107,101,121,115,61,116,104,105,115,46,103,101,116,65,116,
        116,114,40,34,107,101,121,115,34,44,50,53,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,107,101,121,115,34,41,41,32,79,98,106,101,99,116,
        46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,107,101,121,115,34,44,123,103,101,116,58,40,41,61,62,123,114,101,116,117,114,110,32,116,104,105,115,46,95,107,101,
        121,115,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,107,101,121,115,61,43,118,59,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,
        32,116,104,105,115,46,95,99,111,108,111,114,115,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,99,111,108,111,114,115,34,44,34,35,50,50,50,59,35,101,101,101,59,35,99,99,99,59,35,51,51,51,
        59,35,48,48,48,59,35,101,56,56,59,35,99,52,52,59,35,99,51,51,59,35,56,48,48,34,41,59,32,105,102,32,40,33,116,104,105,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,34,99,111,108,
        111,114,115,34,41,41,32,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,34,99,111,108,111,114,115,34,44,123,103,101,116,58,40,41,61,62,123,114,
        101,116,117,114,110,32,116,104,105,115,46,95,99,111,108,111,114,115,125,44,115,101,116,58,40,118,41,61,62,123,116,104,105,115,46,95,99,111,108,111,114,115,61,118,59,116,104,105,115,46,115,101,116,
        117,112,73,109,97,103,101,40,41,125,125,41,59,10,32,32,32,32,32,32,116,104,105,115,46,111,117,116,108,105,110,101,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,111,117,116,108,105,110,101,
        34,44,111,112,116,46,111,117,116,108,105,110,101,41,59,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,108,101,97,114,110,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,109,105,100,
        105,108,101,97,114,110,34,44,48,41,59,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,99,99,61,116,104,105,115,46,103,101,116,65,116,116,114,40,34,109,105,100,105,99,99,34,44,110,117,108,
        108,41,59,10,32,32,32,32,32,32,116,104,105,115,46,112,114,101,115,115,61,48,59,10,32,32,32,32,32,32,116,104,105,115,46,107,101,121,99,111,100,101,115,49,61,91,57,48,44,56,51,44,56,56,44,54,56,44,
        54,55,44,56,54,44,55,49,44,54,54,44,55,50,44,55,56,44,55,52,44,55,55,44,49,56,56,44,55,54,44,49,57,48,44,49,56,55,44,49,57,49,44,50,50,54,93,59,10,32,32,32,32,32,32,116,104,105,115,46,107,101,121,
        99,111,100,101,115,50,61,91,56,49,44,53,48,44,56,55,44,53,49,44,54,57,44,56,50,44,53,51,44,56,52,44,53,52,44,56,57,44,53,53,44,56,53,44,55,51,44,53,55,44,55,57,44,52,56,44,56,48,44,49,57,50,44,50,
        50,50,44,50,49,57,93,59,10,32,32,32,32,32,32,116,104,105,115,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,107,101,121,117,112,34,44,116,104,105,115,46,107,101,121,117,112,
        41,59,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,67,111,110,116,114,111,108,108,101,114,61,123,125,59,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,77,111,100,101,61,34,110,
        111,114,109,97,108,34,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,109,105,100,105,99,99,41,32,123,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,99,104,32,61,32,112,97,114,115,101,73,
        110,116,40,116,104,105,115,46,109,105,100,105,99,99,46,115,117,98,115,116,114,105,110,103,40,48,44,32,116,104,105,115,46,109,105,100,105,99,99,46,108,97,115,116,73,110,100,101,120,79,102,40,34,46,
        34,41,41,41,32,45,32,49,59,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,99,99,32,61,32,112,97,114,115,101,73,110,116,40,116,104,105,115,46,109,105,100,105,99,99,46,115,117,98,115,116,114,105,
        110,103,40,116,104,105,115,46,109,105,100,105,99,99,46,108,97,115,116,73,110,100,101,120,79,102,40,34,46,34,41,32,43,32,49,41,41,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,
        77,105,100,105,67,111,110,116,114,111,108,108,101,114,40,99,104,44,32,99,99,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,116,104,105,115,46,115,101,116,117,112,73,109,97,103,101,40,41,59,
        10,32,32,32,32,32,32,116,104,105,115,46,100,105,103,105,116,115,61,48,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,115,116,101,112,32,38,38,32,116,104,105,115,46,115,116,101,112,32,60,32,
        49,41,32,123,10,32,32,32,32,32,32,32,32,102,111,114,40,108,101,116,32,110,32,61,32,116,104,105,115,46,115,116,101,112,32,59,32,110,32,60,32,49,59,32,110,32,42,61,32,49,48,41,10,32,32,32,32,32,32,
        32,32,32,32,43,43,116,104,105,115,46,100,105,103,105,116,115,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,
        111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,41,10,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,
        116,77,97,110,97,103,101,114,46,97,100,100,87,105,100,103,101,116,40,116,104,105,115,41,59,10,32,32,32,32,125,10,32,32,32,32,100,105,115,99,111,110,110,101,99,116,101,100,67,97,108,108,98,97,99,
        107,40,41,123,125,10,32,32,32,32,115,101,116,117,112,73,109,97,103,101,40,41,123,10,32,32,32,32,32,32,116,104,105,115,46,99,118,46,115,116,121,108,101,46,119,105,100,116,104,61,116,104,105,115,46,
        119,105,100,116,104,43,34,112,120,34,59,10,32,32,32,32,32,32,116,104,105,115,46,99,118,46,115,116,121,108,101,46,104,101,105,103,104,116,61,116,104,105,115,46,104,101,105,103,104,116,43,34,112,120,
        34,59,10,32,32,32,32,32,32,116,104,105,115,46,98,104,101,105,103,104,116,32,61,32,116,104,105,115,46,104,101,105,103,104,116,32,42,32,48,46,53,53,59,10,32,32,32,32,32,32,116,104,105,115,46,107,112,
        61,91,48,44,55,47,49,50,44,49,44,51,42,55,47,49,50,44,50,44,51,44,54,42,55,47,49,50,44,52,44,56,42,55,47,49,50,44,53,44,49,48,42,55,47,49,50,44,54,93,59,10,32,32,32,32,32,32,116,104,105,115,46,107,
        102,61,91,48,44,49,44,48,44,49,44,48,44,48,44,49,44,48,44,49,44,48,44,49,44,48,93,59,10,32,32,32,32,32,32,116,104,105,115,46,107,111,61,91,48,44,48,44,40,55,42,50,41,47,49,50,45,49,44,48,44,40,55,
        42,52,41,47,49,50,45,50,44,40,55,42,53,41,47,49,50,45,51,44,48,44,40,55,42,55,41,47,49,50,45,52,44,48,44,40,55,42,57,41,47,49,50,45,53,44,48,44,40,55,42,49,49,41,47,49,50,45,54,93,59,10,32,32,32,
        32,32,32,116,104,105,115,46,107,110,61,91,48,44,50,44,52,44,53,44,55,44,57,44,49,49,93,59,10,32,32,32,32,32,32,116,104,105,115,46,99,111,108,116,97,98,61,116,104,105,115,46,99,111,108,111,114,115,
        46,115,112,108,105,116,40,34,59,34,41,59,10,32,32,32,32,32,32,116,104,105,115,46,99,118,46,119,105,100,116,104,32,61,32,116,104,105,115,46,119,105,100,116,104,59,10,32,32,32,32,32,32,116,104,105,
        115,46,99,118,46,104,101,105,103,104,116,32,61,32,116,104,105,115,46,104,101,105,103,104,116,59,10,32,32,32,32,32,32,116,104,105,115,46,99,118,46,115,116,121,108,101,46,119,105,100,116,104,32,61,
        32,116,104,105,115,46,119,105,100,116,104,43,39,112,120,39,59,10,32,32,32,32,32,32,116,104,105,115,46,99,118,46,115,116,121,108,101,46,104,101,105,103,104,116,32,61,32,116,104,105,115,46,104,101,
        105,103,104,116,43,39,112,120,39,59,10,32,32,32,32,32,32,116,104,105,115,46,115,116,121,108,101,46,104,101,105,103,104,116,32,61,32,116,104,105,115,46,104,101,105,103,104,116,43,39,112,120,39,59,
        10,32,32,32,32,32,32,116,104,105,115,46,99,118,46,115,116,121,108,101,46,111,117,116,108,105,110,101,61,116,104,105,115,46,111,117,116,108,105,110,101,63,34,34,58,34,110,111,110,101,34,59,10,32,
        32,32,32,32,32,116,104,105,115,46,98,104,101,105,103,104,116,32,61,32,116,104,105,115,46,104,101,105,103,104,116,32,42,32,48,46,53,53,59,10,32,32,32,32,32,32,116,104,105,115,46,109,97,120,61,116,
        104,105,115,46,109,105,110,43,116,104,105,115,46,107,101,121,115,45,49,59,10,32,32,32,32,32,32,116,104,105,115,46,100,105,115,112,118,97,108,117,101,115,61,91,93,59,10,32,32,32,32,32,32,116,104,
        105,115,46,100,105,115,97,98,108,101,100,118,97,108,117,101,115,61,91,93,59,10,32,32,32,32,32,32,116,104,105,115,46,118,97,108,117,101,115,111,108,100,61,91,93,59,10,32,32,32,32,32,32,105,102,40,
        116,104,105,115,46,107,102,91,116,104,105,115,46,109,105,110,37,49,50,93,41,10,32,32,32,32,32,32,32,32,45,45,116,104,105,115,46,109,105,110,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,
        107,102,91,116,104,105,115,46,109,97,120,37,49,50,93,41,10,32,32,32,32,32,32,32,32,43,43,116,104,105,115,46,109,97,120,59,10,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,97,119,40,41,59,
        10,32,32,32,32,125,10,32,32,32,32,114,101,100,114,97,119,40,41,123,10,32,32,32,32,32,32,102,117,110,99,116,105,111,110,32,114,114,101,99,116,40,99,116,120,44,32,120,44,32,121,44,32,119,44,32,104,
        44,32,114,44,32,99,49,44,32,99,50,41,32,123,10,32,32,32,32,32,32,32,32,105,102,40,99,50,41,32,123,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,103,61,99,116,120,46,99,114,101,97,116,101,76,105,
        110,101,97,114,71,114,97,100,105,101,110,116,40,120,44,121,44,120,43,119,44,121,41,59,10,32,32,32,32,32,32,32,32,32,32,103,46,97,100,100,67,111,108,111,114,83,116,111,112,40,48,44,99,49,41,59,10,
        32,32,32,32,32,32,32,32,32,32,103,46,97,100,100,67,111,108,111,114,83,116,111,112,40,49,44,99,50,41,59,10,32,32,32,32,32,32,32,32,32,32,99,116,120,46,102,105,108,108,83,116,121,108,101,61,103,59,
        10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,32,32,99,116,120,46,102,105,108,108,83,116,121,108,101,61,99,49,59,10,32,32,32,32,32,32,32,32,
        99,116,120,46,98,101,103,105,110,80,97,116,104,40,41,59,10,32,32,32,32,32,32,32,32,99,116,120,46,109,111,118,101,84,111,40,120,44,32,121,41,59,10,32,32,32,32,32,32,32,32,99,116,120,46,108,105,110,
        101,84,111,40,120,43,119,44,32,121,41,59,10,32,32,32,32,32,32,32,32,99,116,120,46,108,105,110,101,84,111,40,120,43,119,44,32,121,43,104,45,114,41,59,10,32,32,32,32,32,32,32,32,99,116,120,46,113,
        117,97,100,114,97,116,105,99,67,117,114,118,101,84,111,40,120,43,119,44,32,121,43,104,44,32,120,43,119,45,114,44,32,121,43,104,41,59,10,32,32,32,32,32,32,32,32,99,116,120,46,108,105,110,101,84,111,
        40,120,43,114,44,32,121,43,104,41,59,10,32,32,32,32,32,32,32,32,99,116,120,46,113,117,97,100,114,97,116,105,99,67,117,114,118,101,84,111,40,120,44,32,121,43,104,44,32,120,44,32,121,43,104,45,114,
        41,59,10,32,32,32,32,32,32,32,32,99,116,120,46,108,105,110,101,84,111,40,120,44,32,121,41,59,10,32,32,32,32,32,32,32,32,99,116,120,46,102,105,108,108,40,41,59,10,32,32,32,32,32,32,125,10,32,32,32,
        32,32,32,116,104,105,115,46,99,116,120,46,102,105,108,108,83,116,121,108,101,32,61,32,116,104,105,115,46,99,111,108,116,97,98,91,48,93,59,10,32,32,32,32,32,32,116,104,105,115,46,99,116,120,46,102,
        105,108,108,82,101,99,116,40,48,44,48,44,116,104,105,115,46,119,105,100,116,104,44,116,104,105,115,46,104,101,105,103,104,116,41,59,10,32,32,32,32,32,32,108,101,116,32,120,48,61,55,42,40,40,116,
        104,105,115,46,109,105,110,47,49,50,41,124,48,41,43,116,104,105,115,46,107,112,91,116,104,105,115,46,109,105,110,37,49,50,93,59,10,32,32,32,32,32,32,108,101,116,32,120,49,61,55,42,40,40,116,104,
        105,115,46,109,97,120,47,49,50,41,124,48,41,43,116,104,105,115,46,107,112,91,116,104,105,115,46,109,97,120,37,49,50,93,59,10,32,32,32,32,32,32,108,101,116,32,110,61,120,49,45,120,48,59,10,32,32,
        32,32,32,32,116,104,105,115,46,119,119,105,100,116,104,61,40,116,104,105,115,46,119,105,100,116,104,45,49,41,47,40,110,43,49,41,59,10,32,32,32,32,32,32,116,104,105,115,46,98,119,105,100,116,104,
        61,116,104,105,115,46,119,119,105,100,116,104,42,55,47,49,50,59,10,32,32,32,32,32,32,108,101,116,32,104,50,61,116,104,105,115,46,98,104,101,105,103,104,116,59,10,32,32,32,32,32,32,108,101,116,32,
        114,61,77,97,116,104,46,109,105,110,40,56,44,116,104,105,115,46,119,119,105,100,116,104,42,48,46,50,41,59,10,32,32,32,32,32,32,102,111,114,40,108,101,116,32,105,61,116,104,105,115,46,109,105,110,
        44,106,61,48,59,105,60,61,116,104,105,115,46,109,97,120,59,43,43,105,41,32,123,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,107,102,91,105,37,49,50,93,61,61,48,41,32,123,10,32,32,32,
        32,32,32,32,32,32,32,108,101,116,32,120,61,116,104,105,115,46,119,119,105,100,116,104,42,40,106,43,43,41,43,49,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,100,105,115,97,98,
        108,101,100,118,97,108,117,101,115,46,105,110,100,101,120,79,102,40,105,41,62,61,48,41,10,32,32,32,32,32,32,32,32,32,32,32,32,114,114,101,99,116,40,116,104,105,115,46,99,116,120,44,120,44,49,44,
        116,104,105,115,46,119,119,105,100,116,104,45,49,44,116,104,105,115,46,104,101,105,103,104,116,45,50,44,114,44,116,104,105,115,46,99,111,108,116,97,98,91,51,93,44,116,104,105,115,46,99,111,108,116,
        97,98,91,51,93,41,59,10,32,32,32,32,32,32,32,32,32,32,101,108,115,101,32,105,102,40,116,104,105,115,46,100,105,115,112,118,97,108,117,101,115,46,105,110,100,101,120,79,102,40,105,41,62,61,48,41,
        10,32,32,32,32,32,32,32,32,32,32,32,32,114,114,101,99,116,40,116,104,105,115,46,99,116,120,44,120,44,49,44,116,104,105,115,46,119,119,105,100,116,104,45,49,44,116,104,105,115,46,104,101,105,103,
        104,116,45,50,44,114,44,116,104,105,115,46,99,111,108,116,97,98,91,53,93,44,116,104,105,115,46,99,111,108,116,97,98,91,54,93,41,59,10,32,32,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,
        32,32,32,32,32,32,32,32,114,114,101,99,116,40,116,104,105,115,46,99,116,120,44,120,44,49,44,116,104,105,115,46,119,119,105,100,116,104,45,49,44,116,104,105,115,46,104,101,105,103,104,116,45,50,44,
        114,44,116,104,105,115,46,99,111,108,116,97,98,91,49,93,44,116,104,105,115,46,99,111,108,116,97,98,91,50,93,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,114,
        61,77,97,116,104,46,109,105,110,40,56,44,116,104,105,115,46,98,119,105,100,116,104,42,48,46,51,41,59,10,32,32,32,32,32,32,102,111,114,40,108,101,116,32,105,61,116,104,105,115,46,109,105,110,59,105,
        60,116,104,105,115,46,109,97,120,59,43,43,105,41,32,123,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,107,102,91,105,37,49,50,93,41,32,123,10,32,32,32,32,32,32,32,32,32,32,108,101,116,
        32,120,61,116,104,105,115,46,119,119,105,100,116,104,42,116,104,105,115,46,107,111,91,116,104,105,115,46,109,105,110,37,49,50,93,43,116,104,105,115,46,98,119,105,100,116,104,42,40,105,45,116,104,
        105,115,46,109,105,110,41,43,49,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,100,105,115,97,98,108,101,100,118,97,108,117,101,115,46,105,110,100,101,120,79,102,40,105,41,62,
        61,48,41,10,32,32,32,32,32,32,32,32,32,32,32,32,114,114,101,99,116,40,116,104,105,115,46,99,116,120,44,120,44,49,44,116,104,105,115,46,98,119,105,100,116,104,44,104,50,44,114,44,116,104,105,115,
        46,99,111,108,116,97,98,91,51,93,44,116,104,105,115,46,99,111,108,116,97,98,91,51,93,41,59,10,32,32,32,32,32,32,32,32,32,32,101,108,115,101,32,105,102,40,116,104,105,115,46,100,105,115,112,118,97,
        108,117,101,115,46,105,110,100,101,120,79,102,40,105,41,62,61,48,41,10,32,32,32,32,32,32,32,32,32,32,32,32,114,114,101,99,116,40,116,104,105,115,46,99,116,120,44,120,44,49,44,116,104,105,115,46,
        98,119,105,100,116,104,44,104,50,44,114,44,116,104,105,115,46,99,111,108,116,97,98,91,55,93,44,116,104,105,115,46,99,111,108,116,97,98,91,56,93,41,59,10,32,32,32,32,32,32,32,32,32,32,101,108,115,
        101,10,32,32,32,32,32,32,32,32,32,32,32,32,114,114,101,99,116,40,116,104,105,115,46,99,116,120,44,120,44,49,44,116,104,105,115,46,98,119,105,100,116,104,44,104,50,44,114,44,116,104,105,115,46,99,
        111,108,116,97,98,91,51,93,44,116,104,105,115,46,99,111,108,116,97,98,91,52,93,41,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,116,120,46,115,116,114,111,107,101,83,116,121,108,101,
        61,116,104,105,115,46,99,111,108,116,97,98,91,48,93,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,116,120,46,115,116,114,111,107,101,40,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,
        32,32,32,32,125,10,32,32,32,32,125,10,32,32,32,32,95,115,101,116,86,97,108,117,101,40,118,41,123,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,115,116,101,112,41,10,32,32,32,32,32,32,32,32,
        118,61,40,77,97,116,104,46,114,111,117,110,100,40,40,118,45,116,104,105,115,46,109,105,110,41,47,116,104,105,115,46,115,116,101,112,41,41,42,116,104,105,115,46,115,116,101,112,43,116,104,105,115,
        46,109,105,110,59,10,32,32,32,32,32,32,116,104,105,115,46,95,118,97,108,117,101,61,77,97,116,104,46,109,105,110,40,116,104,105,115,46,109,97,120,44,77,97,116,104,46,109,97,120,40,116,104,105,115,
        46,109,105,110,44,118,41,41,59,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,118,97,108,117,101,33,61,116,104,105,115,46,111,108,100,118,97,108,117,101,41,123,10,32,32,32,32,32,32,32,32,
        116,104,105,115,46,111,108,100,118,97,108,117,101,61,116,104,105,115,46,95,118,97,108,117,101,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,97,119,40,41,59,10,32,32,32,32,32,32,
        32,32,116,104,105,115,46,115,104,111,119,116,105,112,40,48,41,59,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,32,49,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,114,101,116,117,114,110,
        32,48,59,10,32,32,32,32,125,10,32,32,32,32,115,101,116,86,97,108,117,101,40,118,44,102,41,123,10,32,32,32,32,32,32,105,102,40,116,104,105,115,46,95,115,101,116,86,97,108,117,101,40,118,41,32,38,
        38,32,102,41,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,100,69,118,101,110,116,40,34,105,110,112,117,116,34,41,44,116,104,105,115,46,115,101,110,100,69,118,101,110,116,40,34,99,104,
        97,110,103,101,34,41,59,10,32,32,32,32,125,10,32,32,32,32,119,104,101,101,108,40,101,41,123,125,10,32,32,32,32,107,101,121,100,111,119,110,40,101,41,123,10,32,32,32,32,32,32,108,101,116,32,109,61,
        77,97,116,104,46,102,108,111,111,114,40,40,116,104,105,115,46,109,105,110,43,49,49,41,47,49,50,41,42,49,50,59,10,32,32,32,32,32,32,108,101,116,32,107,61,116,104,105,115,46,107,101,121,99,111,100,
        101,115,49,46,105,110,100,101,120,79,102,40,101,46,107,101,121,67,111,100,101,41,59,10,32,32,32,32,32,32,105,102,40,107,60,48,41,32,123,10,32,32,32,32,32,32,32,32,107,61,116,104,105,115,46,107,101,
        121,99,111,100,101,115,50,46,105,110,100,101,120,79,102,40,101,46,107,101,121,67,111,100,101,41,59,10,32,32,32,32,32,32,32,32,105,102,40,107,62,61,48,41,32,107,43,61,49,50,59,10,32,32,32,32,32,32,
        125,10,32,32,32,32,32,32,105,102,40,107,62,61,48,41,123,10,32,32,32,32,32,32,32,32,107,43,61,109,59,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,99,117,114,114,101,110,116,75,101,121,
        33,61,107,41,123,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,99,117,114,114,101,110,116,75,101,121,61,107,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,100,69,118,101,
        110,116,70,114,111,109,75,101,121,40,49,44,107,41,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,78,111,116,101,40,49,44,107,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,
        32,32,32,125,10,32,32,32,32,125,10,32,32,32,32,107,101,121,117,112,40,101,41,123,10,32,32,32,32,32,32,108,101,116,32,109,61,77,97,116,104,46,102,108,111,111,114,40,40,116,104,105,115,46,109,105,
        110,43,49,49,41,47,49,50,41,42,49,50,59,10,32,32,32,32,32,32,108,101,116,32,107,61,116,104,105,115,46,107,101,121,99,111,100,101,115,49,46,105,110,100,101,120,79,102,40,101,46,107,101,121,67,111,
        100,101,41,59,10,32,32,32,32,32,32,105,102,40,107,60,48,41,32,123,10,32,32,32,32,32,32,32,32,107,61,116,104,105,115,46,107,101,121,99,111,100,101,115,50,46,105,110,100,101,120,79,102,40,101,46,107,
        101,121,67,111,100,101,41,59,10,32,32,32,32,32,32,32,32,105,102,40,107,62,61,48,41,32,107,43,61,49,50,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,107,62,61,48,41,123,10,32,32,32,
        32,32,32,32,32,107,43,61,109,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,99,117,114,114,101,110,116,75,101,121,61,45,49,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,100,69,118,
        101,110,116,70,114,111,109,75,101,121,40,48,44,107,41,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,78,111,116,101,40,48,44,107,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,125,10,
        32,32,32,32,112,111,105,110,116,101,114,100,111,119,110,40,101,118,41,123,10,32,32,32,32,32,32,116,104,105,115,46,99,118,46,102,111,99,117,115,40,41,59,10,32,32,32,32,32,32,105,102,40,116,104,105,
        115,46,101,110,97,98,108,101,41,32,123,10,32,32,32,32,32,32,32,32,43,43,116,104,105,115,46,112,114,101,115,115,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,108,101,116,32,112,111,105,110,116,
        101,114,109,111,118,101,61,40,101,118,41,61,62,123,10,32,32,32,32,32,32,32,32,105,102,40,33,116,104,105,115,46,101,110,97,98,108,101,41,10,32,32,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,
        10,32,32,32,32,32,32,32,32,108,101,116,32,114,61,116,104,105,115,46,103,101,116,66,111,117,110,100,105,110,103,67,108,105,101,110,116,82,101,99,116,40,41,59,10,32,32,32,32,32,32,32,32,108,101,116,
        32,118,61,91,93,44,112,59,10,32,32,32,32,32,32,32,32,105,102,40,101,118,46,116,111,117,99,104,101,115,41,10,32,32,32,32,32,32,32,32,32,32,112,61,101,118,46,116,97,114,103,101,116,84,111,117,99,104,
        101,115,59,10,32,32,32,32,32,32,32,32,101,108,115,101,32,105,102,40,116,104,105,115,46,112,114,101,115,115,41,10,32,32,32,32,32,32,32,32,32,32,112,61,91,101,118,93,59,10,32,32,32,32,32,32,32,32,
        101,108,115,101,10,32,32,32,32,32,32,32,32,32,32,112,61,91,93,59,10,32,32,32,32,32,32,32,32,105,102,40,112,46,108,101,110,103,116,104,62,48,41,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,
        100,114,97,103,61,49,59,10,32,32,32,32,32,32,32,32,102,111,114,40,108,101,116,32,105,61,48,59,105,60,112,46,108,101,110,103,116,104,59,43,43,105,41,32,123,10,32,32,32,32,32,32,32,32,32,32,108,101,
        116,32,112,120,61,112,91,105,93,46,99,108,105,101,110,116,88,45,114,46,108,101,102,116,59,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,112,121,61,112,91,105,93,46,99,108,105,101,110,116,89,45,
        114,46,116,111,112,59,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,120,44,107,44,107,111,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,112,121,62,61,48,38,38,112,121,60,116,104,105,115,46,104,
        101,105,103,104,116,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,112,121,60,116,104,105,115,46,98,104,101,105,103,104,116,41,32,123,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,120,61,
        112,120,45,116,104,105,115,46,119,119,105,100,116,104,42,116,104,105,115,46,107,111,91,116,104,105,115,46,109,105,110,37,49,50,93,59,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,107,61,116,104,105,
        115,46,109,105,110,43,40,40,120,47,116,104,105,115,46,98,119,105,100,116,104,41,124,48,41,59,10,32,32,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,32,32,32,32,101,108,115,101,32,
        123,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,107,61,40,112,120,47,116,104,105,115,46,119,119,105,100,116,104,41,124,48,59,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,107,111,61,116,104,105,
        115,46,107,112,91,116,104,105,115,46,109,105,110,37,49,50,93,59,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,107,43,61,107,111,59,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,107,61,116,104,105,
        115,46,109,105,110,43,40,40,107,47,55,41,124,48,41,42,49,50,43,116,104,105,115,46,107,110,91,107,37,55,93,45,116,104,105,115,46,107,110,91,107,111,37,55,93,59,10,32,32,32,32,32,32,32,32,32,32,32,
        32,125,10,32,32,32,32,32,32,32,32,32,32,32,32,105,102,40,107,62,61,116,104,105,115,46,109,105,110,38,38,107,60,61,116,104,105,115,46,109,97,120,41,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,118,
        46,112,117,115,104,40,107,41,59,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,118,46,115,111,114,116,40,41,59,10,32,32,32,32,32,32,32,32,116,104,
        105,115,46,118,97,108,117,101,115,61,118,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,110,100,101,118,101,110,116,40,41,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,
        97,119,40,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,108,101,116,32,112,111,105,110,116,101,114,117,112,61,40,101,118,41,61,62,123,10,32,32,32,32,32,32,32,32,
        105,102,40,116,104,105,115,46,101,110,97,98,108,101,41,32,123,10,32,32,32,32,32,32,32,32,32,32,105,102,40,101,118,46,116,111,117,99,104,101,115,41,10,32,32,32,32,32,32,32,32,32,32,32,32,116,104,
        105,115,46,112,114,101,115,115,61,101,118,46,116,111,117,99,104,101,115,46,108,101,110,103,116,104,59,10,32,32,32,32,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,32,32,32,32,116,
        104,105,115,46,112,114,101,115,115,61,48,59,10,32,32,32,32,32,32,32,32,32,32,112,111,105,110,116,101,114,109,111,118,101,40,101,118,41,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,
        101,110,100,101,118,101,110,116,40,41,59,10,32,32,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,112,114,101,115,115,61,61,48,41,123,10,32,32,32,32,32,32,32,32,32,32,32,32,119,105,110,100,
        111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,109,111,118,101,39,44,32,112,111,105,110,116,101,114,109,111,118,101,41,59,10,32,32,
        32,32,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,109,111,118,101,39,44,32,112,111,105,110,
        116,101,114,109,111,118,101,44,32,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,
        101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,117,112,39,44,32,112,111,105,110,116,101,114,117,112,41,59,10,32,32,32,32,32,32,32,32,32,32,32,32,119,105,110,100,111,119,46,
        114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,101,110,100,39,44,32,112,111,105,110,116,101,114,117,112,41,59,10,32,32,32,32,32,32,32,32,32,32,
        32,32,119,105,110,100,111,119,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,99,97,110,99,101,108,39,44,32,112,111,105,110,116,101,114,117,
        112,41,59,10,32,32,32,32,32,32,32,32,32,32,32,32,100,111,99,117,109,101,110,116,46,98,111,100,121,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,
        104,115,116,97,114,116,39,44,32,112,114,101,118,101,110,116,83,99,114,111,108,108,44,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,32,32,32,32,125,10,32,32,
        32,32,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,97,119,40,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,32,32,116,104,105,115,46,100,114,97,103,61,48,59,10,32,32,32,32,32,
        32,32,32,101,118,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,108,101,116,32,112,114,101,118,101,110,116,83,99,114,111,108,108,
        61,40,101,118,41,61,62,123,10,32,32,32,32,32,32,32,32,101,118,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,119,105,110,100,111,
        119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,109,111,118,101,39,44,32,112,111,105,110,116,101,114,109,111,118,101,41,59,10,32,32,32,32,32,32,119,
        105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,109,111,118,101,39,44,32,112,111,105,110,116,101,114,109,111,118,101,44,32,123,112,97,
        115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,109,111,117,115,101,117,112,
        39,44,32,112,111,105,110,116,101,114,117,112,41,59,10,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,101,110,100,
        39,44,32,112,111,105,110,116,101,114,117,112,41,59,10,32,32,32,32,32,32,119,105,110,100,111,119,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,39,116,111,117,99,104,99,97,110,
        99,101,108,39,44,32,112,111,105,110,116,101,114,117,112,41,59,10,32,32,32,32,32,32,100,111,99,117,109,101,110,116,46,98,111,100,121,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,
        40,39,116,111,117,99,104,115,116,97,114,116,39,44,32,112,114,101,118,101,110,116,83,99,114,111,108,108,44,123,112,97,115,115,105,118,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,112,
        111,105,110,116,101,114,109,111,118,101,40,101,118,41,59,10,32,32,32,32,32,32,101,118,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,59,10,32,32,32,32,32,32,101,118,46,115,116,111,
        112,80,114,111,112,97,103,97,116,105,111,110,40,41,59,10,32,32,32,32,125,10,32,32,32,32,115,101,110,100,69,118,101,110,116,70,114,111,109,75,101,121,40,115,44,107,41,123,10,32,32,32,32,32,32,105,
        102,32,40,116,104,105,115,46,100,105,115,97,98,108,101,100,118,97,108,117,101,115,46,105,110,99,108,117,100,101,115,40,107,41,41,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,108,101,116,32,
        101,118,32,61,32,110,101,119,32,69,118,101,110,116,40,34,99,104,97,110,103,101,34,44,32,123,98,117,98,98,108,101,115,58,111,112,116,46,98,117,98,98,108,101,115,63,116,114,117,101,58,102,97,108,115,
        101,44,32,99,97,110,99,101,108,97,98,108,101,58,111,112,116,46,99,97,110,99,101,108,97,98,108,101,63,116,114,117,101,58,102,97,108,115,101,125,41,59,10,32,32,32,32,32,32,101,118,46,110,111,116,101,
        61,91,115,44,107,93,59,10,32,32,32,32,32,32,116,104,105,115,46,100,105,115,112,97,116,99,104,69,118,101,110,116,40,101,118,41,59,10,32,32,32,32,125,10,32,32,32,32,115,101,110,100,101,118,101,110,
        116,40,41,123,10,32,32,32,32,32,32,108,101,116,32,110,111,116,101,115,61,91,93,59,10,32,32,32,32,32,32,102,111,114,40,108,101,116,32,105,61,48,44,106,61,116,104,105,115,46,118,97,108,117,101,115,
        111,108,100,46,108,101,110,103,116,104,59,105,60,106,59,43,43,105,41,32,123,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,118,97,108,117,101,115,46,105,110,100,101,120,79,102,40,116,104,
        105,115,46,118,97,108,117,101,115,111,108,100,91,105,93,41,60,48,41,10,32,32,32,32,32,32,32,32,32,32,110,111,116,101,115,46,112,117,115,104,40,91,48,44,116,104,105,115,46,118,97,108,117,101,115,
        111,108,100,91,105,93,93,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,102,111,114,40,108,101,116,32,105,61,48,44,106,61,116,104,105,115,46,118,97,108,117,101,115,46,108,101,110,103,116,104,
        59,105,60,106,59,43,43,105,41,32,123,10,32,32,32,32,32,32,32,32,105,102,40,116,104,105,115,46,118,97,108,117,101,115,111,108,100,46,105,110,100,101,120,79,102,40,116,104,105,115,46,118,97,108,117,
        101,115,91,105,93,41,60,48,41,10,32,32,32,32,32,32,32,32,32,32,110,111,116,101,115,46,112,117,115,104,40,91,49,44,116,104,105,115,46,118,97,108,117,101,115,91,105,93,93,41,59,10,32,32,32,32,32,32,
        125,10,32,32,32,32,32,32,105,102,40,110,111,116,101,115,46,108,101,110,103,116,104,41,32,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,118,97,108,117,101,115,111,108,100,61,116,104,105,115,46,
        118,97,108,117,101,115,59,10,32,32,32,32,32,32,32,32,102,111,114,40,108,101,116,32,105,61,48,59,105,60,110,111,116,101,115,46,108,101,110,103,116,104,59,43,43,105,41,32,123,10,32,32,32,32,32,32,
        32,32,32,32,105,102,32,40,116,104,105,115,46,100,105,115,97,98,108,101,100,118,97,108,117,101,115,46,105,110,99,108,117,100,101,115,40,110,111,116,101,115,91,105,93,91,49,93,41,41,32,114,101,116,
        117,114,110,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,100,105,115,112,118,97,108,117,101,115,40,110,111,116,101,115,91,105,93,91,48,93,44,110,111,116,101,115,91,105,93,91,
        49,93,41,59,10,32,32,32,32,32,32,32,32,32,32,108,101,116,32,101,118,32,61,32,110,101,119,32,69,118,101,110,116,40,34,99,104,97,110,103,101,34,44,32,123,98,117,98,98,108,101,115,58,111,112,116,46,
        98,117,98,98,108,101,115,63,116,114,117,101,58,102,97,108,115,101,44,32,99,97,110,99,101,108,97,98,108,101,58,111,112,116,46,99,97,110,99,101,108,97,98,108,101,63,116,114,117,101,58,102,97,108,115,
        101,125,41,59,10,32,32,32,32,32,32,32,32,32,32,101,118,46,110,111,116,101,61,110,111,116,101,115,91,105,93,59,10,32,32,32,32,32,32,32,32,32,32,116,104,105,115,46,100,105,115,112,97,116,99,104,69,
        118,101,110,116,40,101,118,41,59,10,32,32,32,32,32,32,32,32,125,10,32,32,32,32,32,32,125,10,32,32,32,32,125,10,32,32,32,32,115,101,116,68,105,115,97,98,108,101,100,82,97,110,103,101,40,115,116,97,
        116,101,44,115,116,97,114,116,44,101,110,100,41,32,123,10,32,32,32,32,32,32,102,111,114,32,40,118,97,114,32,105,61,115,116,97,114,116,59,32,105,60,101,110,100,59,105,43,43,41,32,123,10,32,32,32,
        32,32,32,32,32,116,104,105,115,46,115,101,116,100,105,115,97,98,108,101,100,118,97,108,117,101,115,40,115,116,97,116,101,44,105,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,116,104,105,115,
        46,114,101,100,114,97,119,40,41,59,10,32,32,32,32,125,10,32,32,32,32,115,101,116,100,105,115,97,98,108,101,100,118,97,108,117,101,115,40,115,116,97,116,101,44,110,111,116,101,41,32,123,10,32,32,
        32,32,32,32,108,101,116,32,110,61,116,104,105,115,46,100,105,115,97,98,108,101,100,118,97,108,117,101,115,46,105,110,100,101,120,79,102,40,110,111,116,101,41,59,10,32,32,32,32,32,32,105,102,40,115,
        116,97,116,101,41,32,123,10,32,32,32,32,32,32,32,32,105,102,40,110,60,48,41,32,116,104,105,115,46,100,105,115,97,98,108,101,100,118,97,108,117,101,115,46,112,117,115,104,40,110,111,116,101,41,59,
        10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,101,32,123,10,32,32,32,32,32,32,32,32,105,102,40,110,62,61,48,41,32,116,104,105,115,46,100,105,115,97,98,108,101,100,118,97,108,117,101,
        115,46,115,112,108,105,99,101,40,110,44,49,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,125,10,32,32,32,32,115,101,116,100,105,115,112,118,97,108,117,101,115,40,115,116,97,116,101,44,110,111,116,
        101,41,32,123,10,32,32,32,32,32,32,108,101,116,32,110,61,116,104,105,115,46,100,105,115,112,118,97,108,117,101,115,46,105,110,100,101,120,79,102,40,110,111,116,101,41,59,10,32,32,32,32,32,32,105,
        102,40,115,116,97,116,101,41,32,123,10,32,32,32,32,32,32,32,32,105,102,40,110,60,48,41,32,116,104,105,115,46,100,105,115,112,118,97,108,117,101,115,46,112,117,115,104,40,110,111,116,101,41,59,10,
        32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,101,32,123,10,32,32,32,32,32,32,32,32,105,102,40,110,62,61,48,41,32,116,104,105,115,46,100,105,115,112,118,97,108,117,101,115,46,115,112,108,
        105,99,101,40,110,44,49,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,125,10,32,32,32,32,115,101,116,78,111,116,101,40,115,116,97,116,101,44,110,111,116,101,44,97,99,116,120,44,119,104,101,110,41,
        32,123,10,32,32,32,32,32,32,99,111,110,115,116,32,116,61,40,97,99,116,120,38,38,119,104,101,110,45,97,99,116,120,46,99,117,114,114,101,110,116,84,105,109,101,41,59,10,32,32,32,32,32,32,105,102,40,
        116,62,48,41,123,10,32,32,32,32,32,32,32,32,115,101,116,84,105,109,101,111,117,116,40,40,41,61,62,123,116,104,105,115,46,115,101,116,78,111,116,101,40,115,116,97,116,101,44,110,111,116,101,41,125,
        44,116,42,49,48,48,48,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,101,108,115,101,123,10,32,32,32,32,32,32,32,32,116,104,105,115,46,115,101,116,100,105,115,112,118,97,108,117,101,115,40,
        115,116,97,116,101,44,110,111,116,101,41,59,10,32,32,32,32,32,32,32,32,116,104,105,115,46,114,101,100,114,97,119,40,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,125,32,32,125,41,59,10,125,32,99,
        97,116,99,104,40,101,114,114,111,114,41,123,10,32,32,99,111,110,115,111,108,101,46,108,111,103,40,34,119,101,98,97,117,100,105,111,45,107,101,121,98,111,97,114,100,32,97,108,114,101,97,100,121,32,
        100,101,102,105,110,101,100,34,41,59,10,125,10,10,32,32,99,108,97,115,115,32,87,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,32,123,10,
        32,32,32,32,99,111,110,115,116,114,117,99,116,111,114,40,41,123,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,65,99,99,101,115,115,32,61,32,110,117,108,108,59,10,32,32,32,32,32,32,116,
        104,105,115,46,108,105,115,116,79,102,87,105,100,103,101,116,115,32,61,32,91,93,59,10,32,32,32,32,32,32,116,104,105,115,46,108,105,115,116,79,102,69,120,116,101,114,110,97,108,77,105,100,105,76,
        105,115,116,101,110,101,114,115,32,61,32,91,93,59,10,32,32,32,32,32,32,116,104,105,115,46,117,112,100,97,116,101,87,105,100,103,101,116,115,40,41,59,10,32,32,32,32,32,32,105,102,40,111,112,116,46,
        112,114,101,115,101,114,118,101,77,105,100,105,76,101,97,114,110,41,10,32,32,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,76,101,97,114,110,84,97,98,108,101,61,74,83,79,78,46,112,97,114,
        115,101,40,108,111,99,97,108,83,116,111,114,97,103,101,46,103,101,116,73,116,101,109,40,34,87,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,77,105,100,105,76,101,97,114,110,34,41,41,59,
        10,32,32,32,32,32,32,101,108,115,101,10,32,32,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,76,101,97,114,110,84,97,98,108,101,61,110,117,108,108,59,10,32,32,32,32,32,32,116,104,105,115,46,
        105,110,105,116,87,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,40,41,59,10,32,32,32,32,125,10,32,32,32,32,97,100,100,87,105,100,103,101,116,40,119,41,123,10,32,32,32,32,32,32,116,104,
        105,115,46,108,105,115,116,79,102,87,105,100,103,101,116,115,46,112,117,115,104,40,119,41,59,10,32,32,32,32,125,10,32,32,32,32,117,112,100,97,116,101,87,105,100,103,101,116,115,40,41,123,10,47,47,
        32,32,32,32,32,32,116,104,105,115,46,108,105,115,116,79,102,87,105,100,103,101,116,115,32,61,32,100,111,99,117,109,101,110,116,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,
        34,119,101,98,97,117,100,105,111,45,107,110,111,98,44,119,101,98,97,117,100,105,111,45,115,108,105,100,101,114,44,119,101,98,97,117,100,105,111,45,115,119,105,116,99,104,34,41,59,10,32,32,32,32,
        125,10,32,32,32,32,105,110,105,116,87,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,40,41,32,123,10,32,32,32,32,32,32,105,102,40,110,97,118,105,103,97,116,111,114,46,114,101,113,117,101,
        115,116,77,73,68,73,65,99,99,101,115,115,41,32,123,10,32,32,32,32,32,32,32,32,110,97,118,105,103,97,116,111,114,46,114,101,113,117,101,115,116,77,73,68,73,65,99,99,101,115,115,40,41,46,116,104,101,
        110,40,10,32,32,32,32,32,32,32,32,32,32,40,109,97,41,61,62,123,116,104,105,115,46,109,105,100,105,65,99,99,101,115,115,32,61,32,109,97,44,116,104,105,115,46,101,110,97,98,108,101,73,110,112,117,
        116,115,40,41,125,44,10,32,32,32,32,32,32,32,32,32,32,40,101,114,114,41,61,62,123,32,99,111,110,115,111,108,101,46,108,111,103,40,34,77,73,68,73,32,110,111,116,32,105,110,105,116,105,97,108,105,
        122,101,100,32,45,32,101,114,114,111,114,32,101,110,99,111,117,110,116,101,114,101,100,58,34,32,43,32,101,114,114,46,99,111,100,101,41,125,10,32,32,32,32,32,32,32,32,41,59,10,32,32,32,32,32,32,125,
        10,32,32,32,32,125,10,32,32,32,32,101,110,97,98,108,101,73,110,112,117,116,115,40,41,32,123,10,32,32,32,32,32,32,108,101,116,32,105,110,112,117,116,115,32,61,32,116,104,105,115,46,109,105,100,105,
        65,99,99,101,115,115,46,105,110,112,117,116,115,46,118,97,108,117,101,115,40,41,59,10,32,32,32,32,32,32,99,111,110,115,111,108,101,46,108,111,103,40,34,70,111,117,110,100,32,34,32,43,32,116,104,
        105,115,46,109,105,100,105,65,99,99,101,115,115,46,105,110,112,117,116,115,46,115,105,122,101,32,43,32,34,32,77,73,68,73,32,105,110,112,117,116,40,115,41,34,41,59,10,32,32,32,32,32,32,102,111,114,
        40,108,101,116,32,105,110,112,117,116,32,61,32,105,110,112,117,116,115,46,110,101,120,116,40,41,59,32,105,110,112,117,116,32,38,38,32,33,105,110,112,117,116,46,100,111,110,101,59,32,105,110,112,
        117,116,32,61,32,105,110,112,117,116,115,46,110,101,120,116,40,41,41,32,123,10,32,32,32,32,32,32,32,32,99,111,110,115,111,108,101,46,108,111,103,40,34,67,111,110,110,101,99,116,101,100,32,105,110,
        112,117,116,58,32,34,32,43,32,105,110,112,117,116,46,118,97,108,117,101,46,110,97,109,101,41,59,10,32,32,32,32,32,32,32,32,105,110,112,117,116,46,118,97,108,117,101,46,111,110,109,105,100,105,109,
        101,115,115,97,103,101,32,61,32,116,104,105,115,46,104,97,110,100,108,101,77,73,68,73,77,101,115,115,97,103,101,46,98,105,110,100,40,116,104,105,115,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,
        125,10,32,32,32,32,109,105,100,105,67,111,110,110,101,99,116,105,111,110,83,116,97,116,101,67,104,97,110,103,101,40,101,41,32,123,10,32,32,32,32,32,32,99,111,110,115,111,108,101,46,108,111,103,40,
        34,99,111,110,110,101,99,116,105,111,110,58,32,34,32,43,32,101,46,112,111,114,116,46,110,97,109,101,32,43,32,34,32,34,32,43,32,101,46,112,111,114,116,46,99,111,110,110,101,99,116,105,111,110,32,
        43,32,34,32,34,32,43,32,101,46,112,111,114,116,46,115,116,97,116,101,41,59,10,32,32,32,32,32,32,101,110,97,98,108,101,73,110,112,117,116,115,40,41,59,10,32,32,32,32,125,10,10,32,32,32,32,111,110,
        77,73,68,73,83,116,97,114,116,101,100,40,109,105,100,105,41,32,123,10,32,32,32,32,32,32,116,104,105,115,46,109,105,100,105,65,99,99,101,115,115,32,61,32,109,105,100,105,59,10,32,32,32,32,32,32,109,
        105,100,105,46,111,110,115,116,97,116,101,99,104,97,110,103,101,32,61,32,116,104,105,115,46,109,105,100,105,67,111,110,110,101,99,116,105,111,110,83,116,97,116,101,67,104,97,110,103,101,59,10,32,
        32,32,32,32,32,101,110,97,98,108,101,73,110,112,117,116,115,40,109,105,100,105,41,59,10,32,32,32,32,125,10,32,32,32,32,47,47,32,65,100,100,32,104,111,111,107,115,32,102,111,114,32,101,120,116,101,
        114,110,97,108,32,109,105,100,105,32,108,105,115,116,101,110,101,114,115,32,115,117,112,112,111,114,116,10,32,32,32,32,97,100,100,77,105,100,105,76,105,115,116,101,110,101,114,40,99,97,108,108,98,
        97,99,107,41,32,123,10,32,32,32,32,32,32,116,104,105,115,46,108,105,115,116,79,102,69,120,116,101,114,110,97,108,77,105,100,105,76,105,115,116,101,110,101,114,115,46,112,117,115,104,40,99,97,108,
        108,98,97,99,107,41,59,10,32,32,32,32,125,10,32,32,32,32,103,101,116,67,117,114,114,101,110,116,67,111,110,102,105,103,65,115,74,83,79,78,40,41,32,123,10,32,32,32,32,32,32,114,101,116,117,114,110,
        32,99,117,114,114,101,110,116,67,111,110,102,105,103,46,115,116,114,105,110,103,105,102,121,40,41,59,10,32,32,32,32,125,10,32,32,32,32,104,97,110,100,108,101,77,73,68,73,77,101,115,115,97,103,101,
        40,101,118,101,110,116,41,32,123,10,32,32,32,32,32,32,116,104,105,115,46,108,105,115,116,79,102,69,120,116,101,114,110,97,108,77,105,100,105,76,105,115,116,101,110,101,114,115,46,102,111,114,69,
        97,99,104,40,102,117,110,99,116,105,111,110,32,40,101,120,116,101,114,110,97,108,76,105,115,116,101,110,101,114,41,32,123,10,32,32,32,32,32,32,32,32,101,120,116,101,114,110,97,108,76,105,115,116,
        101,110,101,114,40,101,118,101,110,116,41,59,10,32,32,32,32,32,32,125,41,59,10,32,32,32,32,32,32,105,102,40,40,40,101,118,101,110,116,46,100,97,116,97,91,48,93,32,38,32,48,120,102,48,41,32,61,61,
        32,48,120,102,48,41,32,124,124,32,40,40,101,118,101,110,116,46,100,97,116,97,91,48,93,32,38,32,48,120,102,48,41,32,61,61,32,48,120,98,48,32,38,38,32,101,118,101,110,116,46,100,97,116,97,91,49,93,
        32,62,61,32,49,50,48,41,41,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,102,111,114,40,108,101,116,32,119,32,111,102,32,116,104,105,115,46,108,105,115,116,79,102,87,
        105,100,103,101,116,115,41,32,123,10,32,32,32,32,32,32,32,32,105,102,40,119,46,112,114,111,99,101,115,115,77,105,100,105,69,118,101,110,116,41,10,32,32,32,32,32,32,32,32,32,32,119,46,112,114,111,
        99,101,115,115,77,105,100,105,69,118,101,110,116,40,101,118,101,110,116,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,105,102,40,111,112,116,46,109,105,100,105,100,117,109,112,41,10,32,32,
        32,32,32,32,32,32,99,111,110,115,111,108,101,46,108,111,103,40,101,118,101,110,116,46,100,97,116,97,41,59,10,32,32,32,32,125,10,32,32,32,32,99,111,110,116,101,120,116,77,101,110,117,79,112,101,110,
        40,101,44,107,110,111,98,41,123,10,32,32,32,32,32,32,105,102,40,33,116,104,105,115,46,109,105,100,105,65,99,99,101,115,115,41,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,
        32,32,108,101,116,32,109,101,110,117,61,100,111,99,117,109,101,110,116,46,103,101,116,69,108,101,109,101,110,116,66,121,73,100,40,34,119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,
        101,120,116,45,109,101,110,117,34,41,59,10,32,32,32,32,32,32,109,101,110,117,46,115,116,121,108,101,46,108,101,102,116,61,101,46,112,97,103,101,88,43,34,112,120,34,59,10,32,32,32,32,32,32,109,101,
        110,117,46,115,116,121,108,101,46,116,111,112,61,101,46,112,97,103,101,89,43,34,112,120,34,59,10,32,32,32,32,32,32,109,101,110,117,46,107,110,111,98,61,107,110,111,98,59,10,32,32,32,32,32,32,109,
        101,110,117,46,99,108,97,115,115,76,105,115,116,46,97,100,100,40,34,97,99,116,105,118,101,34,41,59,10,32,32,32,32,32,32,109,101,110,117,46,107,110,111,98,46,102,111,99,117,115,40,41,59,10,32,32,
        32,32,32,32,109,101,110,117,46,107,110,111,98,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,107,101,121,100,111,119,110,34,44,116,104,105,115,46,99,111,110,116,101,120,116,
        77,101,110,117,67,108,111,115,101,66,121,75,101,121,46,98,105,110,100,40,116,104,105,115,41,41,59,10,32,32,32,32,125,10,32,32,32,32,99,111,110,116,101,120,116,77,101,110,117,67,108,111,115,101,66,
        121,75,101,121,40,101,41,123,10,32,32,32,32,32,32,105,102,40,101,46,107,101,121,67,111,100,101,61,61,50,55,41,10,32,32,32,32,32,32,32,116,104,105,115,46,99,111,110,116,101,120,116,77,101,110,117,
        67,108,111,115,101,40,41,59,10,32,32,32,32,125,10,32,32,32,32,99,111,110,116,101,120,116,77,101,110,117,67,108,111,115,101,40,41,123,10,32,32,32,32,32,32,108,101,116,32,109,101,110,117,61,100,111,
        99,117,109,101,110,116,46,103,101,116,69,108,101,109,101,110,116,66,121,73,100,40,34,119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,34,41,59,10,32,
        32,32,32,32,32,109,101,110,117,46,107,110,111,98,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,107,101,121,100,111,119,110,34,44,116,104,105,115,46,99,111,110,
        116,101,120,116,77,101,110,117,67,108,111,115,101,66,121,75,101,121,41,59,10,32,32,32,32,32,32,109,101,110,117,46,99,108,97,115,115,76,105,115,116,46,114,101,109,111,118,101,40,34,97,99,116,105,
        118,101,34,41,59,10,32,32,32,32,32,32,108,101,116,32,109,101,110,117,73,116,101,109,76,101,97,114,110,61,100,111,99,117,109,101,110,116,46,103,101,116,69,108,101,109,101,110,116,66,121,73,100,40,
        34,119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,45,108,101,97,114,110,34,41,59,10,32,32,32,32,32,32,109,101,110,117,73,116,101,109,76,101,97,114,
        110,46,105,110,110,101,114,72,84,77,76,32,61,32,39,76,101,97,114,110,39,59,10,32,32,32,32,32,32,109,101,110,117,46,107,110,111,98,46,109,105,100,105,77,111,100,101,32,61,32,39,110,111,114,109,97,
        108,39,59,10,32,32,32,32,125,10,32,32,32,32,99,111,110,116,101,120,116,77,101,110,117,76,101,97,114,110,40,41,123,10,32,32,32,32,32,32,108,101,116,32,109,101,110,117,61,100,111,99,117,109,101,110,
        116,46,103,101,116,69,108,101,109,101,110,116,66,121,73,100,40,34,119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,34,41,59,10,32,32,32,32,32,32,108,
        101,116,32,109,101,110,117,73,116,101,109,76,101,97,114,110,61,100,111,99,117,109,101,110,116,46,103,101,116,69,108,101,109,101,110,116,66,121,73,100,40,34,119,101,98,97,117,100,105,111,99,116,114,
        108,45,99,111,110,116,101,120,116,45,109,101,110,117,45,108,101,97,114,110,34,41,59,10,32,32,32,32,32,32,109,101,110,117,73,116,101,109,76,101,97,114,110,46,105,110,110,101,114,72,84,77,76,32,61,
        32,39,76,105,115,116,101,110,105,110,103,46,46,46,39,59,10,32,32,32,32,32,32,109,101,110,117,46,107,110,111,98,46,109,105,100,105,77,111,100,101,32,61,32,39,108,101,97,114,110,39,59,10,32,32,32,
        32,125,10,32,32,32,32,99,111,110,116,101,120,116,77,101,110,117,67,108,101,97,114,40,101,41,123,10,32,32,32,32,32,32,108,101,116,32,109,101,110,117,61,100,111,99,117,109,101,110,116,46,103,101,116,
        69,108,101,109,101,110,116,66,121,73,100,40,34,119,101,98,97,117,100,105,111,99,116,114,108,45,99,111,110,116,101,120,116,45,109,101,110,117,34,41,59,10,32,32,32,32,32,32,109,101,110,117,46,107,
        110,111,98,46,109,105,100,105,67,111,110,116,114,111,108,108,101,114,61,123,125,59,10,32,32,32,32,32,32,116,104,105,115,46,99,111,110,116,101,120,116,77,101,110,117,67,108,111,115,101,40,41,59,10,
        32,32,32,32,125,10,32,32,32,32,112,114,101,115,101,114,118,101,77,105,100,105,76,101,97,114,110,40,41,123,10,32,32,32,32,32,32,105,102,40,33,111,112,116,46,112,114,101,115,101,114,118,101,77,105,
        100,105,76,101,97,114,110,41,10,32,32,32,32,32,32,32,32,114,101,116,117,114,110,59,10,32,32,32,32,32,32,99,111,110,115,116,32,118,61,91,93,59,10,32,32,32,32,32,32,102,111,114,40,108,101,116,32,119,
        32,111,102,32,116,104,105,115,46,108,105,115,116,79,102,87,105,100,103,101,116,115,41,32,123,10,32,32,32,32,32,32,32,32,105,102,40,119,46,105,100,41,10,32,32,32,32,32,32,32,32,32,32,118,46,112,117,
        115,104,40,123,34,105,100,34,58,119,46,105,100,44,32,34,99,99,34,58,119,46,109,105,100,105,67,111,110,116,114,111,108,108,101,114,125,41,59,10,32,32,32,32,32,32,125,10,32,32,32,32,32,32,99,111,110,
        115,116,32,115,61,74,83,79,78,46,115,116,114,105,110,103,105,102,121,40,118,41,59,10,32,32,32,32,32,32,108,111,99,97,108,83,116,111,114,97,103,101,46,115,101,116,73,116,101,109,40,34,87,101,98,65,
        117,100,105,111,67,111,110,116,114,111,108,115,77,105,100,105,76,101,97,114,110,34,44,115,41,59,10,32,32,32,32,125,10,32,32,125,10,32,32,105,102,40,119,105,110,100,111,119,46,85,115,101,87,101,98,
        65,117,100,105,111,67,111,110,116,114,111,108,115,77,105,100,105,124,124,111,112,116,46,117,115,101,77,105,100,105,41,10,32,32,32,32,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,
        110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,32,61,32,119,105,110,100,111,119,46,119,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,77,105,100,105,77,97,110,
        97,103,101,114,32,61,32,110,101,119,32,87,101,98,65,117,100,105,111,67,111,110,116,114,111,108,115,87,105,100,103,101,116,77,97,110,97,103,101,114,40,41,59,10,125,10, 0 };



    static constexpr std::array files =
    {
        File { "cmaj_api/cmaj-audio-worklet-helper.js", std::string_view (cmaj_api_cmajaudioworklethelper_js, 28203) },
        File { "delaygrain.cmajorpatch", std::string_view (delaygrain_cmajorpatch, 371) },
        File { "cmaj_api/assets/cmajor-logo.svg", std::string_view (cmaj_api_assets_cmajorlogo_svg, 2913) },
        File { "cmaj_api/cmaj-event-listener-list.js", std::string_view (cmaj_api_cmajeventlistenerlist_js, 3474) },
        File { "cmaj_api/cmaj-generic-patch-view.js", std::string_view (cmaj_api_cmajgenericpatchview_js, 6912) },
        File { "cmaj_api/cmaj-midi-helpers.js", std::string_view (cmaj_api_cmajmidihelpers_js, 13253) },
        File { "cmaj_api/cmaj-parameter-controls.js", std::string_view (cmaj_api_cmajparametercontrols_js, 30756) },
        File { "cmaj_api/cmaj-patch-connection.js", std::string_view (cmaj_api_cmajpatchconnection_js, 13131) },
        File { "cmaj_api/cmaj-patch-view.js", std::string_view (cmaj_api_cmajpatchview_js, 7388) },
        File { "cmaj_api/cmaj-piano-keyboard.js", std::string_view (cmaj_api_cmajpianokeyboard_js, 15557) },
        File { "cmaj_api/cmaj-server-session.js", std::string_view (cmaj_api_cmajserversession_js, 18553) },
        File { "view/LICENSE", std::string_view (view_LICENSE, 10273) },
        File { "view/Middle_Potion.png", std::string_view (view_Middle_Potion_png, 9548) },
        File { "view/Sky_Blue_Bevel.png", std::string_view (view_Sky_Blue_Bevel_png, 15179) },
        File { "view/index.js", std::string_view (view_index_js, 7302) },
        File { "view/webaudio-controls.js", std::string_view (view_webaudiocontrols_js, 72769) }
    };

};



juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new cmaj::plugin::GeneratedPlugin<::SmoothRandomDelayFilter> (std::make_shared<cmaj::Patch>());
}
