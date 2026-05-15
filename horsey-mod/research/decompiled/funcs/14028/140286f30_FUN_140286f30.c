// Address: 0x140286f30
// Ghidra name: FUN_140286f30
// ============ 0x140286f30 FUN_140286f30 (size=186) ============


void FUN_140286f30(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  char *pcVar3;

  char cVar4;

  char cVar5;

  char cVar6;

  int iVar7;

  

  lVar2 = *(longlong *)(param_1 + 0x148);

  cVar4 = '\0';

  cVar6 = '\0';

  cVar5 = '\0';

  FUN_140190720(lVar2 + 0x48,(longlong)*(int *)(lVar2 + 0xc48),0xc,&LAB_140286f10);

  iVar7 = 0;

  if (0 < *(int *)(*(longlong *)(param_1 + 0x148) + 0xc48)) {

    pcVar3 = (char *)(lVar2 + 0x50);

    do {

      iVar1 = *(int *)(pcVar3 + -4);

      if (iVar1 == 0) {

        *pcVar3 = cVar4;

        cVar4 = cVar4 + '\x01';

      }

      else if (iVar1 == 1) {

        *pcVar3 = cVar5;

        cVar5 = cVar5 + '\x01';

      }

      else if (iVar1 == 2) {

        *pcVar3 = cVar6;

        cVar6 = cVar6 + '\x01';

      }

      iVar7 = iVar7 + 1;

      pcVar3 = pcVar3 + 0xc;

    } while (iVar7 < *(int *)(*(longlong *)(param_1 + 0x148) + 0xc48));

  }

  return;

}




