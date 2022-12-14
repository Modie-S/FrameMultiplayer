// MaxiMod Games 2022
// Modie Shakarchi


#include "HealthPickUp.h"
#include "FrameMultiplayer/Character/FrameCharacter.h"
#include "FrameMultiplayer/Components/BuffComponent.h"




AHealthPickUp::AHealthPickUp()
{
    bReplicates = true;
    
}

void AHealthPickUp::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

    AFrameCharacter* FrameCharacter = Cast<AFrameCharacter>(OtherActor);
    if (FrameCharacter)
    {
       UBuffComponent* Buff = FrameCharacter->GetBuff();
       if (Buff)
       {
            Buff->Heal(HealAmount, HealingTime);
       }
    }

    Destroy();
}

