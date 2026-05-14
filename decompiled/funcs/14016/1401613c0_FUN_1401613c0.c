// Address: 0x1401613c0
// Ghidra name: FUN_1401613c0
// ============ 0x1401613c0 FUN_1401613c0 (size=318) ============


void FUN_1401613c0(longlong param_1,float param_2,float param_3)



{

  char cVar1;

  longlong lVar2;

  longlong lVar3;

  ulonglong uVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  lVar2 = FUN_1401611a0();

  if ((((*(char *)(lVar2 + 199) == '\0') && (*(char *)(lVar2 + 0xc5) != '\0')) &&

      (*(char *)(lVar2 + 0x128) == '\0')) && (*(char *)(lVar2 + 0xc6) == '\0')) {

    if ((param_1 != 0) || (param_1 = *(longlong *)(lVar2 + 0x88), param_1 != 0)) {

      fVar7 = (float)*(int *)(param_1 + 0x20) * DAT_14039ca34;

      fVar6 = (float)*(int *)(param_1 + 0x24) * DAT_14039ca34;

      fVar5 = (float)thunk_FUN_1402d0350(fVar7);

      if (((fVar5 <= param_2) &&

          ((fVar5 = (float)thunk_FUN_1402e33f0(fVar7), param_2 <= fVar5 &&

           (fVar5 = (float)thunk_FUN_1402d0350(fVar6), fVar5 <= param_3)))) &&

         (fVar5 = (float)thunk_FUN_1402e33f0(fVar6), param_3 <= fVar5)) {

        lVar3 = FUN_140149300();

        uVar4 = lVar3 - *(longlong *)(lVar2 + 200);

        if (uVar4 < 30000000) {

          *(undefined1 *)(lVar2 + 0xc6) = 1;

          cVar1 = FUN_140162d10(CONCAT71((int7)(uVar4 >> 8),1));

          if (cVar1 == '\0') {

            *(undefined1 *)(lVar2 + 0xc6) = 0;

          }

        }

        *(longlong *)(lVar2 + 200) = lVar3;

        return;

      }

    }

    *(undefined8 *)(lVar2 + 200) = 0;

  }

  return;

}




