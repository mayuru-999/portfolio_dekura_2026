using UnityEngine;
using DG.Tweening;

public class Shake : MonoBehaviour
{
    [SerializeField] static Transform base_Transform;

    public static void Shaking()
    {
        base_Transform.DOShakePosition(1f);
    }
}
