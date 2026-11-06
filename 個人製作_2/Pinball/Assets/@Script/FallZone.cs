using UnityEngine;

public class FallZone : MonoBehaviour
{
    private void OnTriggerEnter(Collider other)
    {
        var rb = other.attachedRigidbody;
        if (rb.CompareTag("Ball"))
        {
            Destroy(rb.gameObject);
            Debug.Log("Ball destroyed");
        }
    }
}
