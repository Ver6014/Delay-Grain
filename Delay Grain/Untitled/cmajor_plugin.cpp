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
                "        \"name\": \"Max Delay\",\n"
                "        \"min\": 0.0,\n"
                "        \"max\": 0.25,\n"
                "        \"init\": 0.25\n"
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
                "        \"init\": 0.4\n"
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
                "        \"init\": 0.5\n"
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
                "        \"init\": 0.5\n"
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
                "        \"init\": 0.0\n"
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
        "  \"version\": \"4.0\",\n"
        "  \"name\": \"Delay Grain\",\n"
        "  \"description\": \"Delay grain effect\",\n"
        "  \"manufacturer\": \"Victor Schulhoff\",\n"
        "  \"category\": \"effect\",\n"
        "  \"isInstrument\": false,\n"
        "  \"source\": \"DelayGrain.cmajor\",\n"
        "  \"view\": {\n"
        "    \"src\": \"view/index.js\",\n"
        "    \"width\": 400,\n"
        "    \"height\": 400,\n"
        "    \"resizable\": true\n"
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
    static constexpr const char* view_index_js =
        "class MyView extends HTMLElement\n"
        "{\n"
        "    constructor (patchConnection)\n"
        "    {\n"
        "       super(); \n"
        "       this.patchConnection = patchConnection;\n"
        "       this.innerHTML = this.getHTML();\n"
        "       this.classList.add (\"view-patch-element\");\n"
        "    }\n"
        "\n"
        "    connectedCallback()\n"
        "    {\n"
        "        this.paramListener = event =>\n"
        "        {\n"
        "            const slider = this.querySelector (\"#\" + event.endpointID);\n"
        "\n"
        "            if (slider)\n"
        "            {\n"
        "                slider.value = event.value * 100.0;\n"
        "                this.updateKnob(slider);\n"
        "            }\n"
        "        };\n"
        "\n"
        "        this.patchConnection.addAllParameterListener (this.paramListener);\n"
        "\n"
        "        for (const slider of this.querySelectorAll (\".knob\"))\n"
        "        {\n"
        "            this.patchConnection.requestParameterValue (slider.id);\n"
        "            slider.value = 50; // default\n"
        "            this.createKnob(slider);\n"
        "        }\n"
        "    }\n"
        "\n"
        "    createKnob(knob)\n"
        "    {\n"
        "        const svg = document.createElementNS(\"http://www.w3.org/2000/svg\", \"svg\");\n"
        "        svg.setAttribute(\"width\", \"80\");\n"
        "        svg.setAttribute(\"height\", \"80\");\n"
        "        svg.setAttribute(\"transform\", \"rotate(-90 40 40)\");\n"
        "        const circle = document.createElementNS(\"http://www.w3.org/2000/svg\", \"circle\");\n"
        "        circle.setAttribute(\"cx\", \"40\");\n"
        "        circle.setAttribute(\"cy\", \"40\");\n"
        "        circle.setAttribute(\"r\", \"35\");\n"
        "        circle.setAttribute(\"fill\", \"#ea3b93\");\n"
        "        circle.setAttribute(\"stroke\", \"#000\");\n"
        "        circle.setAttribute(\"stroke-width\", \"2\");\n"
        "        const line = document.createElementNS(\"http://www.w3.org/2000/svg\", \"line\");\n"
        "        line.setAttribute(\"x1\", \"40\");\n"
        "        line.setAttribute(\"y1\", \"40\");\n"
        "        line.setAttribute(\"stroke\", \"#000\");\n"
        "        line.setAttribute(\"stroke-width\", \"3\");\n"
        "        line.setAttribute(\"stroke-linecap\", \"round\");\n"
        "        svg.appendChild(circle);\n"
        "        svg.appendChild(line);\n"
        "        knob.appendChild(svg);\n"
        "        this.updateKnob(knob);\n"
        "\n"
        "        let isDragging = false;\n"
        "        const startDrag = (e) => {\n"
        "            isDragging = true;\n"
        "            updateValue(e);\n"
        "        };\n"
        "        const drag = (e) => {\n"
        "            if (isDragging) updateValue(e);\n"
        "        };\n"
        "        const endDrag = () => {\n"
        "            isDragging = false;\n"
        "        };\n"
        "        const updateValue = (e) => {\n"
        "            const rect = svg.getBoundingClientRect();\n"
        "            const relativeY = e.clientY - rect.top;\n"
        "            const value = Math.max(0, Math.min(100, ((rect.height - relativeY) / rect.height) * 100));\n"
        "            knob.value = value;\n"
        "            this.updateKnob(knob);\n"
        "            this.patchConnection.sendEventOrValue(knob.id, value / 100.0);\n"
        "        };\n"
        "        svg.addEventListener('mousedown', startDrag);\n"
        "        document.addEventListener('mousemove', drag);\n"
        "        document.addEventListener('mouseup', endDrag);\n"
        "    }\n"
        "\n"
        "    updateKnob(knob)\n"
        "    {\n"
        "        const line = knob.querySelector('line');\n"
        "        const angle = (knob.value / 100) * 270 - 225;\n"
        "        const rad = angle * Math.PI / 180;\n"
        "        const x2 = 40 + 25 * Math.cos(rad);\n"
        "        const y2 = 40 + 25 * Math.sin(rad);\n"
        "        line.setAttribute('x2', x2);\n"
        "        line.setAttribute('y2', y2);\n"
        "\n"
        "        const valueId = knob.id.replace('Param', 'Value');\n"
        "        const valueDiv = this.querySelector('#' + valueId);\n"
        "        if (valueDiv) valueDiv.textContent = knob.value.toFixed(0);\n"
        "    }\n"
        "\n"
        "    disconnectedCallback()\n"
        "    {\n"
        "        this.patchConnection.removeAllParameterListener (this.paramListener);\n"
        "    }\n"
        "\n"
        "    getHTML()\n"
        "    {\n"
        "        return `\n"
        "            <link href='https://fonts.googleapis.com/css?family=Coral Pixels' rel='stylesheet'>\n"
        "            <link rel=\"stylesheet\" href=\"view/styles.css\">\n"
        "            \n"
        "            <body>\n"
        "\n"
        "                <h1>Delay Grain</h1>\n"
        "                <p>Made By: Victor Schulhoff</p>\n"
        "                <br>\n"
        "            <div id=\"console\" class=\"console\">\n"
        "                \n"
        "                <p>Max Delay</p>\n"
        "                <div class=\"knob\" id=\"maxDelayParam\"></div>\n"
        "                <div class=\"value-display\" id=\"maxDelayValue\">50</div>\n"
        "                \n"
        "                <p>Feedback</p>\n"
        "                <div class=\"knob\" id=\"feedbackParam\"></div>\n"
        "                <div class=\"value-display\" id=\"feedbackValue\">50</div>\n"
        "               \n"
        "                <p>Mix</p>\n"
        "                <div class=\"knob\" id=\"mixParam\"></div>\n"
        "                <div class=\"value-display\" id=\"mixValue\">50</div>\n"
        "                \n"
        "                <p>Cutoff</p>\n"
        "                <div class=\"knob\" id=\"cutoffParam\"></div>\n"
        "                <div class=\"value-display\" id=\"cutoffValue\">50</div>\n"
        "                \n"
        "               \n"
        "                <p>Resonance</p>\n"
        "                <div class=\"knob\" id=\"resonanceParam\"></div>\n"
        "                <div class=\"value-display\" id=\"resonanceValue\">50</div>\n"
        "               \n"
        "            </div>  \n"
        "\n"
        "            </body>\n"
        "        `;   \n"
        "    }\n"
        "}\n"
        "\n"
        "window.customElements.define (\"my-view\", MyView);\n"
        "\n"
        "export default function createPatchView (patchConnection)\n"
        "{\n"
        "    return new MyView (patchConnection);\n"
        "}\n";
    static constexpr const char view_jquery_min_js[] = {
        47,42,33,32,106,81,117,101,114,121,32,118,51,46,54,46,48,32,124,32,40,99,41,32,79,112,101,110,74,83,32,70,111,117,110,100,97,116,105,111,110,32,97,110,100,32,111,116,104,101,114,32,99,111,110,116,114,105,
        98,117,116,111,114,115,32,124,32,106,113,117,101,114,121,46,111,114,103,47,108,105,99,101,110,115,101,32,42,47,10,33,102,117,110,99,116,105,111,110,40,101,44,116,41,123,34,117,115,101,32,115,116,
        114,105,99,116,34,59,34,111,98,106,101,99,116,34,61,61,116,121,112,101,111,102,32,109,111,100,117,108,101,38,38,34,111,98,106,101,99,116,34,61,61,116,121,112,101,111,102,32,109,111,100,117,108,101,
        46,101,120,112,111,114,116,115,63,109,111,100,117,108,101,46,101,120,112,111,114,116,115,61,101,46,100,111,99,117,109,101,110,116,63,116,40,101,44,33,48,41,58,102,117,110,99,116,105,111,110,40,101,
        41,123,105,102,40,33,101,46,100,111,99,117,109,101,110,116,41,116,104,114,111,119,32,110,101,119,32,69,114,114,111,114,40,34,106,81,117,101,114,121,32,114,101,113,117,105,114,101,115,32,97,32,119,
        105,110,100,111,119,32,119,105,116,104,32,97,32,100,111,99,117,109,101,110,116,34,41,59,114,101,116,117,114,110,32,116,40,101,41,125,58,116,40,101,41,125,40,34,117,110,100,101,102,105,110,101,100,
        34,33,61,116,121,112,101,111,102,32,119,105,110,100,111,119,63,119,105,110,100,111,119,58,116,104,105,115,44,102,117,110,99,116,105,111,110,40,67,44,101,41,123,34,117,115,101,32,115,116,114,105,
        99,116,34,59,118,97,114,32,116,61,91,93,44,114,61,79,98,106,101,99,116,46,103,101,116,80,114,111,116,111,116,121,112,101,79,102,44,115,61,116,46,115,108,105,99,101,44,103,61,116,46,102,108,97,116,
        63,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,116,46,102,108,97,116,46,99,97,108,108,40,101,41,125,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,
        110,32,116,46,99,111,110,99,97,116,46,97,112,112,108,121,40,91,93,44,101,41,125,44,117,61,116,46,112,117,115,104,44,105,61,116,46,105,110,100,101,120,79,102,44,110,61,123,125,44,111,61,110,46,116,
        111,83,116,114,105,110,103,44,118,61,110,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,44,97,61,118,46,116,111,83,116,114,105,110,103,44,108,61,97,46,99,97,108,108,40,79,98,106,101,99,
        116,41,44,121,61,123,125,44,109,61,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,34,102,117,110,99,116,105,111,110,34,61,61,116,121,112,101,111,102,32,101,38,38,34,110,117,
        109,98,101,114,34,33,61,116,121,112,101,111,102,32,101,46,110,111,100,101,84,121,112,101,38,38,34,102,117,110,99,116,105,111,110,34,33,61,116,121,112,101,111,102,32,101,46,105,116,101,109,125,44,
        120,61,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,110,117,108,108,33,61,101,38,38,101,61,61,61,101,46,119,105,110,100,111,119,125,44,69,61,67,46,100,111,99,117,109,101,
        110,116,44,99,61,123,116,121,112,101,58,33,48,44,115,114,99,58,33,48,44,110,111,110,99,101,58,33,48,44,110,111,77,111,100,117,108,101,58,33,48,125,59,102,117,110,99,116,105,111,110,32,98,40,101,
        44,116,44,110,41,123,118,97,114,32,114,44,105,44,111,61,40,110,61,110,124,124,69,41,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,115,99,114,105,112,116,34,41,59,105,102,40,111,46,116,
        101,120,116,61,101,44,116,41,102,111,114,40,114,32,105,110,32,99,41,40,105,61,116,91,114,93,124,124,116,46,103,101,116,65,116,116,114,105,98,117,116,101,38,38,116,46,103,101,116,65,116,116,114,105,
        98,117,116,101,40,114,41,41,38,38,111,46,115,101,116,65,116,116,114,105,98,117,116,101,40,114,44,105,41,59,110,46,104,101,97,100,46,97,112,112,101,110,100,67,104,105,108,100,40,111,41,46,112,97,
        114,101,110,116,78,111,100,101,46,114,101,109,111,118,101,67,104,105,108,100,40,111,41,125,102,117,110,99,116,105,111,110,32,119,40,101,41,123,114,101,116,117,114,110,32,110,117,108,108,61,61,101,
        63,101,43,34,34,58,34,111,98,106,101,99,116,34,61,61,116,121,112,101,111,102,32,101,124,124,34,102,117,110,99,116,105,111,110,34,61,61,116,121,112,101,111,102,32,101,63,110,91,111,46,99,97,108,108,
        40,101,41,93,124,124,34,111,98,106,101,99,116,34,58,116,121,112,101,111,102,32,101,125,118,97,114,32,102,61,34,51,46,54,46,48,34,44,83,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,
        101,116,117,114,110,32,110,101,119,32,83,46,102,110,46,105,110,105,116,40,101,44,116,41,125,59,102,117,110,99,116,105,111,110,32,112,40,101,41,123,118,97,114,32,116,61,33,33,101,38,38,34,108,101,
        110,103,116,104,34,105,110,32,101,38,38,101,46,108,101,110,103,116,104,44,110,61,119,40,101,41,59,114,101,116,117,114,110,33,109,40,101,41,38,38,33,120,40,101,41,38,38,40,34,97,114,114,97,121,34,
        61,61,61,110,124,124,48,61,61,61,116,124,124,34,110,117,109,98,101,114,34,61,61,116,121,112,101,111,102,32,116,38,38,48,60,116,38,38,116,45,49,32,105,110,32,101,41,125,83,46,102,110,61,83,46,112,
        114,111,116,111,116,121,112,101,61,123,106,113,117,101,114,121,58,102,44,99,111,110,115,116,114,117,99,116,111,114,58,83,44,108,101,110,103,116,104,58,48,44,116,111,65,114,114,97,121,58,102,117,
        110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,115,46,99,97,108,108,40,116,104,105,115,41,125,44,103,101,116,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,
        32,110,117,108,108,61,61,101,63,115,46,99,97,108,108,40,116,104,105,115,41,58,101,60,48,63,116,104,105,115,91,101,43,116,104,105,115,46,108,101,110,103,116,104,93,58,116,104,105,115,91,101,93,125,
        44,112,117,115,104,83,116,97,99,107,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,83,46,109,101,114,103,101,40,116,104,105,115,46,99,111,110,115,116,114,117,99,116,111,114,
        40,41,44,101,41,59,114,101,116,117,114,110,32,116,46,112,114,101,118,79,98,106,101,99,116,61,116,104,105,115,44,116,125,44,101,97,99,104,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,
        117,114,110,32,83,46,101,97,99,104,40,116,104,105,115,44,101,41,125,44,109,97,112,58,102,117,110,99,116,105,111,110,40,110,41,123,114,101,116,117,114,110,32,116,104,105,115,46,112,117,115,104,83,
        116,97,99,107,40,83,46,109,97,112,40,116,104,105,115,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,110,46,99,97,108,108,40,101,44,116,44,101,41,125,41,41,125,
        44,115,108,105,99,101,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,116,104,105,115,46,112,117,115,104,83,116,97,99,107,40,115,46,97,112,112,108,121,40,116,104,105,115,44,
        97,114,103,117,109,101,110,116,115,41,41,125,44,102,105,114,115,116,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,116,104,105,115,46,101,113,40,48,41,125,44,108,97,115,116,
        58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,116,104,105,115,46,101,113,40,45,49,41,125,44,101,118,101,110,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,
        110,32,116,104,105,115,46,112,117,115,104,83,116,97,99,107,40,83,46,103,114,101,112,40,116,104,105,115,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,40,116,43,49,
        41,37,50,125,41,41,125,44,111,100,100,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,116,104,105,115,46,112,117,115,104,83,116,97,99,107,40,83,46,103,114,101,112,40,116,104,
        105,115,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,116,37,50,125,41,41,125,44,101,113,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,
        116,104,105,115,46,108,101,110,103,116,104,44,110,61,43,101,43,40,101,60,48,63,116,58,48,41,59,114,101,116,117,114,110,32,116,104,105,115,46,112,117,115,104,83,116,97,99,107,40,48,60,61,110,38,38,
        110,60,116,63,91,116,104,105,115,91,110,93,93,58,91,93,41,125,44,101,110,100,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,116,104,105,115,46,112,114,101,118,79,98,106,101,
        99,116,124,124,116,104,105,115,46,99,111,110,115,116,114,117,99,116,111,114,40,41,125,44,112,117,115,104,58,117,44,115,111,114,116,58,116,46,115,111,114,116,44,115,112,108,105,99,101,58,116,46,115,
        112,108,105,99,101,125,44,83,46,101,120,116,101,110,100,61,83,46,102,110,46,101,120,116,101,110,100,61,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,44,116,44,110,44,114,44,105,44,111,
        44,97,61,97,114,103,117,109,101,110,116,115,91,48,93,124,124,123,125,44,115,61,49,44,117,61,97,114,103,117,109,101,110,116,115,46,108,101,110,103,116,104,44,108,61,33,49,59,102,111,114,40,34,98,
        111,111,108,101,97,110,34,61,61,116,121,112,101,111,102,32,97,38,38,40,108,61,97,44,97,61,97,114,103,117,109,101,110,116,115,91,115,93,124,124,123,125,44,115,43,43,41,44,34,111,98,106,101,99,116,
        34,61,61,116,121,112,101,111,102,32,97,124,124,109,40,97,41,124,124,40,97,61,123,125,41,44,115,61,61,61,117,38,38,40,97,61,116,104,105,115,44,115,45,45,41,59,115,60,117,59,115,43,43,41,105,102,40,
        110,117,108,108,33,61,40,101,61,97,114,103,117,109,101,110,116,115,91,115,93,41,41,102,111,114,40,116,32,105,110,32,101,41,114,61,101,91,116,93,44,34,95,95,112,114,111,116,111,95,95,34,33,61,61,
        116,38,38,97,33,61,61,114,38,38,40,108,38,38,114,38,38,40,83,46,105,115,80,108,97,105,110,79,98,106,101,99,116,40,114,41,124,124,40,105,61,65,114,114,97,121,46,105,115,65,114,114,97,121,40,114,41,
        41,41,63,40,110,61,97,91,116,93,44,111,61,105,38,38,33,65,114,114,97,121,46,105,115,65,114,114,97,121,40,110,41,63,91,93,58,105,124,124,83,46,105,115,80,108,97,105,110,79,98,106,101,99,116,40,110,
        41,63,110,58,123,125,44,105,61,33,49,44,97,91,116,93,61,83,46,101,120,116,101,110,100,40,108,44,111,44,114,41,41,58,118,111,105,100,32,48,33,61,61,114,38,38,40,97,91,116,93,61,114,41,41,59,114,101,
        116,117,114,110,32,97,125,44,83,46,101,120,116,101,110,100,40,123,101,120,112,97,110,100,111,58,34,106,81,117,101,114,121,34,43,40,102,43,77,97,116,104,46,114,97,110,100,111,109,40,41,41,46,114,
        101,112,108,97,99,101,40,47,92,68,47,103,44,34,34,41,44,105,115,82,101,97,100,121,58,33,48,44,101,114,114,111,114,58,102,117,110,99,116,105,111,110,40,101,41,123,116,104,114,111,119,32,110,101,119,
        32,69,114,114,111,114,40,101,41,125,44,110,111,111,112,58,102,117,110,99,116,105,111,110,40,41,123,125,44,105,115,80,108,97,105,110,79,98,106,101,99,116,58,102,117,110,99,116,105,111,110,40,101,
        41,123,118,97,114,32,116,44,110,59,114,101,116,117,114,110,33,40,33,101,124,124,34,91,111,98,106,101,99,116,32,79,98,106,101,99,116,93,34,33,61,61,111,46,99,97,108,108,40,101,41,41,38,38,40,33,40,
        116,61,114,40,101,41,41,124,124,34,102,117,110,99,116,105,111,110,34,61,61,116,121,112,101,111,102,40,110,61,118,46,99,97,108,108,40,116,44,34,99,111,110,115,116,114,117,99,116,111,114,34,41,38,
        38,116,46,99,111,110,115,116,114,117,99,116,111,114,41,38,38,97,46,99,97,108,108,40,110,41,61,61,61,108,41,125,44,105,115,69,109,112,116,121,79,98,106,101,99,116,58,102,117,110,99,116,105,111,110,
        40,101,41,123,118,97,114,32,116,59,102,111,114,40,116,32,105,110,32,101,41,114,101,116,117,114,110,33,49,59,114,101,116,117,114,110,33,48,125,44,103,108,111,98,97,108,69,118,97,108,58,102,117,110,
        99,116,105,111,110,40,101,44,116,44,110,41,123,98,40,101,44,123,110,111,110,99,101,58,116,38,38,116,46,110,111,110,99,101,125,44,110,41,125,44,101,97,99,104,58,102,117,110,99,116,105,111,110,40,
        101,44,116,41,123,118,97,114,32,110,44,114,61,48,59,105,102,40,112,40,101,41,41,123,102,111,114,40,110,61,101,46,108,101,110,103,116,104,59,114,60,110,59,114,43,43,41,105,102,40,33,49,61,61,61,116,
        46,99,97,108,108,40,101,91,114,93,44,114,44,101,91,114,93,41,41,98,114,101,97,107,125,101,108,115,101,32,102,111,114,40,114,32,105,110,32,101,41,105,102,40,33,49,61,61,61,116,46,99,97,108,108,40,
        101,91,114,93,44,114,44,101,91,114,93,41,41,98,114,101,97,107,59,114,101,116,117,114,110,32,101,125,44,109,97,107,101,65,114,114,97,121,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,
        97,114,32,110,61,116,124,124,91,93,59,114,101,116,117,114,110,32,110,117,108,108,33,61,101,38,38,40,112,40,79,98,106,101,99,116,40,101,41,41,63,83,46,109,101,114,103,101,40,110,44,34,115,116,114,
        105,110,103,34,61,61,116,121,112,101,111,102,32,101,63,91,101,93,58,101,41,58,117,46,99,97,108,108,40,110,44,101,41,41,44,110,125,44,105,110,65,114,114,97,121,58,102,117,110,99,116,105,111,110,40,
        101,44,116,44,110,41,123,114,101,116,117,114,110,32,110,117,108,108,61,61,116,63,45,49,58,105,46,99,97,108,108,40,116,44,101,44,110,41,125,44,109,101,114,103,101,58,102,117,110,99,116,105,111,110,
        40,101,44,116,41,123,102,111,114,40,118,97,114,32,110,61,43,116,46,108,101,110,103,116,104,44,114,61,48,44,105,61,101,46,108,101,110,103,116,104,59,114,60,110,59,114,43,43,41,101,91,105,43,43,93,
        61,116,91,114,93,59,114,101,116,117,114,110,32,101,46,108,101,110,103,116,104,61,105,44,101,125,44,103,114,101,112,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,102,111,114,40,118,
        97,114,32,114,61,91,93,44,105,61,48,44,111,61,101,46,108,101,110,103,116,104,44,97,61,33,110,59,105,60,111,59,105,43,43,41,33,116,40,101,91,105,93,44,105,41,33,61,61,97,38,38,114,46,112,117,115,
        104,40,101,91,105,93,41,59,114,101,116,117,114,110,32,114,125,44,109,97,112,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,44,105,44,111,61,48,44,97,61,91,93,59,
        105,102,40,112,40,101,41,41,102,111,114,40,114,61,101,46,108,101,110,103,116,104,59,111,60,114,59,111,43,43,41,110,117,108,108,33,61,40,105,61,116,40,101,91,111,93,44,111,44,110,41,41,38,38,97,46,
        112,117,115,104,40,105,41,59,101,108,115,101,32,102,111,114,40,111,32,105,110,32,101,41,110,117,108,108,33,61,40,105,61,116,40,101,91,111,93,44,111,44,110,41,41,38,38,97,46,112,117,115,104,40,105,
        41,59,114,101,116,117,114,110,32,103,40,97,41,125,44,103,117,105,100,58,49,44,115,117,112,112,111,114,116,58,121,125,41,44,34,102,117,110,99,116,105,111,110,34,61,61,116,121,112,101,111,102,32,83,
        121,109,98,111,108,38,38,40,83,46,102,110,91,83,121,109,98,111,108,46,105,116,101,114,97,116,111,114,93,61,116,91,83,121,109,98,111,108,46,105,116,101,114,97,116,111,114,93,41,44,83,46,101,97,99,
        104,40,34,66,111,111,108,101,97,110,32,78,117,109,98,101,114,32,83,116,114,105,110,103,32,70,117,110,99,116,105,111,110,32,65,114,114,97,121,32,68,97,116,101,32,82,101,103,69,120,112,32,79,98,106,
        101,99,116,32,69,114,114,111,114,32,83,121,109,98,111,108,34,46,115,112,108,105,116,40,34,32,34,41,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,110,91,34,91,111,98,106,101,99,116,32,34,
        43,116,43,34,93,34,93,61,116,46,116,111,76,111,119,101,114,67,97,115,101,40,41,125,41,59,118,97,114,32,100,61,102,117,110,99,116,105,111,110,40,110,41,123,118,97,114,32,101,44,100,44,98,44,111,44,
        105,44,104,44,102,44,103,44,119,44,117,44,108,44,84,44,67,44,97,44,69,44,118,44,115,44,99,44,121,44,83,61,34,115,105,122,122,108,101,34,43,49,42,110,101,119,32,68,97,116,101,44,112,61,110,46,100,
        111,99,117,109,101,110,116,44,107,61,48,44,114,61,48,44,109,61,117,101,40,41,44,120,61,117,101,40,41,44,65,61,117,101,40,41,44,78,61,117,101,40,41,44,106,61,102,117,110,99,116,105,111,110,40,101,
        44,116,41,123,114,101,116,117,114,110,32,101,61,61,61,116,38,38,40,108,61,33,48,41,44,48,125,44,68,61,123,125,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,44,116,61,91,93,44,113,61,116,
        46,112,111,112,44,76,61,116,46,112,117,115,104,44,72,61,116,46,112,117,115,104,44,79,61,116,46,115,108,105,99,101,44,80,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,102,111,114,40,118,
        97,114,32,110,61,48,44,114,61,101,46,108,101,110,103,116,104,59,110,60,114,59,110,43,43,41,105,102,40,101,91,110,93,61,61,61,116,41,114,101,116,117,114,110,32,110,59,114,101,116,117,114,110,45,49,
        125,44,82,61,34,99,104,101,99,107,101,100,124,115,101,108,101,99,116,101,100,124,97,115,121,110,99,124,97,117,116,111,102,111,99,117,115,124,97,117,116,111,112,108,97,121,124,99,111,110,116,114,
        111,108,115,124,100,101,102,101,114,124,100,105,115,97,98,108,101,100,124,104,105,100,100,101,110,124,105,115,109,97,112,124,108,111,111,112,124,109,117,108,116,105,112,108,101,124,111,112,101,110,
        124,114,101,97,100,111,110,108,121,124,114,101,113,117,105,114,101,100,124,115,99,111,112,101,100,34,44,77,61,34,91,92,92,120,50,48,92,92,116,92,92,114,92,92,110,92,92,102,93,34,44,73,61,34,40,63,
        58,92,92,92,92,91,92,92,100,97,45,102,65,45,70,93,123,49,44,54,125,34,43,77,43,34,63,124,92,92,92,92,91,94,92,92,114,92,92,110,92,92,102,93,124,91,92,92,119,45,93,124,91,94,92,48,45,92,92,120,55,
        102,93,41,43,34,44,87,61,34,92,92,91,34,43,77,43,34,42,40,34,43,73,43,34,41,40,63,58,34,43,77,43,34,42,40,91,42,94,36,124,33,126,93,63,61,41,34,43,77,43,34,42,40,63,58,39,40,40,63,58,92,92,92,92,
        46,124,91,94,92,92,92,92,39,93,41,42,41,39,124,92,34,40,40,63,58,92,92,92,92,46,124,91,94,92,92,92,92,92,34,93,41,42,41,92,34,124,40,34,43,73,43,34,41,41,124,41,34,43,77,43,34,42,92,92,93,34,44,
        70,61,34,58,40,34,43,73,43,34,41,40,63,58,92,92,40,40,40,39,40,40,63,58,92,92,92,92,46,124,91,94,92,92,92,92,39,93,41,42,41,39,124,92,34,40,40,63,58,92,92,92,92,46,124,91,94,92,92,92,92,92,34,93,
        41,42,41,92,34,41,124,40,40,63,58,92,92,92,92,46,124,91,94,92,92,92,92,40,41,91,92,92,93,93,124,34,43,87,43,34,41,42,41,124,46,42,41,92,92,41,124,41,34,44,66,61,110,101,119,32,82,101,103,69,120,
        112,40,77,43,34,43,34,44,34,103,34,41,44,36,61,110,101,119,32,82,101,103,69,120,112,40,34,94,34,43,77,43,34,43,124,40,40,63,58,94,124,91,94,92,92,92,92,93,41,40,63,58,92,92,92,92,46,41,42,41,34,
        43,77,43,34,43,36,34,44,34,103,34,41,44,95,61,110,101,119,32,82,101,103,69,120,112,40,34,94,34,43,77,43,34,42,44,34,43,77,43,34,42,34,41,44,122,61,110,101,119,32,82,101,103,69,120,112,40,34,94,34,
        43,77,43,34,42,40,91,62,43,126,93,124,34,43,77,43,34,41,34,43,77,43,34,42,34,41,44,85,61,110,101,119,32,82,101,103,69,120,112,40,77,43,34,124,62,34,41,44,88,61,110,101,119,32,82,101,103,69,120,112,
        40,70,41,44,86,61,110,101,119,32,82,101,103,69,120,112,40,34,94,34,43,73,43,34,36,34,41,44,71,61,123,73,68,58,110,101,119,32,82,101,103,69,120,112,40,34,94,35,40,34,43,73,43,34,41,34,41,44,67,76,
        65,83,83,58,110,101,119,32,82,101,103,69,120,112,40,34,94,92,92,46,40,34,43,73,43,34,41,34,41,44,84,65,71,58,110,101,119,32,82,101,103,69,120,112,40,34,94,40,34,43,73,43,34,124,91,42,93,41,34,41,
        44,65,84,84,82,58,110,101,119,32,82,101,103,69,120,112,40,34,94,34,43,87,41,44,80,83,69,85,68,79,58,110,101,119,32,82,101,103,69,120,112,40,34,94,34,43,70,41,44,67,72,73,76,68,58,110,101,119,32,
        82,101,103,69,120,112,40,34,94,58,40,111,110,108,121,124,102,105,114,115,116,124,108,97,115,116,124,110,116,104,124,110,116,104,45,108,97,115,116,41,45,40,99,104,105,108,100,124,111,102,45,116,121,
        112,101,41,40,63,58,92,92,40,34,43,77,43,34,42,40,101,118,101,110,124,111,100,100,124,40,40,91,43,45,93,124,41,40,92,92,100,42,41,110,124,41,34,43,77,43,34,42,40,63,58,40,91,43,45,93,124,41,34,43,
        77,43,34,42,40,92,92,100,43,41,124,41,41,34,43,77,43,34,42,92,92,41,124,41,34,44,34,105,34,41,44,98,111,111,108,58,110,101,119,32,82,101,103,69,120,112,40,34,94,40,63,58,34,43,82,43,34,41,36,34,
        44,34,105,34,41,44,110,101,101,100,115,67,111,110,116,101,120,116,58,110,101,119,32,82,101,103,69,120,112,40,34,94,34,43,77,43,34,42,91,62,43,126,93,124,58,40,101,118,101,110,124,111,100,100,124,
        101,113,124,103,116,124,108,116,124,110,116,104,124,102,105,114,115,116,124,108,97,115,116,41,40,63,58,92,92,40,34,43,77,43,34,42,40,40,63,58,45,92,92,100,41,63,92,92,100,42,41,34,43,77,43,34,42,
        92,92,41,124,41,40,63,61,91,94,45,93,124,36,41,34,44,34,105,34,41,125,44,89,61,47,72,84,77,76,36,47,105,44,81,61,47,94,40,63,58,105,110,112,117,116,124,115,101,108,101,99,116,124,116,101,120,116,
        97,114,101,97,124,98,117,116,116,111,110,41,36,47,105,44,74,61,47,94,104,92,100,36,47,105,44,75,61,47,94,91,94,123,93,43,92,123,92,115,42,92,91,110,97,116,105,118,101,32,92,119,47,44,90,61,47,94,
        40,63,58,35,40,91,92,119,45,93,43,41,124,40,92,119,43,41,124,92,46,40,91,92,119,45,93,43,41,41,36,47,44,101,101,61,47,91,43,126,93,47,44,116,101,61,110,101,119,32,82,101,103,69,120,112,40,34,92,
        92,92,92,91,92,92,100,97,45,102,65,45,70,93,123,49,44,54,125,34,43,77,43,34,63,124,92,92,92,92,40,91,94,92,92,114,92,92,110,92,92,102,93,41,34,44,34,103,34,41,44,110,101,61,102,117,110,99,116,105,
        111,110,40,101,44,116,41,123,118,97,114,32,110,61,34,48,120,34,43,101,46,115,108,105,99,101,40,49,41,45,54,53,53,51,54,59,114,101,116,117,114,110,32,116,124,124,40,110,60,48,63,83,116,114,105,110,
        103,46,102,114,111,109,67,104,97,114,67,111,100,101,40,110,43,54,53,53,51,54,41,58,83,116,114,105,110,103,46,102,114,111,109,67,104,97,114,67,111,100,101,40,110,62,62,49,48,124,53,53,50,57,54,44,
        49,48,50,51,38,110,124,53,54,51,50,48,41,41,125,44,114,101,61,47,40,91,92,48,45,92,120,49,102,92,120,55,102,93,124,94,45,63,92,100,41,124,94,45,36,124,91,94,92,48,45,92,120,49,102,92,120,55,102,
        45,92,117,70,70,70,70,92,119,45,93,47,103,44,105,101,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,116,63,34,92,48,34,61,61,61,101,63,34,92,117,102,102,102,100,
        34,58,101,46,115,108,105,99,101,40,48,44,45,49,41,43,34,92,92,34,43,101,46,99,104,97,114,67,111,100,101,65,116,40,101,46,108,101,110,103,116,104,45,49,41,46,116,111,83,116,114,105,110,103,40,49,
        54,41,43,34,32,34,58,34,92,92,34,43,101,125,44,111,101,61,102,117,110,99,116,105,111,110,40,41,123,84,40,41,125,44,97,101,61,98,101,40,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,
        114,110,33,48,61,61,61,101,46,100,105,115,97,98,108,101,100,38,38,34,102,105,101,108,100,115,101,116,34,61,61,61,101,46,110,111,100,101,78,97,109,101,46,116,111,76,111,119,101,114,67,97,115,101,
        40,41,125,44,123,100,105,114,58,34,112,97,114,101,110,116,78,111,100,101,34,44,110,101,120,116,58,34,108,101,103,101,110,100,34,125,41,59,116,114,121,123,72,46,97,112,112,108,121,40,116,61,79,46,
        99,97,108,108,40,112,46,99,104,105,108,100,78,111,100,101,115,41,44,112,46,99,104,105,108,100,78,111,100,101,115,41,44,116,91,112,46,99,104,105,108,100,78,111,100,101,115,46,108,101,110,103,116,
        104,93,46,110,111,100,101,84,121,112,101,125,99,97,116,99,104,40,101,41,123,72,61,123,97,112,112,108,121,58,116,46,108,101,110,103,116,104,63,102,117,110,99,116,105,111,110,40,101,44,116,41,123,
        76,46,97,112,112,108,121,40,101,44,79,46,99,97,108,108,40,116,41,41,125,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,61,101,46,108,101,110,103,116,104,44,114,61,48,59,
        119,104,105,108,101,40,101,91,110,43,43,93,61,116,91,114,43,43,93,41,59,101,46,108,101,110,103,116,104,61,110,45,49,125,125,125,102,117,110,99,116,105,111,110,32,115,101,40,116,44,101,44,110,44,
        114,41,123,118,97,114,32,105,44,111,44,97,44,115,44,117,44,108,44,99,44,102,61,101,38,38,101,46,111,119,110,101,114,68,111,99,117,109,101,110,116,44,112,61,101,63,101,46,110,111,100,101,84,121,112,
        101,58,57,59,105,102,40,110,61,110,124,124,91,93,44,34,115,116,114,105,110,103,34,33,61,116,121,112,101,111,102,32,116,124,124,33,116,124,124,49,33,61,61,112,38,38,57,33,61,61,112,38,38,49,49,33,
        61,61,112,41,114,101,116,117,114,110,32,110,59,105,102,40,33,114,38,38,40,84,40,101,41,44,101,61,101,124,124,67,44,69,41,41,123,105,102,40,49,49,33,61,61,112,38,38,40,117,61,90,46,101,120,101,99,
        40,116,41,41,41,105,102,40,105,61,117,91,49,93,41,123,105,102,40,57,61,61,61,112,41,123,105,102,40,33,40,97,61,101,46,103,101,116,69,108,101,109,101,110,116,66,121,73,100,40,105,41,41,41,114,101,
        116,117,114,110,32,110,59,105,102,40,97,46,105,100,61,61,61,105,41,114,101,116,117,114,110,32,110,46,112,117,115,104,40,97,41,44,110,125,101,108,115,101,32,105,102,40,102,38,38,40,97,61,102,46,103,
        101,116,69,108,101,109,101,110,116,66,121,73,100,40,105,41,41,38,38,121,40,101,44,97,41,38,38,97,46,105,100,61,61,61,105,41,114,101,116,117,114,110,32,110,46,112,117,115,104,40,97,41,44,110,125,
        101,108,115,101,123,105,102,40,117,91,50,93,41,114,101,116,117,114,110,32,72,46,97,112,112,108,121,40,110,44,101,46,103,101,116,69,108,101,109,101,110,116,115,66,121,84,97,103,78,97,109,101,40,116,
        41,41,44,110,59,105,102,40,40,105,61,117,91,51,93,41,38,38,100,46,103,101,116,69,108,101,109,101,110,116,115,66,121,67,108,97,115,115,78,97,109,101,38,38,101,46,103,101,116,69,108,101,109,101,110,
        116,115,66,121,67,108,97,115,115,78,97,109,101,41,114,101,116,117,114,110,32,72,46,97,112,112,108,121,40,110,44,101,46,103,101,116,69,108,101,109,101,110,116,115,66,121,67,108,97,115,115,78,97,109,
        101,40,105,41,41,44,110,125,105,102,40,100,46,113,115,97,38,38,33,78,91,116,43,34,32,34,93,38,38,40,33,118,124,124,33,118,46,116,101,115,116,40,116,41,41,38,38,40,49,33,61,61,112,124,124,34,111,
        98,106,101,99,116,34,33,61,61,101,46,110,111,100,101,78,97,109,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,41,41,123,105,102,40,99,61,116,44,102,61,101,44,49,61,61,61,112,38,38,40,85,46,
        116,101,115,116,40,116,41,124,124,122,46,116,101,115,116,40,116,41,41,41,123,40,102,61,101,101,46,116,101,115,116,40,116,41,38,38,121,101,40,101,46,112,97,114,101,110,116,78,111,100,101,41,124,124,
        101,41,61,61,61,101,38,38,100,46,115,99,111,112,101,124,124,40,40,115,61,101,46,103,101,116,65,116,116,114,105,98,117,116,101,40,34,105,100,34,41,41,63,115,61,115,46,114,101,112,108,97,99,101,40,
        114,101,44,105,101,41,58,101,46,115,101,116,65,116,116,114,105,98,117,116,101,40,34,105,100,34,44,115,61,83,41,41,44,111,61,40,108,61,104,40,116,41,41,46,108,101,110,103,116,104,59,119,104,105,108,
        101,40,111,45,45,41,108,91,111,93,61,40,115,63,34,35,34,43,115,58,34,58,115,99,111,112,101,34,41,43,34,32,34,43,120,101,40,108,91,111,93,41,59,99,61,108,46,106,111,105,110,40,34,44,34,41,125,116,
        114,121,123,114,101,116,117,114,110,32,72,46,97,112,112,108,121,40,110,44,102,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,99,41,41,44,110,125,99,97,116,99,104,40,101,41,123,
        78,40,116,44,33,48,41,125,102,105,110,97,108,108,121,123,115,61,61,61,83,38,38,101,46,114,101,109,111,118,101,65,116,116,114,105,98,117,116,101,40,34,105,100,34,41,125,125,125,114,101,116,117,114,
        110,32,103,40,116,46,114,101,112,108,97,99,101,40,36,44,34,36,49,34,41,44,101,44,110,44,114,41,125,102,117,110,99,116,105,111,110,32,117,101,40,41,123,118,97,114,32,114,61,91,93,59,114,101,116,117,
        114,110,32,102,117,110,99,116,105,111,110,32,101,40,116,44,110,41,123,114,101,116,117,114,110,32,114,46,112,117,115,104,40,116,43,34,32,34,41,62,98,46,99,97,99,104,101,76,101,110,103,116,104,38,
        38,100,101,108,101,116,101,32,101,91,114,46,115,104,105,102,116,40,41,93,44,101,91,116,43,34,32,34,93,61,110,125,125,102,117,110,99,116,105,111,110,32,108,101,40,101,41,123,114,101,116,117,114,110,
        32,101,91,83,93,61,33,48,44,101,125,102,117,110,99,116,105,111,110,32,99,101,40,101,41,123,118,97,114,32,116,61,67,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,102,105,101,108,100,115,
        101,116,34,41,59,116,114,121,123,114,101,116,117,114,110,33,33,101,40,116,41,125,99,97,116,99,104,40,101,41,123,114,101,116,117,114,110,33,49,125,102,105,110,97,108,108,121,123,116,46,112,97,114,
        101,110,116,78,111,100,101,38,38,116,46,112,97,114,101,110,116,78,111,100,101,46,114,101,109,111,118,101,67,104,105,108,100,40,116,41,44,116,61,110,117,108,108,125,125,102,117,110,99,116,105,111,
        110,32,102,101,40,101,44,116,41,123,118,97,114,32,110,61,101,46,115,112,108,105,116,40,34,124,34,41,44,114,61,110,46,108,101,110,103,116,104,59,119,104,105,108,101,40,114,45,45,41,98,46,97,116,116,
        114,72,97,110,100,108,101,91,110,91,114,93,93,61,116,125,102,117,110,99,116,105,111,110,32,112,101,40,101,44,116,41,123,118,97,114,32,110,61,116,38,38,101,44,114,61,110,38,38,49,61,61,61,101,46,
        110,111,100,101,84,121,112,101,38,38,49,61,61,61,116,46,110,111,100,101,84,121,112,101,38,38,101,46,115,111,117,114,99,101,73,110,100,101,120,45,116,46,115,111,117,114,99,101,73,110,100,101,120,
        59,105,102,40,114,41,114,101,116,117,114,110,32,114,59,105,102,40,110,41,119,104,105,108,101,40,110,61,110,46,110,101,120,116,83,105,98,108,105,110,103,41,105,102,40,110,61,61,61,116,41,114,101,
        116,117,114,110,45,49,59,114,101,116,117,114,110,32,101,63,49,58,45,49,125,102,117,110,99,116,105,111,110,32,100,101,40,116,41,123,114,101,116,117,114,110,32,102,117,110,99,116,105,111,110,40,101,
        41,123,114,101,116,117,114,110,34,105,110,112,117,116,34,61,61,61,101,46,110,111,100,101,78,97,109,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,38,38,101,46,116,121,112,101,61,61,61,116,
        125,125,102,117,110,99,116,105,111,110,32,104,101,40,110,41,123,114,101,116,117,114,110,32,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,101,46,110,111,100,101,78,97,109,101,
        46,116,111,76,111,119,101,114,67,97,115,101,40,41,59,114,101,116,117,114,110,40,34,105,110,112,117,116,34,61,61,61,116,124,124,34,98,117,116,116,111,110,34,61,61,61,116,41,38,38,101,46,116,121,112,
        101,61,61,61,110,125,125,102,117,110,99,116,105,111,110,32,103,101,40,116,41,123,114,101,116,117,114,110,32,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,34,102,111,114,109,
        34,105,110,32,101,63,101,46,112,97,114,101,110,116,78,111,100,101,38,38,33,49,61,61,61,101,46,100,105,115,97,98,108,101,100,63,34,108,97,98,101,108,34,105,110,32,101,63,34,108,97,98,101,108,34,105,
        110,32,101,46,112,97,114,101,110,116,78,111,100,101,63,101,46,112,97,114,101,110,116,78,111,100,101,46,100,105,115,97,98,108,101,100,61,61,61,116,58,101,46,100,105,115,97,98,108,101,100,61,61,61,
        116,58,101,46,105,115,68,105,115,97,98,108,101,100,61,61,61,116,124,124,101,46,105,115,68,105,115,97,98,108,101,100,33,61,61,33,116,38,38,97,101,40,101,41,61,61,61,116,58,101,46,100,105,115,97,98,
        108,101,100,61,61,61,116,58,34,108,97,98,101,108,34,105,110,32,101,38,38,101,46,100,105,115,97,98,108,101,100,61,61,61,116,125,125,102,117,110,99,116,105,111,110,32,118,101,40,97,41,123,114,101,
        116,117,114,110,32,108,101,40,102,117,110,99,116,105,111,110,40,111,41,123,114,101,116,117,114,110,32,111,61,43,111,44,108,101,40,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,
        110,44,114,61,97,40,91,93,44,101,46,108,101,110,103,116,104,44,111,41,44,105,61,114,46,108,101,110,103,116,104,59,119,104,105,108,101,40,105,45,45,41,101,91,110,61,114,91,105,93,93,38,38,40,101,
        91,110,93,61,33,40,116,91,110,93,61,101,91,110,93,41,41,125,41,125,41,125,102,117,110,99,116,105,111,110,32,121,101,40,101,41,123,114,101,116,117,114,110,32,101,38,38,34,117,110,100,101,102,105,
        110,101,100,34,33,61,116,121,112,101,111,102,32,101,46,103,101,116,69,108,101,109,101,110,116,115,66,121,84,97,103,78,97,109,101,38,38,101,125,102,111,114,40,101,32,105,110,32,100,61,115,101,46,
        115,117,112,112,111,114,116,61,123,125,44,105,61,115,101,46,105,115,88,77,76,61,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,101,38,38,101,46,110,97,109,101,115,112,97,99,101,
        85,82,73,44,110,61,101,38,38,40,101,46,111,119,110,101,114,68,111,99,117,109,101,110,116,124,124,101,41,46,100,111,99,117,109,101,110,116,69,108,101,109,101,110,116,59,114,101,116,117,114,110,33,
        89,46,116,101,115,116,40,116,124,124,110,38,38,110,46,110,111,100,101,78,97,109,101,124,124,34,72,84,77,76,34,41,125,44,84,61,115,101,46,115,101,116,68,111,99,117,109,101,110,116,61,102,117,110,
        99,116,105,111,110,40,101,41,123,118,97,114,32,116,44,110,44,114,61,101,63,101,46,111,119,110,101,114,68,111,99,117,109,101,110,116,124,124,101,58,112,59,114,101,116,117,114,110,32,114,33,61,67,
        38,38,57,61,61,61,114,46,110,111,100,101,84,121,112,101,38,38,114,46,100,111,99,117,109,101,110,116,69,108,101,109,101,110,116,38,38,40,97,61,40,67,61,114,41,46,100,111,99,117,109,101,110,116,69,
        108,101,109,101,110,116,44,69,61,33,105,40,67,41,44,112,33,61,67,38,38,40,110,61,67,46,100,101,102,97,117,108,116,86,105,101,119,41,38,38,110,46,116,111,112,33,61,61,110,38,38,40,110,46,97,100,100,
        69,118,101,110,116,76,105,115,116,101,110,101,114,63,110,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,117,110,108,111,97,100,34,44,111,101,44,33,49,41,58,110,46,97,116,116,
        97,99,104,69,118,101,110,116,38,38,110,46,97,116,116,97,99,104,69,118,101,110,116,40,34,111,110,117,110,108,111,97,100,34,44,111,101,41,41,44,100,46,115,99,111,112,101,61,99,101,40,102,117,110,99,
        116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,97,46,97,112,112,101,110,100,67,104,105,108,100,40,101,41,46,97,112,112,101,110,100,67,104,105,108,100,40,67,46,99,114,101,97,116,101,69,
        108,101,109,101,110,116,40,34,100,105,118,34,41,41,44,34,117,110,100,101,102,105,110,101,100,34,33,61,116,121,112,101,111,102,32,101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,
        38,38,33,101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,34,58,115,99,111,112,101,32,102,105,101,108,100,115,101,116,32,100,105,118,34,41,46,108,101,110,103,116,104,125,41,
        44,100,46,97,116,116,114,105,98,117,116,101,115,61,99,101,40,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,46,99,108,97,115,115,78,97,109,101,61,34,105,34,44,33,101,
        46,103,101,116,65,116,116,114,105,98,117,116,101,40,34,99,108,97,115,115,78,97,109,101,34,41,125,41,44,100,46,103,101,116,69,108,101,109,101,110,116,115,66,121,84,97,103,78,97,109,101,61,99,101,
        40,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,46,97,112,112,101,110,100,67,104,105,108,100,40,67,46,99,114,101,97,116,101,67,111,109,109,101,110,116,40,34,34,41,
        41,44,33,101,46,103,101,116,69,108,101,109,101,110,116,115,66,121,84,97,103,78,97,109,101,40,34,42,34,41,46,108,101,110,103,116,104,125,41,44,100,46,103,101,116,69,108,101,109,101,110,116,115,66,
        121,67,108,97,115,115,78,97,109,101,61,75,46,116,101,115,116,40,67,46,103,101,116,69,108,101,109,101,110,116,115,66,121,67,108,97,115,115,78,97,109,101,41,44,100,46,103,101,116,66,121,73,100,61,
        99,101,40,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,97,46,97,112,112,101,110,100,67,104,105,108,100,40,101,41,46,105,100,61,83,44,33,67,46,103,101,116,69,108,101,109,
        101,110,116,115,66,121,78,97,109,101,124,124,33,67,46,103,101,116,69,108,101,109,101,110,116,115,66,121,78,97,109,101,40,83,41,46,108,101,110,103,116,104,125,41,44,100,46,103,101,116,66,121,73,100,
        63,40,98,46,102,105,108,116,101,114,46,73,68,61,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,101,46,114,101,112,108,97,99,101,40,116,101,44,110,101,41,59,114,101,116,117,114,
        110,32,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,46,103,101,116,65,116,116,114,105,98,117,116,101,40,34,105,100,34,41,61,61,61,116,125,125,44,98,46,102,105,110,
        100,46,73,68,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,105,102,40,34,117,110,100,101,102,105,110,101,100,34,33,61,116,121,112,101,111,102,32,116,46,103,101,116,69,108,101,109,101,110,
        116,66,121,73,100,38,38,69,41,123,118,97,114,32,110,61,116,46,103,101,116,69,108,101,109,101,110,116,66,121,73,100,40,101,41,59,114,101,116,117,114,110,32,110,63,91,110,93,58,91,93,125,125,41,58,
        40,98,46,102,105,108,116,101,114,46,73,68,61,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,110,61,101,46,114,101,112,108,97,99,101,40,116,101,44,110,101,41,59,114,101,116,117,114,110,
        32,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,34,117,110,100,101,102,105,110,101,100,34,33,61,116,121,112,101,111,102,32,101,46,103,101,116,65,116,116,114,105,98,117,116,101,
        78,111,100,101,38,38,101,46,103,101,116,65,116,116,114,105,98,117,116,101,78,111,100,101,40,34,105,100,34,41,59,114,101,116,117,114,110,32,116,38,38,116,46,118,97,108,117,101,61,61,61,110,125,125,
        44,98,46,102,105,110,100,46,73,68,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,105,102,40,34,117,110,100,101,102,105,110,101,100,34,33,61,116,121,112,101,111,102,32,116,46,103,101,116,
        69,108,101,109,101,110,116,66,121,73,100,38,38,69,41,123,118,97,114,32,110,44,114,44,105,44,111,61,116,46,103,101,116,69,108,101,109,101,110,116,66,121,73,100,40,101,41,59,105,102,40,111,41,123,
        105,102,40,40,110,61,111,46,103,101,116,65,116,116,114,105,98,117,116,101,78,111,100,101,40,34,105,100,34,41,41,38,38,110,46,118,97,108,117,101,61,61,61,101,41,114,101,116,117,114,110,91,111,93,
        59,105,61,116,46,103,101,116,69,108,101,109,101,110,116,115,66,121,78,97,109,101,40,101,41,44,114,61,48,59,119,104,105,108,101,40,111,61,105,91,114,43,43,93,41,105,102,40,40,110,61,111,46,103,101,
        116,65,116,116,114,105,98,117,116,101,78,111,100,101,40,34,105,100,34,41,41,38,38,110,46,118,97,108,117,101,61,61,61,101,41,114,101,116,117,114,110,91,111,93,125,114,101,116,117,114,110,91,93,125,
        125,41,44,98,46,102,105,110,100,46,84,65,71,61,100,46,103,101,116,69,108,101,109,101,110,116,115,66,121,84,97,103,78,97,109,101,63,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,
        117,114,110,34,117,110,100,101,102,105,110,101,100,34,33,61,116,121,112,101,111,102,32,116,46,103,101,116,69,108,101,109,101,110,116,115,66,121,84,97,103,78,97,109,101,63,116,46,103,101,116,69,108,
        101,109,101,110,116,115,66,121,84,97,103,78,97,109,101,40,101,41,58,100,46,113,115,97,63,116,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,101,41,58,118,111,105,100,32,48,125,
        58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,44,114,61,91,93,44,105,61,48,44,111,61,116,46,103,101,116,69,108,101,109,101,110,116,115,66,121,84,97,103,78,97,109,101,40,
        101,41,59,105,102,40,34,42,34,61,61,61,101,41,123,119,104,105,108,101,40,110,61,111,91,105,43,43,93,41,49,61,61,61,110,46,110,111,100,101,84,121,112,101,38,38,114,46,112,117,115,104,40,110,41,59,
        114,101,116,117,114,110,32,114,125,114,101,116,117,114,110,32,111,125,44,98,46,102,105,110,100,46,67,76,65,83,83,61,100,46,103,101,116,69,108,101,109,101,110,116,115,66,121,67,108,97,115,115,78,
        97,109,101,38,38,102,117,110,99,116,105,111,110,40,101,44,116,41,123,105,102,40,34,117,110,100,101,102,105,110,101,100,34,33,61,116,121,112,101,111,102,32,116,46,103,101,116,69,108,101,109,101,110,
        116,115,66,121,67,108,97,115,115,78,97,109,101,38,38,69,41,114,101,116,117,114,110,32,116,46,103,101,116,69,108,101,109,101,110,116,115,66,121,67,108,97,115,115,78,97,109,101,40,101,41,125,44,115,
        61,91,93,44,118,61,91,93,44,40,100,46,113,115,97,61,75,46,116,101,115,116,40,67,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,41,41,38,38,40,99,101,40,102,117,110,99,116,105,111,
        110,40,101,41,123,118,97,114,32,116,59,97,46,97,112,112,101,110,100,67,104,105,108,100,40,101,41,46,105,110,110,101,114,72,84,77,76,61,34,60,97,32,105,100,61,39,34,43,83,43,34,39,62,60,47,97,62,
        60,115,101,108,101,99,116,32,105,100,61,39,34,43,83,43,34,45,92,114,92,92,39,32,109,115,97,108,108,111,119,99,97,112,116,117,114,101,61,39,39,62,60,111,112,116,105,111,110,32,115,101,108,101,99,
        116,101,100,61,39,39,62,60,47,111,112,116,105,111,110,62,60,47,115,101,108,101,99,116,62,34,44,101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,34,91,109,115,97,108,108,111,
        119,99,97,112,116,117,114,101,94,61,39,39,93,34,41,46,108,101,110,103,116,104,38,38,118,46,112,117,115,104,40,34,91,42,94,36,93,61,34,43,77,43,34,42,40,63,58,39,39,124,92,34,92,34,41,34,41,44,101,
        46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,34,91,115,101,108,101,99,116,101,100,93,34,41,46,108,101,110,103,116,104,124,124,118,46,112,117,115,104,40,34,92,92,91,34,43,77,
        43,34,42,40,63,58,118,97,108,117,101,124,34,43,82,43,34,41,34,41,44,101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,34,91,105,100,126,61,34,43,83,43,34,45,93,34,41,46,108,
        101,110,103,116,104,124,124,118,46,112,117,115,104,40,34,126,61,34,41,44,40,116,61,67,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,105,110,112,117,116,34,41,41,46,115,101,116,65,116,
        116,114,105,98,117,116,101,40,34,110,97,109,101,34,44,34,34,41,44,101,46,97,112,112,101,110,100,67,104,105,108,100,40,116,41,44,101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,
        40,34,91,110,97,109,101,61,39,39,93,34,41,46,108,101,110,103,116,104,124,124,118,46,112,117,115,104,40,34,92,92,91,34,43,77,43,34,42,110,97,109,101,34,43,77,43,34,42,61,34,43,77,43,34,42,40,63,58,
        39,39,124,92,34,92,34,41,34,41,44,101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,34,58,99,104,101,99,107,101,100,34,41,46,108,101,110,103,116,104,124,124,118,46,112,117,115,
        104,40,34,58,99,104,101,99,107,101,100,34,41,44,101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,34,97,35,34,43,83,43,34,43,42,34,41,46,108,101,110,103,116,104,124,124,118,
        46,112,117,115,104,40,34,46,35,46,43,91,43,126,93,34,41,44,101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,34,92,92,92,102,34,41,44,118,46,112,117,115,104,40,34,91,92,92,114,
        92,92,110,92,92,102,93,34,41,125,41,44,99,101,40,102,117,110,99,116,105,111,110,40,101,41,123,101,46,105,110,110,101,114,72,84,77,76,61,34,60,97,32,104,114,101,102,61,39,39,32,100,105,115,97,98,
        108,101,100,61,39,100,105,115,97,98,108,101,100,39,62,60,47,97,62,60,115,101,108,101,99,116,32,100,105,115,97,98,108,101,100,61,39,100,105,115,97,98,108,101,100,39,62,60,111,112,116,105,111,110,
        47,62,60,47,115,101,108,101,99,116,62,34,59,118,97,114,32,116,61,67,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,105,110,112,117,116,34,41,59,116,46,115,101,116,65,116,116,114,105,98,
        117,116,101,40,34,116,121,112,101,34,44,34,104,105,100,100,101,110,34,41,44,101,46,97,112,112,101,110,100,67,104,105,108,100,40,116,41,46,115,101,116,65,116,116,114,105,98,117,116,101,40,34,110,
        97,109,101,34,44,34,68,34,41,44,101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,34,91,110,97,109,101,61,100,93,34,41,46,108,101,110,103,116,104,38,38,118,46,112,117,115,104,
        40,34,110,97,109,101,34,43,77,43,34,42,91,42,94,36,124,33,126,93,63,61,34,41,44,50,33,61,61,101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,34,58,101,110,97,98,108,101,100,
        34,41,46,108,101,110,103,116,104,38,38,118,46,112,117,115,104,40,34,58,101,110,97,98,108,101,100,34,44,34,58,100,105,115,97,98,108,101,100,34,41,44,97,46,97,112,112,101,110,100,67,104,105,108,100,
        40,101,41,46,100,105,115,97,98,108,101,100,61,33,48,44,50,33,61,61,101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,34,58,100,105,115,97,98,108,101,100,34,41,46,108,101,110,
        103,116,104,38,38,118,46,112,117,115,104,40,34,58,101,110,97,98,108,101,100,34,44,34,58,100,105,115,97,98,108,101,100,34,41,44,101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,
        40,34,42,44,58,120,34,41,44,118,46,112,117,115,104,40,34,44,46,42,58,34,41,125,41,41,44,40,100,46,109,97,116,99,104,101,115,83,101,108,101,99,116,111,114,61,75,46,116,101,115,116,40,99,61,97,46,
        109,97,116,99,104,101,115,124,124,97,46,119,101,98,107,105,116,77,97,116,99,104,101,115,83,101,108,101,99,116,111,114,124,124,97,46,109,111,122,77,97,116,99,104,101,115,83,101,108,101,99,116,111,
        114,124,124,97,46,111,77,97,116,99,104,101,115,83,101,108,101,99,116,111,114,124,124,97,46,109,115,77,97,116,99,104,101,115,83,101,108,101,99,116,111,114,41,41,38,38,99,101,40,102,117,110,99,116,
        105,111,110,40,101,41,123,100,46,100,105,115,99,111,110,110,101,99,116,101,100,77,97,116,99,104,61,99,46,99,97,108,108,40,101,44,34,42,34,41,44,99,46,99,97,108,108,40,101,44,34,91,115,33,61,39,39,
        93,58,120,34,41,44,115,46,112,117,115,104,40,34,33,61,34,44,70,41,125,41,44,118,61,118,46,108,101,110,103,116,104,38,38,110,101,119,32,82,101,103,69,120,112,40,118,46,106,111,105,110,40,34,124,34,
        41,41,44,115,61,115,46,108,101,110,103,116,104,38,38,110,101,119,32,82,101,103,69,120,112,40,115,46,106,111,105,110,40,34,124,34,41,41,44,116,61,75,46,116,101,115,116,40,97,46,99,111,109,112,97,
        114,101,68,111,99,117,109,101,110,116,80,111,115,105,116,105,111,110,41,44,121,61,116,124,124,75,46,116,101,115,116,40,97,46,99,111,110,116,97,105,110,115,41,63,102,117,110,99,116,105,111,110,40,
        101,44,116,41,123,118,97,114,32,110,61,57,61,61,61,101,46,110,111,100,101,84,121,112,101,63,101,46,100,111,99,117,109,101,110,116,69,108,101,109,101,110,116,58,101,44,114,61,116,38,38,116,46,112,
        97,114,101,110,116,78,111,100,101,59,114,101,116,117,114,110,32,101,61,61,61,114,124,124,33,40,33,114,124,124,49,33,61,61,114,46,110,111,100,101,84,121,112,101,124,124,33,40,110,46,99,111,110,116,
        97,105,110,115,63,110,46,99,111,110,116,97,105,110,115,40,114,41,58,101,46,99,111,109,112,97,114,101,68,111,99,117,109,101,110,116,80,111,115,105,116,105,111,110,38,38,49,54,38,101,46,99,111,109,
        112,97,114,101,68,111,99,117,109,101,110,116,80,111,115,105,116,105,111,110,40,114,41,41,41,125,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,105,102,40,116,41,119,104,105,108,101,40,116,
        61,116,46,112,97,114,101,110,116,78,111,100,101,41,105,102,40,116,61,61,61,101,41,114,101,116,117,114,110,33,48,59,114,101,116,117,114,110,33,49,125,44,106,61,116,63,102,117,110,99,116,105,111,110,
        40,101,44,116,41,123,105,102,40,101,61,61,61,116,41,114,101,116,117,114,110,32,108,61,33,48,44,48,59,118,97,114,32,110,61,33,101,46,99,111,109,112,97,114,101,68,111,99,117,109,101,110,116,80,111,
        115,105,116,105,111,110,45,33,116,46,99,111,109,112,97,114,101,68,111,99,117,109,101,110,116,80,111,115,105,116,105,111,110,59,114,101,116,117,114,110,32,110,124,124,40,49,38,40,110,61,40,101,46,
        111,119,110,101,114,68,111,99,117,109,101,110,116,124,124,101,41,61,61,40,116,46,111,119,110,101,114,68,111,99,117,109,101,110,116,124,124,116,41,63,101,46,99,111,109,112,97,114,101,68,111,99,117,
        109,101,110,116,80,111,115,105,116,105,111,110,40,116,41,58,49,41,124,124,33,100,46,115,111,114,116,68,101,116,97,99,104,101,100,38,38,116,46,99,111,109,112,97,114,101,68,111,99,117,109,101,110,
        116,80,111,115,105,116,105,111,110,40,101,41,61,61,61,110,63,101,61,61,67,124,124,101,46,111,119,110,101,114,68,111,99,117,109,101,110,116,61,61,112,38,38,121,40,112,44,101,41,63,45,49,58,116,61,
        61,67,124,124,116,46,111,119,110,101,114,68,111,99,117,109,101,110,116,61,61,112,38,38,121,40,112,44,116,41,63,49,58,117,63,80,40,117,44,101,41,45,80,40,117,44,116,41,58,48,58,52,38,110,63,45,49,
        58,49,41,125,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,105,102,40,101,61,61,61,116,41,114,101,116,117,114,110,32,108,61,33,48,44,48,59,118,97,114,32,110,44,114,61,48,44,105,61,101,46,
        112,97,114,101,110,116,78,111,100,101,44,111,61,116,46,112,97,114,101,110,116,78,111,100,101,44,97,61,91,101,93,44,115,61,91,116,93,59,105,102,40,33,105,124,124,33,111,41,114,101,116,117,114,110,
        32,101,61,61,67,63,45,49,58,116,61,61,67,63,49,58,105,63,45,49,58,111,63,49,58,117,63,80,40,117,44,101,41,45,80,40,117,44,116,41,58,48,59,105,102,40,105,61,61,61,111,41,114,101,116,117,114,110,32,
        112,101,40,101,44,116,41,59,110,61,101,59,119,104,105,108,101,40,110,61,110,46,112,97,114,101,110,116,78,111,100,101,41,97,46,117,110,115,104,105,102,116,40,110,41,59,110,61,116,59,119,104,105,108,
        101,40,110,61,110,46,112,97,114,101,110,116,78,111,100,101,41,115,46,117,110,115,104,105,102,116,40,110,41,59,119,104,105,108,101,40,97,91,114,93,61,61,61,115,91,114,93,41,114,43,43,59,114,101,116,
        117,114,110,32,114,63,112,101,40,97,91,114,93,44,115,91,114,93,41,58,97,91,114,93,61,61,112,63,45,49,58,115,91,114,93,61,61,112,63,49,58,48,125,41,44,67,125,44,115,101,46,109,97,116,99,104,101,115,
        61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,115,101,40,101,44,110,117,108,108,44,110,117,108,108,44,116,41,125,44,115,101,46,109,97,116,99,104,101,115,83,101,
        108,101,99,116,111,114,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,105,102,40,84,40,101,41,44,100,46,109,97,116,99,104,101,115,83,101,108,101,99,116,111,114,38,38,69,38,38,33,78,91,116,
        43,34,32,34,93,38,38,40,33,115,124,124,33,115,46,116,101,115,116,40,116,41,41,38,38,40,33,118,124,124,33,118,46,116,101,115,116,40,116,41,41,41,116,114,121,123,118,97,114,32,110,61,99,46,99,97,108,
        108,40,101,44,116,41,59,105,102,40,110,124,124,100,46,100,105,115,99,111,110,110,101,99,116,101,100,77,97,116,99,104,124,124,101,46,100,111,99,117,109,101,110,116,38,38,49,49,33,61,61,101,46,100,
        111,99,117,109,101,110,116,46,110,111,100,101,84,121,112,101,41,114,101,116,117,114,110,32,110,125,99,97,116,99,104,40,101,41,123,78,40,116,44,33,48,41,125,114,101,116,117,114,110,32,48,60,115,101,
        40,116,44,67,44,110,117,108,108,44,91,101,93,41,46,108,101,110,103,116,104,125,44,115,101,46,99,111,110,116,97,105,110,115,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,
        114,110,40,101,46,111,119,110,101,114,68,111,99,117,109,101,110,116,124,124,101,41,33,61,67,38,38,84,40,101,41,44,121,40,101,44,116,41,125,44,115,101,46,97,116,116,114,61,102,117,110,99,116,105,
        111,110,40,101,44,116,41,123,40,101,46,111,119,110,101,114,68,111,99,117,109,101,110,116,124,124,101,41,33,61,67,38,38,84,40,101,41,59,118,97,114,32,110,61,98,46,97,116,116,114,72,97,110,100,108,
        101,91,116,46,116,111,76,111,119,101,114,67,97,115,101,40,41,93,44,114,61,110,38,38,68,46,99,97,108,108,40,98,46,97,116,116,114,72,97,110,100,108,101,44,116,46,116,111,76,111,119,101,114,67,97,115,
        101,40,41,41,63,110,40,101,44,116,44,33,69,41,58,118,111,105,100,32,48,59,114,101,116,117,114,110,32,118,111,105,100,32,48,33,61,61,114,63,114,58,100,46,97,116,116,114,105,98,117,116,101,115,124,
        124,33,69,63,101,46,103,101,116,65,116,116,114,105,98,117,116,101,40,116,41,58,40,114,61,101,46,103,101,116,65,116,116,114,105,98,117,116,101,78,111,100,101,40,116,41,41,38,38,114,46,115,112,101,
        99,105,102,105,101,100,63,114,46,118,97,108,117,101,58,110,117,108,108,125,44,115,101,46,101,115,99,97,112,101,61,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,40,101,43,34,
        34,41,46,114,101,112,108,97,99,101,40,114,101,44,105,101,41,125,44,115,101,46,101,114,114,111,114,61,102,117,110,99,116,105,111,110,40,101,41,123,116,104,114,111,119,32,110,101,119,32,69,114,114,
        111,114,40,34,83,121,110,116,97,120,32,101,114,114,111,114,44,32,117,110,114,101,99,111,103,110,105,122,101,100,32,101,120,112,114,101,115,115,105,111,110,58,32,34,43,101,41,125,44,115,101,46,117,
        110,105,113,117,101,83,111,114,116,61,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,44,110,61,91,93,44,114,61,48,44,105,61,48,59,105,102,40,108,61,33,100,46,100,101,116,101,99,116,
        68,117,112,108,105,99,97,116,101,115,44,117,61,33,100,46,115,111,114,116,83,116,97,98,108,101,38,38,101,46,115,108,105,99,101,40,48,41,44,101,46,115,111,114,116,40,106,41,44,108,41,123,119,104,105,
        108,101,40,116,61,101,91,105,43,43,93,41,116,61,61,61,101,91,105,93,38,38,40,114,61,110,46,112,117,115,104,40,105,41,41,59,119,104,105,108,101,40,114,45,45,41,101,46,115,112,108,105,99,101,40,110,
        91,114,93,44,49,41,125,114,101,116,117,114,110,32,117,61,110,117,108,108,44,101,125,44,111,61,115,101,46,103,101,116,84,101,120,116,61,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,
        116,44,110,61,34,34,44,114,61,48,44,105,61,101,46,110,111,100,101,84,121,112,101,59,105,102,40,105,41,123,105,102,40,49,61,61,61,105,124,124,57,61,61,61,105,124,124,49,49,61,61,61,105,41,123,105,
        102,40,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,101,46,116,101,120,116,67,111,110,116,101,110,116,41,114,101,116,117,114,110,32,101,46,116,101,120,116,67,111,110,116,101,110,
        116,59,102,111,114,40,101,61,101,46,102,105,114,115,116,67,104,105,108,100,59,101,59,101,61,101,46,110,101,120,116,83,105,98,108,105,110,103,41,110,43,61,111,40,101,41,125,101,108,115,101,32,105,
        102,40,51,61,61,61,105,124,124,52,61,61,61,105,41,114,101,116,117,114,110,32,101,46,110,111,100,101,86,97,108,117,101,125,101,108,115,101,32,119,104,105,108,101,40,116,61,101,91,114,43,43,93,41,
        110,43,61,111,40,116,41,59,114,101,116,117,114,110,32,110,125,44,40,98,61,115,101,46,115,101,108,101,99,116,111,114,115,61,123,99,97,99,104,101,76,101,110,103,116,104,58,53,48,44,99,114,101,97,116,
        101,80,115,101,117,100,111,58,108,101,44,109,97,116,99,104,58,71,44,97,116,116,114,72,97,110,100,108,101,58,123,125,44,102,105,110,100,58,123,125,44,114,101,108,97,116,105,118,101,58,123,34,62,34,
        58,123,100,105,114,58,34,112,97,114,101,110,116,78,111,100,101,34,44,102,105,114,115,116,58,33,48,125,44,34,32,34,58,123,100,105,114,58,34,112,97,114,101,110,116,78,111,100,101,34,125,44,34,43,34,
        58,123,100,105,114,58,34,112,114,101,118,105,111,117,115,83,105,98,108,105,110,103,34,44,102,105,114,115,116,58,33,48,125,44,34,126,34,58,123,100,105,114,58,34,112,114,101,118,105,111,117,115,83,
        105,98,108,105,110,103,34,125,125,44,112,114,101,70,105,108,116,101,114,58,123,65,84,84,82,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,91,49,93,61,101,91,49,93,
        46,114,101,112,108,97,99,101,40,116,101,44,110,101,41,44,101,91,51,93,61,40,101,91,51,93,124,124,101,91,52,93,124,124,101,91,53,93,124,124,34,34,41,46,114,101,112,108,97,99,101,40,116,101,44,110,
        101,41,44,34,126,61,34,61,61,61,101,91,50,93,38,38,40,101,91,51,93,61,34,32,34,43,101,91,51,93,43,34,32,34,41,44,101,46,115,108,105,99,101,40,48,44,52,41,125,44,67,72,73,76,68,58,102,117,110,99,
        116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,91,49,93,61,101,91,49,93,46,116,111,76,111,119,101,114,67,97,115,101,40,41,44,34,110,116,104,34,61,61,61,101,91,49,93,46,115,108,105,
        99,101,40,48,44,51,41,63,40,101,91,51,93,124,124,115,101,46,101,114,114,111,114,40,101,91,48,93,41,44,101,91,52,93,61,43,40,101,91,52,93,63,101,91,53,93,43,40,101,91,54,93,124,124,49,41,58,50,42,
        40,34,101,118,101,110,34,61,61,61,101,91,51,93,124,124,34,111,100,100,34,61,61,61,101,91,51,93,41,41,44,101,91,53,93,61,43,40,101,91,55,93,43,101,91,56,93,124,124,34,111,100,100,34,61,61,61,101,
        91,51,93,41,41,58,101,91,51,93,38,38,115,101,46,101,114,114,111,114,40,101,91,48,93,41,44,101,125,44,80,83,69,85,68,79,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,44,110,61,
        33,101,91,54,93,38,38,101,91,50,93,59,114,101,116,117,114,110,32,71,46,67,72,73,76,68,46,116,101,115,116,40,101,91,48,93,41,63,110,117,108,108,58,40,101,91,51,93,63,101,91,50,93,61,101,91,52,93,
        124,124,101,91,53,93,124,124,34,34,58,110,38,38,88,46,116,101,115,116,40,110,41,38,38,40,116,61,104,40,110,44,33,48,41,41,38,38,40,116,61,110,46,105,110,100,101,120,79,102,40,34,41,34,44,110,46,
        108,101,110,103,116,104,45,116,41,45,110,46,108,101,110,103,116,104,41,38,38,40,101,91,48,93,61,101,91,48,93,46,115,108,105,99,101,40,48,44,116,41,44,101,91,50,93,61,110,46,115,108,105,99,101,40,
        48,44,116,41,41,44,101,46,115,108,105,99,101,40,48,44,51,41,41,125,125,44,102,105,108,116,101,114,58,123,84,65,71,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,101,46,114,
        101,112,108,97,99,101,40,116,101,44,110,101,41,46,116,111,76,111,119,101,114,67,97,115,101,40,41,59,114,101,116,117,114,110,34,42,34,61,61,61,101,63,102,117,110,99,116,105,111,110,40,41,123,114,
        101,116,117,114,110,33,48,125,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,46,110,111,100,101,78,97,109,101,38,38,101,46,110,111,100,101,78,97,109,101,46,116,111,
        76,111,119,101,114,67,97,115,101,40,41,61,61,61,116,125,125,44,67,76,65,83,83,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,109,91,101,43,34,32,34,93,59,114,101,116,117,114,
        110,32,116,124,124,40,116,61,110,101,119,32,82,101,103,69,120,112,40,34,40,94,124,34,43,77,43,34,41,34,43,101,43,34,40,34,43,77,43,34,124,36,41,34,41,41,38,38,109,40,101,44,102,117,110,99,116,105,
        111,110,40,101,41,123,114,101,116,117,114,110,32,116,46,116,101,115,116,40,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,101,46,99,108,97,115,115,78,97,109,101,38,38,101,46,99,108,
        97,115,115,78,97,109,101,124,124,34,117,110,100,101,102,105,110,101,100,34,33,61,116,121,112,101,111,102,32,101,46,103,101,116,65,116,116,114,105,98,117,116,101,38,38,101,46,103,101,116,65,116,116,
        114,105,98,117,116,101,40,34,99,108,97,115,115,34,41,124,124,34,34,41,125,41,125,44,65,84,84,82,58,102,117,110,99,116,105,111,110,40,110,44,114,44,105,41,123,114,101,116,117,114,110,32,102,117,110,
        99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,115,101,46,97,116,116,114,40,101,44,110,41,59,114,101,116,117,114,110,32,110,117,108,108,61,61,116,63,34,33,61,34,61,61,61,114,58,33,114,124,
        124,40,116,43,61,34,34,44,34,61,34,61,61,61,114,63,116,61,61,61,105,58,34,33,61,34,61,61,61,114,63,116,33,61,61,105,58,34,94,61,34,61,61,61,114,63,105,38,38,48,61,61,61,116,46,105,110,100,101,120,
        79,102,40,105,41,58,34,42,61,34,61,61,61,114,63,105,38,38,45,49,60,116,46,105,110,100,101,120,79,102,40,105,41,58,34,36,61,34,61,61,61,114,63,105,38,38,116,46,115,108,105,99,101,40,45,105,46,108,
        101,110,103,116,104,41,61,61,61,105,58,34,126,61,34,61,61,61,114,63,45,49,60,40,34,32,34,43,116,46,114,101,112,108,97,99,101,40,66,44,34,32,34,41,43,34,32,34,41,46,105,110,100,101,120,79,102,40,
        105,41,58,34,124,61,34,61,61,61,114,38,38,40,116,61,61,61,105,124,124,116,46,115,108,105,99,101,40,48,44,105,46,108,101,110,103,116,104,43,49,41,61,61,61,105,43,34,45,34,41,41,125,125,44,67,72,73,
        76,68,58,102,117,110,99,116,105,111,110,40,104,44,101,44,116,44,103,44,118,41,123,118,97,114,32,121,61,34,110,116,104,34,33,61,61,104,46,115,108,105,99,101,40,48,44,51,41,44,109,61,34,108,97,115,
        116,34,33,61,61,104,46,115,108,105,99,101,40,45,52,41,44,120,61,34,111,102,45,116,121,112,101,34,61,61,61,101,59,114,101,116,117,114,110,32,49,61,61,61,103,38,38,48,61,61,61,118,63,102,117,110,99,
        116,105,111,110,40,101,41,123,114,101,116,117,114,110,33,33,101,46,112,97,114,101,110,116,78,111,100,101,125,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,44,105,
        44,111,44,97,44,115,44,117,44,108,61,121,33,61,61,109,63,34,110,101,120,116,83,105,98,108,105,110,103,34,58,34,112,114,101,118,105,111,117,115,83,105,98,108,105,110,103,34,44,99,61,101,46,112,97,
        114,101,110,116,78,111,100,101,44,102,61,120,38,38,101,46,110,111,100,101,78,97,109,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,44,112,61,33,110,38,38,33,120,44,100,61,33,49,59,105,102,
        40,99,41,123,105,102,40,121,41,123,119,104,105,108,101,40,108,41,123,97,61,101,59,119,104,105,108,101,40,97,61,97,91,108,93,41,105,102,40,120,63,97,46,110,111,100,101,78,97,109,101,46,116,111,76,
        111,119,101,114,67,97,115,101,40,41,61,61,61,102,58,49,61,61,61,97,46,110,111,100,101,84,121,112,101,41,114,101,116,117,114,110,33,49,59,117,61,108,61,34,111,110,108,121,34,61,61,61,104,38,38,33,
        117,38,38,34,110,101,120,116,83,105,98,108,105,110,103,34,125,114,101,116,117,114,110,33,48,125,105,102,40,117,61,91,109,63,99,46,102,105,114,115,116,67,104,105,108,100,58,99,46,108,97,115,116,67,
        104,105,108,100,93,44,109,38,38,112,41,123,100,61,40,115,61,40,114,61,40,105,61,40,111,61,40,97,61,99,41,91,83,93,124,124,40,97,91,83,93,61,123,125,41,41,91,97,46,117,110,105,113,117,101,73,68,93,
        124,124,40,111,91,97,46,117,110,105,113,117,101,73,68,93,61,123,125,41,41,91,104,93,124,124,91,93,41,91,48,93,61,61,61,107,38,38,114,91,49,93,41,38,38,114,91,50,93,44,97,61,115,38,38,99,46,99,104,
        105,108,100,78,111,100,101,115,91,115,93,59,119,104,105,108,101,40,97,61,43,43,115,38,38,97,38,38,97,91,108,93,124,124,40,100,61,115,61,48,41,124,124,117,46,112,111,112,40,41,41,105,102,40,49,61,
        61,61,97,46,110,111,100,101,84,121,112,101,38,38,43,43,100,38,38,97,61,61,61,101,41,123,105,91,104,93,61,91,107,44,115,44,100,93,59,98,114,101,97,107,125,125,101,108,115,101,32,105,102,40,112,38,
        38,40,100,61,115,61,40,114,61,40,105,61,40,111,61,40,97,61,101,41,91,83,93,124,124,40,97,91,83,93,61,123,125,41,41,91,97,46,117,110,105,113,117,101,73,68,93,124,124,40,111,91,97,46,117,110,105,113,
        117,101,73,68,93,61,123,125,41,41,91,104,93,124,124,91,93,41,91,48,93,61,61,61,107,38,38,114,91,49,93,41,44,33,49,61,61,61,100,41,119,104,105,108,101,40,97,61,43,43,115,38,38,97,38,38,97,91,108,
        93,124,124,40,100,61,115,61,48,41,124,124,117,46,112,111,112,40,41,41,105,102,40,40,120,63,97,46,110,111,100,101,78,97,109,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,61,61,61,102,58,49,
        61,61,61,97,46,110,111,100,101,84,121,112,101,41,38,38,43,43,100,38,38,40,112,38,38,40,40,105,61,40,111,61,97,91,83,93,124,124,40,97,91,83,93,61,123,125,41,41,91,97,46,117,110,105,113,117,101,73,
        68,93,124,124,40,111,91,97,46,117,110,105,113,117,101,73,68,93,61,123,125,41,41,91,104,93,61,91,107,44,100,93,41,44,97,61,61,61,101,41,41,98,114,101,97,107,59,114,101,116,117,114,110,40,100,45,61,
        118,41,61,61,61,103,124,124,100,37,103,61,61,48,38,38,48,60,61,100,47,103,125,125,125,44,80,83,69,85,68,79,58,102,117,110,99,116,105,111,110,40,101,44,111,41,123,118,97,114,32,116,44,97,61,98,46,
        112,115,101,117,100,111,115,91,101,93,124,124,98,46,115,101,116,70,105,108,116,101,114,115,91,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,93,124,124,115,101,46,101,114,114,111,114,40,34,
        117,110,115,117,112,112,111,114,116,101,100,32,112,115,101,117,100,111,58,32,34,43,101,41,59,114,101,116,117,114,110,32,97,91,83,93,63,97,40,111,41,58,49,60,97,46,108,101,110,103,116,104,63,40,116,
        61,91,101,44,101,44,34,34,44,111,93,44,98,46,115,101,116,70,105,108,116,101,114,115,46,104,97,115,79,119,110,80,114,111,112,101,114,116,121,40,101,46,116,111,76,111,119,101,114,67,97,115,101,40,
        41,41,63,108,101,40,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,44,114,61,97,40,101,44,111,41,44,105,61,114,46,108,101,110,103,116,104,59,119,104,105,108,101,40,105,45,
        45,41,101,91,110,61,80,40,101,44,114,91,105,93,41,93,61,33,40,116,91,110,93,61,114,91,105,93,41,125,41,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,97,40,101,44,48,
        44,116,41,125,41,58,97,125,125,44,112,115,101,117,100,111,115,58,123,110,111,116,58,108,101,40,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,114,61,91,93,44,105,61,91,93,44,115,61,102,
        40,101,46,114,101,112,108,97,99,101,40,36,44,34,36,49,34,41,41,59,114,101,116,117,114,110,32,115,91,83,93,63,108,101,40,102,117,110,99,116,105,111,110,40,101,44,116,44,110,44,114,41,123,118,97,114,
        32,105,44,111,61,115,40,101,44,110,117,108,108,44,114,44,91,93,41,44,97,61,101,46,108,101,110,103,116,104,59,119,104,105,108,101,40,97,45,45,41,40,105,61,111,91,97,93,41,38,38,40,101,91,97,93,61,
        33,40,116,91,97,93,61,105,41,41,125,41,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,114,101,116,117,114,110,32,114,91,48,93,61,101,44,115,40,114,44,110,117,108,108,44,110,44,105,
        41,44,114,91,48,93,61,110,117,108,108,44,33,105,46,112,111,112,40,41,125,125,41,44,104,97,115,58,108,101,40,102,117,110,99,116,105,111,110,40,116,41,123,114,101,116,117,114,110,32,102,117,110,99,
        116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,48,60,115,101,40,116,44,101,41,46,108,101,110,103,116,104,125,125,41,44,99,111,110,116,97,105,110,115,58,108,101,40,102,117,110,99,116,105,
        111,110,40,116,41,123,114,101,116,117,114,110,32,116,61,116,46,114,101,112,108,97,99,101,40,116,101,44,110,101,41,44,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,45,49,60,
        40,101,46,116,101,120,116,67,111,110,116,101,110,116,124,124,111,40,101,41,41,46,105,110,100,101,120,79,102,40,116,41,125,125,41,44,108,97,110,103,58,108,101,40,102,117,110,99,116,105,111,110,40,
        110,41,123,114,101,116,117,114,110,32,86,46,116,101,115,116,40,110,124,124,34,34,41,124,124,115,101,46,101,114,114,111,114,40,34,117,110,115,117,112,112,111,114,116,101,100,32,108,97,110,103,58,
        32,34,43,110,41,44,110,61,110,46,114,101,112,108,97,99,101,40,116,101,44,110,101,41,46,116,111,76,111,119,101,114,67,97,115,101,40,41,44,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,
        116,59,100,111,123,105,102,40,116,61,69,63,101,46,108,97,110,103,58,101,46,103,101,116,65,116,116,114,105,98,117,116,101,40,34,120,109,108,58,108,97,110,103,34,41,124,124,101,46,103,101,116,65,116,
        116,114,105,98,117,116,101,40,34,108,97,110,103,34,41,41,114,101,116,117,114,110,40,116,61,116,46,116,111,76,111,119,101,114,67,97,115,101,40,41,41,61,61,61,110,124,124,48,61,61,61,116,46,105,110,
        100,101,120,79,102,40,110,43,34,45,34,41,125,119,104,105,108,101,40,40,101,61,101,46,112,97,114,101,110,116,78,111,100,101,41,38,38,49,61,61,61,101,46,110,111,100,101,84,121,112,101,41,59,114,101,
        116,117,114,110,33,49,125,125,41,44,116,97,114,103,101,116,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,110,46,108,111,99,97,116,105,111,110,38,38,110,46,108,111,99,97,116,
        105,111,110,46,104,97,115,104,59,114,101,116,117,114,110,32,116,38,38,116,46,115,108,105,99,101,40,49,41,61,61,61,101,46,105,100,125,44,114,111,111,116,58,102,117,110,99,116,105,111,110,40,101,41,
        123,114,101,116,117,114,110,32,101,61,61,61,97,125,44,102,111,99,117,115,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,61,61,61,67,46,97,99,116,105,118,101,69,108,
        101,109,101,110,116,38,38,40,33,67,46,104,97,115,70,111,99,117,115,124,124,67,46,104,97,115,70,111,99,117,115,40,41,41,38,38,33,33,40,101,46,116,121,112,101,124,124,101,46,104,114,101,102,124,124,
        126,101,46,116,97,98,73,110,100,101,120,41,125,44,101,110,97,98,108,101,100,58,103,101,40,33,49,41,44,100,105,115,97,98,108,101,100,58,103,101,40,33,48,41,44,99,104,101,99,107,101,100,58,102,117,
        110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,101,46,110,111,100,101,78,97,109,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,59,114,101,116,117,114,110,34,105,110,112,117,116,
        34,61,61,61,116,38,38,33,33,101,46,99,104,101,99,107,101,100,124,124,34,111,112,116,105,111,110,34,61,61,61,116,38,38,33,33,101,46,115,101,108,101,99,116,101,100,125,44,115,101,108,101,99,116,101,
        100,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,46,112,97,114,101,110,116,78,111,100,101,38,38,101,46,112,97,114,101,110,116,78,111,100,101,46,115,101,108,101,
        99,116,101,100,73,110,100,101,120,44,33,48,61,61,61,101,46,115,101,108,101,99,116,101,100,125,44,101,109,112,116,121,58,102,117,110,99,116,105,111,110,40,101,41,123,102,111,114,40,101,61,101,46,
        102,105,114,115,116,67,104,105,108,100,59,101,59,101,61,101,46,110,101,120,116,83,105,98,108,105,110,103,41,105,102,40,101,46,110,111,100,101,84,121,112,101,60,54,41,114,101,116,117,114,110,33,49,
        59,114,101,116,117,114,110,33,48,125,44,112,97,114,101,110,116,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,33,98,46,112,115,101,117,100,111,115,46,101,109,112,116,121,
        40,101,41,125,44,104,101,97,100,101,114,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,74,46,116,101,115,116,40,101,46,110,111,100,101,78,97,109,101,41,125,44,105,110,
        112,117,116,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,81,46,116,101,115,116,40,101,46,110,111,100,101,78,97,109,101,41,125,44,98,117,116,116,111,110,58,102,117,110,
        99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,101,46,110,111,100,101,78,97,109,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,59,114,101,116,117,114,110,34,105,110,112,117,116,34,
        61,61,61,116,38,38,34,98,117,116,116,111,110,34,61,61,61,101,46,116,121,112,101,124,124,34,98,117,116,116,111,110,34,61,61,61,116,125,44,116,101,120,116,58,102,117,110,99,116,105,111,110,40,101,
        41,123,118,97,114,32,116,59,114,101,116,117,114,110,34,105,110,112,117,116,34,61,61,61,101,46,110,111,100,101,78,97,109,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,38,38,34,116,101,120,
        116,34,61,61,61,101,46,116,121,112,101,38,38,40,110,117,108,108,61,61,40,116,61,101,46,103,101,116,65,116,116,114,105,98,117,116,101,40,34,116,121,112,101,34,41,41,124,124,34,116,101,120,116,34,
        61,61,61,116,46,116,111,76,111,119,101,114,67,97,115,101,40,41,41,125,44,102,105,114,115,116,58,118,101,40,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,91,48,93,125,41,44,108,
        97,115,116,58,118,101,40,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,91,116,45,49,93,125,41,44,101,113,58,118,101,40,102,117,110,99,116,105,111,110,40,101,44,116,
        44,110,41,123,114,101,116,117,114,110,91,110,60,48,63,110,43,116,58,110,93,125,41,44,101,118,101,110,58,118,101,40,102,117,110,99,116,105,111,110,40,101,44,116,41,123,102,111,114,40,118,97,114,32,
        110,61,48,59,110,60,116,59,110,43,61,50,41,101,46,112,117,115,104,40,110,41,59,114,101,116,117,114,110,32,101,125,41,44,111,100,100,58,118,101,40,102,117,110,99,116,105,111,110,40,101,44,116,41,
        123,102,111,114,40,118,97,114,32,110,61,49,59,110,60,116,59,110,43,61,50,41,101,46,112,117,115,104,40,110,41,59,114,101,116,117,114,110,32,101,125,41,44,108,116,58,118,101,40,102,117,110,99,116,
        105,111,110,40,101,44,116,44,110,41,123,102,111,114,40,118,97,114,32,114,61,110,60,48,63,110,43,116,58,116,60,110,63,116,58,110,59,48,60,61,45,45,114,59,41,101,46,112,117,115,104,40,114,41,59,114,
        101,116,117,114,110,32,101,125,41,44,103,116,58,118,101,40,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,102,111,114,40,118,97,114,32,114,61,110,60,48,63,110,43,116,58,110,59,43,43,
        114,60,116,59,41,101,46,112,117,115,104,40,114,41,59,114,101,116,117,114,110,32,101,125,41,125,125,41,46,112,115,101,117,100,111,115,46,110,116,104,61,98,46,112,115,101,117,100,111,115,46,101,113,
        44,123,114,97,100,105,111,58,33,48,44,99,104,101,99,107,98,111,120,58,33,48,44,102,105,108,101,58,33,48,44,112,97,115,115,119,111,114,100,58,33,48,44,105,109,97,103,101,58,33,48,125,41,98,46,112,
        115,101,117,100,111,115,91,101,93,61,100,101,40,101,41,59,102,111,114,40,101,32,105,110,123,115,117,98,109,105,116,58,33,48,44,114,101,115,101,116,58,33,48,125,41,98,46,112,115,101,117,100,111,115,
        91,101,93,61,104,101,40,101,41,59,102,117,110,99,116,105,111,110,32,109,101,40,41,123,125,102,117,110,99,116,105,111,110,32,120,101,40,101,41,123,102,111,114,40,118,97,114,32,116,61,48,44,110,61,
        101,46,108,101,110,103,116,104,44,114,61,34,34,59,116,60,110,59,116,43,43,41,114,43,61,101,91,116,93,46,118,97,108,117,101,59,114,101,116,117,114,110,32,114,125,102,117,110,99,116,105,111,110,32,
        98,101,40,115,44,101,44,116,41,123,118,97,114,32,117,61,101,46,100,105,114,44,108,61,101,46,110,101,120,116,44,99,61,108,124,124,117,44,102,61,116,38,38,34,112,97,114,101,110,116,78,111,100,101,
        34,61,61,61,99,44,112,61,114,43,43,59,114,101,116,117,114,110,32,101,46,102,105,114,115,116,63,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,119,104,105,108,101,40,101,61,101,91,117,
        93,41,105,102,40,49,61,61,61,101,46,110,111,100,101,84,121,112,101,124,124,102,41,114,101,116,117,114,110,32,115,40,101,44,116,44,110,41,59,114,101,116,117,114,110,33,49,125,58,102,117,110,99,116,
        105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,44,105,44,111,44,97,61,91,107,44,112,93,59,105,102,40,110,41,123,119,104,105,108,101,40,101,61,101,91,117,93,41,105,102,40,40,49,61,61,61,
        101,46,110,111,100,101,84,121,112,101,124,124,102,41,38,38,115,40,101,44,116,44,110,41,41,114,101,116,117,114,110,33,48,125,101,108,115,101,32,119,104,105,108,101,40,101,61,101,91,117,93,41,105,
        102,40,49,61,61,61,101,46,110,111,100,101,84,121,112,101,124,124,102,41,105,102,40,105,61,40,111,61,101,91,83,93,124,124,40,101,91,83,93,61,123,125,41,41,91,101,46,117,110,105,113,117,101,73,68,
        93,124,124,40,111,91,101,46,117,110,105,113,117,101,73,68,93,61,123,125,41,44,108,38,38,108,61,61,61,101,46,110,111,100,101,78,97,109,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,41,101,
        61,101,91,117,93,124,124,101,59,101,108,115,101,123,105,102,40,40,114,61,105,91,99,93,41,38,38,114,91,48,93,61,61,61,107,38,38,114,91,49,93,61,61,61,112,41,114,101,116,117,114,110,32,97,91,50,93,
        61,114,91,50,93,59,105,102,40,40,105,91,99,93,61,97,41,91,50,93,61,115,40,101,44,116,44,110,41,41,114,101,116,117,114,110,33,48,125,114,101,116,117,114,110,33,49,125,125,102,117,110,99,116,105,111,
        110,32,119,101,40,105,41,123,114,101,116,117,114,110,32,49,60,105,46,108,101,110,103,116,104,63,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,61,105,46,108,101,110,
        103,116,104,59,119,104,105,108,101,40,114,45,45,41,105,102,40,33,105,91,114,93,40,101,44,116,44,110,41,41,114,101,116,117,114,110,33,49,59,114,101,116,117,114,110,33,48,125,58,105,91,48,93,125,102,
        117,110,99,116,105,111,110,32,84,101,40,101,44,116,44,110,44,114,44,105,41,123,102,111,114,40,118,97,114,32,111,44,97,61,91,93,44,115,61,48,44,117,61,101,46,108,101,110,103,116,104,44,108,61,110,
        117,108,108,33,61,116,59,115,60,117,59,115,43,43,41,40,111,61,101,91,115,93,41,38,38,40,110,38,38,33,110,40,111,44,114,44,105,41,124,124,40,97,46,112,117,115,104,40,111,41,44,108,38,38,116,46,112,
        117,115,104,40,115,41,41,41,59,114,101,116,117,114,110,32,97,125,102,117,110,99,116,105,111,110,32,67,101,40,100,44,104,44,103,44,118,44,121,44,101,41,123,114,101,116,117,114,110,32,118,38,38,33,
        118,91,83,93,38,38,40,118,61,67,101,40,118,41,41,44,121,38,38,33,121,91,83,93,38,38,40,121,61,67,101,40,121,44,101,41,41,44,108,101,40,102,117,110,99,116,105,111,110,40,101,44,116,44,110,44,114,
        41,123,118,97,114,32,105,44,111,44,97,44,115,61,91,93,44,117,61,91,93,44,108,61,116,46,108,101,110,103,116,104,44,99,61,101,124,124,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,102,
        111,114,40,118,97,114,32,114,61,48,44,105,61,116,46,108,101,110,103,116,104,59,114,60,105,59,114,43,43,41,115,101,40,101,44,116,91,114,93,44,110,41,59,114,101,116,117,114,110,32,110,125,40,104,124,
        124,34,42,34,44,110,46,110,111,100,101,84,121,112,101,63,91,110,93,58,110,44,91,93,41,44,102,61,33,100,124,124,33,101,38,38,104,63,99,58,84,101,40,99,44,115,44,100,44,110,44,114,41,44,112,61,103,
        63,121,124,124,40,101,63,100,58,108,124,124,118,41,63,91,93,58,116,58,102,59,105,102,40,103,38,38,103,40,102,44,112,44,110,44,114,41,44,118,41,123,105,61,84,101,40,112,44,117,41,44,118,40,105,44,
        91,93,44,110,44,114,41,44,111,61,105,46,108,101,110,103,116,104,59,119,104,105,108,101,40,111,45,45,41,40,97,61,105,91,111,93,41,38,38,40,112,91,117,91,111,93,93,61,33,40,102,91,117,91,111,93,93,
        61,97,41,41,125,105,102,40,101,41,123,105,102,40,121,124,124,100,41,123,105,102,40,121,41,123,105,61,91,93,44,111,61,112,46,108,101,110,103,116,104,59,119,104,105,108,101,40,111,45,45,41,40,97,61,
        112,91,111,93,41,38,38,105,46,112,117,115,104,40,102,91,111,93,61,97,41,59,121,40,110,117,108,108,44,112,61,91,93,44,105,44,114,41,125,111,61,112,46,108,101,110,103,116,104,59,119,104,105,108,101,
        40,111,45,45,41,40,97,61,112,91,111,93,41,38,38,45,49,60,40,105,61,121,63,80,40,101,44,97,41,58,115,91,111,93,41,38,38,40,101,91,105,93,61,33,40,116,91,105,93,61,97,41,41,125,125,101,108,115,101,
        32,112,61,84,101,40,112,61,61,61,116,63,112,46,115,112,108,105,99,101,40,108,44,112,46,108,101,110,103,116,104,41,58,112,41,44,121,63,121,40,110,117,108,108,44,116,44,112,44,114,41,58,72,46,97,112,
        112,108,121,40,116,44,112,41,125,41,125,102,117,110,99,116,105,111,110,32,69,101,40,101,41,123,102,111,114,40,118,97,114,32,105,44,116,44,110,44,114,61,101,46,108,101,110,103,116,104,44,111,61,98,
        46,114,101,108,97,116,105,118,101,91,101,91,48,93,46,116,121,112,101,93,44,97,61,111,124,124,98,46,114,101,108,97,116,105,118,101,91,34,32,34,93,44,115,61,111,63,49,58,48,44,117,61,98,101,40,102,
        117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,61,61,61,105,125,44,97,44,33,48,41,44,108,61,98,101,40,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,
        45,49,60,80,40,105,44,101,41,125,44,97,44,33,48,41,44,99,61,91,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,61,33,111,38,38,40,110,124,124,116,33,61,61,119,41,124,
        124,40,40,105,61,116,41,46,110,111,100,101,84,121,112,101,63,117,40,101,44,116,44,110,41,58,108,40,101,44,116,44,110,41,41,59,114,101,116,117,114,110,32,105,61,110,117,108,108,44,114,125,93,59,115,
        60,114,59,115,43,43,41,105,102,40,116,61,98,46,114,101,108,97,116,105,118,101,91,101,91,115,93,46,116,121,112,101,93,41,99,61,91,98,101,40,119,101,40,99,41,44,116,41,93,59,101,108,115,101,123,105,
        102,40,40,116,61,98,46,102,105,108,116,101,114,91,101,91,115,93,46,116,121,112,101,93,46,97,112,112,108,121,40,110,117,108,108,44,101,91,115,93,46,109,97,116,99,104,101,115,41,41,91,83,93,41,123,
        102,111,114,40,110,61,43,43,115,59,110,60,114,59,110,43,43,41,105,102,40,98,46,114,101,108,97,116,105,118,101,91,101,91,110,93,46,116,121,112,101,93,41,98,114,101,97,107,59,114,101,116,117,114,110,
        32,67,101,40,49,60,115,38,38,119,101,40,99,41,44,49,60,115,38,38,120,101,40,101,46,115,108,105,99,101,40,48,44,115,45,49,41,46,99,111,110,99,97,116,40,123,118,97,108,117,101,58,34,32,34,61,61,61,
        101,91,115,45,50,93,46,116,121,112,101,63,34,42,34,58,34,34,125,41,41,46,114,101,112,108,97,99,101,40,36,44,34,36,49,34,41,44,116,44,115,60,110,38,38,69,101,40,101,46,115,108,105,99,101,40,115,44,
        110,41,41,44,110,60,114,38,38,69,101,40,101,61,101,46,115,108,105,99,101,40,110,41,41,44,110,60,114,38,38,120,101,40,101,41,41,125,99,46,112,117,115,104,40,116,41,125,114,101,116,117,114,110,32,
        119,101,40,99,41,125,114,101,116,117,114,110,32,109,101,46,112,114,111,116,111,116,121,112,101,61,98,46,102,105,108,116,101,114,115,61,98,46,112,115,101,117,100,111,115,44,98,46,115,101,116,70,105,
        108,116,101,114,115,61,110,101,119,32,109,101,44,104,61,115,101,46,116,111,107,101,110,105,122,101,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,44,114,44,105,44,111,44,
        97,44,115,44,117,44,108,61,120,91,101,43,34,32,34,93,59,105,102,40,108,41,114,101,116,117,114,110,32,116,63,48,58,108,46,115,108,105,99,101,40,48,41,59,97,61,101,44,115,61,91,93,44,117,61,98,46,
        112,114,101,70,105,108,116,101,114,59,119,104,105,108,101,40,97,41,123,102,111,114,40,111,32,105,110,32,110,38,38,33,40,114,61,95,46,101,120,101,99,40,97,41,41,124,124,40,114,38,38,40,97,61,97,46,
        115,108,105,99,101,40,114,91,48,93,46,108,101,110,103,116,104,41,124,124,97,41,44,115,46,112,117,115,104,40,105,61,91,93,41,41,44,110,61,33,49,44,40,114,61,122,46,101,120,101,99,40,97,41,41,38,38,
        40,110,61,114,46,115,104,105,102,116,40,41,44,105,46,112,117,115,104,40,123,118,97,108,117,101,58,110,44,116,121,112,101,58,114,91,48,93,46,114,101,112,108,97,99,101,40,36,44,34,32,34,41,125,41,
        44,97,61,97,46,115,108,105,99,101,40,110,46,108,101,110,103,116,104,41,41,44,98,46,102,105,108,116,101,114,41,33,40,114,61,71,91,111,93,46,101,120,101,99,40,97,41,41,124,124,117,91,111,93,38,38,
        33,40,114,61,117,91,111,93,40,114,41,41,124,124,40,110,61,114,46,115,104,105,102,116,40,41,44,105,46,112,117,115,104,40,123,118,97,108,117,101,58,110,44,116,121,112,101,58,111,44,109,97,116,99,104,
        101,115,58,114,125,41,44,97,61,97,46,115,108,105,99,101,40,110,46,108,101,110,103,116,104,41,41,59,105,102,40,33,110,41,98,114,101,97,107,125,114,101,116,117,114,110,32,116,63,97,46,108,101,110,
        103,116,104,58,97,63,115,101,46,101,114,114,111,114,40,101,41,58,120,40,101,44,115,41,46,115,108,105,99,101,40,48,41,125,44,102,61,115,101,46,99,111,109,112,105,108,101,61,102,117,110,99,116,105,
        111,110,40,101,44,116,41,123,118,97,114,32,110,44,118,44,121,44,109,44,120,44,114,44,105,61,91,93,44,111,61,91,93,44,97,61,65,91,101,43,34,32,34,93,59,105,102,40,33,97,41,123,116,124,124,40,116,
        61,104,40,101,41,41,44,110,61,116,46,108,101,110,103,116,104,59,119,104,105,108,101,40,110,45,45,41,40,97,61,69,101,40,116,91,110,93,41,41,91,83,93,63,105,46,112,117,115,104,40,97,41,58,111,46,112,
        117,115,104,40,97,41,59,40,97,61,65,40,101,44,40,118,61,111,44,109,61,48,60,40,121,61,105,41,46,108,101,110,103,116,104,44,120,61,48,60,118,46,108,101,110,103,116,104,44,114,61,102,117,110,99,116,
        105,111,110,40,101,44,116,44,110,44,114,44,105,41,123,118,97,114,32,111,44,97,44,115,44,117,61,48,44,108,61,34,48,34,44,99,61,101,38,38,91,93,44,102,61,91,93,44,112,61,119,44,100,61,101,124,124,
        120,38,38,98,46,102,105,110,100,46,84,65,71,40,34,42,34,44,105,41,44,104,61,107,43,61,110,117,108,108,61,61,112,63,49,58,77,97,116,104,46,114,97,110,100,111,109,40,41,124,124,46,49,44,103,61,100,
        46,108,101,110,103,116,104,59,102,111,114,40,105,38,38,40,119,61,116,61,61,67,124,124,116,124,124,105,41,59,108,33,61,61,103,38,38,110,117,108,108,33,61,40,111,61,100,91,108,93,41,59,108,43,43,41,
        123,105,102,40,120,38,38,111,41,123,97,61,48,44,116,124,124,111,46,111,119,110,101,114,68,111,99,117,109,101,110,116,61,61,67,124,124,40,84,40,111,41,44,110,61,33,69,41,59,119,104,105,108,101,40,
        115,61,118,91,97,43,43,93,41,105,102,40,115,40,111,44,116,124,124,67,44,110,41,41,123,114,46,112,117,115,104,40,111,41,59,98,114,101,97,107,125,105,38,38,40,107,61,104,41,125,109,38,38,40,40,111,
        61,33,115,38,38,111,41,38,38,117,45,45,44,101,38,38,99,46,112,117,115,104,40,111,41,41,125,105,102,40,117,43,61,108,44,109,38,38,108,33,61,61,117,41,123,97,61,48,59,119,104,105,108,101,40,115,61,
        121,91,97,43,43,93,41,115,40,99,44,102,44,116,44,110,41,59,105,102,40,101,41,123,105,102,40,48,60,117,41,119,104,105,108,101,40,108,45,45,41,99,91,108,93,124,124,102,91,108,93,124,124,40,102,91,
        108,93,61,113,46,99,97,108,108,40,114,41,41,59,102,61,84,101,40,102,41,125,72,46,97,112,112,108,121,40,114,44,102,41,44,105,38,38,33,101,38,38,48,60,102,46,108,101,110,103,116,104,38,38,49,60,117,
        43,121,46,108,101,110,103,116,104,38,38,115,101,46,117,110,105,113,117,101,83,111,114,116,40,114,41,125,114,101,116,117,114,110,32,105,38,38,40,107,61,104,44,119,61,112,41,44,99,125,44,109,63,108,
        101,40,114,41,58,114,41,41,41,46,115,101,108,101,99,116,111,114,61,101,125,114,101,116,117,114,110,32,97,125,44,103,61,115,101,46,115,101,108,101,99,116,61,102,117,110,99,116,105,111,110,40,101,
        44,116,44,110,44,114,41,123,118,97,114,32,105,44,111,44,97,44,115,44,117,44,108,61,34,102,117,110,99,116,105,111,110,34,61,61,116,121,112,101,111,102,32,101,38,38,101,44,99,61,33,114,38,38,104,40,
        101,61,108,46,115,101,108,101,99,116,111,114,124,124,101,41,59,105,102,40,110,61,110,124,124,91,93,44,49,61,61,61,99,46,108,101,110,103,116,104,41,123,105,102,40,50,60,40,111,61,99,91,48,93,61,99,
        91,48,93,46,115,108,105,99,101,40,48,41,41,46,108,101,110,103,116,104,38,38,34,73,68,34,61,61,61,40,97,61,111,91,48,93,41,46,116,121,112,101,38,38,57,61,61,61,116,46,110,111,100,101,84,121,112,101,
        38,38,69,38,38,98,46,114,101,108,97,116,105,118,101,91,111,91,49,93,46,116,121,112,101,93,41,123,105,102,40,33,40,116,61,40,98,46,102,105,110,100,46,73,68,40,97,46,109,97,116,99,104,101,115,91,48,
        93,46,114,101,112,108,97,99,101,40,116,101,44,110,101,41,44,116,41,124,124,91,93,41,91,48,93,41,41,114,101,116,117,114,110,32,110,59,108,38,38,40,116,61,116,46,112,97,114,101,110,116,78,111,100,
        101,41,44,101,61,101,46,115,108,105,99,101,40,111,46,115,104,105,102,116,40,41,46,118,97,108,117,101,46,108,101,110,103,116,104,41,125,105,61,71,46,110,101,101,100,115,67,111,110,116,101,120,116,
        46,116,101,115,116,40,101,41,63,48,58,111,46,108,101,110,103,116,104,59,119,104,105,108,101,40,105,45,45,41,123,105,102,40,97,61,111,91,105,93,44,98,46,114,101,108,97,116,105,118,101,91,115,61,97,
        46,116,121,112,101,93,41,98,114,101,97,107,59,105,102,40,40,117,61,98,46,102,105,110,100,91,115,93,41,38,38,40,114,61,117,40,97,46,109,97,116,99,104,101,115,91,48,93,46,114,101,112,108,97,99,101,
        40,116,101,44,110,101,41,44,101,101,46,116,101,115,116,40,111,91,48,93,46,116,121,112,101,41,38,38,121,101,40,116,46,112,97,114,101,110,116,78,111,100,101,41,124,124,116,41,41,41,123,105,102,40,
        111,46,115,112,108,105,99,101,40,105,44,49,41,44,33,40,101,61,114,46,108,101,110,103,116,104,38,38,120,101,40,111,41,41,41,114,101,116,117,114,110,32,72,46,97,112,112,108,121,40,110,44,114,41,44,
        110,59,98,114,101,97,107,125,125,125,114,101,116,117,114,110,40,108,124,124,102,40,101,44,99,41,41,40,114,44,116,44,33,69,44,110,44,33,116,124,124,101,101,46,116,101,115,116,40,101,41,38,38,121,
        101,40,116,46,112,97,114,101,110,116,78,111,100,101,41,124,124,116,41,44,110,125,44,100,46,115,111,114,116,83,116,97,98,108,101,61,83,46,115,112,108,105,116,40,34,34,41,46,115,111,114,116,40,106,
        41,46,106,111,105,110,40,34,34,41,61,61,61,83,44,100,46,100,101,116,101,99,116,68,117,112,108,105,99,97,116,101,115,61,33,33,108,44,84,40,41,44,100,46,115,111,114,116,68,101,116,97,99,104,101,100,
        61,99,101,40,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,49,38,101,46,99,111,109,112,97,114,101,68,111,99,117,109,101,110,116,80,111,115,105,116,105,111,110,40,67,46,
        99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,102,105,101,108,100,115,101,116,34,41,41,125,41,44,99,101,40,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,46,
        105,110,110,101,114,72,84,77,76,61,34,60,97,32,104,114,101,102,61,39,35,39,62,60,47,97,62,34,44,34,35,34,61,61,61,101,46,102,105,114,115,116,67,104,105,108,100,46,103,101,116,65,116,116,114,105,
        98,117,116,101,40,34,104,114,101,102,34,41,125,41,124,124,102,101,40,34,116,121,112,101,124,104,114,101,102,124,104,101,105,103,104,116,124,119,105,100,116,104,34,44,102,117,110,99,116,105,111,110,
        40,101,44,116,44,110,41,123,105,102,40,33,110,41,114,101,116,117,114,110,32,101,46,103,101,116,65,116,116,114,105,98,117,116,101,40,116,44,34,116,121,112,101,34,61,61,61,116,46,116,111,76,111,119,
        101,114,67,97,115,101,40,41,63,49,58,50,41,125,41,44,100,46,97,116,116,114,105,98,117,116,101,115,38,38,99,101,40,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,46,105,
        110,110,101,114,72,84,77,76,61,34,60,105,110,112,117,116,47,62,34,44,101,46,102,105,114,115,116,67,104,105,108,100,46,115,101,116,65,116,116,114,105,98,117,116,101,40,34,118,97,108,117,101,34,44,
        34,34,41,44,34,34,61,61,61,101,46,102,105,114,115,116,67,104,105,108,100,46,103,101,116,65,116,116,114,105,98,117,116,101,40,34,118,97,108,117,101,34,41,125,41,124,124,102,101,40,34,118,97,108,117,
        101,34,44,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,105,102,40,33,110,38,38,34,105,110,112,117,116,34,61,61,61,101,46,110,111,100,101,78,97,109,101,46,116,111,76,111,119,101,114,
        67,97,115,101,40,41,41,114,101,116,117,114,110,32,101,46,100,101,102,97,117,108,116,86,97,108,117,101,125,41,44,99,101,40,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,
        110,117,108,108,61,61,101,46,103,101,116,65,116,116,114,105,98,117,116,101,40,34,100,105,115,97,98,108,101,100,34,41,125,41,124,124,102,101,40,82,44,102,117,110,99,116,105,111,110,40,101,44,116,
        44,110,41,123,118,97,114,32,114,59,105,102,40,33,110,41,114,101,116,117,114,110,33,48,61,61,61,101,91,116,93,63,116,46,116,111,76,111,119,101,114,67,97,115,101,40,41,58,40,114,61,101,46,103,101,
        116,65,116,116,114,105,98,117,116,101,78,111,100,101,40,116,41,41,38,38,114,46,115,112,101,99,105,102,105,101,100,63,114,46,118,97,108,117,101,58,110,117,108,108,125,41,44,115,101,125,40,67,41,59,
        83,46,102,105,110,100,61,100,44,83,46,101,120,112,114,61,100,46,115,101,108,101,99,116,111,114,115,44,83,46,101,120,112,114,91,34,58,34,93,61,83,46,101,120,112,114,46,112,115,101,117,100,111,115,
        44,83,46,117,110,105,113,117,101,83,111,114,116,61,83,46,117,110,105,113,117,101,61,100,46,117,110,105,113,117,101,83,111,114,116,44,83,46,116,101,120,116,61,100,46,103,101,116,84,101,120,116,44,
        83,46,105,115,88,77,76,68,111,99,61,100,46,105,115,88,77,76,44,83,46,99,111,110,116,97,105,110,115,61,100,46,99,111,110,116,97,105,110,115,44,83,46,101,115,99,97,112,101,83,101,108,101,99,116,111,
        114,61,100,46,101,115,99,97,112,101,59,118,97,114,32,104,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,61,91,93,44,105,61,118,111,105,100,32,48,33,61,61,110,59,
        119,104,105,108,101,40,40,101,61,101,91,116,93,41,38,38,57,33,61,61,101,46,110,111,100,101,84,121,112,101,41,105,102,40,49,61,61,61,101,46,110,111,100,101,84,121,112,101,41,123,105,102,40,105,38,
        38,83,40,101,41,46,105,115,40,110,41,41,98,114,101,97,107,59,114,46,112,117,115,104,40,101,41,125,114,101,116,117,114,110,32,114,125,44,84,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,
        102,111,114,40,118,97,114,32,110,61,91,93,59,101,59,101,61,101,46,110,101,120,116,83,105,98,108,105,110,103,41,49,61,61,61,101,46,110,111,100,101,84,121,112,101,38,38,101,33,61,61,116,38,38,110,
        46,112,117,115,104,40,101,41,59,114,101,116,117,114,110,32,110,125,44,107,61,83,46,101,120,112,114,46,109,97,116,99,104,46,110,101,101,100,115,67,111,110,116,101,120,116,59,102,117,110,99,116,105,
        111,110,32,65,40,101,44,116,41,123,114,101,116,117,114,110,32,101,46,110,111,100,101,78,97,109,101,38,38,101,46,110,111,100,101,78,97,109,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,61,
        61,61,116,46,116,111,76,111,119,101,114,67,97,115,101,40,41,125,118,97,114,32,78,61,47,94,60,40,91,97,45,122,93,91,94,92,47,92,48,62,58,92,120,50,48,92,116,92,114,92,110,92,102,93,42,41,91,92,120,
        50,48,92,116,92,114,92,110,92,102,93,42,92,47,63,62,40,63,58,60,92,47,92,49,62,124,41,36,47,105,59,102,117,110,99,116,105,111,110,32,106,40,101,44,110,44,114,41,123,114,101,116,117,114,110,32,109,
        40,110,41,63,83,46,103,114,101,112,40,101,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,33,33,110,46,99,97,108,108,40,101,44,116,44,101,41,33,61,61,114,125,41,58,
        110,46,110,111,100,101,84,121,112,101,63,83,46,103,114,101,112,40,101,44,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,61,61,61,110,33,61,61,114,125,41,58,34,115,116,
        114,105,110,103,34,33,61,116,121,112,101,111,102,32,110,63,83,46,103,114,101,112,40,101,44,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,45,49,60,105,46,99,97,108,108,40,110,
        44,101,41,33,61,61,114,125,41,58,83,46,102,105,108,116,101,114,40,110,44,101,44,114,41,125,83,46,102,105,108,116,101,114,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,
        32,114,61,116,91,48,93,59,114,101,116,117,114,110,32,110,38,38,40,101,61,34,58,110,111,116,40,34,43,101,43,34,41,34,41,44,49,61,61,61,116,46,108,101,110,103,116,104,38,38,49,61,61,61,114,46,110,
        111,100,101,84,121,112,101,63,83,46,102,105,110,100,46,109,97,116,99,104,101,115,83,101,108,101,99,116,111,114,40,114,44,101,41,63,91,114,93,58,91,93,58,83,46,102,105,110,100,46,109,97,116,99,104,
        101,115,40,101,44,83,46,103,114,101,112,40,116,44,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,49,61,61,61,101,46,110,111,100,101,84,121,112,101,125,41,41,125,44,83,46,
        102,110,46,101,120,116,101,110,100,40,123,102,105,110,100,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,44,110,44,114,61,116,104,105,115,46,108,101,110,103,116,104,44,105,61,
        116,104,105,115,59,105,102,40,34,115,116,114,105,110,103,34,33,61,116,121,112,101,111,102,32,101,41,114,101,116,117,114,110,32,116,104,105,115,46,112,117,115,104,83,116,97,99,107,40,83,40,101,41,
        46,102,105,108,116,101,114,40,102,117,110,99,116,105,111,110,40,41,123,102,111,114,40,116,61,48,59,116,60,114,59,116,43,43,41,105,102,40,83,46,99,111,110,116,97,105,110,115,40,105,91,116,93,44,116,
        104,105,115,41,41,114,101,116,117,114,110,33,48,125,41,41,59,102,111,114,40,110,61,116,104,105,115,46,112,117,115,104,83,116,97,99,107,40,91,93,41,44,116,61,48,59,116,60,114,59,116,43,43,41,83,46,
        102,105,110,100,40,101,44,105,91,116,93,44,110,41,59,114,101,116,117,114,110,32,49,60,114,63,83,46,117,110,105,113,117,101,83,111,114,116,40,110,41,58,110,125,44,102,105,108,116,101,114,58,102,117,
        110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,116,104,105,115,46,112,117,115,104,83,116,97,99,107,40,106,40,116,104,105,115,44,101,124,124,91,93,44,33,49,41,41,125,44,110,111,116,
        58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,116,104,105,115,46,112,117,115,104,83,116,97,99,107,40,106,40,116,104,105,115,44,101,124,124,91,93,44,33,48,41,41,125,44,
        105,115,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,33,33,106,40,116,104,105,115,44,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,101,38,38,107,46,116,
        101,115,116,40,101,41,63,83,40,101,41,58,101,124,124,91,93,44,33,49,41,46,108,101,110,103,116,104,125,125,41,59,118,97,114,32,68,44,113,61,47,94,40,63,58,92,115,42,40,60,91,92,119,92,87,93,43,62,
        41,91,94,62,93,42,124,35,40,91,92,119,45,93,43,41,41,36,47,59,40,83,46,102,110,46,105,110,105,116,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,44,105,59,105,102,
        40,33,101,41,114,101,116,117,114,110,32,116,104,105,115,59,105,102,40,110,61,110,124,124,68,44,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,101,41,123,105,102,40,33,40,114,61,34,
        60,34,61,61,61,101,91,48,93,38,38,34,62,34,61,61,61,101,91,101,46,108,101,110,103,116,104,45,49,93,38,38,51,60,61,101,46,108,101,110,103,116,104,63,91,110,117,108,108,44,101,44,110,117,108,108,93,
        58,113,46,101,120,101,99,40,101,41,41,124,124,33,114,91,49,93,38,38,116,41,114,101,116,117,114,110,33,116,124,124,116,46,106,113,117,101,114,121,63,40,116,124,124,110,41,46,102,105,110,100,40,101,
        41,58,116,104,105,115,46,99,111,110,115,116,114,117,99,116,111,114,40,116,41,46,102,105,110,100,40,101,41,59,105,102,40,114,91,49,93,41,123,105,102,40,116,61,116,32,105,110,115,116,97,110,99,101,
        111,102,32,83,63,116,91,48,93,58,116,44,83,46,109,101,114,103,101,40,116,104,105,115,44,83,46,112,97,114,115,101,72,84,77,76,40,114,91,49,93,44,116,38,38,116,46,110,111,100,101,84,121,112,101,63,
        116,46,111,119,110,101,114,68,111,99,117,109,101,110,116,124,124,116,58,69,44,33,48,41,41,44,78,46,116,101,115,116,40,114,91,49,93,41,38,38,83,46,105,115,80,108,97,105,110,79,98,106,101,99,116,40,
        116,41,41,102,111,114,40,114,32,105,110,32,116,41,109,40,116,104,105,115,91,114,93,41,63,116,104,105,115,91,114,93,40,116,91,114,93,41,58,116,104,105,115,46,97,116,116,114,40,114,44,116,91,114,93,
        41,59,114,101,116,117,114,110,32,116,104,105,115,125,114,101,116,117,114,110,40,105,61,69,46,103,101,116,69,108,101,109,101,110,116,66,121,73,100,40,114,91,50,93,41,41,38,38,40,116,104,105,115,91,
        48,93,61,105,44,116,104,105,115,46,108,101,110,103,116,104,61,49,41,44,116,104,105,115,125,114,101,116,117,114,110,32,101,46,110,111,100,101,84,121,112,101,63,40,116,104,105,115,91,48,93,61,101,
        44,116,104,105,115,46,108,101,110,103,116,104,61,49,44,116,104,105,115,41,58,109,40,101,41,63,118,111,105,100,32,48,33,61,61,110,46,114,101,97,100,121,63,110,46,114,101,97,100,121,40,101,41,58,101,
        40,83,41,58,83,46,109,97,107,101,65,114,114,97,121,40,101,44,116,104,105,115,41,125,41,46,112,114,111,116,111,116,121,112,101,61,83,46,102,110,44,68,61,83,40,69,41,59,118,97,114,32,76,61,47,94,40,
        63,58,112,97,114,101,110,116,115,124,112,114,101,118,40,63,58,85,110,116,105,108,124,65,108,108,41,41,47,44,72,61,123,99,104,105,108,100,114,101,110,58,33,48,44,99,111,110,116,101,110,116,115,58,
        33,48,44,110,101,120,116,58,33,48,44,112,114,101,118,58,33,48,125,59,102,117,110,99,116,105,111,110,32,79,40,101,44,116,41,123,119,104,105,108,101,40,40,101,61,101,91,116,93,41,38,38,49,33,61,61,
        101,46,110,111,100,101,84,121,112,101,41,59,114,101,116,117,114,110,32,101,125,83,46,102,110,46,101,120,116,101,110,100,40,123,104,97,115,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,
        32,116,61,83,40,101,44,116,104,105,115,41,44,110,61,116,46,108,101,110,103,116,104,59,114,101,116,117,114,110,32,116,104,105,115,46,102,105,108,116,101,114,40,102,117,110,99,116,105,111,110,40,41,
        123,102,111,114,40,118,97,114,32,101,61,48,59,101,60,110,59,101,43,43,41,105,102,40,83,46,99,111,110,116,97,105,110,115,40,116,104,105,115,44,116,91,101,93,41,41,114,101,116,117,114,110,33,48,125,
        41,125,44,99,108,111,115,101,115,116,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,44,114,61,48,44,105,61,116,104,105,115,46,108,101,110,103,116,104,44,111,61,91,93,44,
        97,61,34,115,116,114,105,110,103,34,33,61,116,121,112,101,111,102,32,101,38,38,83,40,101,41,59,105,102,40,33,107,46,116,101,115,116,40,101,41,41,102,111,114,40,59,114,60,105,59,114,43,43,41,102,
        111,114,40,110,61,116,104,105,115,91,114,93,59,110,38,38,110,33,61,61,116,59,110,61,110,46,112,97,114,101,110,116,78,111,100,101,41,105,102,40,110,46,110,111,100,101,84,121,112,101,60,49,49,38,38,
        40,97,63,45,49,60,97,46,105,110,100,101,120,40,110,41,58,49,61,61,61,110,46,110,111,100,101,84,121,112,101,38,38,83,46,102,105,110,100,46,109,97,116,99,104,101,115,83,101,108,101,99,116,111,114,
        40,110,44,101,41,41,41,123,111,46,112,117,115,104,40,110,41,59,98,114,101,97,107,125,114,101,116,117,114,110,32,116,104,105,115,46,112,117,115,104,83,116,97,99,107,40,49,60,111,46,108,101,110,103,
        116,104,63,83,46,117,110,105,113,117,101,83,111,114,116,40,111,41,58,111,41,125,44,105,110,100,101,120,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,63,34,115,116,
        114,105,110,103,34,61,61,116,121,112,101,111,102,32,101,63,105,46,99,97,108,108,40,83,40,101,41,44,116,104,105,115,91,48,93,41,58,105,46,99,97,108,108,40,116,104,105,115,44,101,46,106,113,117,101,
        114,121,63,101,91,48,93,58,101,41,58,116,104,105,115,91,48,93,38,38,116,104,105,115,91,48,93,46,112,97,114,101,110,116,78,111,100,101,63,116,104,105,115,46,102,105,114,115,116,40,41,46,112,114,101,
        118,65,108,108,40,41,46,108,101,110,103,116,104,58,45,49,125,44,97,100,100,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,116,104,105,115,46,112,117,115,104,83,
        116,97,99,107,40,83,46,117,110,105,113,117,101,83,111,114,116,40,83,46,109,101,114,103,101,40,116,104,105,115,46,103,101,116,40,41,44,83,40,101,44,116,41,41,41,41,125,44,97,100,100,66,97,99,107,
        58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,116,104,105,115,46,97,100,100,40,110,117,108,108,61,61,101,63,116,104,105,115,46,112,114,101,118,79,98,106,101,99,116,58,
        116,104,105,115,46,112,114,101,118,79,98,106,101,99,116,46,102,105,108,116,101,114,40,101,41,41,125,125,41,44,83,46,101,97,99,104,40,123,112,97,114,101,110,116,58,102,117,110,99,116,105,111,110,
        40,101,41,123,118,97,114,32,116,61,101,46,112,97,114,101,110,116,78,111,100,101,59,114,101,116,117,114,110,32,116,38,38,49,49,33,61,61,116,46,110,111,100,101,84,121,112,101,63,116,58,110,117,108,
        108,125,44,112,97,114,101,110,116,115,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,104,40,101,44,34,112,97,114,101,110,116,78,111,100,101,34,41,125,44,112,97,114,101,
        110,116,115,85,110,116,105,108,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,114,101,116,117,114,110,32,104,40,101,44,34,112,97,114,101,110,116,78,111,100,101,34,44,110,41,125,44,
        110,101,120,116,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,79,40,101,44,34,110,101,120,116,83,105,98,108,105,110,103,34,41,125,44,112,114,101,118,58,102,117,110,99,
        116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,79,40,101,44,34,112,114,101,118,105,111,117,115,83,105,98,108,105,110,103,34,41,125,44,110,101,120,116,65,108,108,58,102,117,110,99,116,105,
        111,110,40,101,41,123,114,101,116,117,114,110,32,104,40,101,44,34,110,101,120,116,83,105,98,108,105,110,103,34,41,125,44,112,114,101,118,65,108,108,58,102,117,110,99,116,105,111,110,40,101,41,123,
        114,101,116,117,114,110,32,104,40,101,44,34,112,114,101,118,105,111,117,115,83,105,98,108,105,110,103,34,41,125,44,110,101,120,116,85,110,116,105,108,58,102,117,110,99,116,105,111,110,40,101,44,
        116,44,110,41,123,114,101,116,117,114,110,32,104,40,101,44,34,110,101,120,116,83,105,98,108,105,110,103,34,44,110,41,125,44,112,114,101,118,85,110,116,105,108,58,102,117,110,99,116,105,111,110,40,
        101,44,116,44,110,41,123,114,101,116,117,114,110,32,104,40,101,44,34,112,114,101,118,105,111,117,115,83,105,98,108,105,110,103,34,44,110,41,125,44,115,105,98,108,105,110,103,115,58,102,117,110,99,
        116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,84,40,40,101,46,112,97,114,101,110,116,78,111,100,101,124,124,123,125,41,46,102,105,114,115,116,67,104,105,108,100,44,101,41,125,44,99,104,
        105,108,100,114,101,110,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,84,40,101,46,102,105,114,115,116,67,104,105,108,100,41,125,44,99,111,110,116,101,110,116,115,58,
        102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,110,117,108,108,33,61,101,46,99,111,110,116,101,110,116,68,111,99,117,109,101,110,116,38,38,114,40,101,46,99,111,110,116,101,
        110,116,68,111,99,117,109,101,110,116,41,63,101,46,99,111,110,116,101,110,116,68,111,99,117,109,101,110,116,58,40,65,40,101,44,34,116,101,109,112,108,97,116,101,34,41,38,38,40,101,61,101,46,99,111,
        110,116,101,110,116,124,124,101,41,44,83,46,109,101,114,103,101,40,91,93,44,101,46,99,104,105,108,100,78,111,100,101,115,41,41,125,125,44,102,117,110,99,116,105,111,110,40,114,44,105,41,123,83,46,
        102,110,91,114,93,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,61,83,46,109,97,112,40,116,104,105,115,44,105,44,101,41,59,114,101,116,117,114,110,34,85,110,116,105,108,
        34,33,61,61,114,46,115,108,105,99,101,40,45,53,41,38,38,40,116,61,101,41,44,116,38,38,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,116,38,38,40,110,61,83,46,102,105,108,116,101,
        114,40,116,44,110,41,41,44,49,60,116,104,105,115,46,108,101,110,103,116,104,38,38,40,72,91,114,93,124,124,83,46,117,110,105,113,117,101,83,111,114,116,40,110,41,44,76,46,116,101,115,116,40,114,41,
        38,38,110,46,114,101,118,101,114,115,101,40,41,41,44,116,104,105,115,46,112,117,115,104,83,116,97,99,107,40,110,41,125,125,41,59,118,97,114,32,80,61,47,91,94,92,120,50,48,92,116,92,114,92,110,92,
        102,93,43,47,103,59,102,117,110,99,116,105,111,110,32,82,40,101,41,123,114,101,116,117,114,110,32,101,125,102,117,110,99,116,105,111,110,32,77,40,101,41,123,116,104,114,111,119,32,101,125,102,117,
        110,99,116,105,111,110,32,73,40,101,44,116,44,110,44,114,41,123,118,97,114,32,105,59,116,114,121,123,101,38,38,109,40,105,61,101,46,112,114,111,109,105,115,101,41,63,105,46,99,97,108,108,40,101,
        41,46,100,111,110,101,40,116,41,46,102,97,105,108,40,110,41,58,101,38,38,109,40,105,61,101,46,116,104,101,110,41,63,105,46,99,97,108,108,40,101,44,116,44,110,41,58,116,46,97,112,112,108,121,40,118,
        111,105,100,32,48,44,91,101,93,46,115,108,105,99,101,40,114,41,41,125,99,97,116,99,104,40,101,41,123,110,46,97,112,112,108,121,40,118,111,105,100,32,48,44,91,101,93,41,125,125,83,46,67,97,108,108,
        98,97,99,107,115,61,102,117,110,99,116,105,111,110,40,114,41,123,118,97,114,32,101,44,110,59,114,61,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,114,63,40,101,61,114,44,110,61,
        123,125,44,83,46,101,97,99,104,40,101,46,109,97,116,99,104,40,80,41,124,124,91,93,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,110,91,116,93,61,33,48,125,41,44,110,41,58,83,46,101,120,
        116,101,110,100,40,123,125,44,114,41,59,118,97,114,32,105,44,116,44,111,44,97,44,115,61,91,93,44,117,61,91,93,44,108,61,45,49,44,99,61,102,117,110,99,116,105,111,110,40,41,123,102,111,114,40,97,
        61,97,124,124,114,46,111,110,99,101,44,111,61,105,61,33,48,59,117,46,108,101,110,103,116,104,59,108,61,45,49,41,123,116,61,117,46,115,104,105,102,116,40,41,59,119,104,105,108,101,40,43,43,108,60,
        115,46,108,101,110,103,116,104,41,33,49,61,61,61,115,91,108,93,46,97,112,112,108,121,40,116,91,48,93,44,116,91,49,93,41,38,38,114,46,115,116,111,112,79,110,70,97,108,115,101,38,38,40,108,61,115,
        46,108,101,110,103,116,104,44,116,61,33,49,41,125,114,46,109,101,109,111,114,121,124,124,40,116,61,33,49,41,44,105,61,33,49,44,97,38,38,40,115,61,116,63,91,93,58,34,34,41,125,44,102,61,123,97,100,
        100,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,115,38,38,40,116,38,38,33,105,38,38,40,108,61,115,46,108,101,110,103,116,104,45,49,44,117,46,112,117,115,104,40,116,41,
        41,44,102,117,110,99,116,105,111,110,32,110,40,101,41,123,83,46,101,97,99,104,40,101,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,109,40,116,41,63,114,46,117,110,105,113,117,101,38,38,
        102,46,104,97,115,40,116,41,124,124,115,46,112,117,115,104,40,116,41,58,116,38,38,116,46,108,101,110,103,116,104,38,38,34,115,116,114,105,110,103,34,33,61,61,119,40,116,41,38,38,110,40,116,41,125,
        41,125,40,97,114,103,117,109,101,110,116,115,41,44,116,38,38,33,105,38,38,99,40,41,41,44,116,104,105,115,125,44,114,101,109,111,118,101,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,
        114,110,32,83,46,101,97,99,104,40,97,114,103,117,109,101,110,116,115,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,59,119,104,105,108,101,40,45,49,60,40,110,61,83,46,105,
        110,65,114,114,97,121,40,116,44,115,44,110,41,41,41,115,46,115,112,108,105,99,101,40,110,44,49,41,44,110,60,61,108,38,38,108,45,45,125,41,44,116,104,105,115,125,44,104,97,115,58,102,117,110,99,116,
        105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,63,45,49,60,83,46,105,110,65,114,114,97,121,40,101,44,115,41,58,48,60,115,46,108,101,110,103,116,104,125,44,101,109,112,116,121,58,102,117,
        110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,115,38,38,40,115,61,91,93,41,44,116,104,105,115,125,44,100,105,115,97,98,108,101,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,
        117,114,110,32,97,61,117,61,91,93,44,115,61,116,61,34,34,44,116,104,105,115,125,44,100,105,115,97,98,108,101,100,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,33,115,125,44,
        108,111,99,107,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,97,61,117,61,91,93,44,116,124,124,105,124,124,40,115,61,116,61,34,34,41,44,116,104,105,115,125,44,108,111,99,
        107,101,100,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,33,33,97,125,44,102,105,114,101,87,105,116,104,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,
        117,114,110,32,97,124,124,40,116,61,91,101,44,40,116,61,116,124,124,91,93,41,46,115,108,105,99,101,63,116,46,115,108,105,99,101,40,41,58,116,93,44,117,46,112,117,115,104,40,116,41,44,105,124,124,
        99,40,41,41,44,116,104,105,115,125,44,102,105,114,101,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,102,46,102,105,114,101,87,105,116,104,40,116,104,105,115,44,97,114,103,
        117,109,101,110,116,115,41,44,116,104,105,115,125,44,102,105,114,101,100,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,33,33,111,125,125,59,114,101,116,117,114,110,32,102,125,
        44,83,46,101,120,116,101,110,100,40,123,68,101,102,101,114,114,101,100,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,111,61,91,91,34,110,111,116,105,102,121,34,44,34,112,114,111,
        103,114,101,115,115,34,44,83,46,67,97,108,108,98,97,99,107,115,40,34,109,101,109,111,114,121,34,41,44,83,46,67,97,108,108,98,97,99,107,115,40,34,109,101,109,111,114,121,34,41,44,50,93,44,91,34,114,
        101,115,111,108,118,101,34,44,34,100,111,110,101,34,44,83,46,67,97,108,108,98,97,99,107,115,40,34,111,110,99,101,32,109,101,109,111,114,121,34,41,44,83,46,67,97,108,108,98,97,99,107,115,40,34,111,
        110,99,101,32,109,101,109,111,114,121,34,41,44,48,44,34,114,101,115,111,108,118,101,100,34,93,44,91,34,114,101,106,101,99,116,34,44,34,102,97,105,108,34,44,83,46,67,97,108,108,98,97,99,107,115,40,
        34,111,110,99,101,32,109,101,109,111,114,121,34,41,44,83,46,67,97,108,108,98,97,99,107,115,40,34,111,110,99,101,32,109,101,109,111,114,121,34,41,44,49,44,34,114,101,106,101,99,116,101,100,34,93,
        93,44,105,61,34,112,101,110,100,105,110,103,34,44,97,61,123,115,116,97,116,101,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,105,125,44,97,108,119,97,121,115,58,102,117,
        110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,115,46,100,111,110,101,40,97,114,103,117,109,101,110,116,115,41,46,102,97,105,108,40,97,114,103,117,109,101,110,116,115,41,44,116,104,
        105,115,125,44,34,99,97,116,99,104,34,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,97,46,116,104,101,110,40,110,117,108,108,44,101,41,125,44,112,105,112,101,58,102,
        117,110,99,116,105,111,110,40,41,123,118,97,114,32,105,61,97,114,103,117,109,101,110,116,115,59,114,101,116,117,114,110,32,83,46,68,101,102,101,114,114,101,100,40,102,117,110,99,116,105,111,110,
        40,114,41,123,83,46,101,97,99,104,40,111,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,61,109,40,105,91,116,91,52,93,93,41,38,38,105,91,116,91,52,93,93,59,115,91,116,91,
        49,93,93,40,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,61,110,38,38,110,46,97,112,112,108,121,40,116,104,105,115,44,97,114,103,117,109,101,110,116,115,41,59,101,38,38,109,40,101,
        46,112,114,111,109,105,115,101,41,63,101,46,112,114,111,109,105,115,101,40,41,46,112,114,111,103,114,101,115,115,40,114,46,110,111,116,105,102,121,41,46,100,111,110,101,40,114,46,114,101,115,111,
        108,118,101,41,46,102,97,105,108,40,114,46,114,101,106,101,99,116,41,58,114,91,116,91,48,93,43,34,87,105,116,104,34,93,40,116,104,105,115,44,110,63,91,101,93,58,97,114,103,117,109,101,110,116,115,
        41,125,41,125,41,44,105,61,110,117,108,108,125,41,46,112,114,111,109,105,115,101,40,41,125,44,116,104,101,110,58,102,117,110,99,116,105,111,110,40,116,44,110,44,114,41,123,118,97,114,32,117,61,48,
        59,102,117,110,99,116,105,111,110,32,108,40,105,44,111,44,97,44,115,41,123,114,101,116,117,114,110,32,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,110,61,116,104,105,115,44,114,61,97,114,
        103,117,109,101,110,116,115,44,101,61,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,44,116,59,105,102,40,33,40,105,60,117,41,41,123,105,102,40,40,101,61,97,46,97,112,112,108,121,40,
        110,44,114,41,41,61,61,61,111,46,112,114,111,109,105,115,101,40,41,41,116,104,114,111,119,32,110,101,119,32,84,121,112,101,69,114,114,111,114,40,34,84,104,101,110,97,98,108,101,32,115,101,108,102,
        45,114,101,115,111,108,117,116,105,111,110,34,41,59,116,61,101,38,38,40,34,111,98,106,101,99,116,34,61,61,116,121,112,101,111,102,32,101,124,124,34,102,117,110,99,116,105,111,110,34,61,61,116,121,
        112,101,111,102,32,101,41,38,38,101,46,116,104,101,110,44,109,40,116,41,63,115,63,116,46,99,97,108,108,40,101,44,108,40,117,44,111,44,82,44,115,41,44,108,40,117,44,111,44,77,44,115,41,41,58,40,117,
        43,43,44,116,46,99,97,108,108,40,101,44,108,40,117,44,111,44,82,44,115,41,44,108,40,117,44,111,44,77,44,115,41,44,108,40,117,44,111,44,82,44,111,46,110,111,116,105,102,121,87,105,116,104,41,41,41,
        58,40,97,33,61,61,82,38,38,40,110,61,118,111,105,100,32,48,44,114,61,91,101,93,41,44,40,115,124,124,111,46,114,101,115,111,108,118,101,87,105,116,104,41,40,110,44,114,41,41,125,125,44,116,61,115,
        63,101,58,102,117,110,99,116,105,111,110,40,41,123,116,114,121,123,101,40,41,125,99,97,116,99,104,40,101,41,123,83,46,68,101,102,101,114,114,101,100,46,101,120,99,101,112,116,105,111,110,72,111,
        111,107,38,38,83,46,68,101,102,101,114,114,101,100,46,101,120,99,101,112,116,105,111,110,72,111,111,107,40,101,44,116,46,115,116,97,99,107,84,114,97,99,101,41,44,117,60,61,105,43,49,38,38,40,97,
        33,61,61,77,38,38,40,110,61,118,111,105,100,32,48,44,114,61,91,101,93,41,44,111,46,114,101,106,101,99,116,87,105,116,104,40,110,44,114,41,41,125,125,59,105,63,116,40,41,58,40,83,46,68,101,102,101,
        114,114,101,100,46,103,101,116,83,116,97,99,107,72,111,111,107,38,38,40,116,46,115,116,97,99,107,84,114,97,99,101,61,83,46,68,101,102,101,114,114,101,100,46,103,101,116,83,116,97,99,107,72,111,111,
        107,40,41,41,44,67,46,115,101,116,84,105,109,101,111,117,116,40,116,41,41,125,125,114,101,116,117,114,110,32,83,46,68,101,102,101,114,114,101,100,40,102,117,110,99,116,105,111,110,40,101,41,123,
        111,91,48,93,91,51,93,46,97,100,100,40,108,40,48,44,101,44,109,40,114,41,63,114,58,82,44,101,46,110,111,116,105,102,121,87,105,116,104,41,41,44,111,91,49,93,91,51,93,46,97,100,100,40,108,40,48,44,
        101,44,109,40,116,41,63,116,58,82,41,41,44,111,91,50,93,91,51,93,46,97,100,100,40,108,40,48,44,101,44,109,40,110,41,63,110,58,77,41,41,125,41,46,112,114,111,109,105,115,101,40,41,125,44,112,114,
        111,109,105,115,101,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,110,117,108,108,33,61,101,63,83,46,101,120,116,101,110,100,40,101,44,97,41,58,97,125,125,44,115,61,
        123,125,59,114,101,116,117,114,110,32,83,46,101,97,99,104,40,111,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,61,116,91,50,93,44,114,61,116,91,53,93,59,97,91,116,91,49,
        93,93,61,110,46,97,100,100,44,114,38,38,110,46,97,100,100,40,102,117,110,99,116,105,111,110,40,41,123,105,61,114,125,44,111,91,51,45,101,93,91,50,93,46,100,105,115,97,98,108,101,44,111,91,51,45,
        101,93,91,51,93,46,100,105,115,97,98,108,101,44,111,91,48,93,91,50,93,46,108,111,99,107,44,111,91,48,93,91,51,93,46,108,111,99,107,41,44,110,46,97,100,100,40,116,91,51,93,46,102,105,114,101,41,44,
        115,91,116,91,48,93,93,61,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,115,91,116,91,48,93,43,34,87,105,116,104,34,93,40,116,104,105,115,61,61,61,115,63,118,111,105,100,32,
        48,58,116,104,105,115,44,97,114,103,117,109,101,110,116,115,41,44,116,104,105,115,125,44,115,91,116,91,48,93,43,34,87,105,116,104,34,93,61,110,46,102,105,114,101,87,105,116,104,125,41,44,97,46,112,
        114,111,109,105,115,101,40,115,41,44,101,38,38,101,46,99,97,108,108,40,115,44,115,41,44,115,125,44,119,104,101,110,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,110,61,97,114,103,
        117,109,101,110,116,115,46,108,101,110,103,116,104,44,116,61,110,44,114,61,65,114,114,97,121,40,116,41,44,105,61,115,46,99,97,108,108,40,97,114,103,117,109,101,110,116,115,41,44,111,61,83,46,68,
        101,102,101,114,114,101,100,40,41,44,97,61,102,117,110,99,116,105,111,110,40,116,41,123,114,101,116,117,114,110,32,102,117,110,99,116,105,111,110,40,101,41,123,114,91,116,93,61,116,104,105,115,44,
        105,91,116,93,61,49,60,97,114,103,117,109,101,110,116,115,46,108,101,110,103,116,104,63,115,46,99,97,108,108,40,97,114,103,117,109,101,110,116,115,41,58,101,44,45,45,110,124,124,111,46,114,101,115,
        111,108,118,101,87,105,116,104,40,114,44,105,41,125,125,59,105,102,40,110,60,61,49,38,38,40,73,40,101,44,111,46,100,111,110,101,40,97,40,116,41,41,46,114,101,115,111,108,118,101,44,111,46,114,101,
        106,101,99,116,44,33,110,41,44,34,112,101,110,100,105,110,103,34,61,61,61,111,46,115,116,97,116,101,40,41,124,124,109,40,105,91,116,93,38,38,105,91,116,93,46,116,104,101,110,41,41,41,114,101,116,
        117,114,110,32,111,46,116,104,101,110,40,41,59,119,104,105,108,101,40,116,45,45,41,73,40,105,91,116,93,44,97,40,116,41,44,111,46,114,101,106,101,99,116,41,59,114,101,116,117,114,110,32,111,46,112,
        114,111,109,105,115,101,40,41,125,125,41,59,118,97,114,32,87,61,47,94,40,69,118,97,108,124,73,110,116,101,114,110,97,108,124,82,97,110,103,101,124,82,101,102,101,114,101,110,99,101,124,83,121,110,
        116,97,120,124,84,121,112,101,124,85,82,73,41,69,114,114,111,114,36,47,59,83,46,68,101,102,101,114,114,101,100,46,101,120,99,101,112,116,105,111,110,72,111,111,107,61,102,117,110,99,116,105,111,
        110,40,101,44,116,41,123,67,46,99,111,110,115,111,108,101,38,38,67,46,99,111,110,115,111,108,101,46,119,97,114,110,38,38,101,38,38,87,46,116,101,115,116,40,101,46,110,97,109,101,41,38,38,67,46,99,
        111,110,115,111,108,101,46,119,97,114,110,40,34,106,81,117,101,114,121,46,68,101,102,101,114,114,101,100,32,101,120,99,101,112,116,105,111,110,58,32,34,43,101,46,109,101,115,115,97,103,101,44,101,
        46,115,116,97,99,107,44,116,41,125,44,83,46,114,101,97,100,121,69,120,99,101,112,116,105,111,110,61,102,117,110,99,116,105,111,110,40,101,41,123,67,46,115,101,116,84,105,109,101,111,117,116,40,102,
        117,110,99,116,105,111,110,40,41,123,116,104,114,111,119,32,101,125,41,125,59,118,97,114,32,70,61,83,46,68,101,102,101,114,114,101,100,40,41,59,102,117,110,99,116,105,111,110,32,66,40,41,123,69,
        46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,68,79,77,67,111,110,116,101,110,116,76,111,97,100,101,100,34,44,66,41,44,67,46,114,101,109,111,118,101,69,118,101,
        110,116,76,105,115,116,101,110,101,114,40,34,108,111,97,100,34,44,66,41,44,83,46,114,101,97,100,121,40,41,125,83,46,102,110,46,114,101,97,100,121,61,102,117,110,99,116,105,111,110,40,101,41,123,
        114,101,116,117,114,110,32,70,46,116,104,101,110,40,101,41,91,34,99,97,116,99,104,34,93,40,102,117,110,99,116,105,111,110,40,101,41,123,83,46,114,101,97,100,121,69,120,99,101,112,116,105,111,110,
        40,101,41,125,41,44,116,104,105,115,125,44,83,46,101,120,116,101,110,100,40,123,105,115,82,101,97,100,121,58,33,49,44,114,101,97,100,121,87,97,105,116,58,49,44,114,101,97,100,121,58,102,117,110,
        99,116,105,111,110,40,101,41,123,40,33,48,61,61,61,101,63,45,45,83,46,114,101,97,100,121,87,97,105,116,58,83,46,105,115,82,101,97,100,121,41,124,124,40,83,46,105,115,82,101,97,100,121,61,33,48,41,
        33,61,61,101,38,38,48,60,45,45,83,46,114,101,97,100,121,87,97,105,116,124,124,70,46,114,101,115,111,108,118,101,87,105,116,104,40,69,44,91,83,93,41,125,125,41,44,83,46,114,101,97,100,121,46,116,
        104,101,110,61,70,46,116,104,101,110,44,34,99,111,109,112,108,101,116,101,34,61,61,61,69,46,114,101,97,100,121,83,116,97,116,101,124,124,34,108,111,97,100,105,110,103,34,33,61,61,69,46,114,101,97,
        100,121,83,116,97,116,101,38,38,33,69,46,100,111,99,117,109,101,110,116,69,108,101,109,101,110,116,46,100,111,83,99,114,111,108,108,63,67,46,115,101,116,84,105,109,101,111,117,116,40,83,46,114,101,
        97,100,121,41,58,40,69,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,34,68,79,77,67,111,110,116,101,110,116,76,111,97,100,101,100,34,44,66,41,44,67,46,97,100,100,69,118,101,
        110,116,76,105,115,116,101,110,101,114,40,34,108,111,97,100,34,44,66,41,41,59,118,97,114,32,36,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,44,114,44,105,44,111,44,97,41,123,118,97,114,
        32,115,61,48,44,117,61,101,46,108,101,110,103,116,104,44,108,61,110,117,108,108,61,61,110,59,105,102,40,34,111,98,106,101,99,116,34,61,61,61,119,40,110,41,41,102,111,114,40,115,32,105,110,32,105,
        61,33,48,44,110,41,36,40,101,44,116,44,115,44,110,91,115,93,44,33,48,44,111,44,97,41,59,101,108,115,101,32,105,102,40,118,111,105,100,32,48,33,61,61,114,38,38,40,105,61,33,48,44,109,40,114,41,124,
        124,40,97,61,33,48,41,44,108,38,38,40,97,63,40,116,46,99,97,108,108,40,101,44,114,41,44,116,61,110,117,108,108,41,58,40,108,61,116,44,116,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,
        123,114,101,116,117,114,110,32,108,46,99,97,108,108,40,83,40,101,41,44,110,41,125,41,41,44,116,41,41,102,111,114,40,59,115,60,117,59,115,43,43,41,116,40,101,91,115,93,44,110,44,97,63,114,58,114,
        46,99,97,108,108,40,101,91,115,93,44,115,44,116,40,101,91,115,93,44,110,41,41,41,59,114,101,116,117,114,110,32,105,63,101,58,108,63,116,46,99,97,108,108,40,101,41,58,117,63,116,40,101,91,48,93,44,
        110,41,58,111,125,44,95,61,47,94,45,109,115,45,47,44,122,61,47,45,40,91,97,45,122,93,41,47,103,59,102,117,110,99,116,105,111,110,32,85,40,101,44,116,41,123,114,101,116,117,114,110,32,116,46,116,
        111,85,112,112,101,114,67,97,115,101,40,41,125,102,117,110,99,116,105,111,110,32,88,40,101,41,123,114,101,116,117,114,110,32,101,46,114,101,112,108,97,99,101,40,95,44,34,109,115,45,34,41,46,114,
        101,112,108,97,99,101,40,122,44,85,41,125,118,97,114,32,86,61,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,49,61,61,61,101,46,110,111,100,101,84,121,112,101,124,124,57,
        61,61,61,101,46,110,111,100,101,84,121,112,101,124,124,33,43,101,46,110,111,100,101,84,121,112,101,125,59,102,117,110,99,116,105,111,110,32,71,40,41,123,116,104,105,115,46,101,120,112,97,110,100,
        111,61,83,46,101,120,112,97,110,100,111,43,71,46,117,105,100,43,43,125,71,46,117,105,100,61,49,44,71,46,112,114,111,116,111,116,121,112,101,61,123,99,97,99,104,101,58,102,117,110,99,116,105,111,
        110,40,101,41,123,118,97,114,32,116,61,101,91,116,104,105,115,46,101,120,112,97,110,100,111,93,59,114,101,116,117,114,110,32,116,124,124,40,116,61,123,125,44,86,40,101,41,38,38,40,101,46,110,111,
        100,101,84,121,112,101,63,101,91,116,104,105,115,46,101,120,112,97,110,100,111,93,61,116,58,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,101,44,116,104,105,115,
        46,101,120,112,97,110,100,111,44,123,118,97,108,117,101,58,116,44,99,111,110,102,105,103,117,114,97,98,108,101,58,33,48,125,41,41,41,44,116,125,44,115,101,116,58,102,117,110,99,116,105,111,110,40,
        101,44,116,44,110,41,123,118,97,114,32,114,44,105,61,116,104,105,115,46,99,97,99,104,101,40,101,41,59,105,102,40,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,116,41,105,91,88,40,
        116,41,93,61,110,59,101,108,115,101,32,102,111,114,40,114,32,105,110,32,116,41,105,91,88,40,114,41,93,61,116,91,114,93,59,114,101,116,117,114,110,32,105,125,44,103,101,116,58,102,117,110,99,116,
        105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,118,111,105,100,32,48,61,61,61,116,63,116,104,105,115,46,99,97,99,104,101,40,101,41,58,101,91,116,104,105,115,46,101,120,112,97,110,100,
        111,93,38,38,101,91,116,104,105,115,46,101,120,112,97,110,100,111,93,91,88,40,116,41,93,125,44,97,99,99,101,115,115,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,114,101,116,117,
        114,110,32,118,111,105,100,32,48,61,61,61,116,124,124,116,38,38,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,116,38,38,118,111,105,100,32,48,61,61,61,110,63,116,104,105,115,46,
        103,101,116,40,101,44,116,41,58,40,116,104,105,115,46,115,101,116,40,101,44,116,44,110,41,44,118,111,105,100,32,48,33,61,61,110,63,110,58,116,41,125,44,114,101,109,111,118,101,58,102,117,110,99,
        116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,44,114,61,101,91,116,104,105,115,46,101,120,112,97,110,100,111,93,59,105,102,40,118,111,105,100,32,48,33,61,61,114,41,123,105,102,40,118,111,
        105,100,32,48,33,61,61,116,41,123,110,61,40,116,61,65,114,114,97,121,46,105,115,65,114,114,97,121,40,116,41,63,116,46,109,97,112,40,88,41,58,40,116,61,88,40,116,41,41,105,110,32,114,63,91,116,93,
        58,116,46,109,97,116,99,104,40,80,41,124,124,91,93,41,46,108,101,110,103,116,104,59,119,104,105,108,101,40,110,45,45,41,100,101,108,101,116,101,32,114,91,116,91,110,93,93,125,40,118,111,105,100,
        32,48,61,61,61,116,124,124,83,46,105,115,69,109,112,116,121,79,98,106,101,99,116,40,114,41,41,38,38,40,101,46,110,111,100,101,84,121,112,101,63,101,91,116,104,105,115,46,101,120,112,97,110,100,111,
        93,61,118,111,105,100,32,48,58,100,101,108,101,116,101,32,101,91,116,104,105,115,46,101,120,112,97,110,100,111,93,41,125,125,44,104,97,115,68,97,116,97,58,102,117,110,99,116,105,111,110,40,101,41,
        123,118,97,114,32,116,61,101,91,116,104,105,115,46,101,120,112,97,110,100,111,93,59,114,101,116,117,114,110,32,118,111,105,100,32,48,33,61,61,116,38,38,33,83,46,105,115,69,109,112,116,121,79,98,
        106,101,99,116,40,116,41,125,125,59,118,97,114,32,89,61,110,101,119,32,71,44,81,61,110,101,119,32,71,44,74,61,47,94,40,63,58,92,123,91,92,119,92,87,93,42,92,125,124,92,91,91,92,119,92,87,93,42,92,
        93,41,36,47,44,75,61,47,91,65,45,90,93,47,103,59,102,117,110,99,116,105,111,110,32,90,40,101,44,116,44,110,41,123,118,97,114,32,114,44,105,59,105,102,40,118,111,105,100,32,48,61,61,61,110,38,38,
        49,61,61,61,101,46,110,111,100,101,84,121,112,101,41,105,102,40,114,61,34,100,97,116,97,45,34,43,116,46,114,101,112,108,97,99,101,40,75,44,34,45,36,38,34,41,46,116,111,76,111,119,101,114,67,97,115,
        101,40,41,44,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,40,110,61,101,46,103,101,116,65,116,116,114,105,98,117,116,101,40,114,41,41,41,123,116,114,121,123,110,61,34,116,114,117,
        101,34,61,61,61,40,105,61,110,41,124,124,34,102,97,108,115,101,34,33,61,61,105,38,38,40,34,110,117,108,108,34,61,61,61,105,63,110,117,108,108,58,105,61,61,61,43,105,43,34,34,63,43,105,58,74,46,116,
        101,115,116,40,105,41,63,74,83,79,78,46,112,97,114,115,101,40,105,41,58,105,41,125,99,97,116,99,104,40,101,41,123,125,81,46,115,101,116,40,101,44,116,44,110,41,125,101,108,115,101,32,110,61,118,
        111,105,100,32,48,59,114,101,116,117,114,110,32,110,125,83,46,101,120,116,101,110,100,40,123,104,97,115,68,97,116,97,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,81,
        46,104,97,115,68,97,116,97,40,101,41,124,124,89,46,104,97,115,68,97,116,97,40,101,41,125,44,100,97,116,97,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,114,101,116,117,114,110,32,
        81,46,97,99,99,101,115,115,40,101,44,116,44,110,41,125,44,114,101,109,111,118,101,68,97,116,97,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,81,46,114,101,109,111,118,101,40,101,44,116,
        41,125,44,95,100,97,116,97,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,114,101,116,117,114,110,32,89,46,97,99,99,101,115,115,40,101,44,116,44,110,41,125,44,95,114,101,109,111,118,
        101,68,97,116,97,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,89,46,114,101,109,111,118,101,40,101,44,116,41,125,125,41,44,83,46,102,110,46,101,120,116,101,110,100,40,123,100,97,116,97,
        58,102,117,110,99,116,105,111,110,40,110,44,101,41,123,118,97,114,32,116,44,114,44,105,44,111,61,116,104,105,115,91,48,93,44,97,61,111,38,38,111,46,97,116,116,114,105,98,117,116,101,115,59,105,102,
        40,118,111,105,100,32,48,61,61,61,110,41,123,105,102,40,116,104,105,115,46,108,101,110,103,116,104,38,38,40,105,61,81,46,103,101,116,40,111,41,44,49,61,61,61,111,46,110,111,100,101,84,121,112,101,
        38,38,33,89,46,103,101,116,40,111,44,34,104,97,115,68,97,116,97,65,116,116,114,115,34,41,41,41,123,116,61,97,46,108,101,110,103,116,104,59,119,104,105,108,101,40,116,45,45,41,97,91,116,93,38,38,
        48,61,61,61,40,114,61,97,91,116,93,46,110,97,109,101,41,46,105,110,100,101,120,79,102,40,34,100,97,116,97,45,34,41,38,38,40,114,61,88,40,114,46,115,108,105,99,101,40,53,41,41,44,90,40,111,44,114,
        44,105,91,114,93,41,41,59,89,46,115,101,116,40,111,44,34,104,97,115,68,97,116,97,65,116,116,114,115,34,44,33,48,41,125,114,101,116,117,114,110,32,105,125,114,101,116,117,114,110,34,111,98,106,101,
        99,116,34,61,61,116,121,112,101,111,102,32,110,63,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,41,123,81,46,115,101,116,40,116,104,105,115,44,110,41,125,41,58,36,40,116,
        104,105,115,44,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,59,105,102,40,111,38,38,118,111,105,100,32,48,61,61,61,101,41,114,101,116,117,114,110,32,118,111,105,100,32,48,33,61,
        61,40,116,61,81,46,103,101,116,40,111,44,110,41,41,63,116,58,118,111,105,100,32,48,33,61,61,40,116,61,90,40,111,44,110,41,41,63,116,58,118,111,105,100,32,48,59,116,104,105,115,46,101,97,99,104,40,
        102,117,110,99,116,105,111,110,40,41,123,81,46,115,101,116,40,116,104,105,115,44,110,44,101,41,125,41,125,44,110,117,108,108,44,101,44,49,60,97,114,103,117,109,101,110,116,115,46,108,101,110,103,
        116,104,44,110,117,108,108,44,33,48,41,125,44,114,101,109,111,118,101,68,97,116,97,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,116,104,105,115,46,101,97,99,104,40,
        102,117,110,99,116,105,111,110,40,41,123,81,46,114,101,109,111,118,101,40,116,104,105,115,44,101,41,125,41,125,125,41,44,83,46,101,120,116,101,110,100,40,123,113,117,101,117,101,58,102,117,110,99,
        116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,59,105,102,40,101,41,114,101,116,117,114,110,32,116,61,40,116,124,124,34,102,120,34,41,43,34,113,117,101,117,101,34,44,114,61,89,46,
        103,101,116,40,101,44,116,41,44,110,38,38,40,33,114,124,124,65,114,114,97,121,46,105,115,65,114,114,97,121,40,110,41,63,114,61,89,46,97,99,99,101,115,115,40,101,44,116,44,83,46,109,97,107,101,65,
        114,114,97,121,40,110,41,41,58,114,46,112,117,115,104,40,110,41,41,44,114,124,124,91,93,125,44,100,101,113,117,101,117,101,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,116,61,116,124,124,
        34,102,120,34,59,118,97,114,32,110,61,83,46,113,117,101,117,101,40,101,44,116,41,44,114,61,110,46,108,101,110,103,116,104,44,105,61,110,46,115,104,105,102,116,40,41,44,111,61,83,46,95,113,117,101,
        117,101,72,111,111,107,115,40,101,44,116,41,59,34,105,110,112,114,111,103,114,101,115,115,34,61,61,61,105,38,38,40,105,61,110,46,115,104,105,102,116,40,41,44,114,45,45,41,44,105,38,38,40,34,102,
        120,34,61,61,61,116,38,38,110,46,117,110,115,104,105,102,116,40,34,105,110,112,114,111,103,114,101,115,115,34,41,44,100,101,108,101,116,101,32,111,46,115,116,111,112,44,105,46,99,97,108,108,40,101,
        44,102,117,110,99,116,105,111,110,40,41,123,83,46,100,101,113,117,101,117,101,40,101,44,116,41,125,44,111,41,41,44,33,114,38,38,111,38,38,111,46,101,109,112,116,121,46,102,105,114,101,40,41,125,
        44,95,113,117,101,117,101,72,111,111,107,115,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,61,116,43,34,113,117,101,117,101,72,111,111,107,115,34,59,114,101,116,117,114,
        110,32,89,46,103,101,116,40,101,44,110,41,124,124,89,46,97,99,99,101,115,115,40,101,44,110,44,123,101,109,112,116,121,58,83,46,67,97,108,108,98,97,99,107,115,40,34,111,110,99,101,32,109,101,109,
        111,114,121,34,41,46,97,100,100,40,102,117,110,99,116,105,111,110,40,41,123,89,46,114,101,109,111,118,101,40,101,44,91,116,43,34,113,117,101,117,101,34,44,110,93,41,125,41,125,41,125,125,41,44,83,
        46,102,110,46,101,120,116,101,110,100,40,123,113,117,101,117,101,58,102,117,110,99,116,105,111,110,40,116,44,110,41,123,118,97,114,32,101,61,50,59,114,101,116,117,114,110,34,115,116,114,105,110,
        103,34,33,61,116,121,112,101,111,102,32,116,38,38,40,110,61,116,44,116,61,34,102,120,34,44,101,45,45,41,44,97,114,103,117,109,101,110,116,115,46,108,101,110,103,116,104,60,101,63,83,46,113,117,101,
        117,101,40,116,104,105,115,91,48,93,44,116,41,58,118,111,105,100,32,48,61,61,61,110,63,116,104,105,115,58,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,41,123,118,97,114,
        32,101,61,83,46,113,117,101,117,101,40,116,104,105,115,44,116,44,110,41,59,83,46,95,113,117,101,117,101,72,111,111,107,115,40,116,104,105,115,44,116,41,44,34,102,120,34,61,61,61,116,38,38,34,105,
        110,112,114,111,103,114,101,115,115,34,33,61,61,101,91,48,93,38,38,83,46,100,101,113,117,101,117,101,40,116,104,105,115,44,116,41,125,41,125,44,100,101,113,117,101,117,101,58,102,117,110,99,116,
        105,111,110,40,101,41,123,114,101,116,117,114,110,32,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,41,123,83,46,100,101,113,117,101,117,101,40,116,104,105,115,44,101,41,125,
        41,125,44,99,108,101,97,114,81,117,101,117,101,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,116,104,105,115,46,113,117,101,117,101,40,101,124,124,34,102,120,34,44,91,
        93,41,125,44,112,114,111,109,105,115,101,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,44,114,61,49,44,105,61,83,46,68,101,102,101,114,114,101,100,40,41,44,111,61,116,
        104,105,115,44,97,61,116,104,105,115,46,108,101,110,103,116,104,44,115,61,102,117,110,99,116,105,111,110,40,41,123,45,45,114,124,124,105,46,114,101,115,111,108,118,101,87,105,116,104,40,111,44,91,
        111,93,41,125,59,34,115,116,114,105,110,103,34,33,61,116,121,112,101,111,102,32,101,38,38,40,116,61,101,44,101,61,118,111,105,100,32,48,41,44,101,61,101,124,124,34,102,120,34,59,119,104,105,108,
        101,40,97,45,45,41,40,110,61,89,46,103,101,116,40,111,91,97,93,44,101,43,34,113,117,101,117,101,72,111,111,107,115,34,41,41,38,38,110,46,101,109,112,116,121,38,38,40,114,43,43,44,110,46,101,109,
        112,116,121,46,97,100,100,40,115,41,41,59,114,101,116,117,114,110,32,115,40,41,44,105,46,112,114,111,109,105,115,101,40,116,41,125,125,41,59,118,97,114,32,101,101,61,47,91,43,45,93,63,40,63,58,92,
        100,42,92,46,124,41,92,100,43,40,63,58,91,101,69,93,91,43,45,93,63,92,100,43,124,41,47,46,115,111,117,114,99,101,44,116,101,61,110,101,119,32,82,101,103,69,120,112,40,34,94,40,63,58,40,91,43,45,
        93,41,61,124,41,40,34,43,101,101,43,34,41,40,91,97,45,122,37,93,42,41,36,34,44,34,105,34,41,44,110,101,61,91,34,84,111,112,34,44,34,82,105,103,104,116,34,44,34,66,111,116,116,111,109,34,44,34,76,
        101,102,116,34,93,44,114,101,61,69,46,100,111,99,117,109,101,110,116,69,108,101,109,101,110,116,44,105,101,61,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,83,46,99,111,
        110,116,97,105,110,115,40,101,46,111,119,110,101,114,68,111,99,117,109,101,110,116,44,101,41,125,44,111,101,61,123,99,111,109,112,111,115,101,100,58,33,48,125,59,114,101,46,103,101,116,82,111,111,
        116,78,111,100,101,38,38,40,105,101,61,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,83,46,99,111,110,116,97,105,110,115,40,101,46,111,119,110,101,114,68,111,99,117,109,
        101,110,116,44,101,41,124,124,101,46,103,101,116,82,111,111,116,78,111,100,101,40,111,101,41,61,61,61,101,46,111,119,110,101,114,68,111,99,117,109,101,110,116,125,41,59,118,97,114,32,97,101,61,102,
        117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,34,110,111,110,101,34,61,61,61,40,101,61,116,124,124,101,41,46,115,116,121,108,101,46,100,105,115,112,108,97,121,124,124,34,
        34,61,61,61,101,46,115,116,121,108,101,46,100,105,115,112,108,97,121,38,38,105,101,40,101,41,38,38,34,110,111,110,101,34,61,61,61,83,46,99,115,115,40,101,44,34,100,105,115,112,108,97,121,34,41,125,
        59,102,117,110,99,116,105,111,110,32,115,101,40,101,44,116,44,110,44,114,41,123,118,97,114,32,105,44,111,44,97,61,50,48,44,115,61,114,63,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,
        114,110,32,114,46,99,117,114,40,41,125,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,83,46,99,115,115,40,101,44,116,44,34,34,41,125,44,117,61,115,40,41,44,108,61,110,38,
        38,110,91,51,93,124,124,40,83,46,99,115,115,78,117,109,98,101,114,91,116,93,63,34,34,58,34,112,120,34,41,44,99,61,101,46,110,111,100,101,84,121,112,101,38,38,40,83,46,99,115,115,78,117,109,98,101,
        114,91,116,93,124,124,34,112,120,34,33,61,61,108,38,38,43,117,41,38,38,116,101,46,101,120,101,99,40,83,46,99,115,115,40,101,44,116,41,41,59,105,102,40,99,38,38,99,91,51,93,33,61,61,108,41,123,117,
        47,61,50,44,108,61,108,124,124,99,91,51,93,44,99,61,43,117,124,124,49,59,119,104,105,108,101,40,97,45,45,41,83,46,115,116,121,108,101,40,101,44,116,44,99,43,108,41,44,40,49,45,111,41,42,40,49,45,
        40,111,61,115,40,41,47,117,124,124,46,53,41,41,60,61,48,38,38,40,97,61,48,41,44,99,47,61,111,59,99,42,61,50,44,83,46,115,116,121,108,101,40,101,44,116,44,99,43,108,41,44,110,61,110,124,124,91,93,
        125,114,101,116,117,114,110,32,110,38,38,40,99,61,43,99,124,124,43,117,124,124,48,44,105,61,110,91,49,93,63,99,43,40,110,91,49,93,43,49,41,42,110,91,50,93,58,43,110,91,50,93,44,114,38,38,40,114,
        46,117,110,105,116,61,108,44,114,46,115,116,97,114,116,61,99,44,114,46,101,110,100,61,105,41,41,44,105,125,118,97,114,32,117,101,61,123,125,59,102,117,110,99,116,105,111,110,32,108,101,40,101,44,
        116,41,123,102,111,114,40,118,97,114,32,110,44,114,44,105,44,111,44,97,44,115,44,117,44,108,61,91,93,44,99,61,48,44,102,61,101,46,108,101,110,103,116,104,59,99,60,102,59,99,43,43,41,40,114,61,101,
        91,99,93,41,46,115,116,121,108,101,38,38,40,110,61,114,46,115,116,121,108,101,46,100,105,115,112,108,97,121,44,116,63,40,34,110,111,110,101,34,61,61,61,110,38,38,40,108,91,99,93,61,89,46,103,101,
        116,40,114,44,34,100,105,115,112,108,97,121,34,41,124,124,110,117,108,108,44,108,91,99,93,124,124,40,114,46,115,116,121,108,101,46,100,105,115,112,108,97,121,61,34,34,41,41,44,34,34,61,61,61,114,
        46,115,116,121,108,101,46,100,105,115,112,108,97,121,38,38,97,101,40,114,41,38,38,40,108,91,99,93,61,40,117,61,97,61,111,61,118,111,105,100,32,48,44,97,61,40,105,61,114,41,46,111,119,110,101,114,
        68,111,99,117,109,101,110,116,44,115,61,105,46,110,111,100,101,78,97,109,101,44,40,117,61,117,101,91,115,93,41,124,124,40,111,61,97,46,98,111,100,121,46,97,112,112,101,110,100,67,104,105,108,100,
        40,97,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,115,41,41,44,117,61,83,46,99,115,115,40,111,44,34,100,105,115,112,108,97,121,34,41,44,111,46,112,97,114,101,110,116,78,111,100,101,46,
        114,101,109,111,118,101,67,104,105,108,100,40,111,41,44,34,110,111,110,101,34,61,61,61,117,38,38,40,117,61,34,98,108,111,99,107,34,41,44,117,101,91,115,93,61,117,41,41,41,41,58,34,110,111,110,101,
        34,33,61,61,110,38,38,40,108,91,99,93,61,34,110,111,110,101,34,44,89,46,115,101,116,40,114,44,34,100,105,115,112,108,97,121,34,44,110,41,41,41,59,102,111,114,40,99,61,48,59,99,60,102,59,99,43,43,
        41,110,117,108,108,33,61,108,91,99,93,38,38,40,101,91,99,93,46,115,116,121,108,101,46,100,105,115,112,108,97,121,61,108,91,99,93,41,59,114,101,116,117,114,110,32,101,125,83,46,102,110,46,101,120,
        116,101,110,100,40,123,115,104,111,119,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,108,101,40,116,104,105,115,44,33,48,41,125,44,104,105,100,101,58,102,117,110,99,116,
        105,111,110,40,41,123,114,101,116,117,114,110,32,108,101,40,116,104,105,115,41,125,44,116,111,103,103,108,101,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,34,98,111,111,
        108,101,97,110,34,61,61,116,121,112,101,111,102,32,101,63,101,63,116,104,105,115,46,115,104,111,119,40,41,58,116,104,105,115,46,104,105,100,101,40,41,58,116,104,105,115,46,101,97,99,104,40,102,117,
        110,99,116,105,111,110,40,41,123,97,101,40,116,104,105,115,41,63,83,40,116,104,105,115,41,46,115,104,111,119,40,41,58,83,40,116,104,105,115,41,46,104,105,100,101,40,41,125,41,125,125,41,59,118,97,
        114,32,99,101,44,102,101,44,112,101,61,47,94,40,63,58,99,104,101,99,107,98,111,120,124,114,97,100,105,111,41,36,47,105,44,100,101,61,47,60,40,91,97,45,122,93,91,94,92,47,92,48,62,92,120,50,48,92,
        116,92,114,92,110,92,102,93,42,41,47,105,44,104,101,61,47,94,36,124,94,109,111,100,117,108,101,36,124,92,47,40,63,58,106,97,118,97,124,101,99,109,97,41,115,99,114,105,112,116,47,105,59,99,101,61,
        69,46,99,114,101,97,116,101,68,111,99,117,109,101,110,116,70,114,97,103,109,101,110,116,40,41,46,97,112,112,101,110,100,67,104,105,108,100,40,69,46,99,114,101,97,116,101,69,108,101,109,101,110,116,
        40,34,100,105,118,34,41,41,44,40,102,101,61,69,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,105,110,112,117,116,34,41,41,46,115,101,116,65,116,116,114,105,98,117,116,101,40,34,116,121,
        112,101,34,44,34,114,97,100,105,111,34,41,44,102,101,46,115,101,116,65,116,116,114,105,98,117,116,101,40,34,99,104,101,99,107,101,100,34,44,34,99,104,101,99,107,101,100,34,41,44,102,101,46,115,101,
        116,65,116,116,114,105,98,117,116,101,40,34,110,97,109,101,34,44,34,116,34,41,44,99,101,46,97,112,112,101,110,100,67,104,105,108,100,40,102,101,41,44,121,46,99,104,101,99,107,67,108,111,110,101,
        61,99,101,46,99,108,111,110,101,78,111,100,101,40,33,48,41,46,99,108,111,110,101,78,111,100,101,40,33,48,41,46,108,97,115,116,67,104,105,108,100,46,99,104,101,99,107,101,100,44,99,101,46,105,110,
        110,101,114,72,84,77,76,61,34,60,116,101,120,116,97,114,101,97,62,120,60,47,116,101,120,116,97,114,101,97,62,34,44,121,46,110,111,67,108,111,110,101,67,104,101,99,107,101,100,61,33,33,99,101,46,
        99,108,111,110,101,78,111,100,101,40,33,48,41,46,108,97,115,116,67,104,105,108,100,46,100,101,102,97,117,108,116,86,97,108,117,101,44,99,101,46,105,110,110,101,114,72,84,77,76,61,34,60,111,112,116,
        105,111,110,62,60,47,111,112,116,105,111,110,62,34,44,121,46,111,112,116,105,111,110,61,33,33,99,101,46,108,97,115,116,67,104,105,108,100,59,118,97,114,32,103,101,61,123,116,104,101,97,100,58,91,
        49,44,34,60,116,97,98,108,101,62,34,44,34,60,47,116,97,98,108,101,62,34,93,44,99,111,108,58,91,50,44,34,60,116,97,98,108,101,62,60,99,111,108,103,114,111,117,112,62,34,44,34,60,47,99,111,108,103,
        114,111,117,112,62,60,47,116,97,98,108,101,62,34,93,44,116,114,58,91,50,44,34,60,116,97,98,108,101,62,60,116,98,111,100,121,62,34,44,34,60,47,116,98,111,100,121,62,60,47,116,97,98,108,101,62,34,
        93,44,116,100,58,91,51,44,34,60,116,97,98,108,101,62,60,116,98,111,100,121,62,60,116,114,62,34,44,34,60,47,116,114,62,60,47,116,98,111,100,121,62,60,47,116,97,98,108,101,62,34,93,44,95,100,101,102,
        97,117,108,116,58,91,48,44,34,34,44,34,34,93,125,59,102,117,110,99,116,105,111,110,32,118,101,40,101,44,116,41,123,118,97,114,32,110,59,114,101,116,117,114,110,32,110,61,34,117,110,100,101,102,105,
        110,101,100,34,33,61,116,121,112,101,111,102,32,101,46,103,101,116,69,108,101,109,101,110,116,115,66,121,84,97,103,78,97,109,101,63,101,46,103,101,116,69,108,101,109,101,110,116,115,66,121,84,97,
        103,78,97,109,101,40,116,124,124,34,42,34,41,58,34,117,110,100,101,102,105,110,101,100,34,33,61,116,121,112,101,111,102,32,101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,63,
        101,46,113,117,101,114,121,83,101,108,101,99,116,111,114,65,108,108,40,116,124,124,34,42,34,41,58,91,93,44,118,111,105,100,32,48,61,61,61,116,124,124,116,38,38,65,40,101,44,116,41,63,83,46,109,101,
        114,103,101,40,91,101,93,44,110,41,58,110,125,102,117,110,99,116,105,111,110,32,121,101,40,101,44,116,41,123,102,111,114,40,118,97,114,32,110,61,48,44,114,61,101,46,108,101,110,103,116,104,59,110,
        60,114,59,110,43,43,41,89,46,115,101,116,40,101,91,110,93,44,34,103,108,111,98,97,108,69,118,97,108,34,44,33,116,124,124,89,46,103,101,116,40,116,91,110,93,44,34,103,108,111,98,97,108,69,118,97,
        108,34,41,41,125,103,101,46,116,98,111,100,121,61,103,101,46,116,102,111,111,116,61,103,101,46,99,111,108,103,114,111,117,112,61,103,101,46,99,97,112,116,105,111,110,61,103,101,46,116,104,101,97,
        100,44,103,101,46,116,104,61,103,101,46,116,100,44,121,46,111,112,116,105,111,110,124,124,40,103,101,46,111,112,116,103,114,111,117,112,61,103,101,46,111,112,116,105,111,110,61,91,49,44,34,60,115,
        101,108,101,99,116,32,109,117,108,116,105,112,108,101,61,39,109,117,108,116,105,112,108,101,39,62,34,44,34,60,47,115,101,108,101,99,116,62,34,93,41,59,118,97,114,32,109,101,61,47,60,124,38,35,63,
        92,119,43,59,47,59,102,117,110,99,116,105,111,110,32,120,101,40,101,44,116,44,110,44,114,44,105,41,123,102,111,114,40,118,97,114,32,111,44,97,44,115,44,117,44,108,44,99,44,102,61,116,46,99,114,101,
        97,116,101,68,111,99,117,109,101,110,116,70,114,97,103,109,101,110,116,40,41,44,112,61,91,93,44,100,61,48,44,104,61,101,46,108,101,110,103,116,104,59,100,60,104,59,100,43,43,41,105,102,40,40,111,
        61,101,91,100,93,41,124,124,48,61,61,61,111,41,105,102,40,34,111,98,106,101,99,116,34,61,61,61,119,40,111,41,41,83,46,109,101,114,103,101,40,112,44,111,46,110,111,100,101,84,121,112,101,63,91,111,
        93,58,111,41,59,101,108,115,101,32,105,102,40,109,101,46,116,101,115,116,40,111,41,41,123,97,61,97,124,124,102,46,97,112,112,101,110,100,67,104,105,108,100,40,116,46,99,114,101,97,116,101,69,108,
        101,109,101,110,116,40,34,100,105,118,34,41,41,44,115,61,40,100,101,46,101,120,101,99,40,111,41,124,124,91,34,34,44,34,34,93,41,91,49,93,46,116,111,76,111,119,101,114,67,97,115,101,40,41,44,117,
        61,103,101,91,115,93,124,124,103,101,46,95,100,101,102,97,117,108,116,44,97,46,105,110,110,101,114,72,84,77,76,61,117,91,49,93,43,83,46,104,116,109,108,80,114,101,102,105,108,116,101,114,40,111,
        41,43,117,91,50,93,44,99,61,117,91,48,93,59,119,104,105,108,101,40,99,45,45,41,97,61,97,46,108,97,115,116,67,104,105,108,100,59,83,46,109,101,114,103,101,40,112,44,97,46,99,104,105,108,100,78,111,
        100,101,115,41,44,40,97,61,102,46,102,105,114,115,116,67,104,105,108,100,41,46,116,101,120,116,67,111,110,116,101,110,116,61,34,34,125,101,108,115,101,32,112,46,112,117,115,104,40,116,46,99,114,
        101,97,116,101,84,101,120,116,78,111,100,101,40,111,41,41,59,102,46,116,101,120,116,67,111,110,116,101,110,116,61,34,34,44,100,61,48,59,119,104,105,108,101,40,111,61,112,91,100,43,43,93,41,105,102,
        40,114,38,38,45,49,60,83,46,105,110,65,114,114,97,121,40,111,44,114,41,41,105,38,38,105,46,112,117,115,104,40,111,41,59,101,108,115,101,32,105,102,40,108,61,105,101,40,111,41,44,97,61,118,101,40,
        102,46,97,112,112,101,110,100,67,104,105,108,100,40,111,41,44,34,115,99,114,105,112,116,34,41,44,108,38,38,121,101,40,97,41,44,110,41,123,99,61,48,59,119,104,105,108,101,40,111,61,97,91,99,43,43,
        93,41,104,101,46,116,101,115,116,40,111,46,116,121,112,101,124,124,34,34,41,38,38,110,46,112,117,115,104,40,111,41,125,114,101,116,117,114,110,32,102,125,118,97,114,32,98,101,61,47,94,40,91,94,46,
        93,42,41,40,63,58,92,46,40,46,43,41,124,41,47,59,102,117,110,99,116,105,111,110,32,119,101,40,41,123,114,101,116,117,114,110,33,48,125,102,117,110,99,116,105,111,110,32,84,101,40,41,123,114,101,
        116,117,114,110,33,49,125,102,117,110,99,116,105,111,110,32,67,101,40,101,44,116,41,123,114,101,116,117,114,110,32,101,61,61,61,102,117,110,99,116,105,111,110,40,41,123,116,114,121,123,114,101,116,
        117,114,110,32,69,46,97,99,116,105,118,101,69,108,101,109,101,110,116,125,99,97,116,99,104,40,101,41,123,125,125,40,41,61,61,40,34,102,111,99,117,115,34,61,61,61,116,41,125,102,117,110,99,116,105,
        111,110,32,69,101,40,101,44,116,44,110,44,114,44,105,44,111,41,123,118,97,114,32,97,44,115,59,105,102,40,34,111,98,106,101,99,116,34,61,61,116,121,112,101,111,102,32,116,41,123,102,111,114,40,115,
        32,105,110,34,115,116,114,105,110,103,34,33,61,116,121,112,101,111,102,32,110,38,38,40,114,61,114,124,124,110,44,110,61,118,111,105,100,32,48,41,44,116,41,69,101,40,101,44,115,44,110,44,114,44,116,
        91,115,93,44,111,41,59,114,101,116,117,114,110,32,101,125,105,102,40,110,117,108,108,61,61,114,38,38,110,117,108,108,61,61,105,63,40,105,61,110,44,114,61,110,61,118,111,105,100,32,48,41,58,110,117,
        108,108,61,61,105,38,38,40,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,110,63,40,105,61,114,44,114,61,118,111,105,100,32,48,41,58,40,105,61,114,44,114,61,110,44,110,61,118,111,
        105,100,32,48,41,41,44,33,49,61,61,61,105,41,105,61,84,101,59,101,108,115,101,32,105,102,40,33,105,41,114,101,116,117,114,110,32,101,59,114,101,116,117,114,110,32,49,61,61,61,111,38,38,40,97,61,
        105,44,40,105,61,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,83,40,41,46,111,102,102,40,101,41,44,97,46,97,112,112,108,121,40,116,104,105,115,44,97,114,103,117,109,101,
        110,116,115,41,125,41,46,103,117,105,100,61,97,46,103,117,105,100,124,124,40,97,46,103,117,105,100,61,83,46,103,117,105,100,43,43,41,41,44,101,46,101,97,99,104,40,102,117,110,99,116,105,111,110,
        40,41,123,83,46,101,118,101,110,116,46,97,100,100,40,116,104,105,115,44,116,44,105,44,114,44,110,41,125,41,125,102,117,110,99,116,105,111,110,32,83,101,40,101,44,105,44,111,41,123,111,63,40,89,46,
        115,101,116,40,101,44,105,44,33,49,41,44,83,46,101,118,101,110,116,46,97,100,100,40,101,44,105,44,123,110,97,109,101,115,112,97,99,101,58,33,49,44,104,97,110,100,108,101,114,58,102,117,110,99,116,
        105,111,110,40,101,41,123,118,97,114,32,116,44,110,44,114,61,89,46,103,101,116,40,116,104,105,115,44,105,41,59,105,102,40,49,38,101,46,105,115,84,114,105,103,103,101,114,38,38,116,104,105,115,91,
        105,93,41,123,105,102,40,114,46,108,101,110,103,116,104,41,40,83,46,101,118,101,110,116,46,115,112,101,99,105,97,108,91,105,93,124,124,123,125,41,46,100,101,108,101,103,97,116,101,84,121,112,101,
        38,38,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,59,101,108,115,101,32,105,102,40,114,61,115,46,99,97,108,108,40,97,114,103,117,109,101,110,116,115,41,44,89,46,115,101,
        116,40,116,104,105,115,44,105,44,114,41,44,116,61,111,40,116,104,105,115,44,105,41,44,116,104,105,115,91,105,93,40,41,44,114,33,61,61,40,110,61,89,46,103,101,116,40,116,104,105,115,44,105,41,41,
        124,124,116,63,89,46,115,101,116,40,116,104,105,115,44,105,44,33,49,41,58,110,61,123,125,44,114,33,61,61,110,41,114,101,116,117,114,110,32,101,46,115,116,111,112,73,109,109,101,100,105,97,116,101,
        80,114,111,112,97,103,97,116,105,111,110,40,41,44,101,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,44,110,38,38,110,46,118,97,108,117,101,125,101,108,115,101,32,114,46,108,101,
        110,103,116,104,38,38,40,89,46,115,101,116,40,116,104,105,115,44,105,44,123,118,97,108,117,101,58,83,46,101,118,101,110,116,46,116,114,105,103,103,101,114,40,83,46,101,120,116,101,110,100,40,114,
        91,48,93,44,83,46,69,118,101,110,116,46,112,114,111,116,111,116,121,112,101,41,44,114,46,115,108,105,99,101,40,49,41,44,116,104,105,115,41,125,41,44,101,46,115,116,111,112,73,109,109,101,100,105,
        97,116,101,80,114,111,112,97,103,97,116,105,111,110,40,41,41,125,125,41,41,58,118,111,105,100,32,48,61,61,61,89,46,103,101,116,40,101,44,105,41,38,38,83,46,101,118,101,110,116,46,97,100,100,40,101,
        44,105,44,119,101,41,125,83,46,101,118,101,110,116,61,123,103,108,111,98,97,108,58,123,125,44,97,100,100,58,102,117,110,99,116,105,111,110,40,116,44,101,44,110,44,114,44,105,41,123,118,97,114,32,
        111,44,97,44,115,44,117,44,108,44,99,44,102,44,112,44,100,44,104,44,103,44,118,61,89,46,103,101,116,40,116,41,59,105,102,40,86,40,116,41,41,123,110,46,104,97,110,100,108,101,114,38,38,40,110,61,
        40,111,61,110,41,46,104,97,110,100,108,101,114,44,105,61,111,46,115,101,108,101,99,116,111,114,41,44,105,38,38,83,46,102,105,110,100,46,109,97,116,99,104,101,115,83,101,108,101,99,116,111,114,40,
        114,101,44,105,41,44,110,46,103,117,105,100,124,124,40,110,46,103,117,105,100,61,83,46,103,117,105,100,43,43,41,44,40,117,61,118,46,101,118,101,110,116,115,41,124,124,40,117,61,118,46,101,118,101,
        110,116,115,61,79,98,106,101,99,116,46,99,114,101,97,116,101,40,110,117,108,108,41,41,44,40,97,61,118,46,104,97,110,100,108,101,41,124,124,40,97,61,118,46,104,97,110,100,108,101,61,102,117,110,99,
        116,105,111,110,40,101,41,123,114,101,116,117,114,110,34,117,110,100,101,102,105,110,101,100,34,33,61,116,121,112,101,111,102,32,83,38,38,83,46,101,118,101,110,116,46,116,114,105,103,103,101,114,
        101,100,33,61,61,101,46,116,121,112,101,63,83,46,101,118,101,110,116,46,100,105,115,112,97,116,99,104,46,97,112,112,108,121,40,116,44,97,114,103,117,109,101,110,116,115,41,58,118,111,105,100,32,
        48,125,41,44,108,61,40,101,61,40,101,124,124,34,34,41,46,109,97,116,99,104,40,80,41,124,124,91,34,34,93,41,46,108,101,110,103,116,104,59,119,104,105,108,101,40,108,45,45,41,100,61,103,61,40,115,
        61,98,101,46,101,120,101,99,40,101,91,108,93,41,124,124,91,93,41,91,49,93,44,104,61,40,115,91,50,93,124,124,34,34,41,46,115,112,108,105,116,40,34,46,34,41,46,115,111,114,116,40,41,44,100,38,38,40,
        102,61,83,46,101,118,101,110,116,46,115,112,101,99,105,97,108,91,100,93,124,124,123,125,44,100,61,40,105,63,102,46,100,101,108,101,103,97,116,101,84,121,112,101,58,102,46,98,105,110,100,84,121,112,
        101,41,124,124,100,44,102,61,83,46,101,118,101,110,116,46,115,112,101,99,105,97,108,91,100,93,124,124,123,125,44,99,61,83,46,101,120,116,101,110,100,40,123,116,121,112,101,58,100,44,111,114,105,
        103,84,121,112,101,58,103,44,100,97,116,97,58,114,44,104,97,110,100,108,101,114,58,110,44,103,117,105,100,58,110,46,103,117,105,100,44,115,101,108,101,99,116,111,114,58,105,44,110,101,101,100,115,
        67,111,110,116,101,120,116,58,105,38,38,83,46,101,120,112,114,46,109,97,116,99,104,46,110,101,101,100,115,67,111,110,116,101,120,116,46,116,101,115,116,40,105,41,44,110,97,109,101,115,112,97,99,
        101,58,104,46,106,111,105,110,40,34,46,34,41,125,44,111,41,44,40,112,61,117,91,100,93,41,124,124,40,40,112,61,117,91,100,93,61,91,93,41,46,100,101,108,101,103,97,116,101,67,111,117,110,116,61,48,
        44,102,46,115,101,116,117,112,38,38,33,49,33,61,61,102,46,115,101,116,117,112,46,99,97,108,108,40,116,44,114,44,104,44,97,41,124,124,116,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,
        114,38,38,116,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,100,44,97,41,41,44,102,46,97,100,100,38,38,40,102,46,97,100,100,46,99,97,108,108,40,116,44,99,41,44,99,46,104,97,
        110,100,108,101,114,46,103,117,105,100,124,124,40,99,46,104,97,110,100,108,101,114,46,103,117,105,100,61,110,46,103,117,105,100,41,41,44,105,63,112,46,115,112,108,105,99,101,40,112,46,100,101,108,
        101,103,97,116,101,67,111,117,110,116,43,43,44,48,44,99,41,58,112,46,112,117,115,104,40,99,41,44,83,46,101,118,101,110,116,46,103,108,111,98,97,108,91,100,93,61,33,48,41,125,125,44,114,101,109,111,
        118,101,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,44,114,44,105,41,123,118,97,114,32,111,44,97,44,115,44,117,44,108,44,99,44,102,44,112,44,100,44,104,44,103,44,118,61,89,46,104,97,115,
        68,97,116,97,40,101,41,38,38,89,46,103,101,116,40,101,41,59,105,102,40,118,38,38,40,117,61,118,46,101,118,101,110,116,115,41,41,123,108,61,40,116,61,40,116,124,124,34,34,41,46,109,97,116,99,104,
        40,80,41,124,124,91,34,34,93,41,46,108,101,110,103,116,104,59,119,104,105,108,101,40,108,45,45,41,105,102,40,100,61,103,61,40,115,61,98,101,46,101,120,101,99,40,116,91,108,93,41,124,124,91,93,41,
        91,49,93,44,104,61,40,115,91,50,93,124,124,34,34,41,46,115,112,108,105,116,40,34,46,34,41,46,115,111,114,116,40,41,44,100,41,123,102,61,83,46,101,118,101,110,116,46,115,112,101,99,105,97,108,91,
        100,93,124,124,123,125,44,112,61,117,91,100,61,40,114,63,102,46,100,101,108,101,103,97,116,101,84,121,112,101,58,102,46,98,105,110,100,84,121,112,101,41,124,124,100,93,124,124,91,93,44,115,61,115,
        91,50,93,38,38,110,101,119,32,82,101,103,69,120,112,40,34,40,94,124,92,92,46,41,34,43,104,46,106,111,105,110,40,34,92,92,46,40,63,58,46,42,92,92,46,124,41,34,41,43,34,40,92,92,46,124,36,41,34,41,
        44,97,61,111,61,112,46,108,101,110,103,116,104,59,119,104,105,108,101,40,111,45,45,41,99,61,112,91,111,93,44,33,105,38,38,103,33,61,61,99,46,111,114,105,103,84,121,112,101,124,124,110,38,38,110,
        46,103,117,105,100,33,61,61,99,46,103,117,105,100,124,124,115,38,38,33,115,46,116,101,115,116,40,99,46,110,97,109,101,115,112,97,99,101,41,124,124,114,38,38,114,33,61,61,99,46,115,101,108,101,99,
        116,111,114,38,38,40,34,42,42,34,33,61,61,114,124,124,33,99,46,115,101,108,101,99,116,111,114,41,124,124,40,112,46,115,112,108,105,99,101,40,111,44,49,41,44,99,46,115,101,108,101,99,116,111,114,
        38,38,112,46,100,101,108,101,103,97,116,101,67,111,117,110,116,45,45,44,102,46,114,101,109,111,118,101,38,38,102,46,114,101,109,111,118,101,46,99,97,108,108,40,101,44,99,41,41,59,97,38,38,33,112,
        46,108,101,110,103,116,104,38,38,40,102,46,116,101,97,114,100,111,119,110,38,38,33,49,33,61,61,102,46,116,101,97,114,100,111,119,110,46,99,97,108,108,40,101,44,104,44,118,46,104,97,110,100,108,101,
        41,124,124,83,46,114,101,109,111,118,101,69,118,101,110,116,40,101,44,100,44,118,46,104,97,110,100,108,101,41,44,100,101,108,101,116,101,32,117,91,100,93,41,125,101,108,115,101,32,102,111,114,40,
        100,32,105,110,32,117,41,83,46,101,118,101,110,116,46,114,101,109,111,118,101,40,101,44,100,43,116,91,108,93,44,110,44,114,44,33,48,41,59,83,46,105,115,69,109,112,116,121,79,98,106,101,99,116,40,
        117,41,38,38,89,46,114,101,109,111,118,101,40,101,44,34,104,97,110,100,108,101,32,101,118,101,110,116,115,34,41,125,125,44,100,105,115,112,97,116,99,104,58,102,117,110,99,116,105,111,110,40,101,
        41,123,118,97,114,32,116,44,110,44,114,44,105,44,111,44,97,44,115,61,110,101,119,32,65,114,114,97,121,40,97,114,103,117,109,101,110,116,115,46,108,101,110,103,116,104,41,44,117,61,83,46,101,118,
        101,110,116,46,102,105,120,40,101,41,44,108,61,40,89,46,103,101,116,40,116,104,105,115,44,34,101,118,101,110,116,115,34,41,124,124,79,98,106,101,99,116,46,99,114,101,97,116,101,40,110,117,108,108,
        41,41,91,117,46,116,121,112,101,93,124,124,91,93,44,99,61,83,46,101,118,101,110,116,46,115,112,101,99,105,97,108,91,117,46,116,121,112,101,93,124,124,123,125,59,102,111,114,40,115,91,48,93,61,117,
        44,116,61,49,59,116,60,97,114,103,117,109,101,110,116,115,46,108,101,110,103,116,104,59,116,43,43,41,115,91,116,93,61,97,114,103,117,109,101,110,116,115,91,116,93,59,105,102,40,117,46,100,101,108,
        101,103,97,116,101,84,97,114,103,101,116,61,116,104,105,115,44,33,99,46,112,114,101,68,105,115,112,97,116,99,104,124,124,33,49,33,61,61,99,46,112,114,101,68,105,115,112,97,116,99,104,46,99,97,108,
        108,40,116,104,105,115,44,117,41,41,123,97,61,83,46,101,118,101,110,116,46,104,97,110,100,108,101,114,115,46,99,97,108,108,40,116,104,105,115,44,117,44,108,41,44,116,61,48,59,119,104,105,108,101,
        40,40,105,61,97,91,116,43,43,93,41,38,38,33,117,46,105,115,80,114,111,112,97,103,97,116,105,111,110,83,116,111,112,112,101,100,40,41,41,123,117,46,99,117,114,114,101,110,116,84,97,114,103,101,116,
        61,105,46,101,108,101,109,44,110,61,48,59,119,104,105,108,101,40,40,111,61,105,46,104,97,110,100,108,101,114,115,91,110,43,43,93,41,38,38,33,117,46,105,115,73,109,109,101,100,105,97,116,101,80,114,
        111,112,97,103,97,116,105,111,110,83,116,111,112,112,101,100,40,41,41,117,46,114,110,97,109,101,115,112,97,99,101,38,38,33,49,33,61,61,111,46,110,97,109,101,115,112,97,99,101,38,38,33,117,46,114,
        110,97,109,101,115,112,97,99,101,46,116,101,115,116,40,111,46,110,97,109,101,115,112,97,99,101,41,124,124,40,117,46,104,97,110,100,108,101,79,98,106,61,111,44,117,46,100,97,116,97,61,111,46,100,
        97,116,97,44,118,111,105,100,32,48,33,61,61,40,114,61,40,40,83,46,101,118,101,110,116,46,115,112,101,99,105,97,108,91,111,46,111,114,105,103,84,121,112,101,93,124,124,123,125,41,46,104,97,110,100,
        108,101,124,124,111,46,104,97,110,100,108,101,114,41,46,97,112,112,108,121,40,105,46,101,108,101,109,44,115,41,41,38,38,33,49,61,61,61,40,117,46,114,101,115,117,108,116,61,114,41,38,38,40,117,46,
        112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,44,117,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,41,41,125,114,101,116,117,114,110,32,99,46,112,111,115,116,68,
        105,115,112,97,116,99,104,38,38,99,46,112,111,115,116,68,105,115,112,97,116,99,104,46,99,97,108,108,40,116,104,105,115,44,117,41,44,117,46,114,101,115,117,108,116,125,125,44,104,97,110,100,108,101,
        114,115,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,44,114,44,105,44,111,44,97,44,115,61,91,93,44,117,61,116,46,100,101,108,101,103,97,116,101,67,111,117,110,116,44,
        108,61,101,46,116,97,114,103,101,116,59,105,102,40,117,38,38,108,46,110,111,100,101,84,121,112,101,38,38,33,40,34,99,108,105,99,107,34,61,61,61,101,46,116,121,112,101,38,38,49,60,61,101,46,98,117,
        116,116,111,110,41,41,102,111,114,40,59,108,33,61,61,116,104,105,115,59,108,61,108,46,112,97,114,101,110,116,78,111,100,101,124,124,116,104,105,115,41,105,102,40,49,61,61,61,108,46,110,111,100,101,
        84,121,112,101,38,38,40,34,99,108,105,99,107,34,33,61,61,101,46,116,121,112,101,124,124,33,48,33,61,61,108,46,100,105,115,97,98,108,101,100,41,41,123,102,111,114,40,111,61,91,93,44,97,61,123,125,
        44,110,61,48,59,110,60,117,59,110,43,43,41,118,111,105,100,32,48,61,61,61,97,91,105,61,40,114,61,116,91,110,93,41,46,115,101,108,101,99,116,111,114,43,34,32,34,93,38,38,40,97,91,105,93,61,114,46,
        110,101,101,100,115,67,111,110,116,101,120,116,63,45,49,60,83,40,105,44,116,104,105,115,41,46,105,110,100,101,120,40,108,41,58,83,46,102,105,110,100,40,105,44,116,104,105,115,44,110,117,108,108,
        44,91,108,93,41,46,108,101,110,103,116,104,41,44,97,91,105,93,38,38,111,46,112,117,115,104,40,114,41,59,111,46,108,101,110,103,116,104,38,38,115,46,112,117,115,104,40,123,101,108,101,109,58,108,
        44,104,97,110,100,108,101,114,115,58,111,125,41,125,114,101,116,117,114,110,32,108,61,116,104,105,115,44,117,60,116,46,108,101,110,103,116,104,38,38,115,46,112,117,115,104,40,123,101,108,101,109,
        58,108,44,104,97,110,100,108,101,114,115,58,116,46,115,108,105,99,101,40,117,41,125,41,44,115,125,44,97,100,100,80,114,111,112,58,102,117,110,99,116,105,111,110,40,116,44,101,41,123,79,98,106,101,
        99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,83,46,69,118,101,110,116,46,112,114,111,116,111,116,121,112,101,44,116,44,123,101,110,117,109,101,114,97,98,108,101,58,33,48,44,
        99,111,110,102,105,103,117,114,97,98,108,101,58,33,48,44,103,101,116,58,109,40,101,41,63,102,117,110,99,116,105,111,110,40,41,123,105,102,40,116,104,105,115,46,111,114,105,103,105,110,97,108,69,
        118,101,110,116,41,114,101,116,117,114,110,32,101,40,116,104,105,115,46,111,114,105,103,105,110,97,108,69,118,101,110,116,41,125,58,102,117,110,99,116,105,111,110,40,41,123,105,102,40,116,104,105,
        115,46,111,114,105,103,105,110,97,108,69,118,101,110,116,41,114,101,116,117,114,110,32,116,104,105,115,46,111,114,105,103,105,110,97,108,69,118,101,110,116,91,116,93,125,44,115,101,116,58,102,117,
        110,99,116,105,111,110,40,101,41,123,79,98,106,101,99,116,46,100,101,102,105,110,101,80,114,111,112,101,114,116,121,40,116,104,105,115,44,116,44,123,101,110,117,109,101,114,97,98,108,101,58,33,48,
        44,99,111,110,102,105,103,117,114,97,98,108,101,58,33,48,44,119,114,105,116,97,98,108,101,58,33,48,44,118,97,108,117,101,58,101,125,41,125,125,41,125,44,102,105,120,58,102,117,110,99,116,105,111,
        110,40,101,41,123,114,101,116,117,114,110,32,101,91,83,46,101,120,112,97,110,100,111,93,63,101,58,110,101,119,32,83,46,69,118,101,110,116,40,101,41,125,44,115,112,101,99,105,97,108,58,123,108,111,
        97,100,58,123,110,111,66,117,98,98,108,101,58,33,48,125,44,99,108,105,99,107,58,123,115,101,116,117,112,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,116,104,105,115,124,124,
        101,59,114,101,116,117,114,110,32,112,101,46,116,101,115,116,40,116,46,116,121,112,101,41,38,38,116,46,99,108,105,99,107,38,38,65,40,116,44,34,105,110,112,117,116,34,41,38,38,83,101,40,116,44,34,
        99,108,105,99,107,34,44,119,101,41,44,33,49,125,44,116,114,105,103,103,101,114,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,116,104,105,115,124,124,101,59,114,101,116,117,
        114,110,32,112,101,46,116,101,115,116,40,116,46,116,121,112,101,41,38,38,116,46,99,108,105,99,107,38,38,65,40,116,44,34,105,110,112,117,116,34,41,38,38,83,101,40,116,44,34,99,108,105,99,107,34,41,
        44,33,48,125,44,95,100,101,102,97,117,108,116,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,101,46,116,97,114,103,101,116,59,114,101,116,117,114,110,32,112,101,46,116,101,
        115,116,40,116,46,116,121,112,101,41,38,38,116,46,99,108,105,99,107,38,38,65,40,116,44,34,105,110,112,117,116,34,41,38,38,89,46,103,101,116,40,116,44,34,99,108,105,99,107,34,41,124,124,65,40,116,
        44,34,97,34,41,125,125,44,98,101,102,111,114,101,117,110,108,111,97,100,58,123,112,111,115,116,68,105,115,112,97,116,99,104,58,102,117,110,99,116,105,111,110,40,101,41,123,118,111,105,100,32,48,
        33,61,61,101,46,114,101,115,117,108,116,38,38,101,46,111,114,105,103,105,110,97,108,69,118,101,110,116,38,38,40,101,46,111,114,105,103,105,110,97,108,69,118,101,110,116,46,114,101,116,117,114,110,
        86,97,108,117,101,61,101,46,114,101,115,117,108,116,41,125,125,125,125,44,83,46,114,101,109,111,118,101,69,118,101,110,116,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,101,46,114,
        101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,38,38,101,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,116,44,110,41,125,44,83,46,69,118,
        101,110,116,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,105,102,40,33,40,116,104,105,115,32,105,110,115,116,97,110,99,101,111,102,32,83,46,69,118,101,110,116,41,41,114,101,116,117,114,
        110,32,110,101,119,32,83,46,69,118,101,110,116,40,101,44,116,41,59,101,38,38,101,46,116,121,112,101,63,40,116,104,105,115,46,111,114,105,103,105,110,97,108,69,118,101,110,116,61,101,44,116,104,105,
        115,46,116,121,112,101,61,101,46,116,121,112,101,44,116,104,105,115,46,105,115,68,101,102,97,117,108,116,80,114,101,118,101,110,116,101,100,61,101,46,100,101,102,97,117,108,116,80,114,101,118,101,
        110,116,101,100,124,124,118,111,105,100,32,48,61,61,61,101,46,100,101,102,97,117,108,116,80,114,101,118,101,110,116,101,100,38,38,33,49,61,61,61,101,46,114,101,116,117,114,110,86,97,108,117,101,
        63,119,101,58,84,101,44,116,104,105,115,46,116,97,114,103,101,116,61,101,46,116,97,114,103,101,116,38,38,51,61,61,61,101,46,116,97,114,103,101,116,46,110,111,100,101,84,121,112,101,63,101,46,116,
        97,114,103,101,116,46,112,97,114,101,110,116,78,111,100,101,58,101,46,116,97,114,103,101,116,44,116,104,105,115,46,99,117,114,114,101,110,116,84,97,114,103,101,116,61,101,46,99,117,114,114,101,110,
        116,84,97,114,103,101,116,44,116,104,105,115,46,114,101,108,97,116,101,100,84,97,114,103,101,116,61,101,46,114,101,108,97,116,101,100,84,97,114,103,101,116,41,58,116,104,105,115,46,116,121,112,101,
        61,101,44,116,38,38,83,46,101,120,116,101,110,100,40,116,104,105,115,44,116,41,44,116,104,105,115,46,116,105,109,101,83,116,97,109,112,61,101,38,38,101,46,116,105,109,101,83,116,97,109,112,124,124,
        68,97,116,101,46,110,111,119,40,41,44,116,104,105,115,91,83,46,101,120,112,97,110,100,111,93,61,33,48,125,44,83,46,69,118,101,110,116,46,112,114,111,116,111,116,121,112,101,61,123,99,111,110,115,
        116,114,117,99,116,111,114,58,83,46,69,118,101,110,116,44,105,115,68,101,102,97,117,108,116,80,114,101,118,101,110,116,101,100,58,84,101,44,105,115,80,114,111,112,97,103,97,116,105,111,110,83,116,
        111,112,112,101,100,58,84,101,44,105,115,73,109,109,101,100,105,97,116,101,80,114,111,112,97,103,97,116,105,111,110,83,116,111,112,112,101,100,58,84,101,44,105,115,83,105,109,117,108,97,116,101,
        100,58,33,49,44,112,114,101,118,101,110,116,68,101,102,97,117,108,116,58,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,61,116,104,105,115,46,111,114,105,103,105,110,97,108,69,118,101,
        110,116,59,116,104,105,115,46,105,115,68,101,102,97,117,108,116,80,114,101,118,101,110,116,101,100,61,119,101,44,101,38,38,33,116,104,105,115,46,105,115,83,105,109,117,108,97,116,101,100,38,38,101,
        46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,125,44,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,58,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,61,116,
        104,105,115,46,111,114,105,103,105,110,97,108,69,118,101,110,116,59,116,104,105,115,46,105,115,80,114,111,112,97,103,97,116,105,111,110,83,116,111,112,112,101,100,61,119,101,44,101,38,38,33,116,
        104,105,115,46,105,115,83,105,109,117,108,97,116,101,100,38,38,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,125,44,115,116,111,112,73,109,109,101,100,105,97,116,101,80,114,
        111,112,97,103,97,116,105,111,110,58,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,61,116,104,105,115,46,111,114,105,103,105,110,97,108,69,118,101,110,116,59,116,104,105,115,46,105,
        115,73,109,109,101,100,105,97,116,101,80,114,111,112,97,103,97,116,105,111,110,83,116,111,112,112,101,100,61,119,101,44,101,38,38,33,116,104,105,115,46,105,115,83,105,109,117,108,97,116,101,100,
        38,38,101,46,115,116,111,112,73,109,109,101,100,105,97,116,101,80,114,111,112,97,103,97,116,105,111,110,40,41,44,116,104,105,115,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,
        125,125,44,83,46,101,97,99,104,40,123,97,108,116,75,101,121,58,33,48,44,98,117,98,98,108,101,115,58,33,48,44,99,97,110,99,101,108,97,98,108,101,58,33,48,44,99,104,97,110,103,101,100,84,111,117,99,
        104,101,115,58,33,48,44,99,116,114,108,75,101,121,58,33,48,44,100,101,116,97,105,108,58,33,48,44,101,118,101,110,116,80,104,97,115,101,58,33,48,44,109,101,116,97,75,101,121,58,33,48,44,112,97,103,
        101,88,58,33,48,44,112,97,103,101,89,58,33,48,44,115,104,105,102,116,75,101,121,58,33,48,44,118,105,101,119,58,33,48,44,34,99,104,97,114,34,58,33,48,44,99,111,100,101,58,33,48,44,99,104,97,114,67,
        111,100,101,58,33,48,44,107,101,121,58,33,48,44,107,101,121,67,111,100,101,58,33,48,44,98,117,116,116,111,110,58,33,48,44,98,117,116,116,111,110,115,58,33,48,44,99,108,105,101,110,116,88,58,33,48,
        44,99,108,105,101,110,116,89,58,33,48,44,111,102,102,115,101,116,88,58,33,48,44,111,102,102,115,101,116,89,58,33,48,44,112,111,105,110,116,101,114,73,100,58,33,48,44,112,111,105,110,116,101,114,
        84,121,112,101,58,33,48,44,115,99,114,101,101,110,88,58,33,48,44,115,99,114,101,101,110,89,58,33,48,44,116,97,114,103,101,116,84,111,117,99,104,101,115,58,33,48,44,116,111,69,108,101,109,101,110,
        116,58,33,48,44,116,111,117,99,104,101,115,58,33,48,44,119,104,105,99,104,58,33,48,125,44,83,46,101,118,101,110,116,46,97,100,100,80,114,111,112,41,44,83,46,101,97,99,104,40,123,102,111,99,117,115,
        58,34,102,111,99,117,115,105,110,34,44,98,108,117,114,58,34,102,111,99,117,115,111,117,116,34,125,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,83,46,101,118,101,110,116,46,115,112,101,
        99,105,97,108,91,101,93,61,123,115,101,116,117,112,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,83,101,40,116,104,105,115,44,101,44,67,101,41,44,33,49,125,44,116,114,105,
        103,103,101,114,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,83,101,40,116,104,105,115,44,101,41,44,33,48,125,44,95,100,101,102,97,117,108,116,58,102,117,110,99,116,105,
        111,110,40,41,123,114,101,116,117,114,110,33,48,125,44,100,101,108,101,103,97,116,101,84,121,112,101,58,116,125,125,41,44,83,46,101,97,99,104,40,123,109,111,117,115,101,101,110,116,101,114,58,34,
        109,111,117,115,101,111,118,101,114,34,44,109,111,117,115,101,108,101,97,118,101,58,34,109,111,117,115,101,111,117,116,34,44,112,111,105,110,116,101,114,101,110,116,101,114,58,34,112,111,105,110,
        116,101,114,111,118,101,114,34,44,112,111,105,110,116,101,114,108,101,97,118,101,58,34,112,111,105,110,116,101,114,111,117,116,34,125,44,102,117,110,99,116,105,111,110,40,101,44,105,41,123,83,46,
        101,118,101,110,116,46,115,112,101,99,105,97,108,91,101,93,61,123,100,101,108,101,103,97,116,101,84,121,112,101,58,105,44,98,105,110,100,84,121,112,101,58,105,44,104,97,110,100,108,101,58,102,117,
        110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,44,110,61,101,46,114,101,108,97,116,101,100,84,97,114,103,101,116,44,114,61,101,46,104,97,110,100,108,101,79,98,106,59,114,101,116,117,114,
        110,32,110,38,38,40,110,61,61,61,116,104,105,115,124,124,83,46,99,111,110,116,97,105,110,115,40,116,104,105,115,44,110,41,41,124,124,40,101,46,116,121,112,101,61,114,46,111,114,105,103,84,121,112,
        101,44,116,61,114,46,104,97,110,100,108,101,114,46,97,112,112,108,121,40,116,104,105,115,44,97,114,103,117,109,101,110,116,115,41,44,101,46,116,121,112,101,61,105,41,44,116,125,125,125,41,44,83,
        46,102,110,46,101,120,116,101,110,100,40,123,111,110,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,44,114,41,123,114,101,116,117,114,110,32,69,101,40,116,104,105,115,44,101,44,116,44,110,
        44,114,41,125,44,111,110,101,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,44,114,41,123,114,101,116,117,114,110,32,69,101,40,116,104,105,115,44,101,44,116,44,110,44,114,44,49,41,125,44,
        111,102,102,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,44,105,59,105,102,40,101,38,38,101,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,38,38,101,
        46,104,97,110,100,108,101,79,98,106,41,114,101,116,117,114,110,32,114,61,101,46,104,97,110,100,108,101,79,98,106,44,83,40,101,46,100,101,108,101,103,97,116,101,84,97,114,103,101,116,41,46,111,102,
        102,40,114,46,110,97,109,101,115,112,97,99,101,63,114,46,111,114,105,103,84,121,112,101,43,34,46,34,43,114,46,110,97,109,101,115,112,97,99,101,58,114,46,111,114,105,103,84,121,112,101,44,114,46,
        115,101,108,101,99,116,111,114,44,114,46,104,97,110,100,108,101,114,41,44,116,104,105,115,59,105,102,40,34,111,98,106,101,99,116,34,61,61,116,121,112,101,111,102,32,101,41,123,102,111,114,40,105,
        32,105,110,32,101,41,116,104,105,115,46,111,102,102,40,105,44,116,44,101,91,105,93,41,59,114,101,116,117,114,110,32,116,104,105,115,125,114,101,116,117,114,110,33,49,33,61,61,116,38,38,34,102,117,
        110,99,116,105,111,110,34,33,61,116,121,112,101,111,102,32,116,124,124,40,110,61,116,44,116,61,118,111,105,100,32,48,41,44,33,49,61,61,61,110,38,38,40,110,61,84,101,41,44,116,104,105,115,46,101,
        97,99,104,40,102,117,110,99,116,105,111,110,40,41,123,83,46,101,118,101,110,116,46,114,101,109,111,118,101,40,116,104,105,115,44,101,44,110,44,116,41,125,41,125,125,41,59,118,97,114,32,107,101,61,
        47,60,115,99,114,105,112,116,124,60,115,116,121,108,101,124,60,108,105,110,107,47,105,44,65,101,61,47,99,104,101,99,107,101,100,92,115,42,40,63,58,91,94,61,93,124,61,92,115,42,46,99,104,101,99,107,
        101,100,46,41,47,105,44,78,101,61,47,94,92,115,42,60,33,40,63,58,92,91,67,68,65,84,65,92,91,124,45,45,41,124,40,63,58,92,93,92,93,124,45,45,41,62,92,115,42,36,47,103,59,102,117,110,99,116,105,111,
        110,32,106,101,40,101,44,116,41,123,114,101,116,117,114,110,32,65,40,101,44,34,116,97,98,108,101,34,41,38,38,65,40,49,49,33,61,61,116,46,110,111,100,101,84,121,112,101,63,116,58,116,46,102,105,114,
        115,116,67,104,105,108,100,44,34,116,114,34,41,38,38,83,40,101,41,46,99,104,105,108,100,114,101,110,40,34,116,98,111,100,121,34,41,91,48,93,124,124,101,125,102,117,110,99,116,105,111,110,32,68,101,
        40,101,41,123,114,101,116,117,114,110,32,101,46,116,121,112,101,61,40,110,117,108,108,33,61,61,101,46,103,101,116,65,116,116,114,105,98,117,116,101,40,34,116,121,112,101,34,41,41,43,34,47,34,43,
        101,46,116,121,112,101,44,101,125,102,117,110,99,116,105,111,110,32,113,101,40,101,41,123,114,101,116,117,114,110,34,116,114,117,101,47,34,61,61,61,40,101,46,116,121,112,101,124,124,34,34,41,46,
        115,108,105,99,101,40,48,44,53,41,63,101,46,116,121,112,101,61,101,46,116,121,112,101,46,115,108,105,99,101,40,53,41,58,101,46,114,101,109,111,118,101,65,116,116,114,105,98,117,116,101,40,34,116,
        121,112,101,34,41,44,101,125,102,117,110,99,116,105,111,110,32,76,101,40,101,44,116,41,123,118,97,114,32,110,44,114,44,105,44,111,44,97,44,115,59,105,102,40,49,61,61,61,116,46,110,111,100,101,84,
        121,112,101,41,123,105,102,40,89,46,104,97,115,68,97,116,97,40,101,41,38,38,40,115,61,89,46,103,101,116,40,101,41,46,101,118,101,110,116,115,41,41,102,111,114,40,105,32,105,110,32,89,46,114,101,
        109,111,118,101,40,116,44,34,104,97,110,100,108,101,32,101,118,101,110,116,115,34,41,44,115,41,102,111,114,40,110,61,48,44,114,61,115,91,105,93,46,108,101,110,103,116,104,59,110,60,114,59,110,43,
        43,41,83,46,101,118,101,110,116,46,97,100,100,40,116,44,105,44,115,91,105,93,91,110,93,41,59,81,46,104,97,115,68,97,116,97,40,101,41,38,38,40,111,61,81,46,97,99,99,101,115,115,40,101,41,44,97,61,
        83,46,101,120,116,101,110,100,40,123,125,44,111,41,44,81,46,115,101,116,40,116,44,97,41,41,125,125,102,117,110,99,116,105,111,110,32,72,101,40,110,44,114,44,105,44,111,41,123,114,61,103,40,114,41,
        59,118,97,114,32,101,44,116,44,97,44,115,44,117,44,108,44,99,61,48,44,102,61,110,46,108,101,110,103,116,104,44,112,61,102,45,49,44,100,61,114,91,48,93,44,104,61,109,40,100,41,59,105,102,40,104,124,
        124,49,60,102,38,38,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,100,38,38,33,121,46,99,104,101,99,107,67,108,111,110,101,38,38,65,101,46,116,101,115,116,40,100,41,41,114,101,116,
        117,114,110,32,110,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,110,46,101,113,40,101,41,59,104,38,38,40,114,91,48,93,61,100,46,99,97,108,108,40,116,104,
        105,115,44,101,44,116,46,104,116,109,108,40,41,41,41,44,72,101,40,116,44,114,44,105,44,111,41,125,41,59,105,102,40,102,38,38,40,116,61,40,101,61,120,101,40,114,44,110,91,48,93,46,111,119,110,101,
        114,68,111,99,117,109,101,110,116,44,33,49,44,110,44,111,41,41,46,102,105,114,115,116,67,104,105,108,100,44,49,61,61,61,101,46,99,104,105,108,100,78,111,100,101,115,46,108,101,110,103,116,104,38,
        38,40,101,61,116,41,44,116,124,124,111,41,41,123,102,111,114,40,115,61,40,97,61,83,46,109,97,112,40,118,101,40,101,44,34,115,99,114,105,112,116,34,41,44,68,101,41,41,46,108,101,110,103,116,104,59,
        99,60,102,59,99,43,43,41,117,61,101,44,99,33,61,61,112,38,38,40,117,61,83,46,99,108,111,110,101,40,117,44,33,48,44,33,48,41,44,115,38,38,83,46,109,101,114,103,101,40,97,44,118,101,40,117,44,34,115,
        99,114,105,112,116,34,41,41,41,44,105,46,99,97,108,108,40,110,91,99,93,44,117,44,99,41,59,105,102,40,115,41,102,111,114,40,108,61,97,91,97,46,108,101,110,103,116,104,45,49,93,46,111,119,110,101,
        114,68,111,99,117,109,101,110,116,44,83,46,109,97,112,40,97,44,113,101,41,44,99,61,48,59,99,60,115,59,99,43,43,41,117,61,97,91,99,93,44,104,101,46,116,101,115,116,40,117,46,116,121,112,101,124,124,
        34,34,41,38,38,33,89,46,97,99,99,101,115,115,40,117,44,34,103,108,111,98,97,108,69,118,97,108,34,41,38,38,83,46,99,111,110,116,97,105,110,115,40,108,44,117,41,38,38,40,117,46,115,114,99,38,38,34,
        109,111,100,117,108,101,34,33,61,61,40,117,46,116,121,112,101,124,124,34,34,41,46,116,111,76,111,119,101,114,67,97,115,101,40,41,63,83,46,95,101,118,97,108,85,114,108,38,38,33,117,46,110,111,77,
        111,100,117,108,101,38,38,83,46,95,101,118,97,108,85,114,108,40,117,46,115,114,99,44,123,110,111,110,99,101,58,117,46,110,111,110,99,101,124,124,117,46,103,101,116,65,116,116,114,105,98,117,116,
        101,40,34,110,111,110,99,101,34,41,125,44,108,41,58,98,40,117,46,116,101,120,116,67,111,110,116,101,110,116,46,114,101,112,108,97,99,101,40,78,101,44,34,34,41,44,117,44,108,41,41,125,114,101,116,
        117,114,110,32,110,125,102,117,110,99,116,105,111,110,32,79,101,40,101,44,116,44,110,41,123,102,111,114,40,118,97,114,32,114,44,105,61,116,63,83,46,102,105,108,116,101,114,40,116,44,101,41,58,101,
        44,111,61,48,59,110,117,108,108,33,61,40,114,61,105,91,111,93,41,59,111,43,43,41,110,124,124,49,33,61,61,114,46,110,111,100,101,84,121,112,101,124,124,83,46,99,108,101,97,110,68,97,116,97,40,118,
        101,40,114,41,41,44,114,46,112,97,114,101,110,116,78,111,100,101,38,38,40,110,38,38,105,101,40,114,41,38,38,121,101,40,118,101,40,114,44,34,115,99,114,105,112,116,34,41,41,44,114,46,112,97,114,101,
        110,116,78,111,100,101,46,114,101,109,111,118,101,67,104,105,108,100,40,114,41,41,59,114,101,116,117,114,110,32,101,125,83,46,101,120,116,101,110,100,40,123,104,116,109,108,80,114,101,102,105,108,
        116,101,114,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,125,44,99,108,111,110,101,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,
        44,105,44,111,44,97,44,115,44,117,44,108,44,99,61,101,46,99,108,111,110,101,78,111,100,101,40,33,48,41,44,102,61,105,101,40,101,41,59,105,102,40,33,40,121,46,110,111,67,108,111,110,101,67,104,101,
        99,107,101,100,124,124,49,33,61,61,101,46,110,111,100,101,84,121,112,101,38,38,49,49,33,61,61,101,46,110,111,100,101,84,121,112,101,124,124,83,46,105,115,88,77,76,68,111,99,40,101,41,41,41,102,111,
        114,40,97,61,118,101,40,99,41,44,114,61,48,44,105,61,40,111,61,118,101,40,101,41,41,46,108,101,110,103,116,104,59,114,60,105,59,114,43,43,41,115,61,111,91,114,93,44,117,61,97,91,114,93,44,118,111,
        105,100,32,48,44,34,105,110,112,117,116,34,61,61,61,40,108,61,117,46,110,111,100,101,78,97,109,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,41,38,38,112,101,46,116,101,115,116,40,115,46,
        116,121,112,101,41,63,117,46,99,104,101,99,107,101,100,61,115,46,99,104,101,99,107,101,100,58,34,105,110,112,117,116,34,33,61,61,108,38,38,34,116,101,120,116,97,114,101,97,34,33,61,61,108,124,124,
        40,117,46,100,101,102,97,117,108,116,86,97,108,117,101,61,115,46,100,101,102,97,117,108,116,86,97,108,117,101,41,59,105,102,40,116,41,105,102,40,110,41,102,111,114,40,111,61,111,124,124,118,101,
        40,101,41,44,97,61,97,124,124,118,101,40,99,41,44,114,61,48,44,105,61,111,46,108,101,110,103,116,104,59,114,60,105,59,114,43,43,41,76,101,40,111,91,114,93,44,97,91,114,93,41,59,101,108,115,101,32,
        76,101,40,101,44,99,41,59,114,101,116,117,114,110,32,48,60,40,97,61,118,101,40,99,44,34,115,99,114,105,112,116,34,41,41,46,108,101,110,103,116,104,38,38,121,101,40,97,44,33,102,38,38,118,101,40,
        101,44,34,115,99,114,105,112,116,34,41,41,44,99,125,44,99,108,101,97,110,68,97,116,97,58,102,117,110,99,116,105,111,110,40,101,41,123,102,111,114,40,118,97,114,32,116,44,110,44,114,44,105,61,83,
        46,101,118,101,110,116,46,115,112,101,99,105,97,108,44,111,61,48,59,118,111,105,100,32,48,33,61,61,40,110,61,101,91,111,93,41,59,111,43,43,41,105,102,40,86,40,110,41,41,123,105,102,40,116,61,110,
        91,89,46,101,120,112,97,110,100,111,93,41,123,105,102,40,116,46,101,118,101,110,116,115,41,102,111,114,40,114,32,105,110,32,116,46,101,118,101,110,116,115,41,105,91,114,93,63,83,46,101,118,101,110,
        116,46,114,101,109,111,118,101,40,110,44,114,41,58,83,46,114,101,109,111,118,101,69,118,101,110,116,40,110,44,114,44,116,46,104,97,110,100,108,101,41,59,110,91,89,46,101,120,112,97,110,100,111,93,
        61,118,111,105,100,32,48,125,110,91,81,46,101,120,112,97,110,100,111,93,38,38,40,110,91,81,46,101,120,112,97,110,100,111,93,61,118,111,105,100,32,48,41,125,125,125,41,44,83,46,102,110,46,101,120,
        116,101,110,100,40,123,100,101,116,97,99,104,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,79,101,40,116,104,105,115,44,101,44,33,48,41,125,44,114,101,109,111,118,101,
        58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,79,101,40,116,104,105,115,44,101,41,125,44,116,101,120,116,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,
        117,114,110,32,36,40,116,104,105,115,44,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,118,111,105,100,32,48,61,61,61,101,63,83,46,116,101,120,116,40,116,104,105,115,41,
        58,116,104,105,115,46,101,109,112,116,121,40,41,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,41,123,49,33,61,61,116,104,105,115,46,110,111,100,101,84,121,112,101,38,38,49,49,33,61,61,116,
        104,105,115,46,110,111,100,101,84,121,112,101,38,38,57,33,61,61,116,104,105,115,46,110,111,100,101,84,121,112,101,124,124,40,116,104,105,115,46,116,101,120,116,67,111,110,116,101,110,116,61,101,
        41,125,41,125,44,110,117,108,108,44,101,44,97,114,103,117,109,101,110,116,115,46,108,101,110,103,116,104,41,125,44,97,112,112,101,110,100,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,
        117,114,110,32,72,101,40,116,104,105,115,44,97,114,103,117,109,101,110,116,115,44,102,117,110,99,116,105,111,110,40,101,41,123,49,33,61,61,116,104,105,115,46,110,111,100,101,84,121,112,101,38,38,
        49,49,33,61,61,116,104,105,115,46,110,111,100,101,84,121,112,101,38,38,57,33,61,61,116,104,105,115,46,110,111,100,101,84,121,112,101,124,124,106,101,40,116,104,105,115,44,101,41,46,97,112,112,101,
        110,100,67,104,105,108,100,40,101,41,125,41,125,44,112,114,101,112,101,110,100,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,72,101,40,116,104,105,115,44,97,114,103,117,
        109,101,110,116,115,44,102,117,110,99,116,105,111,110,40,101,41,123,105,102,40,49,61,61,61,116,104,105,115,46,110,111,100,101,84,121,112,101,124,124,49,49,61,61,61,116,104,105,115,46,110,111,100,
        101,84,121,112,101,124,124,57,61,61,61,116,104,105,115,46,110,111,100,101,84,121,112,101,41,123,118,97,114,32,116,61,106,101,40,116,104,105,115,44,101,41,59,116,46,105,110,115,101,114,116,66,101,
        102,111,114,101,40,101,44,116,46,102,105,114,115,116,67,104,105,108,100,41,125,125,41,125,44,98,101,102,111,114,101,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,72,101,
        40,116,104,105,115,44,97,114,103,117,109,101,110,116,115,44,102,117,110,99,116,105,111,110,40,101,41,123,116,104,105,115,46,112,97,114,101,110,116,78,111,100,101,38,38,116,104,105,115,46,112,97,
        114,101,110,116,78,111,100,101,46,105,110,115,101,114,116,66,101,102,111,114,101,40,101,44,116,104,105,115,41,125,41,125,44,97,102,116,101,114,58,102,117,110,99,116,105,111,110,40,41,123,114,101,
        116,117,114,110,32,72,101,40,116,104,105,115,44,97,114,103,117,109,101,110,116,115,44,102,117,110,99,116,105,111,110,40,101,41,123,116,104,105,115,46,112,97,114,101,110,116,78,111,100,101,38,38,
        116,104,105,115,46,112,97,114,101,110,116,78,111,100,101,46,105,110,115,101,114,116,66,101,102,111,114,101,40,101,44,116,104,105,115,46,110,101,120,116,83,105,98,108,105,110,103,41,125,41,125,44,
        101,109,112,116,121,58,102,117,110,99,116,105,111,110,40,41,123,102,111,114,40,118,97,114,32,101,44,116,61,48,59,110,117,108,108,33,61,40,101,61,116,104,105,115,91,116,93,41,59,116,43,43,41,49,61,
        61,61,101,46,110,111,100,101,84,121,112,101,38,38,40,83,46,99,108,101,97,110,68,97,116,97,40,118,101,40,101,44,33,49,41,41,44,101,46,116,101,120,116,67,111,110,116,101,110,116,61,34,34,41,59,114,
        101,116,117,114,110,32,116,104,105,115,125,44,99,108,111,110,101,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,101,61,110,117,108,108,33,61,101,38,38,101,44,116,
        61,110,117,108,108,61,61,116,63,101,58,116,44,116,104,105,115,46,109,97,112,40,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,83,46,99,108,111,110,101,40,116,104,105,115,44,
        101,44,116,41,125,41,125,44,104,116,109,108,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,36,40,116,104,105,115,44,102,117,110,99,116,105,111,110,40,101,41,123,118,97,
        114,32,116,61,116,104,105,115,91,48,93,124,124,123,125,44,110,61,48,44,114,61,116,104,105,115,46,108,101,110,103,116,104,59,105,102,40,118,111,105,100,32,48,61,61,61,101,38,38,49,61,61,61,116,46,
        110,111,100,101,84,121,112,101,41,114,101,116,117,114,110,32,116,46,105,110,110,101,114,72,84,77,76,59,105,102,40,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,101,38,38,33,107,
        101,46,116,101,115,116,40,101,41,38,38,33,103,101,91,40,100,101,46,101,120,101,99,40,101,41,124,124,91,34,34,44,34,34,93,41,91,49,93,46,116,111,76,111,119,101,114,67,97,115,101,40,41,93,41,123,101,
        61,83,46,104,116,109,108,80,114,101,102,105,108,116,101,114,40,101,41,59,116,114,121,123,102,111,114,40,59,110,60,114,59,110,43,43,41,49,61,61,61,40,116,61,116,104,105,115,91,110,93,124,124,123,
        125,41,46,110,111,100,101,84,121,112,101,38,38,40,83,46,99,108,101,97,110,68,97,116,97,40,118,101,40,116,44,33,49,41,41,44,116,46,105,110,110,101,114,72,84,77,76,61,101,41,59,116,61,48,125,99,97,
        116,99,104,40,101,41,123,125,125,116,38,38,116,104,105,115,46,101,109,112,116,121,40,41,46,97,112,112,101,110,100,40,101,41,125,44,110,117,108,108,44,101,44,97,114,103,117,109,101,110,116,115,46,
        108,101,110,103,116,104,41,125,44,114,101,112,108,97,99,101,87,105,116,104,58,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,110,61,91,93,59,114,101,116,117,114,110,32,72,101,40,116,104,
        105,115,44,97,114,103,117,109,101,110,116,115,44,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,116,104,105,115,46,112,97,114,101,110,116,78,111,100,101,59,83,46,105,110,65,114,
        114,97,121,40,116,104,105,115,44,110,41,60,48,38,38,40,83,46,99,108,101,97,110,68,97,116,97,40,118,101,40,116,104,105,115,41,41,44,116,38,38,116,46,114,101,112,108,97,99,101,67,104,105,108,100,40,
        101,44,116,104,105,115,41,41,125,44,110,41,125,125,41,44,83,46,101,97,99,104,40,123,97,112,112,101,110,100,84,111,58,34,97,112,112,101,110,100,34,44,112,114,101,112,101,110,100,84,111,58,34,112,
        114,101,112,101,110,100,34,44,105,110,115,101,114,116,66,101,102,111,114,101,58,34,98,101,102,111,114,101,34,44,105,110,115,101,114,116,65,102,116,101,114,58,34,97,102,116,101,114,34,44,114,101,
        112,108,97,99,101,65,108,108,58,34,114,101,112,108,97,99,101,87,105,116,104,34,125,44,102,117,110,99,116,105,111,110,40,101,44,97,41,123,83,46,102,110,91,101,93,61,102,117,110,99,116,105,111,110,
        40,101,41,123,102,111,114,40,118,97,114,32,116,44,110,61,91,93,44,114,61,83,40,101,41,44,105,61,114,46,108,101,110,103,116,104,45,49,44,111,61,48,59,111,60,61,105,59,111,43,43,41,116,61,111,61,61,
        61,105,63,116,104,105,115,58,116,104,105,115,46,99,108,111,110,101,40,33,48,41,44,83,40,114,91,111,93,41,91,97,93,40,116,41,44,117,46,97,112,112,108,121,40,110,44,116,46,103,101,116,40,41,41,59,
        114,101,116,117,114,110,32,116,104,105,115,46,112,117,115,104,83,116,97,99,107,40,110,41,125,125,41,59,118,97,114,32,80,101,61,110,101,119,32,82,101,103,69,120,112,40,34,94,40,34,43,101,101,43,34,
        41,40,63,33,112,120,41,91,97,45,122,37,93,43,36,34,44,34,105,34,41,44,82,101,61,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,101,46,111,119,110,101,114,68,111,99,117,109,101,
        110,116,46,100,101,102,97,117,108,116,86,105,101,119,59,114,101,116,117,114,110,32,116,38,38,116,46,111,112,101,110,101,114,124,124,40,116,61,67,41,44,116,46,103,101,116,67,111,109,112,117,116,101,
        100,83,116,121,108,101,40,101,41,125,44,77,101,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,44,105,44,111,61,123,125,59,102,111,114,40,105,32,105,110,32,116,41,
        111,91,105,93,61,101,46,115,116,121,108,101,91,105,93,44,101,46,115,116,121,108,101,91,105,93,61,116,91,105,93,59,102,111,114,40,105,32,105,110,32,114,61,110,46,99,97,108,108,40,101,41,44,116,41,
        101,46,115,116,121,108,101,91,105,93,61,111,91,105,93,59,114,101,116,117,114,110,32,114,125,44,73,101,61,110,101,119,32,82,101,103,69,120,112,40,110,101,46,106,111,105,110,40,34,124,34,41,44,34,
        105,34,41,59,102,117,110,99,116,105,111,110,32,87,101,40,101,44,116,44,110,41,123,118,97,114,32,114,44,105,44,111,44,97,44,115,61,101,46,115,116,121,108,101,59,114,101,116,117,114,110,40,110,61,
        110,124,124,82,101,40,101,41,41,38,38,40,34,34,33,61,61,40,97,61,110,46,103,101,116,80,114,111,112,101,114,116,121,86,97,108,117,101,40,116,41,124,124,110,91,116,93,41,124,124,105,101,40,101,41,
        124,124,40,97,61,83,46,115,116,121,108,101,40,101,44,116,41,41,44,33,121,46,112,105,120,101,108,66,111,120,83,116,121,108,101,115,40,41,38,38,80,101,46,116,101,115,116,40,97,41,38,38,73,101,46,116,
        101,115,116,40,116,41,38,38,40,114,61,115,46,119,105,100,116,104,44,105,61,115,46,109,105,110,87,105,100,116,104,44,111,61,115,46,109,97,120,87,105,100,116,104,44,115,46,109,105,110,87,105,100,116,
        104,61,115,46,109,97,120,87,105,100,116,104,61,115,46,119,105,100,116,104,61,97,44,97,61,110,46,119,105,100,116,104,44,115,46,119,105,100,116,104,61,114,44,115,46,109,105,110,87,105,100,116,104,
        61,105,44,115,46,109,97,120,87,105,100,116,104,61,111,41,41,44,118,111,105,100,32,48,33,61,61,97,63,97,43,34,34,58,97,125,102,117,110,99,116,105,111,110,32,70,101,40,101,44,116,41,123,114,101,116,
        117,114,110,123,103,101,116,58,102,117,110,99,116,105,111,110,40,41,123,105,102,40,33,101,40,41,41,114,101,116,117,114,110,40,116,104,105,115,46,103,101,116,61,116,41,46,97,112,112,108,121,40,116,
        104,105,115,44,97,114,103,117,109,101,110,116,115,41,59,100,101,108,101,116,101,32,116,104,105,115,46,103,101,116,125,125,125,33,102,117,110,99,116,105,111,110,40,41,123,102,117,110,99,116,105,111,
        110,32,101,40,41,123,105,102,40,108,41,123,117,46,115,116,121,108,101,46,99,115,115,84,101,120,116,61,34,112,111,115,105,116,105,111,110,58,97,98,115,111,108,117,116,101,59,108,101,102,116,58,45,
        49,49,49,49,49,112,120,59,119,105,100,116,104,58,54,48,112,120,59,109,97,114,103,105,110,45,116,111,112,58,49,112,120,59,112,97,100,100,105,110,103,58,48,59,98,111,114,100,101,114,58,48,34,44,108,
        46,115,116,121,108,101,46,99,115,115,84,101,120,116,61,34,112,111,115,105,116,105,111,110,58,114,101,108,97,116,105,118,101,59,100,105,115,112,108,97,121,58,98,108,111,99,107,59,98,111,120,45,115,
        105,122,105,110,103,58,98,111,114,100,101,114,45,98,111,120,59,111,118,101,114,102,108,111,119,58,115,99,114,111,108,108,59,109,97,114,103,105,110,58,97,117,116,111,59,98,111,114,100,101,114,58,
        49,112,120,59,112,97,100,100,105,110,103,58,49,112,120,59,119,105,100,116,104,58,54,48,37,59,116,111,112,58,49,37,34,44,114,101,46,97,112,112,101,110,100,67,104,105,108,100,40,117,41,46,97,112,112,
        101,110,100,67,104,105,108,100,40,108,41,59,118,97,114,32,101,61,67,46,103,101,116,67,111,109,112,117,116,101,100,83,116,121,108,101,40,108,41,59,110,61,34,49,37,34,33,61,61,101,46,116,111,112,44,
        115,61,49,50,61,61,61,116,40,101,46,109,97,114,103,105,110,76,101,102,116,41,44,108,46,115,116,121,108,101,46,114,105,103,104,116,61,34,54,48,37,34,44,111,61,51,54,61,61,61,116,40,101,46,114,105,
        103,104,116,41,44,114,61,51,54,61,61,61,116,40,101,46,119,105,100,116,104,41,44,108,46,115,116,121,108,101,46,112,111,115,105,116,105,111,110,61,34,97,98,115,111,108,117,116,101,34,44,105,61,49,
        50,61,61,61,116,40,108,46,111,102,102,115,101,116,87,105,100,116,104,47,51,41,44,114,101,46,114,101,109,111,118,101,67,104,105,108,100,40,117,41,44,108,61,110,117,108,108,125,125,102,117,110,99,
        116,105,111,110,32,116,40,101,41,123,114,101,116,117,114,110,32,77,97,116,104,46,114,111,117,110,100,40,112,97,114,115,101,70,108,111,97,116,40,101,41,41,125,118,97,114,32,110,44,114,44,105,44,111,
        44,97,44,115,44,117,61,69,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,100,105,118,34,41,44,108,61,69,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,100,105,118,34,41,59,
        108,46,115,116,121,108,101,38,38,40,108,46,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,67,108,105,112,61,34,99,111,110,116,101,110,116,45,98,111,120,34,44,108,46,99,108,111,110,101,
        78,111,100,101,40,33,48,41,46,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,67,108,105,112,61,34,34,44,121,46,99,108,101,97,114,67,108,111,110,101,83,116,121,108,101,61,34,99,111,110,
        116,101,110,116,45,98,111,120,34,61,61,61,108,46,115,116,121,108,101,46,98,97,99,107,103,114,111,117,110,100,67,108,105,112,44,83,46,101,120,116,101,110,100,40,121,44,123,98,111,120,83,105,122,105,
        110,103,82,101,108,105,97,98,108,101,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,101,40,41,44,114,125,44,112,105,120,101,108,66,111,120,83,116,121,108,101,115,58,102,117,
        110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,101,40,41,44,111,125,44,112,105,120,101,108,80,111,115,105,116,105,111,110,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,
        114,110,32,101,40,41,44,110,125,44,114,101,108,105,97,98,108,101,77,97,114,103,105,110,76,101,102,116,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,101,40,41,44,115,125,
        44,115,99,114,111,108,108,98,111,120,83,105,122,101,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,101,40,41,44,105,125,44,114,101,108,105,97,98,108,101,84,114,68,105,109,
        101,110,115,105,111,110,115,58,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,44,116,44,110,44,114,59,114,101,116,117,114,110,32,110,117,108,108,61,61,97,38,38,40,101,61,69,46,99,114,
        101,97,116,101,69,108,101,109,101,110,116,40,34,116,97,98,108,101,34,41,44,116,61,69,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,116,114,34,41,44,110,61,69,46,99,114,101,97,116,101,
        69,108,101,109,101,110,116,40,34,100,105,118,34,41,44,101,46,115,116,121,108,101,46,99,115,115,84,101,120,116,61,34,112,111,115,105,116,105,111,110,58,97,98,115,111,108,117,116,101,59,108,101,102,
        116,58,45,49,49,49,49,49,112,120,59,98,111,114,100,101,114,45,99,111,108,108,97,112,115,101,58,115,101,112,97,114,97,116,101,34,44,116,46,115,116,121,108,101,46,99,115,115,84,101,120,116,61,34,98,
        111,114,100,101,114,58,49,112,120,32,115,111,108,105,100,34,44,116,46,115,116,121,108,101,46,104,101,105,103,104,116,61,34,49,112,120,34,44,110,46,115,116,121,108,101,46,104,101,105,103,104,116,
        61,34,57,112,120,34,44,110,46,115,116,121,108,101,46,100,105,115,112,108,97,121,61,34,98,108,111,99,107,34,44,114,101,46,97,112,112,101,110,100,67,104,105,108,100,40,101,41,46,97,112,112,101,110,
        100,67,104,105,108,100,40,116,41,46,97,112,112,101,110,100,67,104,105,108,100,40,110,41,44,114,61,67,46,103,101,116,67,111,109,112,117,116,101,100,83,116,121,108,101,40,116,41,44,97,61,112,97,114,
        115,101,73,110,116,40,114,46,104,101,105,103,104,116,44,49,48,41,43,112,97,114,115,101,73,110,116,40,114,46,98,111,114,100,101,114,84,111,112,87,105,100,116,104,44,49,48,41,43,112,97,114,115,101,
        73,110,116,40,114,46,98,111,114,100,101,114,66,111,116,116,111,109,87,105,100,116,104,44,49,48,41,61,61,61,116,46,111,102,102,115,101,116,72,101,105,103,104,116,44,114,101,46,114,101,109,111,118,
        101,67,104,105,108,100,40,101,41,41,44,97,125,125,41,41,125,40,41,59,118,97,114,32,66,101,61,91,34,87,101,98,107,105,116,34,44,34,77,111,122,34,44,34,109,115,34,93,44,36,101,61,69,46,99,114,101,
        97,116,101,69,108,101,109,101,110,116,40,34,100,105,118,34,41,46,115,116,121,108,101,44,95,101,61,123,125,59,102,117,110,99,116,105,111,110,32,122,101,40,101,41,123,118,97,114,32,116,61,83,46,99,
        115,115,80,114,111,112,115,91,101,93,124,124,95,101,91,101,93,59,114,101,116,117,114,110,32,116,124,124,40,101,32,105,110,32,36,101,63,101,58,95,101,91,101,93,61,102,117,110,99,116,105,111,110,40,
        101,41,123,118,97,114,32,116,61,101,91,48,93,46,116,111,85,112,112,101,114,67,97,115,101,40,41,43,101,46,115,108,105,99,101,40,49,41,44,110,61,66,101,46,108,101,110,103,116,104,59,119,104,105,108,
        101,40,110,45,45,41,105,102,40,40,101,61,66,101,91,110,93,43,116,41,105,110,32,36,101,41,114,101,116,117,114,110,32,101,125,40,101,41,124,124,101,41,125,118,97,114,32,85,101,61,47,94,40,110,111,
        110,101,124,116,97,98,108,101,40,63,33,45,99,91,101,97,93,41,46,43,41,47,44,88,101,61,47,94,45,45,47,44,86,101,61,123,112,111,115,105,116,105,111,110,58,34,97,98,115,111,108,117,116,101,34,44,118,
        105,115,105,98,105,108,105,116,121,58,34,104,105,100,100,101,110,34,44,100,105,115,112,108,97,121,58,34,98,108,111,99,107,34,125,44,71,101,61,123,108,101,116,116,101,114,83,112,97,99,105,110,103,
        58,34,48,34,44,102,111,110,116,87,101,105,103,104,116,58,34,52,48,48,34,125,59,102,117,110,99,116,105,111,110,32,89,101,40,101,44,116,44,110,41,123,118,97,114,32,114,61,116,101,46,101,120,101,99,
        40,116,41,59,114,101,116,117,114,110,32,114,63,77,97,116,104,46,109,97,120,40,48,44,114,91,50,93,45,40,110,124,124,48,41,41,43,40,114,91,51,93,124,124,34,112,120,34,41,58,116,125,102,117,110,99,
        116,105,111,110,32,81,101,40,101,44,116,44,110,44,114,44,105,44,111,41,123,118,97,114,32,97,61,34,119,105,100,116,104,34,61,61,61,116,63,49,58,48,44,115,61,48,44,117,61,48,59,105,102,40,110,61,61,
        61,40,114,63,34,98,111,114,100,101,114,34,58,34,99,111,110,116,101,110,116,34,41,41,114,101,116,117,114,110,32,48,59,102,111,114,40,59,97,60,52,59,97,43,61,50,41,34,109,97,114,103,105,110,34,61,
        61,61,110,38,38,40,117,43,61,83,46,99,115,115,40,101,44,110,43,110,101,91,97,93,44,33,48,44,105,41,41,44,114,63,40,34,99,111,110,116,101,110,116,34,61,61,61,110,38,38,40,117,45,61,83,46,99,115,115,
        40,101,44,34,112,97,100,100,105,110,103,34,43,110,101,91,97,93,44,33,48,44,105,41,41,44,34,109,97,114,103,105,110,34,33,61,61,110,38,38,40,117,45,61,83,46,99,115,115,40,101,44,34,98,111,114,100,
        101,114,34,43,110,101,91,97,93,43,34,87,105,100,116,104,34,44,33,48,44,105,41,41,41,58,40,117,43,61,83,46,99,115,115,40,101,44,34,112,97,100,100,105,110,103,34,43,110,101,91,97,93,44,33,48,44,105,
        41,44,34,112,97,100,100,105,110,103,34,33,61,61,110,63,117,43,61,83,46,99,115,115,40,101,44,34,98,111,114,100,101,114,34,43,110,101,91,97,93,43,34,87,105,100,116,104,34,44,33,48,44,105,41,58,115,
        43,61,83,46,99,115,115,40,101,44,34,98,111,114,100,101,114,34,43,110,101,91,97,93,43,34,87,105,100,116,104,34,44,33,48,44,105,41,41,59,114,101,116,117,114,110,33,114,38,38,48,60,61,111,38,38,40,
        117,43,61,77,97,116,104,46,109,97,120,40,48,44,77,97,116,104,46,99,101,105,108,40,101,91,34,111,102,102,115,101,116,34,43,116,91,48,93,46,116,111,85,112,112,101,114,67,97,115,101,40,41,43,116,46,
        115,108,105,99,101,40,49,41,93,45,111,45,117,45,115,45,46,53,41,41,124,124,48,41,44,117,125,102,117,110,99,116,105,111,110,32,74,101,40,101,44,116,44,110,41,123,118,97,114,32,114,61,82,101,40,101,
        41,44,105,61,40,33,121,46,98,111,120,83,105,122,105,110,103,82,101,108,105,97,98,108,101,40,41,124,124,110,41,38,38,34,98,111,114,100,101,114,45,98,111,120,34,61,61,61,83,46,99,115,115,40,101,44,
        34,98,111,120,83,105,122,105,110,103,34,44,33,49,44,114,41,44,111,61,105,44,97,61,87,101,40,101,44,116,44,114,41,44,115,61,34,111,102,102,115,101,116,34,43,116,91,48,93,46,116,111,85,112,112,101,
        114,67,97,115,101,40,41,43,116,46,115,108,105,99,101,40,49,41,59,105,102,40,80,101,46,116,101,115,116,40,97,41,41,123,105,102,40,33,110,41,114,101,116,117,114,110,32,97,59,97,61,34,97,117,116,111,
        34,125,114,101,116,117,114,110,40,33,121,46,98,111,120,83,105,122,105,110,103,82,101,108,105,97,98,108,101,40,41,38,38,105,124,124,33,121,46,114,101,108,105,97,98,108,101,84,114,68,105,109,101,110,
        115,105,111,110,115,40,41,38,38,65,40,101,44,34,116,114,34,41,124,124,34,97,117,116,111,34,61,61,61,97,124,124,33,112,97,114,115,101,70,108,111,97,116,40,97,41,38,38,34,105,110,108,105,110,101,34,
        61,61,61,83,46,99,115,115,40,101,44,34,100,105,115,112,108,97,121,34,44,33,49,44,114,41,41,38,38,101,46,103,101,116,67,108,105,101,110,116,82,101,99,116,115,40,41,46,108,101,110,103,116,104,38,38,
        40,105,61,34,98,111,114,100,101,114,45,98,111,120,34,61,61,61,83,46,99,115,115,40,101,44,34,98,111,120,83,105,122,105,110,103,34,44,33,49,44,114,41,44,40,111,61,115,32,105,110,32,101,41,38,38,40,
        97,61,101,91,115,93,41,41,44,40,97,61,112,97,114,115,101,70,108,111,97,116,40,97,41,124,124,48,41,43,81,101,40,101,44,116,44,110,124,124,40,105,63,34,98,111,114,100,101,114,34,58,34,99,111,110,116,
        101,110,116,34,41,44,111,44,114,44,97,41,43,34,112,120,34,125,102,117,110,99,116,105,111,110,32,75,101,40,101,44,116,44,110,44,114,44,105,41,123,114,101,116,117,114,110,32,110,101,119,32,75,101,
        46,112,114,111,116,111,116,121,112,101,46,105,110,105,116,40,101,44,116,44,110,44,114,44,105,41,125,83,46,101,120,116,101,110,100,40,123,99,115,115,72,111,111,107,115,58,123,111,112,97,99,105,116,
        121,58,123,103,101,116,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,105,102,40,116,41,123,118,97,114,32,110,61,87,101,40,101,44,34,111,112,97,99,105,116,121,34,41,59,114,101,116,117,114,
        110,34,34,61,61,61,110,63,34,49,34,58,110,125,125,125,125,44,99,115,115,78,117,109,98,101,114,58,123,97,110,105,109,97,116,105,111,110,73,116,101,114,97,116,105,111,110,67,111,117,110,116,58,33,
        48,44,99,111,108,117,109,110,67,111,117,110,116,58,33,48,44,102,105,108,108,79,112,97,99,105,116,121,58,33,48,44,102,108,101,120,71,114,111,119,58,33,48,44,102,108,101,120,83,104,114,105,110,107,
        58,33,48,44,102,111,110,116,87,101,105,103,104,116,58,33,48,44,103,114,105,100,65,114,101,97,58,33,48,44,103,114,105,100,67,111,108,117,109,110,58,33,48,44,103,114,105,100,67,111,108,117,109,110,
        69,110,100,58,33,48,44,103,114,105,100,67,111,108,117,109,110,83,116,97,114,116,58,33,48,44,103,114,105,100,82,111,119,58,33,48,44,103,114,105,100,82,111,119,69,110,100,58,33,48,44,103,114,105,100,
        82,111,119,83,116,97,114,116,58,33,48,44,108,105,110,101,72,101,105,103,104,116,58,33,48,44,111,112,97,99,105,116,121,58,33,48,44,111,114,100,101,114,58,33,48,44,111,114,112,104,97,110,115,58,33,
        48,44,119,105,100,111,119,115,58,33,48,44,122,73,110,100,101,120,58,33,48,44,122,111,111,109,58,33,48,125,44,99,115,115,80,114,111,112,115,58,123,125,44,115,116,121,108,101,58,102,117,110,99,116,
        105,111,110,40,101,44,116,44,110,44,114,41,123,105,102,40,101,38,38,51,33,61,61,101,46,110,111,100,101,84,121,112,101,38,38,56,33,61,61,101,46,110,111,100,101,84,121,112,101,38,38,101,46,115,116,
        121,108,101,41,123,118,97,114,32,105,44,111,44,97,44,115,61,88,40,116,41,44,117,61,88,101,46,116,101,115,116,40,116,41,44,108,61,101,46,115,116,121,108,101,59,105,102,40,117,124,124,40,116,61,122,
        101,40,115,41,41,44,97,61,83,46,99,115,115,72,111,111,107,115,91,116,93,124,124,83,46,99,115,115,72,111,111,107,115,91,115,93,44,118,111,105,100,32,48,61,61,61,110,41,114,101,116,117,114,110,32,
        97,38,38,34,103,101,116,34,105,110,32,97,38,38,118,111,105,100,32,48,33,61,61,40,105,61,97,46,103,101,116,40,101,44,33,49,44,114,41,41,63,105,58,108,91,116,93,59,34,115,116,114,105,110,103,34,61,
        61,61,40,111,61,116,121,112,101,111,102,32,110,41,38,38,40,105,61,116,101,46,101,120,101,99,40,110,41,41,38,38,105,91,49,93,38,38,40,110,61,115,101,40,101,44,116,44,105,41,44,111,61,34,110,117,109,
        98,101,114,34,41,44,110,117,108,108,33,61,110,38,38,110,61,61,110,38,38,40,34,110,117,109,98,101,114,34,33,61,61,111,124,124,117,124,124,40,110,43,61,105,38,38,105,91,51,93,124,124,40,83,46,99,115,
        115,78,117,109,98,101,114,91,115,93,63,34,34,58,34,112,120,34,41,41,44,121,46,99,108,101,97,114,67,108,111,110,101,83,116,121,108,101,124,124,34,34,33,61,61,110,124,124,48,33,61,61,116,46,105,110,
        100,101,120,79,102,40,34,98,97,99,107,103,114,111,117,110,100,34,41,124,124,40,108,91,116,93,61,34,105,110,104,101,114,105,116,34,41,44,97,38,38,34,115,101,116,34,105,110,32,97,38,38,118,111,105,
        100,32,48,61,61,61,40,110,61,97,46,115,101,116,40,101,44,110,44,114,41,41,124,124,40,117,63,108,46,115,101,116,80,114,111,112,101,114,116,121,40,116,44,110,41,58,108,91,116,93,61,110,41,41,125,125,
        44,99,115,115,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,44,114,41,123,118,97,114,32,105,44,111,44,97,44,115,61,88,40,116,41,59,114,101,116,117,114,110,32,88,101,46,116,101,115,116,40,
        116,41,124,124,40,116,61,122,101,40,115,41,41,44,40,97,61,83,46,99,115,115,72,111,111,107,115,91,116,93,124,124,83,46,99,115,115,72,111,111,107,115,91,115,93,41,38,38,34,103,101,116,34,105,110,32,
        97,38,38,40,105,61,97,46,103,101,116,40,101,44,33,48,44,110,41,41,44,118,111,105,100,32,48,61,61,61,105,38,38,40,105,61,87,101,40,101,44,116,44,114,41,41,44,34,110,111,114,109,97,108,34,61,61,61,
        105,38,38,116,32,105,110,32,71,101,38,38,40,105,61,71,101,91,116,93,41,44,34,34,61,61,61,110,124,124,110,63,40,111,61,112,97,114,115,101,70,108,111,97,116,40,105,41,44,33,48,61,61,61,110,124,124,
        105,115,70,105,110,105,116,101,40,111,41,63,111,124,124,48,58,105,41,58,105,125,125,41,44,83,46,101,97,99,104,40,91,34,104,101,105,103,104,116,34,44,34,119,105,100,116,104,34,93,44,102,117,110,99,
        116,105,111,110,40,101,44,117,41,123,83,46,99,115,115,72,111,111,107,115,91,117,93,61,123,103,101,116,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,105,102,40,116,41,114,101,116,
        117,114,110,33,85,101,46,116,101,115,116,40,83,46,99,115,115,40,101,44,34,100,105,115,112,108,97,121,34,41,41,124,124,101,46,103,101,116,67,108,105,101,110,116,82,101,99,116,115,40,41,46,108,101,
        110,103,116,104,38,38,101,46,103,101,116,66,111,117,110,100,105,110,103,67,108,105,101,110,116,82,101,99,116,40,41,46,119,105,100,116,104,63,74,101,40,101,44,117,44,110,41,58,77,101,40,101,44,86,
        101,44,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,74,101,40,101,44,117,44,110,41,125,41,125,44,115,101,116,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,
        118,97,114,32,114,44,105,61,82,101,40,101,41,44,111,61,33,121,46,115,99,114,111,108,108,98,111,120,83,105,122,101,40,41,38,38,34,97,98,115,111,108,117,116,101,34,61,61,61,105,46,112,111,115,105,
        116,105,111,110,44,97,61,40,111,124,124,110,41,38,38,34,98,111,114,100,101,114,45,98,111,120,34,61,61,61,83,46,99,115,115,40,101,44,34,98,111,120,83,105,122,105,110,103,34,44,33,49,44,105,41,44,
        115,61,110,63,81,101,40,101,44,117,44,110,44,97,44,105,41,58,48,59,114,101,116,117,114,110,32,97,38,38,111,38,38,40,115,45,61,77,97,116,104,46,99,101,105,108,40,101,91,34,111,102,102,115,101,116,
        34,43,117,91,48,93,46,116,111,85,112,112,101,114,67,97,115,101,40,41,43,117,46,115,108,105,99,101,40,49,41,93,45,112,97,114,115,101,70,108,111,97,116,40,105,91,117,93,41,45,81,101,40,101,44,117,
        44,34,98,111,114,100,101,114,34,44,33,49,44,105,41,45,46,53,41,41,44,115,38,38,40,114,61,116,101,46,101,120,101,99,40,116,41,41,38,38,34,112,120,34,33,61,61,40,114,91,51,93,124,124,34,112,120,34,
        41,38,38,40,101,46,115,116,121,108,101,91,117,93,61,116,44,116,61,83,46,99,115,115,40,101,44,117,41,41,44,89,101,40,48,44,116,44,115,41,125,125,125,41,44,83,46,99,115,115,72,111,111,107,115,46,109,
        97,114,103,105,110,76,101,102,116,61,70,101,40,121,46,114,101,108,105,97,98,108,101,77,97,114,103,105,110,76,101,102,116,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,105,102,40,116,41,
        114,101,116,117,114,110,40,112,97,114,115,101,70,108,111,97,116,40,87,101,40,101,44,34,109,97,114,103,105,110,76,101,102,116,34,41,41,124,124,101,46,103,101,116,66,111,117,110,100,105,110,103,67,
        108,105,101,110,116,82,101,99,116,40,41,46,108,101,102,116,45,77,101,40,101,44,123,109,97,114,103,105,110,76,101,102,116,58,48,125,44,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,
        110,32,101,46,103,101,116,66,111,117,110,100,105,110,103,67,108,105,101,110,116,82,101,99,116,40,41,46,108,101,102,116,125,41,41,43,34,112,120,34,125,41,44,83,46,101,97,99,104,40,123,109,97,114,
        103,105,110,58,34,34,44,112,97,100,100,105,110,103,58,34,34,44,98,111,114,100,101,114,58,34,87,105,100,116,104,34,125,44,102,117,110,99,116,105,111,110,40,105,44,111,41,123,83,46,99,115,115,72,111,
        111,107,115,91,105,43,111,93,61,123,101,120,112,97,110,100,58,102,117,110,99,116,105,111,110,40,101,41,123,102,111,114,40,118,97,114,32,116,61,48,44,110,61,123,125,44,114,61,34,115,116,114,105,110,
        103,34,61,61,116,121,112,101,111,102,32,101,63,101,46,115,112,108,105,116,40,34,32,34,41,58,91,101,93,59,116,60,52,59,116,43,43,41,110,91,105,43,110,101,91,116,93,43,111,93,61,114,91,116,93,124,
        124,114,91,116,45,50,93,124,124,114,91,48,93,59,114,101,116,117,114,110,32,110,125,125,44,34,109,97,114,103,105,110,34,33,61,61,105,38,38,40,83,46,99,115,115,72,111,111,107,115,91,105,43,111,93,
        46,115,101,116,61,89,101,41,125,41,44,83,46,102,110,46,101,120,116,101,110,100,40,123,99,115,115,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,36,40,116,104,105,
        115,44,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,44,105,44,111,61,123,125,44,97,61,48,59,105,102,40,65,114,114,97,121,46,105,115,65,114,114,97,121,40,116,41,41,
        123,102,111,114,40,114,61,82,101,40,101,41,44,105,61,116,46,108,101,110,103,116,104,59,97,60,105,59,97,43,43,41,111,91,116,91,97,93,93,61,83,46,99,115,115,40,101,44,116,91,97,93,44,33,49,44,114,
        41,59,114,101,116,117,114,110,32,111,125,114,101,116,117,114,110,32,118,111,105,100,32,48,33,61,61,110,63,83,46,115,116,121,108,101,40,101,44,116,44,110,41,58,83,46,99,115,115,40,101,44,116,41,125,
        44,101,44,116,44,49,60,97,114,103,117,109,101,110,116,115,46,108,101,110,103,116,104,41,125,125,41,44,40,40,83,46,84,119,101,101,110,61,75,101,41,46,112,114,111,116,111,116,121,112,101,61,123,99,
        111,110,115,116,114,117,99,116,111,114,58,75,101,44,105,110,105,116,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,44,114,44,105,44,111,41,123,116,104,105,115,46,101,108,101,109,61,101,44,
        116,104,105,115,46,112,114,111,112,61,110,44,116,104,105,115,46,101,97,115,105,110,103,61,105,124,124,83,46,101,97,115,105,110,103,46,95,100,101,102,97,117,108,116,44,116,104,105,115,46,111,112,
        116,105,111,110,115,61,116,44,116,104,105,115,46,115,116,97,114,116,61,116,104,105,115,46,110,111,119,61,116,104,105,115,46,99,117,114,40,41,44,116,104,105,115,46,101,110,100,61,114,44,116,104,105,
        115,46,117,110,105,116,61,111,124,124,40,83,46,99,115,115,78,117,109,98,101,114,91,110,93,63,34,34,58,34,112,120,34,41,125,44,99,117,114,58,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,
        101,61,75,101,46,112,114,111,112,72,111,111,107,115,91,116,104,105,115,46,112,114,111,112,93,59,114,101,116,117,114,110,32,101,38,38,101,46,103,101,116,63,101,46,103,101,116,40,116,104,105,115,41,
        58,75,101,46,112,114,111,112,72,111,111,107,115,46,95,100,101,102,97,117,108,116,46,103,101,116,40,116,104,105,115,41,125,44,114,117,110,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,
        32,116,44,110,61,75,101,46,112,114,111,112,72,111,111,107,115,91,116,104,105,115,46,112,114,111,112,93,59,114,101,116,117,114,110,32,116,104,105,115,46,111,112,116,105,111,110,115,46,100,117,114,
        97,116,105,111,110,63,116,104,105,115,46,112,111,115,61,116,61,83,46,101,97,115,105,110,103,91,116,104,105,115,46,101,97,115,105,110,103,93,40,101,44,116,104,105,115,46,111,112,116,105,111,110,115,
        46,100,117,114,97,116,105,111,110,42,101,44,48,44,49,44,116,104,105,115,46,111,112,116,105,111,110,115,46,100,117,114,97,116,105,111,110,41,58,116,104,105,115,46,112,111,115,61,116,61,101,44,116,
        104,105,115,46,110,111,119,61,40,116,104,105,115,46,101,110,100,45,116,104,105,115,46,115,116,97,114,116,41,42,116,43,116,104,105,115,46,115,116,97,114,116,44,116,104,105,115,46,111,112,116,105,
        111,110,115,46,115,116,101,112,38,38,116,104,105,115,46,111,112,116,105,111,110,115,46,115,116,101,112,46,99,97,108,108,40,116,104,105,115,46,101,108,101,109,44,116,104,105,115,46,110,111,119,44,
        116,104,105,115,41,44,110,38,38,110,46,115,101,116,63,110,46,115,101,116,40,116,104,105,115,41,58,75,101,46,112,114,111,112,72,111,111,107,115,46,95,100,101,102,97,117,108,116,46,115,101,116,40,
        116,104,105,115,41,44,116,104,105,115,125,125,41,46,105,110,105,116,46,112,114,111,116,111,116,121,112,101,61,75,101,46,112,114,111,116,111,116,121,112,101,44,40,75,101,46,112,114,111,112,72,111,
        111,107,115,61,123,95,100,101,102,97,117,108,116,58,123,103,101,116,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,59,114,101,116,117,114,110,32,49,33,61,61,101,46,101,108,101,
        109,46,110,111,100,101,84,121,112,101,124,124,110,117,108,108,33,61,101,46,101,108,101,109,91,101,46,112,114,111,112,93,38,38,110,117,108,108,61,61,101,46,101,108,101,109,46,115,116,121,108,101,
        91,101,46,112,114,111,112,93,63,101,46,101,108,101,109,91,101,46,112,114,111,112,93,58,40,116,61,83,46,99,115,115,40,101,46,101,108,101,109,44,101,46,112,114,111,112,44,34,34,41,41,38,38,34,97,117,
        116,111,34,33,61,61,116,63,116,58,48,125,44,115,101,116,58,102,117,110,99,116,105,111,110,40,101,41,123,83,46,102,120,46,115,116,101,112,91,101,46,112,114,111,112,93,63,83,46,102,120,46,115,116,
        101,112,91,101,46,112,114,111,112,93,40,101,41,58,49,33,61,61,101,46,101,108,101,109,46,110,111,100,101,84,121,112,101,124,124,33,83,46,99,115,115,72,111,111,107,115,91,101,46,112,114,111,112,93,
        38,38,110,117,108,108,61,61,101,46,101,108,101,109,46,115,116,121,108,101,91,122,101,40,101,46,112,114,111,112,41,93,63,101,46,101,108,101,109,91,101,46,112,114,111,112,93,61,101,46,110,111,119,
        58,83,46,115,116,121,108,101,40,101,46,101,108,101,109,44,101,46,112,114,111,112,44,101,46,110,111,119,43,101,46,117,110,105,116,41,125,125,125,41,46,115,99,114,111,108,108,84,111,112,61,75,101,
        46,112,114,111,112,72,111,111,107,115,46,115,99,114,111,108,108,76,101,102,116,61,123,115,101,116,58,102,117,110,99,116,105,111,110,40,101,41,123,101,46,101,108,101,109,46,110,111,100,101,84,121,
        112,101,38,38,101,46,101,108,101,109,46,112,97,114,101,110,116,78,111,100,101,38,38,40,101,46,101,108,101,109,91,101,46,112,114,111,112,93,61,101,46,110,111,119,41,125,125,44,83,46,101,97,115,105,
        110,103,61,123,108,105,110,101,97,114,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,125,44,115,119,105,110,103,58,102,117,110,99,116,105,111,110,40,101,41,123,114,
        101,116,117,114,110,46,53,45,77,97,116,104,46,99,111,115,40,101,42,77,97,116,104,46,80,73,41,47,50,125,44,95,100,101,102,97,117,108,116,58,34,115,119,105,110,103,34,125,44,83,46,102,120,61,75,101,
        46,112,114,111,116,111,116,121,112,101,46,105,110,105,116,44,83,46,102,120,46,115,116,101,112,61,123,125,59,118,97,114,32,90,101,44,101,116,44,116,116,44,110,116,44,114,116,61,47,94,40,63,58,116,
        111,103,103,108,101,124,115,104,111,119,124,104,105,100,101,41,36,47,44,105,116,61,47,113,117,101,117,101,72,111,111,107,115,36,47,59,102,117,110,99,116,105,111,110,32,111,116,40,41,123,101,116,
        38,38,40,33,49,61,61,61,69,46,104,105,100,100,101,110,38,38,67,46,114,101,113,117,101,115,116,65,110,105,109,97,116,105,111,110,70,114,97,109,101,63,67,46,114,101,113,117,101,115,116,65,110,105,
        109,97,116,105,111,110,70,114,97,109,101,40,111,116,41,58,67,46,115,101,116,84,105,109,101,111,117,116,40,111,116,44,83,46,102,120,46,105,110,116,101,114,118,97,108,41,44,83,46,102,120,46,116,105,
        99,107,40,41,41,125,102,117,110,99,116,105,111,110,32,97,116,40,41,123,114,101,116,117,114,110,32,67,46,115,101,116,84,105,109,101,111,117,116,40,102,117,110,99,116,105,111,110,40,41,123,90,101,
        61,118,111,105,100,32,48,125,41,44,90,101,61,68,97,116,101,46,110,111,119,40,41,125,102,117,110,99,116,105,111,110,32,115,116,40,101,44,116,41,123,118,97,114,32,110,44,114,61,48,44,105,61,123,104,
        101,105,103,104,116,58,101,125,59,102,111,114,40,116,61,116,63,49,58,48,59,114,60,52,59,114,43,61,50,45,116,41,105,91,34,109,97,114,103,105,110,34,43,40,110,61,110,101,91,114,93,41,93,61,105,91,
        34,112,97,100,100,105,110,103,34,43,110,93,61,101,59,114,101,116,117,114,110,32,116,38,38,40,105,46,111,112,97,99,105,116,121,61,105,46,119,105,100,116,104,61,101,41,44,105,125,102,117,110,99,116,
        105,111,110,32,117,116,40,101,44,116,44,110,41,123,102,111,114,40,118,97,114,32,114,44,105,61,40,108,116,46,116,119,101,101,110,101,114,115,91,116,93,124,124,91,93,41,46,99,111,110,99,97,116,40,
        108,116,46,116,119,101,101,110,101,114,115,91,34,42,34,93,41,44,111,61,48,44,97,61,105,46,108,101,110,103,116,104,59,111,60,97,59,111,43,43,41,105,102,40,114,61,105,91,111,93,46,99,97,108,108,40,
        110,44,116,44,101,41,41,114,101,116,117,114,110,32,114,125,102,117,110,99,116,105,111,110,32,108,116,40,111,44,101,44,116,41,123,118,97,114,32,110,44,97,44,114,61,48,44,105,61,108,116,46,112,114,
        101,102,105,108,116,101,114,115,46,108,101,110,103,116,104,44,115,61,83,46,68,101,102,101,114,114,101,100,40,41,46,97,108,119,97,121,115,40,102,117,110,99,116,105,111,110,40,41,123,100,101,108,101,
        116,101,32,117,46,101,108,101,109,125,41,44,117,61,102,117,110,99,116,105,111,110,40,41,123,105,102,40,97,41,114,101,116,117,114,110,33,49,59,102,111,114,40,118,97,114,32,101,61,90,101,124,124,97,
        116,40,41,44,116,61,77,97,116,104,46,109,97,120,40,48,44,108,46,115,116,97,114,116,84,105,109,101,43,108,46,100,117,114,97,116,105,111,110,45,101,41,44,110,61,49,45,40,116,47,108,46,100,117,114,
        97,116,105,111,110,124,124,48,41,44,114,61,48,44,105,61,108,46,116,119,101,101,110,115,46,108,101,110,103,116,104,59,114,60,105,59,114,43,43,41,108,46,116,119,101,101,110,115,91,114,93,46,114,117,
        110,40,110,41,59,114,101,116,117,114,110,32,115,46,110,111,116,105,102,121,87,105,116,104,40,111,44,91,108,44,110,44,116,93,41,44,110,60,49,38,38,105,63,116,58,40,105,124,124,115,46,110,111,116,
        105,102,121,87,105,116,104,40,111,44,91,108,44,49,44,48,93,41,44,115,46,114,101,115,111,108,118,101,87,105,116,104,40,111,44,91,108,93,41,44,33,49,41,125,44,108,61,115,46,112,114,111,109,105,115,
        101,40,123,101,108,101,109,58,111,44,112,114,111,112,115,58,83,46,101,120,116,101,110,100,40,123,125,44,101,41,44,111,112,116,115,58,83,46,101,120,116,101,110,100,40,33,48,44,123,115,112,101,99,
        105,97,108,69,97,115,105,110,103,58,123,125,44,101,97,115,105,110,103,58,83,46,101,97,115,105,110,103,46,95,100,101,102,97,117,108,116,125,44,116,41,44,111,114,105,103,105,110,97,108,80,114,111,
        112,101,114,116,105,101,115,58,101,44,111,114,105,103,105,110,97,108,79,112,116,105,111,110,115,58,116,44,115,116,97,114,116,84,105,109,101,58,90,101,124,124,97,116,40,41,44,100,117,114,97,116,105,
        111,110,58,116,46,100,117,114,97,116,105,111,110,44,116,119,101,101,110,115,58,91,93,44,99,114,101,97,116,101,84,119,101,101,110,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,
        32,110,61,83,46,84,119,101,101,110,40,111,44,108,46,111,112,116,115,44,101,44,116,44,108,46,111,112,116,115,46,115,112,101,99,105,97,108,69,97,115,105,110,103,91,101,93,124,124,108,46,111,112,116,
        115,46,101,97,115,105,110,103,41,59,114,101,116,117,114,110,32,108,46,116,119,101,101,110,115,46,112,117,115,104,40,110,41,44,110,125,44,115,116,111,112,58,102,117,110,99,116,105,111,110,40,101,
        41,123,118,97,114,32,116,61,48,44,110,61,101,63,108,46,116,119,101,101,110,115,46,108,101,110,103,116,104,58,48,59,105,102,40,97,41,114,101,116,117,114,110,32,116,104,105,115,59,102,111,114,40,97,
        61,33,48,59,116,60,110,59,116,43,43,41,108,46,116,119,101,101,110,115,91,116,93,46,114,117,110,40,49,41,59,114,101,116,117,114,110,32,101,63,40,115,46,110,111,116,105,102,121,87,105,116,104,40,111,
        44,91,108,44,49,44,48,93,41,44,115,46,114,101,115,111,108,118,101,87,105,116,104,40,111,44,91,108,44,101,93,41,41,58,115,46,114,101,106,101,99,116,87,105,116,104,40,111,44,91,108,44,101,93,41,44,
        116,104,105,115,125,125,41,44,99,61,108,46,112,114,111,112,115,59,102,111,114,40,33,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,44,114,44,105,44,111,44,97,59,102,111,114,
        40,110,32,105,110,32,101,41,105,102,40,105,61,116,91,114,61,88,40,110,41,93,44,111,61,101,91,110,93,44,65,114,114,97,121,46,105,115,65,114,114,97,121,40,111,41,38,38,40,105,61,111,91,49,93,44,111,
        61,101,91,110,93,61,111,91,48,93,41,44,110,33,61,61,114,38,38,40,101,91,114,93,61,111,44,100,101,108,101,116,101,32,101,91,110,93,41,44,40,97,61,83,46,99,115,115,72,111,111,107,115,91,114,93,41,
        38,38,34,101,120,112,97,110,100,34,105,110,32,97,41,102,111,114,40,110,32,105,110,32,111,61,97,46,101,120,112,97,110,100,40,111,41,44,100,101,108,101,116,101,32,101,91,114,93,44,111,41,110,32,105,
        110,32,101,124,124,40,101,91,110,93,61,111,91,110,93,44,116,91,110,93,61,105,41,59,101,108,115,101,32,116,91,114,93,61,105,125,40,99,44,108,46,111,112,116,115,46,115,112,101,99,105,97,108,69,97,
        115,105,110,103,41,59,114,60,105,59,114,43,43,41,105,102,40,110,61,108,116,46,112,114,101,102,105,108,116,101,114,115,91,114,93,46,99,97,108,108,40,108,44,111,44,99,44,108,46,111,112,116,115,41,
        41,114,101,116,117,114,110,32,109,40,110,46,115,116,111,112,41,38,38,40,83,46,95,113,117,101,117,101,72,111,111,107,115,40,108,46,101,108,101,109,44,108,46,111,112,116,115,46,113,117,101,117,101,
        41,46,115,116,111,112,61,110,46,115,116,111,112,46,98,105,110,100,40,110,41,41,44,110,59,114,101,116,117,114,110,32,83,46,109,97,112,40,99,44,117,116,44,108,41,44,109,40,108,46,111,112,116,115,46,
        115,116,97,114,116,41,38,38,108,46,111,112,116,115,46,115,116,97,114,116,46,99,97,108,108,40,111,44,108,41,44,108,46,112,114,111,103,114,101,115,115,40,108,46,111,112,116,115,46,112,114,111,103,
        114,101,115,115,41,46,100,111,110,101,40,108,46,111,112,116,115,46,100,111,110,101,44,108,46,111,112,116,115,46,99,111,109,112,108,101,116,101,41,46,102,97,105,108,40,108,46,111,112,116,115,46,102,
        97,105,108,41,46,97,108,119,97,121,115,40,108,46,111,112,116,115,46,97,108,119,97,121,115,41,44,83,46,102,120,46,116,105,109,101,114,40,83,46,101,120,116,101,110,100,40,117,44,123,101,108,101,109,
        58,111,44,97,110,105,109,58,108,44,113,117,101,117,101,58,108,46,111,112,116,115,46,113,117,101,117,101,125,41,41,44,108,125,83,46,65,110,105,109,97,116,105,111,110,61,83,46,101,120,116,101,110,
        100,40,108,116,44,123,116,119,101,101,110,101,114,115,58,123,34,42,34,58,91,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,61,116,104,105,115,46,99,114,101,97,116,101,84,119,
        101,101,110,40,101,44,116,41,59,114,101,116,117,114,110,32,115,101,40,110,46,101,108,101,109,44,101,44,116,101,46,101,120,101,99,40,116,41,44,110,41,44,110,125,93,125,44,116,119,101,101,110,101,
        114,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,109,40,101,41,63,40,116,61,101,44,101,61,91,34,42,34,93,41,58,101,61,101,46,109,97,116,99,104,40,80,41,59,102,111,114,40,118,97,114,32,
        110,44,114,61,48,44,105,61,101,46,108,101,110,103,116,104,59,114,60,105,59,114,43,43,41,110,61,101,91,114,93,44,108,116,46,116,119,101,101,110,101,114,115,91,110,93,61,108,116,46,116,119,101,101,
        110,101,114,115,91,110,93,124,124,91,93,44,108,116,46,116,119,101,101,110,101,114,115,91,110,93,46,117,110,115,104,105,102,116,40,116,41,125,44,112,114,101,102,105,108,116,101,114,115,58,91,102,
        117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,44,105,44,111,44,97,44,115,44,117,44,108,44,99,44,102,61,34,119,105,100,116,104,34,105,110,32,116,124,124,34,104,101,105,
        103,104,116,34,105,110,32,116,44,112,61,116,104,105,115,44,100,61,123,125,44,104,61,101,46,115,116,121,108,101,44,103,61,101,46,110,111,100,101,84,121,112,101,38,38,97,101,40,101,41,44,118,61,89,
        46,103,101,116,40,101,44,34,102,120,115,104,111,119,34,41,59,102,111,114,40,114,32,105,110,32,110,46,113,117,101,117,101,124,124,40,110,117,108,108,61,61,40,97,61,83,46,95,113,117,101,117,101,72,
        111,111,107,115,40,101,44,34,102,120,34,41,41,46,117,110,113,117,101,117,101,100,38,38,40,97,46,117,110,113,117,101,117,101,100,61,48,44,115,61,97,46,101,109,112,116,121,46,102,105,114,101,44,97,
        46,101,109,112,116,121,46,102,105,114,101,61,102,117,110,99,116,105,111,110,40,41,123,97,46,117,110,113,117,101,117,101,100,124,124,115,40,41,125,41,44,97,46,117,110,113,117,101,117,101,100,43,43,
        44,112,46,97,108,119,97,121,115,40,102,117,110,99,116,105,111,110,40,41,123,112,46,97,108,119,97,121,115,40,102,117,110,99,116,105,111,110,40,41,123,97,46,117,110,113,117,101,117,101,100,45,45,44,
        83,46,113,117,101,117,101,40,101,44,34,102,120,34,41,46,108,101,110,103,116,104,124,124,97,46,101,109,112,116,121,46,102,105,114,101,40,41,125,41,125,41,41,44,116,41,105,102,40,105,61,116,91,114,
        93,44,114,116,46,116,101,115,116,40,105,41,41,123,105,102,40,100,101,108,101,116,101,32,116,91,114,93,44,111,61,111,124,124,34,116,111,103,103,108,101,34,61,61,61,105,44,105,61,61,61,40,103,63,34,
        104,105,100,101,34,58,34,115,104,111,119,34,41,41,123,105,102,40,34,115,104,111,119,34,33,61,61,105,124,124,33,118,124,124,118,111,105,100,32,48,61,61,61,118,91,114,93,41,99,111,110,116,105,110,
        117,101,59,103,61,33,48,125,100,91,114,93,61,118,38,38,118,91,114,93,124,124,83,46,115,116,121,108,101,40,101,44,114,41,125,105,102,40,40,117,61,33,83,46,105,115,69,109,112,116,121,79,98,106,101,
        99,116,40,116,41,41,124,124,33,83,46,105,115,69,109,112,116,121,79,98,106,101,99,116,40,100,41,41,102,111,114,40,114,32,105,110,32,102,38,38,49,61,61,61,101,46,110,111,100,101,84,121,112,101,38,
        38,40,110,46,111,118,101,114,102,108,111,119,61,91,104,46,111,118,101,114,102,108,111,119,44,104,46,111,118,101,114,102,108,111,119,88,44,104,46,111,118,101,114,102,108,111,119,89,93,44,110,117,
        108,108,61,61,40,108,61,118,38,38,118,46,100,105,115,112,108,97,121,41,38,38,40,108,61,89,46,103,101,116,40,101,44,34,100,105,115,112,108,97,121,34,41,41,44,34,110,111,110,101,34,61,61,61,40,99,
        61,83,46,99,115,115,40,101,44,34,100,105,115,112,108,97,121,34,41,41,38,38,40,108,63,99,61,108,58,40,108,101,40,91,101,93,44,33,48,41,44,108,61,101,46,115,116,121,108,101,46,100,105,115,112,108,
        97,121,124,124,108,44,99,61,83,46,99,115,115,40,101,44,34,100,105,115,112,108,97,121,34,41,44,108,101,40,91,101,93,41,41,41,44,40,34,105,110,108,105,110,101,34,61,61,61,99,124,124,34,105,110,108,
        105,110,101,45,98,108,111,99,107,34,61,61,61,99,38,38,110,117,108,108,33,61,108,41,38,38,34,110,111,110,101,34,61,61,61,83,46,99,115,115,40,101,44,34,102,108,111,97,116,34,41,38,38,40,117,124,124,
        40,112,46,100,111,110,101,40,102,117,110,99,116,105,111,110,40,41,123,104,46,100,105,115,112,108,97,121,61,108,125,41,44,110,117,108,108,61,61,108,38,38,40,99,61,104,46,100,105,115,112,108,97,121,
        44,108,61,34,110,111,110,101,34,61,61,61,99,63,34,34,58,99,41,41,44,104,46,100,105,115,112,108,97,121,61,34,105,110,108,105,110,101,45,98,108,111,99,107,34,41,41,44,110,46,111,118,101,114,102,108,
        111,119,38,38,40,104,46,111,118,101,114,102,108,111,119,61,34,104,105,100,100,101,110,34,44,112,46,97,108,119,97,121,115,40,102,117,110,99,116,105,111,110,40,41,123,104,46,111,118,101,114,102,108,
        111,119,61,110,46,111,118,101,114,102,108,111,119,91,48,93,44,104,46,111,118,101,114,102,108,111,119,88,61,110,46,111,118,101,114,102,108,111,119,91,49,93,44,104,46,111,118,101,114,102,108,111,119,
        89,61,110,46,111,118,101,114,102,108,111,119,91,50,93,125,41,41,44,117,61,33,49,44,100,41,117,124,124,40,118,63,34,104,105,100,100,101,110,34,105,110,32,118,38,38,40,103,61,118,46,104,105,100,100,
        101,110,41,58,118,61,89,46,97,99,99,101,115,115,40,101,44,34,102,120,115,104,111,119,34,44,123,100,105,115,112,108,97,121,58,108,125,41,44,111,38,38,40,118,46,104,105,100,100,101,110,61,33,103,41,
        44,103,38,38,108,101,40,91,101,93,44,33,48,41,44,112,46,100,111,110,101,40,102,117,110,99,116,105,111,110,40,41,123,102,111,114,40,114,32,105,110,32,103,124,124,108,101,40,91,101,93,41,44,89,46,
        114,101,109,111,118,101,40,101,44,34,102,120,115,104,111,119,34,41,44,100,41,83,46,115,116,121,108,101,40,101,44,114,44,100,91,114,93,41,125,41,41,44,117,61,117,116,40,103,63,118,91,114,93,58,48,
        44,114,44,112,41,44,114,32,105,110,32,118,124,124,40,118,91,114,93,61,117,46,115,116,97,114,116,44,103,38,38,40,117,46,101,110,100,61,117,46,115,116,97,114,116,44,117,46,115,116,97,114,116,61,48,
        41,41,125,93,44,112,114,101,102,105,108,116,101,114,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,116,63,108,116,46,112,114,101,102,105,108,116,101,114,115,46,117,110,115,104,105,102,116,
        40,101,41,58,108,116,46,112,114,101,102,105,108,116,101,114,115,46,112,117,115,104,40,101,41,125,125,41,44,83,46,115,112,101,101,100,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,
        118,97,114,32,114,61,101,38,38,34,111,98,106,101,99,116,34,61,61,116,121,112,101,111,102,32,101,63,83,46,101,120,116,101,110,100,40,123,125,44,101,41,58,123,99,111,109,112,108,101,116,101,58,110,
        124,124,33,110,38,38,116,124,124,109,40,101,41,38,38,101,44,100,117,114,97,116,105,111,110,58,101,44,101,97,115,105,110,103,58,110,38,38,116,124,124,116,38,38,33,109,40,116,41,38,38,116,125,59,114,
        101,116,117,114,110,32,83,46,102,120,46,111,102,102,63,114,46,100,117,114,97,116,105,111,110,61,48,58,34,110,117,109,98,101,114,34,33,61,116,121,112,101,111,102,32,114,46,100,117,114,97,116,105,
        111,110,38,38,40,114,46,100,117,114,97,116,105,111,110,32,105,110,32,83,46,102,120,46,115,112,101,101,100,115,63,114,46,100,117,114,97,116,105,111,110,61,83,46,102,120,46,115,112,101,101,100,115,
        91,114,46,100,117,114,97,116,105,111,110,93,58,114,46,100,117,114,97,116,105,111,110,61,83,46,102,120,46,115,112,101,101,100,115,46,95,100,101,102,97,117,108,116,41,44,110,117,108,108,33,61,114,
        46,113,117,101,117,101,38,38,33,48,33,61,61,114,46,113,117,101,117,101,124,124,40,114,46,113,117,101,117,101,61,34,102,120,34,41,44,114,46,111,108,100,61,114,46,99,111,109,112,108,101,116,101,44,
        114,46,99,111,109,112,108,101,116,101,61,102,117,110,99,116,105,111,110,40,41,123,109,40,114,46,111,108,100,41,38,38,114,46,111,108,100,46,99,97,108,108,40,116,104,105,115,41,44,114,46,113,117,101,
        117,101,38,38,83,46,100,101,113,117,101,117,101,40,116,104,105,115,44,114,46,113,117,101,117,101,41,125,44,114,125,44,83,46,102,110,46,101,120,116,101,110,100,40,123,102,97,100,101,84,111,58,102,
        117,110,99,116,105,111,110,40,101,44,116,44,110,44,114,41,123,114,101,116,117,114,110,32,116,104,105,115,46,102,105,108,116,101,114,40,97,101,41,46,99,115,115,40,34,111,112,97,99,105,116,121,34,
        44,48,41,46,115,104,111,119,40,41,46,101,110,100,40,41,46,97,110,105,109,97,116,101,40,123,111,112,97,99,105,116,121,58,116,125,44,101,44,110,44,114,41,125,44,97,110,105,109,97,116,101,58,102,117,
        110,99,116,105,111,110,40,116,44,101,44,110,44,114,41,123,118,97,114,32,105,61,83,46,105,115,69,109,112,116,121,79,98,106,101,99,116,40,116,41,44,111,61,83,46,115,112,101,101,100,40,101,44,110,44,
        114,41,44,97,61,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,61,108,116,40,116,104,105,115,44,83,46,101,120,116,101,110,100,40,123,125,44,116,41,44,111,41,59,40,105,124,124,89,46,103,
        101,116,40,116,104,105,115,44,34,102,105,110,105,115,104,34,41,41,38,38,101,46,115,116,111,112,40,33,48,41,125,59,114,101,116,117,114,110,32,97,46,102,105,110,105,115,104,61,97,44,105,124,124,33,
        49,61,61,61,111,46,113,117,101,117,101,63,116,104,105,115,46,101,97,99,104,40,97,41,58,116,104,105,115,46,113,117,101,117,101,40,111,46,113,117,101,117,101,44,97,41,125,44,115,116,111,112,58,102,
        117,110,99,116,105,111,110,40,105,44,101,44,111,41,123,118,97,114,32,97,61,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,101,46,115,116,111,112,59,100,101,108,101,116,101,32,
        101,46,115,116,111,112,44,116,40,111,41,125,59,114,101,116,117,114,110,34,115,116,114,105,110,103,34,33,61,116,121,112,101,111,102,32,105,38,38,40,111,61,101,44,101,61,105,44,105,61,118,111,105,
        100,32,48,41,44,101,38,38,116,104,105,115,46,113,117,101,117,101,40,105,124,124,34,102,120,34,44,91,93,41,44,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,41,123,118,97,114,
        32,101,61,33,48,44,116,61,110,117,108,108,33,61,105,38,38,105,43,34,113,117,101,117,101,72,111,111,107,115,34,44,110,61,83,46,116,105,109,101,114,115,44,114,61,89,46,103,101,116,40,116,104,105,115,
        41,59,105,102,40,116,41,114,91,116,93,38,38,114,91,116,93,46,115,116,111,112,38,38,97,40,114,91,116,93,41,59,101,108,115,101,32,102,111,114,40,116,32,105,110,32,114,41,114,91,116,93,38,38,114,91,
        116,93,46,115,116,111,112,38,38,105,116,46,116,101,115,116,40,116,41,38,38,97,40,114,91,116,93,41,59,102,111,114,40,116,61,110,46,108,101,110,103,116,104,59,116,45,45,59,41,110,91,116,93,46,101,
        108,101,109,33,61,61,116,104,105,115,124,124,110,117,108,108,33,61,105,38,38,110,91,116,93,46,113,117,101,117,101,33,61,61,105,124,124,40,110,91,116,93,46,97,110,105,109,46,115,116,111,112,40,111,
        41,44,101,61,33,49,44,110,46,115,112,108,105,99,101,40,116,44,49,41,41,59,33,101,38,38,111,124,124,83,46,100,101,113,117,101,117,101,40,116,104,105,115,44,105,41,125,41,125,44,102,105,110,105,115,
        104,58,102,117,110,99,116,105,111,110,40,97,41,123,114,101,116,117,114,110,33,49,33,61,61,97,38,38,40,97,61,97,124,124,34,102,120,34,41,44,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,
        105,111,110,40,41,123,118,97,114,32,101,44,116,61,89,46,103,101,116,40,116,104,105,115,41,44,110,61,116,91,97,43,34,113,117,101,117,101,34,93,44,114,61,116,91,97,43,34,113,117,101,117,101,72,111,
        111,107,115,34,93,44,105,61,83,46,116,105,109,101,114,115,44,111,61,110,63,110,46,108,101,110,103,116,104,58,48,59,102,111,114,40,116,46,102,105,110,105,115,104,61,33,48,44,83,46,113,117,101,117,
        101,40,116,104,105,115,44,97,44,91,93,41,44,114,38,38,114,46,115,116,111,112,38,38,114,46,115,116,111,112,46,99,97,108,108,40,116,104,105,115,44,33,48,41,44,101,61,105,46,108,101,110,103,116,104,
        59,101,45,45,59,41,105,91,101,93,46,101,108,101,109,61,61,61,116,104,105,115,38,38,105,91,101,93,46,113,117,101,117,101,61,61,61,97,38,38,40,105,91,101,93,46,97,110,105,109,46,115,116,111,112,40,
        33,48,41,44,105,46,115,112,108,105,99,101,40,101,44,49,41,41,59,102,111,114,40,101,61,48,59,101,60,111,59,101,43,43,41,110,91,101,93,38,38,110,91,101,93,46,102,105,110,105,115,104,38,38,110,91,101,
        93,46,102,105,110,105,115,104,46,99,97,108,108,40,116,104,105,115,41,59,100,101,108,101,116,101,32,116,46,102,105,110,105,115,104,125,41,125,125,41,44,83,46,101,97,99,104,40,91,34,116,111,103,103,
        108,101,34,44,34,115,104,111,119,34,44,34,104,105,100,101,34,93,44,102,117,110,99,116,105,111,110,40,101,44,114,41,123,118,97,114,32,105,61,83,46,102,110,91,114,93,59,83,46,102,110,91,114,93,61,
        102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,114,101,116,117,114,110,32,110,117,108,108,61,61,101,124,124,34,98,111,111,108,101,97,110,34,61,61,116,121,112,101,111,102,32,101,63,105,
        46,97,112,112,108,121,40,116,104,105,115,44,97,114,103,117,109,101,110,116,115,41,58,116,104,105,115,46,97,110,105,109,97,116,101,40,115,116,40,114,44,33,48,41,44,101,44,116,44,110,41,125,125,41,
        44,83,46,101,97,99,104,40,123,115,108,105,100,101,68,111,119,110,58,115,116,40,34,115,104,111,119,34,41,44,115,108,105,100,101,85,112,58,115,116,40,34,104,105,100,101,34,41,44,115,108,105,100,101,
        84,111,103,103,108,101,58,115,116,40,34,116,111,103,103,108,101,34,41,44,102,97,100,101,73,110,58,123,111,112,97,99,105,116,121,58,34,115,104,111,119,34,125,44,102,97,100,101,79,117,116,58,123,111,
        112,97,99,105,116,121,58,34,104,105,100,101,34,125,44,102,97,100,101,84,111,103,103,108,101,58,123,111,112,97,99,105,116,121,58,34,116,111,103,103,108,101,34,125,125,44,102,117,110,99,116,105,111,
        110,40,101,44,114,41,123,83,46,102,110,91,101,93,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,114,101,116,117,114,110,32,116,104,105,115,46,97,110,105,109,97,116,101,40,114,44,101,
        44,116,44,110,41,125,125,41,44,83,46,116,105,109,101,114,115,61,91,93,44,83,46,102,120,46,116,105,99,107,61,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,44,116,61,48,44,110,61,83,46,
        116,105,109,101,114,115,59,102,111,114,40,90,101,61,68,97,116,101,46,110,111,119,40,41,59,116,60,110,46,108,101,110,103,116,104,59,116,43,43,41,40,101,61,110,91,116,93,41,40,41,124,124,110,91,116,
        93,33,61,61,101,124,124,110,46,115,112,108,105,99,101,40,116,45,45,44,49,41,59,110,46,108,101,110,103,116,104,124,124,83,46,102,120,46,115,116,111,112,40,41,44,90,101,61,118,111,105,100,32,48,125,
        44,83,46,102,120,46,116,105,109,101,114,61,102,117,110,99,116,105,111,110,40,101,41,123,83,46,116,105,109,101,114,115,46,112,117,115,104,40,101,41,44,83,46,102,120,46,115,116,97,114,116,40,41,125,
        44,83,46,102,120,46,105,110,116,101,114,118,97,108,61,49,51,44,83,46,102,120,46,115,116,97,114,116,61,102,117,110,99,116,105,111,110,40,41,123,101,116,124,124,40,101,116,61,33,48,44,111,116,40,41,
        41,125,44,83,46,102,120,46,115,116,111,112,61,102,117,110,99,116,105,111,110,40,41,123,101,116,61,110,117,108,108,125,44,83,46,102,120,46,115,112,101,101,100,115,61,123,115,108,111,119,58,54,48,
        48,44,102,97,115,116,58,50,48,48,44,95,100,101,102,97,117,108,116,58,52,48,48,125,44,83,46,102,110,46,100,101,108,97,121,61,102,117,110,99,116,105,111,110,40,114,44,101,41,123,114,101,116,117,114,
        110,32,114,61,83,46,102,120,38,38,83,46,102,120,46,115,112,101,101,100,115,91,114,93,124,124,114,44,101,61,101,124,124,34,102,120,34,44,116,104,105,115,46,113,117,101,117,101,40,101,44,102,117,110,
        99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,61,67,46,115,101,116,84,105,109,101,111,117,116,40,101,44,114,41,59,116,46,115,116,111,112,61,102,117,110,99,116,105,111,110,40,41,123,67,
        46,99,108,101,97,114,84,105,109,101,111,117,116,40,110,41,125,125,41,125,44,116,116,61,69,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,105,110,112,117,116,34,41,44,110,116,61,69,46,
        99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,115,101,108,101,99,116,34,41,46,97,112,112,101,110,100,67,104,105,108,100,40,69,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,111,
        112,116,105,111,110,34,41,41,44,116,116,46,116,121,112,101,61,34,99,104,101,99,107,98,111,120,34,44,121,46,99,104,101,99,107,79,110,61,34,34,33,61,61,116,116,46,118,97,108,117,101,44,121,46,111,
        112,116,83,101,108,101,99,116,101,100,61,110,116,46,115,101,108,101,99,116,101,100,44,40,116,116,61,69,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,105,110,112,117,116,34,41,41,46,118,
        97,108,117,101,61,34,116,34,44,116,116,46,116,121,112,101,61,34,114,97,100,105,111,34,44,121,46,114,97,100,105,111,86,97,108,117,101,61,34,116,34,61,61,61,116,116,46,118,97,108,117,101,59,118,97,
        114,32,99,116,44,102,116,61,83,46,101,120,112,114,46,97,116,116,114,72,97,110,100,108,101,59,83,46,102,110,46,101,120,116,101,110,100,40,123,97,116,116,114,58,102,117,110,99,116,105,111,110,40,101,
        44,116,41,123,114,101,116,117,114,110,32,36,40,116,104,105,115,44,83,46,97,116,116,114,44,101,44,116,44,49,60,97,114,103,117,109,101,110,116,115,46,108,101,110,103,116,104,41,125,44,114,101,109,
        111,118,101,65,116,116,114,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,41,123,83,46,114,101,109,
        111,118,101,65,116,116,114,40,116,104,105,115,44,101,41,125,41,125,125,41,44,83,46,101,120,116,101,110,100,40,123,97,116,116,114,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,
        97,114,32,114,44,105,44,111,61,101,46,110,111,100,101,84,121,112,101,59,105,102,40,51,33,61,61,111,38,38,56,33,61,61,111,38,38,50,33,61,61,111,41,114,101,116,117,114,110,34,117,110,100,101,102,105,
        110,101,100,34,61,61,116,121,112,101,111,102,32,101,46,103,101,116,65,116,116,114,105,98,117,116,101,63,83,46,112,114,111,112,40,101,44,116,44,110,41,58,40,49,61,61,61,111,38,38,83,46,105,115,88,
        77,76,68,111,99,40,101,41,124,124,40,105,61,83,46,97,116,116,114,72,111,111,107,115,91,116,46,116,111,76,111,119,101,114,67,97,115,101,40,41,93,124,124,40,83,46,101,120,112,114,46,109,97,116,99,
        104,46,98,111,111,108,46,116,101,115,116,40,116,41,63,99,116,58,118,111,105,100,32,48,41,41,44,118,111,105,100,32,48,33,61,61,110,63,110,117,108,108,61,61,61,110,63,118,111,105,100,32,83,46,114,
        101,109,111,118,101,65,116,116,114,40,101,44,116,41,58,105,38,38,34,115,101,116,34,105,110,32,105,38,38,118,111,105,100,32,48,33,61,61,40,114,61,105,46,115,101,116,40,101,44,110,44,116,41,41,63,
        114,58,40,101,46,115,101,116,65,116,116,114,105,98,117,116,101,40,116,44,110,43,34,34,41,44,110,41,58,105,38,38,34,103,101,116,34,105,110,32,105,38,38,110,117,108,108,33,61,61,40,114,61,105,46,103,
        101,116,40,101,44,116,41,41,63,114,58,110,117,108,108,61,61,40,114,61,83,46,102,105,110,100,46,97,116,116,114,40,101,44,116,41,41,63,118,111,105,100,32,48,58,114,41,125,44,97,116,116,114,72,111,
        111,107,115,58,123,116,121,112,101,58,123,115,101,116,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,105,102,40,33,121,46,114,97,100,105,111,86,97,108,117,101,38,38,34,114,97,100,105,111,
        34,61,61,61,116,38,38,65,40,101,44,34,105,110,112,117,116,34,41,41,123,118,97,114,32,110,61,101,46,118,97,108,117,101,59,114,101,116,117,114,110,32,101,46,115,101,116,65,116,116,114,105,98,117,116,
        101,40,34,116,121,112,101,34,44,116,41,44,110,38,38,40,101,46,118,97,108,117,101,61,110,41,44,116,125,125,125,125,44,114,101,109,111,118,101,65,116,116,114,58,102,117,110,99,116,105,111,110,40,101,
        44,116,41,123,118,97,114,32,110,44,114,61,48,44,105,61,116,38,38,116,46,109,97,116,99,104,40,80,41,59,105,102,40,105,38,38,49,61,61,61,101,46,110,111,100,101,84,121,112,101,41,119,104,105,108,101,
        40,110,61,105,91,114,43,43,93,41,101,46,114,101,109,111,118,101,65,116,116,114,105,98,117,116,101,40,110,41,125,125,41,44,99,116,61,123,115,101,116,58,102,117,110,99,116,105,111,110,40,101,44,116,
        44,110,41,123,114,101,116,117,114,110,33,49,61,61,61,116,63,83,46,114,101,109,111,118,101,65,116,116,114,40,101,44,110,41,58,101,46,115,101,116,65,116,116,114,105,98,117,116,101,40,110,44,110,41,
        44,110,125,125,44,83,46,101,97,99,104,40,83,46,101,120,112,114,46,109,97,116,99,104,46,98,111,111,108,46,115,111,117,114,99,101,46,109,97,116,99,104,40,47,92,119,43,47,103,41,44,102,117,110,99,116,
        105,111,110,40,101,44,116,41,123,118,97,114,32,97,61,102,116,91,116,93,124,124,83,46,102,105,110,100,46,97,116,116,114,59,102,116,91,116,93,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,
        41,123,118,97,114,32,114,44,105,44,111,61,116,46,116,111,76,111,119,101,114,67,97,115,101,40,41,59,114,101,116,117,114,110,32,110,124,124,40,105,61,102,116,91,111,93,44,102,116,91,111,93,61,114,
        44,114,61,110,117,108,108,33,61,97,40,101,44,116,44,110,41,63,111,58,110,117,108,108,44,102,116,91,111,93,61,105,41,44,114,125,125,41,59,118,97,114,32,112,116,61,47,94,40,63,58,105,110,112,117,116,
        124,115,101,108,101,99,116,124,116,101,120,116,97,114,101,97,124,98,117,116,116,111,110,41,36,47,105,44,100,116,61,47,94,40,63,58,97,124,97,114,101,97,41,36,47,105,59,102,117,110,99,116,105,111,
        110,32,104,116,40,101,41,123,114,101,116,117,114,110,40,101,46,109,97,116,99,104,40,80,41,124,124,91,93,41,46,106,111,105,110,40,34,32,34,41,125,102,117,110,99,116,105,111,110,32,103,116,40,101,
        41,123,114,101,116,117,114,110,32,101,46,103,101,116,65,116,116,114,105,98,117,116,101,38,38,101,46,103,101,116,65,116,116,114,105,98,117,116,101,40,34,99,108,97,115,115,34,41,124,124,34,34,125,
        102,117,110,99,116,105,111,110,32,118,116,40,101,41,123,114,101,116,117,114,110,32,65,114,114,97,121,46,105,115,65,114,114,97,121,40,101,41,63,101,58,34,115,116,114,105,110,103,34,61,61,116,121,
        112,101,111,102,32,101,38,38,101,46,109,97,116,99,104,40,80,41,124,124,91,93,125,83,46,102,110,46,101,120,116,101,110,100,40,123,112,114,111,112,58,102,117,110,99,116,105,111,110,40,101,44,116,41,
        123,114,101,116,117,114,110,32,36,40,116,104,105,115,44,83,46,112,114,111,112,44,101,44,116,44,49,60,97,114,103,117,109,101,110,116,115,46,108,101,110,103,116,104,41,125,44,114,101,109,111,118,101,
        80,114,111,112,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,41,123,100,101,108,101,116,101,32,
        116,104,105,115,91,83,46,112,114,111,112,70,105,120,91,101,93,124,124,101,93,125,41,125,125,41,44,83,46,101,120,116,101,110,100,40,123,112,114,111,112,58,102,117,110,99,116,105,111,110,40,101,44,
        116,44,110,41,123,118,97,114,32,114,44,105,44,111,61,101,46,110,111,100,101,84,121,112,101,59,105,102,40,51,33,61,61,111,38,38,56,33,61,61,111,38,38,50,33,61,61,111,41,114,101,116,117,114,110,32,
        49,61,61,61,111,38,38,83,46,105,115,88,77,76,68,111,99,40,101,41,124,124,40,116,61,83,46,112,114,111,112,70,105,120,91,116,93,124,124,116,44,105,61,83,46,112,114,111,112,72,111,111,107,115,91,116,
        93,41,44,118,111,105,100,32,48,33,61,61,110,63,105,38,38,34,115,101,116,34,105,110,32,105,38,38,118,111,105,100,32,48,33,61,61,40,114,61,105,46,115,101,116,40,101,44,110,44,116,41,41,63,114,58,101,
        91,116,93,61,110,58,105,38,38,34,103,101,116,34,105,110,32,105,38,38,110,117,108,108,33,61,61,40,114,61,105,46,103,101,116,40,101,44,116,41,41,63,114,58,101,91,116,93,125,44,112,114,111,112,72,111,
        111,107,115,58,123,116,97,98,73,110,100,101,120,58,123,103,101,116,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,83,46,102,105,110,100,46,97,116,116,114,40,101,44,34,116,97,
        98,105,110,100,101,120,34,41,59,114,101,116,117,114,110,32,116,63,112,97,114,115,101,73,110,116,40,116,44,49,48,41,58,112,116,46,116,101,115,116,40,101,46,110,111,100,101,78,97,109,101,41,124,124,
        100,116,46,116,101,115,116,40,101,46,110,111,100,101,78,97,109,101,41,38,38,101,46,104,114,101,102,63,48,58,45,49,125,125,125,44,112,114,111,112,70,105,120,58,123,34,102,111,114,34,58,34,104,116,
        109,108,70,111,114,34,44,34,99,108,97,115,115,34,58,34,99,108,97,115,115,78,97,109,101,34,125,125,41,44,121,46,111,112,116,83,101,108,101,99,116,101,100,124,124,40,83,46,112,114,111,112,72,111,111,
        107,115,46,115,101,108,101,99,116,101,100,61,123,103,101,116,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,101,46,112,97,114,101,110,116,78,111,100,101,59,114,101,116,117,
        114,110,32,116,38,38,116,46,112,97,114,101,110,116,78,111,100,101,38,38,116,46,112,97,114,101,110,116,78,111,100,101,46,115,101,108,101,99,116,101,100,73,110,100,101,120,44,110,117,108,108,125,44,
        115,101,116,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,101,46,112,97,114,101,110,116,78,111,100,101,59,116,38,38,40,116,46,115,101,108,101,99,116,101,100,73,110,100,101,
        120,44,116,46,112,97,114,101,110,116,78,111,100,101,38,38,116,46,112,97,114,101,110,116,78,111,100,101,46,115,101,108,101,99,116,101,100,73,110,100,101,120,41,125,125,41,44,83,46,101,97,99,104,40,
        91,34,116,97,98,73,110,100,101,120,34,44,34,114,101,97,100,79,110,108,121,34,44,34,109,97,120,76,101,110,103,116,104,34,44,34,99,101,108,108,83,112,97,99,105,110,103,34,44,34,99,101,108,108,80,97,
        100,100,105,110,103,34,44,34,114,111,119,83,112,97,110,34,44,34,99,111,108,83,112,97,110,34,44,34,117,115,101,77,97,112,34,44,34,102,114,97,109,101,66,111,114,100,101,114,34,44,34,99,111,110,116,
        101,110,116,69,100,105,116,97,98,108,101,34,93,44,102,117,110,99,116,105,111,110,40,41,123,83,46,112,114,111,112,70,105,120,91,116,104,105,115,46,116,111,76,111,119,101,114,67,97,115,101,40,41,93,
        61,116,104,105,115,125,41,44,83,46,102,110,46,101,120,116,101,110,100,40,123,97,100,100,67,108,97,115,115,58,102,117,110,99,116,105,111,110,40,116,41,123,118,97,114,32,101,44,110,44,114,44,105,44,
        111,44,97,44,115,44,117,61,48,59,105,102,40,109,40,116,41,41,114,101,116,117,114,110,32,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,101,41,123,83,40,116,104,105,115,41,
        46,97,100,100,67,108,97,115,115,40,116,46,99,97,108,108,40,116,104,105,115,44,101,44,103,116,40,116,104,105,115,41,41,41,125,41,59,105,102,40,40,101,61,118,116,40,116,41,41,46,108,101,110,103,116,
        104,41,119,104,105,108,101,40,110,61,116,104,105,115,91,117,43,43,93,41,105,102,40,105,61,103,116,40,110,41,44,114,61,49,61,61,61,110,46,110,111,100,101,84,121,112,101,38,38,34,32,34,43,104,116,
        40,105,41,43,34,32,34,41,123,97,61,48,59,119,104,105,108,101,40,111,61,101,91,97,43,43,93,41,114,46,105,110,100,101,120,79,102,40,34,32,34,43,111,43,34,32,34,41,60,48,38,38,40,114,43,61,111,43,34,
        32,34,41,59,105,33,61,61,40,115,61,104,116,40,114,41,41,38,38,110,46,115,101,116,65,116,116,114,105,98,117,116,101,40,34,99,108,97,115,115,34,44,115,41,125,114,101,116,117,114,110,32,116,104,105,
        115,125,44,114,101,109,111,118,101,67,108,97,115,115,58,102,117,110,99,116,105,111,110,40,116,41,123,118,97,114,32,101,44,110,44,114,44,105,44,111,44,97,44,115,44,117,61,48,59,105,102,40,109,40,
        116,41,41,114,101,116,117,114,110,32,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,101,41,123,83,40,116,104,105,115,41,46,114,101,109,111,118,101,67,108,97,115,115,40,116,
        46,99,97,108,108,40,116,104,105,115,44,101,44,103,116,40,116,104,105,115,41,41,41,125,41,59,105,102,40,33,97,114,103,117,109,101,110,116,115,46,108,101,110,103,116,104,41,114,101,116,117,114,110,
        32,116,104,105,115,46,97,116,116,114,40,34,99,108,97,115,115,34,44,34,34,41,59,105,102,40,40,101,61,118,116,40,116,41,41,46,108,101,110,103,116,104,41,119,104,105,108,101,40,110,61,116,104,105,115,
        91,117,43,43,93,41,105,102,40,105,61,103,116,40,110,41,44,114,61,49,61,61,61,110,46,110,111,100,101,84,121,112,101,38,38,34,32,34,43,104,116,40,105,41,43,34,32,34,41,123,97,61,48,59,119,104,105,
        108,101,40,111,61,101,91,97,43,43,93,41,119,104,105,108,101,40,45,49,60,114,46,105,110,100,101,120,79,102,40,34,32,34,43,111,43,34,32,34,41,41,114,61,114,46,114,101,112,108,97,99,101,40,34,32,34,
        43,111,43,34,32,34,44,34,32,34,41,59,105,33,61,61,40,115,61,104,116,40,114,41,41,38,38,110,46,115,101,116,65,116,116,114,105,98,117,116,101,40,34,99,108,97,115,115,34,44,115,41,125,114,101,116,117,
        114,110,32,116,104,105,115,125,44,116,111,103,103,108,101,67,108,97,115,115,58,102,117,110,99,116,105,111,110,40,105,44,116,41,123,118,97,114,32,111,61,116,121,112,101,111,102,32,105,44,97,61,34,
        115,116,114,105,110,103,34,61,61,61,111,124,124,65,114,114,97,121,46,105,115,65,114,114,97,121,40,105,41,59,114,101,116,117,114,110,34,98,111,111,108,101,97,110,34,61,61,116,121,112,101,111,102,
        32,116,38,38,97,63,116,63,116,104,105,115,46,97,100,100,67,108,97,115,115,40,105,41,58,116,104,105,115,46,114,101,109,111,118,101,67,108,97,115,115,40,105,41,58,109,40,105,41,63,116,104,105,115,
        46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,101,41,123,83,40,116,104,105,115,41,46,116,111,103,103,108,101,67,108,97,115,115,40,105,46,99,97,108,108,40,116,104,105,115,44,101,44,103,116,
        40,116,104,105,115,41,44,116,41,44,116,41,125,41,58,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,44,116,44,110,44,114,59,105,102,40,97,41,123,116,
        61,48,44,110,61,83,40,116,104,105,115,41,44,114,61,118,116,40,105,41,59,119,104,105,108,101,40,101,61,114,91,116,43,43,93,41,110,46,104,97,115,67,108,97,115,115,40,101,41,63,110,46,114,101,109,111,
        118,101,67,108,97,115,115,40,101,41,58,110,46,97,100,100,67,108,97,115,115,40,101,41,125,101,108,115,101,32,118,111,105,100,32,48,33,61,61,105,38,38,34,98,111,111,108,101,97,110,34,33,61,61,111,
        124,124,40,40,101,61,103,116,40,116,104,105,115,41,41,38,38,89,46,115,101,116,40,116,104,105,115,44,34,95,95,99,108,97,115,115,78,97,109,101,95,95,34,44,101,41,44,116,104,105,115,46,115,101,116,
        65,116,116,114,105,98,117,116,101,38,38,116,104,105,115,46,115,101,116,65,116,116,114,105,98,117,116,101,40,34,99,108,97,115,115,34,44,101,124,124,33,49,61,61,61,105,63,34,34,58,89,46,103,101,116,
        40,116,104,105,115,44,34,95,95,99,108,97,115,115,78,97,109,101,95,95,34,41,124,124,34,34,41,41,125,41,125,44,104,97,115,67,108,97,115,115,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,
        32,116,44,110,44,114,61,48,59,116,61,34,32,34,43,101,43,34,32,34,59,119,104,105,108,101,40,110,61,116,104,105,115,91,114,43,43,93,41,105,102,40,49,61,61,61,110,46,110,111,100,101,84,121,112,101,
        38,38,45,49,60,40,34,32,34,43,104,116,40,103,116,40,110,41,41,43,34,32,34,41,46,105,110,100,101,120,79,102,40,116,41,41,114,101,116,117,114,110,33,48,59,114,101,116,117,114,110,33,49,125,125,41,
        59,118,97,114,32,121,116,61,47,92,114,47,103,59,83,46,102,110,46,101,120,116,101,110,100,40,123,118,97,108,58,102,117,110,99,116,105,111,110,40,110,41,123,118,97,114,32,114,44,101,44,105,44,116,
        61,116,104,105,115,91,48,93,59,114,101,116,117,114,110,32,97,114,103,117,109,101,110,116,115,46,108,101,110,103,116,104,63,40,105,61,109,40,110,41,44,116,104,105,115,46,101,97,99,104,40,102,117,
        110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,59,49,61,61,61,116,104,105,115,46,110,111,100,101,84,121,112,101,38,38,40,110,117,108,108,61,61,40,116,61,105,63,110,46,99,97,108,108,40,116,
        104,105,115,44,101,44,83,40,116,104,105,115,41,46,118,97,108,40,41,41,58,110,41,63,116,61,34,34,58,34,110,117,109,98,101,114,34,61,61,116,121,112,101,111,102,32,116,63,116,43,61,34,34,58,65,114,
        114,97,121,46,105,115,65,114,114,97,121,40,116,41,38,38,40,116,61,83,46,109,97,112,40,116,44,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,110,117,108,108,61,61,101,63,
        34,34,58,101,43,34,34,125,41,41,44,40,114,61,83,46,118,97,108,72,111,111,107,115,91,116,104,105,115,46,116,121,112,101,93,124,124,83,46,118,97,108,72,111,111,107,115,91,116,104,105,115,46,110,111,
        100,101,78,97,109,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,93,41,38,38,34,115,101,116,34,105,110,32,114,38,38,118,111,105,100,32,48,33,61,61,114,46,115,101,116,40,116,104,105,115,44,
        116,44,34,118,97,108,117,101,34,41,124,124,40,116,104,105,115,46,118,97,108,117,101,61,116,41,41,125,41,41,58,116,63,40,114,61,83,46,118,97,108,72,111,111,107,115,91,116,46,116,121,112,101,93,124,
        124,83,46,118,97,108,72,111,111,107,115,91,116,46,110,111,100,101,78,97,109,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,93,41,38,38,34,103,101,116,34,105,110,32,114,38,38,118,111,105,100,
        32,48,33,61,61,40,101,61,114,46,103,101,116,40,116,44,34,118,97,108,117,101,34,41,41,63,101,58,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,40,101,61,116,46,118,97,108,117,101,41,
        63,101,46,114,101,112,108,97,99,101,40,121,116,44,34,34,41,58,110,117,108,108,61,61,101,63,34,34,58,101,58,118,111,105,100,32,48,125,125,41,44,83,46,101,120,116,101,110,100,40,123,118,97,108,72,
        111,111,107,115,58,123,111,112,116,105,111,110,58,123,103,101,116,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,83,46,102,105,110,100,46,97,116,116,114,40,101,44,34,118,97,
        108,117,101,34,41,59,114,101,116,117,114,110,32,110,117,108,108,33,61,116,63,116,58,104,116,40,83,46,116,101,120,116,40,101,41,41,125,125,44,115,101,108,101,99,116,58,123,103,101,116,58,102,117,
        110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,44,110,44,114,44,105,61,101,46,111,112,116,105,111,110,115,44,111,61,101,46,115,101,108,101,99,116,101,100,73,110,100,101,120,44,97,61,34,115,
        101,108,101,99,116,45,111,110,101,34,61,61,61,101,46,116,121,112,101,44,115,61,97,63,110,117,108,108,58,91,93,44,117,61,97,63,111,43,49,58,105,46,108,101,110,103,116,104,59,102,111,114,40,114,61,
        111,60,48,63,117,58,97,63,111,58,48,59,114,60,117,59,114,43,43,41,105,102,40,40,40,110,61,105,91,114,93,41,46,115,101,108,101,99,116,101,100,124,124,114,61,61,61,111,41,38,38,33,110,46,100,105,115,
        97,98,108,101,100,38,38,40,33,110,46,112,97,114,101,110,116,78,111,100,101,46,100,105,115,97,98,108,101,100,124,124,33,65,40,110,46,112,97,114,101,110,116,78,111,100,101,44,34,111,112,116,103,114,
        111,117,112,34,41,41,41,123,105,102,40,116,61,83,40,110,41,46,118,97,108,40,41,44,97,41,114,101,116,117,114,110,32,116,59,115,46,112,117,115,104,40,116,41,125,114,101,116,117,114,110,32,115,125,
        44,115,101,116,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,44,114,44,105,61,101,46,111,112,116,105,111,110,115,44,111,61,83,46,109,97,107,101,65,114,114,97,121,40,116,
        41,44,97,61,105,46,108,101,110,103,116,104,59,119,104,105,108,101,40,97,45,45,41,40,40,114,61,105,91,97,93,41,46,115,101,108,101,99,116,101,100,61,45,49,60,83,46,105,110,65,114,114,97,121,40,83,
        46,118,97,108,72,111,111,107,115,46,111,112,116,105,111,110,46,103,101,116,40,114,41,44,111,41,41,38,38,40,110,61,33,48,41,59,114,101,116,117,114,110,32,110,124,124,40,101,46,115,101,108,101,99,
        116,101,100,73,110,100,101,120,61,45,49,41,44,111,125,125,125,125,41,44,83,46,101,97,99,104,40,91,34,114,97,100,105,111,34,44,34,99,104,101,99,107,98,111,120,34,93,44,102,117,110,99,116,105,111,
        110,40,41,123,83,46,118,97,108,72,111,111,107,115,91,116,104,105,115,93,61,123,115,101,116,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,105,102,40,65,114,114,97,121,46,105,115,65,114,114,
        97,121,40,116,41,41,114,101,116,117,114,110,32,101,46,99,104,101,99,107,101,100,61,45,49,60,83,46,105,110,65,114,114,97,121,40,83,40,101,41,46,118,97,108,40,41,44,116,41,125,125,44,121,46,99,104,
        101,99,107,79,110,124,124,40,83,46,118,97,108,72,111,111,107,115,91,116,104,105,115,93,46,103,101,116,61,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,110,117,108,108,61,
        61,61,101,46,103,101,116,65,116,116,114,105,98,117,116,101,40,34,118,97,108,117,101,34,41,63,34,111,110,34,58,101,46,118,97,108,117,101,125,41,125,41,44,121,46,102,111,99,117,115,105,110,61,34,111,
        110,102,111,99,117,115,105,110,34,105,110,32,67,59,118,97,114,32,109,116,61,47,94,40,63,58,102,111,99,117,115,105,110,102,111,99,117,115,124,102,111,99,117,115,111,117,116,98,108,117,114,41,36,47,
        44,120,116,61,102,117,110,99,116,105,111,110,40,101,41,123,101,46,115,116,111,112,80,114,111,112,97,103,97,116,105,111,110,40,41,125,59,83,46,101,120,116,101,110,100,40,83,46,101,118,101,110,116,
        44,123,116,114,105,103,103,101,114,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,44,114,41,123,118,97,114,32,105,44,111,44,97,44,115,44,117,44,108,44,99,44,102,44,112,61,91,110,124,124,
        69,93,44,100,61,118,46,99,97,108,108,40,101,44,34,116,121,112,101,34,41,63,101,46,116,121,112,101,58,101,44,104,61,118,46,99,97,108,108,40,101,44,34,110,97,109,101,115,112,97,99,101,34,41,63,101,
        46,110,97,109,101,115,112,97,99,101,46,115,112,108,105,116,40,34,46,34,41,58,91,93,59,105,102,40,111,61,102,61,97,61,110,61,110,124,124,69,44,51,33,61,61,110,46,110,111,100,101,84,121,112,101,38,
        38,56,33,61,61,110,46,110,111,100,101,84,121,112,101,38,38,33,109,116,46,116,101,115,116,40,100,43,83,46,101,118,101,110,116,46,116,114,105,103,103,101,114,101,100,41,38,38,40,45,49,60,100,46,105,
        110,100,101,120,79,102,40,34,46,34,41,38,38,40,100,61,40,104,61,100,46,115,112,108,105,116,40,34,46,34,41,41,46,115,104,105,102,116,40,41,44,104,46,115,111,114,116,40,41,41,44,117,61,100,46,105,
        110,100,101,120,79,102,40,34,58,34,41,60,48,38,38,34,111,110,34,43,100,44,40,101,61,101,91,83,46,101,120,112,97,110,100,111,93,63,101,58,110,101,119,32,83,46,69,118,101,110,116,40,100,44,34,111,
        98,106,101,99,116,34,61,61,116,121,112,101,111,102,32,101,38,38,101,41,41,46,105,115,84,114,105,103,103,101,114,61,114,63,50,58,51,44,101,46,110,97,109,101,115,112,97,99,101,61,104,46,106,111,105,
        110,40,34,46,34,41,44,101,46,114,110,97,109,101,115,112,97,99,101,61,101,46,110,97,109,101,115,112,97,99,101,63,110,101,119,32,82,101,103,69,120,112,40,34,40,94,124,92,92,46,41,34,43,104,46,106,
        111,105,110,40,34,92,92,46,40,63,58,46,42,92,92,46,124,41,34,41,43,34,40,92,92,46,124,36,41,34,41,58,110,117,108,108,44,101,46,114,101,115,117,108,116,61,118,111,105,100,32,48,44,101,46,116,97,114,
        103,101,116,124,124,40,101,46,116,97,114,103,101,116,61,110,41,44,116,61,110,117,108,108,61,61,116,63,91,101,93,58,83,46,109,97,107,101,65,114,114,97,121,40,116,44,91,101,93,41,44,99,61,83,46,101,
        118,101,110,116,46,115,112,101,99,105,97,108,91,100,93,124,124,123,125,44,114,124,124,33,99,46,116,114,105,103,103,101,114,124,124,33,49,33,61,61,99,46,116,114,105,103,103,101,114,46,97,112,112,
        108,121,40,110,44,116,41,41,41,123,105,102,40,33,114,38,38,33,99,46,110,111,66,117,98,98,108,101,38,38,33,120,40,110,41,41,123,102,111,114,40,115,61,99,46,100,101,108,101,103,97,116,101,84,121,112,
        101,124,124,100,44,109,116,46,116,101,115,116,40,115,43,100,41,124,124,40,111,61,111,46,112,97,114,101,110,116,78,111,100,101,41,59,111,59,111,61,111,46,112,97,114,101,110,116,78,111,100,101,41,
        112,46,112,117,115,104,40,111,41,44,97,61,111,59,97,61,61,61,40,110,46,111,119,110,101,114,68,111,99,117,109,101,110,116,124,124,69,41,38,38,112,46,112,117,115,104,40,97,46,100,101,102,97,117,108,
        116,86,105,101,119,124,124,97,46,112,97,114,101,110,116,87,105,110,100,111,119,124,124,67,41,125,105,61,48,59,119,104,105,108,101,40,40,111,61,112,91,105,43,43,93,41,38,38,33,101,46,105,115,80,114,
        111,112,97,103,97,116,105,111,110,83,116,111,112,112,101,100,40,41,41,102,61,111,44,101,46,116,121,112,101,61,49,60,105,63,115,58,99,46,98,105,110,100,84,121,112,101,124,124,100,44,40,108,61,40,
        89,46,103,101,116,40,111,44,34,101,118,101,110,116,115,34,41,124,124,79,98,106,101,99,116,46,99,114,101,97,116,101,40,110,117,108,108,41,41,91,101,46,116,121,112,101,93,38,38,89,46,103,101,116,40,
        111,44,34,104,97,110,100,108,101,34,41,41,38,38,108,46,97,112,112,108,121,40,111,44,116,41,44,40,108,61,117,38,38,111,91,117,93,41,38,38,108,46,97,112,112,108,121,38,38,86,40,111,41,38,38,40,101,
        46,114,101,115,117,108,116,61,108,46,97,112,112,108,121,40,111,44,116,41,44,33,49,61,61,61,101,46,114,101,115,117,108,116,38,38,101,46,112,114,101,118,101,110,116,68,101,102,97,117,108,116,40,41,
        41,59,114,101,116,117,114,110,32,101,46,116,121,112,101,61,100,44,114,124,124,101,46,105,115,68,101,102,97,117,108,116,80,114,101,118,101,110,116,101,100,40,41,124,124,99,46,95,100,101,102,97,117,
        108,116,38,38,33,49,33,61,61,99,46,95,100,101,102,97,117,108,116,46,97,112,112,108,121,40,112,46,112,111,112,40,41,44,116,41,124,124,33,86,40,110,41,124,124,117,38,38,109,40,110,91,100,93,41,38,
        38,33,120,40,110,41,38,38,40,40,97,61,110,91,117,93,41,38,38,40,110,91,117,93,61,110,117,108,108,41,44,83,46,101,118,101,110,116,46,116,114,105,103,103,101,114,101,100,61,100,44,101,46,105,115,80,
        114,111,112,97,103,97,116,105,111,110,83,116,111,112,112,101,100,40,41,38,38,102,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,100,44,120,116,41,44,110,91,100,93,40,41,44,101,
        46,105,115,80,114,111,112,97,103,97,116,105,111,110,83,116,111,112,112,101,100,40,41,38,38,102,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,100,44,120,116,41,44,
        83,46,101,118,101,110,116,46,116,114,105,103,103,101,114,101,100,61,118,111,105,100,32,48,44,97,38,38,40,110,91,117,93,61,97,41,41,44,101,46,114,101,115,117,108,116,125,125,44,115,105,109,117,108,
        97,116,101,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,61,83,46,101,120,116,101,110,100,40,110,101,119,32,83,46,69,118,101,110,116,44,110,44,123,116,121,112,101,
        58,101,44,105,115,83,105,109,117,108,97,116,101,100,58,33,48,125,41,59,83,46,101,118,101,110,116,46,116,114,105,103,103,101,114,40,114,44,110,117,108,108,44,116,41,125,125,41,44,83,46,102,110,46,
        101,120,116,101,110,100,40,123,116,114,105,103,103,101,114,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,
        105,111,110,40,41,123,83,46,101,118,101,110,116,46,116,114,105,103,103,101,114,40,101,44,116,44,116,104,105,115,41,125,41,125,44,116,114,105,103,103,101,114,72,97,110,100,108,101,114,58,102,117,
        110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,61,116,104,105,115,91,48,93,59,105,102,40,110,41,114,101,116,117,114,110,32,83,46,101,118,101,110,116,46,116,114,105,103,103,101,114,
        40,101,44,116,44,110,44,33,48,41,125,125,41,44,121,46,102,111,99,117,115,105,110,124,124,83,46,101,97,99,104,40,123,102,111,99,117,115,58,34,102,111,99,117,115,105,110,34,44,98,108,117,114,58,34,
        102,111,99,117,115,111,117,116,34,125,44,102,117,110,99,116,105,111,110,40,110,44,114,41,123,118,97,114,32,105,61,102,117,110,99,116,105,111,110,40,101,41,123,83,46,101,118,101,110,116,46,115,105,
        109,117,108,97,116,101,40,114,44,101,46,116,97,114,103,101,116,44,83,46,101,118,101,110,116,46,102,105,120,40,101,41,41,125,59,83,46,101,118,101,110,116,46,115,112,101,99,105,97,108,91,114,93,61,
        123,115,101,116,117,112,58,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,61,116,104,105,115,46,111,119,110,101,114,68,111,99,117,109,101,110,116,124,124,116,104,105,115,46,100,111,99,
        117,109,101,110,116,124,124,116,104,105,115,44,116,61,89,46,97,99,99,101,115,115,40,101,44,114,41,59,116,124,124,101,46,97,100,100,69,118,101,110,116,76,105,115,116,101,110,101,114,40,110,44,105,
        44,33,48,41,44,89,46,97,99,99,101,115,115,40,101,44,114,44,40,116,124,124,48,41,43,49,41,125,44,116,101,97,114,100,111,119,110,58,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,61,116,
        104,105,115,46,111,119,110,101,114,68,111,99,117,109,101,110,116,124,124,116,104,105,115,46,100,111,99,117,109,101,110,116,124,124,116,104,105,115,44,116,61,89,46,97,99,99,101,115,115,40,101,44,
        114,41,45,49,59,116,63,89,46,97,99,99,101,115,115,40,101,44,114,44,116,41,58,40,101,46,114,101,109,111,118,101,69,118,101,110,116,76,105,115,116,101,110,101,114,40,110,44,105,44,33,48,41,44,89,46,
        114,101,109,111,118,101,40,101,44,114,41,41,125,125,125,41,59,118,97,114,32,98,116,61,67,46,108,111,99,97,116,105,111,110,44,119,116,61,123,103,117,105,100,58,68,97,116,101,46,110,111,119,40,41,
        125,44,84,116,61,47,92,63,47,59,83,46,112,97,114,115,101,88,77,76,61,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,44,110,59,105,102,40,33,101,124,124,34,115,116,114,105,110,103,
        34,33,61,116,121,112,101,111,102,32,101,41,114,101,116,117,114,110,32,110,117,108,108,59,116,114,121,123,116,61,40,110,101,119,32,67,46,68,79,77,80,97,114,115,101,114,41,46,112,97,114,115,101,70,
        114,111,109,83,116,114,105,110,103,40,101,44,34,116,101,120,116,47,120,109,108,34,41,125,99,97,116,99,104,40,101,41,123,125,114,101,116,117,114,110,32,110,61,116,38,38,116,46,103,101,116,69,108,
        101,109,101,110,116,115,66,121,84,97,103,78,97,109,101,40,34,112,97,114,115,101,114,101,114,114,111,114,34,41,91,48,93,44,116,38,38,33,110,124,124,83,46,101,114,114,111,114,40,34,73,110,118,97,108,
        105,100,32,88,77,76,58,32,34,43,40,110,63,83,46,109,97,112,40,110,46,99,104,105,108,100,78,111,100,101,115,44,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,101,46,116,101,
        120,116,67,111,110,116,101,110,116,125,41,46,106,111,105,110,40,34,92,110,34,41,58,101,41,41,44,116,125,59,118,97,114,32,67,116,61,47,92,91,92,93,36,47,44,69,116,61,47,92,114,63,92,110,47,103,44,
        83,116,61,47,94,40,63,58,115,117,98,109,105,116,124,98,117,116,116,111,110,124,105,109,97,103,101,124,114,101,115,101,116,124,102,105,108,101,41,36,47,105,44,107,116,61,47,94,40,63,58,105,110,112,
        117,116,124,115,101,108,101,99,116,124,116,101,120,116,97,114,101,97,124,107,101,121,103,101,110,41,47,105,59,102,117,110,99,116,105,111,110,32,65,116,40,110,44,101,44,114,44,105,41,123,118,97,114,
        32,116,59,105,102,40,65,114,114,97,121,46,105,115,65,114,114,97,121,40,101,41,41,83,46,101,97,99,104,40,101,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,124,124,67,116,46,116,101,115,
        116,40,110,41,63,105,40,110,44,116,41,58,65,116,40,110,43,34,91,34,43,40,34,111,98,106,101,99,116,34,61,61,116,121,112,101,111,102,32,116,38,38,110,117,108,108,33,61,116,63,101,58,34,34,41,43,34,
        93,34,44,116,44,114,44,105,41,125,41,59,101,108,115,101,32,105,102,40,114,124,124,34,111,98,106,101,99,116,34,33,61,61,119,40,101,41,41,105,40,110,44,101,41,59,101,108,115,101,32,102,111,114,40,
        116,32,105,110,32,101,41,65,116,40,110,43,34,91,34,43,116,43,34,93,34,44,101,91,116,93,44,114,44,105,41,125,83,46,112,97,114,97,109,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,
        114,32,110,44,114,61,91,93,44,105,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,61,109,40,116,41,63,116,40,41,58,116,59,114,91,114,46,108,101,110,103,116,104,93,61,101,
        110,99,111,100,101,85,82,73,67,111,109,112,111,110,101,110,116,40,101,41,43,34,61,34,43,101,110,99,111,100,101,85,82,73,67,111,109,112,111,110,101,110,116,40,110,117,108,108,61,61,110,63,34,34,58,
        110,41,125,59,105,102,40,110,117,108,108,61,61,101,41,114,101,116,117,114,110,34,34,59,105,102,40,65,114,114,97,121,46,105,115,65,114,114,97,121,40,101,41,124,124,101,46,106,113,117,101,114,121,
        38,38,33,83,46,105,115,80,108,97,105,110,79,98,106,101,99,116,40,101,41,41,83,46,101,97,99,104,40,101,44,102,117,110,99,116,105,111,110,40,41,123,105,40,116,104,105,115,46,110,97,109,101,44,116,
        104,105,115,46,118,97,108,117,101,41,125,41,59,101,108,115,101,32,102,111,114,40,110,32,105,110,32,101,41,65,116,40,110,44,101,91,110,93,44,116,44,105,41,59,114,101,116,117,114,110,32,114,46,106,
        111,105,110,40,34,38,34,41,125,44,83,46,102,110,46,101,120,116,101,110,100,40,123,115,101,114,105,97,108,105,122,101,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,83,46,
        112,97,114,97,109,40,116,104,105,115,46,115,101,114,105,97,108,105,122,101,65,114,114,97,121,40,41,41,125,44,115,101,114,105,97,108,105,122,101,65,114,114,97,121,58,102,117,110,99,116,105,111,110,
        40,41,123,114,101,116,117,114,110,32,116,104,105,115,46,109,97,112,40,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,61,83,46,112,114,111,112,40,116,104,105,115,44,34,101,108,101,109,
        101,110,116,115,34,41,59,114,101,116,117,114,110,32,101,63,83,46,109,97,107,101,65,114,114,97,121,40,101,41,58,116,104,105,115,125,41,46,102,105,108,116,101,114,40,102,117,110,99,116,105,111,110,
        40,41,123,118,97,114,32,101,61,116,104,105,115,46,116,121,112,101,59,114,101,116,117,114,110,32,116,104,105,115,46,110,97,109,101,38,38,33,83,40,116,104,105,115,41,46,105,115,40,34,58,100,105,115,
        97,98,108,101,100,34,41,38,38,107,116,46,116,101,115,116,40,116,104,105,115,46,110,111,100,101,78,97,109,101,41,38,38,33,83,116,46,116,101,115,116,40,101,41,38,38,40,116,104,105,115,46,99,104,101,
        99,107,101,100,124,124,33,112,101,46,116,101,115,116,40,101,41,41,125,41,46,109,97,112,40,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,61,83,40,116,104,105,115,41,46,118,
        97,108,40,41,59,114,101,116,117,114,110,32,110,117,108,108,61,61,110,63,110,117,108,108,58,65,114,114,97,121,46,105,115,65,114,114,97,121,40,110,41,63,83,46,109,97,112,40,110,44,102,117,110,99,116,
        105,111,110,40,101,41,123,114,101,116,117,114,110,123,110,97,109,101,58,116,46,110,97,109,101,44,118,97,108,117,101,58,101,46,114,101,112,108,97,99,101,40,69,116,44,34,92,114,92,110,34,41,125,125,
        41,58,123,110,97,109,101,58,116,46,110,97,109,101,44,118,97,108,117,101,58,110,46,114,101,112,108,97,99,101,40,69,116,44,34,92,114,92,110,34,41,125,125,41,46,103,101,116,40,41,125,125,41,59,118,
        97,114,32,78,116,61,47,37,50,48,47,103,44,106,116,61,47,35,46,42,36,47,44,68,116,61,47,40,91,63,38,93,41,95,61,91,94,38,93,42,47,44,113,116,61,47,94,40,46,42,63,41,58,91,32,92,116,93,42,40,91,94,
        92,114,92,110,93,42,41,36,47,103,109,44,76,116,61,47,94,40,63,58,71,69,84,124,72,69,65,68,41,36,47,44,72,116,61,47,94,92,47,92,47,47,44,79,116,61,123,125,44,80,116,61,123,125,44,82,116,61,34,42,
        47,34,46,99,111,110,99,97,116,40,34,42,34,41,44,77,116,61,69,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,97,34,41,59,102,117,110,99,116,105,111,110,32,73,116,40,111,41,123,114,101,
        116,117,114,110,32,102,117,110,99,116,105,111,110,40,101,44,116,41,123,34,115,116,114,105,110,103,34,33,61,116,121,112,101,111,102,32,101,38,38,40,116,61,101,44,101,61,34,42,34,41,59,118,97,114,
        32,110,44,114,61,48,44,105,61,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,46,109,97,116,99,104,40,80,41,124,124,91,93,59,105,102,40,109,40,116,41,41,119,104,105,108,101,40,110,61,105,91,
        114,43,43,93,41,34,43,34,61,61,61,110,91,48,93,63,40,110,61,110,46,115,108,105,99,101,40,49,41,124,124,34,42,34,44,40,111,91,110,93,61,111,91,110,93,124,124,91,93,41,46,117,110,115,104,105,102,116,
        40,116,41,41,58,40,111,91,110,93,61,111,91,110,93,124,124,91,93,41,46,112,117,115,104,40,116,41,125,125,102,117,110,99,116,105,111,110,32,87,116,40,116,44,105,44,111,44,97,41,123,118,97,114,32,115,
        61,123,125,44,117,61,116,61,61,61,80,116,59,102,117,110,99,116,105,111,110,32,108,40,101,41,123,118,97,114,32,114,59,114,101,116,117,114,110,32,115,91,101,93,61,33,48,44,83,46,101,97,99,104,40,116,
        91,101,93,124,124,91,93,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,61,116,40,105,44,111,44,97,41,59,114,101,116,117,114,110,34,115,116,114,105,110,103,34,33,61,116,
        121,112,101,111,102,32,110,124,124,117,124,124,115,91,110,93,63,117,63,33,40,114,61,110,41,58,118,111,105,100,32,48,58,40,105,46,100,97,116,97,84,121,112,101,115,46,117,110,115,104,105,102,116,40,
        110,41,44,108,40,110,41,44,33,49,41,125,41,44,114,125,114,101,116,117,114,110,32,108,40,105,46,100,97,116,97,84,121,112,101,115,91,48,93,41,124,124,33,115,91,34,42,34,93,38,38,108,40,34,42,34,41,
        125,102,117,110,99,116,105,111,110,32,70,116,40,101,44,116,41,123,118,97,114,32,110,44,114,44,105,61,83,46,97,106,97,120,83,101,116,116,105,110,103,115,46,102,108,97,116,79,112,116,105,111,110,115,
        124,124,123,125,59,102,111,114,40,110,32,105,110,32,116,41,118,111,105,100,32,48,33,61,61,116,91,110,93,38,38,40,40,105,91,110,93,63,101,58,114,124,124,40,114,61,123,125,41,41,91,110,93,61,116,91,
        110,93,41,59,114,101,116,117,114,110,32,114,38,38,83,46,101,120,116,101,110,100,40,33,48,44,101,44,114,41,44,101,125,77,116,46,104,114,101,102,61,98,116,46,104,114,101,102,44,83,46,101,120,116,101,
        110,100,40,123,97,99,116,105,118,101,58,48,44,108,97,115,116,77,111,100,105,102,105,101,100,58,123,125,44,101,116,97,103,58,123,125,44,97,106,97,120,83,101,116,116,105,110,103,115,58,123,117,114,
        108,58,98,116,46,104,114,101,102,44,116,121,112,101,58,34,71,69,84,34,44,105,115,76,111,99,97,108,58,47,94,40,63,58,97,98,111,117,116,124,97,112,112,124,97,112,112,45,115,116,111,114,97,103,101,
        124,46,43,45,101,120,116,101,110,115,105,111,110,124,102,105,108,101,124,114,101,115,124,119,105,100,103,101,116,41,58,36,47,46,116,101,115,116,40,98,116,46,112,114,111,116,111,99,111,108,41,44,
        103,108,111,98,97,108,58,33,48,44,112,114,111,99,101,115,115,68,97,116,97,58,33,48,44,97,115,121,110,99,58,33,48,44,99,111,110,116,101,110,116,84,121,112,101,58,34,97,112,112,108,105,99,97,116,105,
        111,110,47,120,45,119,119,119,45,102,111,114,109,45,117,114,108,101,110,99,111,100,101,100,59,32,99,104,97,114,115,101,116,61,85,84,70,45,56,34,44,97,99,99,101,112,116,115,58,123,34,42,34,58,82,
        116,44,116,101,120,116,58,34,116,101,120,116,47,112,108,97,105,110,34,44,104,116,109,108,58,34,116,101,120,116,47,104,116,109,108,34,44,120,109,108,58,34,97,112,112,108,105,99,97,116,105,111,110,
        47,120,109,108,44,32,116,101,120,116,47,120,109,108,34,44,106,115,111,110,58,34,97,112,112,108,105,99,97,116,105,111,110,47,106,115,111,110,44,32,116,101,120,116,47,106,97,118,97,115,99,114,105,
        112,116,34,125,44,99,111,110,116,101,110,116,115,58,123,120,109,108,58,47,92,98,120,109,108,92,98,47,44,104,116,109,108,58,47,92,98,104,116,109,108,47,44,106,115,111,110,58,47,92,98,106,115,111,
        110,92,98,47,125,44,114,101,115,112,111,110,115,101,70,105,101,108,100,115,58,123,120,109,108,58,34,114,101,115,112,111,110,115,101,88,77,76,34,44,116,101,120,116,58,34,114,101,115,112,111,110,115,
        101,84,101,120,116,34,44,106,115,111,110,58,34,114,101,115,112,111,110,115,101,74,83,79,78,34,125,44,99,111,110,118,101,114,116,101,114,115,58,123,34,42,32,116,101,120,116,34,58,83,116,114,105,110,
        103,44,34,116,101,120,116,32,104,116,109,108,34,58,33,48,44,34,116,101,120,116,32,106,115,111,110,34,58,74,83,79,78,46,112,97,114,115,101,44,34,116,101,120,116,32,120,109,108,34,58,83,46,112,97,
        114,115,101,88,77,76,125,44,102,108,97,116,79,112,116,105,111,110,115,58,123,117,114,108,58,33,48,44,99,111,110,116,101,120,116,58,33,48,125,125,44,97,106,97,120,83,101,116,117,112,58,102,117,110,
        99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,116,63,70,116,40,70,116,40,101,44,83,46,97,106,97,120,83,101,116,116,105,110,103,115,41,44,116,41,58,70,116,40,83,46,97,106,97,
        120,83,101,116,116,105,110,103,115,44,101,41,125,44,97,106,97,120,80,114,101,102,105,108,116,101,114,58,73,116,40,79,116,41,44,97,106,97,120,84,114,97,110,115,112,111,114,116,58,73,116,40,80,116,
        41,44,97,106,97,120,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,34,111,98,106,101,99,116,34,61,61,116,121,112,101,111,102,32,101,38,38,40,116,61,101,44,101,61,118,111,105,100,32,48,41,
        44,116,61,116,124,124,123,125,59,118,97,114,32,99,44,102,44,112,44,110,44,100,44,114,44,104,44,103,44,105,44,111,44,118,61,83,46,97,106,97,120,83,101,116,117,112,40,123,125,44,116,41,44,121,61,118,
        46,99,111,110,116,101,120,116,124,124,118,44,109,61,118,46,99,111,110,116,101,120,116,38,38,40,121,46,110,111,100,101,84,121,112,101,124,124,121,46,106,113,117,101,114,121,41,63,83,40,121,41,58,
        83,46,101,118,101,110,116,44,120,61,83,46,68,101,102,101,114,114,101,100,40,41,44,98,61,83,46,67,97,108,108,98,97,99,107,115,40,34,111,110,99,101,32,109,101,109,111,114,121,34,41,44,119,61,118,46,
        115,116,97,116,117,115,67,111,100,101,124,124,123,125,44,97,61,123,125,44,115,61,123,125,44,117,61,34,99,97,110,99,101,108,101,100,34,44,84,61,123,114,101,97,100,121,83,116,97,116,101,58,48,44,103,
        101,116,82,101,115,112,111,110,115,101,72,101,97,100,101,114,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,59,105,102,40,104,41,123,105,102,40,33,110,41,123,110,61,123,125,59,
        119,104,105,108,101,40,116,61,113,116,46,101,120,101,99,40,112,41,41,110,91,116,91,49,93,46,116,111,76,111,119,101,114,67,97,115,101,40,41,43,34,32,34,93,61,40,110,91,116,91,49,93,46,116,111,76,
        111,119,101,114,67,97,115,101,40,41,43,34,32,34,93,124,124,91,93,41,46,99,111,110,99,97,116,40,116,91,50,93,41,125,116,61,110,91,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,43,34,32,34,
        93,125,114,101,116,117,114,110,32,110,117,108,108,61,61,116,63,110,117,108,108,58,116,46,106,111,105,110,40,34,44,32,34,41,125,44,103,101,116,65,108,108,82,101,115,112,111,110,115,101,72,101,97,
        100,101,114,115,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,104,63,112,58,110,117,108,108,125,44,115,101,116,82,101,113,117,101,115,116,72,101,97,100,101,114,58,102,117,
        110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,110,117,108,108,61,61,104,38,38,40,101,61,115,91,101,46,116,111,76,111,119,101,114,67,97,115,101,40,41,93,61,115,91,101,46,
        116,111,76,111,119,101,114,67,97,115,101,40,41,93,124,124,101,44,97,91,101,93,61,116,41,44,116,104,105,115,125,44,111,118,101,114,114,105,100,101,77,105,109,101,84,121,112,101,58,102,117,110,99,
        116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,110,117,108,108,61,61,104,38,38,40,118,46,109,105,109,101,84,121,112,101,61,101,41,44,116,104,105,115,125,44,115,116,97,116,117,115,67,111,
        100,101,58,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,59,105,102,40,101,41,105,102,40,104,41,84,46,97,108,119,97,121,115,40,101,91,84,46,115,116,97,116,117,115,93,41,59,101,108,
        115,101,32,102,111,114,40,116,32,105,110,32,101,41,119,91,116,93,61,91,119,91,116,93,44,101,91,116,93,93,59,114,101,116,117,114,110,32,116,104,105,115,125,44,97,98,111,114,116,58,102,117,110,99,
        116,105,111,110,40,101,41,123,118,97,114,32,116,61,101,124,124,117,59,114,101,116,117,114,110,32,99,38,38,99,46,97,98,111,114,116,40,116,41,44,108,40,48,44,116,41,44,116,104,105,115,125,125,59,105,
        102,40,120,46,112,114,111,109,105,115,101,40,84,41,44,118,46,117,114,108,61,40,40,101,124,124,118,46,117,114,108,124,124,98,116,46,104,114,101,102,41,43,34,34,41,46,114,101,112,108,97,99,101,40,
        72,116,44,98,116,46,112,114,111,116,111,99,111,108,43,34,47,47,34,41,44,118,46,116,121,112,101,61,116,46,109,101,116,104,111,100,124,124,116,46,116,121,112,101,124,124,118,46,109,101,116,104,111,
        100,124,124,118,46,116,121,112,101,44,118,46,100,97,116,97,84,121,112,101,115,61,40,118,46,100,97,116,97,84,121,112,101,124,124,34,42,34,41,46,116,111,76,111,119,101,114,67,97,115,101,40,41,46,109,
        97,116,99,104,40,80,41,124,124,91,34,34,93,44,110,117,108,108,61,61,118,46,99,114,111,115,115,68,111,109,97,105,110,41,123,114,61,69,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,97,
        34,41,59,116,114,121,123,114,46,104,114,101,102,61,118,46,117,114,108,44,114,46,104,114,101,102,61,114,46,104,114,101,102,44,118,46,99,114,111,115,115,68,111,109,97,105,110,61,77,116,46,112,114,
        111,116,111,99,111,108,43,34,47,47,34,43,77,116,46,104,111,115,116,33,61,114,46,112,114,111,116,111,99,111,108,43,34,47,47,34,43,114,46,104,111,115,116,125,99,97,116,99,104,40,101,41,123,118,46,
        99,114,111,115,115,68,111,109,97,105,110,61,33,48,125,125,105,102,40,118,46,100,97,116,97,38,38,118,46,112,114,111,99,101,115,115,68,97,116,97,38,38,34,115,116,114,105,110,103,34,33,61,116,121,112,
        101,111,102,32,118,46,100,97,116,97,38,38,40,118,46,100,97,116,97,61,83,46,112,97,114,97,109,40,118,46,100,97,116,97,44,118,46,116,114,97,100,105,116,105,111,110,97,108,41,41,44,87,116,40,79,116,
        44,118,44,116,44,84,41,44,104,41,114,101,116,117,114,110,32,84,59,102,111,114,40,105,32,105,110,40,103,61,83,46,101,118,101,110,116,38,38,118,46,103,108,111,98,97,108,41,38,38,48,61,61,83,46,97,
        99,116,105,118,101,43,43,38,38,83,46,101,118,101,110,116,46,116,114,105,103,103,101,114,40,34,97,106,97,120,83,116,97,114,116,34,41,44,118,46,116,121,112,101,61,118,46,116,121,112,101,46,116,111,
        85,112,112,101,114,67,97,115,101,40,41,44,118,46,104,97,115,67,111,110,116,101,110,116,61,33,76,116,46,116,101,115,116,40,118,46,116,121,112,101,41,44,102,61,118,46,117,114,108,46,114,101,112,108,
        97,99,101,40,106,116,44,34,34,41,44,118,46,104,97,115,67,111,110,116,101,110,116,63,118,46,100,97,116,97,38,38,118,46,112,114,111,99,101,115,115,68,97,116,97,38,38,48,61,61,61,40,118,46,99,111,110,
        116,101,110,116,84,121,112,101,124,124,34,34,41,46,105,110,100,101,120,79,102,40,34,97,112,112,108,105,99,97,116,105,111,110,47,120,45,119,119,119,45,102,111,114,109,45,117,114,108,101,110,99,111,
        100,101,100,34,41,38,38,40,118,46,100,97,116,97,61,118,46,100,97,116,97,46,114,101,112,108,97,99,101,40,78,116,44,34,43,34,41,41,58,40,111,61,118,46,117,114,108,46,115,108,105,99,101,40,102,46,108,
        101,110,103,116,104,41,44,118,46,100,97,116,97,38,38,40,118,46,112,114,111,99,101,115,115,68,97,116,97,124,124,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,118,46,100,97,116,97,
        41,38,38,40,102,43,61,40,84,116,46,116,101,115,116,40,102,41,63,34,38,34,58,34,63,34,41,43,118,46,100,97,116,97,44,100,101,108,101,116,101,32,118,46,100,97,116,97,41,44,33,49,61,61,61,118,46,99,
        97,99,104,101,38,38,40,102,61,102,46,114,101,112,108,97,99,101,40,68,116,44,34,36,49,34,41,44,111,61,40,84,116,46,116,101,115,116,40,102,41,63,34,38,34,58,34,63,34,41,43,34,95,61,34,43,119,116,46,
        103,117,105,100,43,43,43,111,41,44,118,46,117,114,108,61,102,43,111,41,44,118,46,105,102,77,111,100,105,102,105,101,100,38,38,40,83,46,108,97,115,116,77,111,100,105,102,105,101,100,91,102,93,38,
        38,84,46,115,101,116,82,101,113,117,101,115,116,72,101,97,100,101,114,40,34,73,102,45,77,111,100,105,102,105,101,100,45,83,105,110,99,101,34,44,83,46,108,97,115,116,77,111,100,105,102,105,101,100,
        91,102,93,41,44,83,46,101,116,97,103,91,102,93,38,38,84,46,115,101,116,82,101,113,117,101,115,116,72,101,97,100,101,114,40,34,73,102,45,78,111,110,101,45,77,97,116,99,104,34,44,83,46,101,116,97,
        103,91,102,93,41,41,44,40,118,46,100,97,116,97,38,38,118,46,104,97,115,67,111,110,116,101,110,116,38,38,33,49,33,61,61,118,46,99,111,110,116,101,110,116,84,121,112,101,124,124,116,46,99,111,110,
        116,101,110,116,84,121,112,101,41,38,38,84,46,115,101,116,82,101,113,117,101,115,116,72,101,97,100,101,114,40,34,67,111,110,116,101,110,116,45,84,121,112,101,34,44,118,46,99,111,110,116,101,110,
        116,84,121,112,101,41,44,84,46,115,101,116,82,101,113,117,101,115,116,72,101,97,100,101,114,40,34,65,99,99,101,112,116,34,44,118,46,100,97,116,97,84,121,112,101,115,91,48,93,38,38,118,46,97,99,99,
        101,112,116,115,91,118,46,100,97,116,97,84,121,112,101,115,91,48,93,93,63,118,46,97,99,99,101,112,116,115,91,118,46,100,97,116,97,84,121,112,101,115,91,48,93,93,43,40,34,42,34,33,61,61,118,46,100,
        97,116,97,84,121,112,101,115,91,48,93,63,34,44,32,34,43,82,116,43,34,59,32,113,61,48,46,48,49,34,58,34,34,41,58,118,46,97,99,99,101,112,116,115,91,34,42,34,93,41,44,118,46,104,101,97,100,101,114,
        115,41,84,46,115,101,116,82,101,113,117,101,115,116,72,101,97,100,101,114,40,105,44,118,46,104,101,97,100,101,114,115,91,105,93,41,59,105,102,40,118,46,98,101,102,111,114,101,83,101,110,100,38,38,
        40,33,49,61,61,61,118,46,98,101,102,111,114,101,83,101,110,100,46,99,97,108,108,40,121,44,84,44,118,41,124,124,104,41,41,114,101,116,117,114,110,32,84,46,97,98,111,114,116,40,41,59,105,102,40,117,
        61,34,97,98,111,114,116,34,44,98,46,97,100,100,40,118,46,99,111,109,112,108,101,116,101,41,44,84,46,100,111,110,101,40,118,46,115,117,99,99,101,115,115,41,44,84,46,102,97,105,108,40,118,46,101,114,
        114,111,114,41,44,99,61,87,116,40,80,116,44,118,44,116,44,84,41,41,123,105,102,40,84,46,114,101,97,100,121,83,116,97,116,101,61,49,44,103,38,38,109,46,116,114,105,103,103,101,114,40,34,97,106,97,
        120,83,101,110,100,34,44,91,84,44,118,93,41,44,104,41,114,101,116,117,114,110,32,84,59,118,46,97,115,121,110,99,38,38,48,60,118,46,116,105,109,101,111,117,116,38,38,40,100,61,67,46,115,101,116,84,
        105,109,101,111,117,116,40,102,117,110,99,116,105,111,110,40,41,123,84,46,97,98,111,114,116,40,34,116,105,109,101,111,117,116,34,41,125,44,118,46,116,105,109,101,111,117,116,41,41,59,116,114,121,
        123,104,61,33,49,44,99,46,115,101,110,100,40,97,44,108,41,125,99,97,116,99,104,40,101,41,123,105,102,40,104,41,116,104,114,111,119,32,101,59,108,40,45,49,44,101,41,125,125,101,108,115,101,32,108,
        40,45,49,44,34,78,111,32,84,114,97,110,115,112,111,114,116,34,41,59,102,117,110,99,116,105,111,110,32,108,40,101,44,116,44,110,44,114,41,123,118,97,114,32,105,44,111,44,97,44,115,44,117,44,108,61,
        116,59,104,124,124,40,104,61,33,48,44,100,38,38,67,46,99,108,101,97,114,84,105,109,101,111,117,116,40,100,41,44,99,61,118,111,105,100,32,48,44,112,61,114,124,124,34,34,44,84,46,114,101,97,100,121,
        83,116,97,116,101,61,48,60,101,63,52,58,48,44,105,61,50,48,48,60,61,101,38,38,101,60,51,48,48,124,124,51,48,52,61,61,61,101,44,110,38,38,40,115,61,102,117,110,99,116,105,111,110,40,101,44,116,44,
        110,41,123,118,97,114,32,114,44,105,44,111,44,97,44,115,61,101,46,99,111,110,116,101,110,116,115,44,117,61,101,46,100,97,116,97,84,121,112,101,115,59,119,104,105,108,101,40,34,42,34,61,61,61,117,
        91,48,93,41,117,46,115,104,105,102,116,40,41,44,118,111,105,100,32,48,61,61,61,114,38,38,40,114,61,101,46,109,105,109,101,84,121,112,101,124,124,116,46,103,101,116,82,101,115,112,111,110,115,101,
        72,101,97,100,101,114,40,34,67,111,110,116,101,110,116,45,84,121,112,101,34,41,41,59,105,102,40,114,41,102,111,114,40,105,32,105,110,32,115,41,105,102,40,115,91,105,93,38,38,115,91,105,93,46,116,
        101,115,116,40,114,41,41,123,117,46,117,110,115,104,105,102,116,40,105,41,59,98,114,101,97,107,125,105,102,40,117,91,48,93,105,110,32,110,41,111,61,117,91,48,93,59,101,108,115,101,123,102,111,114,
        40,105,32,105,110,32,110,41,123,105,102,40,33,117,91,48,93,124,124,101,46,99,111,110,118,101,114,116,101,114,115,91,105,43,34,32,34,43,117,91,48,93,93,41,123,111,61,105,59,98,114,101,97,107,125,
        97,124,124,40,97,61,105,41,125,111,61,111,124,124,97,125,105,102,40,111,41,114,101,116,117,114,110,32,111,33,61,61,117,91,48,93,38,38,117,46,117,110,115,104,105,102,116,40,111,41,44,110,91,111,93,
        125,40,118,44,84,44,110,41,41,44,33,105,38,38,45,49,60,83,46,105,110,65,114,114,97,121,40,34,115,99,114,105,112,116,34,44,118,46,100,97,116,97,84,121,112,101,115,41,38,38,83,46,105,110,65,114,114,
        97,121,40,34,106,115,111,110,34,44,118,46,100,97,116,97,84,121,112,101,115,41,60,48,38,38,40,118,46,99,111,110,118,101,114,116,101,114,115,91,34,116,101,120,116,32,115,99,114,105,112,116,34,93,61,
        102,117,110,99,116,105,111,110,40,41,123,125,41,44,115,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,44,114,41,123,118,97,114,32,105,44,111,44,97,44,115,44,117,44,108,61,123,125,44,99,61,
        101,46,100,97,116,97,84,121,112,101,115,46,115,108,105,99,101,40,41,59,105,102,40,99,91,49,93,41,102,111,114,40,97,32,105,110,32,101,46,99,111,110,118,101,114,116,101,114,115,41,108,91,97,46,116,
        111,76,111,119,101,114,67,97,115,101,40,41,93,61,101,46,99,111,110,118,101,114,116,101,114,115,91,97,93,59,111,61,99,46,115,104,105,102,116,40,41,59,119,104,105,108,101,40,111,41,105,102,40,101,
        46,114,101,115,112,111,110,115,101,70,105,101,108,100,115,91,111,93,38,38,40,110,91,101,46,114,101,115,112,111,110,115,101,70,105,101,108,100,115,91,111,93,93,61,116,41,44,33,117,38,38,114,38,38,
        101,46,100,97,116,97,70,105,108,116,101,114,38,38,40,116,61,101,46,100,97,116,97,70,105,108,116,101,114,40,116,44,101,46,100,97,116,97,84,121,112,101,41,41,44,117,61,111,44,111,61,99,46,115,104,
        105,102,116,40,41,41,105,102,40,34,42,34,61,61,61,111,41,111,61,117,59,101,108,115,101,32,105,102,40,34,42,34,33,61,61,117,38,38,117,33,61,61,111,41,123,105,102,40,33,40,97,61,108,91,117,43,34,32,
        34,43,111,93,124,124,108,91,34,42,32,34,43,111,93,41,41,102,111,114,40,105,32,105,110,32,108,41,105,102,40,40,115,61,105,46,115,112,108,105,116,40,34,32,34,41,41,91,49,93,61,61,61,111,38,38,40,97,
        61,108,91,117,43,34,32,34,43,115,91,48,93,93,124,124,108,91,34,42,32,34,43,115,91,48,93,93,41,41,123,33,48,61,61,61,97,63,97,61,108,91,105,93,58,33,48,33,61,61,108,91,105,93,38,38,40,111,61,115,
        91,48,93,44,99,46,117,110,115,104,105,102,116,40,115,91,49,93,41,41,59,98,114,101,97,107,125,105,102,40,33,48,33,61,61,97,41,105,102,40,97,38,38,101,91,34,116,104,114,111,119,115,34,93,41,116,61,
        97,40,116,41,59,101,108,115,101,32,116,114,121,123,116,61,97,40,116,41,125,99,97,116,99,104,40,101,41,123,114,101,116,117,114,110,123,115,116,97,116,101,58,34,112,97,114,115,101,114,101,114,114,
        111,114,34,44,101,114,114,111,114,58,97,63,101,58,34,78,111,32,99,111,110,118,101,114,115,105,111,110,32,102,114,111,109,32,34,43,117,43,34,32,116,111,32,34,43,111,125,125,125,114,101,116,117,114,
        110,123,115,116,97,116,101,58,34,115,117,99,99,101,115,115,34,44,100,97,116,97,58,116,125,125,40,118,44,115,44,84,44,105,41,44,105,63,40,118,46,105,102,77,111,100,105,102,105,101,100,38,38,40,40,
        117,61,84,46,103,101,116,82,101,115,112,111,110,115,101,72,101,97,100,101,114,40,34,76,97,115,116,45,77,111,100,105,102,105,101,100,34,41,41,38,38,40,83,46,108,97,115,116,77,111,100,105,102,105,
        101,100,91,102,93,61,117,41,44,40,117,61,84,46,103,101,116,82,101,115,112,111,110,115,101,72,101,97,100,101,114,40,34,101,116,97,103,34,41,41,38,38,40,83,46,101,116,97,103,91,102,93,61,117,41,41,
        44,50,48,52,61,61,61,101,124,124,34,72,69,65,68,34,61,61,61,118,46,116,121,112,101,63,108,61,34,110,111,99,111,110,116,101,110,116,34,58,51,48,52,61,61,61,101,63,108,61,34,110,111,116,109,111,100,
        105,102,105,101,100,34,58,40,108,61,115,46,115,116,97,116,101,44,111,61,115,46,100,97,116,97,44,105,61,33,40,97,61,115,46,101,114,114,111,114,41,41,41,58,40,97,61,108,44,33,101,38,38,108,124,124,
        40,108,61,34,101,114,114,111,114,34,44,101,60,48,38,38,40,101,61,48,41,41,41,44,84,46,115,116,97,116,117,115,61,101,44,84,46,115,116,97,116,117,115,84,101,120,116,61,40,116,124,124,108,41,43,34,
        34,44,105,63,120,46,114,101,115,111,108,118,101,87,105,116,104,40,121,44,91,111,44,108,44,84,93,41,58,120,46,114,101,106,101,99,116,87,105,116,104,40,121,44,91,84,44,108,44,97,93,41,44,84,46,115,
        116,97,116,117,115,67,111,100,101,40,119,41,44,119,61,118,111,105,100,32,48,44,103,38,38,109,46,116,114,105,103,103,101,114,40,105,63,34,97,106,97,120,83,117,99,99,101,115,115,34,58,34,97,106,97,
        120,69,114,114,111,114,34,44,91,84,44,118,44,105,63,111,58,97,93,41,44,98,46,102,105,114,101,87,105,116,104,40,121,44,91,84,44,108,93,41,44,103,38,38,40,109,46,116,114,105,103,103,101,114,40,34,
        97,106,97,120,67,111,109,112,108,101,116,101,34,44,91,84,44,118,93,41,44,45,45,83,46,97,99,116,105,118,101,124,124,83,46,101,118,101,110,116,46,116,114,105,103,103,101,114,40,34,97,106,97,120,83,
        116,111,112,34,41,41,41,125,114,101,116,117,114,110,32,84,125,44,103,101,116,74,83,79,78,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,114,101,116,117,114,110,32,83,46,103,101,116,
        40,101,44,116,44,110,44,34,106,115,111,110,34,41,125,44,103,101,116,83,99,114,105,112,116,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,83,46,103,101,116,40,101,
        44,118,111,105,100,32,48,44,116,44,34,115,99,114,105,112,116,34,41,125,125,41,44,83,46,101,97,99,104,40,91,34,103,101,116,34,44,34,112,111,115,116,34,93,44,102,117,110,99,116,105,111,110,40,101,
        44,105,41,123,83,91,105,93,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,44,114,41,123,114,101,116,117,114,110,32,109,40,116,41,38,38,40,114,61,114,124,124,110,44,110,61,116,44,116,61,118,
        111,105,100,32,48,41,44,83,46,97,106,97,120,40,83,46,101,120,116,101,110,100,40,123,117,114,108,58,101,44,116,121,112,101,58,105,44,100,97,116,97,84,121,112,101,58,114,44,100,97,116,97,58,116,44,
        115,117,99,99,101,115,115,58,110,125,44,83,46,105,115,80,108,97,105,110,79,98,106,101,99,116,40,101,41,38,38,101,41,41,125,125,41,44,83,46,97,106,97,120,80,114,101,102,105,108,116,101,114,40,102,
        117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,59,102,111,114,40,116,32,105,110,32,101,46,104,101,97,100,101,114,115,41,34,99,111,110,116,101,110,116,45,116,121,112,101,34,61,61,61,116,
        46,116,111,76,111,119,101,114,67,97,115,101,40,41,38,38,40,101,46,99,111,110,116,101,110,116,84,121,112,101,61,101,46,104,101,97,100,101,114,115,91,116,93,124,124,34,34,41,125,41,44,83,46,95,101,
        118,97,108,85,114,108,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,114,101,116,117,114,110,32,83,46,97,106,97,120,40,123,117,114,108,58,101,44,116,121,112,101,58,34,71,69,84,34,
        44,100,97,116,97,84,121,112,101,58,34,115,99,114,105,112,116,34,44,99,97,99,104,101,58,33,48,44,97,115,121,110,99,58,33,49,44,103,108,111,98,97,108,58,33,49,44,99,111,110,118,101,114,116,101,114,
        115,58,123,34,116,101,120,116,32,115,99,114,105,112,116,34,58,102,117,110,99,116,105,111,110,40,41,123,125,125,44,100,97,116,97,70,105,108,116,101,114,58,102,117,110,99,116,105,111,110,40,101,41,
        123,83,46,103,108,111,98,97,108,69,118,97,108,40,101,44,116,44,110,41,125,125,41,125,44,83,46,102,110,46,101,120,116,101,110,100,40,123,119,114,97,112,65,108,108,58,102,117,110,99,116,105,111,110,
        40,101,41,123,118,97,114,32,116,59,114,101,116,117,114,110,32,116,104,105,115,91,48,93,38,38,40,109,40,101,41,38,38,40,101,61,101,46,99,97,108,108,40,116,104,105,115,91,48,93,41,41,44,116,61,83,
        40,101,44,116,104,105,115,91,48,93,46,111,119,110,101,114,68,111,99,117,109,101,110,116,41,46,101,113,40,48,41,46,99,108,111,110,101,40,33,48,41,44,116,104,105,115,91,48,93,46,112,97,114,101,110,
        116,78,111,100,101,38,38,116,46,105,110,115,101,114,116,66,101,102,111,114,101,40,116,104,105,115,91,48,93,41,44,116,46,109,97,112,40,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,61,
        116,104,105,115,59,119,104,105,108,101,40,101,46,102,105,114,115,116,69,108,101,109,101,110,116,67,104,105,108,100,41,101,61,101,46,102,105,114,115,116,69,108,101,109,101,110,116,67,104,105,108,
        100,59,114,101,116,117,114,110,32,101,125,41,46,97,112,112,101,110,100,40,116,104,105,115,41,41,44,116,104,105,115,125,44,119,114,97,112,73,110,110,101,114,58,102,117,110,99,116,105,111,110,40,110,
        41,123,114,101,116,117,114,110,32,109,40,110,41,63,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,101,41,123,83,40,116,104,105,115,41,46,119,114,97,112,73,110,110,101,114,
        40,110,46,99,97,108,108,40,116,104,105,115,44,101,41,41,125,41,58,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,61,83,40,116,104,105,115,41,44,116,
        61,101,46,99,111,110,116,101,110,116,115,40,41,59,116,46,108,101,110,103,116,104,63,116,46,119,114,97,112,65,108,108,40,110,41,58,101,46,97,112,112,101,110,100,40,110,41,125,41,125,44,119,114,97,
        112,58,102,117,110,99,116,105,111,110,40,116,41,123,118,97,114,32,110,61,109,40,116,41,59,114,101,116,117,114,110,32,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,101,41,
        123,83,40,116,104,105,115,41,46,119,114,97,112,65,108,108,40,110,63,116,46,99,97,108,108,40,116,104,105,115,44,101,41,58,116,41,125,41,125,44,117,110,119,114,97,112,58,102,117,110,99,116,105,111,
        110,40,101,41,123,114,101,116,117,114,110,32,116,104,105,115,46,112,97,114,101,110,116,40,101,41,46,110,111,116,40,34,98,111,100,121,34,41,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,41,
        123,83,40,116,104,105,115,41,46,114,101,112,108,97,99,101,87,105,116,104,40,116,104,105,115,46,99,104,105,108,100,78,111,100,101,115,41,125,41,44,116,104,105,115,125,125,41,44,83,46,101,120,112,
        114,46,112,115,101,117,100,111,115,46,104,105,100,100,101,110,61,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,33,83,46,101,120,112,114,46,112,115,101,117,100,111,115,46,118,
        105,115,105,98,108,101,40,101,41,125,44,83,46,101,120,112,114,46,112,115,101,117,100,111,115,46,118,105,115,105,98,108,101,61,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,
        33,33,40,101,46,111,102,102,115,101,116,87,105,100,116,104,124,124,101,46,111,102,102,115,101,116,72,101,105,103,104,116,124,124,101,46,103,101,116,67,108,105,101,110,116,82,101,99,116,115,40,41,
        46,108,101,110,103,116,104,41,125,44,83,46,97,106,97,120,83,101,116,116,105,110,103,115,46,120,104,114,61,102,117,110,99,116,105,111,110,40,41,123,116,114,121,123,114,101,116,117,114,110,32,110,
        101,119,32,67,46,88,77,76,72,116,116,112,82,101,113,117,101,115,116,125,99,97,116,99,104,40,101,41,123,125,125,59,118,97,114,32,66,116,61,123,48,58,50,48,48,44,49,50,50,51,58,50,48,52,125,44,36,
        116,61,83,46,97,106,97,120,83,101,116,116,105,110,103,115,46,120,104,114,40,41,59,121,46,99,111,114,115,61,33,33,36,116,38,38,34,119,105,116,104,67,114,101,100,101,110,116,105,97,108,115,34,105,
        110,32,36,116,44,121,46,97,106,97,120,61,36,116,61,33,33,36,116,44,83,46,97,106,97,120,84,114,97,110,115,112,111,114,116,40,102,117,110,99,116,105,111,110,40,105,41,123,118,97,114,32,111,44,97,59,
        105,102,40,121,46,99,111,114,115,124,124,36,116,38,38,33,105,46,99,114,111,115,115,68,111,109,97,105,110,41,114,101,116,117,114,110,123,115,101,110,100,58,102,117,110,99,116,105,111,110,40,101,44,
        116,41,123,118,97,114,32,110,44,114,61,105,46,120,104,114,40,41,59,105,102,40,114,46,111,112,101,110,40,105,46,116,121,112,101,44,105,46,117,114,108,44,105,46,97,115,121,110,99,44,105,46,117,115,
        101,114,110,97,109,101,44,105,46,112,97,115,115,119,111,114,100,41,44,105,46,120,104,114,70,105,101,108,100,115,41,102,111,114,40,110,32,105,110,32,105,46,120,104,114,70,105,101,108,100,115,41,114,
        91,110,93,61,105,46,120,104,114,70,105,101,108,100,115,91,110,93,59,102,111,114,40,110,32,105,110,32,105,46,109,105,109,101,84,121,112,101,38,38,114,46,111,118,101,114,114,105,100,101,77,105,109,
        101,84,121,112,101,38,38,114,46,111,118,101,114,114,105,100,101,77,105,109,101,84,121,112,101,40,105,46,109,105,109,101,84,121,112,101,41,44,105,46,99,114,111,115,115,68,111,109,97,105,110,124,124,
        101,91,34,88,45,82,101,113,117,101,115,116,101,100,45,87,105,116,104,34,93,124,124,40,101,91,34,88,45,82,101,113,117,101,115,116,101,100,45,87,105,116,104,34,93,61,34,88,77,76,72,116,116,112,82,
        101,113,117,101,115,116,34,41,44,101,41,114,46,115,101,116,82,101,113,117,101,115,116,72,101,97,100,101,114,40,110,44,101,91,110,93,41,59,111,61,102,117,110,99,116,105,111,110,40,101,41,123,114,
        101,116,117,114,110,32,102,117,110,99,116,105,111,110,40,41,123,111,38,38,40,111,61,97,61,114,46,111,110,108,111,97,100,61,114,46,111,110,101,114,114,111,114,61,114,46,111,110,97,98,111,114,116,
        61,114,46,111,110,116,105,109,101,111,117,116,61,114,46,111,110,114,101,97,100,121,115,116,97,116,101,99,104,97,110,103,101,61,110,117,108,108,44,34,97,98,111,114,116,34,61,61,61,101,63,114,46,97,
        98,111,114,116,40,41,58,34,101,114,114,111,114,34,61,61,61,101,63,34,110,117,109,98,101,114,34,33,61,116,121,112,101,111,102,32,114,46,115,116,97,116,117,115,63,116,40,48,44,34,101,114,114,111,114,
        34,41,58,116,40,114,46,115,116,97,116,117,115,44,114,46,115,116,97,116,117,115,84,101,120,116,41,58,116,40,66,116,91,114,46,115,116,97,116,117,115,93,124,124,114,46,115,116,97,116,117,115,44,114,
        46,115,116,97,116,117,115,84,101,120,116,44,34,116,101,120,116,34,33,61,61,40,114,46,114,101,115,112,111,110,115,101,84,121,112,101,124,124,34,116,101,120,116,34,41,124,124,34,115,116,114,105,110,
        103,34,33,61,116,121,112,101,111,102,32,114,46,114,101,115,112,111,110,115,101,84,101,120,116,63,123,98,105,110,97,114,121,58,114,46,114,101,115,112,111,110,115,101,125,58,123,116,101,120,116,58,
        114,46,114,101,115,112,111,110,115,101,84,101,120,116,125,44,114,46,103,101,116,65,108,108,82,101,115,112,111,110,115,101,72,101,97,100,101,114,115,40,41,41,41,125,125,44,114,46,111,110,108,111,
        97,100,61,111,40,41,44,97,61,114,46,111,110,101,114,114,111,114,61,114,46,111,110,116,105,109,101,111,117,116,61,111,40,34,101,114,114,111,114,34,41,44,118,111,105,100,32,48,33,61,61,114,46,111,
        110,97,98,111,114,116,63,114,46,111,110,97,98,111,114,116,61,97,58,114,46,111,110,114,101,97,100,121,115,116,97,116,101,99,104,97,110,103,101,61,102,117,110,99,116,105,111,110,40,41,123,52,61,61,
        61,114,46,114,101,97,100,121,83,116,97,116,101,38,38,67,46,115,101,116,84,105,109,101,111,117,116,40,102,117,110,99,116,105,111,110,40,41,123,111,38,38,97,40,41,125,41,125,44,111,61,111,40,34,97,
        98,111,114,116,34,41,59,116,114,121,123,114,46,115,101,110,100,40,105,46,104,97,115,67,111,110,116,101,110,116,38,38,105,46,100,97,116,97,124,124,110,117,108,108,41,125,99,97,116,99,104,40,101,41,
        123,105,102,40,111,41,116,104,114,111,119,32,101,125,125,44,97,98,111,114,116,58,102,117,110,99,116,105,111,110,40,41,123,111,38,38,111,40,41,125,125,125,41,44,83,46,97,106,97,120,80,114,101,102,
        105,108,116,101,114,40,102,117,110,99,116,105,111,110,40,101,41,123,101,46,99,114,111,115,115,68,111,109,97,105,110,38,38,40,101,46,99,111,110,116,101,110,116,115,46,115,99,114,105,112,116,61,33,
        49,41,125,41,44,83,46,97,106,97,120,83,101,116,117,112,40,123,97,99,99,101,112,116,115,58,123,115,99,114,105,112,116,58,34,116,101,120,116,47,106,97,118,97,115,99,114,105,112,116,44,32,97,112,112,
        108,105,99,97,116,105,111,110,47,106,97,118,97,115,99,114,105,112,116,44,32,97,112,112,108,105,99,97,116,105,111,110,47,101,99,109,97,115,99,114,105,112,116,44,32,97,112,112,108,105,99,97,116,105,
        111,110,47,120,45,101,99,109,97,115,99,114,105,112,116,34,125,44,99,111,110,116,101,110,116,115,58,123,115,99,114,105,112,116,58,47,92,98,40,63,58,106,97,118,97,124,101,99,109,97,41,115,99,114,105,
        112,116,92,98,47,125,44,99,111,110,118,101,114,116,101,114,115,58,123,34,116,101,120,116,32,115,99,114,105,112,116,34,58,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,83,
        46,103,108,111,98,97,108,69,118,97,108,40,101,41,44,101,125,125,125,41,44,83,46,97,106,97,120,80,114,101,102,105,108,116,101,114,40,34,115,99,114,105,112,116,34,44,102,117,110,99,116,105,111,110,
        40,101,41,123,118,111,105,100,32,48,61,61,61,101,46,99,97,99,104,101,38,38,40,101,46,99,97,99,104,101,61,33,49,41,44,101,46,99,114,111,115,115,68,111,109,97,105,110,38,38,40,101,46,116,121,112,101,
        61,34,71,69,84,34,41,125,41,44,83,46,97,106,97,120,84,114,97,110,115,112,111,114,116,40,34,115,99,114,105,112,116,34,44,102,117,110,99,116,105,111,110,40,110,41,123,118,97,114,32,114,44,105,59,105,
        102,40,110,46,99,114,111,115,115,68,111,109,97,105,110,124,124,110,46,115,99,114,105,112,116,65,116,116,114,115,41,114,101,116,117,114,110,123,115,101,110,100,58,102,117,110,99,116,105,111,110,40,
        101,44,116,41,123,114,61,83,40,34,60,115,99,114,105,112,116,62,34,41,46,97,116,116,114,40,110,46,115,99,114,105,112,116,65,116,116,114,115,124,124,123,125,41,46,112,114,111,112,40,123,99,104,97,
        114,115,101,116,58,110,46,115,99,114,105,112,116,67,104,97,114,115,101,116,44,115,114,99,58,110,46,117,114,108,125,41,46,111,110,40,34,108,111,97,100,32,101,114,114,111,114,34,44,105,61,102,117,
        110,99,116,105,111,110,40,101,41,123,114,46,114,101,109,111,118,101,40,41,44,105,61,110,117,108,108,44,101,38,38,116,40,34,101,114,114,111,114,34,61,61,61,101,46,116,121,112,101,63,52,48,52,58,50,
        48,48,44,101,46,116,121,112,101,41,125,41,44,69,46,104,101,97,100,46,97,112,112,101,110,100,67,104,105,108,100,40,114,91,48,93,41,125,44,97,98,111,114,116,58,102,117,110,99,116,105,111,110,40,41,
        123,105,38,38,105,40,41,125,125,125,41,59,118,97,114,32,95,116,44,122,116,61,91,93,44,85,116,61,47,40,61,41,92,63,40,63,61,38,124,36,41,124,92,63,92,63,47,59,83,46,97,106,97,120,83,101,116,117,112,
        40,123,106,115,111,110,112,58,34,99,97,108,108,98,97,99,107,34,44,106,115,111,110,112,67,97,108,108,98,97,99,107,58,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,61,122,116,46,112,111,
        112,40,41,124,124,83,46,101,120,112,97,110,100,111,43,34,95,34,43,119,116,46,103,117,105,100,43,43,59,114,101,116,117,114,110,32,116,104,105,115,91,101,93,61,33,48,44,101,125,125,41,44,83,46,97,
        106,97,120,80,114,101,102,105,108,116,101,114,40,34,106,115,111,110,32,106,115,111,110,112,34,44,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,44,105,44,111,44,97,
        61,33,49,33,61,61,101,46,106,115,111,110,112,38,38,40,85,116,46,116,101,115,116,40,101,46,117,114,108,41,63,34,117,114,108,34,58,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,101,
        46,100,97,116,97,38,38,48,61,61,61,40,101,46,99,111,110,116,101,110,116,84,121,112,101,124,124,34,34,41,46,105,110,100,101,120,79,102,40,34,97,112,112,108,105,99,97,116,105,111,110,47,120,45,119,
        119,119,45,102,111,114,109,45,117,114,108,101,110,99,111,100,101,100,34,41,38,38,85,116,46,116,101,115,116,40,101,46,100,97,116,97,41,38,38,34,100,97,116,97,34,41,59,105,102,40,97,124,124,34,106,
        115,111,110,112,34,61,61,61,101,46,100,97,116,97,84,121,112,101,115,91,48,93,41,114,101,116,117,114,110,32,114,61,101,46,106,115,111,110,112,67,97,108,108,98,97,99,107,61,109,40,101,46,106,115,111,
        110,112,67,97,108,108,98,97,99,107,41,63,101,46,106,115,111,110,112,67,97,108,108,98,97,99,107,40,41,58,101,46,106,115,111,110,112,67,97,108,108,98,97,99,107,44,97,63,101,91,97,93,61,101,91,97,93,
        46,114,101,112,108,97,99,101,40,85,116,44,34,36,49,34,43,114,41,58,33,49,33,61,61,101,46,106,115,111,110,112,38,38,40,101,46,117,114,108,43,61,40,84,116,46,116,101,115,116,40,101,46,117,114,108,
        41,63,34,38,34,58,34,63,34,41,43,101,46,106,115,111,110,112,43,34,61,34,43,114,41,44,101,46,99,111,110,118,101,114,116,101,114,115,91,34,115,99,114,105,112,116,32,106,115,111,110,34,93,61,102,117,
        110,99,116,105,111,110,40,41,123,114,101,116,117,114,110,32,111,124,124,83,46,101,114,114,111,114,40,114,43,34,32,119,97,115,32,110,111,116,32,99,97,108,108,101,100,34,41,44,111,91,48,93,125,44,
        101,46,100,97,116,97,84,121,112,101,115,91,48,93,61,34,106,115,111,110,34,44,105,61,67,91,114,93,44,67,91,114,93,61,102,117,110,99,116,105,111,110,40,41,123,111,61,97,114,103,117,109,101,110,116,
        115,125,44,110,46,97,108,119,97,121,115,40,102,117,110,99,116,105,111,110,40,41,123,118,111,105,100,32,48,61,61,61,105,63,83,40,67,41,46,114,101,109,111,118,101,80,114,111,112,40,114,41,58,67,91,
        114,93,61,105,44,101,91,114,93,38,38,40,101,46,106,115,111,110,112,67,97,108,108,98,97,99,107,61,116,46,106,115,111,110,112,67,97,108,108,98,97,99,107,44,122,116,46,112,117,115,104,40,114,41,41,
        44,111,38,38,109,40,105,41,38,38,105,40,111,91,48,93,41,44,111,61,105,61,118,111,105,100,32,48,125,41,44,34,115,99,114,105,112,116,34,125,41,44,121,46,99,114,101,97,116,101,72,84,77,76,68,111,99,
        117,109,101,110,116,61,40,40,95,116,61,69,46,105,109,112,108,101,109,101,110,116,97,116,105,111,110,46,99,114,101,97,116,101,72,84,77,76,68,111,99,117,109,101,110,116,40,34,34,41,46,98,111,100,121,
        41,46,105,110,110,101,114,72,84,77,76,61,34,60,102,111,114,109,62,60,47,102,111,114,109,62,60,102,111,114,109,62,60,47,102,111,114,109,62,34,44,50,61,61,61,95,116,46,99,104,105,108,100,78,111,100,
        101,115,46,108,101,110,103,116,104,41,44,83,46,112,97,114,115,101,72,84,77,76,61,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,114,101,116,117,114,110,34,115,116,114,105,110,103,34,
        33,61,116,121,112,101,111,102,32,101,63,91,93,58,40,34,98,111,111,108,101,97,110,34,61,61,116,121,112,101,111,102,32,116,38,38,40,110,61,116,44,116,61,33,49,41,44,116,124,124,40,121,46,99,114,101,
        97,116,101,72,84,77,76,68,111,99,117,109,101,110,116,63,40,40,114,61,40,116,61,69,46,105,109,112,108,101,109,101,110,116,97,116,105,111,110,46,99,114,101,97,116,101,72,84,77,76,68,111,99,117,109,
        101,110,116,40,34,34,41,41,46,99,114,101,97,116,101,69,108,101,109,101,110,116,40,34,98,97,115,101,34,41,41,46,104,114,101,102,61,69,46,108,111,99,97,116,105,111,110,46,104,114,101,102,44,116,46,
        104,101,97,100,46,97,112,112,101,110,100,67,104,105,108,100,40,114,41,41,58,116,61,69,41,44,111,61,33,110,38,38,91,93,44,40,105,61,78,46,101,120,101,99,40,101,41,41,63,91,116,46,99,114,101,97,116,
        101,69,108,101,109,101,110,116,40,105,91,49,93,41,93,58,40,105,61,120,101,40,91,101,93,44,116,44,111,41,44,111,38,38,111,46,108,101,110,103,116,104,38,38,83,40,111,41,46,114,101,109,111,118,101,
        40,41,44,83,46,109,101,114,103,101,40,91,93,44,105,46,99,104,105,108,100,78,111,100,101,115,41,41,41,59,118,97,114,32,114,44,105,44,111,125,44,83,46,102,110,46,108,111,97,100,61,102,117,110,99,116,
        105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,44,105,44,111,44,97,61,116,104,105,115,44,115,61,101,46,105,110,100,101,120,79,102,40,34,32,34,41,59,114,101,116,117,114,110,45,49,60,115,
        38,38,40,114,61,104,116,40,101,46,115,108,105,99,101,40,115,41,41,44,101,61,101,46,115,108,105,99,101,40,48,44,115,41,41,44,109,40,116,41,63,40,110,61,116,44,116,61,118,111,105,100,32,48,41,58,116,
        38,38,34,111,98,106,101,99,116,34,61,61,116,121,112,101,111,102,32,116,38,38,40,105,61,34,80,79,83,84,34,41,44,48,60,97,46,108,101,110,103,116,104,38,38,83,46,97,106,97,120,40,123,117,114,108,58,
        101,44,116,121,112,101,58,105,124,124,34,71,69,84,34,44,100,97,116,97,84,121,112,101,58,34,104,116,109,108,34,44,100,97,116,97,58,116,125,41,46,100,111,110,101,40,102,117,110,99,116,105,111,110,
        40,101,41,123,111,61,97,114,103,117,109,101,110,116,115,44,97,46,104,116,109,108,40,114,63,83,40,34,60,100,105,118,62,34,41,46,97,112,112,101,110,100,40,83,46,112,97,114,115,101,72,84,77,76,40,101,
        41,41,46,102,105,110,100,40,114,41,58,101,41,125,41,46,97,108,119,97,121,115,40,110,38,38,102,117,110,99,116,105,111,110,40,101,44,116,41,123,97,46,101,97,99,104,40,102,117,110,99,116,105,111,110,
        40,41,123,110,46,97,112,112,108,121,40,116,104,105,115,44,111,124,124,91,101,46,114,101,115,112,111,110,115,101,84,101,120,116,44,116,44,101,93,41,125,41,125,41,44,116,104,105,115,125,44,83,46,101,
        120,112,114,46,112,115,101,117,100,111,115,46,97,110,105,109,97,116,101,100,61,102,117,110,99,116,105,111,110,40,116,41,123,114,101,116,117,114,110,32,83,46,103,114,101,112,40,83,46,116,105,109,
        101,114,115,44,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,116,61,61,61,101,46,101,108,101,109,125,41,46,108,101,110,103,116,104,125,44,83,46,111,102,102,115,101,116,
        61,123,115,101,116,79,102,102,115,101,116,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,44,105,44,111,44,97,44,115,44,117,44,108,61,83,46,99,115,115,40,101,44,34,
        112,111,115,105,116,105,111,110,34,41,44,99,61,83,40,101,41,44,102,61,123,125,59,34,115,116,97,116,105,99,34,61,61,61,108,38,38,40,101,46,115,116,121,108,101,46,112,111,115,105,116,105,111,110,61,
        34,114,101,108,97,116,105,118,101,34,41,44,115,61,99,46,111,102,102,115,101,116,40,41,44,111,61,83,46,99,115,115,40,101,44,34,116,111,112,34,41,44,117,61,83,46,99,115,115,40,101,44,34,108,101,102,
        116,34,41,44,40,34,97,98,115,111,108,117,116,101,34,61,61,61,108,124,124,34,102,105,120,101,100,34,61,61,61,108,41,38,38,45,49,60,40,111,43,117,41,46,105,110,100,101,120,79,102,40,34,97,117,116,
        111,34,41,63,40,97,61,40,114,61,99,46,112,111,115,105,116,105,111,110,40,41,41,46,116,111,112,44,105,61,114,46,108,101,102,116,41,58,40,97,61,112,97,114,115,101,70,108,111,97,116,40,111,41,124,124,
        48,44,105,61,112,97,114,115,101,70,108,111,97,116,40,117,41,124,124,48,41,44,109,40,116,41,38,38,40,116,61,116,46,99,97,108,108,40,101,44,110,44,83,46,101,120,116,101,110,100,40,123,125,44,115,41,
        41,41,44,110,117,108,108,33,61,116,46,116,111,112,38,38,40,102,46,116,111,112,61,116,46,116,111,112,45,115,46,116,111,112,43,97,41,44,110,117,108,108,33,61,116,46,108,101,102,116,38,38,40,102,46,
        108,101,102,116,61,116,46,108,101,102,116,45,115,46,108,101,102,116,43,105,41,44,34,117,115,105,110,103,34,105,110,32,116,63,116,46,117,115,105,110,103,46,99,97,108,108,40,101,44,102,41,58,99,46,
        99,115,115,40,102,41,125,125,44,83,46,102,110,46,101,120,116,101,110,100,40,123,111,102,102,115,101,116,58,102,117,110,99,116,105,111,110,40,116,41,123,105,102,40,97,114,103,117,109,101,110,116,
        115,46,108,101,110,103,116,104,41,114,101,116,117,114,110,32,118,111,105,100,32,48,61,61,61,116,63,116,104,105,115,58,116,104,105,115,46,101,97,99,104,40,102,117,110,99,116,105,111,110,40,101,41,
        123,83,46,111,102,102,115,101,116,46,115,101,116,79,102,102,115,101,116,40,116,104,105,115,44,116,44,101,41,125,41,59,118,97,114,32,101,44,110,44,114,61,116,104,105,115,91,48,93,59,114,101,116,117,
        114,110,32,114,63,114,46,103,101,116,67,108,105,101,110,116,82,101,99,116,115,40,41,46,108,101,110,103,116,104,63,40,101,61,114,46,103,101,116,66,111,117,110,100,105,110,103,67,108,105,101,110,116,
        82,101,99,116,40,41,44,110,61,114,46,111,119,110,101,114,68,111,99,117,109,101,110,116,46,100,101,102,97,117,108,116,86,105,101,119,44,123,116,111,112,58,101,46,116,111,112,43,110,46,112,97,103,
        101,89,79,102,102,115,101,116,44,108,101,102,116,58,101,46,108,101,102,116,43,110,46,112,97,103,101,88,79,102,102,115,101,116,125,41,58,123,116,111,112,58,48,44,108,101,102,116,58,48,125,58,118,
        111,105,100,32,48,125,44,112,111,115,105,116,105,111,110,58,102,117,110,99,116,105,111,110,40,41,123,105,102,40,116,104,105,115,91,48,93,41,123,118,97,114,32,101,44,116,44,110,44,114,61,116,104,
        105,115,91,48,93,44,105,61,123,116,111,112,58,48,44,108,101,102,116,58,48,125,59,105,102,40,34,102,105,120,101,100,34,61,61,61,83,46,99,115,115,40,114,44,34,112,111,115,105,116,105,111,110,34,41,
        41,116,61,114,46,103,101,116,66,111,117,110,100,105,110,103,67,108,105,101,110,116,82,101,99,116,40,41,59,101,108,115,101,123,116,61,116,104,105,115,46,111,102,102,115,101,116,40,41,44,110,61,114,
        46,111,119,110,101,114,68,111,99,117,109,101,110,116,44,101,61,114,46,111,102,102,115,101,116,80,97,114,101,110,116,124,124,110,46,100,111,99,117,109,101,110,116,69,108,101,109,101,110,116,59,119,
        104,105,108,101,40,101,38,38,40,101,61,61,61,110,46,98,111,100,121,124,124,101,61,61,61,110,46,100,111,99,117,109,101,110,116,69,108,101,109,101,110,116,41,38,38,34,115,116,97,116,105,99,34,61,61,
        61,83,46,99,115,115,40,101,44,34,112,111,115,105,116,105,111,110,34,41,41,101,61,101,46,112,97,114,101,110,116,78,111,100,101,59,101,38,38,101,33,61,61,114,38,38,49,61,61,61,101,46,110,111,100,101,
        84,121,112,101,38,38,40,40,105,61,83,40,101,41,46,111,102,102,115,101,116,40,41,41,46,116,111,112,43,61,83,46,99,115,115,40,101,44,34,98,111,114,100,101,114,84,111,112,87,105,100,116,104,34,44,33,
        48,41,44,105,46,108,101,102,116,43,61,83,46,99,115,115,40,101,44,34,98,111,114,100,101,114,76,101,102,116,87,105,100,116,104,34,44,33,48,41,41,125,114,101,116,117,114,110,123,116,111,112,58,116,
        46,116,111,112,45,105,46,116,111,112,45,83,46,99,115,115,40,114,44,34,109,97,114,103,105,110,84,111,112,34,44,33,48,41,44,108,101,102,116,58,116,46,108,101,102,116,45,105,46,108,101,102,116,45,83,
        46,99,115,115,40,114,44,34,109,97,114,103,105,110,76,101,102,116,34,44,33,48,41,125,125,125,44,111,102,102,115,101,116,80,97,114,101,110,116,58,102,117,110,99,116,105,111,110,40,41,123,114,101,116,
        117,114,110,32,116,104,105,115,46,109,97,112,40,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,101,61,116,104,105,115,46,111,102,102,115,101,116,80,97,114,101,110,116,59,119,104,105,108,
        101,40,101,38,38,34,115,116,97,116,105,99,34,61,61,61,83,46,99,115,115,40,101,44,34,112,111,115,105,116,105,111,110,34,41,41,101,61,101,46,111,102,102,115,101,116,80,97,114,101,110,116,59,114,101,
        116,117,114,110,32,101,124,124,114,101,125,41,125,125,41,44,83,46,101,97,99,104,40,123,115,99,114,111,108,108,76,101,102,116,58,34,112,97,103,101,88,79,102,102,115,101,116,34,44,115,99,114,111,108,
        108,84,111,112,58,34,112,97,103,101,89,79,102,102,115,101,116,34,125,44,102,117,110,99,116,105,111,110,40,116,44,105,41,123,118,97,114,32,111,61,34,112,97,103,101,89,79,102,102,115,101,116,34,61,
        61,61,105,59,83,46,102,110,91,116,93,61,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,36,40,116,104,105,115,44,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,
        118,97,114,32,114,59,105,102,40,120,40,101,41,63,114,61,101,58,57,61,61,61,101,46,110,111,100,101,84,121,112,101,38,38,40,114,61,101,46,100,101,102,97,117,108,116,86,105,101,119,41,44,118,111,105,
        100,32,48,61,61,61,110,41,114,101,116,117,114,110,32,114,63,114,91,105,93,58,101,91,116,93,59,114,63,114,46,115,99,114,111,108,108,84,111,40,111,63,114,46,112,97,103,101,88,79,102,102,115,101,116,
        58,110,44,111,63,110,58,114,46,112,97,103,101,89,79,102,102,115,101,116,41,58,101,91,116,93,61,110,125,44,116,44,101,44,97,114,103,117,109,101,110,116,115,46,108,101,110,103,116,104,41,125,125,41,
        44,83,46,101,97,99,104,40,91,34,116,111,112,34,44,34,108,101,102,116,34,93,44,102,117,110,99,116,105,111,110,40,101,44,110,41,123,83,46,99,115,115,72,111,111,107,115,91,110,93,61,70,101,40,121,46,
        112,105,120,101,108,80,111,115,105,116,105,111,110,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,105,102,40,116,41,114,101,116,117,114,110,32,116,61,87,101,40,101,44,110,41,44,80,101,46,
        116,101,115,116,40,116,41,63,83,40,101,41,46,112,111,115,105,116,105,111,110,40,41,91,110,93,43,34,112,120,34,58,116,125,41,125,41,44,83,46,101,97,99,104,40,123,72,101,105,103,104,116,58,34,104,
        101,105,103,104,116,34,44,87,105,100,116,104,58,34,119,105,100,116,104,34,125,44,102,117,110,99,116,105,111,110,40,97,44,115,41,123,83,46,101,97,99,104,40,123,112,97,100,100,105,110,103,58,34,105,
        110,110,101,114,34,43,97,44,99,111,110,116,101,110,116,58,115,44,34,34,58,34,111,117,116,101,114,34,43,97,125,44,102,117,110,99,116,105,111,110,40,114,44,111,41,123,83,46,102,110,91,111,93,61,102,
        117,110,99,116,105,111,110,40,101,44,116,41,123,118,97,114,32,110,61,97,114,103,117,109,101,110,116,115,46,108,101,110,103,116,104,38,38,40,114,124,124,34,98,111,111,108,101,97,110,34,33,61,116,
        121,112,101,111,102,32,101,41,44,105,61,114,124,124,40,33,48,61,61,61,101,124,124,33,48,61,61,61,116,63,34,109,97,114,103,105,110,34,58,34,98,111,114,100,101,114,34,41,59,114,101,116,117,114,110,
        32,36,40,116,104,105,115,44,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,118,97,114,32,114,59,114,101,116,117,114,110,32,120,40,101,41,63,48,61,61,61,111,46,105,110,100,101,120,79,
        102,40,34,111,117,116,101,114,34,41,63,101,91,34,105,110,110,101,114,34,43,97,93,58,101,46,100,111,99,117,109,101,110,116,46,100,111,99,117,109,101,110,116,69,108,101,109,101,110,116,91,34,99,108,
        105,101,110,116,34,43,97,93,58,57,61,61,61,101,46,110,111,100,101,84,121,112,101,63,40,114,61,101,46,100,111,99,117,109,101,110,116,69,108,101,109,101,110,116,44,77,97,116,104,46,109,97,120,40,101,
        46,98,111,100,121,91,34,115,99,114,111,108,108,34,43,97,93,44,114,91,34,115,99,114,111,108,108,34,43,97,93,44,101,46,98,111,100,121,91,34,111,102,102,115,101,116,34,43,97,93,44,114,91,34,111,102,
        102,115,101,116,34,43,97,93,44,114,91,34,99,108,105,101,110,116,34,43,97,93,41,41,58,118,111,105,100,32,48,61,61,61,110,63,83,46,99,115,115,40,101,44,116,44,105,41,58,83,46,115,116,121,108,101,40,
        101,44,116,44,110,44,105,41,125,44,115,44,110,63,101,58,118,111,105,100,32,48,44,110,41,125,125,41,125,41,44,83,46,101,97,99,104,40,91,34,97,106,97,120,83,116,97,114,116,34,44,34,97,106,97,120,83,
        116,111,112,34,44,34,97,106,97,120,67,111,109,112,108,101,116,101,34,44,34,97,106,97,120,69,114,114,111,114,34,44,34,97,106,97,120,83,117,99,99,101,115,115,34,44,34,97,106,97,120,83,101,110,100,
        34,93,44,102,117,110,99,116,105,111,110,40,101,44,116,41,123,83,46,102,110,91,116,93,61,102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,116,104,105,115,46,111,110,40,116,
        44,101,41,125,125,41,44,83,46,102,110,46,101,120,116,101,110,100,40,123,98,105,110,100,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,114,101,116,117,114,110,32,116,104,105,115,46,
        111,110,40,101,44,110,117,108,108,44,116,44,110,41,125,44,117,110,98,105,110,100,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,116,104,105,115,46,111,102,102,
        40,101,44,110,117,108,108,44,116,41,125,44,100,101,108,101,103,97,116,101,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,44,114,41,123,114,101,116,117,114,110,32,116,104,105,115,46,111,110,
        40,116,44,101,44,110,44,114,41,125,44,117,110,100,101,108,101,103,97,116,101,58,102,117,110,99,116,105,111,110,40,101,44,116,44,110,41,123,114,101,116,117,114,110,32,49,61,61,61,97,114,103,117,109,
        101,110,116,115,46,108,101,110,103,116,104,63,116,104,105,115,46,111,102,102,40,101,44,34,42,42,34,41,58,116,104,105,115,46,111,102,102,40,116,44,101,124,124,34,42,42,34,44,110,41,125,44,104,111,
        118,101,114,58,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,116,104,105,115,46,109,111,117,115,101,101,110,116,101,114,40,101,41,46,109,111,117,115,101,108,101,
        97,118,101,40,116,124,124,101,41,125,125,41,44,83,46,101,97,99,104,40,34,98,108,117,114,32,102,111,99,117,115,32,102,111,99,117,115,105,110,32,102,111,99,117,115,111,117,116,32,114,101,115,105,122,
        101,32,115,99,114,111,108,108,32,99,108,105,99,107,32,100,98,108,99,108,105,99,107,32,109,111,117,115,101,100,111,119,110,32,109,111,117,115,101,117,112,32,109,111,117,115,101,109,111,118,101,32,
        109,111,117,115,101,111,118,101,114,32,109,111,117,115,101,111,117,116,32,109,111,117,115,101,101,110,116,101,114,32,109,111,117,115,101,108,101,97,118,101,32,99,104,97,110,103,101,32,115,101,108,
        101,99,116,32,115,117,98,109,105,116,32,107,101,121,100,111,119,110,32,107,101,121,112,114,101,115,115,32,107,101,121,117,112,32,99,111,110,116,101,120,116,109,101,110,117,34,46,115,112,108,105,
        116,40,34,32,34,41,44,102,117,110,99,116,105,111,110,40,101,44,110,41,123,83,46,102,110,91,110,93,61,102,117,110,99,116,105,111,110,40,101,44,116,41,123,114,101,116,117,114,110,32,48,60,97,114,103,
        117,109,101,110,116,115,46,108,101,110,103,116,104,63,116,104,105,115,46,111,110,40,110,44,110,117,108,108,44,101,44,116,41,58,116,104,105,115,46,116,114,105,103,103,101,114,40,110,41,125,125,41,
        59,118,97,114,32,88,116,61,47,94,91,92,115,92,117,70,69,70,70,92,120,65,48,93,43,124,91,92,115,92,117,70,69,70,70,92,120,65,48,93,43,36,47,103,59,83,46,112,114,111,120,121,61,102,117,110,99,116,
        105,111,110,40,101,44,116,41,123,118,97,114,32,110,44,114,44,105,59,105,102,40,34,115,116,114,105,110,103,34,61,61,116,121,112,101,111,102,32,116,38,38,40,110,61,101,91,116,93,44,116,61,101,44,101,
        61,110,41,44,109,40,101,41,41,114,101,116,117,114,110,32,114,61,115,46,99,97,108,108,40,97,114,103,117,109,101,110,116,115,44,50,41,44,40,105,61,102,117,110,99,116,105,111,110,40,41,123,114,101,
        116,117,114,110,32,101,46,97,112,112,108,121,40,116,124,124,116,104,105,115,44,114,46,99,111,110,99,97,116,40,115,46,99,97,108,108,40,97,114,103,117,109,101,110,116,115,41,41,41,125,41,46,103,117,
        105,100,61,101,46,103,117,105,100,61,101,46,103,117,105,100,124,124,83,46,103,117,105,100,43,43,44,105,125,44,83,46,104,111,108,100,82,101,97,100,121,61,102,117,110,99,116,105,111,110,40,101,41,
        123,101,63,83,46,114,101,97,100,121,87,97,105,116,43,43,58,83,46,114,101,97,100,121,40,33,48,41,125,44,83,46,105,115,65,114,114,97,121,61,65,114,114,97,121,46,105,115,65,114,114,97,121,44,83,46,
        112,97,114,115,101,74,83,79,78,61,74,83,79,78,46,112,97,114,115,101,44,83,46,110,111,100,101,78,97,109,101,61,65,44,83,46,105,115,70,117,110,99,116,105,111,110,61,109,44,83,46,105,115,87,105,110,
        100,111,119,61,120,44,83,46,99,97,109,101,108,67,97,115,101,61,88,44,83,46,116,121,112,101,61,119,44,83,46,110,111,119,61,68,97,116,101,46,110,111,119,44,83,46,105,115,78,117,109,101,114,105,99,
        61,102,117,110,99,116,105,111,110,40,101,41,123,118,97,114,32,116,61,83,46,116,121,112,101,40,101,41,59,114,101,116,117,114,110,40,34,110,117,109,98,101,114,34,61,61,61,116,124,124,34,115,116,114,
        105,110,103,34,61,61,61,116,41,38,38,33,105,115,78,97,78,40,101,45,112,97,114,115,101,70,108,111,97,116,40,101,41,41,125,44,83,46,116,114,105,109,61,102,117,110,99,116,105,111,110,40,101,41,123,
        114,101,116,117,114,110,32,110,117,108,108,61,61,101,63,34,34,58,40,101,43,34,34,41,46,114,101,112,108,97,99,101,40,88,116,44,34,34,41,125,44,34,102,117,110,99,116,105,111,110,34,61,61,116,121,112,
        101,111,102,32,100,101,102,105,110,101,38,38,100,101,102,105,110,101,46,97,109,100,38,38,100,101,102,105,110,101,40,34,106,113,117,101,114,121,34,44,91,93,44,102,117,110,99,116,105,111,110,40,41,
        123,114,101,116,117,114,110,32,83,125,41,59,118,97,114,32,86,116,61,67,46,106,81,117,101,114,121,44,71,116,61,67,46,36,59,114,101,116,117,114,110,32,83,46,110,111,67,111,110,102,108,105,99,116,61,
        102,117,110,99,116,105,111,110,40,101,41,123,114,101,116,117,114,110,32,67,46,36,61,61,61,83,38,38,40,67,46,36,61,71,116,41,44,101,38,38,67,46,106,81,117,101,114,121,61,61,61,83,38,38,40,67,46,106,
        81,117,101,114,121,61,86,116,41,44,83,125,44,34,117,110,100,101,102,105,110,101,100,34,61,61,116,121,112,101,111,102,32,101,38,38,40,67,46,106,81,117,101,114,121,61,67,46,36,61,83,41,44,83,125,41,
        59,10, 0 };

    static constexpr const char* view_roundslider_min_js =
        "Failed to fetch version info for roundslider.";
    static constexpr const char* view_styles_css =
        ".view-patch-element {\n"
        "    font-family: 'Coral Pixels';\n"
        "    font-size: 22px;\n"
        "    text-align: center;\n"
        "    display: block;\n"
        "    width: 100%;\n"
        "    height: 100%;\n"
        "    padding: 10px;\n"
        "    overflow: auto;\n"
        "    flex-direction: column;\n"
        "    align-items: left;\n"
        "    background-color: lightpink;\n"
        "}\n"
        "\n"
        ".param {\n"
        "    -webkit-appearance: none;\n"
        "    appearance: none;\n"
        "    width: 100%;\n"
        "    height: 20px;\n"
        "    background: #d3d3d3;\n"
        "    outline: none;\n"
        "    opacity: 0.7;\n"
        "    -webkit-transition: .2s;\n"
        "    transition: opacity .2s;\n"
        "}\n"
        "\n"
        ".param:hover {\n"
        "    opacity: 1;\n"
        "}\n"
        "\n"
        ".param::-webkit-slider-thumb {\n"
        "    -webkit-appearance: none;\n"
        "    appearance: none;\n"
        "    width: 25px;\n"
        "    height: 25px;\n"
        "    background: #f3768f;\n"
        "    cursor: pointer;\n"
        "}\n"
        "\n"
        ".param::-moz-range-thumb {\n"
        "    width: 25px;\n"
        "    height: 25px;\n"
        "    background: #d8506b;\n"
        "    cursor: pointer;\n"
        "}\n"
        "\n"
        ".controls {\n"
        "    border: 2px solid black;\n"
        "    padding: 10px;\n"
        "    border-radius: 5px;\n"
        "    display: flex;\n"
        "    flex-direction: column;\n"
        "    gap: 10px;\n"
        "    width: 300px;\n"
        "    margin: 0 auto;\n"
        "    width: 50%;\n"
        "    background: #f3768f;\n"
        "}\n"
        "\n"
        ".console {\n"
        "    border: 2px solid black;\n"
        "    padding: 10px;\n"
        "    border-radius: 5px;\n"
        "    display: flex;\n"
        "    flex-direction: column;\n"
        "    gap: 10px;\n"
        "    width: 300px;\n"
        "    margin: 0 auto;\n"
        "    width: 100%;\n"
        "    background: #f45c7a;\n"
        "}\n"
        "\n"
        "input[type=\"range\"]{\n"
        "  -webkit-appearance:none;\n"
        "  appearance: none;\n"
        "  width: 250px;\n"
        "  height:auto;\n"
        "  margin:10px 50px;\n"
        "  background: linear-gradient(to bottom, lightpink, white);\n"
        "  background-size:250 auto;\n"
        "  background-position:center;\n"
        "  background-repeat:no-repeat;\n"
        "  overflow:hidden;\n"
        "  outline: none;\n"
        "  position: center;\n"
        "}\n"
        "\n"
        "input[type=\"range\"]:first-of-type{\n"
        "  margin-top:30px;\n"
        "}\n"
        "\n"
        "input[type=\"range\"]::-webkit-slider-thumb{\n"
        "  -webkit-appearance:none;\n"
        "  width:20px;\n"
        "  height:20px;\n"
        "  background:#f3768f;\n"
        "  position:relative;\n"
        "  z-index:3;\n"
        "  box-shadow:0 0 10px 0 rgba(0,0,0,0.3);\n"
        "}\n"
        "\n"
        "input[type=\"range\"]::-webkit-slider-thumb:after{\n"
        "  content:\" \";\n"
        "  width:160px;\n"
        "  height:10px;\n"
        "  position:absolute;\n"
        "  z-index:1;\n"
        "  right:20px;\n"
        "  top:5px;\n"
        "  background: #ff5b32;\n"
        "  background: linear-gradient(to right, #f088fc 1%, #AC6CFF 70%);\n"
        "}\n"
        "\n"
        ".value-display {\n"
        "    text-align: center;\n"
        "    font-size: 16px;\n"
        "    margin-top: 5px;\n"
        "    color: #000;\n"
        "}";


    static constexpr std::array files =
    {
        File { "cmaj_api/cmaj-audio-worklet-helper.js", std::string_view (cmaj_api_cmajaudioworklethelper_js, 28203) },
        File { "delaygrain.cmajorpatch", std::string_view (delaygrain_cmajorpatch, 370) },
        File { "cmaj_api/assets/cmajor-logo.svg", std::string_view (cmaj_api_assets_cmajorlogo_svg, 2913) },
        File { "cmaj_api/cmaj-event-listener-list.js", std::string_view (cmaj_api_cmajeventlistenerlist_js, 3474) },
        File { "cmaj_api/cmaj-generic-patch-view.js", std::string_view (cmaj_api_cmajgenericpatchview_js, 6912) },
        File { "cmaj_api/cmaj-midi-helpers.js", std::string_view (cmaj_api_cmajmidihelpers_js, 13253) },
        File { "cmaj_api/cmaj-parameter-controls.js", std::string_view (cmaj_api_cmajparametercontrols_js, 30756) },
        File { "cmaj_api/cmaj-patch-connection.js", std::string_view (cmaj_api_cmajpatchconnection_js, 13131) },
        File { "cmaj_api/cmaj-patch-view.js", std::string_view (cmaj_api_cmajpatchview_js, 7388) },
        File { "cmaj_api/cmaj-piano-keyboard.js", std::string_view (cmaj_api_cmajpianokeyboard_js, 15557) },
        File { "cmaj_api/cmaj-server-session.js", std::string_view (cmaj_api_cmajserversession_js, 18553) },
        File { "view/index.js", std::string_view (view_index_js, 4928) },
        File { "view/jquery.min.js", std::string_view (view_jquery_min_js, 89501) },
        File { "view/roundslider.min.js", std::string_view (view_roundslider_min_js, 45) },
        File { "view/styles.css", std::string_view (view_styles_css, 2197) }
    };

};



juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new cmaj::plugin::GeneratedPlugin<::SmoothRandomDelayFilter> (std::make_shared<cmaj::Patch>());
}
