#include <benchmark/benchmark.h>

#include "EventProcessor.hpp"
#include <vector>

static void BM_ProcessEventsSequential(benchmark::State& state) {
    csc2026::EventProcessor processor;
    auto events = csc2026::EventProcessor::generateSampleEvents(static_cast<size_t>(state.range(0)));

    for (auto _ : state) {
        processor.reset();
        processor.processEvents(events);
        benchmark::DoNotOptimize(processor.totalTracks());
        benchmark::DoNotOptimize(processor.totalEnergy());
    }
}

BENCHMARK(BM_ProcessEventsSequential)->Arg(100)->Arg(1000)->Arg(5000);

static void BM_ProcessEventsParallel(benchmark::State& state) {
    csc2026::EventProcessor processor;
    auto events = csc2026::EventProcessor::generateSampleEvents(static_cast<size_t>(state.range(0)));

    for (auto _ : state) {
        processor.reset();
        processor.processEvents(events);
        benchmark::DoNotOptimize(processor.totalTracks());
        benchmark::DoNotOptimize(processor.totalEnergy());
    }
}

BENCHMARK(BM_ProcessEventsParallel)->Arg(100)->Arg(1000)->Arg(5000);

BENCHMARK_MAIN();

