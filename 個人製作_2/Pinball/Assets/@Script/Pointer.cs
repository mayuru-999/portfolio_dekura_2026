using DG.Tweening;
using UnityEngine;
using UnityEngine.SocialPlatforms.Impl;

public class Pointer : MonoBehaviour
{
    [SerializeField] private int baseScore = 100;

    void OnCollisionEnter(Collision c)
    {
        if (c.rigidbody == null) return;

        ContactPoint contact = c.GetContact(0);
        Player.AddPointer.AddPoint(baseScore, contact.point);
    }
}
