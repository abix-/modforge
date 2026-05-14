// Address: 0x14018a0e0
// Ghidra name: FUN_14018a0e0
// ============ 0x14018a0e0 FUN_14018a0e0 (size=66) ============


ulonglong FUN_14018a0e0(longlong param_1,ulonglong param_2)



{

  if (*(int *)(param_1 + 0x50) == 2) {

    if ((*(int *)(param_1 + 0x70) == 2) &&

       ((longlong)param_2 < (longlong)(ulonglong)*(uint *)(param_1 + 0x54))) {

      FUN_14012e850("Invalid number of sample frames in WAVE fact chunk (too many)");

      return 0xffffffffffffffff;

    }

    if ((longlong)(ulonglong)*(uint *)(param_1 + 0x54) < (longlong)param_2) {

      param_2 = (ulonglong)*(uint *)(param_1 + 0x54);

    }

  }

  return param_2;

}




