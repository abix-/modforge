// Address: 0x1402706d0
// Ghidra name: FUN_1402706d0
// ============ 0x1402706d0 FUN_1402706d0 (size=673) ============


byte FUN_1402706d0(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  char *pcVar7;

  int iVar8;

  undefined1 local_c8 [32];

  undefined1 local_a8;

  char local_a7;

  char cStack_a6;

  char cStack_a5;

  char cStack_a4;

  char cStack_a3;

  char cStack_a2;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  uVar6 = 0;

  iVar8 = 0;

  uVar4 = FUN_140149350();

  uVar5 = uVar6;

  if (0 < *(int *)(param_1 + 0x8c)) {

    uVar5 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  }

  iVar3 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_a8,0x80,0);

  while (0 < iVar3) {

    cVar2 = FUN_1402712b0(lVar1,&local_a8,iVar3);

    if (cVar2 != '\0') {

      uVar6 = (ulonglong)((int)uVar6 + 1);

      *(ulonglong *)(lVar1 + 0x58) = uVar4;

      if (uVar5 != 0) {

        switch(local_a8) {

        case 1:

          iVar3 = iVar3 + -1;

          pcVar7 = &local_a7;

          break;

        default:

          goto switchD_140270791_caseD_2;

        case 0x11:

        case 0x12:

        case 0x13:

        case 0x14:

        case 0x15:

        case 0x16:

        case 0x17:

        case 0x18:

        case 0x19:

          FUN_140271e30(lVar1);

          iVar3 = iVar3 + -3;

          pcVar7 = &cStack_a5;

        }

        FUN_140270a20(uVar5,*(undefined8 *)(param_1 + 0x80),lVar1,pcVar7,iVar3);

      }

    }

switchD_140270791_caseD_2:

    iVar8 = (int)uVar6;

    iVar3 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_a8,0x80,0);

  }

  if (*(char *)(param_1 + 0x54) != '\0') {

    if (iVar8 == 0) {

      if (*(longlong *)(lVar1 + 0x58) + 500U <= uVar4) {

        FUN_140271d10(param_1);

        *(ulonglong *)(lVar1 + 0x58) = uVar4;

      }

    }

    else if ((*(int *)(param_1 + 0x8c) == 0) &&

            (cVar2 = FUN_140207f20(*(undefined8 *)(param_1 + 0x28)), cVar2 == '\0')) {

      FUN_140208110(param_1,0);

    }

  }

  if ((*(char *)(lVar1 + 0x10) == '\0') && (*(char *)(lVar1 + 0x11) == '\0')) {

    if (iVar8 != 0) goto LAB_14027095a;

  }

  else {

    if (iVar8 != 0) {

      if (*(int *)(param_1 + 0x8c) == 0) {

        iVar3 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),0x12,&local_a8,0x80);

        if ((6 < iVar3) &&

           (((((local_a7 != '\0' || (cStack_a6 != '\0')) || (cStack_a5 != '\0')) ||

             ((cStack_a4 != '\0' || (cStack_a3 != '\0')))) || (cStack_a2 != '\0')))) {

          FUN_14012ef10(local_c8,0x12,"%.2x-%.2x-%.2x-%.2x-%.2x-%.2x",cStack_a2,cStack_a3,cStack_a4,

                        cStack_a5,cStack_a6,local_a7);

          FUN_140208490(param_1,local_c8);

        }

        FUN_140208110(param_1,0);

      }

      goto LAB_14027095a;

    }

    if ((0 < *(int *)(param_1 + 0x8c)) && (*(longlong *)(lVar1 + 0x58) + 500U <= uVar4)) {

      FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

    }

  }

  if ((iVar3 < 0) && (0 < *(int *)(param_1 + 0x8c))) {

    FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

  }

LAB_14027095a:

  return (byte)((uint)iVar3 >> 0x1f) ^ 1;

}




