/**
 * GLOBAL AI GOVERNANCE PROTOCOL (GAGP) — SUBSTRATE HARDWARE INTERCEPT GATE
 * Header Specification
 * Author: Cory Michael Miller / QuickPrompt Solutions™
 * Epoch: 2026
 */

#ifndef GAGP_HARDWARE_GATE_H
#define GAGP_HARDWARE_GATE_H

#include <stdint.h>
#include <stddef.h>

#define TAU_1 "OPTIMUS_HORIZON_LAYER_1"
#define TAU_2 "OPTIMUS_HORIZON_LAYER_2"

/* Physical Memory-Mapped I/O Register Addresses */
#define MMIO_GAGP_BASE         0xF0000000UL
#define REG_BUS_LOCK           (*(volatile uint32_t*)(MMIO_GAGP_BASE + 0x00))
#define REG_HARDWARE_INTERRUPT (*(volatile uint32_t*)(MMIO_GAGP_BASE + 0x04))
#define REG_DRIFT_FAULT        (*(volatile uint32_t*)(MMIO_GAGP_BASE + 0x08))
#define REG_CONSENSUS_GATE     (*(volatile uint32_t*)(MMIO_GAGP_BASE + 0x0C))

#ifdef __cplusplus
extern "C" {
#endif

float compute_hardware_hamming_drift(
    const uint64_t* __restrict vc,
    const uint64_t* __restrict vb,
    size_t n_words
);

void gagp_hardware_execution_gate(
    const uint64_t* mem_current,
    const uint64_t* mem_baseline,
    size_t n_words,
    float max_drift_threshold,
    uint8_t quorum_valid
);

#ifdef __cplusplus
}
#endif

#endif /* GAGP_HARDWARE_GATE_H */
