// Address: 0x14022d9c0
// Ghidra name: FUN_14022d9c0
// ============ 0x14022d9c0 FUN_14022d9c0 (size=194) ============


undefined8 FUN_14022d9c0(undefined4 *param_1,uint *param_2,uint *param_3)



{

  BOOL BVar1;

  uint uVar2;

  undefined4 extraout_var;

  ulonglong uVar3;

  _SYSTEM_POWER_STATUS local_18;

  

  BVar1 = GetSystemPowerStatus(&local_18);

  uVar3 = CONCAT44(extraout_var,BVar1);

  if (BVar1 == 0) {

LAB_14022da5e:

    *param_1 = 0;

  }

  else {

    uVar3 = 0;

    if (local_18.BatteryFlag == 0xff) goto LAB_14022da5e;

    if (-1 < (char)local_18.BatteryFlag) {

      if ((local_18.BatteryFlag & 8) == 0) {

        if (local_18.ACLineStatus == '\x01') {

          *param_1 = 4;

        }

        else {

          *param_1 = 1;

        }

      }

      else {

        *param_1 = 3;

      }

      *param_3 = 0xffffffff;

      *param_2 = 0xffffffff;

      if (local_18.BatteryLifePercent != 0xff) {

        uVar2 = (uint)local_18.BatteryLifePercent;

        if (100 < local_18.BatteryLifePercent) {

          uVar2 = 100;

        }

        *param_3 = uVar2;

      }

      uVar3 = (ulonglong)local_18.BatteryLifeTime;

      if (local_18.BatteryLifeTime != 0xffffffff) {

        *param_2 = local_18.BatteryLifeTime;

        return CONCAT71((uint7)(uint3)(local_18.BatteryLifeTime >> 8),1);

      }

      goto LAB_14022da70;

    }

    *param_1 = 2;

  }

  *param_3 = 0xffffffff;

  *param_2 = 0xffffffff;

LAB_14022da70:

  return CONCAT71((int7)(uVar3 >> 8),1);

}




