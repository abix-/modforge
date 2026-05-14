// Address: 0x14008cad0
// Ghidra name: FUN_14008cad0
// ============ 0x14008cad0 FUN_14008cad0 (size=146) ============


void FUN_14008cad0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  longlong *plVar5;

  ulonglong uVar6;

  

  FUN_140075750(*(undefined1 *)(param_1 + 0x492));

  FUN_140075750(*(undefined1 *)(param_1 + 0x491));

  FUN_140075750(*(undefined1 *)(param_1 + 0x490));

  FUN_140075670(*(undefined4 *)(param_1 + 0x25c));

  iVar3 = -1;

  iVar2 = iVar3;

  if (*(longlong *)(param_1 + 0x270) != 0) {

    plVar5 = *(longlong **)(param_1 + 0xb8);

    iVar4 = 0;

    uVar6 = *(longlong *)(param_1 + 0xc0) - (longlong)plVar5 >> 3;

    if (uVar6 != 0) {

      do {

        lVar1 = *plVar5;

        plVar5 = plVar5 + 1;

        iVar2 = iVar4;

        if (lVar1 != *(longlong *)(param_1 + 0x270)) {

          iVar2 = iVar3;

        }

        iVar4 = iVar4 + 1;

        iVar3 = iVar2;

      } while ((ulonglong)(longlong)iVar4 < uVar6);

    }

  }

  FUN_140075670(iVar2);

  return;

}




