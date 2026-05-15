// Address: 0x14003f590
// Ghidra name: FUN_14003f590
// ============ 0x14003f590 FUN_14003f590 (size=227) ============


void FUN_14003f590(undefined8 param_1)



{

  longlong lVar1;

  double dVar2;

  

  if (((DAT_1403ea292 == '\0') && (DAT_1403ea293 != '\0')) && (DAT_1403ea290 == '\0')) {

    FUN_140044ff0(DAT_1403ea280);

    *(undefined1 *)(DAT_1403ea2a8 + 0x39) = 1;

    if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {

      *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xb) = 1;

    }

    if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {

      *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 0xb) = 1;

    }

    if (((DAT_1403ea298 != 0.0) && (lVar1 = *(longlong *)(DAT_1403ea2a8 + 0x58), lVar1 != 0)) &&

       (dVar2 = (double)**(int **)(lVar1 + 0x28) * DAT_1403ea298,

       dVar2 <= (double)(*(int **)(lVar1 + 0x28))[1])) {

      *(double *)(lVar1 + 0x20) = dVar2;

    }

    DAT_1403ea290 = 1;

    DAT_1403ea298 = 0.0;

    FUN_140027900(param_1);

    return;

  }

  FUN_140027900();

  return;

}




