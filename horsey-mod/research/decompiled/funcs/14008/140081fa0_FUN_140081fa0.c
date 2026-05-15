// Address: 0x140081fa0
// Ghidra name: FUN_140081fa0
// ============ 0x140081fa0 FUN_140081fa0 (size=99) ============


undefined8 FUN_140081fa0(longlong param_1,char param_2)



{

  longlong lVar1;

  int *piVar2;

  

  if (((param_2 == '\0') && (lVar1 = *(longlong *)(param_1 + 0x80), *(int *)(lVar1 + 0x24c) == 2))

     && (*(int *)(param_1 + 0x70) != 0xb)) {

    piVar2 = (int *)(lVar1 + 0x288);

    if (0xf < *(ulonglong *)(lVar1 + 0x2a0)) {

      piVar2 = *(int **)(lVar1 + 0x288);

    }

    if ((*(longlong *)(lVar1 + 0x298) != 4) || (*piVar2 != 0x68736966)) {

      return 0;

    }

  }

  FUN_140080cc0(param_1,0xc,0);

  return 1;

}




