// Address: 0x14006aef0
// Ghidra name: FUN_14006aef0
// ============ 0x14006aef0 FUN_14006aef0 (size=323) ============


ulonglong FUN_14006aef0(longlong param_1)



{

  ulonglong uVar1;

  float fVar2;

  float fVar3;

  char cVar4;

  ulonglong uVar5;

  uint uVar6;

  ulonglong uVar7;

  longlong lVar8;

  ulonglong uVar9;

  float fVar10;

  float fVar11;

  float local_res8;

  float local_resc;

  

  fVar3 = DAT_140304bf4;

  fVar2 = DAT_14030338c;

  lVar8 = *(longlong *)(param_1 + 0x130);

  uVar5 = 0;

  uVar7 = uVar5;

  uVar9 = uVar5;

  fVar11 = DAT_14039ca5c;

  if (*(longlong *)(param_1 + 0x138) - lVar8 >> 3 != 0) {

    do {

      uVar1 = *(ulonglong *)(uVar9 + lVar8);

      FUN_1400b4a10(uVar1,&local_res8);

      fVar10 = (local_resc - fVar3) * (local_resc - fVar3) +

               (local_res8 - fVar2) * (local_res8 - fVar2);

      if (fVar10 < 0.0) {

        fVar10 = (float)FUN_1402cdfa0(fVar10);

      }

      else {

        fVar10 = SQRT(fVar10);

      }

      cVar4 = FUN_1400c5740(&local_res8,*(undefined8 *)(param_1 + 0x78),0);

      if ((cVar4 == '\0') && (fVar10 < fVar11)) {

        uVar5 = uVar1;

        fVar11 = fVar10;

      }

      lVar8 = *(longlong *)(param_1 + 0x130);

      uVar6 = (int)uVar7 + 1;

      uVar7 = (ulonglong)uVar6;

      uVar9 = uVar9 + 8;

    } while ((ulonglong)(longlong)(int)uVar6 <

             (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar8 >> 3));

  }

  return uVar5;

}




